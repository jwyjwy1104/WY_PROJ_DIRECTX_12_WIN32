// File name: [MyModelArmature.cpp] (Copyright to Samil Chai)
// Work Session #0183: 2017-07-13
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4dUpNbVRmSFNGdms%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4dUpNbVRmSFNGdms
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4d3hwMGhoSDQzdU0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4d3hwMGhoSDQzdU0
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4eFdlR0pEVjBIdjA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4eFdlR0pEVjBIdjA
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the bone's information being held in a model 
//			obj loaded from a custom armature file through ModelLoader.
//		- Custom armature file.
//			- Array of bones:
//			- Above memeber variables added + get set member functions to
//				access them.
//				- Bone name.
//				- Bone tail.
//				- Bone head.
// - [Commments]:
//		Inherited from MyModelObj class, so now i have to implement the 
//			constructors by adding ":MyModelObj()". Because there is only a
//			general constructor implemented on MyModelObj and ModelObj, so 
//			since not using any vertices and indices array here so the values
//			passed onto their constructor is not needed so is set with 0.
//		Inner comments implemented.
//		Diagrams added.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0025
//------------------------------------------------------------------------------
// [rev0002:WY:2017070131540]
//------------------------------------------------------------------------------
// File name: [MyModelArmature.cpp] (Copyright to Samil Chai)
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
//		This class holds all the bone's information being held in a model 
//			obj loaded from a custom armature file through ModelLoader.
//		- Custom armature file.
//			- Array of bones:
//			- Above memeber variables added + get set member functions to
//				access them.
//				- Bone name.
//				- Bone tail.
//				- Bone head.
// - [Commments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707012355]
//------------------------------------------------------------------------------
// File name: [MyModelArmature.cpp] (Copyright to Samil Chai)
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
// - [Description]
//		This class holds all the bone's information being held in a model 
//			obj loaded from a custom armature file through ModelLoader.
//		- Custom armature file.
//			- Array of bones:
//			- Above memeber variables added + get set member functions to
//				access them.
//				- Bone name.
//				- Bone tail.
//				- Bone head.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
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
#include "MyModelArmature.h"

// Default constructor
MyModelArmature::MyModelArmature() : MyModelObj(0,0,0,0) {
	// Maximum number of armature bones can be held by the 
	// main data structure "armatureBones".
	this->maxNumArmatureBones = MAX_NUM_BONES_PER_ARMATURE;

	// Main data structure to hold all the MyModelArmatureBone objects.
	this->armatureBones = new MyModelArmatureBone*[this->maxNumArmatureBones];
	for (int i = 0; i < this->maxNumArmatureBones; i++) {
		this->armatureBones[i] = NULL;
	}

	// Number of elements stored in the main data structure "armatureBones".
	this->numArmatureBones = 0;

	// Name of the armature indicated in the armature file.
	this->armatureName = "";
}

// General constructor
MyModelArmature::MyModelArmature(const int maxNumArmatureBones) : MyModelObj(0, 0, 0, 0) {
	// Maximum number of armature bones can be held by the 
	// main data structure "armatureBones".
	this->maxNumArmatureBones = maxNumArmatureBones;
	
	// Number of elements stored in the main data structure "armatureBones".
	this->numArmatureBones = 0;

	// Main data structure to hold all the MyModelArmatureBone objects.
	this->armatureBones = new MyModelArmatureBone*[this->maxNumArmatureBones];

	// Init main data structure "armatureBones".
	for (int i = 0; i < this->maxNumArmatureBones; i++) {
		//this->insertBone(new MyModelArmatureBone());
		this->getArmatureBones()[i] = new MyModelArmatureBone();
		this->numArmatureBones++;
	}

	// Name of the armature indicated in the armature file.
	this->armatureName = "";
}

// Destructor
MyModelArmature::~MyModelArmature() {
	// Release main data structure "armatureBones".
	for (int i = 0; i < this->maxNumArmatureBones; i++) {
		if (this->getArmatureBones()[i] != NULL) {
			delete this->getArmatureBones()[i];
		}
	}

	// Main data structure to hold all the MyModelArmatureBone objects.
	if (this->armatureBones != NULL) {
		delete[] this->armatureBones;
		this->armatureBones = NULL;
	}

	// Maximum number of armature bones can be held by the 
	// main data structure "armatureBones".
	this->maxNumArmatureBones = 0;
	// Number of elements stored in the main data structure "armatureBones".
	this->numArmatureBones = 0;
}

//==============================================================================
// Main data structure related.
//==============================================================================
/*
*	Getter - Member variable "armatureBones".
*	<p>
*	This function is the getter for current MyModelArmature object's
*		member variable "armatureBones".
*		- Main armature object data structure to hold all the 
*		  MyModelArmatureBone objects.
*	@return		Return current MyModelArmature object's
*					member variable "armatureBones"
*					MyModelArmatureBone pointer pointer.
*	@since		ver0025
*/
MyModelArmatureBone **MyModelArmature::getArmatureBones() {
	return this->armatureBones;
}
/*
*	Setter - Member variable "armatureBones".
*	<p>
*	This function is the setter for current MyModelArmature object's
*		member variable "armatureBones".
*		- Main armature object data structure to hold all the
*		  MyModelArmatureBone objects.
*	@param		armatureBones		Data structure MyModelArmatureBone 
*									pointer pointer
*									to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmature::setArmatureBones(MyModelArmatureBone **armatureBones) {
	this->armatureBones = armatureBones;
}

/*
*	Getter - Member variable "numArmatureBones".
*	<p>
*	This function is the getter for current MyModelArmature object's
*		member variable "numArmatureBones".
*		- Number of MyModelArmatureBone object elements stored in the main data 
*		  structure "armatureBones".
*	@return		Return current MyModelArmature object's
*					member variable "numArmatureBones" integer value.
*	@since		ver0025
*/
int MyModelArmature::getNumArmatureBones() {
	return this->numArmatureBones;
}
/*
*	Setter - Member variable "numArmatureBones".
*	<p>
*	This function is the setter for current MyModelArmature object's
*		member variable "numArmatureBones".
*		- Number of MyModelArmatureBone object elements stored in the main data
*		  structure "armatureBones".
*	@param		numArmatureBones		Number of bones to set with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmature::setNumArmatureBones(int numArmatureBones) {
	this->numArmatureBones = numArmatureBones;
}

/*
*	Getter - Member variable "maxNumArmatureBones".
*	<p>
*	This function is the getter for current MyModelArmature object's
*		member variable "maxNumArmatureBones".
*		- Maximum number of armature bones can be held by the main data 
*		  structure "armatureBones".
*	@return		Return current MyModelArmature object's
*					member variable "maxNumArmatureBones" integer value.
*	@since		ver0025
*/
int MyModelArmature::getMaxNumArmatureBones() {
	return this->maxNumArmatureBones;
}

//==========================================================================
// Main data structure operations related.
//==========================================================================
/*
*	Insert the MyModelArmatureBone object passed in as parameter to the main
*	data structure "armatureBones".
*	<p>
*	This function inserts the new MyModelArmatureBone object to 
*		current MyModelArmature object's data structure "armatureBones".
*	It is an array based queue type data structure, FIFO LIFO.
*		so the new MyModelArmatureBone object inserts to the index 
*		of the current element count.
*	@param		armatureBoneToInsert	MyModelArmatureBone object pointer 
*										to insert with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmature::insertArmatureBone(
	MyModelArmatureBone *armatureBoneToInsert) {
	// Append the armature bone to the end of the main data structure.
	if (armatureBoneToInsert != NULL) {
		this->armatureBones[this->numArmatureBones] = armatureBoneToInsert;
		this->numArmatureBones++;
	}
}
/*
*	Remove the matching MyModelArmatureBone object pointer passed in as 
*		parameter in the main data structure "armatureBones".
*	<p>
*	This function removes the MyModelArmatureBone object pointer given as 
*		parameter, search for the matching pointer and remove from 
*		current MyModelArmature object's main data structure "armatureBones" 
*		then decrements the element counter "numArmatureBones".
*	It is an array based queue type data structure, so if the deletion occurs
*		in the middle, all the rest of the elements must shifts to the front.
*	@param		armatureBoneToRemove	MyModelArmatureBone object 
*										to delete with.
*	@return		void
*	@since		ver0025
*/
void MyModelArmature::removeArmatureBone(MyModelArmatureBone *armatureBoneToRemove) {
	if (armatureBoneToRemove != NULL) {
		// Search for the deleting object in the data structure "armatureBones".
		for (int i = 0; i < this->numArmatureBones; i++) {
			if (this->armatureBones[i] == armatureBoneToRemove) { // If matches
				delete this->armatureBones[i]; // Delete 
				this->armatureBones[i] = NULL; // Reset

				// Shift if deletion occured in the middle
				for (int j = i; j < this->numArmatureBones; j++) {
					this->armatureBones[j] = this->armatureBones[j + 1];
				}
				// Done
				break;
			}
		}
		// Decrement counter.
		this->numArmatureBones--;
	}
}

/*
*	Remove all the MyModelArmatureBone objects exist in the main data 
*		structure "armatureBones".
*	<p>
*	This function removes all the MyModelArmatureBone objects exists in the 
*		main data structure "armatureBones"
*		then decrements the resets the element counter to 0.
*	@return		void
*	@since		ver0025
*/
void MyModelArmature::removeAllArmatureBones() {
	// Loop throuhg the data structure to delete all.
	for (int i = 0; i < this->numArmatureBones; i++) {
		// Delete if valid.
		if (this->armatureBones[i] != NULL) {
			delete this->armatureBones[i];
			this->armatureBones[i] = NULL;
		}
	}
	// Reset counter.
	this->numArmatureBones = 0;
}
/*
*	Get MyModelArmatureBone object pointer valid on given index inside the main 
*		data structure "armatureBones".
*	<p>
*	This function retrieves the MyModelArmatureBone object pointer on given 
*		index inside the main data strcuture "armatureBones".
*	@return		MyModelArmatureBone pointer on given index if exist, 
*					else return NULL.
*	@since		ver0025
*/
MyModelArmatureBone *MyModelArmature::getArmatureBoneAtIndex(int index) {
	if (this->armatureBones[index] != NULL) {
		return this->armatureBones[index];
	}
	return NULL;
}

/*
*	Get MyModelArmatureBone object pointer found inside the main
*		data structure "armatureBones" matching the name given as a paramter.
*	<p>
*	This function retrieves the MyModelArmatureBone object pointer found
*		inside the main data strcuture "armatureBones" by comparing the 
*		the name passed in as a parameter.
*	@return		MyModelArmatureBone pointer if found with given name,
*					else return NULL.
*	@since		ver0025
*/
MyModelArmatureBone *MyModelArmature::getArmatureBoneWithName(std::string name) {
	for (int i = 0; i < this->numArmatureBones; i++) {
		if (this->armatureBones[i]->getArmatureBoneName() == name) {
			return this->armatureBones[i];
		}
	}
	_RPT1(0, "################################################################################\n", 0);
	_RPT1(0, "ERROR::MyModelArmature::getArmatureBoneWithName::Could not get the armature bone with given name : %s\n", name);
	_RPT1(0, "################################################################################\n", 0);
	return NULL;
}
/*
*	Utility function to print all the elements stored in the main data structure 
*		"armatureBones".
*	<p>
*	This function prints all the MyModelArmatureBone objects information stored 
*		in the main MyModelArmature object's main data strcuture "armatureBones"  
*		by calling each MyModelArmatureBone object's printBoneInfo() function.
*	@return		void.
*	@since		ver0025
*/
void MyModelArmature::printArmatureBonesInfos() {
	for (int i = 0; i < this->numArmatureBones; i++) {
		// Print bone's information if exist 
		if (this->armatureBones[i] != NULL) { 
			this->armatureBones[i]->printBoneInfo();
		}
	}
}



