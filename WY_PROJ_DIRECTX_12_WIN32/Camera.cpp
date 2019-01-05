// File name: [Camera.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WEw5VlhCa0NCak0
//		Use case: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N0gzQzdEX0XMcWs
//		Sequence diagram: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4SzVjdTNEMFdhcms
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]: 
//		This class holds all the information needed to apply the DirectX 12 
//			engine camera framework.
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//-----------------------------------------------------------------------------
// [rev0001:WY:201707020005]
//-----------------------------------------------------------------------------
// File name: [Camera.cpp] (Copyright to Samil Chai)
// Work Session #0168: 2017-06-27
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WEw5VlhCa0NCak0
//		Use case: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N0gzQzdEX0XMcWs
//		Sequence diagram: https://www.draw.io/?state=%7B%22folderId%22:%220B8vIEi2xiwB4d2Z3RHMyRVNQSjg%22,%22action%22:%22create%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4SzVjdTNEMFdhcms
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]: 
//		This class holds all the information needed to apply the DirectX 12 
//			engine camera framework.
//		Since the code is from UWP platform to Win32, 
//			so codes needed some changes.
// - [Framework]:
//		Each Camera object will have its own calculated view and projection 
//			matrix to be assigned to each constant buffer descriptor resources
//			to properly render objects onto the screen.
//		Camera class properties:
//			float screenWidth;
//				- The width of the camera screen.
//			float screenHeight;
//				- The height of the camera screen.
//			MySpecialModelObj *cameraModel;
//				- Model object of camera.
//			XMVECTOR *eye;
//				- Camera position.
//			XMVECTOR *at;
//				- Camera direction, position of where camera is looking at.
//			XMVECTOR *up;
//				- Camera orientation, up vector of the camera.
//			XMFLOAT4X4 *cameraViewMat; 
//				- Current camera's view matrix to be used for rendering.
//			XMFLOAT4X4 *cameraProjMat; 
//				- Current camera's projection matrix to be used for rendering.
//			float fovAngleY
//				- Camera field of view angle.
//			float nearClipping;
//				- Current camera's distance to the near clip plane.
//			float farClipping;
//				- Current camera's distance to the far clip plane.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0002_cameraclass_tested_201706272200
//-----------------------------------------------------------------------------
// [rev0000:WY:201706272000]
//-----------------------------------------------------------------------------
//#############################################################################
//#############################################################################
//#############################################################################
// Code
//#############################################################################
//#############################################################################
//#############################################################################
#pragma once

#include <iostream>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

using namespace std;
using namespace DirectX;

#include "d3dx12.h"

#include "Camera.h"
/*
*	Camera class general constructor.
*	<p>
*	This function creates and return a Camera object
*		initialized with the data passed as parameters.
*	Calculates the view and projection matrix of the camera
*		using the data passed as parameters
*		by calling Camera::cameraUpdate() function with proper arguments.
*	@param		screenWidth					The width of the camera screen
*	@param		screenHeight				The height of the camera screen
*	@param		nearClipping				The distance between
*												camera and near clip space.
*	@param		farClipping					The distance between
*												camera and far clip space.
*	@param		eye							The position of "this"
*												camera center origin.
*	@param		at							The position where the "this" 
*												camera is looking at.
*	@param		up							The orientation of the "this" 
*												camera's up vector.
*	@param		modelLoader					The model loader pointer to be used
*												for loading "this" camera
*												model objects.
*	@param		cameraModelObjPath			"This" camera model OBJ file path.
*	@see		XMVECTOR
*	@see		XMMATRIX
*	@see		WY_PROJ_DIRECTX_12::MyModelLoader
*	@since		ver0002
*/
Camera::Camera(
	float screenWidth, float screenHeight,
	float fovAngleY,
	float nearClipping,
	float farClipping,
	XMVECTOR *eye, XMVECTOR *at, XMVECTOR *up,
	MyModelLoader *modelLoader,
	char *cameraModelObjPath) {

	// Set "this" camera screen width.
	this->screenWidth = screenWidth;
	// Set "this" camera screen height.
	this->screenHeight = screenHeight;
	// Set "this" camera field of view angle.
	this->fovAngleY = fovAngleY;

	// Set "this" camera near clipping value.
	this->nearClipping = nearClipping;
	// Set "this" camera far clipping value.
	this->farClipping = farClipping;

	// Set "this" camera data
	this->eye = eye;	// Camera location.
	this->at = at;		// Camera direction.
	this->up = up;		// Camera orientation.

	// Init "this" camera model if model loader passed in is not NULL 
	// and model obj path is valid.
	if (cameraModelObjPath == NULL || modelLoader == NULL) {
		// If model loader is invalid then output error message and throw
		// run time error exception.
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::Camera::Camera::Camera model OBJ cannot be loaded either because the loader in invalid ot the file path is invalid!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		//throw std::runtime_error("ERROR::Camera::Camera::Camera model OBJ cannot be loaded either because the loader in invalid or the file path is invalid!!!");
	}
	else {
		// Load the camera model OBJ if both model loader and 
		// camera model OBJ file path is valid.
		if (modelLoader->myObjMtlLoader(cameraModelObjPath) != NULL) {
			// Set the member variable cameraModel to hold the loaded model 
			// if model is loaded properly using given OBJ file path.
			this->cameraModel = modelLoader->myObjMtlLoader(cameraModelObjPath);
		}
		else {
			// Print error message and throw the run time exception
			// if load model from given OBJ file failed.
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::Camera::Camera::Camera model loaded failed, file name: %s\n", cameraModelObjPath);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::Camera::Camera::Camera model OBJ cannot be loaded either because the loader in invalid or the file path is invalid!!!");
		}
	}

	//==========================================================================
	// Init "this" camera view and projection matrix.
	//==========================================================================
	this->cameraViewMat = new XMFLOAT4X4();
	this->cameraProjMat = new XMFLOAT4X4();

	//==========================================================================
	// Calculates and updates "this" camera object data.
	//==========================================================================
	this->cameraUpdate(
		this->screenWidth, 
		this->screenHeight,
		this->fovAngleY, 
		this->nearClipping, 
		this->farClipping);
}

// Destructor
Camera::~Camera() {
	//=========================================================================
	// Screen related.
	//=========================================================================
	// Set "this" camera screen width.
	this->screenWidth = 0;
	// Set "this" camera screen height.
	this->screenHeight = 0;
	// Set "this" camera field of view angle.
	this->fovAngleY = 0;

	// Distance from camera position to near clip plane.
	this->nearClipping = 0.0f;

	// Distance from camera position to far clip plane.
	this->farClipping = 0.0f;

	// Main camera model
	if (this->cameraModel != NULL) {
		delete this->cameraModel;
		this->cameraModel = NULL;
	}

	//=========================================================================
	// Resources needed for DirectX 12 engine for rendering a scene.
	//=========================================================================
	// Camera location.
	if (this->eye != NULL) {
		delete this->eye;
		this->eye = NULL;
	}

	// Location of the camera target, where the camera is looking at.
	// Camera direction
	if (this->at != NULL) {
		delete this->at;
		this->at = NULL;
	}

	// Up vector for camera orientation.
	// Camera orientation.
	if (this->up != NULL) {
		delete this->up;
		this->up = NULL;
	}

	// View matrix for constant buffer data setup.
	if (this->cameraViewMat != NULL) {
		delete this->cameraViewMat;
		this->cameraViewMat = NULL;
	}

	// Projection matrix for constant buffer data setup.
	if (this->cameraProjMat != NULL) {
		delete this->cameraProjMat;
		this->cameraProjMat = NULL;
	}
}

/*
*	Getter - Member variable "cameraModel".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "cameraModel".
*		- MySpecialModelObjMtl object pointer
*		  which holds all the information of
*		  current camera model.
*	@return		Return current Camera object's
*					member variable "cameraModel"
*					MySpecialModelObjMtl pointer.
*	@see		XMVECTOR
*	@since		ver0002
*/
MySpecialModelObjMtl *Camera::getCameraModel() {
	return this->cameraModel;
}

/*
*	Setter - Member variable "cameraModel".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "cameraModel".
*		- MySpecialModelObjMtl which holds all the information of
*		  current camera model.
*	@param		cameraModel			MySpecialModelObjMtl pointer to set with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraModel(MySpecialModelObjMtl *cameraModel) {
	this->cameraModel = cameraModel;
}
//#############################################################################

/*
*	Main camera update function to update the camera attributes needed
*		to render scene onto the screen.
*	<p>
*	Updates the camera view and projection matrcies with updated screen
*		width and screen height and extra information being held by "this"
*		Camera object.
*	@param		screenHWidth			The width of the camera screen
*											to update with.
*	@param		screenHeight			The height of the camera screen
*											to update with.
*	@param		fovAngleY				The field of view angle of the camera.
*	@param		nearClipping			The distance from camera to the near
*											 clip plane to update with.
*	@param		farClipping			The distance from camera to the far
*											 clip plane to update with.
*	@return		void
*	@see		XMMATRIX
*	@since		ver0002
*/
void Camera::cameraUpdate(float screenHWidth, float screenHeight,
	float fovAngleY,
	float nearClipping, float farClipping) {
	// Update "this" camera width
	this->screenWidth = screenHWidth;
	// Update "this" camera height
	this->screenHeight = screenHeight;

	// Update "this" camera near clipping value
	this->nearClipping = nearClipping;
	// Update "this" camera far clipping value
	this->farClipping = farClipping;

	// Re-build and update "this" camera object's projection matrix
	XMMATRIX tmpMat = XMMatrixPerspectiveFovLH(
		fovAngleY*(3.14f / 180.0f), 
		(float)this->screenWidth / (float)this->screenHeight,
		this->nearClipping, // eg. 0.1f
		this->farClipping); // eg. 1000.0f
	// Store updated camera projection matrix with re-calculated value
	XMStoreFloat4x4(&*this->cameraProjMat, tmpMat);

	// Re-build and update "this" camera object's view matrix
	tmpMat = XMMatrixLookAtLH(*this->eye, *this->at, *this->up);
	// Store updated camera view matrix with re-calculated value
	XMStoreFloat4x4(&*this->cameraViewMat, tmpMat);
}

//=============================================================================
// Eye - Camera position
//=============================================================================
/*
*	Getter - Member variable "eye".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "eye".
*		- Coordinate of the camera origin location.
*	@return		Return current Camera object's
*					member variable "eye"
*					XMVECTOR pointer.
*	@see		XMVECTOR
*	@since		ver0002
*/
XMVECTOR *Camera::getCameraEye() {
	return this->eye;
}
/*
*	Setter - Member variable "eye".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "eye".
*		- Coordinate of the camera origin location.
*	@param		eye			Camera location coordinate
*							XMVECOTR pointer to set with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraEye(XMVECTOR *eye) {
	this->eye = eye;
}
/*
*	Assign X, Y and Z coordinate value
*		onto the member variable "eye" corresponding coordinate components.
*	<p>
*	This function assigns the X, Y and Z value passed as parameters,
*		onto the current Camera object's
*		member variable "eye" corresponding coordinate components.
*		- Coordinate of the camera origin location.
*	@param		x			Camera location coordinate X value to assign with.
*	@param		y			Camera location coordinate Y value to assign with.
*	@param		z			Camera location coordinate Z value to assign with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraEyeXYZ(float x, float y, float z) {
	this->eye->m128_f32[0] = x;
	this->eye->m128_f32[1] = y;
	this->eye->m128_f32[2] = z;
}

//=============================================================================
// At - Camera direciton
//=============================================================================
/*
*	Getter - Member variable "at".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "at".
*		- Target location which current Camera object is looking towards to.
*	@return		Return current Camera object's
*					member variable "at"
*					XMVECTOR pointer.
*	@see		XMVECTOR
*	@since		ver0002
*/
XMVECTOR *Camera::getCameraAt() {
	return this->at;
}
/*
*	Setter - Member variable "at".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "at".
*		- Target location which current Camera object is looking towards to.
*	@param		at			Camera target location coordinate
*							XMVECOTR pointer to set with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraAt(XMVECTOR *at) {
	this->at = at;
}

/*
*	Assign X, Y and Z coordinate value onto the
*		member variable "at" corresponding coordinate attributes.
*	<p>
*	This function assigns the X, Y and Z value passed as parameters,
*		onto the current Camera object's
*		member variable "at" corresponding coordinate attributes.
*		- Target location which current Camera object is looking towards to.
*	@param		x			Camera target location coordinate
*								X value to assign with.
*	@param		y			Camera target location coordinate
*								Y value to assign with.
*	@param		z			Camera target location coordinate
*								Z value to assign with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraAtXYZ(float x, float y, float z) {
	this->at->m128_f32[0] = x;
	this->at->m128_f32[1] = y;
	this->at->m128_f32[2] = z;
}

//=============================================================================
// Up - Camera orientation
//=============================================================================
/*
*	Getter - Member variable "up".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "up".
*		- Up vector of current Camera object for orientation.
*	@return		Return current Camera object's
*					member variable "up"
*					XMVECTOR pointer.
*	@see		XMVECTOR
*	@since		ver0002
*/
XMVECTOR *Camera::getCameraUp() {
	return this->up;
}

/*
*	Setter - Member variable "up".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "up".
*		- Up vector of current Camera object for orientation.
*	@param		up			Up vector of current Camera object
*							XMVECOTR pointer to set with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraUp(XMVECTOR *up) {
	this->up = up;
}

/*
*	Assign X, Y and Z coordinate value onto the
*		member variable "up" corresponding coordinate attributes.
*	<p>
*	This function assigns the X, Y and Z value passed as parameters,
*		onto the current Camera object's
*		member variable "up" corresponding coordinate attributes.
*		- Up vector of current Camera object for orientation.
*	@param		x			Camera target location coordinate
*								X value to assign with.
*	@param		y			Camera target location coordinate
*								Y value to assign with.
*	@param		z			Camera target location coordinate
*								Z value to assign with.
*	@return		void
*	@see		XMVECTOR
*	@since		ver0002
*/
void Camera::setCameraUpXYZ(float x, float y, float z) {
	this->up->m128_f32[0] = x;
	this->up->m128_f32[1] = y;
	this->up->m128_f32[2] = z;
}

//=============================================================================
// Camera data 
//=============================================================================
/*
*	Getter - Member variable "cameraViewMat".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "cameraViewMat",
*		which is going to be set to main constant buffer
*		in scene renderer for rendering.
*		- Camera view matrix to be set to
*		  main constant buffer for rendering.
*	@return		Return current Camera object's
*					member variable "cameraViewMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0002
*/
XMFLOAT4X4 *Camera::getCameraViewMat() {
	return this->cameraViewMat;
}

/*
*	Getter - Member variable "cameraProjMat".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "cameraProjMat",
*		which is going to be set to each rendering objects'
*		constant buffer for rendering.
*		- Camera projection matrix to be set to
*		  each rendering objects' constant buffer for rendering.
*	@return		Return current Camera object's
*					member variable "cameraProjMat"
*					XMFLOAT4X4 pointer.
*	@see		XMFLOAT4X4
*	@since		ver0002
*/
XMFLOAT4X4 *Camera::getCameraProjMat() {
	return this->cameraProjMat;
}

/*
*	Getter - Member variable "nearClipping".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "nearClipping",
*		- Near clipping distance to camera, to be used for projection.
*	@return		Return current Camera object's
*					member variable "nearClipping"
*					float value.
*	@since		ver0002
*/
float Camera::getNearClipping() {
	return this->nearClipping;
}

/*
*	Setter - Member variable "nearClipping".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "nearClipping".
*		- Near clipping distance to camera, to be used for projection.
*	@param		nearClipping		Near clipping float value to set with.
*	@return		void
*	@since		ver0002
*/
void Camera::setNearClipping(float nearClipping) {
	this->nearClipping = nearClipping;
}

/*
*	Getter - Member variable "farClipping".
*	<p>
*	This function is the getter for current Camera object's
*		member variable "farClipping",
*		- Far clipping distance to camera, to be used for projection.
*	@return		Return current Camera object's
*					member variable "farClipping"
*					float value.
*	@since		ver0002
*/
// Member variable "farClipping" related
float Camera::getFarClipping() {
	return this->farClipping;
}

/*
*	Setter - Member variable "farClipping".
*	<p>
*	This function is the setter for current Camera object's
*		member variable "farClipping".
*		- Far clipping distance to camera, to be used for projection.
*	@param		farClipping		Far clipping float value to set with.
*	@return		void
*	@since		ver0002
*/
void Camera::setFarClipping(float farClipping) {
	this->farClipping = farClipping;
}

//=============================================================================
// Transformation
//=============================================================================
/*
*	Move camera.
*	<p>
*	This function moves the camera position
*		with the amount of x, y and z values
*		onto corresponding coordinate axis
*		(Model is not moving with the camera for now).
*
*	@param		x		Amount incremented onto x axis.
*	@param		y		Amount incremented onto y axis.
*	@param		z		Amount incremented onto z axis.
*	@return		void
*	@since		ver0002
*/
void Camera::moveCameraXYZ(float x, float y, float z) {
	this->eye->m128_f32[0] += x;
	this->eye->m128_f32[1] += y;
	this->eye->m128_f32[2] += z;
	// Should update the model position whenever the eye position is changed.
	//this->cameraModel->setModelPostionXYZ(
	// m_commandList, this->eye->m128_f32[0], 
	// this->eye->m128_f32[1],
	// this->eye->m128_f32[2]);
}
