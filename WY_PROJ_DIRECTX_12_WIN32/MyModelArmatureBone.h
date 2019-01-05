#pragma once

#include "Line.h"

// Class description: 
//		This class represents an armature bone object imported from 
//		the custom armature file exported from a custom Blender Python script
//		exported through Blender 3D engine.
//			Is being held by a single MyModelArmature object to mange the 
//			armature bones in one place.
class MyModelArmatureBone {
private:
	// Line object for drawing the a line primitive onto the screen using 
	// DirectX 12 engine.
	Line *line;

	// Name of the armature bone.
	char *armatureBoneName;

	// Tail coordinate of the bone (Sharp part).
	DirectX::XMFLOAT3 boneTail;
	// Head coordinate of the bone (Flat part).
	DirectX::XMFLOAT3 boneHead;

public:
	// Default constructor.
	MyModelArmatureBone();

	// General constructor.
	MyModelArmatureBone(
		char *armatureBoneName,
		DirectX::XMFLOAT3 boneTail,
		DirectX::XMFLOAT3 boneHead);

	// Destructor.
	~MyModelArmatureBone();

	// Member variable "line" getter.
	Line *getBoneLine();
	// Member variable "line" setter.
	void setBoneLine(Line *line);

	// Member variable "armatureBoneName" getter.
	char *getArmatureBoneName();
	// Member variable "armatureBoneName" setter.
	void setArmatureBoneName(char *armatureBoneName);

	//==========================================================================
	// Bone coordinates.
	//==========================================================================
	// Member variable "boneTail" getter.
	DirectX::XMFLOAT3 getBoneTail();
	// Member variable "boneTail" setter.
	void setBoneTail(DirectX::XMFLOAT3 boneTail);

	// Member variable "boneHead" getter.
	DirectX::XMFLOAT3 getBoneHead();
	// Member variable "boneHead" setter.
	void setBoneHead(DirectX::XMFLOAT3 boneHead);

	// Print bone's information name, tail cooridnates and head coordinates.
	void printBoneInfo();
};
