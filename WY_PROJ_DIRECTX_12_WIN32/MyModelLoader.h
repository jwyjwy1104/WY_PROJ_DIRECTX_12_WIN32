#pragma once

#include "Util.h"
#include "MySpecialModelObjMtl.h"
#include "ModelObj.h"
#include "MyModelObj.h"
#include "ModelMtl.h"
#include "MyModelMtl.h"
#include "MyModelArmature.h"
#include "MyModelArmatureBone.h"
#include "MyModelAnimation.h"
#include "MyModelAnimationBone.h"

// Class description: 
//		This class represent a loading manager which holds all the loading 
//		mechanisms to load multiple different files to manage all the models, 
//		materials, fonts, armatures and animations.
//			
//		Holds loading mechanisms for following files:
//		========================================================================
//		OBJ: Standard OBJ file exported through other 3D engine like Blender as
//				default ".obj" extension.
//		========================================================================
//		MTL : Standard MTL file exported through other 3D engine like Blender as
//				default ".mtl" extension where it is automatically generated
//				whenever OBJ file is exported.
//		========================================================================
//		WYO : Custom exported model file exported through my custom model
//			 exporter Blender Python script through Blender.
//		========================================================================
//		WYM : Custom exported material file exported through my custom material
//			 exporter Blender Python script through Blender.
//		========================================================================
//		ARM: Custom exported armature file exported through my custom armature
//			 exporter Blender Python script through Blender.
//		========================================================================
//		ANM: Custom exported animation file exported through my custom animation
//			 exporter Blender Python script through Blender.
//		========================================================================
class MyModelLoader {
private:
	// Util object for extra features. 
	// (eg. Load font, Load texture image, get image width height, file check)
	Util *modelLoaderUtils;

public:
	// Default constructor
	MyModelLoader();
	// Destructor
	~MyModelLoader();

	// Load either standard or custom model and material file by giving the 
	// model file path, and returns the initialized MySpecialModelObjMtl object
	// pointer with all the information loaded from files stored in it, to be
	// used for rendering a model on DirectX 12 engine.
	MySpecialModelObjMtl *myObjMtlLoader(const char *objFilePath);

	// Using OBJ file path to retrieve current directory path 
	// and use the MTL file name to combine together to get the MTL file 
	// absolute path. 
	// eg. C:\User\Desktop\mode.obj 
	//		--> mtllib: model.mtl 
	//		--> C:\User\Desktop\ + model.mtl
	char *getMtlFilePathUsingObjFilePathAndMtlFileName(
		const char *objFilePath,
		char *mtlFileName);

	//==========================================================================
	// Standard importer 
	// (Standard OBJ exported through Blender --> DirectX 12).
	//==========================================================================
	// Standard OBJ loader
	ModelObj *stdObjLoader(char *stdObjFilePath);
	// Standard MTL loader
	ModelMtl *stdMtlLoader(char *stdMtlFilePath);

	//==========================================================================
	// Custom importer 
	// (Custom WYO exported through Blender Python --> DirectX 12).
	//==========================================================================
	// Custom WYO loader
	MyModelObj *myObjLoader(char *myObjFilePath);
	// Custom WYM loader
	MyModelMtl *myMtlLoader(char *myMtlFilePath);

	// Custom armature loader
	MyModelArmature *myArmatureLoader(char *myArmatureFilePath);

	// Custom animation loader
	MyModelAnimation *myAnimationLoader(char *myAnimationFilePath);

	//==========================================================================
	// Helper function to read the element counts to create the data structure 
	// before storing the values in from the model files.
	// (Working for both standard OBJ and custom exported WYO file)
	// 
	// Returns true if the integer variable address passed in as parameter 
	// is initialized properly using the element count indicated in the 
	// model file. Else false.
	//
	// Code originally brought from - RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html 
	//  
	// OBJ - stdObjLoader()--> ReadFileCounts()--> LoadDataStructuresModelObj()
	// WYO - myObjLoader()--> ReadFileCounts()--> LoadDataStructuresMyModelObj()
	//==========================================================================
	bool ReadFileCounts(
		char* filename,
		int& vertexCount,
		int& textureCount,
		int& normalCount,
		int& faceCount);

	//==========================================================================
	// Helper function to store the values into the data structure initialized 
	// in the ModelObj object from the model files.
	// (Working for both standard OBJ file only)
	//
	// Returns true if the model file opened success and the data structure 
	// initialzied in the ModelObj object pointer passed in as parameter is 
	// initialized properly with the element values loaded from the model file.
	// Else false.
	//
	// Code originally brought from - RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html 
	// 
	// OBJ - stdObjLoader()--> ReadFileCounts()--> LoadDataStructuresModelObj()
	//==========================================================================
	bool LoadDataStructuresModelObj(
		ModelObj *mainModel,
		char* filename,
		int vertexCount,
		int textureCount,
		int normalCount,
		int faceCount);
	//==========================================================================
	// Helper function to store the values into the data structure initialized 
	// in the MyModelObj object from the model files.
	// (Working for both custom exported WYO file only)
	//
	// Returns true if the model file opened success and the data structure 
	// initialzied in the MyModelObj object pointer passed in as parameter is 
	// initialized properly with the element values loaded from the model file.
	// Else false.
	//
	// Code originally brought from - RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html 
	// 
	// WYO - myObjLoader()--> ReadFileCounts()--> LoadDataStructuresMyModelObj()
	//==========================================================================
	bool LoadDataStructuresMyModelObj(
		MyModelObj *mainModel,
		char* filename,
		int vertexCount,
		int textureCount,
		int normalCount,
		int faceCount);

};

