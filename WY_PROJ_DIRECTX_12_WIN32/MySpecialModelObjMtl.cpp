// File name: [MySpecialModelObjMtl.cpp] (Copyright to Samil Chai)
// Work Session #0193: 2017-07-24
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4TTZaQm5Ia0hmLXc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4TTZaQm5Ia0hmLXc
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4THE1bmp0OGRFaDg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4THE1bmp0OGRFaDg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MHdJNnJFODZxd0U%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MHdJNnJFODZxd0U
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		- This class holds all the information needed for rendering a model
//			through DirectX 12 engine.
//			- Contains a [MyModelObj] 
//				for OBJ file data (CU, CF, mtllib, v, vt, vn, f ... )
//			- Contains a [MyModelMtl] 
//				for MTL file data (newmtl, Ni, Ns, d, Ka, Kd, Ke, Ks ... )
//			- Contains a vertex buffer resources, vertex buffer view
//			- Contains a index buffer resources, index buffer view
//			- Contains a texture buffer resources.
//				- Need an initialization function because the command list
//				 and the device is needed for resource uploading.
//			- Also handles transformations,
//				move, position update, scale and rotate.
//				- Transformation summary: 
//					https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=id.xascw2tyl55i
// - [Comments]:
//		Inner documents and diagrams adjusted.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0003:WY:201707272205]
//------------------------------------------------------------------------------
// File name: [MySpecialModelObjMtl.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4TTZaQm5Ia0hmLXc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4TTZaQm5Ia0hmLXc
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4THE1bmp0OGRFaDg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4THE1bmp0OGRFaDg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MHdJNnJFODZxd0U%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MHdJNnJFODZxd0U
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		- This class holds all the information needed for rendering a model
//			through DirectX 12 engine.
//			- Contains a [MyModelObj] 
//				for OBJ file data (CU, CF, mtllib, v, vt, vn, f ... )
//			- Contains a [MyModelMtl] 
//				for MTL file data (newmtl, Ni, Ns, d, Ka, Kd, Ke, Ks ... )
//			- Contains a vertex buffer resources, vertex buffer view
//			- Contains a index buffer resources, index buffer view
//			- Contains a texture buffer resources.
//				- Need an initialization function because the command list
//				 and the device is needed for resource uploading.
//			- Also handles transformations,
//				move, position update, scale and rotate.
//				- Transformation summary: 
//					https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=id.xascw2tyl55i
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0002:WY:201707101945]
//------------------------------------------------------------------------------
// File name: [MySpecialModelObjMtl.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4amU3MnNrUUZBNVE%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4amU3MnNrUUZBNVE
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4T0JpMlRTLTMxak0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4T0JpMlRTLTMxak0
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0lWNlZLQU45NWs%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0lWNlZLQU45NWs
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		- This class holds all the information needed for rendering a model
//			through DirectX 12 engine.
//			- Contains a [MyModelObj] 
//				for OBJ file data (CU, CF, mtllib, v, vt, vn, f ... )
//			- Contains a [MyModelMtl] 
//				for MTL file data (newmtl, Ni, Ns, d, Ka, Kd, Ke, Ks ... )
//			- Contains a vertex buffer resources, vertex buffer view
//			- Contains a index buffer resources, index buffer view
//			- Contains a texture buffer resources.
//				- Need an initialization function because the command list
//				 and the device is needed for resource uploading.
//			- Also handles transformations,
//				move, position update, scale and rotate.
//				- Transformation summary: 
//					https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=id.xascw2tyl55i
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707012345]
//------------------------------------------------------------------------------
// File name: [MySpecialModelObjMtl.cpp] (Copyright to Samil Chai)
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4amU3MnNrUUZBNVE%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4amU3MnNrUUZBNVE
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4T0JpMlRTLTMxak0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4T0JpMlRTLTMxak0
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0lWNlZLQU45NWs%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0lWNlZLQU45NWs
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [MySpecialModelObjMtl]
//		- This class holds all the information needed for rendering a model
//			through DirectX 12 engine.
//			- Contains a [MyModelObj] 
//				for OBJ file data (CU, CF, mtllib, v, vt, vn, f ... )
//			- Contains a [MyModelMtl] 
//				for MTL file data (newmtl, Ni, Ns, d, Ka, Kd, Ke, Ks ... )
//			- Contains a vertex buffer resources, vertex buffer view
//			- Contains a index buffer resources, index buffer view
//			- Contains a texture buffer resources.
//				- Need an initialization function because the command list
//				 and the device is needed for resource uploading.
//			- Also handles transformations,
//				move, position update, scale and rotate.
//				- Transformation summary: 
//					https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=id.xascw2tyl55i
// - [Documents]
//		- Refactoring, MySpecialModelObjMtl class implementation summary: 
//			https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=kix.k5yo2p6nxi3i
//		- Transformation summary: 
//			https://docs.google.com/document/d/1nQ2iVSRKHMDYQ5_XvfcQHxFr_HCwpvP_O2QwPeJQ9ak/edit#bookmark=id.xascw2tyl55i
// - [Code resources]
//		- Texture buffer init, loading from image file code brought from: 
//			- Zero Tutorials textured cube (Sampler, SRV, root signature ...): 
//					http://www.zerotutorials.com/DirectX12/Tutorial02 
//			- Braynzar Soft texture from file: 
//					https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file 
//				- Load texture from file code has been moved to [Util] class
//					int LoadImageDataFromFile(
//						BYTE** imageData, 
//						D3D12_RESOURCE_DESC& resourceDescription, 
//						LPCWSTR filename, 
//						int &bytesPerRow);
//					DXGI_FORMAT GetDXGIFormatFromWICFormat(
//						WICPixelFormatGUID& wicFormatGUID);
//					WICPixelFormatGUID GetConvertToWICFormat(
//						WICPixelFormatGUID& wicFormatGUID);
//					int GetDXGIFormatBitsPerPixel(DXGI_FORMAT& dxgiFormat);
// - [Framework description]
//		1. MyModelLoader::myObjMtlLoader() - OBJ file path --> Load OBJ file
//			--> Get MTL file name from OBJ file --> Relative MTL file path 
//			--> Load MTL file --> MyModelObj + MyModelMtl = MySpecialModelObjMtl
//			1-1. MyModelLoader::myObjLoader() - Load OBJ file --> MyModelObj 
//					[CU, CF, v, vn, vt, f]
//			1-2. MyModelLoader::myMtlLoader() - Load MTL file --> MyModelMtl
//					[mtl_material_count, mtl_material_name,
//						mtl_mirror_color,mtl_ambient,
//						mtl_diffuse_color,mtl_diffuse_intensity,
//						mtl_specular_color, mtl_specular_intensity,
//						mtl_specular_hardness, 
//						mtl_emit, mtl_raytrace_transparency_ior, mtl_alpha, 
//						mtl_texture_map_image_path]
//		2. MySpecialModelObjMtl::initMySpecialModelObjMtlMtl() 
//			--> Vertex, index and texture buffer initialized 
//				using the data initialized on [MyModelObj] and [MyModelMtl] 
//				through [MyModelLoader].
//			2-1. MySpecialModelObjMtl::initVertexBufferResources() 
//				 --> Vertex buffer init --> Vertex buffer uploaded to GPU
//				 --> Vertex buffer view init
//			2-2. MySpecialModelObjMtl::initIndexBufferResources() 
//				 --> Index buffer init --> Index buffer uploaded to GPU 
//				 --> Index buffer view init
//			2-3. MySpecialModelObjMtl::initTextureBufferResources() 
//				 --> Texture buffer init 
//				 --> Texture buffer loaded from image (provided in MTL file) file
//				 --> Upload resources to GPU
//				 --> SRV created and added on root signature SRV descriptor table
//				 --> Descriptor offset handle incremented.
//		3. Using get functions to draw the primitive
//		   at Sample3DSceneRenderer::Render() function
//			3-1. Set root descriptor table offset --> SRV 
//				 --> Texture buffer
//			3-2. Resource barrier transition (COPY --> PRESENT)
//			3-2. Set vertex buffer view --> Vertex buffer view 
//				 --> Vertex buffer
//			3-3. Set index buffer view --> Index buffer view 
//				 --> Index buffer
//			3-4. Draw index instanced
//		4. Using transformation functions to transform the primitive 
//		   at Sample3DSceneRenderer::Render() function 
//		   by passing the command list variable.
//			4-1. MySpecialModelObjMtl::moveModelXYZ() --> Move (x,y,z)
//				 --> Change vertex buffer data coordinate values 
//					 according to transformation matrix converted from (x,y,z)
//				 --> Upload vertex buffer to GPU for update 
//				 --> Model moved on next frame.
//			4-2. MySpecialModelObjMtl::scaleModelXYZ() -->Scale (x,y,z) 
//				 --> Change vertex buffer data coordinate values 
//					according to transformation matrix converted from (x,y,z)
//				 --> Upload vertex buffer to GPU for update 
//				 --> Model moved on next frame.
//			4-3. MySpecialModelObjMtl::rotateModelXYZ() --> Rotate (x,y,z) 
//				 --> Change vertex buffer data coordinate values 
//					according to transformation matrix converted from (x,y,z)
//				 --> Upload vertex buffer to GPU for update 
//				 --> Model moved on next frame.
//			4-4. MySpecialModelObjMtl::resetModelPosition() --> Reset position 
//				 --> Change vertex buffer data coordinate values
//					back to original vertex buffer data coordinate values
//					backed up on init 
//				 --> Upload vertex buffer to GPU for update 
//				 --> Model moved on next frame.
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
//------------------------------------------------------------------------------
// [rev0000:WY:201706291800]
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
#include "ModelObj.h"
#include "MyModelObj.h"
#include "ModelMtl.h"
#include "MyModelMtl.h"
#include "MySpecialModelObjMtl.h"

// Default constructor
MySpecialModelObjMtl::MySpecialModelObjMtl() {
	// Main model object.
	this->modelObj = NULL;
	// Main material object.
	this->modelMtl = NULL;

	// Main vertex buffer initialized in ModelObj/MyModelObj
	this->modelVertices = NULL;

	// Main index buffer size initialized in MyModelObj.
	this->modelTextureCoordIndices = NULL;

	// Util object for extra features (eg. Load texture image from file).
	this->modelUtils = new Util();

	// Texture image related 
	this->textureWidth = 0;
	this->textureHeight = 0;

	// Index of the current model object's CBV descriptor alignment index
	this->modelCBVAlignmentIndex = -1;
	// Index of the current model object's SRV descriptor table offset index
	//this->modelSRVDescriptorIndex = -1;

	// CPU descriptor heap offset handle for SRV init
	modelSRVDescriptorHeapCPUOffsetHandle = new CD3DX12_CPU_DESCRIPTOR_HANDLE();
	// GPU descriptor heap offset handle for rendering
	modelSRVDescriptorHeapGPUOffsetHandle = new CD3DX12_GPU_DESCRIPTOR_HANDLE();

	// Model world matrix = Move * rotation * scale.
	this->modelWorldMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelWorldMat, XMMatrixIdentity());
	// Model translation matrix.
	this->modelTranslationMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelTranslationMat, XMMatrixIdentity());
	// Model rotation matrix.
	this->modelRotationMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelRotationMat, XMMatrixIdentity());
	// Model scaling matrix.
	this->modelScaleMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelScaleMat, XMMatrixIdentity());
}
/*
*	MySpecialModelObjMtl class general constructor.
*	<p>
*	Initialize the member variables going to be held by this current
*	MySpecialModelObjMtl with MyModelObj object with
*	OBJ data and MyModelMtl object with MTL data passed as parameters.
*   The variables to be intialized are as follows:
*		modelVertices - Main vertex buffer initialized in MyModelObj.
*		modelTextureCoordIndices - Main index buffer size initialized
*			in MyModelObj.
*		modelUtils - Util object for extra features
*			(eg. Load texture image from file).
*		globalTransformMatrix - Transformation matrix that
*			shares the transformation data for moving, rotating and scaling.
*		myPositionXYZ - Current model's center origin position.
*		textureWidth, textureHeight - Global variables for texture buffer init.
*		globalPosition, globalXVector, globalYVector, globalZVector
*			- Testing for local transformations.
*	@param		myModelObj			MyModelObj object pointer to set with.
*	@param		myModelMtl			MyModelMtl object pointer to set with.
*
*	@see		MyModelObj
*	@see		MyModelMtl
*	@since		ver0003
*/
MySpecialModelObjMtl::MySpecialModelObjMtl(ModelObj *modelObj, ModelMtl *modelMtl) {
	// Main model object.
	this->modelObj = modelObj;
	// Main material object.
	this->modelMtl = modelMtl;

	// Main vertex buffer initialized in ModelObj/MyModelObj
	this->modelVertices
		= modelObj->getVertexPositionColorTextureCoordNormalBuffer();

	// Main index buffer size initialized in MyModelObj.
	this->modelTextureCoordIndices = modelObj->getTexcoordsIndices();

	// Util object for extra features (eg. Load texture image from file).
	this->modelUtils = new Util();

	// Texture image related 
	this->textureWidth = 0;
	this->textureHeight = 0;

	// Index of the current model object's CBV descriptor alignment index
	this->modelCBVAlignmentIndex = -1;
	// Index of the current model object's SRV descriptor table offset index
	//this->modelSRVDescriptorIndex = -1;

	// CPU descriptor heap offset handle for SRV init
	modelSRVDescriptorHeapCPUOffsetHandle = new CD3DX12_CPU_DESCRIPTOR_HANDLE();
	// GPU descriptor heap offset handle for rendering
	modelSRVDescriptorHeapGPUOffsetHandle = new CD3DX12_GPU_DESCRIPTOR_HANDLE();

	// Model world matrix = Move * rotation * scale.
	this->modelWorldMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelWorldMat, XMMatrixIdentity());
	// Model translation matrix.
	this->modelTranslationMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelTranslationMat, XMMatrixIdentity());
	// Model rotation matrix.
	this->modelRotationMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelRotationMat, XMMatrixIdentity());
	// Model scaling matrix.
	this->modelScaleMat = new XMFLOAT4X4();
	XMStoreFloat4x4(modelScaleMat, XMMatrixIdentity());
}
//==============================================================================

// Destructor
MySpecialModelObjMtl::~MySpecialModelObjMtl() {
	// Main model object.
	if (this->modelObj != NULL) {
		delete this->modelObj;
		this->modelObj = NULL;
	}

	// Main material object.
	if (this->modelMtl != NULL) {
		delete this->modelMtl;
		this->modelMtl = NULL;
	}

	// Util object for extra features (eg. Load texture image from file).
	if (this->modelUtils != NULL) {
		delete this->modelUtils;
		this->modelUtils = NULL;
	}

	// Main vertex buffer.
	if (this->modelVertices != NULL) {
		this->modelVertices = NULL;
	}
	// Main index buffer - Texture coordinates indices in faces buffer
	if (this->modelTextureCoordIndices != NULL) {
		this->modelTextureCoordIndices = NULL;
	}
	// Texture image width. 
	this->textureWidth = 0;
	// Texture image height. 
	this->textureHeight = 0;

	// Index of the current model object's CBV descriptor alignment index
	this->modelCBVAlignmentIndex = -1;
	// Index of the current model object's SRV descriptor table offset index
	//this->modelSRVDescriptorIndex = -1;

	// CPU descriptor heap offset handle for SRV init
	if (this->modelSRVDescriptorHeapCPUOffsetHandle != NULL) {
		delete this->modelSRVDescriptorHeapCPUOffsetHandle;
		this->modelSRVDescriptorHeapCPUOffsetHandle = NULL;
	}
	// GPU descriptor heap offset handle for rendering
	if (this->modelSRVDescriptorHeapGPUOffsetHandle != NULL) {
		delete this->modelSRVDescriptorHeapGPUOffsetHandle;
		this->modelSRVDescriptorHeapGPUOffsetHandle = NULL;
	}

	// Model world matrix = Move * rotation * scale.
	if (this->modelWorldMat != NULL) {
		delete this->modelWorldMat;
		this->modelWorldMat = NULL;
	}
	// Model translation matrix.
	if (this->modelTranslationMat != NULL) {
		delete this->modelTranslationMat;
		this->modelTranslationMat = NULL;
	}
	// Model rotation matrix.
	if (this->modelRotationMat != NULL) {
		delete this->modelRotationMat;
		this->modelRotationMat = NULL;
	}
	// Model scaling matrix.
	if (this->modelScaleMat != NULL) {
		delete this->modelScaleMat;
		this->modelScaleMat = NULL;
	}
}

/*
*	Getter - Member variable "modelLoaderFormatNumber".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelLoaderFormatNumber".
*		- Format number to be used to determine loaded in which format
*		  when initialized through MyModelLoader from random OBJ file.
*		  Also is used to determine which MTL class functions to load
*		  the texture buffer, because get texture file path function name
*		  are different.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelLoaderFormatNumber"
*					integer value.
*	@since		ver0003
*/
int MySpecialModelObjMtl::getModelLoaderFormatNumber() {
	return this->modelLoaderFormatNumber;
}

/*
*	Getter - Member variable "modelCBVAlignmentIndex".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelCBVAlignmentIndex".
*		- The index of the CBV resources alignment of a CBV descriptor
*			to be used for rendering world space model objects.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelCBVAlignmentIndex"
*					integer value.
*	@since		ver0003
*/
int MySpecialModelObjMtl::getModelCBVAlignmentIndex() {
	return this->modelCBVAlignmentIndex;
}

/*
*	Setter - Member variable "modelCBVAlignmentIndex".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelCBVAlignmentIndex".
*		- The index of the CBV resources alignment of a CBV descriptor
*			to be used for rendering world space model objects.
*	@param		modelCBVAlignmentIndex	CBV alignment index integer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelCBVAlignmentIndex(
	int modelCBVAlignmentIndex) {
	this->modelCBVAlignmentIndex = modelCBVAlignmentIndex;
}

//==============================================================================
// SRV offset handles.
//==============================================================================
/*
*	Getter - Member variable "modelSRVDescriptorHeapCPUOffsetHandle".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelSRVDescriptorHeapCPUOffsetHandle".
*		- The CPU offset handle of the SRV descriptor heap to be used for SRV
*		  creation.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelSRVDescriptorHeapCPUOffsetHandle"
*					CD3DX12_CPU_DESCRIPTOR_HANDLE object pointer.
*	@since		ver0038
*/
CD3DX12_CPU_DESCRIPTOR_HANDLE *MySpecialModelObjMtl::getModelSRVDescriptorOffsetHandleCPU() {
	return this->modelSRVDescriptorHeapCPUOffsetHandle;
}
/*
*	Getter - Member variable "modelSRVDescriptorHeapGPUOffsetHandle".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelSRVDescriptorHeapGPUOffsetHandle".
*		- The GPU offset handle of the SRV descriptor heap to be used for 
*		  setting graphics root descriptor table offset for rendering textures.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelSRVDescriptorHeapGPUOffsetHandle"
*					CD3DX12_GPU_DESCRIPTOR_HANDLE object pointer.
*	@since		ver0038
*/
CD3DX12_GPU_DESCRIPTOR_HANDLE *MySpecialModelObjMtl::getModelSRVDescriptorOffsetHandleGPU() {
	return this->modelSRVDescriptorHeapGPUOffsetHandle;
}
/*
*	Setter - Member variable "modelSRVDescriptorHeapCPUOffsetHandle".
*	Setter - Member variable "modelSRVDescriptorHeapGPUOffsetHandle".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelSRVDescriptorHeapCPUOffsetHandle" 
*		- The CPU offset handle of the SRV descriptor heap to be used for SRV
*		  creation.
*	This function is also the setter for current MySpecialModelObjMtl object's 
*		member variable "modelSRVDescriptorHeapGPUOffsetHandle".
*		- The GPU offset handle of the SRV descriptor heap to be used for
*		  setting graphics root descriptor table offset for rendering textures.
*	@param		modelSRVDescriptorHeapCPUOffsetHandle	CPU offset handle to
*														set with.
*	@param		modelSRVDescriptorHeapCPUOffsetHandle	GPU offset handle to
*														set with.
*	@return		void
*	@since		ver0038
*/
void MySpecialModelObjMtl::setModelSRVDescriptorOffsetHandles(
	CD3DX12_CPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapCPUOffsetHandle,
	CD3DX12_GPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapGPUOffsetHandle) {
	// CPU descriptor heap offset handle for SRV init
	*this->modelSRVDescriptorHeapCPUOffsetHandle = *modelSRVDescriptorHeapCPUOffsetHandle;
	// GPU descriptor heap offset handle for rendering
	*this->modelSRVDescriptorHeapGPUOffsetHandle = *modelSRVDescriptorHeapGPUOffsetHandle;
}

/*
*	Setter - Member variable "modelLoaderFormatNumber".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelLoaderFormatNumber".
*		- Format number to be used to determine loaded in which format
*		  when initialized through MyModelLoader from random OBJ file.
*		  Also is used to determine which MTL class functions to load
*		  the texture buffer, because get texture file path function name
*		  are different.
*	@param		modelLoaderFormatNumber	Format number integer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelLoaderFormatNumber(int modelLoaderFormatNumber) {
	this->modelLoaderFormatNumber = modelLoaderFormatNumber;
}

//==============================================================================
// Init buffer related
//==============================================================================
/*
*	Main init function to initialize the necessary
*	buffers and resources in order to be rendered on DirectX 12 engine.
*	<p>
*	This function initializes 3 buffers by calling 3 different init functions
*		1. MySpecialModelObjMtl::initVertexBufferResources()
*			--> Vertex buffer init --> Vertex buffer uploaded to GPU
*			--> Vertex buffer view init
*		2. MySpecialModelObjMtl::initIndexBufferResources()
*			--> Index buffer init --> Index buffer uploaded to GPU
*			--> Index buffer view init
*		3. MySpecialModelObjMtl::initTextureBufferResources()
*			--> Texture buffer init
*			--> Texture buffer loaded from image (provided in MTL file) file
*			--> Upload resources to GPU
*			--> SRV created and added on root signature SRV descriptor table
*			--> Descriptor offset handle incremented.
*	@param		device			Device object for resource creation.
*	@param		commandList		Command list object for resource uploads.
*	@param		utils				Util object for texture image validation.
*	@param		srvDescriptorHeap	Descriptor heap object
*										to create texture SRV with.
*	@param		descriptorOffset	Current descriptor heap offset handle.
*	@param		descriptorSize		Size of a descriptor to inrement
*										offset handle with
*										when a new descriptor is added.
*	@param		descriptorOffset	Main descriptor offset index integer pointer
*										to set current texture
*										resource with, and increment directly
*										is success.
*	@return		void
*	@see		ID3D12Device
*	@see		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>
*	@since		ver0003
*/

void MySpecialModelObjMtl::initMySpecialModelObjMtl(
	ID3D12Device *device,
	ID3D12GraphicsCommandList *commandList,
	Util *util,
	ID3D12DescriptorHeap* srvDescriptorHeap,
	CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle,
	CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle,
	UINT srvHandleSize) {
	_RPT1(0, "MySpecialModelObj::initMySpecialModelObjMtl() START==============================================================================\n", 0);

	//=========================================================================
	// Vertex buffer and resources init
	//=========================================================================
	// Vertex buffer --> Upload resources to GPU --> Vertex buffer view init
	this->initVertexBufferResources(device, commandList);

	//=========================================================================
	// Vertex buffer and resources init
	//=========================================================================
	// Index buffer --> Upload resources to GPU --> Index buffer view init
	this->initIndexBufferResources(device, commandList);

	//=========================================================================
	// Texture buffer and resources init
	// The get set functions are changed according to the model loader format
	//		number.
	//=========================================================================

	//=========================================================================
	// Loaded from standard OBJ --> Standard MTL (extension .mtl) --> ModelMtl
	//=========================================================================
	_RPT1(0, "MySpecialModelObjMtl::initMySpecialModelObjMtl::Get model loader format number to decide which function to be used for texture buffer init: %d\n", this->getModelLoaderFormatNumber());

	if (this->getModelLoaderFormatNumber() == MODEL_LOADER_FORMAT_OBJ) {
		// Texture image validation before texture init
		// If texture image name provided in MTL file is valid...
		if (util->isFileExist(
			this->getModelMtl()->getMaterial_Map_Kd())) { // ModelMtl 
			_RPT1(0, "MySpecialModelObjMtl::initMySpecialModelObjMtl::OBJ::Texture image absolute file path: %s\n", this->getModelMtl()->getMaterial_Map_Kd());
			// Texture buffer init
			// --> Texture buffer loaded from image(provided in MTL file) file
			// --> Upload resources to GPU
			// --> SRV created and added on root signature SRV descriptor table
			this->initTextureBufferResources(
				device,
				commandList,
				srvDescriptorHeap,
				srvDescriptorHeapCPUOffsetHandle,
				srvDescriptorHeapGPUOffsetHandle,
				srvHandleSize,
				this->getModelMtl()->getMaterial_Map_Kd()); // ModelMtl 

			// Set memeber variable to be used for rendering.
			this->setModelSRVDescriptorOffsetHandles(srvDescriptorHeapCPUOffsetHandle, srvDescriptorHeapGPUOffsetHandle);

			// Need to offset the descriptor handle in order to load next texture
			// onto proper SRV index, but this part is done on 
			// initMySpecialModelObjMtl() function instead of here, because
			// better visualization.
			srvDescriptorHeapCPUOffsetHandle->Offset(srvHandleSize);

			// Increment the GPU decriptor offset handle to be used for 
			// rendering after it is set to each model objects
			srvDescriptorHeapGPUOffsetHandle->Offset(srvHandleSize);

			//// Increment custom SRV descriptor counter to be used for next texture resources
			//(*srvDescriptorHeapOffsetIndex)++; // Custom SRV descriptor counter
		}
		else { // Texture image file doesn't exist on given file path
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture map image path does not exist!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture map image path does not exist!!!");
		}
	}
	//=========================================================================
	// Loaded from my custom OBJ --> My custom MTL (extension .wym) 
	// --> MyModelMtl
	//=========================================================================
	else if (this->getModelLoaderFormatNumber() == MODEL_LOADER_FORMAT_WYO) {
		// Texture image validation before texture init
		// If texture image name provided in MTL file is valid...
		if (util->isFileExist(
			((MyModelMtl *)this->getModelMtl())
			->getMaterialTextureMapImagePath())) { // MyModelMtl 
			_RPT1(0, "MySpecialModelObjMtl::initMySpecialModelObjMtl::WYO::Texture image absolute file path: %s\n", ((MyModelMtl *)this->getModelMtl())->getMaterialTextureMapImagePath());
			// Texture buffer init
			// --> Texture buffer loaded from image(provided in MTL file) file
			// --> Upload resources to GPU
			// --> SRV created and added on root signature SRV descriptor table
			this->initTextureBufferResources(
				device,
				commandList,
				srvDescriptorHeap,
				srvDescriptorHeapCPUOffsetHandle,
				srvDescriptorHeapGPUOffsetHandle,
				srvHandleSize,
				((MyModelMtl *)this->getModelMtl())
				->getMaterialTextureMapImagePath()); // MyModelMtl 


			// Set memeber variable to be used for rendering.
			this->setModelSRVDescriptorOffsetHandles(srvDescriptorHeapCPUOffsetHandle, srvDescriptorHeapGPUOffsetHandle);

			// Need to offset the descriptor handle in order to load next texture
			// onto proper SRV index, but this part is done on 
			// initMySpecialModelObjMtl() function instead of here, because
			// better visualization.
			srvDescriptorHeapCPUOffsetHandle->Offset(srvHandleSize);

			// Increment the GPU decriptor offset handle to be used for 
			// rendering after it is set to each model objects
			srvDescriptorHeapGPUOffsetHandle->Offset(srvHandleSize);

			//// Increment custom SRV descriptor counter to be used for next texture resources
			//(*srvDescriptorHeapOffsetIndex)++;
		}
		else { // Texture image file doesn't exist on given file path
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture map image path does not exist!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture map image path does not exist!!!");
		}
	}
	else {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initMySpecialModelObjMtlMtl::Invalid format!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initMySpecialModelObjMtlMtl::Invalid format!!!");
	}
	_RPT1(0, "MySpecialModelObj::initMySpecialModelObjMtl() END==============================================================================\n", 0);

}
/*
*	Initialize the vertex buffer and resource
*	to be used for rendering on DirectX 12 engine.
*	<p>
*	This function initializes the vertex buffer and resources
*	using the vertex array data loaded on MyModelObj object
*	and upload them to GPU,
*	then creates the vertex buffer view needed for rendering.
*		1. Initialize vertex buffer
*			using the vertex array data loaded on MyModelObj object.
*		2. Create default and upload resources.
*		3. Convert vertex buffer to sub resource data.
*		4. Upload the vertex buffer data to GPU through
*			--> Copy sub resource data to upload resource
*			--> Default resource data copied.
*		5. Create vertex buffer view,
*			which is watching the default resource uploaded above.
*	@param		device			Device object for resource creation.
*	@param		commandList		Command list object for resource uploads.
*
*	@return		void
*	@see		ID3D12Device
*	@see		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>
*	@since		ver0003
*/

void MySpecialModelObjMtl::initVertexBufferResources(
	ID3D12Device *device,
	ID3D12GraphicsCommandList *commandList) {
	// Type init
	CD3DX12_HEAP_PROPERTIES defaultHeapProperties(D3D12_HEAP_TYPE_DEFAULT);
	CD3DX12_HEAP_PROPERTIES uploadHeapProperties(D3D12_HEAP_TYPE_UPLOAD);

	//=========================================================================
	// Initialize the main vertex buffer 
	// using the data initialized on MyModelObj object 
	//=========================================================================
	Vertex *vList = (Vertex *)malloc(VERTEX_BUFFER_SIZE * sizeof(Vertex));
	int numPrimitiveVertices
		= this->modelObj->getVertexPositionColorTextureCoordNormalBufferCount();

	//_RPT1(0, "numPrimitiveVertices : %d\n", numPrimitiveVertices);
	if (this->modelObj->getVertexPositionColorTextureCoordNormalBuffer()
		== NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer is NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer is NULL!!!");
	}
	if (numPrimitiveVertices <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer size is 0!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer size is 0!!!");
	}
	for (int i = 0; i < numPrimitiveVertices; i++) {
		VertexPositionColorTextureCoordNormal *curVertexBuffer
			= this->modelObj->getVertexPositionColorTextureCoordNormalBuffer();
		VertexPositionColorTextureCoordNormal curVertex
			= curVertexBuffer[i];
		vList[i].pos = curVertex.pos;
		//vList[i].color = curVertex.color;
		vList[i].texCoord = curVertex.tex;
	}

	int vBufferSize = sizeof(*vList) * VERTEX_BUFFER_SIZE;
	_RPT1(0, "vBufferSize : %d\n", vBufferSize);

	// create default heap
	// default heap is memory on the GPU. Only the GPU has access to this memory
	// To get data into this heap, we will have to upload the data using
	// an upload heap
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), // a default heap
		D3D12_HEAP_FLAG_NONE, // no flags
		&CD3DX12_RESOURCE_DESC::Buffer(vBufferSize), // resource description for a buffer
		D3D12_RESOURCE_STATE_COPY_DEST, // we will start this heap in the copy destination state since we will copy data
										// from the upload heap to this heap
		nullptr, // optimized clear value must be null for this type of resource. used for render targets and depth/stencil buffers
		IID_PPV_ARGS(&this->vertexBuffer));

	// we can give resource heaps a name so when we debug with the graphics debugger we know what resource we are looking at
	this->vertexBuffer->SetName(L"Vertex Buffer Resource Heap");

	// create upload heap
	// upload heaps are used to upload data to the GPU. CPU can write to it, GPU can read from it
	// We will upload the vertex buffer using this heap to the default heap
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), // upload heap
		D3D12_HEAP_FLAG_NONE, // no flags
		&CD3DX12_RESOURCE_DESC::Buffer(vBufferSize), // resource description for a buffer
		D3D12_RESOURCE_STATE_GENERIC_READ, // GPU will read from this buffer and copy its contents to the default heap
		nullptr,
		IID_PPV_ARGS(&this->vertexBufferUpload));
	this->vertexBufferUpload->SetName(L"Vertex Buffer Upload Resource Heap");

	// store vertex buffer in upload heap
	D3D12_SUBRESOURCE_DATA vertexData = {};
	vertexData.pData = reinterpret_cast<BYTE*>(vList); // pointer to our vertex array
	vertexData.RowPitch = vertexData.RowPitch; // size of all our triangle vertex data
	vertexData.SlicePitch = vBufferSize; // also the size of our triangle vertex data

										 // we are now creating a command with the command list to copy the data from
										 // the upload heap to the default heap
	UpdateSubresources(commandList, this->vertexBuffer, this->vertexBufferUpload, 0, 0, 1, &vertexData);

	// transition the vertex buffer data from copy destination state to vertex buffer state
	commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(this->vertexBuffer, D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER));

	// create a vertex buffer view for the triangle. We get the GPU memory address to the vertex pointer using the GetGPUVirtualAddress() method
	this->vertexBufferView.BufferLocation = this->vertexBuffer->GetGPUVirtualAddress();
	this->vertexBufferView.StrideInBytes = sizeof(Vertex);
	this->vertexBufferView.SizeInBytes = vBufferSize;
}
/*
void MySpecialModelObjMtl::initVertexBufferResources(
ID3D12Device *device,
ID3D12GraphicsCommandList *commandList) {
// Type init
CD3DX12_HEAP_PROPERTIES defaultHeapProperties(D3D12_HEAP_TYPE_DEFAULT);
CD3DX12_HEAP_PROPERTIES uploadHeapProperties(D3D12_HEAP_TYPE_UPLOAD);

//=========================================================================
// Initialize the main vertex buffer
// using the data initialized on MyModelObj object
//=========================================================================
VertexPositionColorTextureCoordNormal *modelVerticesBuffer
= new VertexPositionColorTextureCoordNormal[VERTEX_BUFFER_SIZE];
int numPrimitiveVertices
= this->modelObj->getVertexPositionColorTextureCoordNormalBufferCount();
//_RPT1(0, "numPrimitiveVertices : %d\n", numPrimitiveVertices);
if (this->modelObj->getVertexPositionColorTextureCoordNormalBuffer()
== NULL) {
_RPT1(0, "################################################################################\n", 0);
_RPT1(0, "ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer is NULL!!!\n", 0);
_RPT1(0, "################################################################################\n", 0);
}
if (numPrimitiveVertices <= 0) {
_RPT1(0, "################################################################################\n", 0);
_RPT1(0, "ERROR::MySpecialModelObjMtl::initVertexBufferResources::Vertex buffer size is 0!!!\n", 0);
_RPT1(0, "################################################################################\n", 0);
}
for (int i = 0; i < numPrimitiveVertices; i++) {
VertexPositionColorTextureCoordNormal *curVertexBuffer
= this->modelObj->getVertexPositionColorTextureCoordNormalBuffer();
VertexPositionColorTextureCoordNormal curVertex
= curVertexBuffer[i];
modelVerticesBuffer[i].pos = curVertex.pos;
modelVerticesBuffer[i].color = curVertex.color;
modelVerticesBuffer[i].tex = curVertex.tex;
}
// Size of the vertex buffer.
this->vertexBufferSize
= sizeof(*modelVerticesBuffer) * VERTEX_BUFFER_SIZE; // Global variable
//_RPT1(0, "vertexBufferSize : %d\n", vertexBufferSize);

// Create the vertex buffer resource in the GPU's default heap
// and copy vertex data into it using the upload heap.
// The upload resource must not be released
// until after the GPU has finished using it.
CD3DX12_RESOURCE_DESC vertexBufferDesc
= CD3DX12_RESOURCE_DESC::Buffer(this->vertexBufferSize);
device->CreateCommittedResource(
&defaultHeapProperties,
D3D12_HEAP_FLAG_NONE,
&vertexBufferDesc,
D3D12_RESOURCE_STATE_COPY_DEST,
nullptr,
IID_PPV_ARGS(&this->vertexBuffer));
device->CreateCommittedResource(
&uploadHeapProperties,
D3D12_HEAP_FLAG_NONE,
&vertexBufferDesc,
D3D12_RESOURCE_STATE_GENERIC_READ,
nullptr,
IID_PPV_ARGS(&this->vertexBufferUpload));

this->vertexBuffer->SetName(L"Vertex Buffer Default Resource");
this->vertexBufferUpload->SetName(L"Vertex Buffer Upload Resource");
//vertexBuffer->SetName(L"Vertex buffer resource");

// Upload the vertex buffer to the GPU.
{
D3D12_SUBRESOURCE_DATA vertexData = {};
vertexData.pData = reinterpret_cast<BYTE*>(modelVerticesBuffer);
vertexData.RowPitch = vertexBufferSize;
vertexData.SlicePitch = vertexData.RowPitch;

UpdateSubresources(
commandList,
this->vertexBuffer,
this->vertexBufferUpload,
0, 0, 1,
&vertexData);

CD3DX12_RESOURCE_BARRIER vertexBufferResourceBarrier =
CD3DX12_RESOURCE_BARRIER::Transition(
this->vertexBuffer,
D3D12_RESOURCE_STATE_COPY_DEST,
D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);
commandList->ResourceBarrier(1, &vertexBufferResourceBarrier);
}

// Create vertex buffer views and
// initialize onto memeber variable "vertexBufferView"
this->vertexBufferView.BufferLocation
= this->vertexBuffer->GetGPUVirtualAddress();
this->vertexBufferView.StrideInBytes
= sizeof(VertexPositionColorTextureCoordNormal);
//= sizeof(VertexPositionColorTextureCoordNormal);
this->vertexBufferView.SizeInBytes
= sizeof(*modelVerticesBuffer) * VERTEX_BUFFER_SIZE;

// init member variable "modelVertices"
this->modelVertices = modelVerticesBuffer;
}

*/

/*
*	Initialize the index buffer and resource
*	to be used for rendering on DirectX 12 engine.
*	<p>
*	This function initializes the index buffer and resources
*	using the texture coordinate index array data loaded on MyModelObj object
*	and upload them to GPU,
*	then creates the index buffer view needed for rendering.
*		1. Initialize index buffer
*			using the texture coordinate index array data
*			loaded on MyModelObj object.
*		2. Create default and upload resources.
*		3. Convert vertex buffer to sub resource data.
*		4. Upload the vertex buffer data to GPU through
*			--> Copy sub resource data to upload resource
*			--> Default resource data copied.
*		5. Create index buffer view,
*			which is watching the default resource uploaded above.
*	@param		device					Device object for resource creation.
*	@param		commandList				Command list object for resource uploads.
*
*	@return		void
*	@see		ID3D12Device
*	@see		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>
*	@since		ver0003
*/

void MySpecialModelObjMtl::initIndexBufferResources(
	ID3D12Device *device,
	ID3D12GraphicsCommandList *commandList) {
	int numPrimitiveindices = this->modelObj->getIndicesCount();

	//_RPT1(0, "numPrimitiveVertices : %d\n", numPrimitiveVertices);
	if (this->modelObj->getTexcoordsIndices() == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initIndexBufferResources::Index buffer is NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initIndexBufferResources::Index buffer is NULL!!!");
	}
	if (numPrimitiveindices <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initIndexBufferResources::Index buffer size is 0!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initIndexBufferResources::Index buffer size is 0!!!");
	}
	DWORD *iList = new DWORD[INDEX_BUFFER_SIZE];

	// Initialize index buffer using the texture coordinate index
	// array data loaded on MyModelObj object.
	for (int i = 0; i < numPrimitiveindices; i++) {
		iList[i] = this->modelObj->getTexcoordsIndices()[i];
	}

	int iBufferSize = sizeof(*iList) * INDEX_BUFFER_SIZE;

	// create default heap to hold index buffer
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT), // a default heap
		D3D12_HEAP_FLAG_NONE, // no flags
		&CD3DX12_RESOURCE_DESC::Buffer(iBufferSize), // resource description for a buffer
		D3D12_RESOURCE_STATE_COPY_DEST, // start in the copy destination state
		nullptr, // optimized clear value must be null for this type of resource
		IID_PPV_ARGS(&this->indexBuffer));

	// we can give resource heaps a name so when we debug with the graphics debugger we know what resource we are looking at
	this->indexBuffer->SetName(L"Index Buffer Resource Heap");

	// create upload heap to upload index buffer
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), // upload heap
		D3D12_HEAP_FLAG_NONE, // no flags
		&CD3DX12_RESOURCE_DESC::Buffer(iBufferSize), // resource description for a buffer
		D3D12_RESOURCE_STATE_GENERIC_READ, // GPU will read from this buffer and copy its contents to the default heap
		nullptr,
		IID_PPV_ARGS(&this->indexBufferUpload));
	this->indexBufferUpload->SetName(L"Index Buffer Upload Resource Heap");

	// store vertex buffer in upload heap
	D3D12_SUBRESOURCE_DATA indexData = {};
	indexData.pData = reinterpret_cast<BYTE*>(iList); // pointer to our index array
	indexData.RowPitch = iBufferSize; // size of all our index buffer
	indexData.SlicePitch = iBufferSize; // also the size of our index buffer

										// we are now creating a command with the command list to copy the data from
										// the upload heap to the default heap
	UpdateSubresources(commandList, this->indexBuffer, this->indexBufferUpload, 0, 0, 1, &indexData);

	// transition the vertex buffer data from copy destination state to vertex buffer state
	commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(this->indexBuffer, D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER));

	// create a vertex buffer view for the triangle. We get the GPU memory address to the vertex pointer using the GetGPUVirtualAddress() method
	this->indexBufferView.BufferLocation = this->indexBuffer->GetGPUVirtualAddress();
	this->indexBufferView.Format = DXGI_FORMAT_R32_UINT; // 32-bit unsigned integer (this is what a dword is, double word, a word is 2 bytes)
	this->indexBufferView.SizeInBytes = iBufferSize;

	// init member variable "modelTextureCoordIndices"
	this->modelTextureCoordIndices = iList;
}

/*
void MySpecialModelObjMtl::initIndexBufferResources(
ID3D12Device *device,
ID3D12GraphicsCommandList *commandList) {
// Type init
CD3DX12_HEAP_PROPERTIES defaultHeapProperties(D3D12_HEAP_TYPE_DEFAULT);
CD3DX12_HEAP_PROPERTIES uploadHeapProperties(D3D12_HEAP_TYPE_UPLOAD);
DWORD *modelIndicesBuffer
= new unsigned short[INDEX_BUFFER_SIZE];
int numPrimitiveindices = this->modelObj->getIndicesCount();

// Initialize index buffer using the texture coordinate index
// array data loaded on MyModelObj object.
for (int i = 0; i < numPrimitiveindices; i++) {
modelIndicesBuffer[i] = this->modelObj->getTexcoordsIndices()[i];
}
//_RPT1(0, "numPrimitiveVertices : %d\n", numPrimitiveVertices);
if (this->modelObj->getTexcoordsIndices() == NULL) {
_RPT1(0, "################################################################################\n", 0);
_RPT1(0, "ERROR::MySpecialModelObjMtl::initIndexBufferResources::Vertex buffer is NULL!!!\n", 0);
_RPT1(0, "################################################################################\n", 0);
}
if (numPrimitiveindices <= 0) {
_RPT1(0, "################################################################################\n", 0);
_RPT1(0, "ERROR::MySpecialModelObjMtl::initIndexBufferResources::Index buffer size is 0!!!\n", 0);
_RPT1(0, "################################################################################\n", 0);
}
const UINT indexBufferSize
= sizeof(*modelIndicesBuffer) * INDEX_BUFFER_SIZE;

// Create the index buffer resource in the GPU's default heap
// and copy index data into it using the upload heap.
// The upload resource must not be released
// until after the GPU has finished using it.
CD3DX12_RESOURCE_DESC indexBufferDesc
= CD3DX12_RESOURCE_DESC::Buffer(indexBufferSize);
device->CreateCommittedResource(
&defaultHeapProperties,
D3D12_HEAP_FLAG_NONE,
&indexBufferDesc,
D3D12_RESOURCE_STATE_COPY_DEST,
nullptr,
IID_PPV_ARGS(&this->indexBuffer));
device->CreateCommittedResource(
&uploadHeapProperties,
D3D12_HEAP_FLAG_NONE,
&indexBufferDesc,
D3D12_RESOURCE_STATE_GENERIC_READ,
nullptr,
IID_PPV_ARGS(&this->indexBufferUpload));
this->indexBuffer->SetName(L"Index Buffer Default Resource");
this->indexBufferUpload->SetName(L"Index Buffer Upload Resource");

// Upload the index buffer to the GPU.
{
D3D12_SUBRESOURCE_DATA indexData = {};
indexData.pData = reinterpret_cast<BYTE*>(modelIndicesBuffer);
indexData.RowPitch = indexBufferSize;
indexData.SlicePitch = indexData.RowPitch;

UpdateSubresources(
commandList,
this->indexBuffer,
this->indexBufferUpload,
0, 0, 1, &indexData);

CD3DX12_RESOURCE_BARRIER indexBufferResourceBarrier =
CD3DX12_RESOURCE_BARRIER::Transition(
this->indexBuffer,
D3D12_RESOURCE_STATE_COPY_DEST,
D3D12_RESOURCE_STATE_INDEX_BUFFER);
commandList->ResourceBarrier(1, &indexBufferResourceBarrier);
}

// Create index buffer views,
// which is watching the default resource uploaded just now.
this->indexBufferView.BufferLocation
= this->indexBuffer->GetGPUVirtualAddress();
this->indexBufferView.SizeInBytes
= sizeof(*modelIndicesBuffer) * INDEX_BUFFER_SIZE;
this->indexBufferView.Format = DXGI_FORMAT_R16_UINT;

// init member variable "modelTextureCoordIndices"
this->modelTextureCoordIndices = modelIndicesBuffer;
}


*/

/*
*	Initialize the texture buffer and resource
*	to be used for rendering on DirectX 12 engine.
*	<p>
*	This function initializes the texture buffer and resources
*	using the pixel byte array decoded from image file loaded
*	from given texture image file path provided
*	in MyModelMtl loaded from MTL file through MyModelLoader.
*		1. Given file path validation
*			--> Get image width height init texture description.
*		2. Load image, convert to DXGI compatible format.
*			This is done through using the functions on Util class.
*			Code brought from:
*				Braynzar Soft - Texture from file : https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file)
*		3. Create default and upload resources
*			--> Convert vertex buffer to sub resource data.
*		4. Upload the vertex buffer data to GPU through
*			--> Copy sub resource data to upload resource
*			--> Default resource data copied.
*		5. Create shader resource view (SRV)
*			and set it to the root SRV descriptor table
*			initialized at Sample3DSceneRender,
*			which is watching the default resource uploaded above.
*		6. CAUTION!!!
*			Need to increment the descriptor offset
*			with SRV descriptor size in order to
*			add next SRV descriptor (eg. texture image resource).
*	@param		device			Device object for resource creation.
*	@param		commandList		Command list object for resource uploads.
*	@param		srvDescriptorHeap	Descriptor heap object to create
*										texture SRV with.
*	@param		descriptorOffset	Current descriptor heap offset handle
*										to create texture SRV resource on.
*	@param		textureImagePath	The texture image absolute file path
*										to be loaded.
*
*	@return		void
*	@see		ID3D12Device
*	@see		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>
*	@see		Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>
*	@see		CD3DX12_CPU_DESCRIPTOR_HANDLE
*	@since		ver0003
*/
void MySpecialModelObjMtl::initTextureBufferResources(
	ID3D12Device *device,
	ID3D12GraphicsCommandList *commandList,
	ID3D12DescriptorHeap* srvDescriptorHeap,
	CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle,
	CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle,
	UINT srvHandleSize,
	char *textureImagePath) {
	// Texture image file path validation
	if (textureImagePath == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture buffer image path is not loaded!!! : %s\n", textureImagePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture buffer image path is not loaded!!!");
	}
	else if (!modelUtils->isFileExist(textureImagePath)) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture buffer image path does not exsit!!! : %s\n", textureImagePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initTextureBufferResources::Texture buffer image path does not exsit!!!");
	}

	//=========================================================================
	// Load texture part
	//=========================================================================
	// Load texture from image file 
	// --> Decode image loaded from file
	// --> convert to compatible DXGI format if needed
	// --> Bit map imageData initialized
	// Create texture resources 
	// --> Upload texture to GPU 
	// --> Create SRV 
	// --> Add SRV descriptor to root SRV descriptor table initialized
	// --> Increment the descriptor handle offset 
	//=========================================================================

	// Get image file size to create resource description
	int *textureWidthHeight
		= modelUtils->getTextureSizeWidthHeight(textureImagePath);
	textureWidth = textureWidthHeight[0];
	textureHeight = textureWidthHeight[1];
	// Texture description init
	CD3DX12_RESOURCE_DESC textureDesc
		= CD3DX12_RESOURCE_DESC::Tex2D(
			DXGI_FORMAT_R8G8B8A8_UNORM,
			textureWidth,
			textureHeight,
			1, 1);

	// Code brought from: Braynzar Soft - Texture from file : https://www.braynzarsoft.net/viewtutorial/q16390-directx-12-textures-from-file


	// Convert image file to data values
	int imageBytesPerRow = 0;
	BYTE* imageData = NULL;
	// Convert char * to LPWSTR
	wchar_t textureImagePathLPCWSTR[BUFSIZ];
	mbstowcs(
		textureImagePathLPCWSTR,
		textureImagePath,
		strlen(textureImagePath) + 1);//Plus null LPWSTR ptr = wtext;
									  // Load image + convert image
	int imageSize
		= modelUtils->LoadImageDataFromFile(
			&imageData,
			textureDesc,
			textureImagePathLPCWSTR,
			imageBytesPerRow);
	//_RPT1(0, "imageBytesPerRow : %d\n", imageBytesPerRow);

	// make sure we have data
	if (imageSize <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MySpecialModelObjMtl::initTextureBufferResources::Image loaded failed!!! : imageSize <= 0\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MySpecialModelObjMtl::initTextureBufferResources::Image loaded failed!!!");
	}

	// Create texture default resource
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT),
		D3D12_HEAP_FLAG_NONE,
		&textureDesc,
		D3D12_RESOURCE_STATE_COMMON,
		nullptr,
		IID_PPV_ARGS(&textureBuffer));

	// Create upload resource
	const UINT64 uploadBufferSize
		= GetRequiredIntermediateSize(textureBuffer, 0, 1)
		+ D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
		D3D12_HEAP_FLAG_NONE,
		&CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize),
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&textureBufferUpload));

	this->textureBuffer->SetName(L"Texture Buffer Default Resource");
	this->textureBufferUpload->SetName(L"Texture Buffer Upload Resource");

	//CD3DX12_CPU_DESCRIPTOR_HANDLE descriptorCpuHandle(srvDescriptorHeap->GetCPUDescriptorHandleForHeapStart());
	//UINT descriptorSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

	// Upload the Shader Resource to the GPU.  
	{
		// Copy data to the intermediate upload heap and then schedule a copy  
		// from the upload heap to the texture.  
		D3D12_SUBRESOURCE_DATA textureData = {};
		textureData.pData = imageData; // Main image data
		textureData.RowPitch = textureWidth * texturePixelSizeInBytes;
		textureData.SlicePitch = textureData.RowPitch * textureHeight;

		UpdateSubresources(
			commandList,
			textureBuffer,
			textureBufferUpload,
			0, 0, 1, &textureData);


		// Describe and create a SRV for the texture 
		// on given descriptor handle offset on descriptor heap 
		// passed as the parameter.
		D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
		srvDesc.Shader4ComponentMapping
			= D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
		srvDesc.Format = textureDesc.Format;
		srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = textureDesc.MipLevels;

		device->CreateShaderResourceView(
			textureBuffer,
			&srvDesc,
			*srvDescriptorHeapCPUOffsetHandle);


	}
}

//==============================================================================
// OBJ(WYO) & MTL(WYM) related
//==============================================================================
/*
*	Getter - Member variable "modelObj".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "modelObj"
*		- Holds all the information and data read from OBJ file
*		  loaded through MyModelLoader.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelObj"
*					ModelObj object pointer.
*	@see		ModelObj
*	@since		ver0003
*/
ModelObj *MySpecialModelObjMtl::getModelObj() {
	return this->modelObj;
}
/*
*	Setter - Member variable "modelObj".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*	member variable "modelObj".
*		- Holds all the information and data read from OBJ file
*		  loaded through MyModelLoader.
*	@param		modelObj		ModelObj object pointer to set with.
*	@return		void
*	@see		ModelObj
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelObj(ModelObj *modelObj) {
	this->modelObj = modelObj;
}

/*
*	Getter - Member variable "modelObj"'s
*	member variable "vertexPositionColorTextureCoordNormalBufferCount".
*	<p>
*	This function is the getter for the size of the vertex buffer initialized on
*	current MySpecialModelObjMtl object's member variable "modelObj".
*	By calling MyModelObj::getVertexPositionColorTextureCoordNormalBufferCount() function.
*	@return		Returns the size of the vertex buffer initialized
*					in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj"
*					integer value.
*	@see		MyModelObj::getVertexPositionColorTextureCoordNormalBufferCount()
*	@since		ver0003
*/
int MySpecialModelObjMtl::getVertexPositionColorTextureCoordNormalBufferCount() {
	return this->modelObj->getVertexPositionColorTextureCoordNormalBufferCount();
}

/*
*	Getter - Member variable "modelObj"'s
*	member variable "indicesCount".
*	<p>
*	This function is the getter for the size of the index buffer initialized on
*	current MySpecialModelObjMtl object's member variable "modelObj".
*	By calling MyModelObj::getIndicesCount() function.
*	@return		Returns a the size of the index buffer initialized
*					in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj"
*					integer value.
*	@see		MyModelObj::getIndicesCount()
*	@since		ver0003
*/
int MySpecialModelObjMtl::getIndicesCount() {
	return this->modelObj->getIndicesCount();
}


/*
*	Getter - Member variable "modelMtl".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "modelMtl".
*		- Holds all the information and data read from MTL file
*		  loaded through MyModelLoader.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelMtl"
*					ModelMtl object pointer.
*	@see		ModelMtl
*	@since		ver0003
*/
ModelMtl  *MySpecialModelObjMtl::getModelMtl() {
	return this->modelMtl;
}
/*
*	Setter - Member variable "modelMtl".
*	<p>
*	This function is the setter for current ModelMtl object's
*	member variable "modelMtl".
*		- Holds all the information and data read from MTL file
*		  loaded through MyModelLoader.
*	@param		modelMtl		ModelMtl object pointer to set with.
*	@return		void
*	@see		ModelMtl
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelMtl(ModelMtl  *modelMtl) {
	this->modelMtl = modelMtl;
}


//==============================================================================
// Transform related - Vertex coordinate direct access
//==============================================================================
/*
*	Getter - Member variable "modelWorldMat".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelWorldMat".
*		- The world matrix of current model object, to be used on updating
*			constant buffer resources for rendering.
*			This world matrix is the result of multiplications of
*			translation, rotation and scaling matrices.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelWorldMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *MySpecialModelObjMtl::getModelWorldMat() {
	// Init temporary matrix for calculation
	XMMATRIX temp = XMMatrixIdentity();
	// * Translation matrix
	temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->modelTranslationMat));
	// * Rotation matrix
	temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->modelRotationMat));
	// * Scale matrix
	temp = XMMatrixMultiply(temp, XMLoadFloat4x4(this->modelScaleMat));

	// Store result world matrix
	XMStoreFloat4x4(this->modelWorldMat, temp);
	return this->modelWorldMat;
}
/*
*	Setter - Member variable "modelWorldMat".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelWorldMat".
*		- The world matrix of current model object, to be used on updating
*			constant buffer resources for rendering.
*			This world matrix is the result of multiplications of
*			translation, rotation and scaling matrices.
*	@param		modelWorldMat		World matrix XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelWorldMat(XMFLOAT4X4 *modelWorldMat) {
	this->modelWorldMat = modelWorldMat;
}

/*
*	Getter - Member variable "modelTranslationMat".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelTranslationMat".
*		- The translation matrix of current model object, to be used for
*			calculating and updating model's translation.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelTranslationMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *MySpecialModelObjMtl::getModelTranslationMat() {
	return this->modelTranslationMat;
}
/*
*	Setter - Member variable "modelWorldMat".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelTranslationMat".
*		- The translation matrix of current model object, to be used for
*			calculating and updating model's translation.
*	@param		modelTranslationMat		Translation matrix
*										XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelTranslationMat(
	XMFLOAT4X4 *modelTranslationMat) {
	this->modelTranslationMat = modelTranslationMat;
}

/*
*	Getter - Member variable "modelRotationMat".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelRotationMat".
*		- The rotation matrix of current model object, to be used for
*			calculating and updating model's rotation.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelRotationMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *MySpecialModelObjMtl::getModelRotationMat() {
	return this->modelRotationMat;
}
/*
*	Setter - Member variable "modelRotationMat".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelRotationMat".
*		- The rotation matrix of current model object, to be used for
*			calculating and updating model's rotation.
*	@param		modelRotationMat		Rotation matrix
*										XMFLOAT4X4 pointer
*										value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelRotationMat(
	XMFLOAT4X4 *modelRotationMat) {
	this->modelRotationMat = modelRotationMat;
}
/*
*	Getter - Member variable "modelScaleMat".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelScaleMat".
*		- The scaling matrix of current model object, to be used for
*			calculating and updating model's scale.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelScaleMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0003
*/
XMFLOAT4X4 *MySpecialModelObjMtl::getModelScaleMat() {
	return this->modelScaleMat;
}
/*
*	Setter - Member variable "modelScaleMat".
*	<p>
*	This function is the setter for current MySpecialModelObjMtl object's
*		member variable "modelScaleMat".
*		- The scaling matrix of current model object, to be used for
*			calculating and updating model's scale.
*	@param		modelScaleMat		Scaling matrix
*									XMFLOAT4X4 pointer
*									value to set with
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::setModelScaleMat(
	XMFLOAT4X4 *modelScaleMat) {
	this->modelScaleMat = modelScaleMat;
}
//==============================================================================
// Transform related - Constant buffer
//==============================================================================
/*
*	Set model object onto world space origin coordinates (0,0,0).
*	<p>
*	This function translates the model onto the origin coordinates (0,0,0)
*		by setting the current model object's translation matrix
*		with (0,0,0) values.
*	Main problem here, is that I need to update the constant buffer for current
*		model object, in order to set to the correct given coordinate position.
*	@return		void
*	@since		ver0003
*/
void MySpecialModelObjMtl::resetModelPositionXYZ() {
	XMFLOAT4 temp = XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR posVec = XMLoadFloat4(&temp);
	XMMATRIX tmpMat = XMMatrixTranslationFromVector(posVec);

	XMStoreFloat4x4(this->modelTranslationMat, tmpMat);
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
void MySpecialModelObjMtl::setModelPositionXYZ(float x, float y, float z) {
	XMFLOAT4 temp = XMFLOAT4(x, y, z, 0.0f);
	XMVECTOR posVec = XMLoadFloat4(&temp);
	XMMATRIX tmpMat = XMMatrixTranslationFromVector(posVec);

	XMStoreFloat4x4(this->modelTranslationMat, tmpMat);
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
void MySpecialModelObjMtl::moveModelXYZ(float x, float y, float z) {
	// Calculate the translation matrix to update with.
	XMFLOAT4 temp = XMFLOAT4(x, y, z, 0.0f);
	XMVECTOR posVec = XMLoadFloat4(&temp);
	XMMATRIX tmpMat = XMMatrixTranslationFromVector(posVec);

	// Update current model's translation matrix 
	XMStoreFloat4x4(this->modelTranslationMat,
		// Multiply the calculated translation matrix onto current 
		// model's translation matrix
		XMMatrixMultiply(XMLoadFloat4x4(this->modelTranslationMat), tmpMat));
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
void MySpecialModelObjMtl::rotateModelXYZ(float x, float y, float z) {
	// Add rotation to current MySpecialObject's rotation matrix 
	// and store it.
	XMMATRIX transformMat = XMMatrixRotationZ(z) * (XMLoadFloat4x4(this->modelRotationMat) * (XMMatrixRotationX(x) * XMMatrixRotationX(y)));
	XMStoreFloat4x4(this->modelRotationMat, transformMat);
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
void MySpecialModelObjMtl::scaleModelXYZ(float x, float y, float z) {
	// Multiply scale to current MySpecialObject's scale matrix 
	// and store it.
	XMMATRIX transformMat = XMMatrixTranspose(XMMatrixScaling(x, y, z));
	transformMat = XMMatrixMultiply(XMLoadFloat4x4(this->modelScaleMat), transformMat);
	XMStoreFloat4x4(this->modelScaleMat, transformMat);
}

/*
*	Copy new vertex buffer data
*	onto current MySpecialModelObjMtl object's member variable "modelObj"'s
*	member variable "vertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function copies the vertex buffer passed as parameter
*		to current MySpecialModelObjMtl object's member variable "modelObj"'s
*		member variable "vertexPositionColorTextureCoordNormalBuffer".
*	By calling MyModelObj::copyVertexPositionColorTextureCoordNormalBuffer() function.
*	@param		vertexPositionColorTextureCoordNormalBuffer		Vertex buffer array
*																pointer to copy with.
*	@param		vertexPositionColorTextureCoordNormalCount		Size of the vertex
*																buffer array
*																pointer to copy with.
*	@return		void
*	@see		MyModelObj::copyVertexPositionColorTextureCoordNormalBuffer()
*	@since		ver0003
*/
void MySpecialModelObjMtl::copyVertexPositionColorTextureCoordNormalBuffer(
	VertexPositionColorTextureCoordNormal *vertexPositionColorTextureCoordNormalBuffer,
	int vertexPositionColorTextureCoordNormalCount) {

	this->getModelObj()->copyVertexPositionColorTextureCoordNormalBuffer(
		vertexPositionColorTextureCoordNormalBuffer,
		vertexPositionColorTextureCoordNormalCount);
}

/*
*	Set new vertex buffer data onto current MySpecialModelObjMtl object's
*	member variable "modelObj"'s
*	member variable "vertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function sets the vertex buffer pointer passed as parameter
*		to current MySpecialModelObjMtl object's member variable "modelObj"'s
*		member variable "vertexPositionColorTextureCoordNormalBuffer".
*	By calling MyModelObj::setVertexPositionColorTextureCoordNormalBuffer() function.
*	@param		vertexPositionColorTextureCoordNormalBuffer					Vertex buffer array pointer to copy with.
*	@return		void
*	@see		MyModelObj::setVertexPositionColorTextureCoordNormalBuffer()
*	@since		ver0003
*/
void MySpecialModelObjMtl::setVertexPositionColorTextureCoordNormalBuffer(
	VertexPositionColorTextureCoordNormal *vertexPositionColorTextureCoordNormalBuffer) {
	this->getModelObj()->setVertexPositionColorTextureCoordNormalBuffer(
		vertexPositionColorTextureCoordNormalBuffer);
}

//==============================================================================
// Vertex resources & Buffer related
//==============================================================================
/*
*	Getter - Member variable "vertexBuffer".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "vertexBuffer".
*		- Default resource for holding vertex buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "vertexBuffer"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *MySpecialModelObjMtl::getVertexBufferResource() {
	return this->vertexBuffer;
}
/*
*	Getter - Member variable "vertexBufferUpload".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "vertexBufferUpload".
*		- Upload resource for uploading vertex buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "vertexBufferUpload"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *MySpecialModelObjMtl::getVertexBufferUploadResource() {
	return this->vertexBufferUpload;
}
/*
*	Getter - Member variable "vertexBufferSize".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "vertexBufferSize".
*		- Size of the vertex buffer data to be uploaded to GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "vertexBufferSize"
*					UINT value.
*	@since		ver0003
*/
UINT MySpecialModelObjMtl::getVertexBufferSize() {
	return this->vertexBufferSize;
}
/*
*	Getter - Member variable "vertexBufferView".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "vertexBufferView".
*		- Vertex buffer view pointing the vertex buffer default resource
*		  on GPU side to be used for rendering on DirectX12 engine.
*	At Sample3DSceneRendere::Render() function, going to use the command list
*		ID3D12GraphicsCommandList::IASetVertexBuffers() function to set
*		the vertex buffer resources using currnet vertex buffer view
*		explained above to draw the primitive.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "vertexBufferView"
*					D3D12_VERTEX_BUFFER_VIEW object.
*	@see		D3D12_VERTEX_BUFFER_VIEW
*	@see		ID3D12GraphicsCommandList::IASetVertexBuffers()
*	@since		ver0003
*/
D3D12_VERTEX_BUFFER_VIEW MySpecialModelObjMtl::getVertexBufferView() {
	return this->vertexBufferView;
}

//==============================================================================
// Index resources & Buffer related
//==============================================================================
/*
*	Getter - Member variable "indexBuffer".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "indexBuffer".
*		- Default resource for holding index buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "indexBuffer"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *MySpecialModelObjMtl::getIndexBufferResource() {
	return this->indexBuffer;
}
/*
*	Getter - Member variable "indexBufferUpload".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "indexBufferUpload".
*		- Upload resource for uploading index buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "indexBufferUpload"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *MySpecialModelObjMtl::getIndexBufferUploadResource() {
	return this->indexBufferUpload;
}
/*
*	Getter - Member variable "indexBufferView".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "indexBufferView".
*		- Vertex buffer view pointing the vertex buffer default resource on GPU side
*		  to be used for rendering on DirectX12 engine.
*	At Sample3DSceneRendere::Render() function, going to use the command list
*		ID3D12GraphicsCommandList::IASetIndexBuffer() function
*		to set the index buffer resources
*		using currnet index buffer view explained above to draw the primitive.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "indexBufferView"
*					D3D12_VERTEX_BUFFER_VIEW object.
*	@see		D3D12_VERTEX_BUFFER_VIEW
*	@see		ID3D12GraphicsCommandList::IASetIndexBuffer()
*	@since		ver0003
*/
D3D12_INDEX_BUFFER_VIEW MySpecialModelObjMtl::getIndexBufferView() {
	return this->indexBufferView;
}

//==============================================================================
// Texture resources & Buffer related
//==============================================================================
/*
*	Getter - Member variable "textureWidth".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "textureWidth".
*		- Width of the image for texture buffer init.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "textureWidth"
*					int value.
*	@since		ver0003
*/
int MySpecialModelObjMtl::getTextureWidth() {
	return this->textureWidth;
}
/*
*	Getter - Member variable "textureHeight".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "textureHeight".
*		- Height of the image for texture buffer init.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "textureHeight"
*					int value.
*	@since		ver0003
*/
int MySpecialModelObjMtl::getTextureHeight() {
	return this->textureHeight;
}
/*
*	Getter - Member variable "textureBuffer".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*	member variable "textureBuffer".
*		- Default resource for holding texture buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "textureBuffer"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *
MySpecialModelObjMtl::getTextureBufferResource() {
	return this->textureBuffer;
}
/*
*	Getter - Member variable "textureBufferUpload".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "textureBufferUpload".
*		- Upload resource for uploading texture buffer data on GPU side.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "textureBufferUpload"
*					ID3D12Resource *object.
*	@see		Microsoft::WRL::ComPtr<ID3D12Resource>
*	@since		ver0003
*/
ID3D12Resource *
MySpecialModelObjMtl::getTextureBufferUploadResource() {
	return this->textureBufferUpload;
}

//==============================================================================
// Main ModelObj object related
//==============================================================================
/*
*	Getter - Member variable "modelVertices".
*	<p>
*	This function is the getter for current MySpecialModelObjMtl object's
*		member variable "modelVertices".
*		- Main vertex buffer array being helf by current MySpecialModelObjMtl object
*		  NOT MyModelObj.
*	So member variable "modelVertices" is initialized
*		when initializing vertex buffer resources through
*		MySpecialModelObjMtl::initVertexBufferResources() function
*		by copying the data values from array initialized on MyModelObj.
*	@return		Return current MySpecialModelObjMtl object's
*					member variable "modelVertices"
*					VertexPositionColorTextureCoordNormal array pointer.
*	@see		MySpecialModelObjMtl::initVertexBufferResources()
*	@since		ver0003
*/
VertexPositionColorTextureCoordNormal
*MySpecialModelObjMtl::getModelVertexPositionColorTextureCoordNormalBuffer() {
	return this->modelVertices;
}
/*
*	Getter - Member variable "modelObj"'s
*		member variable "originalVertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function is the getter for the original vertex buffer
*		initialized on current MySpecialModelObjMtl object's
*		member variable "modelObj".
*	By calling
*		MyModelObj::getOriginalVertexPositionColorTextureCoordNormalBuffer() function.
*	@return		Returns the original vertex buffer array pointer initialized
*					in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj",
*					VertexPositionColorTextureCoordNormal pointer pointer.
*	@see		MyModelObj::getOriginalVertexPositionColorTextureCoordNormalBuffer()
*	@since		ver0003
*/
VertexPositionColorTextureCoordNormal
**MySpecialModelObjMtl::getOriginalVertexPositionColorTextureCoordNormalBuffer() {
	return this->modelObj->getOriginalVertexPositionColorTextureCoordNormalBuffer();
}

/*
*	Getter - Member variable "modelObj"'s member variable "texcoordIndices".
*	<p>
*	This function is the getter for the array of model face element indices
*		initialized on current MySpecialModelObjMtl object's member variable "modelObj".
*	By calling MyModelObj::getTexcoordsIndices() function.
*	Caution!!! I'm currently using texture coordinate indices
*		as current model's main indices in index buffer,
*		because my index buffer is initialized
*		according to the texture coordinate indices
*		on faces element indicated in OBJ file.
*	@return		Returns the model face element indices array pointer
*					initialized in MyModelObj
*					as current MySpecialModelObjMtl object's
*					member variable "modelObj",
*					unsigned short array pointer.
*	@see		MyModelObj::getTexcoordsIndices()
*	@since		ver0003
*/
DWORD *MySpecialModelObjMtl::getModelIndexBuffer() {
	return this->modelObj->getTexcoordsIndices();
}
/*
*	Getter - Member variable "modelObj"'s member variable "texcoordIndices".
*	<p>
*	This function is the getter for the array of texture coordinate indices
*		initialized on current MySpecialModelObjMtl object's
*		member variable "modelObj".
*	By calling MyModelObj::getTexcoordsIndices() function.
*	@return		Returns the texture coordinate indices array pointer
*					initialized in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj",
*					unsigned short array pointer.
*	@see		MyModelObj::getTexcoordsIndices()
*	@since		ver0003
*/
DWORD *MySpecialModelObjMtl::getModelTexcoordIndexBuffer() {
	return this->modelObj->getTexcoordsIndices();
}
/*
*	Getter - Member variable "modelObj"'s member variable "vertexIndices".
*	<p>
*	This function is the getter for the array of vertex coordinate indices
*		initialized on current MySpecialModelObjMtl object's
*		member variable "modelObj".
*	By calling MyModelObj::getVertexIndices() function.
*	@return		Returns the vertex indices array pointer
*					initialized in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj",
*					unsigned short array pointer.
*	@see		MyModelObj::getVertexIndices()
*	@since		ver0003
*/
DWORD *MySpecialModelObjMtl::getModelVertexIndexBuffer() {
	return this->modelObj->getVertexIndices();
}
/*
*	Getter - Member variable "modelObj"'s member variable "normalIndices".
*	<p>
*	This function is the getter for the array of normal vector indices
*		initialized on current MySpecialModelObjMtl object's
*		member variable "modelObj".
*	By calling MyModelObj::getNormalIndices() function.
*	@return		Returns the normal vector indices array pointer
*					initialized in MyModelObj as current MySpecialModelObjMtl object's
*					member variable "modelObj",
*					unsigned short array pointer.
*	@see		MyModelObj::getNormalIndices()
*	@since		ver0003
*/
DWORD *MySpecialModelObjMtl::getModelNormalIndexBuffer() {
	return this->modelObj->getNormalIndices();
}
