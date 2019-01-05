#pragma once

#include "MyModelObj.h"
#include "MyModelArmatureBone.h"

// Class description: 
//		This class represents an armature object imported from 
//		the custom armature file exported from a custom Blender Python script
//		exported through Blender 3D engine.
//			Holds multiple MyModelArmatureBone objects to render the 
//			each armatures bones onto the screen.
//
//		This class is also inherited from the class MyModelObj
//		to use the coordinate system UP and FORWARD vector tag values indicated 
//		in the custom exported file to convert the coordinate system 
//		from Blender to DirectX 12 to properly import and render the armature 
//		bones' coordinate system by converting the coordinate values while 
//		loading using the boolean properties inside MyModelObj class.
class MyModelArmature : MyModelObj {
private:
	// Main data structure to hold the imported array of MyModelArmatureBone 
	// objects as a array type data structure. 
	MyModelArmatureBone **armatureBones;

	// Number of elements stored in the main data structure "armatureBones".
	int numArmatureBones;

	// Maximum number of armature bones can be held by the 
	// main data structure "armatureBones".
	int maxNumArmatureBones;

	// Name of the armature indicated in the armature file.
	char *armatureName;
public:
	// Default constructor.
	MyModelArmature();

	// General constructor.
	MyModelArmature(const int maxNumArmatureBones);

	// Destructor.
	~MyModelArmature();

	//==========================================================================
	// Main data structure related.
	//==========================================================================
	// Member variable "armatureBones" getter.
	MyModelArmatureBone **getArmatureBones();
	// Member variable "armatureBones" setter.
	void setArmatureBones(MyModelArmatureBone **armatureBones);

	// Member variable "numArmatureBones" getter.
	int getNumArmatureBones();
	// Member variable "numArmatureBones" setter.
	void setNumArmatureBones(int numArmatureBones);

	// Member variable "maxArmatureBones" getter.
	int getMaxNumArmatureBones();

	//==========================================================================
	// Main data structure operations related.
	//==========================================================================
	// Insert the armature bone to the main data structure "armatureBones".
	void insertArmatureBone(MyModelArmatureBone *armatureBoneToInsert);
	// Remove the armature bone found in the main data structure 
	// "armatureBones".
	void removeArmatureBone(MyModelArmatureBone *armatureBoneToRemove);
	// Remove all the armature bone found in the main data structure 
	// "armatureBones".
	void removeAllArmatureBones();
	// Retrieve the MyModelArmatureBone pointer on given index of the main 
	// data structure "armatureBones".
	MyModelArmatureBone *getArmatureBoneAtIndex(int index);
	// Retrieve the MyModelArmatureBone pointer with the name 
	// found on the main data structure "armatureBones". 
	MyModelArmatureBone *getArmatureBoneWithName(std::string name);

	// Print all the MyModelArmatureBone object's data value
	// currently stored in the main data structure "armatureBones".
	void printArmatureBonesInfos();
};