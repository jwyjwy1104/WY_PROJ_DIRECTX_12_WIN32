#pragma once

#include "ModelMtl.h"

// Class description: 
//		This class represents a model object which holds all the information
//		needed to be rendered on DirectX 12 application.
//			This is the wrapper class of ModelObj and ModelMtl, so this class
//			have model information and material information in one variable.
//			Many properties needed to render the model except the model and 
//			material informations are added to this class so i can handle the 
//			model rendering in one place.
//			(eg. Vertex buffer resources, Index buffer resources, CBV, SRV ...)
//
//==============================================================================
// MySpecialModelObjMtl class
//==============================================================================
//		========================================================================
//		ModelObj class
//		========================================================================
//		OBJ: Standard OBJ file exported through other 3D engine like Blender as
//				default ".obj" extension.
//		========================================================================
//			====================================================================
//			MyModelObj class
//			====================================================================
//			WYO : Custom exported model file exported through my custom model
//				 exporter Blender Python script through Blender.
//			====================================================================
//		========================================================================
//		ModelMtl class
//		========================================================================
//		MTL : Standard MTL file exported through other 3D engine like Blender as
//				default ".mtl" extension where it is automatically generated
//				whenever OBJ file is exported.
//		========================================================================
//			====================================================================
//			MyModelMtl class
//			====================================================================
//			WYM : Custom exported material file exported through my custom 
//				  material exporter Blender Python script through Blender.
//			====================================================================
//==============================================================================

class MySpecialModelObjMtl {
private:
	//==========================================================================
	// Model loader format number to configure which format this 
	// model is loaded with
	//==========================================================================
	int modelLoaderFormatNumber;

	//==========================================================================
	// CBV - Constant buffer & transformation realted
	//==========================================================================
	// Index of the current model object's CBV descriptor alignment index
	int modelCBVAlignmentIndex;
	// Index of the current model object's SRV descriptor table offset index
	//int modelSRVDescriptorIndex;

	// CPU descriptor heap offset handle for SRV init
	CD3DX12_CPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapCPUOffsetHandle;
	// GPU descriptor heap offset handle for rendering
	CD3DX12_GPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapGPUOffsetHandle;

	// Model world matrix = Move * rotation * scale.
	DirectX::XMFLOAT4X4 *modelWorldMat;			
	// Model translation matrix.
	DirectX::XMFLOAT4X4 *modelTranslationMat;	
	// Model rotation matrix.
	DirectX::XMFLOAT4X4 *modelRotationMat;		
	// Model scaling matrix.
	DirectX::XMFLOAT4X4 *modelScaleMat;

	//==========================================================================
	// OBJ (WYO) & MTL (WYM)
	//==========================================================================
	// Main model object.
	ModelObj *modelObj;
	// Main material object.
	ModelMtl *modelMtl;

	// Util object for extra features (eg. Load texture image from file).
	Util *modelUtils;

	//==========================================================================
	// Vertex buffer related
	//==========================================================================
	// Main vertex buffer.
	VertexPositionColorTextureCoordNormal *modelVertices;
	// Global vertex buffer size to be used 
	// for updating vertex buffer for transformations.
	UINT vertexBufferSize;
	// Default resource.
	ID3D12Resource *vertexBuffer;
	// Upload resource.
	ID3D12Resource *vertexBufferUpload;
	// Vertex buffer view watching upload resources on GPU for rendering.
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView;

	//==========================================================================
	// Index buffer related
	//==========================================================================
	// Main index buffer - Texture coordinates indices in faces buffer
	// (eg. f v/t/n --> t).
	DWORD *modelTextureCoordIndices;
	//UINT indexBufferSize;

	// Default resource.
	ID3D12Resource *indexBuffer;
	// Upload resource.
	ID3D12Resource *indexBufferUpload;
	// Index buffer view watching upload resources on GPU for rendering.
	D3D12_INDEX_BUFFER_VIEW	indexBufferView;

	//==========================================================================
	// Texture buffer related
	//==========================================================================
	// Texture image width.
	int textureWidth;
	// Texture image height.
	int textureHeight;
	// Pixel size in bytes.
	static const UINT texturePixelSizeInBytes = 4;

	// Default resource.
	ID3D12Resource *textureBuffer;
	// Upload resource.
	ID3D12Resource *textureBufferUpload;

public:
	// Default constructor
	MySpecialModelObjMtl();

	// General constructor
	MySpecialModelObjMtl(ModelObj *modelObj, ModelMtl *modelMtl);

	// Destructor
	~MySpecialModelObjMtl();

	// Member variable "modelLoaderFormatNumber" getter.
	int getModelLoaderFormatNumber();
	// Member variable "modelLoaderFormatNumber" setter.
	void setModelLoaderFormatNumber(int modelLoaderFormatNumber);

	// Member variable "modelCBVAlignmentIndex" getter.
	int getModelCBVAlignmentIndex();
	// Member variable "modelCBVAlignmentIndex" setter.
	void setModelCBVAlignmentIndex(int modelCBVAlignmentIndex);

	//==========================================================================
	// SRV offset handles.
	//==========================================================================
	// Member variable "modelSRVDescriptorHeapCPUOffsetHandle" getter.
	CD3DX12_CPU_DESCRIPTOR_HANDLE *getModelSRVDescriptorOffsetHandleCPU();
	// Member variable "modelSRVDescriptorHeapGPUOffsetHandle" getter.
	CD3DX12_GPU_DESCRIPTOR_HANDLE *getModelSRVDescriptorOffsetHandleGPU();

	// Member variable "modelSRVDescriptorHeapCPUOffsetHandle" setter.
	// Member variable "modelSRVDescriptorHeapGPUOffsetHandle" setter.
	void setModelSRVDescriptorOffsetHandles(
		CD3DX12_CPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapCPUOffsetHandle,
		CD3DX12_GPU_DESCRIPTOR_HANDLE *modelSRVDescriptorHeapGPUOffsetHandle);

	//==========================================================================
	// Init buffer related
	//==========================================================================
	// Init vertex + index + texture buffer
	void initMySpecialModelObjMtl(
		ID3D12Device *device,
		ID3D12GraphicsCommandList *commandList,
		Util *util,
		ID3D12DescriptorHeap* srvDescriptorHeap,
		CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle,
		CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle,
		UINT srvHandleSize);
	// Init vertex buffer
	void initVertexBufferResources(
		ID3D12Device *device,
		ID3D12GraphicsCommandList *commandList);
	// init index buffer
	void initIndexBufferResources(
		ID3D12Device *device,
		ID3D12GraphicsCommandList *commandList);
	// Init texture buffer
	void initTextureBufferResources(
		ID3D12Device *device,
		ID3D12GraphicsCommandList *commandList,
		ID3D12DescriptorHeap* srvDescriptorHeap,
		CD3DX12_CPU_DESCRIPTOR_HANDLE *srvDescriptorHeapCPUOffsetHandle,
		CD3DX12_GPU_DESCRIPTOR_HANDLE *srvDescriptorHeapGPUOffsetHandle,
		UINT srvHandleSize,
		char *textureImagePath);

	//==========================================================================
	// OBJ(WYO) & MTL(WYM) related
	//==========================================================================
	// Member variable "modelObj" getter.
	ModelObj *getModelObj();
	// Member variable "modelObj" setter.
	void setModelObj(ModelObj  *modelObj);

	// Number of elements in vertex buffer
	int getVertexPositionColorTextureCoordNormalBufferCount();
	// Number of indices in index buffer.
	int getIndicesCount();

	// Member variable "modelMtl" getter.
	ModelMtl *getModelMtl();
	// Member variable "modelMtl" setter.
	void setModelMtl(ModelMtl  *modelMtl);

	//==========================================================================
	// Transform related - Vertex coordinate direct access
	//==========================================================================
	// Member variable "modelWorldMat" getter.
	DirectX::XMFLOAT4X4 *getModelWorldMat();
	// Member variable "modelWorldMat" setter.
	void setModelWorldMat(DirectX::XMFLOAT4X4 *modelWorldMat);

	// Member variable "modelTranslationMat" getter.
	DirectX::XMFLOAT4X4 *getModelTranslationMat();
	// Member variable "modelTranslationMat" setter.
	void setModelTranslationMat(DirectX::XMFLOAT4X4 *modelTranslationMat);

	// Member variable "modelRotationMat" getter.
	DirectX::XMFLOAT4X4 *getModelRotationMat();
	// Member variable "modelRotationMat" setter.
	void setModelRotationMat(DirectX::XMFLOAT4X4 *modelRotationMat);

	// Member variable "modelScaleMat" getter.
	DirectX::XMFLOAT4X4 *getModelScaleMat();
	// Member variable "modelScaleMat" setter.
	void setModelScaleMat(DirectX::XMFLOAT4X4 *modelScaleMat);

	//==========================================================================
	// Transform related - Constant buffer
	//==========================================================================
	void resetModelPositionXYZ(); // Reset model to (0,0,0)
	// Set model locaiton
	void setModelPositionXYZ(float x, float y, float z);
	// Move model x unit on X axis, y unit on Y axis, z unit on Z axis
	void moveModelXYZ(float x, float y, float z);
	// Rotate model 
	//	x degree around X axis, 
	//	y degree around Y axis, 
	//	z degree around Z axis
	void rotateModelXYZ(float x, float y, float z);
	// Scale model 
	//	x factor along X axis, 
	//	y factor along Y axis, 
	//	z factor along Z axis
	void scaleModelXYZ(float x, float y, float z);

	void copyVertexPositionColorTextureCoordNormalBuffer(
		VertexPositionColorTextureCoordNormal
		*vertexPositionColorTextureCoordNormalBuffer,
		int vertexPositionColorTextureCoordNormalBufferCount);
	void setVertexPositionColorTextureCoordNormalBuffer(
		VertexPositionColorTextureCoordNormal
		*vertexPositionColorTextureCoordNormalBuffer);

	//==========================================================================
	// Vertex resources & Buffer related
	//==========================================================================
	// Member variable "vertexBuffer" related
	ID3D12Resource *getVertexBufferResource();
	// Member variable "vertexBufferUpload" related
	ID3D12Resource *getVertexBufferUploadResource();
	// Member variable "vertexBufferSize" related
	UINT getVertexBufferSize();
	// Member variable "vertexBufferView" related
	D3D12_VERTEX_BUFFER_VIEW getVertexBufferView();

	//==========================================================================
	// Index resources & Buffer related
	//==========================================================================
	// Member variable "indexBuffer" related
	ID3D12Resource *getIndexBufferResource();
	// Member variable "indexBufferUpload" related
	ID3D12Resource *getIndexBufferUploadResource();
	// Member variable "indexBufferView" related
	D3D12_INDEX_BUFFER_VIEW getIndexBufferView();

	//==========================================================================
	// Texture resources & Buffer related
	//==========================================================================
	// Member variable "textureWidth" related
	int getTextureWidth();
	// Member variable "textureHeight" related
	int getTextureHeight();
	// Member variable "textureBuffer" related
	ID3D12Resource *getTextureBufferResource();
	// Member variable "textureBufferUpload" related
	ID3D12Resource *getTextureBufferUploadResource();

	//==========================================================================
	// Main ModelObj object related
	//==========================================================================
	// Member variable "modelObj" related - Vertex buffer getter.
	VertexPositionColorTextureCoordNormal
		*getModelVertexPositionColorTextureCoordNormalBuffer();
	// Member variable "modelObj" related 
	// - Backup original vertex buffer getter.
	VertexPositionColorTextureCoordNormal
		**getOriginalVertexPositionColorTextureCoordNormalBuffer();

	// Member variable "modelObj" related - Index buffer getter.
	DWORD *getModelIndexBuffer();
	// Member variable "modelObj" related 
	// - Texture coordinates index array getter.
	DWORD *getModelTexcoordIndexBuffer();
	// Member variable "modelObj" related
	// - Vertices index array getter.
	DWORD *getModelVertexIndexBuffer();
	// Member variable "modelObj" related
	// - Normal vectors index array getter.
	DWORD *getModelNormalIndexBuffer();
};
