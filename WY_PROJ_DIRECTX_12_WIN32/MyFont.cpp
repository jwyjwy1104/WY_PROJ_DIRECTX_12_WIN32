// File name: [ModelFont.cpp] (Copyright to Samil Chai)
// Work Session #0190: 2017-07-22
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ODFKeFNPNFV3VTQ%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ODFKeFNPNFV3VTQ
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4SFV0RFBJVlZFam8%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4SFV0RFBJVlZFam8
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MUFuMjlYd0VGTHM%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]:
//		BraynzarSoft tutorial 11 - https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
// - [Description]:
//		This class holds all the informations loaded from a FNT file and also 
//			manages the rendering of the fonts on DirectX 12 engine.
//		This class is the wrapper class of the Font structure given in 
//			BraynzarSoft tutorial 11 - https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
//			So i can also manage the rendering part, so that i can decrease the 
//			lines of code on main.cpp.
// - [Comments]:
//		Code ported from BraynzarSoft tutorial 11 - https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
//		Inner document done.
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0037
//------------------------------------------------------------------------------
// [rev0000:WY:201707252020]
//------------------------------------------------------------------------------
//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################
#pragma once

#include "MyFont.h"

// Default constructor.
MyFont::MyFont() {
	// Main font information.
	this->font = new Font();
}

// Detructor.
MyFont::~MyFont() {
	// Main font information.
	if (this->font != NULL) {
		delete this->font;
		this->font = NULL;
	}
}

/*
*	Main init function to initialize the necessary
*		buffers and resources in order to render fonts on screen 
*		using DirectX 12 engine.
*	<p>
*	This function first load the FNT file from given file path using the util 
*		object --> Initialize the texture buffer with the font bitmap image
*		file path inidicated in FNT file --> Create array of vertex buffer 
*		resources of each letters provided in the FNT file and map them to 
*		each constant buffers for direct access later on --> 
*		Create vertex buffer view for each letters' vertex buffers -->
*		Ready to render fonts on screen.
*	@param		device			Device object for resource creation.
*	@param		commandList		Command list object for resource uploads.
*	@param		utils			Util object for texture image validation.
*
*	@param		srvDescriptorHeapCPUOffsetHandle	SRV descriptor heap CPU
*													offset handle for SRV 
*													creation.
*	@param		srvDescriptorHeapGPUOffsetHandle	SRV descriptor heap GPU
*													offset handle for rendering.
*
*	@param		descriptorSize		Size of a descriptor to inrement
*										offset handle with when a new descriptor
*										is added.
*	@param		fontFileName		Size of a descriptor to inrement
*	@param		windowWidth			Width of the main appplication window 
*										to render font with.
*	@param		windowHeight		Height of the main appplication window 
*										to render font with.
*	@return		void
*	@since		ver0037
*/
void MyFont::initMyFont(
	ID3D12Device *device,
	ID3D12GraphicsCommandList *commandList,
	Util *util,
	ID3D12DescriptorHeap* srvDescriptorHeap,
	CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle, // For SRV init
	CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle, // For rendering
	UINT descriptorSize,
	LPCWSTR fontFilePath,
	int windowWidth,
	int windowHeight) {

	// NULL point exception error.
	if (device == NULL ||
		commandList == NULL ||
		util == NULL ||
		srvDescriptorHeap == NULL ||
		srvDescriptorHeapCPUOffsetHandle == NULL ||
		srvDescriptorHeapGPUOffsetHandle == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyFont::initMyFont::NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyFont::initMyFont::NULL!!!");
		//Running = false;
		//return false;
	}
	// Result flag.
	HRESULT hr;

	//==========================================================================
	// Init font from FNT file.
	//==========================================================================
	// Font object initialized with font informations loaded from FNT file.
	this->font = util->LoadFont(fontFilePath, windowWidth, windowHeight);

	// Load the font bitmap image from file.
	D3D12_RESOURCE_DESC fontTextureDesc;
	int fontImageBytesPerRow;
	BYTE* fontImageData;
	int fontImageSize = util->LoadImageDataFromFile(&fontImageData, fontTextureDesc, this->font->fontImage.c_str(), fontImageBytesPerRow);

	// Make sure we have data.
	if (fontImageData <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyFont::initMyFont::Font bitmap image loaded failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyFont::initMyFont::Font bitmap image loaded failed!!!");
	}

	// Create the font texture resource.
	hr = device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT),
		D3D12_HEAP_FLAG_NONE,
		&fontTextureDesc,
		D3D12_RESOURCE_STATE_COPY_DEST,
		nullptr,
		IID_PPV_ARGS(&this->font->textureBuffer));
	if (FAILED(hr)) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyFont::initMyFont::Create texture buffer default resources failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyFont::initMyFont::Create texture buffer default resources failed!!!");
		/*Running = false;
		return false;*/
	}
	this->font->textureBuffer->SetName(L"Font Texture Buffer Resource Heap");

	// init exture buffer upload heap.
	ID3D12Resource* fontTextureBufferUploadHeap;
	UINT64 fontTextureUploadBufferSize;
	device->GetCopyableFootprints(&fontTextureDesc, 0, 1, 0, nullptr, nullptr, nullptr, &fontTextureUploadBufferSize);

	// Create an upload heap to copy the texture to the GPU.
	hr = device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
		D3D12_HEAP_FLAG_NONE, // no flags
		&CD3DX12_RESOURCE_DESC::Buffer(fontTextureUploadBufferSize),
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&fontTextureBufferUploadHeap));
	if (FAILED(hr)) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyFont::initMyFont::Create texture buffer resources failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyFont::initMyFont::Create texture buffer resources failed!!!");
	/*	Running = false;
		return false;*/
	}
	fontTextureBufferUploadHeap->SetName(L"Font Texture Buffer Upload Resource Heap");

	// Store font image in upload heap.
	D3D12_SUBRESOURCE_DATA fontTextureData = {};
	fontTextureData.pData = &fontImageData[0]; // Pointer to our image data
	fontTextureData.RowPitch = fontImageBytesPerRow; // Size of all our triangle vertex data
	fontTextureData.SlicePitch = fontImageBytesPerRow * fontTextureDesc.Height; // also the size of our triangle vertex data.

																				// Now we copy the upload buffer contents to the default heap.
	UpdateSubresources(commandList, this->font->textureBuffer, fontTextureBufferUploadHeap, 0, 0, 1, &fontTextureData);

	// Transition the texture default heap to a pixel shader resource (we will be sampling from this heap in the pixel shader to get the color of pixels).
	commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(this->font->textureBuffer, D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE));

	// Create an srv for the font.
	D3D12_SHADER_RESOURCE_VIEW_DESC fontsrvDesc = {};
	fontsrvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	fontsrvDesc.Format = fontTextureDesc.Format;
	fontsrvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
	fontsrvDesc.Texture2D.MipLevels = 1;

	// Create SRV on given CPU SRV descriptor heap.
	device->CreateShaderResourceView(this->font->textureBuffer, &fontsrvDesc, *srvDescriptorHeapCPUOffsetHandle);
	
	this->font->srvHandle = *srvDescriptorHeapGPUOffsetHandle;

	// Increment the handle offset to store the next SRV on proper position of 
	// the descriptor heap.
	srvDescriptorHeapGPUOffsetHandle->Offset(descriptorSize);
	srvDescriptorHeapCPUOffsetHandle->Offset(descriptorSize);

	// Create text vertex buffer committed resources.
	for (int i = 0; i < frameBufferCount; ++i) {
		hr = device->CreateCommittedResource(
			&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), // upload heap
			D3D12_HEAP_FLAG_NONE, // no flags
			&CD3DX12_RESOURCE_DESC::Buffer(maxNumTextCharacters * sizeof(TextVertex)), // resource description for a buffer
			D3D12_RESOURCE_STATE_GENERIC_READ, // GPU will read from this buffer and copy its contents to the default heap
			nullptr,
			IID_PPV_ARGS(&this->textVertexBuffer[i]));
		if (FAILED(hr)) {
			/*Running = false;
			return false;*/
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyFont::initMyFont::Create text vertex buffer resources failed!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyFont::initMyFont::Create text vertex buffer resources failed!!!");
		}
		this->textVertexBuffer[i]->SetName(L"Text Vertex Buffer Upload Resource Heap");

		CD3DX12_RANGE readRange(0, 0);	// We do not intend to read from this resource on the CPU. (so end is less than or equal to begin)

		// Map the resource heap to get a gpu virtual address to the beginning of the heap.
		hr = this->textVertexBuffer[i]->Map(0, &readRange, reinterpret_cast<void**>(&this->textVBGPUAddress[i]));
	}

	// Set the text vertex buffer view for each frame.
	for (int i = 0; i < frameBufferCount; ++i) {
		this->textVertexBufferView[i].BufferLocation = this->textVertexBuffer[i]->GetGPUVirtualAddress();
		this->textVertexBufferView[i].StrideInBytes = sizeof(TextVertex);
		this->textVertexBufferView[i].SizeInBytes = maxNumTextCharacters * sizeof(TextVertex);
	}
}

/*
*	Main init function to initialize the necessary
*		buffers and resources in order to render fonts on screen
*		using DirectX 12 engine.
*	<p>
*	This function first load the FNT file from given file path using the util
*		object --> Initialize the texture buffer with the font bitmap image
*		file path inidicated in FNT file --> Create array of vertex buffer
*		resources of each letters provided in the FNT file and map them to
*		each constant buffers for direct access later on -->
*		Create vertex buffer view for each letters' vertex buffers -->
*		Ready to render fonts on screen.
*	@param		textPSO				PSO for text rendering.
*	@param		commandList			Command list object for resource uploads.
*	@param		dsDescriptorHeap	Depth/stencil buffer descriptor heap.
*	@param		frameIndex			Current RTV frame index for rendering.
*	@param		text				Wstring text to be rendered.
*	@param		pos					Posisiton of the font text to be rendered.
*	@param		scale				Scale factor of the font to be rendered.
*	@param		padding				Padding of the font text to be rendered.
*	@param		color				Color of the font text to be rendered.
*	@return		void
*	@see		ShaderStructures::TextVertex
*	@since		ver0037
*/
void MyFont::RenderText(
	ID3D12PipelineState* textPSO, 
	ID3D12GraphicsCommandList *commandList, 
	ID3D12DescriptorHeap *dsDescriptorHeap, 
	int frameIndex, 
	//Font font, 
	std::wstring text,
	XMFLOAT2 pos, 
	XMFLOAT2 scale, 
	XMFLOAT2 padding, 
	XMFLOAT4 color) {

	//_RPT1(0, "text : %S\n", text.c_str());

	// Clear the depth buffer so we can draw over everything.
	commandList->ClearDepthStencilView(dsDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

	// Set the text pipeline state object.
	commandList->SetPipelineState(textPSO);

	// This way we only need 4 vertices per quad rather than 6 if we were to use a triangle list topology.
	commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// Set the text vertex buffer.
	commandList->IASetVertexBuffers(0, 1, &this->textVertexBufferView[frameIndex]);

	// Bind the text srv. We will assume the correct descriptor heap and table are currently bound and set.
	commandList->SetGraphicsRootDescriptorTable(1, this->font->srvHandle);

	int numCharacters = 0;

	float topLeftScreenX = (pos.x * 2.0f) - 1.0f;
	float topLeftScreenY = ((1.0f - pos.y) * 2.0f) - 1.0f;

	float x = topLeftScreenX;
	float y = topLeftScreenY;

	float horrizontalPadding = (this->font->leftpadding + this->font->rightpadding) * padding.x;
	float verticalPadding = (this->font->toppadding + this->font->bottompadding) * padding.y;

	// Cast the gpu virtual address to a textvertex, 
	// so we can directly store our vertices there.
	TextVertex* vert = (TextVertex*)this->textVBGPUAddress[frameIndex];

	wchar_t lastChar = -1; // No last character to start with

	for (int i = 0; i < text.size(); ++i) {
		wchar_t c = text[i];

		FontChar* fc = this->font->GetChar(c);

		// Character not in font char set.
		if (fc == nullptr)
			continue;

		// End of string.
		if (c == L'\0')
			break;

		// New line.
		if (c == L'\n')
		{
			x = topLeftScreenX;
			y -= (this->font->lineHeight + verticalPadding) * scale.y;
			continue;
		}

		// Don't overflow the buffer. 
		// In your app if this is true, you can implement a resize of your text
		// vertex buffer
		if (numCharacters >= this->maxNumTextCharacters)
			break;

		float kerning = 0.0f;
		if (i > 0)
			kerning = this->font->GetKerning(lastChar, c);

		vert[numCharacters] = TextVertex(
			color.x,
			color.y,
			color.z,
			color.w,
			fc->u,
			fc->v,
			fc->twidth,
			fc->theight,
			x + ((fc->xoffset + kerning) * scale.x),
			y - (fc->yoffset * scale.y),
			fc->width * scale.x,
			fc->height * scale.y);

		numCharacters++;

		// Remove horrizontal padding and advance to next char position.
		x += (fc->xadvance - horrizontalPadding) * scale.x;

		lastChar = c;
	}

	// We are going to have 4 vertices per character 
	// (trianglestrip to make quad), and each instance is one character.
	commandList->DrawInstanced(4, numCharacters, 0, 0);
}