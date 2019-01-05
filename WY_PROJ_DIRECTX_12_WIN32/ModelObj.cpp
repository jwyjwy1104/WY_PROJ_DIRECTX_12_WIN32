// File name: [ModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MUFUM0pwWHYwMjA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MUFUM0pwWHYwMjA
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4TUhNd05BNkZNLUU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4TUhNd05BNkZNLUU
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4Q3NZN3F0bjBOWEU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4Q3NZN3F0bjBOWEU
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information needed to hold the data loaded from
//			a standard OBJ file. (Read [OBJ] section below)
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0002:WY:201707101930]
//------------------------------------------------------------------------------
// File name: [ModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MUFUM0pwWHYwMjA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MUFUM0pwWHYwMjA
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4TUhNd05BNkZNLUU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4TUhNd05BNkZNLUU
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4Q3NZN3F0bjBOWEU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4Q3NZN3F0bjBOWEU
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information needed to hold the data loaded from
//			a standard OBJ file. (Read [OBJ] section below)
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707020000]
//------------------------------------------------------------------------------
// File name: [ModelObj.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4MUFUM0pwWHYwMjA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4MUFUM0pwWHYwMjA
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4TUhNd05BNkZNLUU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4TUhNd05BNkZNLUU
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4Q3NZN3F0bjBOWEU%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4Q3NZN3F0bjBOWEU
// Staff: 
//		Lead programmer: Samil Chai (SC)
//		Junior programmer: Nick Jang (WY)
// Descriptions & Comments: 
// - [Resources]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information needed to hold the data loaded from
//			a standard OBJ file. (Read [OBJ] section below)
// - [Comments]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//		
// - [Recent comments]:
//		*****Document brought from MyModelObj class, because now this class will hold
//			all the standard information loaded from an OBJ file.
//		This class holds all the properties and information 
//			loaded from an OBJ file, representing a model.
//		Design decision:
//			Trying to inherit the MyModelObj class as current ModelObj's child 
//				class. So for each custom formats, i can just add the extra
//				features on child class, where standard format is supported.
//				So each MySpecialModelObj will hold ModelObj and ModelMtl 
//				object, and during loading through MyModelLoader, i will 
//				determine which class to use using the extension found on file 
//				path.
//			eg.
//				.wyo - My custom OBJ file exported through BlenderExporter
//				.obj - Standard OBj file exported through standard 3D engine
//					(Blender, Maya, etc ... )
// - [OBJ] My custom Blender exported OBJ vs Default Blender exported OBJ.
//		- Asserted both OBJ format is the same ... 
//		- BUT after checking, found out that below 2 element tags are added 
//			onto my custom OBJ file.
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
//		//======================================================================
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
//		//======================================================================
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
//		//======================================================================
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
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
//------------------------------------------------------------------------------
// [rev0000:WY:201706291700]
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
#include "ModelObj.h"

/*
*	ModelObj class general constructor.
*		Initialize the data structure needed for rendering
*		using the given data structure array sizes passed as parameters.
*   <p>
*	The variables to be intialized are as follows:
*		materialFileName
*			- mtllib element in standard OBJ file which holds
*			  MTL file name.
*		vertices
*			- Vertices array to hold vertices data
*			  loaded from standard OBJ file.
*		texcoords
*			- Texture coordinates array to hold texture coordinates data
*			  loaded from standard OBJ file.
*		normals
*			- Normal vectors array to hold normal vectors data
*			  loaded from standard OBJ file.
*		faces
*			- Faces to hold faces data loaded from OBJ file.
*		indicesCount
*			- Number of indices indicated in faces data
*			  loaded from standard OBJ file.
*		vertexIndices
*			- Vertex indices indicated in faces data
*			  loaded from standard OBJ file.
*		texcoordIndices
*			- Texture coordinate indices indicated in faces data
*			  loaded from standard OBJ file.
*		normalIndices
*			- Normal vector indices indicated in faces data
*			  loaded from standard OBJ file.
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
ModelObj::ModelObj(
	int vertexCount,	// Number of "v" element in standard OBJ file.
	int textureCount,	// Number of "vt" element in standard OBJ file.
	int normalCount,	// Number of "vn" element in standard OBJ file.
	int faceCount) {	// Number of "f" element in standard OBJ file.

	// init directory path buffer to hold "this" OBJ file.
	this->currentObjDirectoyPath = new char[BUFSIZ]();
	std::fill(this->currentObjDirectoyPath, 
		this->currentObjDirectoyPath + BUFSIZ, 0);

	//==========================================================================
	// Material file name. (eg. mtllib indicated in standard OBJ file)
	// The material file path relative to "this" OBJ file.
	//==========================================================================
	this->materialFileName = new char[BUFSIZ]();
	std::fill(this->materialFileName, this->materialFileName + BUFSIZ, 0);

	//==========================================================================
	// Data structure related
	//==========================================================================
	// Vertices(v) 
	// - The data structure to hold the "v" data loaded from OBJ file.
	this->vertices = new VertexType[vertexCount];
	// Number of elements inside "vertices" array.
	this->vertexCount = vertexCount; 

	// Texture coordinates (vt) 
	// - The data structure to hold the "vt" data loaded from OBJ file.
	this->texcoords = new VertexType[textureCount];
	// Number of elements inside "texcoords" array.
	this->textureCount = textureCount; 

	// Normals (vn) 
	// - The data structure to hold the "vn" data loaded from OBJ file.
	this->normals = new VertexType[normalCount];
	// Number of elements inside "normals" array.
	this->normalCount = normalCount; 

	// Faces (f) 
	// - The data structure to hold the "f" data loaded from OBJ file.
	this->faces = new FaceType[faceCount];
	// Number of elements inside "faces" array
	this->faceCount = faceCount;

	// Number of indices of "this" model.
	this->indicesCount = faceCount * 3;

	//==========================================================================
	// Main data structure.
	//==========================================================================
	// Main vertex buffer size to be used for rendering
	// Number of elements stored in this 
	// "vertexPositionColorTextureCoordNormalBuffer" data structure.
	this->vertexPositionColorTextureCoordNormalBufferCount = this->indicesCount;

	// Main data structrue to hold the array of elements 
	// which has vertex position coordinate, texture coordinate and 
	// vertex normal vector to be used for rendering.	
	this->vertexPositionColorTextureCoordNormalBuffer
		= new VertexPositionColorTextureCoordNormal[this->indicesCount];

	// Back up main data structure for extra features. (eg. Reset position)
	this->originalVertexPositionColorTextureCoordNormalBuffer
		= new VertexPositionColorTextureCoordNormal*[this->indicesCount];
	for (int i = 0; i < this->indicesCount; i++) {
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]
			= new VertexPositionColorTextureCoordNormal();
	}

	//==========================================================================
	// Indices array related.
	// In 3D game engine, the primitive is drawn with triangles 
	// so if it is a cube model = 6 faces = 12 indices
	//==========================================================================
	// Vertex indices array generated from faces array. (eg. v/t/n --> v)
	this->vertexIndices = new DWORD[this->indicesCount];
	// Texture indices array generated from faces array. (eg. v/t/n --> t)
	this->texcoordIndices = new DWORD[this->indicesCount];
	// Normal indices array generated from faces array. (eg. v/t/n --> n)
	this->normalIndices = new DWORD[this->indicesCount];
}

// Destructor
ModelObj::~ModelObj() {
	// OBJ file's directory path.
	if (this->currentObjDirectoyPath != NULL) {
		delete this->currentObjDirectoyPath;
		this->currentObjDirectoyPath = NULL;
	}

	// Material file name. (eg. mtllib indicated in standard OBJ file)
	// The material file path relative to "this" OBJ file.
	if (this->materialFileName != NULL) {
		delete this->materialFileName;
		this->materialFileName = NULL;
	}

	// Vertices(v) 
	// - The data structure to hold the "v" data loaded from OBJ file.
	if (this->vertices != NULL) {
		delete this->vertices;
		this->vertices = NULL;
	}
	this->vertexCount = 0; // Number of elements inside "vertices" array
	
	// Texture coordinates (vt) 
	// - The data structure to hold the "vt" data loaded from OBJ file.
	if (this->texcoords != NULL) {
		delete this->texcoords;
		this->texcoords = NULL;
	}
	this->textureCount = 0; // Number of elements inside "texcoords" array.
	
	// Normals (vn) 
	// - The data structure to hold the "vn" data loaded from OBJ file.
	if (this->normals != NULL) {
		delete this->normals;
		this->normals = NULL;
	}
	this->normalCount = 0; // Number of elements inside "normals" array.
	
	// Faces (f) 
	// - The data structure to hold the "f" data loaded from OBJ file.
	if (this->faces != NULL) {
		delete this->faces;
		this->faces = NULL;
	}
	this->faceCount = 0; // Number of elements inside "faces" array.

	// Main data structrue to hold the array of elements 
	// which has vertex position coordinate, texture coordinate and 
	// vertex normal vector to be used for rendering.
	if (this->vertexPositionColorTextureCoordNormalBuffer != NULL) {
		delete this->vertexPositionColorTextureCoordNormalBuffer;
		this->vertexPositionColorTextureCoordNormalBuffer = NULL;
	}
	// Back up main data structure for extra features. (eg. Reset position)
	if (this->originalVertexPositionColorTextureCoordNormalBuffer != NULL) {
		/*for (int i = 0; 
			i < this->getVertexPositionColorTextureCoordNormalBufferCount();
			i++) {
			if (this->originalVertexPositionColorTextureCoordNormalBuffer[i] 
				!= NULL) {
				delete 
					this
					->originalVertexPositionColorTextureCoordNormalBuffer[i];
			}
		}*/
		delete [] this->originalVertexPositionColorTextureCoordNormalBuffer;
		this->originalVertexPositionColorTextureCoordNormalBuffer = NULL;
	}
	// Main vertex buffer size to be used for rendering
	// Number of elements stored in this 
	// "vertexPositionColorTextureCoordNormalBuffer" data structure.
	this->vertexPositionColorTextureCoordNormalBufferCount = 0;

	// Number of indices of "this" model.
	this->indicesCount = 0;

	// Vertex indices array generated from faces array. (eg. v/t/n --> v)
	if (this->vertexIndices != NULL) {
		delete this->vertexIndices;
		this->vertexIndices = NULL;
	}
	// Texture indices array generated from faces array. (eg. v/t/n --> t)
	if (this->texcoordIndices != NULL) {
		delete this->texcoordIndices;
		this->texcoordIndices = NULL;
	}
	// Normal indices array generated from faces array. (eg. v/t/n --> n)
	if (this->normalIndices != NULL) {
		delete this->normalIndices;
		this->normalIndices = NULL;
	}
}

//==============================================================================
// Directory path of the OBJ file.
//==============================================================================
/*
*	Getter - Member variable "currentObjDirectoyPath".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "currentObjDirectoyPath".
*		- Standard OBJ file's directory path when initialized through MyModelLoader,
*		  to be used for loading relative MTL file.
*	@return		Return current ModelObj  object's
*					member variable "currentObjDirectoyPath"
*					OBJ file directory path
*					C-string.
*	@since		ver0003
*/
char *ModelObj::getCurrentObjDirectoyPath() {
	return this->currentObjDirectoyPath;
}
/*
*	Setter - Member variable "currentObjDirectoyPath".
*	<p>
*	This function is the setter for current ModelObj  object's
*		member variable "currentObjDirectoyPath".
*		- Standard OBJ file's directory path when initialized through MyModelLoader.
*		  to be used for loading relative MTL file.
*	@param		currentObjDirectoyPath		Directory path C-String value
*												to set with.
*	@return		void
*	@since		ver0003
*/
void ModelObj::setCurrentObjDirectoyPath(char *currentObjDirectoyPath) {
	strcpy(this->currentObjDirectoyPath, currentObjDirectoyPath);
}

//==============================================================================
// Model name.
//==============================================================================
/*
*	Getter - Member variable "modelName".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "modelName".
*		- Current model's name property.
*	@return		Return current ModelObj object's
*					member variable "modelName"
*					std::string.
*	@since		ver0003
*/
string ModelObj::getModelName() {
	return this->modelName;
}

//==============================================================================
// Material file name. (eg. mtllib indicated in standard OBJ file)
// The material file path relative to "this" OBJ file.
//==============================================================================
/*
*	Getter - Member variable "materialFileName".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "materialFileName".
*		- Material file name ("mtllib" element) C-String value indicated
*		  in OBJ file when initialized
*		  through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [mtllib].
*	@return		Return current ModelObj object's
*					member variable "materialFileName"
*					C-String.
*	@since		ver0003
*/
char *ModelObj::getMaterialFileName() {
	//_RPT1(0, "this->materialFileName : %s\n", this->materialFileName);
	return this->materialFileName;
}
/*
*	Setter - Member variable "materialFileName".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "materialFileName".
*		- Material file name ("mtllib" element) C-String value indicated
*		  in OBJ file when initialized
*		  through ModelObj from standard OBJ file.
*	Element tag in standard OBJ file - [mtllib].
*	@param		materialFileName		Material file name ("mtllib" element)
*										C-String value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelObj::setMaterialFileName(char *materialFileName) {
	this->materialFileName = new char[BUFSIZ]();
	std::fill(this->materialFileName, this->materialFileName + BUFSIZ, 0);

	strcpy(this->materialFileName, materialFileName);
	//strcat(this->materialFileName, "\0");
	//_RPT1(0, "this->materialFileName : %s\n", this->materialFileName);
}

//==============================================================================
// Vertices(v) - The data structure to hold the "v" data loaded from OBJ file.
//==============================================================================
/*
*	Getter - Member variable "vertices".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "vertices".
*		- Vertices array data structure indicated in standarad OBJ file
*		  when initialized through ModelObj from standarad OBJ file.
*	Element tag in standard OBJ file - [v].
*	@return		Return current MyModelObj object's
*					member variable "vertices"
*					VertexType array pointer.
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
VertexType *ModelObj::getModelVertices() {
	return this->vertices;
}
/*
*	Setter - Member variable "vertices".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "vertices".
*		- Vertices array data structure indicated in standard OBJ file
*		  when initialized through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [v].
*	@param		vertices		Vertex array data structure pointer
*									to set with.
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::setModelVertices(VertexType *vertices) {
	this->vertices = vertices;
}
/*
*	Assign MyModelObj object's vertices array data structure
*		by copying from other vertices array data structure
*		passed as parameter.
*	<p>
*	This function copies the data from parameter "vertices" array onto
*		current ModelObj object's member variable "vertices"
*		- Vertices array data structure indicated in standard OBJ file
*		  when initialized through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [v].
*	@param		vertices		Vertex array data structure pointer
*									to copy data with (Source).
*	@param		vertexCount		Size of the vertex array data structure
*									pointer to copy data with.
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::copyModelVertices(VertexType *vertices, int vertexCount) {
	for (int i = 0; i < vertexCount; i++) {
		this->vertices[i] = vertices[i];
	}
}
/*
*	Getter - Member variable "vertexCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "vertexCount".
*		- Size of the vertices array data structure calculated
*		  when initialized through MyModelLoader from standard OBJ file.
*	@return		Return current ModelObj object's
*					member variable "vertexCount"
*					integer value.
*	@since		ver0003
*/
int ModelObj::getVertexCount() {
	return this->vertexCount;
}

//==============================================================================
// Texture coordinates (vt) 
// - The data structure to hold the "vt" data loaded from OBJ file.
//==============================================================================
/*
*	Getter - Member variable "texcoords".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "texcoords".
*		- Texture coordinates array data structure indicated
*		  in standard OBJ file when initialized
*		  through ModelObj from standard OBJ file.
*	Element tag in standard OBJ file - [vt].
*	@return		Return current ModelObj object's
*					member variable "texcoords"
*					VertexType array pointer.
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
VertexType *ModelObj::getTexcoords() {
	return this->texcoords;
}
/*
*	Setter - Member variable "texcoords".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "texcoords"
*		- Texture coordinates array data structure indicated
*		  in standard OBJ file when initialized
*		  through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [vt].
*	@param		texcoords		Texture coordinates array
*									data structure pointer to set with.
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::setTexcoords(VertexType *texcoords) {
	this->texcoords = texcoords;
}
/*
*	Assign ModelObj object's texture coordinates array data structure
*		by copying from other texture coordinates array data structure
*		passed as parameter.
*	<p>
*	This function copies data from parameter "texcoords" array
*		onto current ModelObj object's
*		member variable "texcoords"
*		- Texture coordinates array data structure indicated
*		  in standard OBJ file when initialized
*		  through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [vt].
*	@param		texcoords			Texture coordinates array data structure
*										pointer to copy data with (Source).
*	@param		textureCount		Size of the texture coordinates array
*									data structure pointer to copy data with.
*	@see		ShaderStructures.h		VertexType
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::copyTexcoords(VertexType *texcoords, int textureCount) {
	for (int i = 0; i < textureCount; i++) {
		this->texcoords[i] = texcoords[i];
	}
}
/*
*	Getter - Member variable "textureCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "textureCount".
*		- Size of the texture coordinates array data structure
*		  calculated when initialized
*		  through MyModelLoader from standard OBJ file.
*	@return		Return current ModelObj object's
*					member variable "textureCount"
*					integer value.
*	@since		ver0003
*/
int ModelObj::getTextureCount() {
	return this->textureCount;
}

//==============================================================================
// Normals (vn) 
// - The data structure to hold the "vn" data loaded from OBJ file.
//==============================================================================
/*
*	Getter - Member variable "normals".
*	<p>
*	This function is the getter for current MyModelObj object's
*		member variable "normals".
*		- Normal vectors array data structure indicated
*		  in standard OBJ file when initialized
*		  through ModelObj from standard OBJ file.
*	Element tag in standard OBJ file - [vn].
*	@see		ShaderStructures.h		VertexType
*	@return		Return current MyModelObj object's
*					member variable "normals"
*					VertexType array pointer.
*	@see		ShaderStructure::VertexType
*	@since		ver0003
*/
VertexType *ModelObj::getNormals() {
	return this->normals;
}
/*
*	Setter - Member variable "normals".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "normals"
*		- Normal vectors array data structure indicated in standard OBJ file 
*		  when initialized through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [vn].
*	@param		normals		Normal vectors array data structure pointer
*								to set with.
*	@see		ShaderStructures.h		VertexType
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::setNormals(VertexType *normals) {
	this->normals = normals;
}
/*
*	Assign ModelObj object's normal vectors data structure
*		by copying from other normal vectors array data structure.
*	<p>
*	This function copies data from parameter "normals" array
*		onto current ModelObj object's member variable "normals"
*		- Normal vectors array data structure indicated
*		  in OBJ standard file when initialized
*		  through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [vn].
*	@param		normals			Normal vectors array data structure pointer
*									to copy data with (Source).
*	@param		normalCount		Size of the normal vectors array
*									pointer to copy data with.
*	@see		ShaderStructures.h		VertexType
*	@return		void
*	@see		ShaderStructures::VertexType
*	@since		ver0003
*/
void ModelObj::copyNormals(VertexType *normals, int normalCount) {
	for (int i = 0; i < normalCount; i++) {
		this->normals[i] = normals[i];
	}
}
/*
*	Getter - Member variable "normalCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "normalCount".
*		- Size of the normal vectors array data structure calculated when
*		  initialized through ModelObj from standard OBJ file.
*	@return		Return current ModelObj object's
*					member variable "normalCount"
*					integer value.
*	@since		ver0003
*/
int ModelObj::getNormalCount() {
	return this->normalCount;
}

//==============================================================================
// Faces (f) - The data structure to hold the "f" data loaded from OBJ file.
//==============================================================================
/*
*	Getter - Member variable "faces".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "faces".
*		- Faces array data structure indicated in OBJ file when initialized
*		  through MyModelLoader from standard OBJ file,
*		  which holds the indices to create the triangle primitives
*		  for surface rendering on models.
*	Element tag in custom OBJ file - [f].
*	@see		ShaderStructures.h		FaceType
*	@return		Return current ModelObj object's
*					member variable "faces"
*					FaceType array pointer.
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
FaceType *ModelObj::getFaces() {
	return this->faces;
}
/*
*	Setter - Member variable "faces".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "faces".
*		- Faces array data structure indicated in standard OBJ file
*		  when initialized through MyModelLoader from standard OBJ file,
*		  which holds the indices to create the triangle primitives
*		  for surface rendering on models.
*	Element tag in standard OBJ file - [f].
*	@param		faces		Faces array data structure pointer to set with.
*	@see		ShaderStructures.h		FaceType
*	@return		void
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
void ModelObj::setFaces(FaceType *faces) {
	this->faces = faces;
}
/*
*	Assign ModelObj object's faces data structure
*		by copying from other faces array data structure.
*	<p>
*	This function copies data from parameter "faces" array
*		onto current ModelObj object's
*		member variable "faces"
*		- Faces array data structure indicated in standard OBJ file when
*		  initialized through MyModelLoader from standard OBJ file.
*	Element tag in standard OBJ file - [f].
*	@param		faces			Faces array data structure pointer
*									to copy data with (Source).
*	@param		faceCount		Size of the faces array data structure
*									pointer to copy data with.
*	@see		ShaderStructures.h		FaceType
*	@return		void
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
void ModelObj::copyFaces(FaceType *faces, int faceCount) {
	for (int i = 0; i < faceCount; i++) {
		this->faces[i] = faces[i];
	}
}
/*
*	Getter - Member variable "faceCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "faceCount".
*		- Size of the faces array data structure calculated when initialized
*		  through MyModelLoader from standard OBJ file.
*	@return		Return current ModelObj object's
*					member variable "faceCount"
*					integer value.
*	@since		ver0003
*/
int ModelObj::getFaceCount() {
	return this->faceCount;
}

//==============================================================================
// Vertex buffer = Faces (f) 
//	--> [Vertex, Texture coordinate, Normal (v/t/n) ... ]
//  - The data structure to hold the converted and calculated data 
//	  that is actually going to be uploaded to GPU for rendering.
//==============================================================================
/*
*	Getter - Member variable "vertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "vertexPositionColorTextureCoordNormalBuffer".
*		- The array of datas which holds vertex corodinate, texture coordinate
*		  and normal vector, calculated and converted
*		  using the data loaded from OBJ file though MyModelLoader.
*	This is the main data structure to be uploaded to GPU for rendering,
*		which has all the information combined using face indices
*		with vertex array, tetxure coordinate array and normals array.
*	This data structure is being held by a pointer allocated on heap memory,
*		but the data objects are created on stack so it can be uploaded to GPU.
*		eg.
*		VertexPositionColorTextureCoordNormal * --> [][][] can be uploaded,
*		BUT VertexPositionColorTextureCoordNormal** --> [*][*][*] can't.
*	@see		ShaderStructures.h		VertexPositionColorTextureCoordNormal
*	@return		Return current ModelObj object's
*					member variable "faces"
*					FaceType array pointer.
*	@see		ShaderStructures::VertexPositionColorTextureCoordNormal
*	@since		ver0003
*/
VertexPositionColorTextureCoordNormal
*ModelObj::getVertexPositionColorTextureCoordNormalBuffer() {
	return this->vertexPositionColorTextureCoordNormalBuffer;
}
/*
*	Setter - Member variable "VertexPositionColorTextureCoordNormal".
*	<p>
*	This function is the setter for current ModelObj object's
*		member variable "vertexPositionColorTextureCoordNormalBuffer"
*		- The array of datas which holds
*		  vertex corodinate, texture coordinate and normal vector,
*		  calculated and converted using the data
*		  loaded from standard OBJ file though MyModelLoader.
*	@param		vertexPositionColorTextureCoordNormalBuffer		vertex buffer
*																array pointer
*																to set with.
*	@see		ShaderStructures.h		VertexPositionColorTextureCoordNormal
*	@return		void
*	@see		ShaderStructures::VertexPositionColorTextureCoordNormal
*	@since		ver0003
*/
void ModelObj::setVertexPositionColorTextureCoordNormalBuffer(
	VertexPositionColorTextureCoordNormal
	*vertexPositionColorTextureCoordNormalBuffer) {
	this->vertexPositionColorTextureCoordNormalBuffer
		= vertexPositionColorTextureCoordNormalBuffer;
}
/*
*	Assign MyModelObj object's vertex buffer data structure
*		by copying from other vertex buffer array data structure.
*	<p>
*	This function copies data from parameter
*		"vertexPositionColorTextureCoordNormalBuffer" array
*		onto current ModelObj object's
*		member variable "vertexPositionColorTextureCoordNormalBuffer"
*		- Vertex buffer array data structure when
*		  initialized through MyModelLoader from standard OBJ file.
*	@param		vertexPositionColorTextureCoordNormalBuffer
*						Vertex buffer array data structure pointer
*						to copy data with (Source).
*	@param		vertexPositionColorTextureCoordNormalCount
*						Size of the vertex buffer array
*						data structure pointer to copy data with.
*	@see		ShaderStructures.h		VertexPositionColorTextureCoordNormal
*	@return		void
*	@see		ShaderStructures::VertexPositionColorTextureCoordNormal
*	@since		ver0003
*/
void ModelObj::copyVertexPositionColorTextureCoordNormalBuffer(
	VertexPositionColorTextureCoordNormal
	*vertexPositionColorTextureCoordNormalBuffer,
	int vertexPositionColorTextureCoordNormalCount) {
	for (int i = 0; i < vertexPositionColorTextureCoordNormalCount; i++) {
		this->vertexPositionColorTextureCoordNormalBuffer[i]
			= vertexPositionColorTextureCoordNormalBuffer[i];
	}
}
/*
*	Getter - Member variable "vertexPositionColorTextureCoordNormalBufferCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "vertexPositionColorTextureCoordNormalBufferCount".
*		- Size of the vertex buffer array data structure when
*		  initialized through MyModelLoader from standard OBJ file.
*	@return	  Return current ModelObj object's
*			  member variable "vertexPositionColorTextureCoordNormalBufferCount"
*			  integer value.
*	@since		ver0003
*/
int ModelObj::getVertexPositionColorTextureCoordNormalBufferCount() {
	return this->vertexPositionColorTextureCoordNormalBufferCount;
}

/*
*	Getter - Member variable 
*		"originalVertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "originalVertexPositionColorTextureCoordNormalBuffer".
*		- The backed up array copied from
*		  "vertexPositionColorTextureCoordNormalBuffer" initialization.
*	This is data structure is used for extra features,
*		such as repositioning or projection.
*	Unlike "vertexPositionColorTextureCoordNormalBuffer"
*		this is dynamically created because this is not being uploaded to GPU
*		but using the data values for updating.
*	@see		ShaderStructures.h		VertexPositionColorTextureCoordNormal
*	@return		Return current MyModelObj object's
*					member variable "faces"
*					FaceType array pointer.
*	@see		ShaderStructures::VertexPositionColorTextureCoordNormal
*	@since		ver0003
*/
VertexPositionColorTextureCoordNormal
**ModelObj::getOriginalVertexPositionColorTextureCoordNormalBuffer() {
	return this->originalVertexPositionColorTextureCoordNormalBuffer;
}


//==============================================================================
// Duplicate vertex buffer element algorithm
//==============================================================================
/*
*	Duplicate the vertices according to the texture coordinate index buffer
*		initialized on current ModelObj object's
*		member variable "vertexPositionColorTextureCoordNormalBuffer".
*	<p>
*	This function generates the main vertex buffer
*		using the vertices, texture coordinates, normal vectors and faces array
*		data structures, to be uploaded to the GPU for rendering.
*	For proper rendering, i needed to create the following
*		framework to duplicate and adjust the vertex buffer elements:
*	- Duplicate vertex, texture coordinate, normal buffer framework:
*		- Texture mapping summary:
*			https://docs.google.com/document/d/1Y9LFjegxIZ1eBNEOH9xu9Jcve7xCY498ZCa-_PK1j1w/edit#bookmark=id.6pneskv8a6ch
*		- Let's say an element of the vertex buffer for rendering is called
*			elem, and we're rendering a cube.
*		- For default OBJ file, there are only
*			8 vertices, 6 normals, 12 faces = 36 indices,
*			BUT have maxmimum of 23 texture coordinate index value.
*		- In order to draw the texture properly, i needed to duplicate
*			the elem so that the number of vertices (8) matches
*			the number of texture coordinates (23).
*		- So i created a framework to duplicate the elems.
*	 Main algorithm description:
//==============================================================================
// Primitive vertex buffer looks like following:
//	- {[Vertex, texture coordinate, normal], [v/t/n], [v/t/n] ... }
//	which have elements of "v/t/n".
//
// Main algorithm converting OBJ file into primitive vertex buffer:
//		Cube vertices count = 8, Texture coordinates count = 24,
//				Faces indices count = 36.
//		Cube - 6 faces - 12 triangle faces - 36 indices acccesing -
//				Maximum of the vertices index indicated in "f" element = 7,
//				Maximum of the texcoord index indicated in "f" element = 23,
//		So i need to fill out rest of the cube's vertex buffer
//		so that the indices buffer can access them to draw the texture onto 
//		proper texture coordinates, when corresponding vertices are drawn
//		to create the model primitive.
//	eg. 
//		Drawn vertex buffer element 1: v/t/n 
//			--> Drawing vertex with "v"
//			--> Drawing textures with "t"
//			But if i use "v" as main vertex buffer index, then there will be 
//			duplication of the texture coordinate indices
//			eg. v1/t1/n1 = 1/4/3 , v20/t20/n20 = 1/30/3
//==============================================================================
// eg. Rectangular model OBJ - faces "f 9/3/1  f 7/12/2 ... 8/3/5 ..."
//
// cubeVertices[0] -
// cubeVertices[1] -
// cubeVertices[2] -
//			pos = XMFLOAT3(Vertices[8].x, Vertices[8].y, Vertices[8].z)
//		-->	tex = XMFLOAT2(Texcoords[2].x, Texcoords[2].y)
//			normal = XMFLOAT3(normals[0].x, normals[0].y, normals[0].z)
// ......
// cubeVertices[10] -
// cubeVertices[11] -
//			pos = XMFLOAT3(Vertices[6].x, Vertices[6].y, Vertices[6].z)
//		-->	tex = XMFLOAT2(Texcoords[11].x, Texcoords[11].y)
//			normal = XMFLOAT3(normals[1].x, normals[1].y, normals[1].z)
// ......
// ------------------- Max texture coordinate index 23 -------------------------
//		"8/3/5" duplicated because texture coordinate index 3
//		has already been set: cubeVertices[2],
//		but the values will be the same
// cubeVertices[24] -
//			pos = XMFLOAT3(Vertices[7].x, Vertices[7].y, Vertices[7].z)
//			tex = XMFLOAT2(Texcoords[2].x, Texcoords[2].y)
//			normal = XMFLOAT3(normals[4].x, normals[4].y, normals[4].z)
// ......
// ------------------------------ Max size 36 ----------------------------------
//==============================================================================
*	@param		vertices		Vertex coordinates array data structure
*									loaded from standard OBJ file.
*	@param		texcoords		Texture coordinates array data structure
*									loaded from standard OBJ file.
*	@param		normals			Normal vectors array data structure
*									loaded from standard OBJ file.
*	@param		faces			Faces array data structure
*									loaded from standard OBJ file.
*	@param		numFaces		Number of face element * 3
*									= Number of indices to
*									generate the vertex buffer.
*	@return		void
*	@see		ShaderStructures::VertexType
*	@see		ShaderStructures::FaceType
*	@see		XMFLOAT3
*	@since		ver0003
*/
//void ModelObj::duplicateverticesPositionColorTexture(
//	VertexType *vertices,
//	VertexType *texcoords,
//	VertexType *normals,
//	FaceType *faces,
//	int numFaces) {
//
//	_RPT1(0, "this->textureCount : %d\n", this->textureCount);
//
//	// Main duplicate algorithm
//	for (int i = 0; i < numFaces; i++) {
//		//=====================================================================
//		// Triangular face's texture coordinate index - tIndex1
//		//=====================================================================
//		int texCoordIndex = (int)faces[i].tIndex1 - 1;
//		int vertexIndex = (int)faces[i].vIndex1 - 1;
//		int normalIndex = (int)faces[i].nIndex1 - 1;
//
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
//			= XMFLOAT3(
//				vertices[vertexIndex].x,
//				vertices[vertexIndex].y,
//				vertices[vertexIndex].z);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
//			= XMFLOAT3(1, 1, 1);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
//			= XMFLOAT2(
//				texcoords[texCoordIndex].x,
//				texcoords[texCoordIndex].y);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
//			= XMFLOAT3(
//				normals[normalIndex].x,
//				normals[normalIndex].y,
//				normals[normalIndex].z);
//
//		//=====================================================================
//		// Triangular face's texture coordinate index - tIndex2
//		//=====================================================================
//		texCoordIndex = (int)faces[i].tIndex2 - 1;
//		vertexIndex = (int)faces[i].vIndex2 - 1;
//		normalIndex = (int)faces[i].nIndex2 - 1;
//
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
//			= XMFLOAT3(
//				vertices[vertexIndex].x,
//				vertices[vertexIndex].y,
//				vertices[vertexIndex].z);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
//			= XMFLOAT3(1, 1, 1);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
//			= XMFLOAT2(
//				texcoords[texCoordIndex].x,
//				texcoords[texCoordIndex].y);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
//			= XMFLOAT3(
//				normals[normalIndex].x,
//				normals[normalIndex].y,
//				normals[normalIndex].z);
//
//		//=====================================================================
//		// Triangular face's texture coordinate index - tIndex3
//		//=====================================================================
//		texCoordIndex = (int)faces[i].tIndex3 - 1;
//		vertexIndex = (int)faces[i].vIndex3 - 1;
//		normalIndex = (int)faces[i].nIndex3 - 1;
//
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
//			= XMFLOAT3(
//				vertices[vertexIndex].x,
//				vertices[vertexIndex].y,
//				vertices[vertexIndex].z);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
//			= XMFLOAT3(1, 1, 1);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
//			= XMFLOAT2(
//				texcoords[texCoordIndex].x,
//				texcoords[texCoordIndex].y);
//		vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
//			= XMFLOAT3(
//				normals[normalIndex].x,
//				normals[normalIndex].y,
//				normals[normalIndex].z);
//	}
//
//	// Initialize original backup vertex buffer after vertex buffer init
//	for (int i = 0;
//		i < this->getVertexPositionColorTextureCoordNormalBufferCount();
//		i++) {
//		// Assign vertex coordinate values
//		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.x
//			= vertexPositionColorTextureCoordNormalBuffer[i].pos.x;
//		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.y
//			= vertexPositionColorTextureCoordNormalBuffer[i].pos.y;
//		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.z
//			= vertexPositionColorTextureCoordNormalBuffer[i].pos.z;
//
//		// Assign texture coordinate values
//		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.x
//			= vertexPositionColorTextureCoordNormalBuffer[i].tex.x;
//		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.y
//			= vertexPositionColorTextureCoordNormalBuffer[i].tex.y;
//	}
//
//	// Print to check all the vertices buffer is initialized 
//	for (int i = 0;
//		i < this->textureCount;
//		i++) {
//		_RPT1(0, "{ %ff,%ff,%ff, %ff,%ff },\n",
//			//_RPT1(0, "ModelObj::duplicateverticesPositionColorTexture::{ %f,%f,%f, %f,%f }\n",
//			vertexPositionColorTextureCoordNormalBuffer[i].pos.x,
//			vertexPositionColorTextureCoordNormalBuffer[i].pos.y,
//			vertexPositionColorTextureCoordNormalBuffer[i].pos.z,
//			vertexPositionColorTextureCoordNormalBuffer[i].tex.x,
//			vertexPositionColorTextureCoordNormalBuffer[i].tex.y);
//		//_RPT1(0, "original vertex buffer[%d] : (%f,%f,%f), (%f,%f)\n",
//		/*i,
//		originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.x,
//		originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.y,
//		originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.z,
//		originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.x,
//		originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.y);*/
//	}
//
//	//for (int i = 0; i < this->indicesCount; i++) {
//	//	if (i % 3 == 0) {
//	//		_RPT1(0, "\n", 0);
//	//	}
//	//	else {
//	//		_RPT1(0, "%f", this->texcoordIndices[i]);
//	//		_RPT1(0, ",", 0);
//	//	}
//	//}
//}
void ModelObj::duplicateverticesPositionColorTexture(
	VertexType *vertices,
	VertexType *texcoords,
	VertexType *normals,
	FaceType *faces,
	int numFaces) {

	// Init vertex buffer elements.
	for (int i = 0; i < this->indicesCount; i++) {
		vertexPositionColorTextureCoordNormalBuffer[i].isSet = false;
	}

	// Max texture coordinate index for duplication of the elements.
	// So the duplicated element will be appeneded to the array.
	int indexDuplication = this->textureCount;

	//==========================================================================
	// Because in 3D gaming engine the faces are rendered with triangular faces
	// where in 3D modelling engine the faces are rendered with rectangular
	// so we must export with "Tirangulate faces" option before importing to
	// this gaming engine.
	//
	// 1 of the face element holds the indices of the vertex buffer to form a
	//	triangular faces:
	//	Face element 1 : "f v1/t1/n1 v2/t2/n2 v3/t3/n3".
	// 3 of the vertex buffer elements combines into a triangular face: 
	//	Vertex buffer element 1: "v/t/n"
	//	Vertex buffer element 2: "v/t/n"
	//	Vertex buffer element 3: "v/t/n"
	// 2 of these triangular faces will be rendered into a 
	//	 rectangular faces which represents a "face" in 3D modelling engine.
	//
	// #########################################################################
	// #### Main point is that this vertex buffer element order matters!!! #####
	// #########################################################################
	//==========================================================================
	// Main duplicate vertex buffer element algorithm.
	for (int i = 0; i < numFaces; i++) {
		//======================================================================
		// Triangular face's texture coordinate index - tIndex1.
		// First vertex buffer element of current triangular face (v1/t1/n1).
		//======================================================================
		// "t" index value retrieved from the current face element "f v/t/n".
		int texCoordIndex = (int)faces[i].tIndex1 - 1;
		// "v" index value retrieved from the current face element "f v/t/n".
		int vertexIndex = (int)faces[i].vIndex1 - 1;
		// "n" index value retrieved from the "f v/t/n".
		int normalIndex = (int)faces[i].nIndex1 - 1;

		// If current vertex buffer element on the index is not initialized, 
		// then initialize with corresponding values "f v/t/n"
		if (!vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture  
			// coordinate array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);

			// Current vertex buffer initialized, so the vertex with the same 
			// index won't be overwritten but is duplicated on the maximum 
			// element counter.
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].isSet
				= true;
		}
		// If element has already been set, then initialize the current vertex 
		// buffer element with corresponding values 
		// BUT on the duplicated position to avoid overwriting to existing 
		// vertex buffer element.
		else if (vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture coordinate 
			// array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);

			// Must + 1 here,
			// because the actual index buffer is accessed with - 1.
			// because the index value indicate in the OBJ file starts with 1
			// not 0.
			faces[i].tIndex1 = indexDuplication + 1;
			//_RPT1(0, "faces[i].tIndex1 : %d\n", faces[i].tIndex1 + 1);
			indexDuplication++;
		}

		//======================================================================
		// Triangular face's texture coordinate index - tIndex2.
		// Second vertex buffer element of current triangular face (v2/t2/n2).
		//======================================================================
		texCoordIndex = (int)faces[i].tIndex2 - 1;
		vertexIndex = (int)faces[i].vIndex2 - 1;
		normalIndex = (int)faces[i].nIndex2 - 1;

		// If element is not set, then initialize with corresponding values
		if (!vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture  
			// coordinate array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);

			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].isSet
				= true;
		}
		// If element has already been set, 
		// then initialize with corresponding values 
		// but on the duplicated position 
		else if (vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture  
			// coordinate array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);
			// Must + 1 here,
			// because the actual index buffer is accessed with - 1.
			// because the index value indicate in the OBJ file starts with 1
			// not 0.
			faces[i].tIndex2 = indexDuplication + 1;

			indexDuplication++;
		}
		//======================================================================
		// Triangular face's texture coordinate index - tIndex3.
		//======================================================================
		texCoordIndex = (int)faces[i].tIndex3 - 1;
		vertexIndex = (int)faces[i].vIndex3 - 1;
		normalIndex = (int)faces[i].nIndex3 - 1;

		// If element is not set, then initialize with corresponding values
		if (!vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture  
			// coordinate array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);

			vertexPositionColorTextureCoordNormalBuffer[texCoordIndex].isSet
				= true;
		}
		// If element has already been set, 
		// then initialize with corresponding values 
		// but on the duplicated position 
		else if (vertexPositionColorTextureCoordNormalBuffer[texCoordIndex]
			.isSet) {
			// Set current vertex position coordinate with the value alculated 
			// by accessing the vertex coordinate inside main vertices
			// array on "v" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].pos
				= XMFLOAT3(
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);
			// Set current vertex color value (Default white (1,1,1)).
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].color
				= XMFLOAT3(1, 1, 1);
			// Set current vertex texture coordinate with the value calculated 
			// by accessing the texture coordinate inside main texture  
			// coordinate array on "t" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].tex
				= XMFLOAT2(
					texcoords[texCoordIndex].x,
					texcoords[texCoordIndex].y);
			// Set current vertex normal vector with the value calculated 
			// by accessing the normal vector inside main normal vectors
			// array on "n" index value retrieved from the "f v/t/n".
			vertexPositionColorTextureCoordNormalBuffer[indexDuplication].normal
				= XMFLOAT3(
					normals[normalIndex].x,
					normals[normalIndex].y,
					normals[normalIndex].z);

			// Must + 1 here,
			// because the actual index buffer is accessed with - 1.
			// because the index value indicate in the OBJ file starts with 1
			// not 0.
			faces[i].tIndex3 = indexDuplication + 1;
			//_RPT1(0, "faces[i].tIndex3 : %d\n", faces[i].tIndex3 + 1);
			indexDuplication++;
		}
		//_RPT1(0, "vertexPositionColorTextureCoordNormal[texCoordIndex].normal [%d] : 
		// %f, %f, %f\n", texCoordIndex, 
		// vertexPositionColorTextureCoordNormal[texCoordIndex].normal.x, 
		// vertexPositionColorTextureCoordNormal[texCoordIndex].normal.y, 
		// vertexPositionColorTextureCoordNormal[texCoordIndex].normal.z);
	}
	//==========================================================================
	// Initialize original backup vertex buffer after vertex buffer init.
	//==========================================================================
	for (int i = 0;
		i < this->getVertexPositionColorTextureCoordNormalBufferCount();
		i++) {
		// Assign vertex coordinate values
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.x
			= vertexPositionColorTextureCoordNormalBuffer[i].pos.x;
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.y
			= vertexPositionColorTextureCoordNormalBuffer[i].pos.y;
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.z
			= vertexPositionColorTextureCoordNormalBuffer[i].pos.z;

		// Assign texture coordinate values
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.x
			= vertexPositionColorTextureCoordNormalBuffer[i].tex.x;
		this->originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.y
			= vertexPositionColorTextureCoordNormalBuffer[i].tex.y;
	}

	//==========================================================================
	// Print to check all the vertices buffer is initialized 
	//==========================================================================
	for (int i = 0;
		i < this->getVertexPositionColorTextureCoordNormalBufferCount();
		i++) {
		_RPT1(0, "{ %ff,%ff,%ff, %ff,%ff },\n",
			//_RPT1(0, "ModelObj::duplicateverticesPositionColorTexture::{ %f,%f,%f, %f,%f }\n",
			vertexPositionColorTextureCoordNormalBuffer[i].pos.x,
			vertexPositionColorTextureCoordNormalBuffer[i].pos.y,
			vertexPositionColorTextureCoordNormalBuffer[i].pos.z,
			vertexPositionColorTextureCoordNormalBuffer[i].tex.x,
			vertexPositionColorTextureCoordNormalBuffer[i].tex.y);
		//_RPT1(0, "original vertex buffer[%d] : (%f,%f,%f), (%f,%f)\n",
			/*i,
			originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.x,
			originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.y,
			originalVertexPositionColorTextureCoordNormalBuffer[i]->pos.z,
			originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.x,
			originalVertexPositionColorTextureCoordNormalBuffer[i]->tex.y);*/
	}
}
//==============================================================================
// Indices array related.
// In 3D game engine, the primitive is drawn with triangles 
// so if it is a cube model = 6 faces = 12 indices
//==============================================================================
/*
*	Getter - Member variable "indicesCount".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "indicesCount".
*		- Number of indices calculated from standard OBJ file
*		  eg. Number of faces * 3 = Number of indices,
*			  Cube --> 6 faces --> 12 traingle faces --> 36 indices.
*		  eg. f	v/t/n v1/t1/n1 v2/t2/n2 --> Form a triangle
*			  --> 3 indices v,v1,v2 ...
*	@return		Return current ModelObj object's
*					member variable "indicesCount"
*					integer value.
*	@since		ver0003
*/
int ModelObj::getIndicesCount() {
	return this->indicesCount;
}

/*
*	Getter - Member variable "texcoordIndices".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "texcoordIndices".
*		- Array of texture coordinate indices calculated from
*		  face element in standard OBJ file
*		  through function texcoordsIndicesCalcFromFacesbuffer()
*		  eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [t, t1, t2 ... ].
*	@return		Return current ModelObj object's
*					member variable "texcoordIndices"
*					unsigned short array pointer.
*	@since		ver0003
*/
DWORD *ModelObj::getTexcoordsIndices() {
	return this->texcoordIndices;
}

/*
*	Generates and initialize current ModelObj object's
*		texture coordinates' indices array data structure.
*	<p>
*	This function is the init fucntion for current ModelObj object's
*		member variable "texcoordIndices".
*		- Array of texture coordinate indices calculated from face element
*		  in standard OBJ file
*		eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [t, t1, t2 ... ].
*	 Calculates and arranges the texture coordinate indices buffer
*		from faces array data structure loaded from standard OBJ file.
*		eg. Faces : v/t/c, v1/t1/c1, v2/t2/c2 ... --> Index buffer : t, t1, t2, t3 ...
*	@param		faces		Faces array data structure
*								loaded from standard OBJ file.
*	@param		numFaces	Size of the faces array data structure
*								loaded from standard OBJ file.
*	@return		void
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
void ModelObj::texcoordsIndicesCalcFromFacesbuffer(
	FaceType *faces, int numFaces) {
	if (faces == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::ModelObj::texcoordsIndicesCalcFromFacesbuffer::Faces array is NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	if (numFaces <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::ModelObj::texcoordsIndicesCalcFromFacesbuffer::Size of the faces array is not greater than 0!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	int tempIndex = 0;
	// Setup triangle indices corresponding to texture coordinate indices
	// converted from model loader
	for (int i = 0; i < numFaces; i++) {
		for (int j = tempIndex; j < tempIndex + 3; j++) {
			this->texcoordIndices[j] = (int)faces[i].tIndex1 - 1;
			j++;

			this->texcoordIndices[j] = (int)faces[i].tIndex2 - 1;
			j++;

			this->texcoordIndices[j] = (int)faces[i].tIndex3 - 1;
			/*_RPT1(0, "this->texcoordIndices[%d] : %d\n", 
			 j, this->texcoordIndices[j]);*/
		}
		tempIndex += 3;
	}
}

/*
*	Getter - Member variable "vertexIndices".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "vertexIndices".
*		- Array of vertex coordinate indices calculated
*		  from face element in standard OBJ file
*		  through function vertexIndicesCalcFromFacesbuffer()
*		  eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [v, v1, v2 ... ].
*	@return		Return current ModelObj object's
*					member variable "vertexIndices"
*					unsigned short array pointer.
*	@since		ver0003
*/
DWORD *ModelObj::getVertexIndices() {
	return this->vertexIndices;
}

/*
*	Generates and initialize current ModelObj object's
*		vertex coordinates' indices array data structure.
*	<p>
*	This function is the init fucntion for current ModelObj object's
*		member variable "vertexIndices".
*		- Array of vertex corodinate indices calculated from face element
*		  in standard OBJ file
*		eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [v, v1, v2 ... ]).
*	 Calculates and arranges the vertex coordinate indices buffer
*		from faces array data structure loaded from standard OBJ file.
*		eg. Faces : v/t/c, v1/t1/c1, v2/t2/c2 ... --> Index buffer : v, v1, v2, v3 ...
*	@param		faces		Faces array data structure
*								loaded from standard OBJ file.
*	@param		numFaces	Size of the faces array data structure
*								loaded from standard OBJ file.
*	@return		void
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
void ModelObj::vertexIndicesCalcFromFacesbuffer(
	FaceType *faces, int numFaces) {
	if (faces == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::ModelObj::vertexIndicesCalcFromFacesbuffer::Faces array is NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	if (numFaces <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::ModelObj::vertexIndicesCalcFromFacesbuffer::Size of the faces array is not greater than 0!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	int tempIndex = 0;
	// Setup triangle indices corresponding to vertex coordinate indices
	// converted from model loader
	for (int i = 0; i < numFaces; i++) {
		for (int j = tempIndex; j < tempIndex + 3; j++) {
			this->vertexIndices[j] = (int)faces[i].vIndex1 - 1;
			j++;

			this->vertexIndices[j] = (int)faces[i].vIndex2 - 1;
			j++;

			this->vertexIndices[j] = (int)faces[i].vIndex3 - 1;
			//_RPT1(0, "this->texcoordIndices[%d] : %d\n",
			// j, this->texcoordIndices[j]);
		}
		tempIndex += 3;
	}
	//_RPT1(0, "\n ", 0);
}

/*
*	Getter - Member variable "normalIndices".
*	<p>
*	This function is the getter for current ModelObj object's
*		member variable "normalIndices".
*		- Array of normal vector indices calculated
*		  from face element in standard OBJ file
*		  through function normalIndicesCalcFromFacesbuffer()
*		  eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [n, n1, n2 ... ].
*	@return		Return current ModelObj object's
*					member variable "normalIndices"
*					unsigned short array pointer.
*	@since		ver0003
*/
DWORD *ModelObj::getNormalIndices() {
	return this->normalIndices;
}

/*
*	Generates and initialize current MyModelObj object's normal vectors'
*		indices array data structure.
*	<p>
*	This function is the init fucntion for current MyModelObj object's
*		member variable "normalIndices".
*		- Array of normal vector indices calculated from face element
*		  in standard OBJ file
*		eg. f v/t/n v1/t1/n1 v2/t2/n2 --> [n, n1, n1, ... ]).
*	Calculates and arranges the normal vector indices buffer
*		from faces array data structure loaded from standard OBJ file.
*		eg. Faces : v/t/c, v1/t1/c1, v2/t2/c2 ... --> Index buffer : n, n1, n1, n3 ...
*	@param		faces		Faces array data structure
*								loaded from standard OBJ file.
*	@param		numFaces	Size of the faces array data structure
*								loaded from standard OBJ file.
*	@return		void
*	@see		ShaderStructures::FaceType
*	@since		ver0003
*/
void ModelObj::normalIndicesCalcFromFacesbuffer(
	FaceType *faces, int numFaces) {
	if (faces == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelObj::normalIndicesCalcFromFacesbuffer::Faces array is NULL!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}
	if (numFaces <= 0) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelObj::normalIndicesCalcFromFacesbuffer::Size of the faces array is not greater than 0!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
	}

	int tempIndex = 0;
	// Setup triangle indices corresponding to normal vector indices 
	// converted from model loader
	for (int i = 0; i < numFaces; i++) {
		for (int j = tempIndex; j < tempIndex + 3; j++) {
			this->normalIndices[j] = (int)faces[i].nIndex1 - 1;
			j++;

			this->normalIndices[j] = (int)faces[i].nIndex2 - 1;
			j++;

			this->normalIndices[j] = (int)faces[i].nIndex3 - 1;
			//_RPT1(0, "this->texcoordIndices[%d] : %d\n",
			// j, this->texcoordIndices[j]);
		}
		tempIndex += 3;
	}
}
