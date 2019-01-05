// File name: [MyModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4QW1SQU4wa0d3b2M%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4QW1SQU4wa0d3b2M
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MVEtaGNCajlzOXM%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MVEtaGNCajlzOXM
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0NVdTY3SnJYZ0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0NVdTY3SnJYZ0k
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom WYO file, representing a model object.
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//-----------------------------------------------------------------------------
// [rev0002:WY:201707101940]
//-----------------------------------------------------------------------------
// File name: [MyModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML:  https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4M2JKeFpReC1udGs%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom WYO file, representing a model object.
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//-----------------------------------------------------------------------------
// [rev0001:WY:201707012350]
//-----------------------------------------------------------------------------
// File name: [MyModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML:  https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4M2JKeFpReC1udGs%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom WYO file, representing a model object.
// - [OBJ] My custom Blender exported OBJ vs Default Blender exported OBJ.
//		- Asserted both OBJ format is the same ... 
//		- BUT after checking, found out that below 2 element tags are added 
//			onto my custom WYO file.
//			- CU Z : Coordinate system UP vector.
//			- CF Y : Coordinate system FORWARD vector.
// - [OBJ-Coordinate system framework]
//		- Above coordinate system vectors will change the method
//		  on how to read in the vertices from file.
//		  Blender Left handed system [X right Z up Y forward]
//		  --> DirectX 12 [X left Y up Z forward]
//			- The algorithm on how to convert them is 
//			  organized on Google Spreadsheet
//				- Blender export with different coordinate system mechanism: 
//					https://docs.google.com/spreadsheets/d/1-Cgt5TWBoKFWQM679ejoNjBIqWlmTwYSD6QxB4lWCBc/edit#gid=0
//				- Blender export --> DirectX 12 import with different coordinate system mechanism:
//					https://docs.google.com/spreadsheets/d/1zarSFgRq6PsNVYPQNASd_uMJoamDMDBFjt2Htn5pDS0/edit#gid=0
// - [Important algorithms]
//		- Coordinate system framework
//			- Explained above.
//		- Duplicate vertex, texture coordinate, normal buffer framework:
//			- Texture mapping summary: 
//				https://docs.google.com/document/d/1Y9LFjegxIZ1eBNEOH9xu9Jcve7xCY498ZCa-_PK1j1w/edit#bookmark=id.6pneskv8a6ch 
//				(Find "Then need to initialize vertices buffer corresponding to texture coordinates loaded from model loader.")
//			- Let's say a element of the vertex buffer for rendering 
//				is called elem, and we're rendering a cube.
//			- For default OBJ file, there are only 
//				8 vertices, 6 normals, 12 faces = 36 indices,
//				BUT 23 texture coordinates.
//			- In order to draw the texture properly, i need to duplicate
//				the elem so that the number of vertices 8 matches 
//				the number of texture coordinates 23.
//			- So i created a framework to duplicate the elems.
//		//=====================================================================
//		// Primitive verices buffer 
//		//	- {[Vertex, texture coordinate, normal] ... }
//		//
//		// Main algorithm converting OBJ file data 
//		//		into primitive vertices buffer 
//		// 
//		// Need to duplicate the OBJ value array elements
//		//		to draw the primitive correctly.
//		// eg. 
//		//		Cube vertices count = 8, Texture coordinates count = 24, 
//		//				Faces indices count = 36.
//		//		Cube - 6 faces - 12 triangle faces - 36 indices acccesing - 
//		//				Vertices buffer max index = 7, 
//		//				texture coordinates buffer max index = 23.
//		//		So i need to fill out rest of the cube vertices buffer 
//		//				so that the indices buffer can access them to
//		//				draw the texture onto proper texture coordinates, 
//		//				when corresponding vertices are drawn
//		//				to create the model primitive.
//		//=====================================================================
//		// eg. Rectangular model OBJ - faces "f 9/3/1  f 7/12/2 ... 8/3/5 ..." 
//		// 
//		// cubeVertices[0] - 
//		// cubeVertices[1] - 
//		// cubeVertices[2] - 
//		//			pos = XMFLOAT3(Vertices[8].x, Vertices[8].y, Vertices[8].z)		
//		//			tex = XMFLOAT2(Texcoords[2].x, Texcoords[2].y)		
//		//			normal = XMFLOAT3(normals[0].x, normals[0].y, normals[0].z)
//		// ......
//		// cubeVertices[10] - 
//		// cubeVertices[11] - 
//		//			pos = XMFLOAT3(Vertices[6].x, Vertices[6].y, Vertices[6].z)		
//		//			tex = XMFLOAT2(Texcoords[11].x, Texcoords[11].y)	
//		//			normal = XMFLOAT3(normals[1].x, normals[1].y, normals[1].z)
//		// ......
//		// ------- Max texture coordinate index 23 -------
//		//		"8/3/5" duplicated because texture coordinate index 3 
//		//		has already been set: cubeVertices[2], 
//		//		but the values will be the same 
//		// cubeVertices[24] - 
//		//			pos = XMFLOAT3(Vertices[7].x, Vertices[7].y, Vertices[7].z)		
//		//			tex = XMFLOAT2(Texcoords[2].x, Texcoords[2].y)		
//		//			normal = XMFLOAT3(normals[4].x, normals[4].y, normals[4].z)
//		// ......
//		// ------- Max size 36 -------
//		//=====================================================================
// - [Documents]
//		- OBJ 
//			- Coordinate system option (CU, CF) summary: 
//				https://docs.google.com/document/d/1sAjWaWN_ztn145rTd6DAV8p5tEHGPs-WhCNasE7ayG4/edit#bookmark=kix.us5b5zgmswls
//			- Texture mapping summary: 
//				https://docs.google.com/document/d/1Y9LFjegxIZ1eBNEOH9xu9Jcve7xCY498ZCa-_PK1j1w/edit#bookmark=id.6pneskv8a6ch
// - [Code resources]
//		- OBJ loader code brought from: 
//			- RasterTek Loading Maya 2011 model: 
//					http://www.rastertek.com/dx11tut08.html 
//				void GetModelFilename(char* , char *);
//				bool ReadFileCounts(char* , int& , int& , int& , int& );
//				bool LoadDataStructures(ModelObj *, char* , int , ... );
//		- GetModelFilename() function was not very necessary for my purpose, 
//			so 90% of the code is commented out.
//		- ReadFileCounts() function and LoadDataStructures() is the main 
//			OBJ loader algorithm, so didn't change anything on original code 
//			but added some code for initializing MyModelObj object 
//			by copying the data values to memeber variables to be 
//			used on rendering.(5% code added)
// - [Framework description]
//		1. MyModelLoader::myObjMtlLoader() - OBJ file path --> Load OBJ file 
//			--> Get MTL file name from OBJ file --> Relative MTL file path
//			--> Load MTL file --> MyModelObj + MyModelMtl = MySpecialModelObj
//			1-2. MyModelLoader::myObjLoader() - Load OBJ file --> MyModelObj 
//				2-2. MyModelLoader::GetModelFilename() 
//					- File check
//				2-3. MyModelLoader::ReadFileCounts() 
//					- Read number of datas for data structure initialization
//				2-4. MyModelLoader::LoadDataStructures() 
//					- MyModelObj initialization
//					[CU, CF, v, vn, vt, f]
//-----------------------------------------------------------------------------
// [rev0000:WY:201706291800]
//-----------------------------------------------------------------------------

//#############################################################################
//#############################################################################
//#############################################################################
// Code
//#############################################################################
//#############################################################################
//#############################################################################
#pragma once

#include "stdafx.h"
#include "MyModelObj.h"

/*
*	MyModelObj class general constructor.
*		Initialize the data structure needed for rendering
*		using the given data structure array sizes passed as parameters.
*   <p>
*	The data structures to be intialized are as follows:
*		materialFileName
*			- mtllib element in OBJ file which holds
*			  MTL file name.
*		vertices
*			- Vertices array to hold vertices data
*			  loaded from custom WYO file.
*		texcoords
*			- Texture coordinates array to hold texture coordinates data
*			  loaded from custom WYO file.
*		normals
*			- Normal vectors array to hold normal vectors data
*			  loaded from custom WYO file.
*		faces
*			- Faces to hold faces data loaded from OBJ file.
*		indicesCount
*			- Number of indices indicated in faces data
*			  loaded from custom WYO file.
*		vertexIndices
*			- Vertex indices indicated in faces data
*			  loaded from custom WYO file.
*		texcoordIndices
*			- Texture coordinate indices indicated in faces data
*			  loaded from custom WYO file.
*		normalIndices
*			- Normal vector indices indicated in faces data
*			  loaded from custom WYO file.
*		vertexPositionColorTextureCoordNormalBuffer
*			- Main vertex buffer to be used for rendering
*			  which holds vertex, texture coordinate, normal for each element.
*		vertexPositionColorTextureCoordNormalBufferCount
*			- Main vertex buffer size to be used for rendering.
*		originalVertexPositionColorTextureCoordNormalBuffer
*			- Back up vertex buffer for extra features (eg. Reposition).
*
*	@param		vertexCount				Size of the vertex array.
*	@param		textureCount			Size of the texture coordinate array.
*	@param		normalCount				Size of the normal vector array.
*	@param		faceCount				Size of the face array.
*	@since		ver0003
*/
MyModelObj::MyModelObj(
	int vertexCount,	// Number of "v" element in custom WYO file.
	int textureCount,	// Number of "vt" element in custom WYO file.
	int normalCount,	// Number of "vn" element in custom WYO file.
	int faceCount)		// Number of "f" element in custom WYO file.
	: ModelObj(
		vertexCount,
		textureCount,
		normalCount,
		faceCount) {
	//==========================================================================
	// Coordinate system UP vector flags used to determine which UP vector is 
	// indicated in the custom exported WYO file as "CU" element.
	//==========================================================================
	this->coordoption_X_up = false;				//  X up
	this->coordoption_minus_X_up = false;		// -X up
	this->coordoption_Y_up = false;				//  Y up
	this->coordoption_minus_Y_up = false;		// -Y up
	this->coordoption_Z_up = false;				//  Z up
	this->coordoption_minus_Z_up = false;		// -Z up

	// CU - Coordinate system UP vector string value.
	this->coordoption_up_str = new char[BUFSIZ]();
	std::fill(this->coordoption_up_str, this->coordoption_up_str + BUFSIZ, 0);

	//==========================================================================
	// Coordinate system FORWARD vector flags used to determine which FORWARD
	//  vector is indicated in the custom exported WYO file as "CF" element.
	//==========================================================================
	this->coordoption_X_forward = false;			//  X forward
	this->coordoption_minus_X_forward = false;		// -X forward
	this->coordoption_Y_forward = false;			//  Y forward
	this->coordoption_minus_Y_forward = false;		// -Y forward
	this->coordoption_Z_forward = false;			//  Z forward
	this->coordoption_minus_Z_forward = false;		// -Z forward

	// CF - Coordinate system FORWARD vector string value.
	this->coordoption_forward_str = new char[BUFSIZ]();
	std::fill(this->coordoption_forward_str,
		this->coordoption_forward_str + BUFSIZ, 0);

}

// Destructor
MyModelObj::~MyModelObj() {
	//==========================================================================
	// Coordinate system UP vector flags used to determine which UP vector is 
	// indicated in the custom exported WYO file as "CU" element.
	//==========================================================================
	this->coordoption_X_up = false;				//  X up
	this->coordoption_minus_X_up = false;		// -X up
	this->coordoption_Y_up = false;				//  Y up
	this->coordoption_minus_Y_up = false;		// -Y up
	this->coordoption_Z_up = false;				//  Z up
	this->coordoption_minus_Z_up = false;		// -Z up

	// CU - Coordinate system UP vector string value.
	if (this->coordoption_up_str != NULL) {
		delete this->coordoption_up_str;
		this->coordoption_up_str = NULL;
	}

	//==========================================================================
	// Coordinate system FORWARD vector flags used to determine which FORWARD
	//  vector is indicated in the custom exported WYO file as "CF" element.
	//==========================================================================
	this->coordoption_X_forward = false;			//  X forward
	this->coordoption_minus_X_forward = false;		// -X forward
	this->coordoption_Y_forward = false;			//  Y forward
	this->coordoption_minus_Y_forward = false;		// -Y forward
	this->coordoption_Z_forward = false;			//  Z forward
	this->coordoption_minus_Z_forward = false;		// -Z forward

	// CF - Coordinate system FORWARD vector string value.
	if (this->coordoption_forward_str != NULL) {
		delete this->coordoption_forward_str;
		this->coordoption_forward_str = NULL;
	}
}

//==============================================================================
// Coordinate system UP vector (CU)
//==============================================================================
/*
*	Getter - Member variable "coordoption_up_str".
*	<p>
*	This function is the getter for current MyModelObj object's
*		member variable "coordoption_up_str".
*		- Coordinate system UP vector C-String value
*		  when initialized through MyModelLoader from the custom WYO file,
*		  this value determines on how the vertices are loaded.
*	Element tag in custom WYO file - [CU].
*	@return		Return current MyModelObj object's
*					member variable "coordoption_up_str"
*					C-String.
*	@since		ver0003
*/
char *MyModelObj::get_coordoption_up_str() {
	return this->coordoption_up_str;
}
/*
*	Setter - Member variable "coordoption_up_str".
*	<p>
*	This function is the setter for current MyModelObj object's
*		member variable "coordoption_up_str",
*		automatically assign a coordinate system UP vector boolean flag value
*		to decide how to load the vertices from the custom WYO file.
*		- Coordinate system UP vector string value when initialized
*		  through MyModelLoader from the custom WYO file,
*		  this value determines on how the vertices are loaded.
*	Element tag in custom WYO file - [CU].
*	@param		coordoption_up_str	Coordinate system UP vetor
*									C-String value to set with
*	@return		void
*	@since		ver0003
*/
void MyModelObj::set_coordoption_up_str(char *coordoption_up_str) {
	// Set memeber variable "coordoption_up_str" with the string received.
	strcpy(this->coordoption_up_str, coordoption_up_str);

	// Set coordinate system boolean flags to decide how to load the vertices.
	(strcmp(coordoption_up_str, "X") == 0) ?
		coordoption_X_up = true :
		(strcmp(coordoption_up_str, "-X") == 0) ?
		coordoption_minus_X_up = true
		: (strcmp(coordoption_up_str, "Y") == 0) ?
		coordoption_Y_up = true :
		(strcmp(coordoption_up_str, "-Y") == 0) ?
		coordoption_minus_Y_up = true
		: (strcmp(coordoption_up_str, "Z") == 0) ?
		coordoption_Z_up = true :
		(strcmp(coordoption_up_str, "-Z") == 0) ?
		coordoption_minus_Z_up = true
		: false;
	//_RPT1(0, "this->coordoption_up_str : %s\n", this->coordoption_up_str);
}
//==============================================================================
// Coordinate system FORWARD vector (CF)
//==============================================================================
/*
*	Getter - Member variable "coordoption_forward_str".
*	<p>
*	This function is the getter for current MyModelObj object's
*		member variable "coordoption_forward_str".
*		- Coordinate system FORWARD vector C-String value indicated
*		  in OBJ file when initialized through MyModelLoader from the custom
*		  WYO file, this value determines on how the vertices are loaded.
*	Element tag in custom WYO file - [CF].
*	@return		Return current MyModelObj object's
*					member variable "coordoption_forward_str"
*					C-String.
*	@since		ver0003
*/
char *MyModelObj::get_coordoption_forward_str() {
	return this->coordoption_forward_str;
}
/*
*	Setter - Member variable "coordoption_forward_str".
*	<p>
*	This function is the setter for current MyModelObj object's
*		member variable "coordoption_forward_str",
*		automatically assign a coordinate system FORWARD vector boolean flag 
*		value to decide how to load the vertices from the custom WYO file.
*		- Coordinate system FORWARD vector C-string value indicated in OBJ file when initialized
*		  through MyModelLoader from the custom WYO file,
*		  this value determines on how the vertices are loaded.
*	Element tag in custom WYO file - [CF].
*	@param		coordoption_forward_str		Coordinate system FORWARD vetor
*											C-String value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelObj::set_coordoption_forward_str(char *coordoption_forward_str) {
	// Set memeber variable "coordoption_forward_str" with the string received.
	strcpy(this->coordoption_forward_str, coordoption_forward_str);
	// Set coordinate system boolean flags to decide how to load the vertices.
	(strcmp(coordoption_forward_str, "X") == 0) ?
		coordoption_X_forward = true :
		(strcmp(coordoption_forward_str, "-X") == 0) ?
		coordoption_minus_X_forward = true
		: (strcmp(coordoption_forward_str, "Y") == 0) ?
		coordoption_Y_forward = true :
		(strcmp(coordoption_forward_str, "-Y") == 0) ?
		coordoption_minus_Y_forward = true
		: (strcmp(coordoption_forward_str, "Z") == 0) ?
		coordoption_Z_forward = true :
		(strcmp(coordoption_forward_str, "-Z") == 0) ?
		coordoption_minus_Z_forward = true
		: false;
}
