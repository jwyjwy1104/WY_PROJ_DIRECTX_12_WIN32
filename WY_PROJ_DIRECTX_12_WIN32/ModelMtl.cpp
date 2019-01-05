// File name: [ModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4VnRlZFh6RnBUb3M%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4VnRlZFh6RnBUb3M
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4UHJLQUZOUjhWNXc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4UHJLQUZOUjhWNXc
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cU1renhaZDFOdWc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cU1renhaZDFOdWc
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information loaded from a standard MTL file 
//			through ModelLoader.
// - [Comments]:
//		UML, UC, SD, diagrams updated.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//-----------------------------------------------------------------------------
// [rev0002:WY:201707101930]
//-----------------------------------------------------------------------------
// File name: [ModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0174: 2017-07-01
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information loaded from a standard MTL file 
//			through ModelLoader.
// - [Comments]:
//		Adding NULL check code in destructor prevents double deletion.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0012
//-----------------------------------------------------------------------------
// [rev0001:WY:201707020000]
//-----------------------------------------------------------------------------
// File name: [ModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class holds all the information loaded from a standard MTL file 
//			through ModelLoader.
//	- [MTL] Standard MTL.
//		- Material count.
//		- newmtl.
//		- d.
//		- Ns.
//		- Ni.
//		- Ka.
//		- Kd.
//		- Ks.
//		- Ke.
//		- map_Kd.
//		- map_Kd.
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003
//-----------------------------------------------------------------------------
// [rev0000:WY:201706291630]
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
#include "ModelMtl.h"

ModelMtl::ModelMtl() {
	// MTL file's directory path.
	this->currentMtlDirectoyPath = new char[BUFSIZ]();
	std::fill(this->currentMtlDirectoyPath, this->currentMtlDirectoyPath + BUFSIZ, 0);
	// MTL: newmtl - material name.
	this->materialName[0] = 0;
	// MTL: map_Kd - Diffuse UV mapping image.
	this->map_Kd[0] = 0;
	// MTL : Ns - Specular hardness, Specular exponent.
	this->Ns = 0;
	// MTL : Ni - Refraction index.
	this->Ni = 0;
	// MTL : d - Alpha, diffuse.
	this->d = 0;
	// MTL : illum - ???.
	this->illum = 0;
}

// Destructor
ModelMtl::~ModelMtl() {
	// MTL file's directory path.
	if (this->currentMtlDirectoyPath != NULL) {
		delete this->currentMtlDirectoyPath;
		this->currentMtlDirectoyPath = NULL;
	}
	// MTL: newmtl - material name.
	this->materialName[0] = 0;
	// MTL: map_Kd - Diffuse UV mapping image.
	this->map_Kd[0] = 0;
	// MTL : Ns - Specular hardness, Specular exponent.
	this->Ns = 0;
	// MTL : Ni - Refraction index.
	this->Ni = 0;
	// MTL : d - Alpha, diffuse.
	this->d = 0;
	// MTL : illum - ???.
	this->illum = 0;
}

//=============================================================================
// Directory path of the MTL file.
//=============================================================================
/*
*	Getter - Member variable "currentMtlDirectoyPath".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "currentMtlDirectoyPath".
*		- MTL file directory path when initialized through MyModelLoader.
*	@return		Return current ModelMtl object's
*					member variable "currentMtlDirectoyPath"
*					C-String.
*	@since		ver0003
*/
char *ModelMtl::getCurrentMtlDirectoyPath() {
	return this->currentMtlDirectoyPath;
}
/*
*	Setter - Member variable "currentMtlDirectoyPath".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "currentMtlDirectoyPath".
*		- MTL file directory path when initialized through MyModelLoader.
*	@param		currentMtlDirectoyPath		Directory path
*											C-String value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setCurrentMtlDirectoyPath(char *currentMtlDirectoyPath) {
	strcpy(this->currentMtlDirectoyPath, currentMtlDirectoyPath);
}

//=============================================================================
// Material related.
//=============================================================================
/*
*	Getter - Member variable "materialName".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "materialName".
*		- Material name inidicated in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "materialName"
*					C-String.
*	@since		ver0003
*/
char *ModelMtl::getMaterialName() {
	return this->materialName;
}
/*
*	Setter - Member variable "materialName".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "materialName".
*		- Material name inidicated in standard MTL file.
*	@param		materialName		Material name
*									C-String value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterialName(char *materialName) {
	strcpy(this->materialName, materialName);
}

/*
*	Getter - Member variable "map_Kd".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "map_Kd".
*		- Texture image file path mapped by Kd diffuse lighting, the element 
*		  value indicated with "map_Kd" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "map_Kd"
*					C-String.
*	@since		ver0003
*/
char *ModelMtl::getMaterial_Map_Kd() {
	return this->map_Kd;
}
/*
*	Setter - Member variable "map_Kd".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "map_Kd".
*		- Texture image file path mapped by Kd diffuse lighting indicated with 
*		  "map_Kd" tag in standard MTL file.
*	@param		map_Kd		Texture image file path mapped by diffuse lighting
*							C-String value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Map_Kd(char *map_Kd) {
	strcpy(this->map_Kd, map_Kd);
}

/*
*	Getter - Member variable "Ns".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Ns".
*		- The specular hardness value indicated with 
*		  "Ns" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Ns"
*					float.
*	@since		ver0003
*/
float ModelMtl::getMaterial_Ns() {
	return this->Ns;
}
/*
*	Setter - Member variable "Ns".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ns".
*		- The specular hardness value indicated with
*		  "Ns" tag in standard MTL file.
*	@param		Ns		The specular hardness float value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Ns(float Ns) {
	this->Ns = Ns;
}

/*
*	Getter - Member variable "Ka".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Ka".
*		- The ambient color value indicated with
*		  "Ka" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Ka"
*					XMFLOAT3.
*	@since		ver0003
*/
XMFLOAT3 ModelMtl::getMaterial_Ka() {
	return this->Ka;
}
/*
*	Setter - Member variable "Ka".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ka".
*		- The ambient color value indicated with
*		  "Ka" tag in standard MTL file.
*	@param		Ka		The ambient color XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Ka(XMFLOAT3 Ka) {
	this->Ka = Ka;
}
/*
*	Getter - Member variable "Kd".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Kd".
*		- The diffuse color value indicated with
*		  "Kd" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Kd"
*					XMFLOAT3.
*	@since		ver0003
*/
XMFLOAT3 ModelMtl::getMaterial_Kd() {
	return this->Kd;
}
/*
*	Setter - Member variable "Kd".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ka".
*		- The diffuse color value indicated with
*		  "Kd" tag in standard MTL file.
*	@param		Kd		The diffuse color XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Kd(XMFLOAT3 Kd) {
	this->Kd = Kd;
}
/*
*	Getter - Member variable "Ks".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Ks".
*		- The specular color value indicated with
*		  "Ks" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Ks"
*					XMFLOAT3.
*	@since		ver0003
*/
XMFLOAT3 ModelMtl::getMaterial_Ks() {
	return this->Ks;
}
/*
*	Setter - Member variable "Ks".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ks".
*		- The specular color value indicated with
*		  "Ks" tag in standard MTL file.
*	@param		Ks		The specular color XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Ks(XMFLOAT3 Ks) {
	this->Ks = Ks;
}
/*
*	Getter - Member variable "Ke".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Ke".
*		- The emissive color value indicated with
*		  "Ke" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Ke"
*					XMFLOAT3.
*	@since		ver0003
*/
XMFLOAT3 ModelMtl::getMaterial_Ke() {
	return this->Ke;
}
/*
*	Setter - Member variable "Ke".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ke".
*		- The emissive color value indicated with
*		  "Ke" tag in standard MTL file.
*	@param		Ke		The emissive color XMFLOAT3 value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Ke(XMFLOAT3 Ke) {
	this->Ke = Ke;
}

/*
*	Getter - Member variable "Ni".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "Ni".
*		- The refraction index value indicated with
*		  "Ni" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "Ni"
*					float.
*	@since		ver0003
*/
float ModelMtl::getMaterial_Ni() {
	return this->Ni;
}
/*
*	Setter - Member variable "Ni".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "Ni".
*		- The refraction index value indicated with
*		  "Ni" tag in standard MTL file.
*	@param		Ni		The refraction index float value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_Ni(float Ni) {
	this->Ni = Ni;
}

/*
*	Getter - Member variable "d".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "d".
*		- The alpha value indicated with
*		  "d" tag in standard MTL file.
*	@return		Return current ModelMtl object's
*					member variable "d"
*					float.
*	@since		ver0003
*/
float ModelMtl::getMaterial_d() {
	return this->d;
}
/*
*	Setter - Member variable "d".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "d".
*		- The alpha value indicated with
*		  "d" tag in standard MTL file.
*	@param		d		The alpha float value to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_d(float d) {
	this->d = d;
}

/*
*	Getter - Member variable "illum".
*	<p>
*	This function is the getter for current ModelMtl object's
*		member variable "illum".
*		- The illumination model option integer value indicated with
*		  "illum" tag in standard MTL file.
		References: https://en.wikipedia.org/wiki/Wavefront_.obj_file
			0. Color on and Ambient off
			1. Color on and Ambient on
			2. Highlight on
			3. Reflection on and Ray trace on
			4. Transparency: Glass on, Reflection: Ray trace on
			5. Reflection: Fresnel on and Ray trace on
			6. Transparency: Refraction on, Reflection: 
				Fresnel off and Ray trace on
			7. Transparency: Refraction on, Reflection: 
				Fresnel on and Ray trace on
			8. Reflection on and Ray trace off
			9. Transparency: Glass on, Reflection: Ray trace off
			10. Casts shadows onto invisible surfaces
*	@return		Return current ModelMtl object's
*					member variable "illum"
*					integer.
*	@since		ver0003
*/
int ModelMtl::getMaterial_illum() {
	return this->illum;
}
/*
*	Setter - Member variable "illum".
*	<p>
*	This function is the setter for current ModelMtl object's
*		member variable "d".
*		- The illumination model option integer value indicated with
*		  "illum" tag in standard MTL file.
		References: https://en.wikipedia.org/wiki/Wavefront_.obj_file
			0. Color on and Ambient off
			1. Color on and Ambient on
			2. Highlight on
			3. Reflection on and Ray trace on
			4. Transparency: Glass on, Reflection: Ray trace on
			5. Reflection: Fresnel on and Ray trace on
			6. Transparency: Refraction on, Reflection:
			Fresnel off and Ray trace on
			7. Transparency: Refraction on, Reflection:
			Fresnel on and Ray trace on
			8. Reflection on and Ray trace off
			9. Transparency: Glass on, Reflection: Ray trace off
			10. Casts shadows onto invisible surfaces
*	@param		illum		The illumination model option integer value 
*							to set with.
*	@return		void
*	@since		ver0003
*/
void ModelMtl::setMaterial_illum(int illum) {
	this->illum = illum;
}

