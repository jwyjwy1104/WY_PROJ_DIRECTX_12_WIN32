#pragma once

#include <wincodec.h>
#include "MyModelAnimation.h"
#include "MyModelObj.h"

class Util {
private:
public:
	// Default constructor.
	Util();

	// Desctructor.
	~Util();

	//==========================================================================
	// Image related.
	//==========================================================================
	// Return the calculated image's width and height 
	// stored in an int array (size 2) 0 - width, 1 - height.
	int *getTextureSizeWidthHeight(std::string textureImageFilePath);

	// Load texture from file + image convertion related.
	int LoadImageDataFromFile(
		BYTE** imageData,
		D3D12_RESOURCE_DESC& resourceDescription,
		LPCWSTR filename,
		int &bytesPerRow);
	DXGI_FORMAT GetDXGIFormatFromWICFormat(
		WICPixelFormatGUID& wicFormatGUID);
	WICPixelFormatGUID GetConvertToWICFormat(
		WICPixelFormatGUID& wicFormatGUID);
	int GetDXGIFormatBitsPerPixel(DXGI_FORMAT& dxgiFormat);

	//==========================================================================
	// Font related
	//==========================================================================
	// Load font from ".fnt" file intializes the properties values into 
	// a Font object and return it.
	// Code brought from: https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
	Font *LoadFont(LPCWSTR filename, int windowWidth, int windowHeight); // load a font

	//==========================================================================
	// File related.
	//==========================================================================
	// Check file exist.
	bool isFileExist(char *filepath);

	// Get directory path of an absolute file path.
	char *getFolderPathFromFileName(const char *absoluteFilePath);

	// Get file extension.
	char *getFileExtensionFromFullPath(const char *absoluteFilePath);

	// Returns the file extension corresponding format number to be used 
	// for model loading.
	int modelLoaderFormatFactoryFileExtensions(char *fileExtension);

	//==========================================================================
	// Print related.
	//==========================================================================
	// Print helper for XMFLOAT3.
	void printXMFLOAT3(char *name, DirectX::XMFLOAT3 *float3);
	// Print helper for DirectX::XMVECTOR.
	void printXMVECTOR3(char *name, DirectX::XMVECTOR *vector);
	// Print helper for DirectX::XMVECTOR.
	void printXMVECTOR4(char *name, DirectX::XMVECTOR *vector);
	// Print helper for XMMATRIX.
	void printXMMATRIX(char *name, DirectX::XMMATRIX *matrix);
	// Print helper for XMMATRIX4X4.
	void printXMFLOAT4x4(char *name, DirectX::XMFLOAT4X4 *float4x4);

	// Print all the animation frame data values valid and stored inside the 
	// MyModelAnimationBone object which is stored in the data structure 
	// of the given MyModelAnimation object.
	void printMyModelAnimation(char *title, MyModelAnimation *anim);

	// Print the animation frame data on the specific index stored in the 
	// given MyModelAnimationBone object.
	void printMyModelAnimationBoneAnimationFrameAtIndex(char *title, MyModelAnimationBone *animBone, int animFrameIndex);

	//==========================================================================
	// Projection & Un-projection.
	//==========================================================================
	// 2D screen space coordinate --> Unproject 
	// --> 3D local space vertex coordinate.
	DirectX::XMVECTOR *get2DscreenSpaceFrom3DworldSpace(
		DirectX::XMVECTOR *localSpaceCoordVector,
		DirectX::XMMATRIX *worldMatrix,
		DirectX::XMMATRIX *viewMatrix,
		DirectX::XMMATRIX *projectionMatrix,
		D3D12_VIEWPORT *viewport);
	// 3D local space vertex coordinate --> Project 
	// --> 2D screen space coordinate.
	DirectX::XMVECTOR *get3DworldSpaceFrom2DscreenSpace(
		DirectX::XMVECTOR *screenSpaceCoordVector,
		DirectX::XMMATRIX *worldMatrix,
		DirectX::XMMATRIX *viewMatrix,
		DirectX::XMMATRIX *projectionMatrix,
		D3D12_VIEWPORT *viewport);

	//==========================================================================
	// Coordinate system related.
	//==========================================================================
	// Read in the coordinate values from fin passed into this funciton
	// and convert them according to the coordinate system UP and FORWARD 
	// vector specified in MyModelObj object and then 
	// returns the converted coordinate value as a VertexType object.
	VertexType *coordinateSystemConversionFromBlenderToDirectX(
		MyModelObj *model, 
		std::ifstream *fin);

	//==========================================================================
	// Extra features.
	//==========================================================================
	// Rounds up a XMVETOR coordinates values.
	void roundDecimal2XMVECTOR3(DirectX::XMVECTOR *src);
};