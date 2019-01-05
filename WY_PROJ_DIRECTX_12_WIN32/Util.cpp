// File name: [Util.cpp] (Copyright to Samil Chai)
// Work Session #0193: 2017-07-24
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4bV9TMnU2cE5rdU0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4bV9TMnU2cE5rdU0
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ampkd203ZnZYQzg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ampkd203ZnZYQzg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ZXoxWHRZWS1xY1k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ZXoxWHRZWS1xY1k
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class is the collection of the utility function to help the program
//			to run.
// - [Comments]:
//		Inner documents done, diagrams adjusted.
//			printMyModelAnimation()
//			printMyModelAnimationBoneAnimationFrameAtIndex()
//			coordinateSystemConversionFromBlenderToDirectX()
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0038
//------------------------------------------------------------------------------
// [rev0002:WY:201707272240]
//------------------------------------------------------------------------------
// File name: [Util.cpp] (Copyright to Samil Chai)
// Work Session #0182: 2017-07-11
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4bV9TMnU2cE5rdU0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4bV9TMnU2cE5rdU0
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ampkd203ZnZYQzg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ampkd203ZnZYQzg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ZXoxWHRZWS1xY1k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ZXoxWHRZWS1xY1k
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class is the collection of the utility function to help the program
//			to run.
// - [Comments]:
//		Coordinate system conversion code has been functionalized and created
//			as a function, to be used for vertex coordinate system conversion
//			during loading data from OBJ files.
//		But i made it into a Util function, is because this kind of function 
//			will be probably used frequently not only in MyModelObj class,
//			eg. MyModelBone class need it to convert the bone's tail and head
//			coordinates.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0024
//------------------------------------------------------------------------------
// [rev0001:WY:201707120030]
//------------------------------------------------------------------------------
// File name: [Util.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4bV9TMnU2cE5rdU0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4bV9TMnU2cE5rdU0
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ampkd203ZnZYQzg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ampkd203ZnZYQzg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ZXoxWHRZWS1xY1k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ZXoxWHRZWS1xY1k
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class is the collection of the utility function to help the program
//			to run.
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0000:WY:201707101940]
//------------------------------------------------------------------------------

//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################
#pragma once

#include "stdafx.h"
#include "Util.h"

// Default constructor
Util::Util() {
}

// Destructor
Util::~Util() {
}
//==============================================================================
// Image related
//==============================================================================
/*
*	Returns the ineteger array of width and height data
*		of a image file on given file path.
*	<p>
*	This function returns the width and height data
*		read from given file path.
*	Code brought from:
*		Stack Overflow Get width and height of image file:
*		http://stackoverflow.com/questions/5354459/c-how-to-get-the-image-size-of-a-png-file-in-directory
*	 @param      textureImageFilePath		Absolute file path of the image
*										file to be accessed to retrive
*										the width and height of the image.
*	@return		Returns an integer pointer of an array of size 2
*					which stores
*					the width of the image on array index 0 and
*					the height of the image on array index 1.
*	@see			ntohl
*	@since		ver0003
*/
int *Util::getTextureSizeWidthHeight(std::string textureImageFilePath) {
	// Integer array to store the width and height data to return
	int *textureSizeWidthHeight;

	// Init integer array to store the width and height data to return
	textureSizeWidthHeight = new int[2];
	textureSizeWidthHeight[0] = 0;
	textureSizeWidthHeight[1] = 0;

	// Get image file size to create resource description, 
	// following includes needed
	//#include <fstream>
	//#include <iostream>
	//#include <winsock.h>
	//#include <winsock2.h>
	std::ifstream in(textureImageFilePath);
	unsigned int width, height;

	in.seekg(16);
	in.read((char *)&width, 4);
	in.read((char *)&height, 4);

	// Width of the image.
	width = ntohl(width);
	// Height of the image.
	height = ntohl(height);

	textureSizeWidthHeight[0] = width;
	textureSizeWidthHeight[1] = height;

	// Return the integer array, index 0 containing width, 1 containing height
	// of the image.
	return textureSizeWidthHeight;
}

/*
*	Load an image file and stores the decoded image pixel data directly onto
*		the pixel data byte array's address passed as the parameter.
*	<p>
*	This function loads the image file with given file path and
*		stores the decoded image pixel data directly
*		onto the pixel data byte array's address passed as the parameter.
*	100% Code brought from:
*		Braynzar Soft Texture from file:
*		https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file
*	This code is called for texture buffer resources initialization
*		through MySpecialModelObj::initTextureBufferResources().
*	@param      imageData                   Address of the integer pointer
*												to hold the decoded pixel data
*												byte array to be loaded
*												on given file path.
*	@param      resourceDescription         DirectX 12 resource description
*												to hold the image data resource.
*	@param      filename                    Absolute path of the image file
*												to load with.
*	@param      bytesPerRow                 Address of the integer variable
*												to hold the number of bytes
*												in each row of the image data.
*	@return     Returns an integer which indicates the result of the process.
*					Returns 0 on failure.
*					Returns 1 on sucess.
*	@see        Util::GetDXGIFormatFromWICFormat()
*	@see        Util::GetConvertToWICFormat()
*	@see        Util::GetDXGIFormatBitsPerPixel()
*	@see        LPCWSTR
*	@see        D3D12_RESOURCE_DESC
*	@see        IWICBitmapDecoder
*	@see        IWICBitmapFrameDecode
*	@see        IWICFormatConverter
*	@since      ver0003
*/int Util::LoadImageDataFromFile(
	BYTE** imageData,
	D3D12_RESOURCE_DESC& resourceDescription,
	LPCWSTR filename,
	int &bytesPerRow) {
	/*string filenamestr = CW2A(filename);
	_RPT1(0, "+++++++++++++++++++++++++++++++++++++++++\n", 0);
	_RPT1(0, "Util::LoadImageDataFromFile : %s\n", filenamestr.c_str());
	_RPT1(0, "+++++++++++++++++++++++++++++++++++++++++\n", 0);*/

	HRESULT hr;

	// we only need one instance of the imaging factory to create decoders and frames
	static IWICImagingFactory *wicFactory;

	// reset decoder, frame and converter since these will be different for each image we load
	IWICBitmapDecoder *wicDecoder = NULL;
	IWICBitmapFrameDecode *wicFrame = NULL;
	IWICFormatConverter *wicConverter = NULL;

	bool imageConverted = false;

	if (wicFactory == NULL)
	{
		// Initialize the COM library
		//CoInitialize(NULL);
		HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

		// create the WIC factory
		hr = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&wicFactory)
		);
		if (FAILED(hr)) return 0;
	}

	// load a decoder for the image
	hr = wicFactory->CreateDecoderFromFilename(
		filename,                        // Image we want to load in
		NULL,                            // This is a vendor ID, we do not prefer a specific one so set to null
		GENERIC_READ,                    // We want to read from this file
		WICDecodeMetadataCacheOnLoad,    // We will cache the metadata right away, rather than when needed, which might be unknown
		&wicDecoder                      // the wic decoder to be created
	);
	if (FAILED(hr)) return 0;

	// get image from decoder (this will decode the "frame")
	hr = wicDecoder->GetFrame(0, &wicFrame);
	if (FAILED(hr)) return 0;

	// get wic pixel format of image
	WICPixelFormatGUID pixelFormat;
	hr = wicFrame->GetPixelFormat(&pixelFormat);
	if (FAILED(hr)) return 0;

	// get size of image
	UINT textureWidth, textureHeight;
	hr = wicFrame->GetSize(&textureWidth, &textureHeight);
	if (FAILED(hr)) return 0;

	//_RPT1(0, "frame size : %d, %d !!\n", textureWidth, textureHeight);

	// we are not handling sRGB types in this tutorial, so if you need that support, you'll have to figure
	// out how to implement the support yourself

	// convert wic pixel format to dxgi pixel format
	DXGI_FORMAT dxgiFormat = GetDXGIFormatFromWICFormat(pixelFormat);

	// if the format of the image is not a supported dxgi format, try to convert it
	if (dxgiFormat == DXGI_FORMAT_UNKNOWN)
	{
		// get a dxgi compatible wic format from the current image format
		WICPixelFormatGUID convertToPixelFormat = GetConvertToWICFormat(pixelFormat);

		// return if no dxgi compatible format was found
		if (convertToPixelFormat == GUID_WICPixelFormatDontCare) return 0;

		// set the dxgi format
		dxgiFormat = GetDXGIFormatFromWICFormat(convertToPixelFormat);

		// create the format converter
		hr = wicFactory->CreateFormatConverter(&wicConverter);
		if (FAILED(hr)) return 0;

		// make sure we can convert to the dxgi compatible format
		BOOL canConvert = FALSE;
		hr = wicConverter->CanConvert(pixelFormat, convertToPixelFormat, &canConvert);
		if (FAILED(hr) || !canConvert) return 0;

		// do the conversion (wicConverter will contain the converted image)
		hr = wicConverter->Initialize(wicFrame, convertToPixelFormat, WICBitmapDitherTypeErrorDiffusion, 0, 0, WICBitmapPaletteTypeCustom);
		if (FAILED(hr)) return 0;

		// this is so we know to get the image data from the wicConverter (otherwise we will get from wicFrame)
		imageConverted = true;
	}

	int bitsPerPixel = GetDXGIFormatBitsPerPixel(dxgiFormat); // number of bits per pixel
	bytesPerRow = (textureWidth * bitsPerPixel) / 8; // number of bytes in each row of the image data
	int imageSize = bytesPerRow * textureHeight; // total image size in bytes

	// allocate enough memory for the raw image data, and set imageData to point to that memory
	*imageData = (BYTE*)malloc(imageSize);

	_RPT1(0, "Util::LoadImageDataFromFile::imageSize: %d\n", imageSize);

	// copy (decoded) raw image data into the newly allocated memory (imageData)
	if (imageConverted)
	{
		//_RPT1(0, "imageConverted !!\n", 0);
		// if image format needed to be converted, the wic converter will contain the converted image
		hr = wicConverter->CopyPixels(0, bytesPerRow, imageSize, *imageData);
		if (FAILED(hr)) return 0;
	}
	else
	{
		//_RPT1(0, "image NOT Converted !!\n", 0);
		// no need to convert, just copy data from the wic frame
		hr = wicFrame->CopyPixels(0, bytesPerRow, imageSize, *imageData);
		if (FAILED(hr)) return 0;
	}

	// now describe the texture with the information we have obtained from the image
	resourceDescription = {};
	resourceDescription.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
	resourceDescription.Alignment = 0; // may be 0, 4KB, 64KB, or 4MB. 0 will let runtime decide between 64KB and 4MB (4MB for multi-sampled textures)
	resourceDescription.Width = textureWidth; // width of the texture
	resourceDescription.Height = textureHeight; // height of the texture
	resourceDescription.DepthOrArraySize = 1; // if 3d image, depth of 3d image. Otherwise an array of 1D or 2D textures (we only have one image, so we set 1)
	resourceDescription.MipLevels = 1; // Number of mipmaps. We are not generating mipmaps for this texture, so we have only one level
	resourceDescription.Format = dxgiFormat; // This is the dxgi format of the image (format of the pixels)
	resourceDescription.SampleDesc.Count = 1; // This is the number of samples per pixel, we just want 1 sample
	resourceDescription.SampleDesc.Quality = 0; // The quality level of the samples. Higher is better quality, but worse performance
	resourceDescription.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN; // The arrangement of the pixels. Setting to unknown lets the driver choose the most efficient one
	resourceDescription.Flags = D3D12_RESOURCE_FLAG_NONE; // no flags

														  //_RPT1(0, "Util::LoadImageDataFromFile::imageSize : %d\n", imageSize);

														  // return the size of the image. remember to delete the image once your done with it (in this tutorial once its uploaded to the gpu)
	return imageSize;
}

/*
*	Returns the DXGI format equivilent of a WIC format.
*  <p>
*  This function returns the converted DXGI pixel format
*		from WIC pixel format address passed as parameter.
*	100% Code brought from:
*		Braynzar Soft Texture from file:
*		https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file
*  @param      wicFormatGUID               WIC pixel format
*												to be used to convert to
*												DXGI pixel format with.
*	@return		Return the converted DXGI pixel format DXGI_FORMAT object.
*  @see        DXGI_FORMAT
*  @see        WICPixelFormatGUID
*  @since      ver0003
*/
DXGI_FORMAT Util::GetDXGIFormatFromWICFormat(
	WICPixelFormatGUID& wicFormatGUID) {
	if (wicFormatGUID == GUID_WICPixelFormat128bppRGBAFloat)
		return DXGI_FORMAT_R32G32B32A32_FLOAT;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGBAHalf)
		return DXGI_FORMAT_R16G16B16A16_FLOAT;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGBA)
		return DXGI_FORMAT_R16G16B16A16_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppRGBA)
		return DXGI_FORMAT_R8G8B8A8_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppBGRA)
		return DXGI_FORMAT_B8G8R8A8_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppBGR)
		return DXGI_FORMAT_B8G8R8X8_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppRGBA1010102XR)
		return DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;

	else if (wicFormatGUID == GUID_WICPixelFormat32bppRGBA1010102)
		return DXGI_FORMAT_R10G10B10A2_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppBGRA5551)
		return DXGI_FORMAT_B5G5R5A1_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppBGR565)
		return DXGI_FORMAT_B5G6R5_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppGrayFloat)
		return DXGI_FORMAT_R32_FLOAT;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppGrayHalf)
		return DXGI_FORMAT_R16_FLOAT;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppGray)
		return DXGI_FORMAT_R16_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat8bppGray)
		return DXGI_FORMAT_R8_UNORM;
	else if (wicFormatGUID == GUID_WICPixelFormat8bppAlpha)
		return DXGI_FORMAT_A8_UNORM;

	else return DXGI_FORMAT_UNKNOWN;
}

/*
*	Returns a DXGI compatible WIC format from another WIC format.
*	<p>
*	This function returns a DXGI compatible wic format calculated from
*		the decoded image format
*		using the image pixel format address passed as parameter.
*	100% Code brought from:
*		Braynzar Soft Texture from file:
*		https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file
*	@param      wicFormatGUID               Current image format to be used
*												to conver to DXGI compatible
*												WIC format with.
*	@return     Returns the converted  DXGI compatible WIC format WICPixelFormatGUID object.
*	@see        DXGI_FORMAT
*	@see        WICPixelFormatGUID
*	@since      ver0003
*/
WICPixelFormatGUID Util::GetConvertToWICFormat(
	WICPixelFormatGUID& wicFormatGUID) {
	if (wicFormatGUID == GUID_WICPixelFormatBlackWhite)
		return GUID_WICPixelFormat8bppGray;
	else if (wicFormatGUID == GUID_WICPixelFormat1bppIndexed)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat2bppIndexed)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat4bppIndexed)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat8bppIndexed)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat2bppGray)
		return GUID_WICPixelFormat8bppGray;
	else if (wicFormatGUID == GUID_WICPixelFormat4bppGray)
		return GUID_WICPixelFormat8bppGray;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppGrayFixedPoint)
		return GUID_WICPixelFormat16bppGrayHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppGrayFixedPoint)
		return GUID_WICPixelFormat32bppGrayFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat16bppBGR555)
		return GUID_WICPixelFormat16bppBGRA5551;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppBGR101010)
		return GUID_WICPixelFormat32bppRGBA1010102;
	else if (wicFormatGUID == GUID_WICPixelFormat24bppBGR)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat24bppRGB)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppPBGRA)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppPRGBA)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat48bppRGB)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat48bppBGR)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppBGRA)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppPRGBA)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppPBGRA)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat48bppRGBFixedPoint)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat48bppBGRFixedPoint)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGBAFixedPoint)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppBGRAFixedPoint)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGBFixedPoint)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGBHalf)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat48bppRGBHalf)
		return GUID_WICPixelFormat64bppRGBAHalf;
	else if (wicFormatGUID == GUID_WICPixelFormat128bppPRGBAFloat)
		return GUID_WICPixelFormat128bppRGBAFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat128bppRGBFloat)
		return GUID_WICPixelFormat128bppRGBAFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat128bppRGBAFixedPoint)
		return GUID_WICPixelFormat128bppRGBAFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat128bppRGBFixedPoint)
		return GUID_WICPixelFormat128bppRGBAFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppRGBE)
		return GUID_WICPixelFormat128bppRGBAFloat;
	else if (wicFormatGUID == GUID_WICPixelFormat32bppCMYK)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppCMYK)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat40bppCMYKAlpha)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat80bppCMYKAlpha)
		return GUID_WICPixelFormat64bppRGBA;

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
	else if (wicFormatGUID == GUID_WICPixelFormat32bppRGB)
		return GUID_WICPixelFormat32bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppRGB)
		return GUID_WICPixelFormat64bppRGBA;
	else if (wicFormatGUID == GUID_WICPixelFormat64bppPRGBAHalf)
		return GUID_WICPixelFormat64bppRGBAHalf;
#endif

	else return GUID_WICPixelFormatDontCare;
}

/*
*	Returns the number of bits per pixel for a DXGI format.
*	<p>
*	This function returns the number of bits per pixel
*		corresponds to the DXGI format address passed as parameter.
*	100% Code brought from:
*		Braynzar Soft Texture from file:
*		https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file
*	@param      dxgiFormat               Current DXGI format to be used
*											to calculate the
*											number of bits per pixel with.
*	@return     Returns the converted number of bits per pixel integer value.
*	@see        DXGI_FORMAT
*	@since      ver0003
*/
int Util::GetDXGIFormatBitsPerPixel(DXGI_FORMAT& dxgiFormat) {
	if (dxgiFormat == DXGI_FORMAT_R32G32B32A32_FLOAT) return 128;
	else if (dxgiFormat == DXGI_FORMAT_R16G16B16A16_FLOAT) return 64;
	else if (dxgiFormat == DXGI_FORMAT_R16G16B16A16_UNORM) return 64;
	else if (dxgiFormat == DXGI_FORMAT_R8G8B8A8_UNORM) return 32;
	else if (dxgiFormat == DXGI_FORMAT_B8G8R8A8_UNORM) return 32;
	else if (dxgiFormat == DXGI_FORMAT_B8G8R8X8_UNORM) return 32;
	else if (dxgiFormat == DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM) return 32;

	else if (dxgiFormat == DXGI_FORMAT_R10G10B10A2_UNORM) return 32;
	else if (dxgiFormat == DXGI_FORMAT_B5G5R5A1_UNORM) return 16;
	else if (dxgiFormat == DXGI_FORMAT_B5G6R5_UNORM) return 16;
	else if (dxgiFormat == DXGI_FORMAT_R32_FLOAT) return 32;
	else if (dxgiFormat == DXGI_FORMAT_R16_FLOAT) return 16;
	else if (dxgiFormat == DXGI_FORMAT_R16_UNORM) return 16;
	else if (dxgiFormat == DXGI_FORMAT_R8_UNORM) return 8;
	else if (dxgiFormat == DXGI_FORMAT_A8_UNORM) return 8;
	return -1;
}

//==============================================================================
// Font related
//==============================================================================
// Code brought from: https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
Font *Util::LoadFont(LPCWSTR filename, int windowWidth, int windowHeight) {
	Font *font = new Font();

	// Local buffers Init for current project directory path retrieving.
	char finalFontAbsFilePath[FILENAME_MAX];
	char currentFontFilePath[FILENAME_MAX];
	char currentFontFileName[FILENAME_MAX];
	std::fill(finalFontAbsFilePath, finalFontAbsFilePath + FILENAME_MAX, NULL);
	std::fill(currentFontFilePath, currentFontFilePath + FILENAME_MAX, NULL);
	std::fill(currentFontFileName, currentFontFileName + FILENAME_MAX, NULL);

	// Get current working directory path and store it into local buffers.
	if (!GetCurrentDir(currentFontFilePath, sizeof(currentFontFilePath))) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::Util::LoadFont::GetCurrentDir() failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	//=========================================================================
	// Need to specify to the Debug folder because all the assets are in the 
	// project's Debug folder, but this get current directory function is 
	// retrieving the directory path of current file MyModelLoader.cpp
	// so i concat "\..\Debug" to specify to the Debug folder in current 
	// project folder.
	//=========================================================================
	strncat_s(currentFontFilePath, FILENAME_MAX,
		"\\..\\Debug", FILENAME_MAX);

	/* not really required */
	currentFontFilePath[sizeof(currentFontFilePath) - 1] = '\0';
	//=========================================================================

	// Print current working directory path.
	//_RPT1(0, "Util::LoadFont::The current working directory is: |%s|\n", currentFontFilePath);

	// Copy Font file name to a local buffer.
	char filenameCStr[500];
	wcstombs(filenameCStr, filename, 500);
	strcpy(currentFontFileName, filenameCStr);

	// Copy working directory path to another local buffer.
	strncpy_s(finalFontAbsFilePath, FILENAME_MAX,
		currentFontFilePath, FILENAME_MAX);

	// Concat Font file name onto current working directory path.
	strncat_s(finalFontAbsFilePath, FILENAME_MAX,
		currentFontFileName, FILENAME_MAX);

	// Final Font absolute file path.
	//_RPT1(0, "Util::LoadFont::Final Font absolute file path : |%s|\n", finalFontAbsFilePath);

	// Convert the final Font absolute file path C-string to LPCWSTR
	wchar_t finalFontAbsFilePathWstr[260];
	std::mbstowcs(finalFontAbsFilePathWstr, finalFontAbsFilePath, 260);
	_RPT1(0, "Util::LoadFont::Final Font absolute file path : |%S|\n", finalFontAbsFilePathWstr); // Need to print with capital %S

																								  // Open file
	std::wifstream fs;
	fs.open(finalFontAbsFilePathWstr);

	if (fs.fail()) {
		_RPT1(0, "Util::LoadFont::Font file open failed\n", 0);
	}

	//Font font;
	std::wstring tmp;
	int startpos;

	// extract font name
	fs >> tmp >> tmp; // info face="Arial"
	startpos = tmp.find(L"\"") + 1;
	font->name = tmp.substr(startpos, tmp.size() - startpos - 1);

	// get font size
	fs >> tmp; // size=73
	startpos = tmp.find(L"=") + 1;
	font->size = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

	// bold, italic, charset, unicode, stretchH, smooth, aa, padding, spacing
	fs >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp >> tmp; // bold=0 italic=0 charset="" unicode=0 stretchH=100 smooth=1 aa=1 

														 // get padding
	fs >> tmp; // padding=5,5,5,5 
	startpos = tmp.find(L"=") + 1;
	tmp = tmp.substr(startpos, tmp.size() - startpos); // 5,5,5,5

													   // get up padding
	startpos = tmp.find(L",") + 1;
	font->toppadding = std::stoi(tmp.substr(0, startpos)) / (float)windowWidth;

	// get right padding
	tmp = tmp.substr(startpos, tmp.size() - startpos);
	startpos = tmp.find(L",") + 1;
	font->rightpadding = std::stoi(tmp.substr(0, startpos)) / (float)windowWidth;

	// get down padding
	tmp = tmp.substr(startpos, tmp.size() - startpos);
	startpos = tmp.find(L",") + 1;
	font->bottompadding = std::stoi(tmp.substr(0, startpos)) / (float)windowWidth;

	// get left padding
	tmp = tmp.substr(startpos, tmp.size() - startpos);
	font->leftpadding = std::stoi(tmp) / (float)windowWidth;

	fs >> tmp; // spacing=0,0

			   // get lineheight (how much to move down for each line), and normalize (between 0.0 and 1.0 based on size of font)
	fs >> tmp >> tmp; // common lineHeight=95
	startpos = tmp.find(L"=") + 1;
	font->lineHeight = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)windowHeight;

	// get base height (height of all characters), and normalize (between 0.0 and 1.0 based on size of font)
	fs >> tmp; // base=68
	startpos = tmp.find(L"=") + 1;
	font->baseHeight = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)windowHeight;

	// get texture width
	fs >> tmp; // scaleW=512
	startpos = tmp.find(L"=") + 1;
	font->textureWidth = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

	// get texture height
	fs >> tmp; // scaleH=512
	startpos = tmp.find(L"=") + 1;
	font->textureHeight = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

	// get pages, packed, page id
	fs >> tmp >> tmp; // pages=1 packed=0
	fs >> tmp >> tmp; // page id=0

					  //==========================================================================
					  // get texture filename
					  //==========================================================================
	std::wstring wtmp;
	fs >> wtmp; // file="Arial.png"
	startpos = wtmp.find(L"\"") + 1;
	// Get wstring of font image file path
	wstring temp = wtmp.substr(startpos, wtmp.size() - startpos - 1);

	// Convert wstring to char * font image file path
	char fontImageCStr[260];
	wcstombs(fontImageCStr, temp.c_str(), 260);

	// Debug folder directory path + '\'
	char *fntImagefilePath = strcat(currentFontFilePath, "\\");

	// Font image absolute file path
	//    = Debug folder directory path + '\' + Font image relative file path
	fntImagefilePath = strcat(currentFontFilePath, fontImageCStr);

	// Convert Font image absolute file path char * to wchar_t array
	wchar_t buffer[260];
	mbstowcs(buffer, fntImagefilePath, 260);
	_RPT1(0, "Util::LoadFont::Final Font image absolute file path : |%S|\n", buffer); // Need to print with capital %S

																					  // Set the Font image absolute file path to the Font object fontImage 
	font->fontImage = buffer;
	//==========================================================================

	//font->fontImage = wtmp.substr(startpos, wtmp.size() - startpos - 1);

	// get number of characters
	fs >> tmp >> tmp; // chars count=97
	startpos = tmp.find(L"=") + 1;
	font->numCharacters = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

	// initialize the character list
	font->CharList = new FontChar[font->numCharacters];

	for (int c = 0; c < font->numCharacters; ++c)
	{
		// get unicode id
		fs >> tmp >> tmp; // char id=0
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].id = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

		// get x
		fs >> tmp; // x=392
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].u = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)font->textureWidth;

		// get y
		fs >> tmp; // y=340
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].v = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)font->textureHeight;

		// get width
		fs >> tmp; // width=47
		startpos = tmp.find(L"=") + 1;
		tmp = tmp.substr(startpos, tmp.size() - startpos);
		font->CharList[c].width = (float)std::stoi(tmp) / (float)windowWidth;
		font->CharList[c].twidth = (float)std::stoi(tmp) / (float)font->textureWidth;

		// get height
		fs >> tmp; // height=57
		startpos = tmp.find(L"=") + 1;
		tmp = tmp.substr(startpos, tmp.size() - startpos);
		font->CharList[c].height = (float)std::stoi(tmp) / (float)windowHeight;
		font->CharList[c].theight = (float)std::stoi(tmp) / (float)font->textureHeight;

		// get xoffset
		fs >> tmp; // xoffset=-6
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].xoffset = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)windowWidth;

		// get yoffset
		fs >> tmp; // yoffset=16
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].yoffset = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)windowHeight;

		// get xadvance
		fs >> tmp; // xadvance=65
		startpos = tmp.find(L"=") + 1;
		font->CharList[c].xadvance = (float)std::stoi(tmp.substr(startpos, tmp.size() - startpos)) / (float)windowWidth;

		// get page
		// get channel
		fs >> tmp >> tmp; // page=0    chnl=0
	}

	// get number of kernings
	fs >> tmp >> tmp; // kernings count=96
	startpos = tmp.find(L"=") + 1;
	font->numKernings = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

	// initialize the kernings list
	font->KerningsList = new FontKerning[font->numKernings];

	for (int k = 0; k < font->numKernings; ++k)
	{
		// get first character
		fs >> tmp >> tmp; // kerning first=87
		startpos = tmp.find(L"=") + 1;
		font->KerningsList[k].firstid = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

		// get second character
		fs >> tmp; // second=45
		startpos = tmp.find(L"=") + 1;
		font->KerningsList[k].secondid = std::stoi(tmp.substr(startpos, tmp.size() - startpos));

		// get amount
		fs >> tmp; // amount=-1
		startpos = tmp.find(L"=") + 1;
		int t = std::stoi(tmp.substr(startpos, tmp.size() - startpos));
		font->KerningsList[k].amount = (float)t / (float)windowWidth;
	}

	return font;
}

//==============================================================================
// File related
//==============================================================================
/*
*	Validate the file path passed as parameter.
*	<p>
*	This function validates the file path passed as parameter,
*		to check if the file exist on given file path.
*	@param      filepath                File path to validate with.
*	@return     Returns false if the given file path is not valid.
*				Returns true if the given file path is valid.
*	@since      ver0003
*/
bool Util::isFileExist(char *filepath) {
	// Result boolean flag.
	bool result = false;
	if (filepath != NULL) {
		// Open file.
		ifstream f(filepath);
		_RPT1(0, "Util::isFileExist : %s\n", filepath);
		if (f.good() == true) {
			_RPT1(0, "Util::isFileExist : Return True\n", 0);
			// Return true if file is valid to open.
			return true;
		}
		else {
			_RPT1(0, "Util::isFileExist :Return False\n", 0);
			// Return false if file is invalid to open.
			return false;
		}
	}
}

/*
*	Returns the directory path of the absolute file path passed as parameter.
*	<p>
*	This function returns the directory path
*		the absolute file path passed as parameter,
*		by finding the last '\' index and copy the characters
*		before the last '\' index onto the character buffer to return.
*	This function is used on loading MTL file and image file
*		when OBJ file is loaded through MyModelLoader,
*		because the MTL file is relative path
*		so I need the directory path to combine
*		the absolute MTL file path to load it.
*	@param      absoluteFilePath       Absolute file path to convert with.
*	@return     Returns the directory path in C-String.
*	@since      ver0003
*/
char *Util::getFolderPathFromFileName(const char *absoluteFilePath) {
	// Index counter.
	int index = 0;
	// Index of the last '\' character.
	int lastSlashIndex = 0;

	// Find last '\' character
	while (absoluteFilePath[index] != '\0') {
		if (absoluteFilePath[index] == '\\') {
			// Store last '\' character index
			lastSlashIndex = index;
		}
		// Increment index.
		index++;
	}

	// Local buffer to store the folder/directory path.
	// String before the last '\' character.
	char *folder = new char[BUFSIZ]();
	std::fill(folder, folder + BUFSIZ, 0);

	//// Local buffer to store the file name.
	//// String after the last '\' character.
	//char *file = new char[BUFSIZ]();
	//std::fill(file, file + BUFSIZ, 0);

	// Get directory path using last "\" index

	// Copy string before the last '\' character, folder/directory path 
	// to the local buffer.
	strncpy(folder, absoluteFilePath, lastSlashIndex);

	//// Copy string after the last '\' character, file name to the local buffer.
	//strncpy(file, absoluteFilePath + lastSlashIndex, index - lastSlashIndex);

	//_RPT1(0, "Util::getFolderPathFromFileName::Directory path: %s\n", folder);
	//_RPT1(0, "Util::getFolderPathFromFileName::File name: %s\n", file);
	//_RPT1(0, "Util::getFolderPathFromFileName::Last slash index: %d\n", lastSlashIndex);

	// Return the directory path retrieved.
	return folder;
}

/*
*	Returns the extension of a file found in the given full path
*		passed as parameter.
*	<p>
*	This function returns the extension of
*		the absolute file path passed as parameter,
*		by finding the last '.' index and copy the characters.
*	This function is used on dedtermining the format to load the models
*		when OBJ file is loaded through MyModelLoader,
*		because the loading mechanism will be different on different file
*		extensions, so I need the extension to decide.
*	@param      filePath       Absolute file path to retrieve file extension
*							   with.
*	@return     Returns the file extension C-String.
*	@since      ver0108
*/
char *Util::getFileExtensionFromFullPath(const char *absoluteFilePath) {
	_RPT1(0, "Util::getFileExtensionFromFullPath::Get extension from: %s\n", absoluteFilePath);
	// Index counter.
	int index = 0;

	// Index of the last '\' character.
	int lastSlashIndex = 0;

	// Find last '.' character
	while (absoluteFilePath[index] != '\0') {
		if (absoluteFilePath[index] == '.') {
			lastSlashIndex = index;
		}
		index++;
	}

	// Local buffer.
	char *fileExtension = new char[BUFSIZ]();
	std::fill(fileExtension, fileExtension + BUFSIZ, 0);

	// Store the rest of the string after last '.' character 
	// to the local buffer.
	strncpy(
		fileExtension, 
		absoluteFilePath + lastSlashIndex, 
		index - lastSlashIndex);

	// Return the retrieved file extension c-string.
	return fileExtension;
}

// 

/*
*	Returns the file extension corresponding format number
*		to be used for model loading using the file extension string passed as
*		parameter.
*	<p>
*	This function returns the corresponding format number using the
*		extension of the absolute file path passed as parameter,
*		by finding the last '.' index and copy the rest of the characters.
*	This function is used to dedtermine the format to load the models
*		when OBJ file is loaded through MyModelLoader,
*		because the loading mechanism will be different on different file
*		extensions, so I decided to let the extension decide whichever format
*		to load the file.
*	@param      fileExtension       File extension C-string value to determine
*										the loading mechanism format number with.
*	@return     Returns the file extension C-String.
*	@since      ver0108
*/
int Util::modelLoaderFormatFactoryFileExtensions(char *fileExtension) {
	_RPT1(0, "Util::modelLoaderFormatFactoryFileExtensions::File extension: %s\n", fileExtension);

	// If file extension is ".obj" return "MODEL_LOADER_FORMAT_OBJ" = 100
	if (strncmp(fileExtension, ".obj", 4) == 0) {
		_RPT1(0, "Util::modelLoaderFormatFactoryFileExtensions::File format: OBJ\n", 0);
		return MODEL_LOADER_FORMAT_OBJ;
	}
	// If file extension is ".wyo" return "MODEL_LOADER_FORMAT_WYO" = 101
	else if ((strncmp(fileExtension, ".wyo", 4) == 0) ||
		strncmp(fileExtension, ".txt", 4) == 0) {
		_RPT1(0, "Util::modelLoaderFormatFactoryFileExtensions::File format: WYO\n", 0);
		return MODEL_LOADER_FORMAT_WYO;
	}
	// Else invalid file extension to load
	else {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::Util::modelLoaderFormatFactoryFileExtensions::File format invalid\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		return -1;
	}
}

//=============================================================================
// Print related
//=============================================================================
/*
*	Prints a XMFLOAT3 coordinate values.
*	<p>
*	This function prints the XMFLOAT3 coordinate values
*		in following format [NAME : (X,Y,Z)]
*	@param		name				The XMFLOAT3 source name.
*	@param		float3				The XMFLOAT3 source.
*	@return		void
*   @since      ver0003
*/
void Util::printXMFLOAT3(char *name, XMFLOAT3 *float3) {
	_RPT1(0, "XMFLOAT3 [Name : %s] : (%f, %f, %f)\n",
		name,
		float3->x,
		float3->y,
		float3->z);
}
/*
*	Prints a XMVECTOR coordinate values.
*	<p>
*	This function prints only the x, y, z component of the XMVECTOR coordinate
*		in following format [NAME : (X,Y,Z)]
*	@param		name				The XMVECTOR source name.
*	@param		vector				The XMVECTOR source.
*	@return		void
*   @since      ver0003
*/
void Util::printXMVECTOR3(char *name, XMVECTOR *vector) {
	_RPT1(0, "XMVECTOR [Name : %s] : (%f, %f, %f)\n",
		name,
		vector->m128_f32[0],
		vector->m128_f32[1],
		vector->m128_f32[2]);
}
/*
*	Prints a XMVECTOR coordinate values.
*	<p>
*	This function prints the x, y, z and w component of the XMVECTOR coordinate
*		in following format [NAME : (X,Y,Z,W)]
*	@param		name				The XMVECTOR source name.
*	@param		vector				The XMVECTOR source.
*	@return		void
*   @since      ver0003
*/
void Util::printXMVECTOR4(char *name, XMVECTOR *vector) {
	_RPT1(0, "XMVECTOR [Name : %s] : (%f, %f, %f, %f)\n",
		name,
		vector->m128_f32[0],
		vector->m128_f32[1],
		vector->m128_f32[2],
		vector->m128_f32[3]);
}
/*
*	Prints a XMMATRIX element values.
*	<p>
*	This function prints the matrix element values
*		in following format [NAME : (01,02,03,04\n11,12,13,14 ... 41,42,43,44)]
*	@param		name				The XMMATRIX source name.
*	@param		matrix				The XMMATRIX source.
*	@return		void
*   @since      ver0003
*/
void Util::printXMMATRIX(char *name, XMMATRIX *matrix) {
	XMFLOAT4X4 matrix4x4;
	XMStoreFloat4x4(&matrix4x4, *matrix);

	_RPT1(0, "XMMATRIX [Name : %s] : \n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n",
		name,
		matrix4x4._11, matrix4x4._12, matrix4x4._13, matrix4x4._14,
		matrix4x4._21, matrix4x4._22, matrix4x4._23, matrix4x4._24,
		matrix4x4._31, matrix4x4._32, matrix4x4._33, matrix4x4._34,
		matrix4x4._41, matrix4x4._42, matrix4x4._43, matrix4x4._44);
}
/*
*	Prints a XMFLOAT4X4 element values.
*	<p>
*	This function prints the matrix element values
*		in following format [NAME : (01,02,03,04\n11,12,13,14 ... 41,42,43,44)]
*	@param		name				The XMFLOAT4X4 source name.
*	@param		float4x4			The XMFLOAT4X4 source.
*	@return		void
*   @since      ver0003
*/
void Util::printXMFLOAT4x4(char *name, XMFLOAT4X4 *float4x4) {
	_RPT1(0, "XMFLOAT4X4 [Name : %s]  : \n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n\t%f, %f, %f, %f\n",
		name,
		float4x4->_11, float4x4->_12, float4x4->_13, float4x4->_14,
		float4x4->_21, float4x4->_22, float4x4->_23, float4x4->_24,
		float4x4->_31, float4x4->_32, float4x4->_33, float4x4->_34,
		float4x4->_41, float4x4->_42, float4x4->_43, float4x4->_44);
}

/*
*	Print all the animation frame data values valid and stored inside the 
*	MyModelAnimationBone object which is stored in the data structure of the 
*	given MyModelAnimation object.
*	<p>
*	This function prints all the animation frame data XMFLOAT4X4 value stored 
*		inside a MyModelAnimationBone object stored in the data structure of the 
*		given MyModelAnimation object, so iterate throuhg the given 
*		MyModelAnimation object to print the animation bone data.
*	@param		title		String to be printed before the information.
*	@param		anim		MyModelAnimation object to print each 
*							MyModelAnimationBone object's animation frame 
*							data with.
*	@return		void
*   @see        MyModelAnimation
*   @since      ver0038
*/
void Util::printMyModelAnimation(char *title, MyModelAnimation *anim) {
	// If MyModelAnimation object is valid.
	if (anim != NULL) {
		// Loop through the MyModelAnimation object.
		for (int i = 0; i < anim->getNumAnimationBones(); i++) {
			// Print the XMFLOAT4X4 value inside each MyModelAnimationBone 
			// object found on the looping index position.
			for (int j = 0; j < 4; j++) {
				_RPT1(0, "%s : (%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)\n",
					title,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._11,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._12,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._13,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._14,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._21,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._22,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._23,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._24,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._31,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._32,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._33,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._34,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._41,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._42,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._43,
					anim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._44);
			}
		}
	}
}

/*
*	Print the animation frame data on the specific index stored in the 
*	given MyModelAnimationBone object.
*	<p>
*	This function print the animation frame data on the specific index 
*	stored in the given MyModelAnimationBone object, iterate throught the 
*	animation queue inside MyModelAnimationBone object to print all the 
*	XMFLOAT4X4 value stored in the data structure queue.
*	@param		title		String to be printed before the information.
*	@param		animBone	MyModelAnimationBone object which holds the 
*							animation frame data to be printed.
*	@return		void
*   @see        MyModelAnimationBone
*   @since      ver0038
*/
void Util::printMyModelAnimationBoneAnimationFrameAtIndex(char *title, MyModelAnimationBone *animBone, int animFrameIndex) {
	if (animBone != NULL) {
		_RPT1(0, "%s : [%d](%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)\n",
			title,
			animFrameIndex,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._11,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._12,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._13,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._14,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._21,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._22,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._23,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._24,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._31,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._32,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._33,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._34,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._41,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._42,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._43,
			animBone->getAnimationFrameAtIndex(animFrameIndex)->worldMatrix._44);
	}
}

//=============================================================================
// Projection & Un-projection
//=============================================================================
/*
*	Convert 3D local vertex coordinate into 2D camera screen pixel coordinate
*	<p>
*	This function calculates and returns
*		the screen space [0,0][viewport width, height] pixel coordinate
*		converted with unprojection algorithm
*		from a local space (Model origin (0,0,0)) vertex coordinate.
*	Local space --> World space --> Eye space --> Homogeneous clip space
*		--> Normalized device space [-1, 1] [1, -1]
*		--> Viewport space [0, 0] [viewport width, viewport height]
*	Caution!!! The converted screen space coordinate's Z value
*		will affect the projection back to world space coordinate,
*		because the near clipping screen depth value is needed
*		in between 0 and 1 (eg. 0.999 = 0.01 near clipping)
*		in order to project back to local space coordinate.
*	@param		localSpaceCoordVector	3D locxal vertex coordinate
*											to unproject with with.
*	@param		modelMatrix				Matrix of the model
*											transformations
*											(Identity at first)
*	@param		viewMatrix				Matrix of the
*											camera position and
*											directions.
*	@param		projectionMatrix		Matrix of the
*											camera prespective
*											field of view.
*	@param		viewport				Data of the screen viewport
*											(Width height)
*	@return		Returns the screen space pixel coordinate XMVECTOR
*					converted from 3D local space vertex coordinates.
*   @see		Util::printXMVECTOR3()
*   @see		Util::printXMVECTOR4()
*   @see		Util::printXMMATRIX()
*   @see		XMVectorSet()
*   @see		XMMatriXMultiply()
*   @see		XMVector3TransformCoord()
*   @since      ver0003
*/
XMVECTOR *Util::get2DscreenSpaceFrom3DworldSpace(
	XMVECTOR *localSpaceCoordVector,
	XMMATRIX *modelMatrix,
	XMMATRIX *viewMatrix,
	XMMATRIX *projectionMatrix,
	D3D12_VIEWPORT *viewport) {
	// Result vector
	XMVECTOR *screenCoord = new XMVECTOR();

	//==========================================================================
	//==========================================================================
	//==========================================================================
	// Projection test
	//
	// Local space --> World space --> Eye space --> Homogeneous clip space
	// --> Normalized device space [-1, 1] [1, -1] 
	// --> Viewport space [0, 0] [viewport width, viewport height]
	// eg. 
	// Screen width = 800, height = 600
	// 3D Local vertex coordinate (0,0,0) 
	//		--> 2D Screen space pixel coordinate (400, 300) 
	// Testing: 
	//	Draw a point on the local vertex coordinate (0,0,0), 
	//	and use mouse cursor to point to the blue diamond origin point and 
	//	using key input (press [W]) to print the mouse coordinate values
	//	to check the screen space coodrinate)
	//			(1,1,0) --> (114, 14)
	//			(1,1,1) --> (228, 128)
	//			(2,1,5) --> (268, 234)
	//==========================================================================
	_RPT1(0, "=====================================================================================\n", 0);
	_RPT1(0, "Projection test\n", 0);
	_RPT1(0, "=====================================================================================\n", 0);
	XMVECTOR localCoord;
	localCoord = XMVectorSet(2.0f, 1.0f, 5.0f, 1.0f);
	printXMVECTOR3("localCoord", &localCoord);
	printXMMATRIX("modelMatrix", modelMatrix);
	printXMMATRIX("viewMatrix", viewMatrix);
	printXMMATRIX("projectionMatrix", projectionMatrix);


	//==========================================================================
	// Local space --> World space --> Eye space --> Homogeneous clip space 
	// World view projection matrix (WVP) 
	//		= * model matrix * view matrix * projection matrix
	//==========================================================================
	XMMATRIX wvp( // Identity matrix.
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	// Need to cast to const static_cast<const XMMATRIX> before multiplication, 
	// or else will have runtime error (DirectXMathMatrix.inl)
	wvp = XMMatrixMultiply(wvp, static_cast<const XMMATRIX>(*modelMatrix));
	wvp = XMMatrixMultiply(wvp, static_cast<const XMMATRIX>(*viewMatrix));
	wvp = XMMatrixMultiply(
		wvp,
		static_cast<const XMMATRIX>(*projectionMatrix));
	printXMMATRIX("wvp", &wvp);

	// Homogeneous clip space --> Normalized device space [-1, 1] [1, -1]
	localCoord = XMVector3TransformCoord(localCoord, wvp);
	printXMVECTOR4("localCoord", &localCoord);

	// Normalized device space [-1, 1] [1, -1] 
	//		--> Viewport space [0, 0] [viewport width, viewport height]
	localCoord.m128_f32[0]
		= ((localCoord.m128_f32[0] + 1.0f) / 2.0f) * viewport->Width;
	localCoord.m128_f32[1]
		= ((1.0f - localCoord.m128_f32[1]) / 2.0f) * viewport->Height;
	printXMVECTOR4("localCoord", &localCoord);

	// Result values
	screenCoord->m128_f32[0] = localCoord.m128_f32[0];
	screenCoord->m128_f32[1] = localCoord.m128_f32[1];
	screenCoord->m128_f32[2] = localCoord.m128_f32[2];

	// Return the resulting screen space coordinate XMVECTOR value.
	return screenCoord;
}

/*
*	Convert 2D camera screen pixel coordinate into locxal vertex coordinate
*	<p>
*	This function calculates and returns
*		the local space (Model origin (0,0,0)) vertex coordinate
*		converted with projection algorithm
*		from a screen space [0,0][viewport width, height] pixel coordinate
*		+ Clip space distance.
*	Viewport space [0, 0] [viewport width, viewport height]
*		--> Normalized device space [-1, 1] [1, -1]
*		--> Homogeneous clip space --> Eye space --> World space
*		--> Local space
*	Caution!!! The screen space coordinate's Z value,
*		near clipping screen depth value,
*		must be valid in between 0 and 1 (eg. 0.999 = 0.01 near clipping)
*		in order to convert to unprojected 3D local space coordinate.
*	@param		screenSpaceCoordVector	2D camera screen pixel coordinate.
*	@param		modelMatrix				Matrix of the model
*											transformations
*											(Identity at first)
*	@param		viewMatrix				Matrix of the
*											camera position and
*											directions.
*	@param		projectionMatrix		Matrix of the
*											camera prespective
*											field of view.
*	@param		viewport				Data of the screen viewport
*											(Width height)
*	@return		Returns the 3D local space vertex coordinates XMVECTOR
*					converted from the screen space pixel coordinate.
*   @since      ver0003
*/
XMVECTOR *Util::get3DworldSpaceFrom2DscreenSpace(
	XMVECTOR *screenSpaceCoordVector,
	XMMATRIX *modelMatrix,
	XMMATRIX *viewMatrix,
	XMMATRIX *projectionMatrix,
	D3D12_VIEWPORT *viewport) {
	// Result vector
	XMVECTOR *localCoord = new XMVECTOR();

	//==========================================================================
	//==========================================================================
	//==========================================================================
	// Unrojection test
	//
	// Viewport space [0, 0] [viewport width, viewport height] 
	// -->  Normalized device space [-1, 1] [1, -1] --> 
	// Homogeneous clip space --> Eye space --> World space 
	// --> Local space 
	// eg.
	// Screen width = 800, height = 600
	// 2D Screen space pixel coordinate (400, 300) 
	//		--> 3D Local vertex coordinate (0,0,0)
	// Testing: 
	//	Draw a point on the local vertex coordinate (0,0,0), 
	//	and use mouse cursor to point to the blue diamond origin point and 
	//	using key input (press [W]) to print the mouse coordinate values
	//	to check the screen space coodrinate)	//			(114, 14) --> (1,1,0) --> 
	//			(228, 128) --> Clip space Z = 1 --> (1,1,1)
	//			(268, 234) --> Clip space Z = 5 --> (2,1,5) 
	//==========================================================================
	//==========================================================================
	//==========================================================================
	/*_RPT1(0, "=====================================================================================\n", 0);
	_RPT1(0, "Unprojection test\n", 0);
	_RPT1(0, "=====================================================================================\n", 0);*/


	// Screen space coordinate 
	XMVECTOR screenCoordUnproject;
	screenCoordUnproject = XMVectorSet(
		screenSpaceCoordVector->m128_f32[0],
		screenSpaceCoordVector->m128_f32[1],
		screenSpaceCoordVector->m128_f32[2],
		screenSpaceCoordVector->m128_f32[3]);
	//printXMVECTOR4("screenCoordUnproject", &screenCoordUnproject);

	// Viewport space [0, 0] [viewport width, viewport height]
	// --> Normalized device space [-1, 1] [1, -1]
	screenCoordUnproject.m128_f32[0]
		= (((screenCoordUnproject.m128_f32[0] / viewport->Width) * 2) - 1);
	screenCoordUnproject.m128_f32[1]
		= ((((screenCoordUnproject.m128_f32[1] / viewport->Height) * 2) - 1) * -1);
	//printXMVECTOR4("screenCoordUnproject", &screenCoordUnproject);

	//=========================================================================
	// Normalized device space [-1, 1] [1, -1] --> Homogeneous clip space 
	//		--> Eye space --> World space --> Local space 
	// World view projection matrix (WVP) 
	//		= * model matrix * view matrix * projection matrix
	//=========================================================================
	XMMATRIX inverseWVP( // Identity matrix = model matrix
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	//printXMMATRIX("modelMatrix", modelMatrix);
	//printXMMATRIX("viewMatrix", viewMatrix);
	//printXMMATRIX("projectionMatrix", projectionMatrix);

	inverseWVP = XMMatrixMultiply(
		inverseWVP,
		static_cast<const XMMATRIX>(*viewMatrix));
	inverseWVP = XMMatrixMultiply(
		inverseWVP,
		static_cast<const XMMATRIX>(*projectionMatrix));
	inverseWVP = XMMatrixInverse(
		nullptr,
		inverseWVP);
	//printXMMATRIX("inverseWVP", &inverseWVP);

	// Normalized device space [-1, 1] [1, -1] --> Homogeneous clip space
	screenCoordUnproject
		= XMVector3TransformCoord(screenCoordUnproject, inverseWVP);
	//printXMVECTOR4("screenCoordUnproject * inverse wvp", &screenCoordUnproject);

	// Result values
	localCoord->m128_f32[0] = screenCoordUnproject.m128_f32[0];
	localCoord->m128_f32[1] = screenCoordUnproject.m128_f32[1];
	localCoord->m128_f32[2] = screenCoordUnproject.m128_f32[2];
	localCoord->m128_f32[3] = screenCoordUnproject.m128_f32[3];

	// Return the resulting screen space coordinate XMVECTOR value.
	return localCoord;
}

//==========================================================================
// Coordinate system related.
//==========================================================================

/*
*	Read 3 float values and convert them refering the coordinate system option 
*		indicated in the custom exported WYO file.
*	<p>
*	This function reads 3 float values in from the ifstream pointer passed as 
*		parameter and converts the coordinate values refering to the coordinate
*		system option loaded in the MyModelObj object passed in as parameter, 
*		then store it into a VertexType object and return it.
*	@param		model		MyModelObj object to access the coordinate system 
*							exported option with.
*	@param		fin			ifstream pointer which is currently reading the 
*							coordinate value in.
*	@return		Returns the VertexType object pointer with the coordinate value 
*				read from the file and is converted with the boolean values 
*				stored inside MyModelObj object passed in as parameter.
*   @see		MyModelObj
*   @see		VertexType
*   @since      ver0038
*/
// Conversion system manually analyzed with sample: https://docs.google.com/spreadsheets/d/1zarSFgRq6PsNVYPQNASd_uMJoamDMDBFjt2Htn5pDS0/edit#gid=0
VertexType *Util::coordinateSystemConversionFromBlenderToDirectX(
	MyModelObj *model,
	ifstream *fin) {
	// Init resulting VertexType object.
	VertexType *resultCoord = (VertexType *)malloc(sizeof(VertexType));

	// Check if the MyModelObj object and the ifstream to load the data are 
	// valid
	if (model == NULL || fin == NULL) {
		throw std::runtime_error("ERROR::Util::coordinateSystemConversionFromBlenderToDirectX::NULL point exception!!!");
	}
	
	// Local variables to hold 3 float values loaded from file and to convert
	// with.
	float x, y, z;

	// Convert the coordinate values with the coordinate system boolean values 
	// stored inside MyModelObj object
#pragma region COODINATE_SYSTEM_CONVERSION
	//=============================================================
	// Imported from -Z up 
	//=============================================================
	// From [Z up X forward]
	if (model->coordoption_Z_up
		&& model->coordoption_X_forward) {
		_RPT1(0, "From [Z up -X forward]\n", 0);
		*fin >> z >> x >> y;
		x *= -1;
	}
	// From [Z up -X forward]
	else if (model->coordoption_Z_up
		&& model->coordoption_minus_X_forward) {
		_RPT1(0, "From [Z up -X forward]\n", 0);
		*fin >> z >> x >> y;
		//*fin >> z >> x >> y;
		z *= -1;
	}
	// From [Z up Y forward]
	else if (model->coordoption_Z_up
		&& model->coordoption_Y_forward) {
		_RPT1(0, "From [Z up Y forward]\n", 0);
		*fin >> x >> z >> y;
	}
	// From [Z up -Y forward]
	else if (model->coordoption_Z_up
		&& model->coordoption_minus_Y_forward) {
		_RPT1(0, "From [Z up -Y forward]\n", 0);
		*fin >> x >> z >> y;
		x *= -1;
		z *= -1;
	}
	//==============================================================
	// Imported from -Z up 
	//==============================================================
	// From [-Z up Y forward]
	else if (model->coordoption_minus_Z_up
		&& model->coordoption_Y_forward) {
		_RPT1(0, "From [-Z up Y forward]\n", 0);
		*fin >> x >> z >> y;
		x *= -1;
		y *= -1;
	}
	// From [-Z up -Y forward]
	else if (model->coordoption_minus_Z_up
		&& model->coordoption_minus_Y_forward) {
		_RPT1(0, "From [-Z up -Y forward]\n", 0);
		*fin >> x >> z >> y;
		y *= -1;
		z *= -1;
	}
	// From [-Z up X forward]
	else if (model->coordoption_minus_Z_up
		&& model->coordoption_X_forward) {
		_RPT1(0, "From [-Z up X forward]\n", 0);
		*fin >> z >> x >> y;
		y *= -1;
	}
	// From [-Z up -X forward]
	else if (model->coordoption_minus_Z_up
		&& model->coordoption_minus_X_forward) {
		_RPT1(0, "From [-Z up -X forward]\n", 0);
		*fin >> z >> x >> y;
		x *= -1;
		z *= -1;
		y *= -1;
	}
	//==============================================================
	// Imported from Y up 
	//==============================================================
	// From [Y up Z forward]
	else if (model->coordoption_Y_up
		&& model->coordoption_Z_forward) {
		_RPT1(0, "From [Y up Z forward]\n", 0);
		*fin >> x >> y >> z;
		x *= -1;
	}
	// From [Y up -Z forward]
	else if (model->coordoption_Y_up
		&& model->coordoption_minus_Z_forward) {
		_RPT1(0, "From [Y up -Z forward]\n", 0);
		*fin >> x >> y >> z;
		z *= -1;
	}
	// From [Y up X forward]
	else if (model->coordoption_Y_up
		&& model->coordoption_X_forward) {
		_RPT1(0, "From [Y up X forward]\n", 0);
		*fin >> z >> y >> x;
	}
	// From [Y up -X forward]
	else if (model->coordoption_Y_up
		&& model->coordoption_minus_X_forward) {
		_RPT1(0, "From [Y up -X forward]\n", 0);
		*fin >> z >> y >> x;
		x *= -1;
		z *= -1;
	}
	//==============================================================
	// Imported from -Y up 
	//==============================================================
	// From [-Y up Z forward]
	else if (model->coordoption_minus_Y_up
		&& model->coordoption_Z_forward) {
		_RPT1(0, "From [-Y up Z forward]\n", 0);
		*fin >> x >> y >> z;
		y *= -1;
	}
	// From [-Y up -Z forward]
	else if (model->coordoption_minus_Y_up
		&& model->coordoption_minus_Z_forward) {
		_RPT1(0, "From [-Y up -Z forward]\n", 0);
		*fin >> x >> y >> z;
		x *= -1;
		y *= -1;
		z *= -1;
	}
	// From [-Y up X forward]
	else if (model->coordoption_minus_Y_up
		&& model->coordoption_X_forward) {
		_RPT1(0, "From [-Y up X forward]\n", 0);
		*fin >> z >> y >> x;
		x *= -1;
		y *= -1;
	}
	// From [-Y up -X forward]
	else if (model->coordoption_minus_Y_up
		&& model->coordoption_minus_X_forward) {
		_RPT1(0, "From [-Y up -X forward]\n", 0);
		*fin >> z >> y >> x;
		y *= -1;
		z *= -1;
	}
	//==============================================================
	// Imported from X up 
	//==============================================================
	// From [X up Z forward]
	else if (model->coordoption_X_up
		&& model->coordoption_Z_forward) {
		_RPT1(0, "From [X up Z forward]\n", 0);
		*fin >> y >> x >> z;
	}
	// From [X up -Z forward]
	else if (model->coordoption_X_up
		&& model->coordoption_minus_Z_forward) {
		_RPT1(0, "From [X up -Z forward]\n", 0);
		*fin >> y >> x >> z;
		x *= -1;
		z *= -1;
	}
	// From [X up Y forward]
	else if (model->coordoption_X_up
		&& model->coordoption_Y_forward) {
		_RPT1(0, "From [X up Y forward]\n", 0);
		*fin >> y >> z >> x;
		x *= -1;

	}
	// From [X up -Y forward]
	else if (model->coordoption_X_up
		&& model->coordoption_minus_Y_forward) {
		_RPT1(0, "From [X up -Y forward]\n", 0);
		*fin >> y >> z >> x;
		z *= -1;
	}
	//==============================================================
	// Imported from -X up 
	//==============================================================
	// From [-X up Z forward]
	else if (model->coordoption_minus_X_up
		&& model->coordoption_Z_forward) {
		_RPT1(0, "From [-X up Z forward]\n", 0);
		*fin >> y >> x >> z;
		x *= -1;
		y *= -1;
	}
	// From [-X up -Z forward]
	else if (model->coordoption_minus_X_up
		&& model->coordoption_minus_Z_forward) {
		_RPT1(0, "From [-X up -Z forward]\n", 0);
		*fin >> y >> x >> z;
		y *= -1;
		z *= -1;
	}
	// From [-X up Y forward]
	else if (model->coordoption_minus_X_up
		&& model->coordoption_Y_forward) {
		_RPT1(0, "From [-X up Y forward]\n", 0);
		*fin >> y >> z >> x;
		y *= -1;
	}
	// From [-X up -Y forward]
	else if (model->coordoption_minus_X_up
		&& model->coordoption_minus_Y_forward) {
		_RPT1(0, "From [-X up -Y forward]\n", 0);
		*fin >> y >> z >> x;
		x *= -1;
		y *= -1;
		z *= -1;
	}
	//==============================================================
	// Invalid coordinate system options for conversion.
	// Using Blender default coordinate system 
	// [Z up Y forward] --> [Y up -Z forward ]
	//==============================================================
	else {
		_RPT1(0, "======================================================================================\n", 0);
		_RPT1(0, "MyModelLoader::LoadDataStructuresMyModelObj::Not imported with myOBJ, CU or CF invalid, importing with default Blender OBJ format [Z up Y forward]\n", 0);
		_RPT1(0, "======================================================================================\n", 0);
		_RPT1(0, "From [Z up Y forward]\n", 0);
		*fin >> x >> z >> y;
	}
#pragma endregion

	// Store the final result.
	resultCoord->x = x;
	resultCoord->y = y;
	resultCoord->z = z;

	// Return the resulting VertexType object which stores the converted
	// coordinat values.
	return resultCoord;
}

//=============================================================================
// Extra features.
//=============================================================================
/*
*	Rounds up a XMVETOR coordinates values.
*	<p>
*	This function rounds up a XMVETOR coordinates x, y and z values
*		up to 2 decimal digits and stores back
*		the rounded values to the source XMVECTOR coordinates.
*	@param		src			The XMVECTOR source which i want to round up with.
*	@return		void
*   @since      ver0003
*/
void Util::roundDecimal2XMVECTOR3(XMVECTOR *src) {
	src->m128_f32[0] = roundf(src->m128_f32[0] * 100) / 100;
	src->m128_f32[1] = roundf(src->m128_f32[1] * 100) / 100;
	src->m128_f32[2] = roundf(src->m128_f32[2] * 100) / 100;
}




