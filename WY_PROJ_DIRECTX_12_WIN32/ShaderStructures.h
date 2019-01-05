#pragma once

#include <iostream>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

struct Vertex {
	Vertex(float x, float y, float z, float u, float v) : pos(x, y, z), texCoord(u, v) {}
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT2 texCoord;
};

struct TextVertex {
	TextVertex(float r, float g, float b, float a, float u, float v, float tw, float th, float x, float y, float w, float h) : color(r, g, b, a), texCoord(u, v, tw, th), pos(x, y, w, h) {}
	DirectX::XMFLOAT4 pos;
	DirectX::XMFLOAT4 texCoord;
	DirectX::XMFLOAT4 color;
};

// this is the structure of our constant buffer.
struct ConstantBufferPerObject {
	DirectX::XMFLOAT4X4 wvpMat;
};

// Constant buffer used to send MVP matrices to the vertex shader.
struct ModelViewProjectionConstantBuffer
{
	DirectX::XMFLOAT4X4 model;
	DirectX::XMFLOAT4X4 view;
	DirectX::XMFLOAT4X4 projection;
	DirectX::XMFLOAT4X4 wvpMat;
};

// Used to send per-vertex data to the vertex shader.
struct VertexPositionColorTextureCoordNormal
{
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 color;
	DirectX::XMFLOAT2 tex;
	DirectX::XMFLOAT3 normal;
	bool isSet;
};

typedef struct {
	float x, y, z;
} VertexType;

typedef struct {
	int vIndex1, vIndex2, vIndex3;
	int tIndex1, tIndex2, tIndex3;
	int nIndex1, nIndex2, nIndex3;
} FaceType;


struct FontChar
{
	// the unicode id
	int id;

	// these need to be converted to texture coordinates 
	// (where 0.0 is 0 and 1.0 is textureWidth of the font)
	float u; // u texture coordinate
	float v; // v texture coordinate
	float twidth; // width of character on texture
	float theight; // height of character on texture

	float width; // width of character in screen coords
	float height; // height of character in screen coords

				  // these need to be normalized based on size of font
	float xoffset; // offset from current cursor pos to left side of character
	float yoffset; // offset from top of line to top of character
	float xadvance; // how far to move to right for next character
};

struct FontKerning
{
	int firstid; // the first character
	int secondid; // the second character
	float amount; // the amount to add/subtract to second characters x
};

struct Font
{
	std::wstring name; // name of the font
	std::wstring fontImage;
	int size; // size of font, lineheight and baseheight will be based on this as if this is a single unit (1.0)
	float lineHeight; // how far to move down to next line, will be normalized
	float baseHeight; // height of all characters, will be normalized
	int textureWidth; // width of the font texture
	int textureHeight; // height of the font texture
	int numCharacters; // number of characters in the font
	FontChar* CharList; // list of characters
	int numKernings; // the number of kernings
	FontKerning* KerningsList; // list to hold kerning values
	ID3D12Resource* textureBuffer; // the font texture resource
	D3D12_GPU_DESCRIPTOR_HANDLE srvHandle; // the font srv

										   // these are how much the character is padded in the texture. We
										   // add padding to give sampling a little space so it does not accidentally
										   // padd the surrounding characters. We will need to subtract these paddings
										   // from the actual spacing between characters to remove the gaps you would otherwise see
	float leftpadding;
	float toppadding;
	float rightpadding;
	float bottompadding;

	// this will return the amount of kerning we need to use for two characters
	float GetKerning(wchar_t first, wchar_t second)
	{
		for (int i = 0; i < numKernings; ++i)
		{
			if ((wchar_t)KerningsList[i].firstid == first && (wchar_t)KerningsList[i].secondid == second)
				return KerningsList[i].amount;
		}
		return 0.0f;
	}

	// this will return a FontChar given a wide character
	FontChar* GetChar(wchar_t c)
	{
		for (int i = 0; i < numCharacters; ++i)
		{
			if (c == (wchar_t)CharList[i].id)
				return &CharList[i];
		}
		return nullptr;
	}
};

struct Timer
{
	double timerFrequency = 0.0;
	long long lastFrameTime = 0;
	long long lastSecond = 0;
	double frameDelta = 0;
	int fps = 0;

	Timer()
	{
		LARGE_INTEGER li;
		QueryPerformanceFrequency(&li);

		// seconds
		//timerFrequency = double(li.QuadPart);

		// milliseconds
		timerFrequency = double(li.QuadPart) / 1000.0;

		// microseconds
		//timerFrequency = double(li.QuadPart) / 1000000.0;

		QueryPerformanceCounter(&li);
		lastFrameTime = li.QuadPart;
	}

	// Call this once per frame
	double GetFrameDelta()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		frameDelta = double(li.QuadPart - lastFrameTime) / timerFrequency;
		if (frameDelta > 0)
			fps = (int) (1000 / frameDelta);
		lastFrameTime = li.QuadPart;
		return frameDelta;
	}
};