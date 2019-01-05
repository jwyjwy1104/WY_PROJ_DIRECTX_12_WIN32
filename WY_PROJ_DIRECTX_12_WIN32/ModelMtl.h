#pragma once

// Class description: 
//		This class represents a standard MTL file default exported through 
//		Blender, which holds all the information as a material object.
//		========================================================================
//		MTL : Standard MTL file exported through other 3D engine like Blender as
//				default ".mtl" extension where it is automatically generated
//				whenever OBJ file is exported.
//		========================================================================
class ModelMtl {
private:
	// MTL file's directory path.
	char *currentMtlDirectoyPath;

	//==========================================================================
	// Single material from Blender.
	//==========================================================================

	// MTL: newmtl - material name.
	char materialName[BUFSIZ];
	// MTL : Ka - Ambient color.
	DirectX::XMFLOAT3 Ka;
	// MTL : Kd - Diffuse color.
	DirectX::XMFLOAT3 Kd;
	// MTL : Ks - Specular color.
	DirectX::XMFLOAT3 Ks;
	// MTL : Ns - Specular hardness, Specular exponent.
	float Ns;
	// MTL : Ke - Emissive color.
	DirectX::XMFLOAT3 Ke;
	// MTL : Ni - Refraction index.
	float Ni;
	// MTL : d - Alpha, diffuse.
	float d;
	// MTL : illum - illumination model option.
	int illum;
	// MTL: map_Kd - Diffuse UV mapping image.
	char map_Kd[BUFSIZ];
public:
	// Default constructor.
	ModelMtl();

	// Destructor.
	~ModelMtl();

	//==========================================================================
	// Directory path of the MTL file.
	//==========================================================================
	// Member variable "currentMtlDirectoyPath" getter.
	char *getCurrentMtlDirectoyPath();
	// Member variable "currentMtlDirectoyPath" setter.
	void setCurrentMtlDirectoyPath(char *currentMtlDirectoyPath);

	//==========================================================================
	// Name of the material indicated in MTL file.
	//==========================================================================
	// Member variable "materialName" getter.
	char *getMaterialName();
	// Member variable "materialName" setter.
	void setMaterialName(char *materialName);

	//==========================================================================
	// Ambient color of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Ka" getter.
	DirectX::XMFLOAT3 getMaterial_Ka();
	// Member variable "Ka" setter.
	void setMaterial_Ka(DirectX::XMFLOAT3 Ka);

	//==========================================================================
	// Diffues color of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Kd" getter.
	DirectX::XMFLOAT3 getMaterial_Kd();
	// Member variable "Kd" setter.
	void setMaterial_Kd(DirectX::XMFLOAT3 Kd);

	//==========================================================================
	// Specular color of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Ks" getter.
	DirectX::XMFLOAT3 getMaterial_Ks();
	// Member variable "Ks" setter.
	void setMaterial_Ks(DirectX::XMFLOAT3 Ks);

	//==========================================================================
	// Specular hardness of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Ns" getter.
	float getMaterial_Ns();
	// Member variable "Ns" setter.
	void setMaterial_Ns(float Ns);

	//==========================================================================
	// Emissive color of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Ke" getter.
	DirectX::XMFLOAT3 getMaterial_Ke();
	// Member variable "Ke" setter.
	void setMaterial_Ke(DirectX::XMFLOAT3 Ke);

	//==========================================================================
	// Refraction index of the material indicated in MTL file.
	//==========================================================================
	// Member variable "Ni" getter.
	float getMaterial_Ni();
	// Member variable "Ni" setter.
	void setMaterial_Ni(float Ni);

	//==========================================================================
	// Alpha value of the material indicated in MTL file.
	//==========================================================================
	// Member variable "d" getter.
	float getMaterial_d();
	// Member variable "d" setter.
	void setMaterial_d(float d);

	//==========================================================================
	// Illumination model option number.
	// References: https://en.wikipedia.org/wiki/Wavefront_.obj_file
	//		0. Color on and Ambient off
	//		1. Color on and Ambient on
	//		2. Highlight on
	//		3. Reflection on and Ray trace on
	//		4. Transparency : Glass on, Reflection : Ray trace on
	//		5. Reflection : Fresnel on and Ray trace on
	//		6. Transparency : Refraction on, Reflection :
	//		Fresnel off and Ray trace on
	//		7. Transparency : Refraction on, Reflection :
	//		Fresnel on and Ray trace on
	//		8. Reflection on and Ray trace off
	//		9. Transparency : Glass on, Reflection : Ray trace off
	//		10. Casts shadows onto invisible surfaces
	//==========================================================================
	// Member variable "illum" getter.
	int getMaterial_illum();
	// Member variable "illum" setter.
	void setMaterial_illum(int illum);

	//=====================================================================
	// UV mapping texture image file path of the material indicated in MTL file.
	//=====================================================================
	// Member variable "map_Kd" getter.
	char *getMaterial_Map_Kd();
	// Member variable "map_Kd" setter.
	void setMaterial_Map_Kd(char * map_Kd);
};
