#pragma once

#include "stdafx.h"
#include "Util.h"

// Class description: 
//		This class represents the font objects to be imported from 
//		the standard FNT file exported from a software called Hiero.
class MyFont {
private:
	// Main font information.
	Font *font;

	// The maximum number of characters you can render during a frame. This is just used to make sure
	// there is enough memory allocated for the text vertex buffer each frame.
	int maxNumTextCharacters = 1024;

	// A view for text vertex buffers. Array of vertex buffer views 
	// keeping track of each text's vertex buffers.
	D3D12_VERTEX_BUFFER_VIEW textVertexBufferView[frameBufferCount];

	// Texture buffer to hold the current font's bitmap image SRV.
	// to be used for font rendering.
	ID3D12Resource* textVertexBuffer[frameBufferCount];
 
	// This is a pointer to each of the text constant buffers.
	// Can cast the gpu virtual address to a textvertex, 
	// so we can directly store our vertices there.
	UINT8* textVBGPUAddress[frameBufferCount];
public:
	// Default constructor.
	MyFont();
	// Detructor.
	~MyFont();

	// Load from a FNT file and initializes the vertex, index, 
	// texture and constant buffers resources for "this" MyFont object to be 
	// rendered on screen using DirectX 12 engine.
	void initMyFont(
		ID3D12Device *device,
		ID3D12GraphicsCommandList *commandList,
		Util *utils,
		ID3D12DescriptorHeap* srvDescriptorHeap,
		// CPU handle for SRC creation.
		CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle,
		// GPU handle for rendering.
		CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle,
		// Size of a descriptor to inrement offset handle with 
		// when a new descriptor is added.
		UINT descriptorSize,
		// FNT file name to load the font file with.
		LPCWSTR fontFilePath,
		// Main application window informations.
		int windowWidth,
		int windowHeight);

	// Draw the text with given string onto the given posisiotn on the 
	// application screen by setting proper PSO and SRV descriptors to pass
	// in the proper vertices for text rendering using DirectX 12 engine.
	void RenderText(
		ID3D12PipelineState* textPSO, 
		ID3D12GraphicsCommandList *commandList, 
		ID3D12DescriptorHeap *dsDescriptorHeap, 
		int frameIndex,
		//Font font, 
		std::wstring text, 
		XMFLOAT2 pos, 
		XMFLOAT2 scale = XMFLOAT2(1.0f, 1.0f), 
		XMFLOAT2 padding = XMFLOAT2(0.5f, 0.0f), 
		XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f));
};

