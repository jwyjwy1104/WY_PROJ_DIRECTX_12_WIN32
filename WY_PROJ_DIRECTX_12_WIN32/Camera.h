#pragma once

#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include "d3dx12.h"

#include "MyModelLoader.h"
#include "MySpecialModelObjMtl.h"

// Class description: 
//		This represents a camera to be used to render 3D objects using this
//		DirectX 12 engine.
class Camera {
private:
	//=====================================================================
	// Main screen related.
	//=====================================================================
	float screenWidth; // Camera screen width.
	float screenHeight; // Camera screen height.

	// Main camera model
	MySpecialModelObjMtl *cameraModel;

	//=====================================================================
	// Camera data needed for DirectX 12 engine for rendering a scene.
	//=====================================================================
	// Camera location.
	DirectX::XMVECTOR *eye;

	// Location of the camera target, where the camera is looking at.
	// Camera direction.
	DirectX::XMVECTOR *at;

	// Up vector for camera orientation.
	// Camera orientation.
	DirectX::XMVECTOR *up;

	// View matrix for constant buffer data setup.
	DirectX::XMFLOAT4X4 *cameraViewMat; 

	// Projection matrix for constant buffer data setup.
	DirectX::XMFLOAT4X4 *cameraProjMat; 

	// Camera field of view angle.
	float fovAngleY;

	// Distance from camera position to near clip plane.
	float nearClipping;

	// Distance from camera position to far clip plane.
	float farClipping;
public:
	// General constructor.
	Camera(
		float screenWidth, float screenHeight,
		float fovAngleY,
		float nearClipping,
		float farClipping,
		DirectX::XMVECTOR *eye, 
		DirectX::XMVECTOR *at, 
		DirectX::XMVECTOR *up,
		MyModelLoader *modelLoader,
		char *cameraModelObjPath);

	// Destructor.
	~Camera();

	// Member variable "cameraModel" getter.
	MySpecialModelObjMtl *getCameraModel();
	// Member variable "cameraModel" setter.
	void setCameraModel(MySpecialModelObjMtl *cameraModel);

	// Camera update function.
	// Updates the data being held by current Camera object.
	void cameraUpdate(float screenHWidth, float screenHeight,
		float fovAngleY,
		float nearClipping, float farClipping);

	//=====================================================================
	// Eye - Camera position
	//=====================================================================
	// Member variable "eye" getter.
	DirectX::XMVECTOR *getCameraEye();
	// Member variable "eye" setter.
	void setCameraEye(DirectX::XMVECTOR *eye);

	void setCameraEyeXYZ(float x, float y, float z);

	//=====================================================================
	// At - Camera direciton
	//=====================================================================
	// Member variable "at" getter.
	DirectX::XMVECTOR *getCameraAt();
	// Member variable "at" setter.
	void setCameraAt(DirectX::XMVECTOR *at);
	void setCameraAtXYZ(float x, float y, float z);

	//=====================================================================
	// Up - Camera orientation
	//=====================================================================
	// Member variable "up" getter.
	DirectX::XMVECTOR *getCameraUp();
	// Member variable "up" setter.
	void setCameraUp(DirectX::XMVECTOR *up);
	void setCameraUpXYZ(float x, float y, float z);

	//=====================================================================
	// Camera data 
	//=====================================================================
	// Member variable "cameraViewMat" related.
	DirectX::XMFLOAT4X4 *getCameraViewMat();
	// Member variable "cameraProjMat" related.
	DirectX::XMFLOAT4X4 *getCameraProjMat();

	// Member variable "nearClipping" getter.
	float getNearClipping();
	// Member variable "nearClipping" setter.
	void setNearClipping(float nearClipping);

	// Member variable "farClipping" getter.
	float getFarClipping();
	// Member variable "farClipping" setter.
	void setFarClipping(float farClipping);

	//=====================================================================
	// Transformation
	//=====================================================================
	// Move camera model along XYZ with corresponding XYZ values.
	void moveCameraXYZ(float x, float y, float z);
};