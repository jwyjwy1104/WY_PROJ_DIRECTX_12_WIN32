// File name: [Line.cpp] (Copyright to Samil Chai)
// Work Session #0184: 2017-07-13
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4OG5vbjRJMXdnYWM%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4OG5vbjRJMXdnYWM
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4Z1drejJYcU9FcWc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4Z1drejJYcU9FcWc
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4WnNIR2xOd0pMMEU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WnNIR2xOd0pMMEU
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		Basic implementation of Line class to render a line object onto screen
// - [Comments]:
//		Diagrams created.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0025
//------------------------------------------------------------------------------
// [rev0002:WY:201707131915]
//------------------------------------------------------------------------------
// File name: [Line.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		Basic implementation of Line class to render a line object onto screen
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707020005]
//------------------------------------------------------------------------------
// File name: [Line.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		Basic implementation of Line class to render a line object onto screen
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
//------------------------------------------------------------------------------
// [rev0000:WY:201706291840]
//------------------------------------------------------------------------------
//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################
#pragma once

#include <iostream>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

using namespace DirectX;

#include "main.h"
#include "Line.h"
#include "ShaderStructures.h"

// Default constructor.
Line::Line() {
	// Index of the current line object's CBV descriptor alignment index.
	this->lineCBVAlignmentIndex = -1;

	// Transformation matrices.
	// World = Move * rotation * scale.
	this->lineWorldMat = new XMFLOAT4X4();
	XMStoreFloat4x4(lineWorldMat, XMMatrixIdentity());
	this->lineTranslationMat = new XMFLOAT4X4();	// Move matrix.
	XMStoreFloat4x4(lineTranslationMat, XMMatrixIdentity());
	this->lineRotationMat = new XMFLOAT4X4();		// Rotation matrix.
	XMStoreFloat4x4(lineRotationMat, XMMatrixIdentity());
	this->lineScaleMat = new XMFLOAT4X4();			// Scale matrix.
	XMStoreFloat4x4(lineScaleMat, XMMatrixIdentity());
}

// General constructor.
Line::Line(XMFLOAT3 p1, XMFLOAT3 p2) {
	this->p1 = p1;	// First point of the line.
	this->p2 = p2;  // Second point of the line.

	// Index of the current line object's CBV descriptor alignment index.
	this->lineCBVAlignmentIndex = -1;

	// Transformation matrices.
	// World = Move * rotation * scale.
	this->lineWorldMat = new XMFLOAT4X4();
	XMStoreFloat4x4(lineWorldMat, XMMatrixIdentity());
	this->lineTranslationMat = new XMFLOAT4X4();	// Move matrix.
	XMStoreFloat4x4(lineTranslationMat, XMMatrixIdentity());
	this->lineRotationMat = new XMFLOAT4X4();		// Rotation matrix.
	XMStoreFloat4x4(lineRotationMat, XMMatrixIdentity());
	this->lineScaleMat = new XMFLOAT4X4();			// Scale matrix.
	XMStoreFloat4x4(lineScaleMat, XMMatrixIdentity());
}

// Destructor.
Line::~Line() {
	// Index of the current line object's CBV descriptor alignment index.
	this->lineCBVAlignmentIndex = -1;

	// Transformation matrices.
	// World = Move * rotation * scale.
	if (this->lineWorldMat != NULL) {
		delete this->lineWorldMat;
		this->lineWorldMat = NULL;
	}
	// Move matrix.
	if (this->lineTranslationMat != NULL) {
		delete this->lineTranslationMat;
		this->lineTranslationMat = NULL;
	}
	// Rotation matrix.
	if (this->lineRotationMat != NULL) {
		delete this->lineRotationMat;
		this->lineRotationMat = NULL;
	}
	// Scale matrix.
	if (this->lineScaleMat != NULL) {
		delete this->lineScaleMat;
		this->lineScaleMat = NULL;
	}
}


/*
*	Setter - Member variable "p1".
*	<p>
*	This function is the setter for current Line object's
*		member variable "p1".
*		- The coordinate representing the first point of the line.
*	@param		p1		XMFLOAT3 coordinate value to set with.
*	@see		XMFLOAT3
*	@since		ver0003
*/
void Line::setP1(XMFLOAT3 p1) {
	this->p1 = p1;
}
/*
*	Setter - Member variable "p2".
*	<p>
*	This function is the setter for current Line object's
*		member variable "p2".
*		- The coordinate representing the second point of the line.
*	@param		p2		XMFLOAT3 coordinate value to set with.
*	@see		XMFLOAT3
*	@since		ver0003
*/
void Line::setP2(XMFLOAT3 p2) {
	this->p2 = p2;
}

/*
*	Setup vertex and index buffer for rendering a line.
*	<p>
*	This function initializes vertex and index buffer resources using the 
*		current Line object's "p1" and "p2" 2 point coordinates,
*		and uploads to GPU to be used for rendering a line object,
*		which has only two points in the buffer.
*
*	@pre		"this" Line object's first point "p1" and second point "p2" 
*					must be initialized with proper coordinate values.
*	@param		d3dDevice			Device for resource initialization.
*	@param		commandList		Command list for resource uploading to GPU.
*	@see		Vertex
*	@return		void
*/
void Line::createLine(
	ID3D12Device *d3dDevice,
	ID3D12GraphicsCommandList *commandList) {
	//--------------------------------------------------------------------------
	// Vertex buffer init
	//--------------------------------------------------------------------------
	Vertex *vList = (Vertex *)malloc(DEFAULT_LINE_NUM_POINTS * sizeof(Vertex));

	// First point of the line
	vList[0].pos.x = this->p1.x; // Assume "this" p1 is set
	vList[0].pos.y = this->p1.y;
	vList[0].pos.z = this->p1.z;

	// Second point of the line
	vList[1].pos.x = this->p2.x; // Assume "this" p2 is set
	vList[1].pos.y = this->p2.y;
	vList[1].pos.z = this->p2.z;

	// Size of the vertex buffer
	int vBufferSize = sizeof(*vList) * DEFAULT_LINE_NUM_POINTS;

	// Create default heap
	// default heap is memory on the GPU. Only the GPU has access to this memory
	// To get data into this heap, we will have to upload the data using
	// an upload heap
	d3dDevice->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), // a default heap
		D3D12_HEAP_FLAG_NONE, // no flags
		// resource description for a buffer
		&CD3DX12_RESOURCE_DESC::Buffer(vBufferSize), 
		// we will start this heap in the copy destination state since
		// we will copy data
		D3D12_RESOURCE_STATE_COPY_DEST, 
		// from the upload heap to this heap
		// optimized clear value must be null for this type of resource. 
		// used for render targets and depth/stencil buffers
		nullptr, 
		IID_PPV_ARGS(&this->vertexLineBuffer));

	// we can give resource heaps a name so when we debug with the graphics 
	// debugger we know what resource we are looking at
	this->vertexLineBuffer->SetName(L"Vertex Buffer Resource Heap");

	// create upload heap
	// upload heaps are used to upload data to the GPU. CPU can write to it, 
	// GPU can read from it
	// We will upload the vertex buffer using this heap to the default heap
	d3dDevice->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), // upload heap
		D3D12_HEAP_FLAG_NONE, // no flags
		// resource description for a buffer
		&CD3DX12_RESOURCE_DESC::Buffer(vBufferSize), 
		// GPU will read from  buffer and copy its contents to the default heap
		D3D12_RESOURCE_STATE_GENERIC_READ, 
		nullptr,
		IID_PPV_ARGS(&this->vertexLineBufferUpload));
	this->vertexLineBufferUpload->SetName(L"Vertex Buffer Upload Resource Heap");

	// Store vertex buffer in upload heap.
	D3D12_SUBRESOURCE_DATA vertexData = {};
	// Pointer to our vertex array.
	vertexData.pData = reinterpret_cast<BYTE*>(vList); 
	// Size of all our triangle vertex data.
	vertexData.RowPitch = vertexData.RowPitch; 
	// Also the size of our triangle vertex data.
	vertexData.SlicePitch = vBufferSize; 

	// We are now creating a command with the command list to copy the data from
	// the upload heap to the default heap.
	UpdateSubresources(
		commandList,
		this->vertexLineBuffer,
		this->vertexLineBufferUpload, 
		0, 0, 1, 
		&vertexData);

	// Transition the vertex buffer data from copy destination state
	// to vertex buffer state.
	commandList->ResourceBarrier(
		1, 
		&CD3DX12_RESOURCE_BARRIER::Transition(
			this->vertexLineBuffer, 
			D3D12_RESOURCE_STATE_COPY_DEST, 
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER));

	// Create a vertex buffer view for the triangle. 
	// We get the GPU memory address to the vertex pointer 
	// using the GetGPUVirtualAddress() method.
	this->vertexLineBufferView.BufferLocation 
		= this->vertexLineBuffer->GetGPUVirtualAddress();
	this->vertexLineBufferView.StrideInBytes = sizeof(Vertex);
	this->vertexLineBufferView.SizeInBytes = vBufferSize;


	//--------------------------------------------------------------------------
	// Index buffer init.
	//--------------------------------------------------------------------------
	DWORD *iList = new DWORD[DEFAULT_LINE_NUM_POINTS];
	// First point of the line.
	iList[0] = 0;
	// Second point of the line.
	iList[1] = 1;

	// Size of the index buffer.
	int iBufferSize = sizeof(*iList) * DEFAULT_LINE_NUM_POINTS;

	// Create default heap to hold index buffer.
	d3dDevice->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), // a default heap
		D3D12_HEAP_FLAG_NONE, // no flags
		// resource description for a buffer
		&CD3DX12_RESOURCE_DESC::Buffer(iBufferSize), 
		D3D12_RESOURCE_STATE_COPY_DEST, // start in the copy destination state
		nullptr, // optimized clear value must be null for this type of resource
		IID_PPV_ARGS(&this->indexLineBuffer));

	// we can give resource heaps a name so when we debug with the graphics 
	// debugger we know what resource we are looking at
	this->indexLineBuffer->SetName(L"Index Buffer Resource Heap");

	// create upload heap to upload index buffer
	d3dDevice->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), // upload heap
		D3D12_HEAP_FLAG_NONE, // no flags
		// resource description for a buffer
		&CD3DX12_RESOURCE_DESC::Buffer(iBufferSize), 
		// GPU will read from buffer and copy its contents to the default heap
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&this->indexLineBufferUpload));
	this->indexLineBufferUpload->SetName(L"Index Buffer Upload Resource Heap");

	// store vertex buffer in upload heap
	D3D12_SUBRESOURCE_DATA indexData = {};
	indexData.pData = reinterpret_cast<BYTE*>(iList); // pointer to  index array
	indexData.RowPitch = iBufferSize; // size of all our index buffer
	indexData.SlicePitch = iBufferSize; // also the size of our index buffer
	
	// We are now creating a command with the command list to copy the data from
	// the upload heap to the default heap.
	UpdateSubresources(
		commandList, 
		this->indexLineBuffer, 
		this->indexLineBufferUpload,
		0, 0, 1, 
		&indexData);

	// Transition the vertex buffer data from copy destination 
	// state to vertex buffer state.
	commandList->ResourceBarrier(
		1, 
		&CD3DX12_RESOURCE_BARRIER::Transition(
			this->indexLineBuffer, 
			D3D12_RESOURCE_STATE_COPY_DEST, 
			D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER));

	// Create a index buffer view for the triangle. 
	// We get the GPU memory address to the index pointer 
	// using the GetGPUVirtualAddress() method.
	this->indexLineBufferView.BufferLocation 
		= this->indexLineBuffer->GetGPUVirtualAddress();
	// 32-bit unsigned integer 
	// (this is what a dword is, double word, a word is 2 bytes)
	this->indexLineBufferView.Format = DXGI_FORMAT_R32_UINT; 
	this->indexLineBufferView.SizeInBytes = iBufferSize;
}

//------------------------------------------------------------------------------
// Buffer view related
//------------------------------------------------------------------------------
/*
*	Getter - Member variable "vertexLineBufferView".
*	<p>
*	This function is the getter for current Point object's
*		member variable "vertexLineBufferView".
*		- Vertex buffer view which is wathcing the vertex buffer resources
*		  to be rendered on screen,
*	Vertex buffer need to be set in order to be rendered through DirectX engine,
*		vertex buffer can be set by calling 
*		ID3D12CommmandList::IASetVertexBuffers().
*	@return		Return current Point object's
*					member variable "vertexLineBufferView"
*					D3D12_VERTEX_BUFFER_VIEW.
*	@see		ID3D12CommmandList::IASetVertexBuffers()
*	@since		ver0003
*/
D3D12_VERTEX_BUFFER_VIEW Line::getVertexLineBufferView() {
	return this->vertexLineBufferView;
}
/*
*	Getter - Member variable "indexLineBufferView".
*	<p>
*	This function is the getter for current Point object's
*		member variable "vertexLineBufferView".
*		- Index buffer view which is wathcing the index buffer resources
*		  to be rendered on screen,
*	Index buffer need to be set in order to be rendered through DirectX engine,
*	  index buffer can be set by calling ID3D12CommmandList::IASetIndexBuffer().
*	@return		Return current Point object's
*					member variable "indexLineBufferView"
*					D3D12_VERTEX_BUFFER_VIEW.
*	@see		ID3D12CommmandList::IASetIndexBuffer()
*	@since		ver0003
*/
D3D12_INDEX_BUFFER_VIEW Line::getIndexLineBufferView() {
	return this->indexLineBufferView;
}

/*
*	Getter - Member variable "lineCBVAlignmentIndex".
*	<p>
*	This function is the getter for current Line object's
*		member variable "lineCBVAlignmentIndex".
*		- The index of the CBV resources alignment of a CBV descriptor
*			to be used for rendering world space line objects.
*	@return		Return current Line object's
*					member variable "lineCBVAlignmentIndex"
*					integer value.
*	@since		ver0003
*/
int Line::getLineCBVAlignmentIndex() {
	return this->lineCBVAlignmentIndex;
}

/*
*	Setter - Member variable "lineCBVAlignmentIndex".
*	<p>
*	This function is the setter for current Line object's
*		member variable "lineCBVAlignmentIndex".
*		- The index of the CBV resources alignment of a CBV descriptor
*			to be used for rendering world space line objects.
*	@param		lineCBVAlignmentIndex	CBV alignment index integer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void Line::setLineCBVAlignmentIndex(
	int lineCBVAlignmentIndex) {
	this->lineCBVAlignmentIndex = lineCBVAlignmentIndex;
}

/*
*	Getter - Member variable "lineWorldMat".
*	<p>
*	This function is the getter for current Line object's
*		member variable "lineWorldMat".
*		- The world matrix of current line object, to be used on updating
*			constant buffer resources for rendering.
*			This world matrix is the result of multiplications of
*			translation, rotation and scaling matrices.
*	@return		Return current Line object's
*					member variable "lineWorldMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *Line::getLineWorldMat() {
	//// Init temporary matrix for calculation
	//XMMATRIX temp = XMMatrixIdentity();
	//// * Translation matrix
	//temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->lineTranslationMat));
	//// * Rotation matrix
	//temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->lineRotationMat));
	//// * Scale matrix
	//temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->lineScaleMat));

	// Store result world matrix
	//XMStoreFloat4x4(this->lineWorldMat, temp);
	return this->lineWorldMat;
}
/*
*	Setter - Member variable "lineWorldMat".
*	<p>
*	This function is the setter for current Line object's
*		member variable "lineWorldMat".
*		- The world matrix of current line object, to be used on updating
*			constant buffer resources for rendering.
*			This world matrix is the result of multiplications of
*			translation, rotation and scaling matrices.
*	@param		lineWorldMat		World matrix XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void Line::setLineWorldMat(XMFLOAT4X4 *lineWorldMat) {
	this->lineWorldMat = lineWorldMat;
}

/*
*	Getter - Member variable "lineTranslationMat".
*	<p>
*	This function is the getter for current Line object's
*		member variable "lineTranslationMat".
*		- The translation matrix of current line object, to be used for
*			calculating and updating line's translation.
*	@return		Return current Line object's
*					member variable "lineTranslationMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *Line::getLineTranslationMat() {
	return this->lineTranslationMat;
}
/*
*	Setter - Member variable "lineWorldMat".
*	<p>
*	This function is the setter for current Line object's
*		member variable "lineTranslationMat".
*		- The translation matrix of current line object, to be used for
*			calculating and updating line's translation.
*	@param		lineTranslationMat		Translation matrix
*										XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void Line::setLineTranslationMat(
	XMFLOAT4X4 *lineTranslationMat) {
	this->lineTranslationMat = lineTranslationMat;
}

/*
*	Getter - Member variable "lineRotationMat".
*	<p>
*	This function is the getter for current Line object's
*		member variable "lineRotationMat".
*		- The rotation matrix of current line object, to be used for
*			calculating and updating line's rotation.
*	@return		Return current Line object's
*					member variable "lineRotationMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *Line::getLineRotationMat() {
	return this->lineRotationMat;
}
/*
*	Setter - Member variable "lineRotationMat".
*	<p>
*	This function is the setter for current Line object's
*		member variable "lineRotationMat".
*		- The rotation matrix of current line object, to be used for
*			calculating and updating line's rotation.
*	@param		lineRotationMat		Rotation matrix
*										XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void Line::setLineRotationMat(
	XMFLOAT4X4 *lineRotationMat) {
	this->lineRotationMat = lineRotationMat;
}
/*
*	Getter - Member variable "lineScaleMat".
*	<p>
*	This function is the getter for current Line object's
*		member variable "lineScaleMat".
*		- The scaling matrix of current line object, to be used for
*			calculating and updating line's scale.
*	@return		Return current Line object's
*					member variable "lineScaleMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *Line::getLineScaleMat() {
	return this->lineScaleMat;
}
/*
*	Setter - Member variable "lineScaleMat".
*	<p>
*	This function is the setter for current Line object's
*		member variable "lineScaleMat".
*		- The scaling matrix of current line object, to be used for
*			calculating and updating line's scale.
*	@param		lineScaleMat		Scaling matrix
*									XMFLOAT4X4 pointer
*									value to set with
*	@return		void
*	@since		ver0003
*/
void Line::setLineScaleMat(
	XMFLOAT4X4 *lineScaleMat) {
	this->lineScaleMat = lineScaleMat;
}

/*
*	Set model object onto given world space coordinates.
*	<p>
*	This function translates the model onto the given coordinates,
*		by setting the current model object's translation matrix
*		with transposed coordinate values.
*	Main problem here, is that I need to update the constant buffer for current
*		model object, in order to set to the correct given coordinate position.
*	@param		x		Position X coordinate to set with
*	@param		y		Position Y coordinate to set with
*	@param		z		Position Z coordinate to set with
*	@return		void
*	@since		ver0003
*/
void Line::setModelPositionXYZ(float x, float y, float z) {
	XMFLOAT4 temp = XMFLOAT4(x, y, z, 0.0f);
	XMVECTOR posVec = XMLoadFloat4(&temp);
	XMMATRIX tmpMat = XMMatrixTranslationFromVector(posVec);

	XMStoreFloat4x4(this->lineTranslationMat, tmpMat);
}

/*
*	Moves model object with given coordinate values.
*	<p>
*	This function translates and moves the model
*		x unit on global X axis,
*		y unit on global Y axis,
*		z unit on global Z axis,
*		by setting the current model object's translation matrix
*		with transposed coordinate values.
*	Main problem here, is that I need to update the constant buffer for current
*		model object, in order to set to the correct given coordinate position.
*	@param		x		Translation x unit on X axis to set translation with
*	@param		y		Translation y unit on Y axis to set translation with
*	@param		z		Translation z unit on Z axis to set translation with
*	@return		void
*	@see		XMMatriXMultiply
*	@since		ver0003
*/
void Line::moveModelXYZ(float x, float y, float z) {
	// Calculate the translation matrix to update with.
	XMFLOAT4 temp = XMFLOAT4(x, y, z, 0.0f);
	XMVECTOR posVec = XMLoadFloat4(&temp);
	XMMATRIX tmpMat = XMMatrixTranslationFromVector(posVec);

	// Update current model's translation matrix 
	XMStoreFloat4x4(this->lineTranslationMat,
		// Multiply the calculated translation matrix onto current 
		// model's translation matrix
		XMMatrixMultiply(XMLoadFloat4x4(this->lineTranslationMat), tmpMat));
}
/*
*	Rotates model object with given coordinate values.
*	<p>
*	This function rotates the model object
*		x degree around global X axis,
*		y degree around global Y axis,
*		z degree around global Z axis,
*		by setting the current model object's rotation matrix
*		with transposed coordinate values.
*	Main problem here, is that I need to update the constant buffer for current
*		model object, in order to set to the correct given coordinate position.
*	@param		x		Rotation x degree around X axis to set rotation with
*	@param		y		Rotation y degree around Y axis to set rotation with
*	@param		z		Rotation z degree around Z axis to set rotation with
*	@return		void
*	@see		XMMatrixRotationX
*	@see		XMMatrixRotationX
*	@see		XMMatrixRotationZ
*	@since		ver0003
*/
void Line::rotateModelXYZ(float x, float y, float z) {
	// Add rotation to current MySpecialObject's rotation matrix 
	// and store it.
	XMMATRIX transformMat = 
		XMMatrixRotationZ(z) * 
		(XMLoadFloat4x4(this->lineRotationMat) * 
		(XMMatrixRotationX(x) * XMMatrixRotationY(y)));
	XMStoreFloat4x4(this->lineRotationMat, transformMat);
}
/*
*	Scales model object with given coordinate values.
*	<p>
*	This function scales the model object
*		x factor along global X axis,
*		y factor along global Y axis,
*		z factor along global Z axis,
*		by setting the current model object's scaling matrix
*		with transposed coordinate values.
*	Main problem here, is that I need to update the constant buffer for current
*		model object, in order to set to the correct given coordinate position.
*	@param		x		x factor along X axis to scale with
*	@param		z		z factor along Z axis to scale with
*	@return		void
*	@see		XMMatrixScaling
*	@see		XMMatrixTranspose
*	@see		XMMatriXMultiply
*	@since		ver0003
*/
void Line::scaleModelXYZ(float x, float y, float z) {
	// Multiply scale to current MySpecialObject's scale matrix 
	// and store it.
	XMMATRIX transformMat = XMMatrixTranspose(XMMatrixScaling(x, y, z));
	transformMat 
		= XMMatrixMultiply(XMLoadFloat4x4(this->lineScaleMat), transformMat);
	XMStoreFloat4x4(this->lineScaleMat, transformMat);
}