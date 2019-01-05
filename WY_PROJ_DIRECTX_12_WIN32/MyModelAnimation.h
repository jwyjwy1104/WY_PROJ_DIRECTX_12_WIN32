#pragma once

#include "MyModelArmature.h"
#include "MyModelAnimationBone.h"

// Class description: 
//		This class represents an animation file imported from 
//		the custom animation file exported from a custom Blender Python script
//		exported through Blender 3D engine.
//			Holds multiple MyModelAnimationBone objects to animate the 
//			corresponding armatures by applying the animation frame data onto  
//			the armature bones over time frames.
//		========================================================================
//		WANIM : Custom exported animation file exported through my custom 
//				animation exporter Blender Python script through Blender.
//		========================================================================
class MyModelAnimation : MyModelObj {
private:
	// Main data structure to hold all the MyModelAnimationBone objects.
	std::vector<MyModelAnimationBone *> *animationBones;
	
	// Name of the animation indicated in the animation file.
	char *animationName;

	// Current MyModelArmature object appying "this" animation to.
	MyModelArmature *currentArmature;
public:
	// Default constructor.
	MyModelAnimation();

	// Destructor.
	~MyModelAnimation();

	//==========================================================================
	// Main data structure related.
	//==========================================================================
	// Member variable "animationBones" getter.
	std::vector<MyModelAnimationBone *> *getAnimationBones();
	// Member variable "animationBones" setter.
	void setAnimationBones(vector<MyModelAnimationBone *> *animationBones);

	// Member variable "animationBones" size getter.
	int getNumAnimationBones();

	// Member variable "maxNumAnimationBones" getter.
	int getMaxNumAnimationBones();

	//==========================================================================
	// Main data structure operations related.
	//==========================================================================
	// Insert the animation bone to the main data structure "animationBones".
	void insertAnimationBone(MyModelAnimationBone *animationBoneToInsert);
	// Remove the animation bone found in the main data structure 
	// "animationBones".
	bool removeAnimationBone(MyModelAnimationBone *animationBoneToRemove);
	// Remove all the animation bone found in the main data structure 
	// "animationBones".
	void removeAllAnimationBones();
	// Retrieve the MyModelAnimationBone pointer on given index of the main 
	// data structure "animationBones".
	MyModelAnimationBone *getAnimationBoneAtIndex(int index);

	// Retrieve the MyModelAnimationBone pointer with the name 
	// found on the main data structure "animationBones". 
	MyModelAnimationBone *getAnimBoneWithName(std::string name);

};

