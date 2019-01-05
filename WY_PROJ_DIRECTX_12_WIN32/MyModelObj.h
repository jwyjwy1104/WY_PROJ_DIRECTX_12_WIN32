#pragma once

#include "ModelObj.h"

// Class description: 
//		This class represents a custom exported WYM file exported through the 
//		Blender Python script called blenderExporter.blend, which holds all the 
//		information as a model object but instead in my OWN format.
//		(Not like standard OBJ).
//		========================================================================
//		WYO : Custom exported model file exported through my custom model
//			 exporter Blender Python script through Blender.
//		========================================================================
//		This class is inherited from the class ModelObj, so the default
//		standard OBJ properties can also be accessed in this class, save the  
//		time to implement the similar methods and codes
//		(eg. Data structure to hold vertices, texture coordinates, ... etc).
class MyModelObj : ModelObj {
public:
	//==========================================================================
	// Coordinate system UP vector flags used to determine which UP vector is 
	// indicated in the custom exported WYO file as "CU" element.
	//==========================================================================
	bool coordoption_X_up = false;				//  X up
	bool coordoption_minus_X_up = false;		// -X up
	bool coordoption_Y_up = false;				//  Y up
	bool coordoption_minus_Y_up = false;		// -Y up
	bool coordoption_Z_up = false;				//  Z up
	bool coordoption_minus_Z_up = false;		// -Z up

	//==========================================================================
	// Coordinate system FORWARD vector flags used to determine which FORWARD
	//  vector is indicated in the custom exported WYO file as "CF" element.
	//==========================================================================
	bool coordoption_X_forward = false;			//  X forward
	bool coordoption_minus_X_forward = false;	// -X forward
	bool coordoption_Y_forward = false;			//  Y forward
	bool coordoption_minus_Y_forward = false;	// -Y forward
	bool coordoption_Z_forward = false;			//  Z forward
	bool coordoption_minus_Z_forward = false;	// -Z forward

	// CU - Coordinate system UP vector string value.
	char *coordoption_up_str = "";
	// CF - Coordinate system FORWARD vector string value.
	char *coordoption_forward_str = "";

public:
	// General constructor
	MyModelObj(
		int vertexCount,	// Number of "v" element in standard OBJ file.
		int textureCount,	// Number of "vt" element in standard OBJ file.
		int normalCount,	// Number of "vn" element in standard OBJ file.
		int faceCount);		// Number of "f" element in standard OBJ file.

	// Destructor
	~MyModelObj();

	//==========================================================================
	// Coordinate system UP vector (CU)
	//==========================================================================
	// Member variable "coordoption_up_str" getter.
	char *get_coordoption_up_str();
	// Member variable "coordoption_up_str" setter.
	void set_coordoption_up_str(char *coordoption_up_str);

	//==========================================================================
	// Coordinate system FORWARD vector (CF)
	//==========================================================================
	// Member variable "coordoption_forward_str" getter.
	char *get_coordoption_forward_str();
	// Member variable "coordoption_forward_str" setter.
	void set_coordoption_forward_str(char *coordoption_forward_str);
};
