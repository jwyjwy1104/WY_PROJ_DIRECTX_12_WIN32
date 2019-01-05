#pragma once

#include "ShaderStructures.h"

// Class description: 
//		This class represents a standard OBJ file default exported through 
//		Blender, which holds all the information as a model object.
//		========================================================================
//		OBJ: Standard OBJ file exported through other 3D engine like Blender as
//				default ".obj" extension.
//		========================================================================
class ModelObj {
private:
	// "this" OBJ file's directory path.
	char *currentObjDirectoyPath;

	// "this" OBJ model name.
	std::string modelName;

	//=========================================================================
	// Material file name. (eg. mtllib indicated in standard OBJ file)
	// The material file path relative to "this" OBJ file.
	//=========================================================================
	char *materialFileName;

	// Vertices(v) 
	// - The data structure to hold the "v" data loaded from OBJ file.
	VertexType *vertices;
	int vertexCount; // Number of elements inside "vertices" array

	// Texture coordinates (vt) 
	// - The data structure to hold the "vt" data loaded from OBJ file.
	VertexType *texcoords;
	int textureCount; // Number of elements inside "texcoords" array.

	// Normals (vn) 
	// - The data structure to hold the "vn" data loaded from OBJ file.
	VertexType *normals;
	int normalCount; // Number of elements inside "normals" array.

	// Faces (f) 
	// - The data structure to hold the "f" data loaded from OBJ file.
	FaceType *faces;
	int faceCount; // Number of elements inside "faces" array.

	// Number of indices of "this" model.
	int indicesCount;

	//==========================================================================
	// Main data structure related.
	//==========================================================================
	// Main data structrue to hold the array of elements 
	// which has vertex position coordinate, texture coordinate and 
	// vertex normal vector to be used for rendering.
	VertexPositionColorTextureCoordNormal
		*vertexPositionColorTextureCoordNormalBuffer;

	// Main vertex buffer size to be used for rendering
	// Number of elements stored in this 
	// "vertexPositionColorTextureCoordNormalBuffer" data structure.
	int vertexPositionColorTextureCoordNormalBufferCount;

	// Back up main data structure for extra features. (eg. Reset position)
	VertexPositionColorTextureCoordNormal
		**originalVertexPositionColorTextureCoordNormalBuffer;

	//==========================================================================
	// Indices array related.
	// In 3D game engine, the primitive is drawn with triangles 
	// so if it is a cube model = 6 faces = 12 indices
	//==========================================================================
	// Vertex indices array generated from faces array. (eg. v/t/n --> v)
	DWORD *vertexIndices;
	// Texture indices array generated from faces array. (eg. v/t/n --> t)
	DWORD *texcoordIndices;
	// Normal indices array generated from faces array. (eg. v/t/n --> n)
	DWORD *normalIndices;
public:
	// General constructor.
	ModelObj(
		int vertexCount,	// Number of "v" element in standard OBJ file.
		int textureCount,	// Number of "vt" element in standard OBJ file.
		int normalCount,	// Number of "vn" element in standard OBJ file.
		int faceCount);		// Number of "f" element in standard OBJ file.

	// Destructor.
	~ModelObj();

	//==========================================================================
	// Directory path of the OBJ file.
	//==========================================================================
	// Member variable "currentObjDirectoyPath" getter.
	char *getCurrentObjDirectoyPath();
	// Member variable "currentObjDirectoyPath" setter.
	void setCurrentObjDirectoyPath(char *currentObjDirectoyPath);

	//==========================================================================
	// Model name.
	//==========================================================================
	// Member variable "modelName" getter.
	std::string getModelName();

	//==========================================================================
	// Material file name. (eg. mtllib indicated in standard OBJ file)
	// The material file path relative to "this" OBJ file.
	//==========================================================================
	// Member variable "materialFileName" getter.
	char *getMaterialFileName();
	// Member variable "materialFileName" setter.
	void setMaterialFileName(char *materialFileName);

	//==========================================================================
	// Vertices(v) - The data structure to hold the "v" data loaded from OBJ file.
	//==========================================================================
	// Member variable "vertices", "vertexCount" getter.
	VertexType *getModelVertices();
	// Member variable "vertices", "vertexCount" setter.
	void setModelVertices(VertexType *vertices);
	// Member variable "vertices", "vertexCount" copier.
	void copyModelVertices(VertexType *vertices, int vertexCount);

	// Get number of elements inside "vertices" array.
	int getVertexCount();

	//==========================================================================
	// Texture coordinates (vt) 
	// - The data structure to hold the "vt" data loaded from OBJ file.
	//==========================================================================
	// Member variable "texcoords", "textureCount" getter.
	VertexType *getTexcoords();
	// Member variable "texcoords", "textureCount" setter.
	void setTexcoords(VertexType *texcoords);
	// Member variable "texcoords", "textureCount" copier.
	void copyTexcoords(VertexType *texcoords, int textureCount);

	// Get number of elements inside "texcoords" array.
	int getTextureCount();

	//==========================================================================
	// Normals (vn) 
	// - The data structure to hold the "vn" data loaded from OBJ file.
	//==========================================================================
	// Member variable "normals" getter.
	VertexType *getNormals();
	// Member variable "normals" setter.
	void setNormals(VertexType *normals);
	// Member variable "normals" copier.
	void copyNormals(VertexType *normals, int normalCount);
	
	// Get number of elements inside "normals" array.
	int getNormalCount();

	//==========================================================================
	// Faces (f) - The data structure to hold the "f" data loaded from OBJ file.
	//==========================================================================
	// Member variable "faces" getter.
	FaceType *getFaces();
	// Member variable "faces" setter.
	void setFaces(FaceType *faces);
	// Member variable "faces" copier.
	void copyFaces(FaceType *faces, int faceCount);

	// Get number of elements inside "faces" array.
	int getFaceCount();

	//==========================================================================
	// Vertex buffer = Faces (f) 
	//	--> [Vertex, Texture coordinate, Normal (v/t/n) ... ]
	//  - The data structure to hold the converted and calculated data 
	//	  that is actually going to be uploaded to GPU for rendering.
	//==========================================================================
	// Main data structure member variable 
	// "vertexPositionColorTextureCoordNormalBuffer" getter.
	VertexPositionColorTextureCoordNormal
		*getVertexPositionColorTextureCoordNormalBuffer();

	// Main data structure member variable 
	// "vertexPositionColorTextureCoordNormalBuffer" setter.
	void setVertexPositionColorTextureCoordNormalBuffer(
		VertexPositionColorTextureCoordNormal
		*vertexPositionColorTextureCoordNormalBuffer);

	// Main data structure member variable 
	// "vertexPositionColorTextureCoordNormalBuffer" copier.
	void copyVertexPositionColorTextureCoordNormalBuffer(
		VertexPositionColorTextureCoordNormal
		*vertexPositionColorTextureCoordNormalBuffer,
		int vertexPositionColorTextureCoordNormalBufferCount);

	// Main vertex buffer size to be used for rendering
	// Number of elements stored in this 
	// "vertexPositionColorTextureCoordNormalBuffer" data structure.
	int getVertexPositionColorTextureCoordNormalBufferCount();

	// Backed up main data structure  member variable 
	// "originalVertexPositionColorTextureCoordNormalBuffer" getter.
	VertexPositionColorTextureCoordNormal
		**getOriginalVertexPositionColorTextureCoordNormalBuffer();

	//==========================================================================
	// Duplicate vertex buffer element algorithm
	//==========================================================================
	// Main function to duplciate the vertices inside the vertex buffer loaded 
	// from OBJ according to the texture coordinate indices or else there
	// won't be enough vertices to render a perfect primitive.
	// Algorithm is explained in detail above the function body.
	void duplicateverticesPositionColorTexture(
		VertexType *vertices,	// Vertices array.
		VertexType *texcoords,  // Texture coordinates array.
		VertexType *normals,	// Noraml vectors array.
		FaceType *faces,		// Faces indices array.
		int numFaces);			// Number of faces in primitive.

	//==========================================================================
	// Indices array related.
	// In 3D game engine, the primitive is drawn with triangles 
	// so if it is a cube model = 6 faces = 12 indices
	//==========================================================================
	// Member variable "indicesCount" getter.
	int getIndicesCount();

	// Member variable "texcoordIndices" getter.
	DWORD *getTexcoordsIndices();
	// Member variable "texcoordIndices" setter by calculating from faces array.
	void texcoordsIndicesCalcFromFacesbuffer(FaceType *faces, int numFaces);

	// Member variable "vertexIndices" getter.
	DWORD *getVertexIndices();
	// Member variable "vertexIndices" setter by calculating from faces array.
	void vertexIndicesCalcFromFacesbuffer(FaceType *faces, int numFaces);

	// Member variable "normalIndices" getter.
	DWORD *getNormalIndices();
	// Member variable "normalIndices" setter by calculating from faces array.
	void normalIndicesCalcFromFacesbuffer(FaceType *faces, int numFaces);
};
