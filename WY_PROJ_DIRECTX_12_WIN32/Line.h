#pragma once

#include <iostream>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

// Class description: 
//		This class represents an actual line (line between 2 points) to be 
//		rendered onto this DirectX 12 engine.
class Line {
private:
	//=====================================================================
	// Constant buffer related
	//=====================================================================
	// Index of the current line object's CBV descriptor alignment index.
	int lineCBVAlignmentIndex;

	// Transformation matrices.
	DirectX::XMFLOAT4X4 *lineWorldMat;			// Move * rotation * scale.
	DirectX::XMFLOAT4X4 *lineTranslationMat;	// Move matrix.
	DirectX::XMFLOAT4X4 *lineRotationMat;		// Rotation matrix.
	DirectX::XMFLOAT4X4 *lineScaleMat;			// Scaling matrix.
	
	// First point of the line.
	DirectX::XMFLOAT3 p1;
	// Second point of the line.
	DirectX::XMFLOAT3 p2;

	// Vertex buffer of a Point object.
	ID3D12Resource *vertexLineBuffer;
	// Upload resource for vertex buffer.
	ID3D12Resource *vertexLineBufferUpload;

	// Index buffer of a Point object.
	ID3D12Resource *indexLineBuffer;
	// Upload resource for index buffer.
	ID3D12Resource *indexLineBufferUpload;

	// Vertex buffer view.
	D3D12_VERTEX_BUFFER_VIEW vertexLineBufferView;
	// Index buffer view.
	D3D12_INDEX_BUFFER_VIEW	indexLineBufferView;

public:
	// Default constructor.
	Line();
	// General constructor.
	Line(DirectX::XMFLOAT3 p1, DirectX::XMFLOAT3 p2);
	// Destructor
	~Line();

	// Member variable "p1" setter - Set first point of the line.
	void setP1(DirectX::XMFLOAT3 p1);
	// Member variable "p2" setter - Set second point of the line.
	void setP2(DirectX::XMFLOAT3 p2);


	// Initializes the resources vertex and index buffers resources 
	// for "this" Line object using member variable "p1" and "p2" to create a 
	// line primitive between this 2 points so a line with given 2 point 
	// coordinate values can be rendered on screen using DirectX 12 engine.
	void createLine(
		ID3D12Device *d3dDevice,
		ID3D12GraphicsCommandList *commandList);

	//------------------------------------------------------------------------------------
	// Buffer view related.
	//------------------------------------------------------------------------------------
	// Memeber varaible "vertexPointBufferView" getter.
	D3D12_VERTEX_BUFFER_VIEW getVertexLineBufferView();
	// Memeber varaible "indexPointBufferView" getter.
	D3D12_INDEX_BUFFER_VIEW getIndexLineBufferView();

	// Member variable "lineCBVAlignmentIndex" getter.
	int getLineCBVAlignmentIndex();
	// Member variable "lineCBVAlignmentIndex" setter.
	void setLineCBVAlignmentIndex(int lineCBVAlignmentIndex);

	// Member variable "lineWorldMat" getter.
	DirectX::XMFLOAT4X4 *getLineWorldMat();
	// Member variable "lineWorldMat" setter.
	void setLineWorldMat(DirectX::XMFLOAT4X4 *lineWorldMat);

	// Member variable "lineTranslationMat" getter.
	DirectX::XMFLOAT4X4 *getLineTranslationMat();
	// Member variable "lineTranslationMat" setter.
	void setLineTranslationMat(DirectX::XMFLOAT4X4 *lineTranslationMat);

	// Member variable "lineRotationMat" getter.
	DirectX::XMFLOAT4X4 *getLineRotationMat();
	// Member variable "lineRotationMat" setter.
	void setLineRotationMat(DirectX::XMFLOAT4X4 *lineRotationMat);

	// Member variable "lineScaleMat" getter.
	DirectX::XMFLOAT4X4 *getLineScaleMat();
	// Member variable "lineScaleMat" setter.
	void setLineScaleMat(DirectX::XMFLOAT4X4 *lineScaleMat);

	//=====================================================================
	// Transform related - Constant buffer.
	//=====================================================================
	// Set line locaiton.
	void setModelPositionXYZ(float x, float y, float z);
	// Move line x unit on X axis, y unit on Y axis, z unit on Z axis.
	void moveModelXYZ(float x, float y, float z);
	// Rotate line 
	//	x degree around X axis, 
	//	y degree around Y axis, 
	//	z degree around Z axis.
	void rotateModelXYZ(float x, float y, float z);
	// Scale line 
	//	x factor along X axis, 
	//	y factor along Y axis, 
	//	z factor along Z axis.
	void scaleModelXYZ(float x, float y, float z);
};
