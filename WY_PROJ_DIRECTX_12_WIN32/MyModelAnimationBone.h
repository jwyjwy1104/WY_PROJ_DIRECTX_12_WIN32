#pragma once

#include <iostream>
#include <vector>

#include "Queue.h"
#include "MyModelArmatureBone.h"
#include "MyModelAnimationBoneData.h"

// Class description: 
//		This class represents an animation bone object imported from 
//		the custom animation file exported from a custom Blender Python script
//		exported through Blender 3D engine.
//			Is being held by a single MyModelAnimation object to apply the 
//			animation in one place by comparing each animation bone names to
//			animate the matching armature bones.
class MyModelAnimationBone {
private:
	// Main data structure to hold the imported array of XMFLOAT4X4 animation 
	// data as a Queue type data structure. 
	// (See Queue.h template class for more)
	std::vector<MyModelAnimationBoneData *> *animationFrames;

	// Name of the animation bone.
	char *animationBoneName;

	// Current MyModelArmatureBone object pointer to assign current animation 
	// data with, for rendering the animation of the armature.
	MyModelArmatureBone *currentArmatureBone;
public:
	// Default constructor.
	MyModelAnimationBone();

	// General constructor 1.
	MyModelAnimationBone(
		MyModelArmatureBone *currentArmatureBone, 
		char *animationBoneName);

	// Destructor.
	~MyModelAnimationBone();

	// Member variable "animationBoneName" getter.
	char *getAnimationBoneName();
	// Member variable "animationBoneName" setter.
	void setAnimationBoneName(char *animationBoneName);

	// Member variable "currentArmatureBone" getter.
	MyModelArmatureBone *getCurrentArmatureBone();
	// Member variable "currentArmatureBone" setter.
	void setCurrentArmatureBone(MyModelArmatureBone *currentArmatureBone);

	// Member variable "animationFrames" getter.
	std::vector<MyModelAnimationBoneData *> *getAnimationFrames();
	// Member variable "animationFrames" setter.
	void setAnimationFrames(vector<MyModelAnimationBoneData *> *animationFrames);

	// Member variable "numAnimationFrames" getter.
	int getMaxNumAnimationFrames();
	// Member variable "maxNumAnimationFrames" getter.
	int getNumAnimationFrames();

	//==========================================================================
	// Main data structure operations related.
	//==========================================================================
	// Insert the animation frame data "animationFrameToInsert" to the 
	// main std::vector type data structure "animationFrames".
	void insertAnimationFrameData(MyModelAnimationBoneData *animationFrameToInsert);

	// Remove all the animation frame data inserted in the main data structure 
	// "animationFrames" by dequeuing all the elements inside.
	void removeAllAnimationFrameData();

	// Retrieve the MyModelAnimationBoneData pointer data value on given index 
	// of the main data structure "animationFrames".
	MyModelAnimationBoneData *getAnimationFrameAtIndex(int index);
};

