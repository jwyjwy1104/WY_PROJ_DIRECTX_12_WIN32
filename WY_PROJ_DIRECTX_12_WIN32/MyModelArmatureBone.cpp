
// File name: [MyModelArmatureBone.cpp] (Copyright to Samil Chai)
// Work Session #0184: 2017-07-13
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NmVicjNoYlVyc0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NmVicjNoYlVyc0k
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4X09jQnpYb3QzN1k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4X09jQnpYb3QzN1k
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4YXhTRWxfTUxBYnM%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4YXhTRWxfTUxBYnM
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds each bone's information loaded from a custom armature
//			file through ModelLoader.
// - [Commments]:
//		Diagrams added.
//		Inner documents implemented  using Javadoc.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0025
//------------------------------------------------------------------------------
// [rev0002:WY:201707131930]
//------------------------------------------------------------------------------
// File name: [MyModelArmatureBone.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram:
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds each bone's information loaded from a custom armature
//			file through ModelLoader.
// - [Commments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707012355]
//------------------------------------------------------------------------------
// File name: [MyModelArmatureBone.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds each bone's information loaded from a custom armature
//			file through ModelLoader.
// - [Commments]:
//	- Custom armature file.
//		- Array of bones:
//			- Bone name.
//			- Bone tail.
//			- Bone head.
//	- Above memeber variables added + get set member functions to access them.
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0000:WY:201706291900]
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
#include "MyModelArmatureBone.h"

// Default constructor
MyModelArmatureBone::MyModelArmatureBone() {
	// Name of the armature bone.
	this->armatureBoneName = new char[BUFSIZ]();
	std::fill(this->armatureBoneName, this->armatureBoneName + BUFSIZ, 0);

	// Line object for drawing the a line primitive onto the screen using 
	// DirectX 12 engine.
	this->line = new Line();
}

// General constructor.
MyModelArmatureBone::MyModelArmatureBone(
	char *armatureBoneName, 
	XMFLOAT3 boneTail, 
	XMFLOAT3 boneHead) {
	// Name of the armature bone.
	this->armatureBoneName = armatureBoneName;

	// Tail coordinate of the bone (Sharp part).
	this->boneTail = boneTail;
	// Head coordinate of the bone (Flat part).
	this->boneHead = boneHead;

	// Line object for drawing the a line primitive onto the screen using 
	// DirectX 12 engine.
	this->line = new Line(boneTail, boneHead);
}

// Destructor
MyModelArmatureBone::~MyModelArmatureBone() {
	// Name of the armature bone.
	if (this->armatureBoneName != NULL) {
		delete this->armatureBoneName;
		this->armatureBoneName = NULL;
	}

	// Line object for drawing the a line primitive onto the screen using 
	// DirectX 12 engine.
	if (this->line != NULL) {
		delete this->line;
		this->line = NULL;
	}
}

// Member variable "line" related
/*
*	Getter - Member variable "line".
*	<p>
*	This function is the getter for current MyModelArmatureBone object's
*		member variable "line".
*		- Line object that is holding all the resources buffer to render a line
*		  primitive.
*		  For here, is to draw a line between 2 points, bone's tail and head.
*	@return		Return current MyModelArmatureBone object's
*					member variable "line"
*					Line pointer.
*	@see		Line
*	@since		ver0025
*/
Line *MyModelArmatureBone::getBoneLine() {
	return this->line;
}

/*
*	Setter - Member variable "bonesArr".
*	<p>
*	This function is the setter for current MyModelArmatureBone object's
*		member variable "line".
*		- Line object that is holding all the resources buffer to render a line
*		  primitive.
*		  For here, is to draw a line between 2 points, bone's tail and head.
*	@param		line		Line object pointer to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmatureBone::setBoneLine(Line *line) {
	this->line = line;
}

/*
*	Getter - Member variable "armatureBoneName".
*	<p>
*	This function is the getter for current MyModelArmatureBone object's
*		member variable "armatureBoneName".
*		- Name of current MyModelArmatureBone object armature bone object 
*		  loaded from armature file.
*	@return		Return current MyModelArmatureBone object's
*					member variable "armatureBoneName"
*					string value.
*	@since		ver0025
*/
char *MyModelArmatureBone::getArmatureBoneName() {
	return this->armatureBoneName;
}

/*
*	Setter - Member variable "armatureBoneName".
*	<p>
*	This function is the setter for current MyModelArmatureBone object's
*		member variable "armatureBoneName".
*		- Name of current MyModelArmatureBone object armature bone object
*		  loaded from armature file.
*	@param		armatureBoneName		Bone name C-string value to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmatureBone::setArmatureBoneName(char *armatureBoneName) {
	strcpy(this->armatureBoneName, armatureBoneName);
}

//==============================================================================
// Bone coordinates.
//==============================================================================
/*
*	Getter - Member variable "boneTail".
*	<p>
*	This function is the getter for current MyModelArmatureBone object's
*		member variable "boneTail".
*		- Coordinate of the tail of current bone.
*	@return		Return current MyModelArmatureBone object's
*					member variable "boneTail"
*					XMFLOAT3 value.
*	@since		ver0025
*/
XMFLOAT3 MyModelArmatureBone::getBoneTail() {
	return this->boneTail;
}

/*
*	Setter - Member variable "boneTail".
*	<p>
*	This function is the setter for current MyModelArmatureBone object's
*		member variable "boneTail".
*		- Coordinate of the tail of current bone.
*===============================================================================
*	This function also sets the FIRST point of the Line object in current
*		MyModelArmatureBone object to be used for rendering.
*	So i can just call the initialize resource buffers function to be ready to
*		render the line primitive onto the screen.
*===============================================================================
*	@param		boneTail	Bone's tail coordinate XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmatureBone::setBoneTail(XMFLOAT3 boneTail) {
	this->line->setP1(boneTail);
	this->boneTail = boneTail;
}

// Member variable "boneHead" related
/*
*	Getter - Member variable "boneHead".
*	<p>
*	This function is the getter for current MyModelArmatureBone object's
*		member variable "boneHead".
*		- Coordinate of the head of current bone.
*	@return		Return current MyModelArmatureBone object's
*					member variable "boneHead"
*					XMFLOAT3 value.
*	@since		ver0025
*/
XMFLOAT3 MyModelArmatureBone::getBoneHead() {
	return this->boneHead;
}

/*
*	Setter - Member variable "boneHead".
*	<p>
*	This function is the setter for current MyModelArmatureBone object's
*		member variable "boneHead".
*		- Coordinate of the head of current bone.
*===============================================================================
*	This function also sets the SECOND point of the Line object in current
*		MyModelArmatureBone object to be used for rendering.
*	So i can just call the initialize resource buffers function to be ready to
*		render the line primitive onto the screen.
*===============================================================================
*	@param		boneTail	Bone's head coordinate XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmatureBone::setBoneHead(XMFLOAT3 boneHead) {
	this->line->setP2(boneHead);
	this->boneHead = boneHead;
}

/*
*	Utility function to print all information of current MyModelArmatureBone object
*		in following format:
*		[Bone: NAME] : Tail - (X,Y,Z) Head - (X,Y,Z).
*	<p>
*	This function prints all the data values and information being held by
*		current MyModelArmatureBone object, for debugging purpose.
*	@return		void.
*	@since		ver0025
*/
void MyModelArmatureBone::printBoneInfo() {
	_RPT1(0, "[Bone: %s] : Tail - (%f, %f, %f) Head - (%f, %f, %f)\n",
		this->armatureBoneName,
		this->boneTail.x, this->boneTail.y, this->boneTail.z,
		this->boneHead.x, this->boneHead.y, this->boneHead.z);
}
