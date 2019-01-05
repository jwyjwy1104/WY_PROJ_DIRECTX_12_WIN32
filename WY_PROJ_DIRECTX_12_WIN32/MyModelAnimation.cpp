// File name: [MyModelAnimation.cpp] (Copyright to Samil Chai)
// Work Session #0196: 2017-08-28
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NFlMelBVUkdTZ0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NFlMelBVUkdTZ0k
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4YjlmWEJxWlg3U3c%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4YjlmWEJxWlg3U3c
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4WVBNZXlBcUxUMlk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WVBNZXlBcUxUMlk
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class represents a single animation file.
//		This class holds the animation data to be rendered on DirectX 12 engine
//			to apply the animation onto the armature models.
//		This will be held by each MyModeArmature object and will hold every 
//			MyModelAnimationBone objects for having each collection of animation 
//			frame data MyModelAnimationBoneData objects inside.
//		Main purpose is to apply animation onto a MyModelArmature object.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each collection of animation 
//				frame data MyModelAnimationBoneData objects which is 
//				the collection of animation frame data values to be used to 
//				apply animation onto each armature bones on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the data values inside each MyModelAnimationBoneData
//				object over time frame to apply the animation onto each 
//				corresponding MyModelArmatureBone objects for animation.
//		The animation file exporting format is adjusted as follows:
//			Summary document: https://docs.google.com/document/d/1yXmmCSx_2r5GVpoty6Y1P1KIiSH8nzz7cffsHfHxTzo/edit#bookmark=kix.gxpvfxacvl9r
//			Custom exported animation file:
//				count - Number of pose bones i want to export the animation 
//						data with.
//				CU - Exported coordinate system option UP vector.
//				CF - Exported coordinate system option FORWARD vector.
//					bn - Current animation bone to export animation data with.
//					Animation data to be held by each animaiton bone object:
//						bt - Current animation frame bone tail coordinate.
//						bh - Current animation frame bone head coordinate.
//						<> - Current animation frame bone world matrix. 
//						tra - Current animation frame bone translation vector. 
//						rot - Current animation frame bone rotation quaternion. 
//						sca - Current animation frame bone scaling vector. 
// - [Commments]:
//		The main data structure to hold the MyModelAnimationBone objects is 
//		changed from array type ot std::vector type, because std::vector is 
//		more standard and safe to use then the manually implemented array or
//		data structure classes.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0041
//------------------------------------------------------------------------------
// [rev0002:WY:201708281750]
//------------------------------------------------------------------------------
// File name: [MyModelAnimation.cpp] (Copyright to Samil Chai)
// Work Session #0188: 2017-07-18
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NFlMelBVUkdTZ0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NFlMelBVUkdTZ0k
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4YjlmWEJxWlg3U3c%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4YjlmWEJxWlg3U3c
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4WVBNZXlBcUxUMlk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WVBNZXlBcUxUMlk
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class represents a single animation file.
//		This class holds the animation data to be rendered on DirectX 12 engine
//		Will be held by each MyModeArmature object and will hold every 
//			MyModelAnimationBone objects for having each animation queue inside.
//		Main purpose is to manage multiple bones inside an armature for applying
//			animations.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each animation queue which is 
//				the array type of XMFLOAT4X4 values on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the XMFLOAT4X4 values onto each MyModelArmatureBone's
//				update its CBV to apply the animation.
// - [Commments]:
//		Inner comments with Javadoc added + 80 characters per line code 
//			+ UML, UC and SD diagrams adjusted.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0037
//------------------------------------------------------------------------------
// [rev0001:WY:201707252350]
//------------------------------------------------------------------------------
// File name: [MyModelAnimation.cpp] (Copyright to Samil Chai)
// Work Session #0188: 2017-07-18
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NFlMelBVUkdTZ0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NFlMelBVUkdTZ0k
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4YjlmWEJxWlg3U3c%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4YjlmWEJxWlg3U3c
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4WVBNZXlBcUxUMlk%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4WVBNZXlBcUxUMlk
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Description]:
//		This class represents a single animation file.
//		This class holds the animation data to be rendered on DirectX 12 engine
//		Will be held by each MyModeArmature object and will hold every 
//			MyModelAnimationBone objects for having each animation queue inside.
//		Main purpose is to manage multiple bones inside an armature for applying
//			animations.
// - [Framework]
//		MyModelArmature - Multiple MyModelArmatureBone objects
//		MyModelAnimation - Multiple MyModelAnimationBone objects
//		Load animation file onto MyModelAnimation object 
//			--> MyModelAnimationBone is holding each animation queue which is 
//				the array type of XMFLOAT4X4 values on each frame 
//				where maximum frame is 250 according to the Blender engine 
//				scene's end frame = 250.
//			--> Then use the XMFLOAT4X4 values onto each MyModelArmatureBone's
//				update its CBV to apply the animation.
// - [Commments]:
//		Basic methods implemented
//		This class object will be held by a single MyModelBone object, where 
//			this object will be holding XMFLOAT4X4 constant buffer data value 
//			for each frames to be updated for animation.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0000:WY:201707171600]
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
#include "Queue.h"
#include "MyModelArmature.h"
#include "MyModelAnimation.h"

MyModelAnimation::MyModelAnimation() : MyModelObj(0, 0, 0, 0) {
	// Init main data structure to hold all the MyModelAnimationBone objects.
	this->animationBones = new vector<MyModelAnimationBone *>();

	// Name of the animation indicated in the animation file.
	this->animationName = "";

	// Current MyModelArmature object appying "this" animation to.
	this->currentArmature = NULL;
}
MyModelAnimation::~MyModelAnimation() {
	// Release main data structure to hold all the MyModelAnimationBone objects.
	if (this->animationBones != NULL) {
		delete [] this->animationBones;
		this->animationBones = NULL;
	}
	// Name of the animation indicated in the animation file.
	this->animationName = "";
	// Current MyModelArmature object appying "this" animation to.
	if (this->currentArmature != NULL) {
		//delete this->currentArmature; // Might double delete?
		this->currentArmature = NULL;
	}
}

//==============================================================================
// Main data structure related.
//==============================================================================
/*
*	Getter - Member variable "animationBones".
*	<p>
*	This function is the getter for current MyModelAnimation object's
*		member variable "animationBones".
*		- Main animation object data structure to hold all the
*		  MyModelAnimationBone objects.
*	@return		Return current MyModelAnimation object's
*					member variable "animationBones"
*					vector<MyModelAnimationBone> pointer.
*	@see		std::vector
*	@since		ver0041
*/
vector<MyModelAnimationBone *> *MyModelAnimation::getAnimationBones() {
	return this->animationBones;
}
/*
*	Setter - Member variable "animationBones".
*	<p>
*	This function is the getter for current MyModelAnimation object's
*		member variable "animationBones".
*		- Main animation object data structure to hold all the
*		  MyModelAnimationBone objects.
*	@param		animationBones		Data structure vector<MyModelAnimationBone>
*									to set with.
*	@return		void
*	@see		std::vector
*	@since		ver0041
*/
void MyModelAnimation::setAnimationBones(vector<MyModelAnimationBone *> *animationBones) {
	this->animationBones = animationBones;
}

/*
*	Getter - Member variable "numAnimationBones".
*	<p>
*	This function is the getter for current MyModelAnimation object's
*		member variable "numAnimationBones".
*		- Number of MyModelAnimationBone object elements stored in the main data
*		  structure "animationBones".
*	@return		Return current MyModelAnimation object's
*					member variable "numAnimationBones" integer value.
*	@see		std::vector::size()
*	@since		ver0041
*/
int MyModelAnimation::getNumAnimationBones() {
	return this->animationBones->size();
}

//==============================================================================
// Main data structure operations related.
//==============================================================================
/*
*	Insert the MyModelAnimationBone object passed in as parameter to the main
*	data structure "armatureBones".
*	<p>
*	This function inserts the new MyModelAnimationBone object to
*		current MyModelAnimation object's data structure "animationBones".
*	It is an std::vector type data structure, so i can simply call the 
*		push_back() function in std::vector to insert the MyModelAnimationBone
*		object to the main data structure.
*	@param		animationBoneToInsert	MyModelAnimationBone object pointer
*										to insert with.
*	@return		void
*	@see		std::vector::push_back()
*	@since		ver0041
*/
void MyModelAnimation::insertAnimationBone(
	MyModelAnimationBone *animationBoneToInsert) {
	// Insert the animation bone to the main data structure.
	this->animationBones->push_back(animationBoneToInsert);
}

/*
*	Remove the matching MyModelAnimationBone object pointer passed in as
*		parameter in the main data structure "animationBones".
*	<p>
*	This function removes the MyModelAnimationBone object pointer given as
*		parameter, search for the matching pointer and remove from
*		current MyModelAnimation object's main data structure "animationBones"
*		, this can be done by calling the erase() function in std::vector.
*	@param		animationBoneToRemove	MyModelAnimationBone object
*										to delete with.
*	@return		void
*	@see		std::vector::erase()
*	@since		ver0041
*/
bool MyModelAnimation::removeAnimationBone(MyModelAnimationBone *animationBoneToRemove) {
	// Loop through the data structure to find the animation bone to remove.
	for (int i = 0; i < this->animationBones->size(); i++) {
		// If found element to delete.
		if (this->animationBones->at(i) == animationBoneToRemove) {
			this->animationBones->erase(this->animationBones->begin() + i);
			return true;
		}
	}
	_RPT1(0, "################################################################################\n", 0);
	_RPT1(0, "ERROR::MyModelAnimationBone::remove::Could not remove the animation bone\n", 0);
	_RPT1(0, "################################################################################\n", 0);
	return false;
}

/*
*	Remove all the MyModelAnimationBone objects exist in the main data
*		structure "animationBones".
*	<p>
*	This function removes all the MyModelAnimationBone objects exist in the
*		main data structure "animationBones", this can be done by calling the 
*		clear() function in std::vector.
*	@return		void
*	@see		std::vector::clear()
*	@since		ver0041
*/
void MyModelAnimation::removeAllAnimationBones() {
	this->animationBones->clear();
}
/*
*	Get MyModelAnimationBone object pointer valid on given index inside the main
*		data structure "animationBones".
*	<p>
*	This function retrieves the MyModelAnimationBone object pointer on given
*		index inside the main data strcuture "animationBones", this can be done 
*		by calling the at() function in std::vector.
*	@return		MyModelAnimationBone pointer on given index if exist,
*					else return NULL.
*	@see		std::vector::at()
*	@since		ver0041
*/
MyModelAnimationBone *MyModelAnimation::getAnimationBoneAtIndex(int index) {
	return this->animationBones->at(index);
}

/*
*	Get MyModelAnimationBone object pointer found inside the main
*		data structure "animationBones" matching the name given as a paramter.
*	<p>
*	This function retrieves the MyModelAnimationBone object pointer found
*		inside the main data strcuture "animationBones" by comparing the
*		the name passed in as a parameter.
*	@return		MyModelAnimationBone pointer if found with given name,
*					else return NULL.
*	@see		std::vector
*	@since		ver0041
*/
MyModelAnimationBone *MyModelAnimation::getAnimBoneWithName(std::string name) {
	for (int i = 0; i < this->animationBones->size(); i++) {
		if (this->animationBones->at(i)->getAnimationBoneName() == name) {
			return this->animationBones->at(i);
		}
	}
	_RPT1(0, "################################################################################\n", 0);
	_RPT1(0, "ERROR::MyModelAnimationBone::getAnimBoneWithName::Could not get the animation bone with given name : %s\n", name);
	_RPT1(0, "################################################################################\n", 0);
	return NULL;
}


