#pragma once

// Class description: 
//		This class represents a custom exported WYM file exported through the 
//		Blender Python script called blenderExporter.blend, which holds all the 
//		information as a material object but instead in my OWN format. 
//		(Not like standard MTL).
//		I wanted  my own format was because the naming convention in the 
//		standard MTL file was not good and doesn't match the namings in Blender
//		(eg. Ni - Raytrace transparency IOR) and some of the material values 
//		are exported with calculated values, so i could not use them properly 
//		if i import the calculated value only, or it might be used for some 
//		other features too, but if i have the calculated values i would not be
//		able to get the exact value of the original value.
//			eg. 
//				Ka = Ambient intensity * Ambient color. 
//				What if i want to use ambient intensity?
//		So i decided to export with my own format with clearer namings and 
//		values.
//		
//		
//		Element attributes of my own format of material file:
//			mtl_material_count - Number of material objects
//			mtl_material_name - Material name
//			mtl_mirror_color - Material ambient color
//			mtl_ambient - Material ambient intensity
//			mtl_diffuse_color - Material diffuse color
//			mtl_diffuse_intensity - Material diffuse intensity
//			mtl_specular_color - Material specular color
//			mtl_specular_intensity - Material specular intensity
//			mtl_specular_hardness - Material specular hardness (Exponent)
//			mtl_emit - Emission color
//			mtl_raytrace_transparency_ior - Reflection index
//			mtl_alpha - Dissolve, alpha
//			mtl_texture_map_image_path - Texture image file path
//		========================================================================
//		WYM : Custom exported material file exported through my custom material
//			 exporter Blender Python script through Blender.
//		========================================================================
//		This class is inherited from the class ModelMtl, so the default
//		standard MTL properties can also be accessed in this class, save the  
//		time to implement the similar methods and codes
//		(eg. Ka, Ks, d, Ni, Ns, illum, ... etc).
class MyModelMtl : ModelMtl {
private:
	// Only handling single material object exported from Blender.

	// mtl_material_count - Number of materials.
	int materialCount;

	// mtl_material_name - Name of the material.
	char *materialName;

	// mtl_mirror_color, mtl_ambient  
	// (Ka = Ambient color * Ambient intensity)
	DirectX::XMFLOAT3 materialMirrorColor; // mtl_mirror_color
	float materialAmbient; // mtl_ambient 

	// mtl_diffuse_color, mtl_diffuse_intensity 
	// (Kd = Diffuse color * Diffuse intensity)
	DirectX::XMFLOAT3 materialDiffuseColor; // mtl_diffuse_color
	float materialDiffuseIntensity; // mtl_diffuse_intensity

	// mtl_specular_color , mtl_specular_intensity 
	// (Ks = Specular color * Specular intensity)
	DirectX::XMFLOAT3 materialSpecularColor; // mtl_specular_color
	float materialSpecularIntensity; // mtl_specular_intensity

	// mtl_specular_hardness 
	// Shininess, Specular exponent (Larger = More focus)
	// (Ns = Specular hardness / 511 * 1000)
	float materialSpecularHardness;

	// mtl_emit (Ke = Emissive color)
	float materialEmit;

	// mtl_raytrace_transparency_ior  
	// (Ni = Refraction index)
	float materialRaytraceTransparencyIOR;

	// mtl_alpha 
	// (d = Alpha (Dissolve))
	float materialAlpha;

	// mtl_texture_map_image_path 
	// (map_K = Texture image file path)
	char *materialTextureMapImagePath;

public:
	// Default constructor
	MyModelMtl();
	// Destructor
	~MyModelMtl();

	//==========================================================================
	// Number of material indicated in MTL file
	//==========================================================================
	// Member variable "materialCount" getter.
	int getMaterialCount();
	// Member variable "materialCount" setter.
	void setMaterialCount(int materialCount);

	//==========================================================================
	// Name of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialName" getter.
	char *getMaterialName();
	// Member variable "materialName" setter.
	void setMaterialName(char *materialName);

	//==========================================================================
	// Ambient color of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialMirrorColor" getter.
	DirectX::XMFLOAT3 getMaterialMirrorColor();
	// Member variable "materialMirrorColor" setter.
	void setMaterialMirrorColor(DirectX::XMFLOAT3 materialMirrorColor);

	//==========================================================================
	// Ambient intensity of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialAmbient" getter.
	float getMaterialAmbient();
	// Member variable "materialAmbient" setter.
	void setMaterialAmbient(float materialAmbient);

	//==========================================================================
	// Diffuse color of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialDiffuseColor" getter.
	DirectX::XMFLOAT3 getMaterialDiffuseColor();
	// Member variable "materialDiffuseColor" setter.
	void setMaterialDiffuseColor(DirectX::XMFLOAT3 materialDiffuseColor);

	//==========================================================================
	// Diffues intensity of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialDiffuseIntensity" gertter.
	float getMaterialDiffuseIntensity();
	// Member variable "materialDiffuseIntensity" sertter.
	void setMaterialDiffuseIntensity(float materialDiffuseIntensity);

	//==========================================================================
	// Specular color of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialSpecularColor" getter.
	DirectX::XMFLOAT3 getMaterialSpecularColor();
	// Member variable "materialSpecularColor" setter.
	void setMaterialSpecularColor(DirectX::XMFLOAT3 materialSpecularColor);

	//==========================================================================
	// Specular intensity of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialSpecularIntensity" getter.
	float getMaterialSpecularIntensity();
	// Member variable "materialSpecularIntensity" setter.
	void setMaterialSpecularIntensity(float materialSpecularIntensity);

	//==========================================================================
	// Specular hardness of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialSpecularHardness" getter.
	float getMaterialSpecularHardness();
	// Member variable "materialSpecularHardness" setter.
	void setMaterialSpecularHardness(float materialSpecularHardness);

	//==========================================================================
	// Emissive color of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialEmit" getter.
	float getMaterialEmit();
	// Member variable "materialEmit" setter.
	void setMaterialEmit(float materialEmit);

	//==========================================================================
	// Refraction index of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialRaytraceTransparencyIOR" getter.
	float getMaterialRaytraceTransparencyIOR();
	// Member variable "materialRaytraceTransparencyIOR" setter.
	void setMaterialRaytraceTransparencyIOR(
		float materialRaytraceTransparencyIOR);

	//==========================================================================
	// Alpha value of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialAlpha" getter.
	float getMaterialAlpha();
	// Member variable "materialAlpha" setter.
	void setMaterialAlpha(float materialAlpha);

	//==========================================================================
	// UV mapping texture image file path of the material indicated in MTL file
	//==========================================================================
	// Member variable "materialTextureMapImagePath" getter.
	char *getMaterialTextureMapImagePath();
	// Member variable "materialTextureMapImagePath" getter.
	void setMaterialTextureMapImagePath(char *materialTextureMapImagePath);
};
