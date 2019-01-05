// File name: [MyModelMtl.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4bV9TMnU2cE5rdU0%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4bV9TMnU2cE5rdU0
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ampkd203ZnZYQzg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ampkd203ZnZYQzg
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4ZXoxWHRZWS1xY1k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4ZXoxWHRZWS1xY1k
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom MTL file, representing a model's material.
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0002:WY:201707101930]
//------------------------------------------------------------------------------
// File name: [MyModelMtl.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4b0JIUmZNM2dpV0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4b0JIUmZNM2dpV0k
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom MTL file, representing a model's material.
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//------------------------------------------------------------------------------
// [rev0001:WY:201707012350]
//------------------------------------------------------------------------------
// File name: [MyModelMtl.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4b0JIUmZNM2dpV0k%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4b0JIUmZNM2dpV0k
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the properties and information 
//			loaded from an custom MTL file, representing a model's material.
// - [Comments]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [MTL]:
//		Caution!! My custom Blender exported MTL file's format 
//		is adjusted for certain purposes...
//		- First, the MTL element tags' naming convention has changed 
//		  for better understanding and organization. (eg. d = mtl_alpha)
//			- Because the actual Blender MTL value names 
//			  and exported element tags' names had not much relations, 
//			  so that it is not easy to organize them. 
//			  (eg. d = alpha, Ni = Specular hardness ... )
//		- Second, an element value (eg. Ka) is separated 
//		  and saved with multiple element values 
//		  before conversion. 
//		  (eg. Ka = mtl_mirror_color * mtl_ambient)
//			- Because I thought it will be more organized to 
//			  import with more specific element values.
// - [Documents]
//		- MTL 
//			- Naming convention and format changes summary: 
//			  https://docs.google.com/document/d/1sAjWaWN_ztn145rTd6DAV8p5tEHGPs-WhCNasE7ayG4/edit#bookmark=id.px6wpkoj4fe1
// - [Resources]
//		- Blender MTL elements Ka, Kd, Ks, d, Ns, Ni, (illum not explained):
//			 https://blender.stackexchange.com/questions/26088/obj-export-is-too-dark
//		- Illum: 
//			  http://paulbourke.net/dataformats/mtl/ 
//		- MTL elements tag:
//			  http://nendowingsmirai.yuku.com/topic/1723/Wavefront-mtl-file-format-info#.WQKKxNLyvIU
//			  https://people.cs.clemson.edu/~dhouse/courses/405/docs/brief-mtl-file-format.html
//			  http://casual-effects.blogspot.ca/2012/01/translucency-in-obj-mtl-files.html 
//		- Importer example illum processing:
//			  https://github.com/trevortomesh/Blender-Python-Learning-Environment/blob/master/BPyLE/lin/blenderPyLE-2.64a-linux64/2.64/scripts/addons/io_scene_obj/import_obj.py
// - [Framework description]
//		1. MyModelLoader::myObjMtlLoader() - OBJ file path --> Load OBJ file 
//			--> Get MTL file name from OBJ file --> Relative MTL file path 
//			--> Load MTL file --> MyModelObj + MyModelMtl = MySpecialModelObj
//			2. MyModelLoader::myObjLoader() - Load OBJ file --> MyModelObj 
//				2-1. MyModelLoader::GetModelFilename() 
//					- File check
//				2-2. MyModelLoader::ReadFileCounts() 
//					- Read number of datas for data structure initialization
//				2-3. MyModelLoader::LoadDataStructures() 
//					- MyModelObj initialization
//				[CU, CF, v, vn, vt, f]
//			3. Using "mtllib" element provided in OBJ file to 
//				load MTL file on relative directory path
//			4. MyModelLoader::myMtlLoader() - Load MTL file --> MyModelMtl
//				[mtl_material_count, mtl_material_name,
//					mtl_mirror_color,mtl_ambient,
//					mtl_diffuse_color,mtl_diffuse_intensity,
//					mtl_specular_color, mtl_specular_intensity, 
//					mtl_specular_hardness, 
//					mtl_emit, mtl_raytrace_transparency_ior, mtl_alpha, 
//					mtl_texture_map_image_path]
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
//------------------------------------------------------------------------------
// [rev0000:WY:201706291730]
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
#include "ModelMtl.h"
#include "MyModelMtl.h"

// Default constructor
MyModelMtl::MyModelMtl() : ModelMtl() {
	// mtl_material_count - Number of material in MTL
	this->materialCount = 0;

	//==========================================================================
	// Single material from Blender 
	//==========================================================================

	// mtl_material_name - Name of the material in MTL
	this->materialName = NULL;

	// mtl_mirror_color, mtl_ambient  
	// (Ka = Ambient color * Ambient intensity)
	this->materialMirrorColor = XMFLOAT3(0, 0, 0);
	this->materialAmbient = 0.0f;

	// mtl_diffuse_color, mtl_diffuse_intensity 
	// (Kd = Diffuse color * Diffuse intensity)
	this->materialDiffuseColor = XMFLOAT3(0, 0, 0);
	this->materialDiffuseIntensity = 0;

	// mtl_specular_color , mtl_specular_intensity 
	// (Ks = Specular color * Specular intensity)
	this->materialSpecularColor = XMFLOAT3(0, 0, 0);
	this->materialSpecularIntensity = 0.0f;

	// mtl_specular_hardness 
	// Shininess, Specular exponent (Larger = More focus)
	// (Ns = Specular hardness / 511 * 1000)
	this->materialSpecularHardness = 0.0f;

	// mtl_emit 
	// (Ke = Emissive color)
	this->materialEmit = 0.0f;

	// mtl_raytrace_transparency_ior  
	// (Ni = Refraction index)
	this->materialRaytraceTransparencyIOR = 0.0f;

	// mtl_alpha (d = Alpha (Dissolve))
	this->materialAlpha = 0.0f;

	// mtl_texture_map_image_path  
	// (map_K = Texture image file path)
	this->materialTextureMapImagePath = new char[BUFSIZ]();
	std::fill(
		this->materialTextureMapImagePath,
		this->materialTextureMapImagePath + BUFSIZ,
		0);
}

// Destructor
MyModelMtl::~MyModelMtl() {
	// mtl_material_name - Name of the material in MTL
	if (this->materialName != NULL) {
		this->materialName = NULL;
	}
	this->materialCount = 0;

	// mtl_mirror_color, mtl_ambient  
	// (Ka = Ambient color * Ambient intensity)
	this->materialMirrorColor = XMFLOAT3(0, 0, 0);
	this->materialAmbient = 0.0f;

	// mtl_diffuse_color, mtl_diffuse_intensity 
	// (Kd = Diffuse color * Diffuse intensity)
	this->materialDiffuseColor = XMFLOAT3(0, 0, 0);
	this->materialDiffuseIntensity = 0;

	// mtl_specular_color , mtl_specular_intensity 
	// (Ks = Specular color * Specular intensity)
	this->materialSpecularColor = XMFLOAT3(0, 0, 0);
	this->materialSpecularIntensity = 0.0f;

	// mtl_specular_hardness 
	// Shininess, Specular exponent (Larger = More focus)
	// (Ns = Specular hardness / 511 * 1000)
	this->materialSpecularHardness = 0.0f;

	// mtl_emit (Ke = Emissive color)
	this->materialEmit = 0.0f;

	// mtl_raytrace_transparency_ior  
	// (Ni = Refraction index)
	this->materialRaytraceTransparencyIOR = 0.0f;

	// mtl_alpha (d = Alpha (Dissolve))
	this->materialAlpha = 0.0f;

	// mtl_texture_map_image_path  
	// (map_K = Texture image file path)
	if (this->materialTextureMapImagePath != NULL) {
		delete this->materialTextureMapImagePath;
		this->materialTextureMapImagePath = NULL;
	}
}



//==============================================================================
// Number of material indicated in MTL file
//==============================================================================
/*
*	Getter - Member variable "materialCount".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialCount".
*		- Number of materials indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_material_count].
*	@return		Return current MyModelMtl object's
*					member variable "materialCount"
*					integer value.
*	@since		ver0003
*/
int MyModelMtl::getMaterialCount() {
	return this->materialCount;
}
/*
*	Setter - Member variable "materialCount".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialCount".
*		- Number of materials indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_material_count].
*	@param		materialCount		Number of materials integer value
*										to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialCount(int materialCount) {
	this->materialCount = materialCount;
}

//==============================================================================
// Name of the material indicated in MTL file
//==============================================================================
/*
*	Getter - Member variable "materialName".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialName".
*		- Material name C-String value when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_material_name].
*	@return		Return current MyModelMtl object's
*					member variable "materialName"
*					C-String.
*	@since		ver0003
*/
char *MyModelMtl::getMaterialName() {
	return this->materialName;
}
/*
*	Setter - Member variable "materialName".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialName".
*		- Material name C-String value when
*		  initialized through MyModelLoader.
*	Element tag in MTL file - [mtl_material_name].
*	@param		materialName		Material name C-String value
*									to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialName(char *materialName) {
	this->materialName = new char[BUFSIZ]();
	std::fill(this->materialName, this->materialName + BUFSIZ, 0);
	strcpy(this->materialName, materialName);
}

//==============================================================================
// Ambient color of the material indicated in MTL file
// mtl_mirror_color (Ka = Ambient color * Ambient intensity)
//==============================================================================
/*
*	Getter - Member variable "materialMirrorColor".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialMirrorColor".
*		- Material ambient color value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_mirror_color].
*	@return		Return current MyModelMtl object's
*					member variable "materialMirrorColor"
*					XMFLOAT3 value.
*	@see		XMFLOAT3
*	@since		ver0003
*/
XMFLOAT3 MyModelMtl::getMaterialMirrorColor() {
	return this->materialMirrorColor;
}
/*
*	Setter - Member variable "materialMirrorColor".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialMirrorColor".
*		- Material ambient color value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_mirror_color].
*	@param		materialMirrorColor		Material ambient color
*										XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialMirrorColor(XMFLOAT3 materialMirrorColor) {
	this->materialMirrorColor = materialMirrorColor;
}

//==============================================================================
// Ambient intensity of the material indicated in MTL file
// mtl_ambient (Ka = Ambient color * Ambient intensity)
//==============================================================================
/*
*	Getter - Member variable "materialAmbient".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialAmbient".
*		- Material ambient intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_ambient].
*	@return		Return current MyModelMtl object's
*					member variable "materialAmbient"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialAmbient() {
	return this->materialAmbient;
}
/*
*	Setter - Member variable "materialAmbient".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialAmbient".
*		- Material ambient intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_ambient].
*	@param		materialAmbient		Material ambient intensity
*									float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialAmbient(float materialAmbient) {
	this->materialAmbient = materialAmbient;
}

//==============================================================================
// Diffuse color of the material indicated in MTL file
// mtl_diffuse_color (Kd = Diffuse color * Diffuse intensity)
//==============================================================================
/*
*	Getter - Member variable "materialDiffuseColor".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialDiffuseColor".
*		- Material diffuse color value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_diffuse_color].
*	@return		Return current MyModelMtl object's
*					member variable "materialDiffuseIntensity"
*					XMFLOAT3 value.
*	@see		XMFLOAT3
*	@since		ver0003
*/
XMFLOAT3 MyModelMtl::getMaterialDiffuseColor() {
	return this->materialDiffuseColor;
}
/*
*	Setter - Member variable "materialDiffuseColor".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialDiffuseColor".
*		- Material diffuse color value indicated in MTL file when
*		initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_diffuse_color].
*	@param		materialDiffuseColor		Material diffuse color
*											XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialDiffuseColor(XMFLOAT3 materialDiffuseColor) {
	this->materialDiffuseColor = materialDiffuseColor;
}

//==============================================================================
// Diffues intensity of the material indicated in MTL file
// mtl_diffuse_intensity (Kd = Diffuse color * Diffuse intensity)
//==============================================================================
/*
*	Getter - Member variable "materialDiffuseIntensity".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialDiffuseIntensity".
*		- Material diffuse intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_diffuse_intensity].
*	@return		Return current MyModelMtl object's
*					member variable "materialDiffuseIntensity"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialDiffuseIntensity() {
	return this->materialDiffuseIntensity;
}
/*
*	Setter - Member variable "materialDiffuseIntensity".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialDiffuseIntensity".
*		- Material diffuse intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_diffuse_intensity].
*	@param		materialDiffuseIntensity		Material diffuse intensity
*												float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialDiffuseIntensity(float materialDiffuseIntensity) {
	this->materialDiffuseIntensity = materialDiffuseIntensity;
}

//==============================================================================
// Specular color of the material indicated in MTL file
// mtl_specular_color (Ks = Specular color * Specular intensity)
//==============================================================================
/*
*	Getter - Member variable "materialSpecularColor".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialSpecularColor".
*		- Material specular color value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_color].
*	@return		Return current MyModelMtl object's
*					member variable "materialSpecularIntensity"
*					XMFLOAT3 value.
*	@see		XMFLOAT3
*	@since		ver0003
*/
XMFLOAT3 MyModelMtl::getMaterialSpecularColor() {
	return this->materialSpecularColor;
}
/*
*	Setter - Member variable "materialSpecularColor".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialSpecularColor".
*		- Material sepcular color value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_color].
*	@param		materialSpecularColor		Material specular color
*											XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialSpecularColor(XMFLOAT3 materialSpecularColor) {
	this->materialSpecularColor = materialSpecularColor;
}

//==============================================================================
// Specular intensity of the material indicated in MTL file
// mtl_specular_intensity (Ks = Specular color * Specular intensity)
//==============================================================================
/*
*	Getter - Member variable "materialSpecularIntensity".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialSpecularIntensity".
*		- Material specular intensity value indicated in MTL file when
*		initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_intensity].
*	@return		Return current MyModelMtl object's
*					member variable "materialSpecularIntensity"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialSpecularIntensity() {
	return this->materialSpecularIntensity;
}
/*
*	Setter - Member variable "materialSpecularIntensity".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialSpecularIntensity".
*		- Material sepcular intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_intensity].
*	@param		materialDiffuseIntensity		Material specular intensity
*												float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialSpecularIntensity(
	float materialSpecularIntensity) {
	this->materialSpecularIntensity = materialSpecularIntensity;
}


//==============================================================================
// Specular hardness of the material indicated in MTL file
// mtl_specular_hardness 
// Shininess, Specular exponent (Larger = More focus)
// (Ns = Specular hardness / 511 * 1000)
//==============================================================================
/*
*	Getter - Member variable "materialSpecularHardness".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialSpecularHardness".
*		- Material specular hardness value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_hardness].
*	@return		Return current MyModelMtl object's
*					member variable "materialSpecularHardness"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialSpecularHardness() {
	return this->materialSpecularHardness;
}
/*
*	Setter - Member variable "materialSpecularHardness".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialSpecularHardness".
*		- Material sepcular hardness value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_specular_hardness].
*	@param		materialSpecularHardness		Material specular hardness
*												float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialSpecularHardness(
	float materialSpecularHardness) {
	this->materialSpecularHardness = materialSpecularHardness;
}

//==============================================================================
// Emissive color of the material indicated in MTL file
// mtl_emit (Ke = Emissive color)
//==============================================================================
/*
*	Getter - Member variable "materialEmit".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialEmit".
*		- Material emissive intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_emit].
*	@return		Return current MyModelMtl object's
*					member variable "materialEmit"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialEmit() {
	return this->materialEmit;
}
/*
*	Setter - Member variable "materialEmit".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialEmit".
*		- Material emissive intensity value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_emit].
*	@param		materialSpecularHardness		Material emissive intensity
*												float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialEmit(float materialEmit) {
	this->materialEmit = materialEmit;
}

//==============================================================================
// Refraction index of the material indicated in MTL file
// mtl_raytrace_transparency_ior  (Ni = Refraction index)
//==============================================================================
/*
*	Getter - Member variable "materialRaytraceTransparencyIOR".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialRaytraceTransparencyIOR".
*		- Material refraction index value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_raytrace_transparency_ior].
*	@return		Return current MyModelMtl object's
*					member variable "materialRaytraceTransparencyIOR"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialRaytraceTransparencyIOR() {
	return this->materialRaytraceTransparencyIOR;
}
/*
*	Setter - Member variable "materialRaytraceTransparencyIOR".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialRaytraceTransparencyIOR".
*		- Material refraction index value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_raytrace_transparency_ior].
*	@param		materialRaytraceTransparencyIOR		Material refraction index
*													float value to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialRaytraceTransparencyIOR(
	float materialRaytraceTransparencyIOR) {
	this->materialRaytraceTransparencyIOR = materialRaytraceTransparencyIOR;
}

//==============================================================================
// Alpha value of the material indicated in MTL file
// mtl_alpha  (d = Alpha (Dissolve))
//==============================================================================
/*
*	Getter - Member variable "materialAlpha".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialAlpha".
*		- Material alpha value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_alpha].
*	@return		Return current MyModelMtl object's
*					member variable "materialAlpha"
*					float value.
*	@since		ver0003
*/
float MyModelMtl::getMaterialAlpha() {
	return this->materialAlpha;
}
/*
*	Setter - Member variable "materialAlpha".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialAlpha".
*		- Material alpha value indicated in MTL file when
*		  initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_alpha].
*	@param		materialAlpha		Material alpha float value
*									to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialAlpha(float materialAlpha) {
	this->materialAlpha = materialAlpha;
}

//==============================================================================
// UV mapping texture image file path of the material indicated in MTL file
// mtl_texture_map_image_path  (map_K = Texture image file path)
//==============================================================================
/*
*	Getter - Member variable "materialTextureMapImagePath".
*	<p>
*	This function is the getter for current MyModelMtl object's
*		member variable "materialTextureMapImagePath".
*	v - Material UV mapping texture image file path C-string indicated
*		in MTL file when initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_texture_map_image_path].
*	@return		Return current MyModelMtl object's
*					member variable "materialTextureMapImagePath"
*					C-string value.
*	@since		ver0003
*/
char *MyModelMtl::getMaterialTextureMapImagePath() {
	return this->materialTextureMapImagePath;
}
/*
*	Setter - Member variable "materialTextureMapImagePath".
*	<p>
*	This function is the setter for current MyModelMtl object's
*		member variable "materialTextureMapImagePath".
*		- Material UV mapping texture image file path C-string indicated
*		  in MTL file when initialized through MyModelLoader from MTL file.
*	Element tag in MTL file - [mtl_texture_map_image_path].
*	@param		materialTextureMapImagePath		Material UV mapping texture
*												image file path C-string
*												to set with.
*	@return		void
*	@since		ver0003
*/
void MyModelMtl::setMaterialTextureMapImagePath(
	char *materialTextureMapImagePath) {
	strcpy(this->materialTextureMapImagePath, materialTextureMapImagePath);
}