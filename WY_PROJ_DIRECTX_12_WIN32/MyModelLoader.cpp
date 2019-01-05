// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0193: 2017-07-24
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4N2JfanV3ejI1djg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N2JfanV3ejI1djg
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0l4bEExaUtPNTA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0l4bEExaUtPNTA
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cl9MMUhfbExldTg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cl9MMUhfbExldTg
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		Animation loader inner documenting. 
//		Every line of inner documents adjusted and fixed. 
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0006:WY:201707271930]
//------------------------------------------------------------------------------
// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0188: 2017-07-18
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4N2JfanV3ejI1djg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N2JfanV3ejI1djg
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0l4bEExaUtPNTA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0l4bEExaUtPNTA
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cl9MMUhfbExldTg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cl9MMUhfbExldTg
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		Animation loading function added.
//		MyModelAnimation *myAnimationLoader(char *myAnimationFilePath) {
//		
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0005:WY:201707182120]
//------------------------------------------------------------------------------
// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0183: 2017-07-13
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4N2JfanV3ejI1djg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N2JfanV3ejI1djg
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0l4bEExaUtPNTA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0l4bEExaUtPNTA
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cl9MMUhfbExldTg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cl9MMUhfbExldTg
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		MyModelArmature class is now inherited from MyModelObj class, so I can
//			cast the MyModelArmature object to set the coordinate system option
//			properties being held in MyModelObj class by casting it to parent
//			pointer.
//		This is needed because I have to pass in the MyModelObj pointer to 
//			convert the coordinate values according to the coordinate system
//			option specified in OBJ file. I wanted to recylce this code 
//			to load armature files too, so I decieded to inherit the 
//			MyModelArmature class from MyModelObj, so I can use the coordinate 
//			system related properties being held in MyModelObj class.
//		So now MyModelArmature is loaded with coordinate values converted
//			using the coordinate system option specified in armatuer file 
//			as CU - UP vector, CF - FORWARD vector.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0025
//------------------------------------------------------------------------------
// [rev0004:WY:201707131550]
//------------------------------------------------------------------------------
// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0182: 2017-07-11
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4N2JfanV3ejI1djg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N2JfanV3ejI1djg
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0l4bEExaUtPNTA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0l4bEExaUtPNTA
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cl9MMUhfbExldTg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cl9MMUhfbExldTg
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		Adjusted myArmatureLoader() function to automatically load file
//			from current project's debug folder.
//		Adding exception code to catch the error if any file cannot be opened.
//		Coordinate system conversion code in OBJ loading function, have been
//			created into a function and moved to Util class.
//		Now during loading data from OBJ file, i can simply call a single 
//			function by passing the proper arguments to return a coordinate
//			system converted coordinate values to be stored into MyModelObj.
//		This framework might be used on other classes too so i moved it to as
//			a Util class function. To load the armatures properly,
//			since i exported them in custom way i need to convert their 
//			coordinate values in order to let them show on screen properly
//			eg. MyModelArmatureBone is also needed conversion framework.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0024
//------------------------------------------------------------------------------
// [rev0003:WY:201707112100]
//------------------------------------------------------------------------------
// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0179: 2017-07-10
// Diagrams:
//		UML: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4N2JfanV3ejI1djg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4N2JfanV3ejI1djg
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4S0l4bEExaUtPNTA%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4S0l4bEExaUtPNTA
//		Sequence diagram: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4cl9MMUhfbExldTg%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4cl9MMUhfbExldTg
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]:
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		UML, UC, SD, diagrams updated.
//		Function myArmatureLoader() commented to test the MyModelArmature 
//			framework.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0021
//------------------------------------------------------------------------------
// [rev0002:WY:201707012350]
//------------------------------------------------------------------------------
// File name: [MyModelLoader.cpp] (Copyright to Samil Chai)
// Work Session #0171: 2017-06-30
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
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		Error handling code added to myObjMtlLoader() function, checking 
//			returned object after loading from is NULL for further processing 
//			to load MTL file.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0004
//------------------------------------------------------------------------------
// [rev0001:WY:201706302030]
//------------------------------------------------------------------------------
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
//		This class handles all the loading mechanism to load the 
//			standard OBJ and MTL files or custom WYO and WYM file
//			+ armature WYM file into class objects to be used for rendering 
//			with DirectX 12 engine framework.
// - [Comments]:
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//		
//		- [Standard OBJ (.obj extension)]:
//			OBJ (or .OBJ) is a geometry definition file format first developed 
//				by Wavefront Technologies for its Advanced Visualizer 
//				animation package. The file format is open and has been 
//				adopted by other 3D graphics application vendors.
//				(https://en.wikipedia.org/wiki/Wavefront_.obj_file)
//		- [Custom OBJ (.wyo extension)]:
//			Customized versions of ModelLoader.h/cpp read and load the model 
//				using my custom OBJ file exported with my custom OBJ exporter 
//				(Called BlenderExporter).
//	- [OBJ] My custom Blender exported OBJ vs Default Blender exported OBJ.
//		- Asserted both OBJ format is the same ... 
//		- BUT after checking, found out that below 2 element tags
//		  are added onto my custom OBJ file.
//			- CU Z : Coordinate system UP vector.
//			- CF Y : Coordinate system FORWARD vector.
//	- [MTL] Caution!! My custom Blender exported MTL file's format 
//		is adjusted for certain purposes ... 
//		- First, the MTL element tags' naming convention has changed
//		  for better understanding and organization. (eg. d = mtl_alpha)
//			- Because the actual Blender MTL value names and 
//			  exported element tags' names had not much relations,
//			  so that it is not easy to organize. 
//			  (eg. Ni = Specular hardness)
//		- Second, an element value (eg. Ka) is separated and
//		  saved with multiple element values before conversion. 
//		  (eg. Ka = mtl_mirror_color * mtl_ambient)
//			- Because I thought it will be more organized to 
//			  import with more specific element values.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0003_classes_ported_
//			nottestedyet_201706292035
//------------------------------------------------------------------------------
// [rev0000:WY:201705151800]
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
#include "MyModelLoader.h"

// Default constructor
MyModelLoader::MyModelLoader() {
	// Util object for extra features. 
	// (eg. Load font, Load texture image, get image width height, file check)
	this->modelLoaderUtils = new Util();
}

// Destructor
MyModelLoader::~MyModelLoader() {
	// Util object for extra features. 
	// (eg. Load font, Load texture image, get image width height, file check)
	if (this->modelLoaderUtils != NULL) {
		delete this->modelLoaderUtils;
		this->modelLoaderUtils = NULL;
	}
}

/*
*	Opens and reads from a model file to initialize
*		the MySpecialModelObjMtl object which
*		holds a ModelObj/MyModelObj object and a ModelMtl/MyModelMtl object
*		each holding the informations of a model and a material to be used 
*		for rendering a model onto the DirectX 12 application.
*	<p>
*	This function handles loading two types of model file:
*		OBJ: Standard OBJ file exported through other 3D engine like Blender as
*				default ".obj" extension.
*		MTL: Standard MTL file exported through other 3D engine like Blender as
*				default ".mtl" extension where it is automatically generated 
*				whenever OBJ file is exported.
*		WYO: Custom exported model file exported through my custom model
*			 exporter Blender Python script through Blender.
*		WYM: Custom exported material file exported through my custom model
*			 exporter Blender Python script through Blender.
*	So there is 2 types of loading mechanism applied to this function:
*		OBJ --> ModelObj --> MTL --> ModelMtl
*		WYO --> MyModelObj --> WYM --> MyModelMtl
*		Note: This loading mechanism is decided by checking the extension of
*			  the model file (eg. .obj OR .wyo). Then a format number will be 
*			  provided to decide which loading mechanism to use to load the 
*			  model file with.
*	Format numbers are as follows:
*		100: Standard format: .obj --> ModelObj --> .mtl --> ModelMtl
*		101: Custom format: .wyo --> MyModelObj --> .wym --> MyModelMtl
*
*	There are many helper functions needed to load the above files:
*	OBJ - stdObjLoader() --> ReadFileCounts() --> LoadDataStructuresModelObj()
*	MTL - stdMtlLoader() 
*	WYO	- myObjLoader() --> ReadFileCounts() --> LoadDataStructuresMyModelObj()
*	WYM - myMtlLoader()
*
*	============================================================================
*	[Framework description: Loading standard OBJ file]
*	============================================================================
*	This function opens and reads the OBJ file with given file path,
*		creates a ModelObj object and intialize the data to be held
*		as a model object.
*	Then opens and reads the MTL file with MTL file name provided in OBJ file
*		as "mtllib" element value, creates a ModelMtl object and
*		intialize the data to be held as a material object.
*	Finally creates a MySpecialModelObjMtl object to hold both
*		ModelObj object and ModelMtl to wrap all the data into 
*		a single variable, and return its pointer to be used for rendering.
*	============================================================================
*
*	============================================================================
*	[Important notes]
*	============================================================================
*	Important note 1: Currently, this function is reading from current
*						project's Debug folder, so the OBJ file path should 
*						be relative to this project's Debug folder.
*	Important note 2: This function automatically detects the OBJ file's 
*						extension to decide which format and method to load the
*						files especially needed for loading MTL elements, 
*						because for standard exported MTL file between custom 
*						exported MTL file has different format, tags, class 
*						names, and function name, so i'm using cosntant values
*						retrieved from each file's extension to decide which 
*						method to load the files with.
*	Important note 3: 
*			ModelObj class is the upper class of MyModelObj class,
*			ModelMtl class is the upper class of MyModelMtl class,
*			The reason why this is implemented this way is because in this way
*				I can use the existing functions loading a standard OBJ file on
*				loading a custom exported WYO file.
*	============================================================================
*
*						
*	@param		objFilePath		Main Model file name relative path to current 
*								project's Debug folder to load the model with.	
*	@return		Return a MySpecialModelObjMtl object pointer which contains a
*				ModelObj/MyModelObj object loaded from given model(OBJ) file
*				path and a ModelMtl/MyModelMtl object loaded from material(MTL)
*				file name provided in model(OBJ) file as "mtllib" element.
*	@since		ver0003
*/
MySpecialModelObjMtl *MyModelLoader::myObjMtlLoader(const char *objFilePath) {
	//==========================================================================
	// Init local buffers for current project directory path retrieving.
	//==========================================================================
	// Local buffer to hold the final absolute OBJ file path to load with.
	char finalObjAbsFilePath[FILENAME_MAX];
	std::fill(finalObjAbsFilePath, finalObjAbsFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the OBJ file path.
	char currentObjFilePath[FILENAME_MAX];  
	std::fill(currentObjFilePath, currentObjFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the OBJ file name.
	char currentObjFileName[FILENAME_MAX]; 
	std::fill(currentObjFileName, currentObjFileName + FILENAME_MAX, NULL);

	// Get current working directory path and store it into local buffer.
	if (!GetCurrentDir(currentObjFilePath, sizeof(currentObjFilePath))) {
		// If failed.
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::GetCurrentDir() failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		//return NULL;
		throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::GetCurrentDir() failed!!!\n");
	}

	//==========================================================================
	// Need to specify to the Debug folder because all the assets are in the 
	// project's Debug folder, but this GetCurrentDir() function is 
	// retrieving the directory path of current file MyModelLoader.cpp
	// so i have to concat "\..\Debug" to redirect to the Debug folder in  
	// current project folder.
	//==========================================================================
	// Append "\..\Debug".
	strncat_s(
		currentObjFilePath, FILENAME_MAX,
		"\\..\\Debug", FILENAME_MAX);

	/* not really required */
	currentObjFilePath[sizeof(currentObjFilePath) - 1] = '\0';
	//==========================================================================

	// Print current working directory path.
	_RPT1(0, "MyModelLoader::myObjMtlLoader::The current working directory is: |%s|\n", currentObjFilePath);

	// Copy OBJ file name to a local buffer.
	strcpy(currentObjFileName, objFilePath);

	// Copy working directory path to another local buffer.
	strncpy_s(finalObjAbsFilePath, FILENAME_MAX,
		currentObjFilePath, FILENAME_MAX);

	// Concat OBJ file name onto current working directory path to generate 
	// final OBJ absolute file path.
	strncat_s(finalObjAbsFilePath, FILENAME_MAX,
		currentObjFileName, FILENAME_MAX);

	// Final OBJ absolute file path.
	_RPT1(0, "MyModelLoader::myObjMtlLoader::Final OBJ absolute file path : |%s|\n", finalObjAbsFilePath);

	// ifsream reader to read the file with.
	ifstream fin;
	fin.open(finalObjAbsFilePath);

	// Check if it was successful in opening the OBJ file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::Given OBJ file does not exist!!! : %s\n", finalObjAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::Given OBJ file does not exist!!!");
	}

	//==========================================================================
	// Pre-condition: OBJ and MTL file must be in the same directory inside 
	//				  project's Debug folder, so does texture images indicated
	//				  in MTL file.
	//==========================================================================
	// Local buffer to hold the OBJ file directory path to load the relative 
	// MTL file with.
	char *currentObjMtlDirPath = new char[BUFSIZ]();
	std::fill(currentObjMtlDirPath, currentObjMtlDirPath + BUFSIZ, 0);
	// Retrieve OBJ file's directory path and store it to a local buffer 
	// to be used for loading MTL file.
	strcpy(
		currentObjMtlDirPath,
		modelLoaderUtils->getFolderPathFromFileName(finalObjAbsFilePath));
	
	// Current OBJ directory path = Current MTL directory path.
	_RPT1(0, "MyModelLoader::myObjMtlLoader::Current OBJ directory path : |%s|\n", currentObjMtlDirPath);

	//==========================================================================
	// Main result MySpecialModelObjMtl pointer to be returned.
	//==========================================================================
	MySpecialModelObjMtl *curMySpecialModelObj = NULL;

	//==========================================================================
	// Determine extension of the files to decide the loading mechanism to 
	// load the OBJ and MTL file.
	//==========================================================================
	// Get file extension C-string from the OBJ absolute file path.
	char *fileExtension
		= modelLoaderUtils->getFileExtensionFromFullPath(finalObjAbsFilePath);
	//_RPT1(0, "Current OBJ file extension : |%s|\n", fileExtension);

	// Retrieve format number constant value with corresponding extension 
	// string.
	int modelLoaderFormatNumber
		= modelLoaderUtils->modelLoaderFormatFactoryFileExtensions(
			fileExtension);

	
	// Boolean flag to check which format to be used to load OBJ and MTL file.
	bool BOOL_MODEL_LOADER_FORMAT_OBJ = false; // Standard OBJ
	bool BOOL_MODEL_LOADER_FORMAT_WYO = false; // Custom WYO

	//==========================================================================
	// Using the retrieved format number to turn the flags on to start loading
	// files.
	//==========================================================================
	// If file extension is ".obj" then the format number is 100 so 
	// turn on the BOOL_MODEL_LOADER_FORMAT_OBJ flag
	if (modelLoaderFormatNumber == MODEL_LOADER_FORMAT_OBJ) {
		_RPT1(0, "MyModelLoader::myObjMtlLoader::File is OBJ\n", 0);
		BOOL_MODEL_LOADER_FORMAT_OBJ = true;

	}
	// Else if file extension is ".wyo" then the format number is 101 so 
	// turn on the BOOL_MODEL_LOADER_FORMAT_WYO flag
	else if (modelLoaderFormatNumber == MODEL_LOADER_FORMAT_WYO) {
		_RPT1(0, "MyModelLoader::myObjMtlLoader::File is WYO\n", 0);
		BOOL_MODEL_LOADER_FORMAT_WYO = true;
	}
	// Else does not support any method.
	else {
		_RPT1(0, "MyModelLoader::myObjMtlLoader::File is not valid\n", 0);
	}

	//##########################################################################
	// Loading file extension .obj for standard OBJ file.
	//##########################################################################
	if (BOOL_MODEL_LOADER_FORMAT_OBJ) {
		//======================================================================
		// Load OBJ.
		//======================================================================
		// Load .obj file onto ModelObj object.
		ModelObj *modelObj
			= this->stdObjLoader(finalObjAbsFilePath);

		// If failed to load the OBJ file onto ModelObj object.
		if (modelObj == NULL) {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_OBJ::Couldn't load OBJ file!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_OBJ::Couldn't load OBJ file!!!");
		}

		// Get "mtllib" element value, relative MTL file name from 
		// loaded ModelObj object.
		_RPT1(0, "MyModelLoader::myObjMtlLoader::MTL file name indicated in OBJ file : |%s|\n",
			modelObj->getMaterialFileName());

		//======================================================================
		// MTL path = OBJ Directory path + '\' + MTL file name provided in OBJ 
		// file
		//======================================================================
		// Local buffer to store the MTL absolute file path.
		char *currentMtlPath = new char[BUFSIZ]();
		std::fill(currentMtlPath, currentMtlPath + BUFSIZ, 0);

		// Retrieve OBJ file's directory path and concat current MTL file name
		// to get the MTL file's absolute path.
		strcpy(
			currentMtlPath,
			getMtlFilePathUsingObjFilePathAndMtlFileName(
				finalObjAbsFilePath,
				modelObj->getMaterialFileName()));

		// Current MTL absolute file path.
		_RPT1(0, "MyModelLoader::myObjMtlLoader::Current MTL absolute file path: |%s|\n", currentMtlPath);

		//======================================================================
		// Load MTL.
		//======================================================================
		// Load .mtl file onto ModelMtl object
		ModelMtl *modelMtl
			= this->stdMtlLoader(currentMtlPath);
		// If failed to load the MTL file onto ModelMtl object.
		if (modelMtl == NULL) {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_OBJ::Couldn't load MTL file!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_OBJ::Couldn't load MTL file!!!\n");
		}
		//======================================================================
		// Using the resulting model MySpecialModelObjMtl object to wrap up
		// ModelObj and ModelMtl object just loaded above by giving the object
		// pointers to the constructor.
		//======================================================================
		curMySpecialModelObj
			= new MySpecialModelObjMtl(modelObj, modelMtl);

		// If initialization failed.
		if (curMySpecialModelObj != NULL) {
			// Set model loader format number used to load current model.
			// Just keeping with the value because might be used later on.
			curMySpecialModelObj->setModelLoaderFormatNumber(
				MODEL_LOADER_FORMAT_OBJ);

			_RPT1(0, "MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization success!!!\n", 0);
		}
		// If failed to load the MySpecialModelObjMtl object with the 
		// initialized ModelObj and ModelMtl objects.
		else {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization failed!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization failed!!!\n");
		}
	}
	//##########################################################################
	// Loading file extension .wyo (.txt for now) for my custom WYO file.
	//##########################################################################
	else if (BOOL_MODEL_LOADER_FORMAT_WYO) {
		//======================================================================
		// Load WYO.
		//======================================================================
		// Load .wyo file onto MyModelObj object.
		MyModelObj *myModelObj
			= this->myObjLoader(finalObjAbsFilePath);

		// If failed to load the WYO file onto MyModelObj object.
		if (myModelObj == NULL) {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_WYO::Couldn't load custom OBJ file!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_WYO::Couldn't load custom OBJ file!!!\n");
		}

		// Get "mtllib" element value, relative MTL file name from 
		// loaded MyModelObj object.
		_RPT1(0, "MyModelLoader::myObjMtlLoader::WYM file name indicated in WYO file  : |%s|\n",
			((ModelObj *)myModelObj)->getMaterialFileName());

		//======================================================================
		// MTL path 
		// = OBJ Directory path + '\' + MTL file name provided in OBJ file
		//======================================================================
		// Local buffer to store the MTL absolute file path.
		char *currentMtlPath = new char[BUFSIZ]();
		std::fill(currentMtlPath, currentMtlPath + BUFSIZ, 0);
		// Retrieve WYO file's directory path and concat current WYM file name
		// to get the WYM file's absolute path.
		strcpy(
			currentMtlPath,
			getMtlFilePathUsingObjFilePathAndMtlFileName(
				finalObjAbsFilePath,
				((ModelObj *)myModelObj)->getMaterialFileName()));
		// Current WYM absolute file path.
		_RPT1(0, "MyModelLoader::myObjMtlLoader::Current WYM absolute file path : |%s|\n", currentMtlPath);

		//======================================================================
		// Load MTL
		//======================================================================
		// Load .wym file onto MyModelMtl object
		MyModelMtl *myModelMtl
			= this->myMtlLoader(currentMtlPath);
		// If failed to load the WYM file onto MyModelMtl object ...
		if (myModelMtl == NULL) {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_WYO::Couldn't load custom MTL file!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::BOOL_MODEL_LOADER_FORMAT_WYO::Couldn't load custom MTL file!!!\n");
		}

		//======================================================================
		// Using the resulting model MySpecialModelObjMtl object to wrap up
		// ModelObj and ModelMtl object just loaded above by giving the object
		// pointers to the constructor.
		//======================================================================
		curMySpecialModelObj
			= new MySpecialModelObjMtl(
			((ModelObj *)myModelObj), ((ModelMtl *)myModelMtl));

		// If initialization failed.
		if (curMySpecialModelObj != NULL) {
			// Set model loader format number to be used to decide which 
			// MTL functions to be used on texture buffer init
			curMySpecialModelObj->setModelLoaderFormatNumber(
				MODEL_LOADER_FORMAT_WYO);

			_RPT1(0, "MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization success!!!\n", 0);

		}
		// If failed to load the MySpecialModelObjMtl object with the 
		// initialized MyModelObj and MyModelMtl objects.
		else {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization failed!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::MySpecialModelObjMtl initialization failed!!!\n");
		}
	}
	// Else currently does not have supported format to load the files with.
	else {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myObjMtlLoader::No format number is valid to load the model files!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myObjMtlLoader::No format number is valid to load the model files!!!\n");
	}

	// Return the resulting MySpecialModelObjMtl pointer.
	return curMySpecialModelObj;
}

/*
*	Using OBJ absolute file path "objFilePath" to retrieve directory path
*		then concat with relative MTL file path given "mtlFileName",
*		combines into absolute MTL file path and return it to load the 
*		relative MTL file.
*	<p>
*	This function combines absolute OBJ file's directory path with the
*		relative MTL file name into
*		absolute MTL file path.
*		(eg. MTL file path = OBJ file's directory path + MTL file name)
*	 First, retrieve OBJ file's directory path
*		using the getFolderPathFromFileName() function in Util class.
*	 Second, concat the relative MTL file name given onto the directory path.
*	@param		objFilePath					OBJ file absolute path
*	@param		mtlFileName					MTL file name
*	@return		Return the combined MTL file path
*					using the OBJ file's directory path
*					+ relative MTL file name.
*	@since		ver0003
*/
char *MyModelLoader::getMtlFilePathUsingObjFilePathAndMtlFileName(
	const char *objFilePath,
	char *mtlFileName) {
	// Init MTL path local buffer.
	char *currentMtlPath = new char[BUFSIZ]();
	std::fill(currentMtlPath, currentMtlPath + BUFSIZ, 0);
	//==========================================================================
	// MTL path = OBJ Directory path + '\' + MTL file name
	//==========================================================================
	// Get OBJ directory path using Util class function .
	// (eg. C:\Desktop\test.obj --> C:\Desktop)
	strcpy(currentMtlPath, 
		modelLoaderUtils->getFolderPathFromFileName(objFilePath));

	// Concat '\' at the end (eg. C:\Dekstop\).
	strcat(currentMtlPath, "\\");

	// Concat relative MTL file name (eg. C:\Dekstop\test.mtl).
	strcat(currentMtlPath, mtlFileName);

	// Concat NULL character since it is a C string.
	strcat(currentMtlPath, "\0");
	//_RPT1(0, "currentMtlPath : %s\n", currentMtlPath);

	// Return absolute MTL file path.
	return currentMtlPath;
}

//==============================================================================
// Standard importer 
// (Standard OBJ exported through Blender --> DirectX 12).
//==============================================================================
/*
*	Standard OBJ file (.obj extension) - Opens and reads from standard
*		OBJ file to initialize the ModelObj object which contiains the model 
*		information values to be used for rendering.
*	<p>
*	This function opens and reads the standard OBJ file on given file path,
*		creates a ModelObj object and
*		intialize the data to be held as a model object.
*	The elements to be loaded and be initialized onto the ModelObj object
*		are as follows:
*		v  - Vertex coordinate
*		vn - Vertex normal vector coordinate
*		vt - Texture mapping UV coordinate
*		f  - Face index
*		------------------------------------------------------------------------
*		Here, the main algorithm is to duplicate the vertices to match
*			texture coordinates count, for texture mapping.
*		This is done AFTRE loading OBJ file (through this function) by calling
*			ModelObj::duplicateverticesPositionColorTexture() function.
*		------------------------------------------------------------------------
*
*	@param		stdObjfilePath	Standard OBJ absolute file path to
*								be opened for reading the model file with.
*	@return		Return a ModelObj object pointer initialized
*					with the model data values read from the standard OBJ file
*					loaded on given file path.
*	@since		ver0003
*/
ModelObj *MyModelLoader::stdObjLoader(char *stdObjFilePath) {
	// Local integer variables to hold the element count for each elements
	// to be loaded from the standard OBJ file.
	int vertexCount, textureCount, normalCount, faceCount;

	// Read in the number of vertices, tex coords, normals, and faces
	// so that the data structures can be initialized 
	// with the exact sizes needed.
	bool result = ReadFileCounts(
		stdObjFilePath, 
		// Will be initialized with the number of "v" elements in the OBJ file.
		vertexCount,  
		// Will be initialized with the number of "vt" elements in the OBJ file.
		textureCount,
		// Will be initialized with the number of "vn" elements in the OBJ file.
		normalCount,
		// Will be initialized with the number of "f" elements in the OBJ file.
		faceCount);

	// Return false if sub function call ReadFileCounts() returned false.
	if (!result) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::stdObjLoader::Read element count from the standard OBJ file failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::stdObjLoader::Read element count from the standard OBJ file failed!!!\n");
		return false;
	}

	//==========================================================================
	// Init the resulting ModelObj object by passing the element counters 
	// loaded above to initialize the data structures to be ready to stored the
	// elemenet values with.
	//==========================================================================
	ModelObj *curModelObj = new ModelObj(
		vertexCount, textureCount, normalCount, faceCount);

	_RPT1(0, "ModelObj START==============================================================================\n", 0);
	_RPT1(0, "ModelObj created: %s\n", stdObjFilePath);
	_RPT1(0, "ModelObj START==============================================================================\n", 0);
	_RPT1(0, "MyModelLoader::stdObjLoader::vertexCount : %d\n", vertexCount);
	_RPT1(0, "MyModelLoader::stdObjLoader::textureCount : %d\n", textureCount);
	_RPT1(0, "MyModelLoader::stdObjLoader::normalCount : %d\n", normalCount);
	_RPT1(0, "MyModelLoader::stdObjLoader::faceCount : %d\n", faceCount);

	// Now read the data from the file into the data structures
	// and then output it in our model format.
	result = LoadDataStructuresModelObj(
		// ModelObj object with the data structures to store the element values with.
		curModelObj,	
		stdObjFilePath, // OBJ file to read data from.
		// Number of "v" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		vertexCount,	
		// Number of "vt" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		textureCount,
		// Number of "vn" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		normalCount,
		// Number of "f" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		faceCount);

	// Return false if sub function call LoadDataStructuresModelObj() 
	// returned false.
	if (!result) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::stdObjLoader::Data strucutre inside ModelObj object created failed or storing values into the data strucutre inside ModelObj failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::stdObjLoader::Data strucutre inside ModelObj object created failed or storing values into the data strucutre inside ModelObj failed!!!\n");

		return false;
	}

	//==========================================================================
	// Retrieve the data structure pointers inside ModelObj object
	// after initializaions for more processing.
	//==========================================================================
	// Data structure of "v" elements initialzied inside ModelObj object.
	VertexType *vertices = curModelObj->getModelVertices();
	// Number of "v" elements initialzied inside ModelObj object.
	int numVertices = curModelObj->getVertexCount();

	// Data structure of "vt" elements initialzied inside ModelObj object.
	VertexType *texcoords = curModelObj->getTexcoords();
	// Number of "vt" elements initialzied inside ModelObj object.
	int numTexture = curModelObj->getTextureCount();

	// Data structure of "vn" elements initialzied inside ModelObj object.
	VertexType *normals = curModelObj->getNormals();
	// Number of "vn" elements initialzied inside ModelObj object.
	int numNormals = curModelObj->getNormalCount();

	// Data structure of "f" elements initialzied inside ModelObj object.
	FaceType *faces = curModelObj->getFaces();
	// Number of "f" elements initialzied inside ModelObj object.
	int numFaces = curModelObj->getFaceCount();

	//==========================================================================
	// Need to do one more step to initialize the vertex buffer to be rendered
	// on the main screen through DirectX 12 engine.
	// 
	// Is to duplicate the vertices to match texture coordinates counts,
	// mostly for texture mapping.
	// 
	// Detailed algorithm is explained in the function document.
	//==========================================================================
	curModelObj->duplicateverticesPositionColorTexture(
		vertices, texcoords, normals, faces, numFaces);

	// Retrieve the texture coordinate indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [t1,t2,t2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ...)
	curModelObj->texcoordsIndicesCalcFromFacesbuffer(faces, numFaces);

	// Retrieve the vertex indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [v1,v2,v2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ... )
	curModelObj->vertexIndicesCalcFromFacesbuffer(faces, numFaces);
	// Retrieve the normal vector indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [n1,n2,n2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ... )
	curModelObj->normalIndicesCalcFromFacesbuffer(faces, numFaces);

	//==========================================================================
	// Print the main index buffer array data values.
	//==========================================================================
	// Currently, the texture coordinate indices is the main index buffer to 
	// render the model on screen.
	_RPT1(0, "curModelObj->getIndicesCount() : %d\n", curModelObj->getIndicesCount());
	int j = 1;
	for (int i = 0; i < (int)curModelObj->getIndicesCount(); i++) {
		_RPT1(0, "%d", curModelObj->getTexcoordsIndices()[i]);
		_RPT1(0, ",", 0);

		if (j % 3 == 0) {
			_RPT1(0, "\n", 0);

		}
		j++;
	}
	_RPT1(0, "\n", 0);

	for (int i = 0; i < numNormals; i++) {
		//cout << "normals : " << normals[i].x << ' ' << normals[i].y << ' ' << normals[i].z << endl;
		_RPT1(0, "MyModelLoader::stdObjLoader::normals : %f %f %f\n", normals[i].x, normals[i].y, normals[i].z);
	}
	_RPT1(0, "ModelObj END==============================================================================\n", 0);

	// Return the resulting ModelObj object.
	return curModelObj;
}

/*
*	Standard MTL file (.mtl extension) - Opens and reads from standard
*		MTL file to initialize the ModelMtl object which contiains the material
*		information values to be used for rendering.
*	<p>
*	This function opens and reads the standard MTL file on given file path,
*		creates a ModelMtl object and
*		intialize the data to be held as a material object.
*	The elements to be loaded and be initialized onto the ModelMtl object
*		are as follows:
*			newmtl - Material name
*			Ka - Final ambient color
*			Kd - Final diffuse color
*			Ks - Final specular color
*			Ke - Final emissive color
*			Ni - Refraction index
*			Ns - Specular hardness, exponenet
*			d - Dissolve, Alpha
*			illum - ???
*			map_Kd - Texture image file path
*
*	@param		stdMtlFilePath		Standard MTL absolute file path to be 
*									opened for reading the material file with.
*	@return		Return a ModelMtl object initialized with
*					the material data read from the standard MTL file
*					opened with given file path.
*	@since		ver0003
*/
ModelMtl *MyModelLoader::stdMtlLoader(char *stdMtlFilePath) {
	// Init resulting ModelMtl object.
	ModelMtl *curModelMtl = new ModelMtl();

	// Retrieve directory path from the MTL absolute file path.
	char *dirPath
		= this->modelLoaderUtils->getFolderPathFromFileName(stdMtlFilePath);

	// Set current MTL directory path onto the ModelMtl object.
	curModelMtl->setCurrentMtlDirectoyPath(dirPath);

	// ifstream to open the file with.
	ifstream fin;
	// Local character variable to read from the file.
	char input = '\0';

	// Open the file.
	fin.open(stdMtlFilePath);

	_RPT1(0, "ModelMtl START==============================================================================\n", 0);
	_RPT1(0, "ModelMtl created : %s\n", stdMtlFilePath);
	_RPT1(0, "ModelMtl START==============================================================================\n", 0);

	// Check if it was successful in opening the MTL file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::mtlLoader::Standard MTL file open failed!!! : %s\n", stdMtlFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::mtlLoader::Standard MTL file open failed!!!");
	}

	// Read in the newmtl, Ka, Kd, Ks, Ns, Ni, d, illum, map_Kd and store them 
	// into the ModelMtl object.
	fin.get(input);
	while (!fin.eof()) {
		//----------------------------------------------------------------------
		// newmtl
		//----------------------------------------------------------------------
		if (input == 'n') {
			fin.get(input);
			if (input == 'e') {
				fin.get(input);
				if (input == 'w') {
					fin.get(input);
					if (input == 'm') {
						fin.get(input);
						if (input == 't') {
							fin.get(input);
							if (input == 'l') {
								fin.get(input);
								if (input == ' ') {
									// Local buffer.
									char temp[BUFSIZ];
									int count = 0;
									// Read "newmtl" string into local buffer.
									while (input != '\n') {
										fin.get(input);
										temp[count] = input;
										count++;
									}
									temp[count - 1] = '\0';
									_RPT1(0, "MyModelLoader::mtlLoader::material name : |%s|\n", temp);

									// Set material name "newmtl" element value.
									curModelMtl->setMaterialName(temp);
								}
							}
						}
					}
				}
			}
		//----------------------------------------------------------------------
		}

		//----------------------------------------------------------------------
		// Ka, Kd, Ks
		//----------------------------------------------------------------------
		if (input == 'K') {
			fin.get(input);
			if (input == 'a') {
				// Local variables to hold the loaded data with.
				float tempX, tempY, tempZ;
				// Read in 3 float values.
				fin >> tempX >> tempY >> tempZ;
				_RPT1(0, "MyModelLoader::mtlLoader::Ka : %f, %f, %f\n", tempX, tempY, tempZ);

				// Set material "Ka" element value.
				curModelMtl->setMaterial_Ka(XMFLOAT3(tempX, tempY, tempZ));
			}
			if (input == 'd') {
				// Local variables to hold the loaded data with.
				float tempX, tempY, tempZ;
				// Read in 3 float values.
				fin >> tempX >> tempY >> tempZ;
				_RPT1(0, "MyModelLoader::mtlLoader::Kd : %f, %f, %f\n", tempX, tempY, tempZ);

				// Set material "Kd" element value.
				curModelMtl->setMaterial_Kd(XMFLOAT3(tempX, tempY, tempZ));
			}
			if (input == 's') {
				// Local variables to hold the loaded data with.
				float tempX, tempY, tempZ;
				// Read in 3 float values.
				fin >> tempX >> tempY >> tempZ;
				_RPT1(0, "MyModelLoader::mtlLoader::Ks : %f, %f, %f\n", tempX, tempY, tempZ);

				// Set material "Ks" element value.
				curModelMtl->setMaterial_Ks(XMFLOAT3(tempX, tempY, tempZ));
			}
			if (input == 'e') {
				// Local variables to hold the loaded data with.
				float tempX, tempY, tempZ;
				// Read in 3 float values.
				fin >> tempX >> tempY >> tempZ;
				_RPT1(0, "MyModelLoader::mtlLoader::Ke : %f, %f, %f\n", tempX, tempY, tempZ);

				// Set material "Ke" element value.
				curModelMtl->setMaterial_Ke(XMFLOAT3(tempX, tempY, tempZ));
			}
		}

		//----------------------------------------------------------------------
		// Ns, Ni
		//----------------------------------------------------------------------
		if (input == 'N') {
			fin.get(input);
			if (input == 's') {
				// Local variable to hold the loaded data with.
				float temp;
				// Read in a float value.
				fin >> temp;
				_RPT1(0, "MyModelLoader::mtlLoader::Ns : %f\n", temp);

				// Set material "Ns" element value.
				curModelMtl->setMaterial_Ns(temp);
			}
			if (input == 'i') {
				// Local variable to hold the loaded data with.
				float temp;
				// Read in a float value.
				fin >> temp;
				_RPT1(0, "MyModelLoader::mtlLoader::Ni : %f\n", temp);

				// Set material "Ni" element value.
				curModelMtl->setMaterial_Ni(temp);
			}
		}

		//----------------------------------------------------------------------
		// d
		//----------------------------------------------------------------------
		if (input == 'd') {
			fin.get(input);
			if (input == ' ') {
				// Local variable to hold the loaded data with.
				float temp;
				// Read in a float value.
				fin >> temp;
				_RPT1(0, "MyModelLoader::mtlLoader::d : %f\n", temp);

				// Set material "d" element value.
				curModelMtl->setMaterial_d(temp);
			}
		}

		//----------------------------------------------------------------------
		// illum
		//----------------------------------------------------------------------
		if (input == 'i') {
			fin.get(input);
			if (input == 'l') {
				fin.get(input);
				if (input == 'l') {
					fin.get(input);
					if (input == 'u') {
						fin.get(input);
						if (input == 'm') {
							fin.get(input);
							if (input == ' ') {
								// Local variable to hold the loaded data with.
								int temp;
								// Read in a integer value.
								fin >> temp;
								_RPT1(0, "MyModelLoader::mtlLoader::illum : %d\n", temp);

								// Set material "illum" element value.
								curModelMtl->setMaterial_illum(temp);
							}
						}
					}
				}
			}
		}

		//----------------------------------------------------------------------
		// map_Kd
		//----------------------------------------------------------------------
		if (input == 'm') {
			fin.get(input);
			if (input == 'a') {
				fin.get(input);
				if (input == 'p') {
					fin.get(input);
					if (input == '_') {
						fin.get(input);
						if (input == 'K') {
							fin.get(input);
							if (input == 'd') {
								fin.get(input);
								if (input == ' ') {
									// Local buffer.
									char temp[BUFSIZ];
									int count = 0;
									// Read "map_Kd" string into local buffer.
									while (input != '\n') {
										fin.get(input);
										temp[count] = input;
										count++;
									}
									temp[count - 1] = '\0';

									// Local buffer for "map_Kd" absolute path.
									char textureMapImageFilePath[BUFSIZ];
									
									// Store current MTL directory path 
									// to the local buffer.
									strcpy(textureMapImageFilePath,
										curModelMtl
										->getCurrentMtlDirectoyPath());
									// Append '\'.
									strcat(textureMapImageFilePath, "\\");
									// Append "map_Kd" file name.
									strcat(textureMapImageFilePath, temp);

									// Set material name "newmtl" element value.
									curModelMtl
										->setMaterial_Map_Kd(
											textureMapImageFilePath);

									_RPT1(0, "MyModelLoader::mtlLoader::map_Kd : |%s|\n", textureMapImageFilePath);
								}
							}
						}
					}
				}
			}
		}

		// Read in the remainder of the line.
		while (input != '\n') {
			fin.get(input);
		}

		// Start reading the beginning of the next line.
		fin.get(input);
	}

	_RPT1(0, "ModelMtl END==============================================================================\n", 0);
	// Return the resulting ModelMtl object.
	return curModelMtl;
}
//------------------------------------------------------------------------------

/*
*	Custom WYO file (.wyo extension) - Opens and reads from a custom exported
*		model file to initialize the MyModelObj object which contiains the model
*		information values to be used for rendering.
*	<p>
*	This function opens and reads from the custom exported model file on
*		given file path, creates a MyModelObj object and
*		intialize the data to be held as a model object.
*	The elements to be loaded and be initialized onto MyModelObj object
*		are as follows:
*		CU - Coordinate system UP vector
*		CF - Coordinate system FORWARD vector
*	MyModelObj class is inherited from ModelObj class which also holds:
*		v - Vertex coordinate
*		vn - Vertex normal vector coordinate
*		vt - Texture mapping UV coordinate
*		f - Face index
*		------------------------------------------------------------------------
*		Here, the main algorithm is to duplicate the vertices to match
*			texture coordinates count, for texture mapping.
*		This is done after loading OBJ file by calling
*			ModelObj::duplicateverticesPositionColorTexture() function.
*		------------------------------------------------------------------------
*
*	@param		myObjfilePath	Custom OBJ absolute file path to be
*								opened for reading
*	@return		Return a MyModelObj object pointer initialized
*					with the model data read from custom exported WYO file
*					loaded on given file path.
*	@since		ver0003
*/
MyModelObj *MyModelLoader::myObjLoader(char *myObjFilePath) {
	// Local integer variables to hold the element count for each elements
	// to be loaded from the standard OBJ file.
	int vertexCount, textureCount, normalCount, faceCount;

	// Read in the number of vertices, tex coords, normals, and faces
	// so that the data structures can be initialized 
	// with the exact sizes needed.
	bool result = ReadFileCounts(
		myObjFilePath,
		// Will be initialized with the number of "v" elements in the OBJ file.
		vertexCount,
		// Will be initialized with the number of "vt" elements in the OBJ file.
		textureCount,
		// Will be initialized with the number of "vn" elements in the OBJ file.
		normalCount,
		// Will be initialized with the number of "f" elements in the OBJ file.
		faceCount);
	
	// Return false if sub function call ReadFileCounts() returned false.
	if (!result) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myObjLoader::Read element count from the standard OBJ file failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myObjLoader::Read element count from the standard OBJ file failed!!!\n");
		return false;
	}

	//==========================================================================
	// Init the resulting MyModelObj object by passing the element counters 
	// loaded above to initialize the data structures to be ready to stored the
	// elemenet values with.
	//==========================================================================
	MyModelObj *curModelObj = new MyModelObj(
		vertexCount,
		textureCount,
		normalCount,
		faceCount);

	// Retrieve directory path from the WYO absolute file path.
	char *dirPath 
		= this->modelLoaderUtils->getFolderPathFromFileName(myObjFilePath);
	// Set current custom exported WYO file's directory path
	((ModelObj *)curModelObj)->setCurrentObjDirectoyPath(dirPath);

	_RPT1(0, "MyModelObj START==============================================================================\n", 0);
	_RPT1(0, "MyModelObj created : %s\n", myObjFilePath);
	_RPT1(0, "MyModelObj START==============================================================================\n", 0);
	_RPT1(0, "vertexCount : %d\n", vertexCount);
	_RPT1(0, "textureCount : %d\n", textureCount);
	_RPT1(0, "normalCount : %d\n", normalCount);
	_RPT1(0, "faceCount : %d\n", faceCount);

	// Now read the data from the file into the data structures
	// and then output it in our model format.
	result = LoadDataStructuresMyModelObj(
		// MyModelObj object with the data structures to store the element values with.
		curModelObj,
		myObjFilePath, // WYO file to read data from.
		// Number of "v" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		vertexCount,
		// Number of "vt" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		textureCount,
		// Number of "vn" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		normalCount,
		// Number of "f" elements loaded above to initialize the data structure 
		// inside ModelObj object.
		faceCount);

	// Return false if sub function call LoadDataStructuresMyModelObj() 
	// returned false.
	if (!result) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myObjLoader::Data strucutre inside ModelObj object created failed or storing values into the data strucutre inside ModelObj failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myObjLoader::Data strucutre inside ModelObj object created failed or storing values into the data strucutre inside ModelObj failed!!!\n");

		return false;
	}

	//==========================================================================
	// Retrieve the data structure pointers inside ModelObj object
	// after initializaions for more processing.
	//==========================================================================
	// Data structure of "v" elements initialzied inside ModelObj object.
	VertexType *vertices = ((ModelObj *)curModelObj)->getModelVertices();
	// Number of "v" elements initialzied inside ModelObj object.
	int numVertices = ((ModelObj *)curModelObj)->getVertexCount();

	// Data structure of "vt" elements initialzied inside ModelObj object.
	VertexType *texcoords = ((ModelObj *)curModelObj)->getTexcoords();
	// Number of "vt" elements initialzied inside ModelObj object.
	int numTexture = ((ModelObj *)curModelObj)->getTextureCount();

	// Data structure of "vn" elements initialzied inside ModelObj object.
	VertexType *normals = ((ModelObj *)curModelObj)->getNormals();
	// Number of "vn" elements initialzied inside ModelObj object.
	int numNormals = ((ModelObj *)curModelObj)->getNormalCount();

	// Data structure of "f" elements initialzied inside ModelObj object.
	FaceType *faces = ((ModelObj *)curModelObj)->getFaces();
	// Number of "f" elements initialzied inside ModelObj object.
	int numFaces = ((ModelObj *)curModelObj)->getFaceCount();


	//==========================================================================
	// Need to do one more step to initialize the vertex buffer to be rendered
	// on the main screen through DirectX 12 engine.
	// 
	// Is to duplicate the vertices to match texture coordinates counts,
	// mostly for texture mapping.
	// 
	// Detailed algorithm is explained in the function document.
	//==========================================================================
	((ModelObj *)curModelObj)->duplicateverticesPositionColorTexture(
		vertices,
		texcoords,
		normals,
		faces,
		numFaces);

	// Retrieve the texture coordinate indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [t1,t2,t2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ...)
	((ModelObj *)curModelObj)->texcoordsIndicesCalcFromFacesbuffer(
		faces, numFaces);
	// Retrieve the vertex indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [v1,v2,v2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ... )
	((ModelObj *)curModelObj)->vertexIndicesCalcFromFacesbuffer(
		faces, numFaces);
	// Retrieve the normal vector indices from the faces element and store
	// it to the data structure inside ModelObj object.
	// (Retrieve [n1,n2,n2 ...] from "f v1/t1/n1 v2/t2/n2 v3/t3/n3" ... )
	((ModelObj *)curModelObj)->normalIndicesCalcFromFacesbuffer(
		faces, numFaces);

	//==========================================================================
	// Print to check results testing normals
	//==========================================================================
	for (int i = 0; i < numNormals; i++) {
		_RPT1(0, "normals : %f %f %f\n",
			normals[i].x,
			normals[i].y,
			normals[i].z);
	}
	//==========================================================================
	_RPT1(0, "MyModelObj END==============================================================================\n", 0);

	// Return the resultng MyModelObj object.
	return curModelObj;
}

/*
*	Custom exported WYM file (.wym extension) - Opens and reads from custom
*		exported MTL file to initialize the MyModelMtl object which contiains 
*		the material information values to be used for rendering.
*	<p>
*	This function opens and reads the custom exported WYM file on given file 
*		path, creates a MyModelMtl object and
*		intialize the data to be held as a material object.
*	The elements to be loaded and be initialized onto the ModelMtl object
*		are as follows:
*		mtl_material_count - Number of material objects
*		mtl_material_name - Material name
*		mtl_mirror_color - Material ambient color
*		mtl_ambient - Material ambient intensity
*		mtl_diffuse_color - Material diffuse color
*		mtl_diffuse_intensity - Material diffuse intensity
*		mtl_specular_color - Material specular color
*		mtl_specular_intensity - Material specular intensity
*		mtl_specular_hardness - Material specular hardness (Exponent)
*		mtl_emit - Emission color
*		mtl_raytrace_transparency_ior - Reflection index
*		mtl_alpha - Dissolve, alpha
*		mtl_texture_map_image_path - Texture image file path
*
*	@param		filePath		Custom exported WYM absolute file path to be 
*								opened for reading the material file with.
*	@return		Return a MyModelMtl object initialized with
*					the model data read from MTL file
*					opened with given file path.
*	@since		ver0003
*/
MyModelMtl *MyModelLoader::myMtlLoader(char *myMtlFilePath) {
	// Init resulting ModelMtl object.
	MyModelMtl *curModelMtl = new MyModelMtl();

	// Retrieve directory path from the MTL absolute file path.
	char *dirPath
		= this->modelLoaderUtils->getFolderPathFromFileName(myMtlFilePath);
	// Set current WYM directory path onto the MyModelMtl object.
	((ModelMtl *)curModelMtl)->setCurrentMtlDirectoyPath(dirPath);

	// ifstream to open the file with.
	ifstream fin;
	// Local string variable to read from the file.
	std::string line;

	// Open the file.
	fin.open(myMtlFilePath);

	_RPT1(0, "MyModelMtl START==============================================================================\n", 0);
	_RPT1(0, "MyModelMtl created : %s\n", myMtlFilePath);
	_RPT1(0, "MyModelMtl START==============================================================================\n", 0);

	// Check if it was successful in opening the custom exported WYM file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myMtlLoader::Custom WYM file open failed!!! : %s\n", myMtlFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myMtlLoader::Custom WYM file open failed!!!");
	}

	// Read in the material data values into the MyModelMtl object.
	//*		mtl_material_count - Number of material objects
	//*		mtl_material_name - Material name
	//*		mtl_mirror_color - Material ambient color
	//*		mtl_ambient - Material ambient intensity
	//*		mtl_diffuse_color - Material diffuse color
	//*		mtl_diffuse_intensity - Material diffuse intensity
	//*		mtl_specular_color - Material specular color
	//*		mtl_specular_intensity - Material specular intensity
	//*		mtl_specular_hardness - Material specular hardness (Exponent)
	//*		mtl_emit - Emission color
	//*		mtl_raytrace_transparency_ior - Reflection index
	//*		mtl_alpha - Dissolve, alpha
	//*		mtl_texture_map_image_path - Texture image file path
	while (std::getline(fin, line)) {
		// Current line of the file.
		char *lineCStr = (char *)line.c_str();

		// [Key Value] --> Tokenize with white space character --> [Key][Value].
		char *token = strtok(lineCStr, " ");
		//_RPT1(0, "first token : %s\n", token);

		//----------------------------------------------------------------------
		// mtl_material_count
		//----------------------------------------------------------------------
		// Load the "mtl_material_count" element integer value
		// If tokenized [Key] string equal to "mtl_material_count".
		if (strcmp(token, "mtl_material_count") == 0) {
			// Tokenize again with whit space char to retrieve the string value.
			token = strtok(NULL, " ");
			//_RPT1(0, "toekn : %s\n", token);

			// String --> Integer value.
			int temp = int(strtof(token, NULL));
			//_RPT1(0, "temp : %d\n", temp);

			// Set MyModelMtl object material count.
			curModelMtl->setMaterialCount(temp);
			//_RPT1(0, "mtl_material_count : %d\n", curModelMtl->getMaterialCount());
		}
		//----------------------------------------------------------------------
		// mtl_material_name
		//----------------------------------------------------------------------
		// Load the "mtl_material_name" element string value
		// If tokenized [Key] string equal to "mtl_material_name".
		else if (strcmp(token, "mtl_material_name") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			//_RPT1(0, "toekn : %s\n", token);

			// Set MyModelMtl object material name.
			curModelMtl->setMaterialName(token);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_material_name : %s\n",
				curModelMtl->getMaterialName());
		}
		//----------------------------------------------------------------------
		// mtl_mirror_color
		//----------------------------------------------------------------------
		// Load the "mtl_mirror_color" element XMFLOAT3 value
		// If tokenized [Key] string equal to "mtl_mirror_color".
		else if (strcmp(token, "mtl_mirror_color") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// Local variables to store the data values loaded from file.
			float f1, f2, f3; // Color XMFLOAT3 value.

			// Get 3 float values from rest of the string tokenized above.
			char *temp1end;
			char *temp2end;
			f1 = strtof(token, &temp1end);		// First float value.
			f2 = strtof(temp1end, &temp2end);	// Second float value.
			f3 = strtof(temp2end, NULL);		// Third float value.

			// Set MyModelMtl object mirror color value.
			curModelMtl->setMaterialMirrorColor(XMFLOAT3(f1, f2, f3));
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_mirror_color : %f, %f, %f\n",
				curModelMtl->getMaterialMirrorColor().x,
				curModelMtl->getMaterialMirrorColor().y,
				curModelMtl->getMaterialMirrorColor().z);
		}
		//----------------------------------------------------------------------
		// mtl_mirror_color
		//----------------------------------------------------------------------
		// Load the "mtl_mirror_color" element float value
		// If tokenized [Key] string equal to "mtl_mirror_color".
		else if (strcmp(token, "mtl_ambient") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// String --> float value.
			float temp = strtof(token, NULL);

			// Set MyModelMtl object ambient intensity value.
			curModelMtl->setMaterialAmbient(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_ambient : %f\n", curModelMtl->getMaterialAmbient());
		}
		//----------------------------------------------------------------------
		// mtl_diffuse_color
		//----------------------------------------------------------------------
		// Load the "mtl_diffuse_color" element XMFLOAT3 value
		// If tokenized [Key] string equal to "mtl_diffuse_color".
		else if (strcmp(token, "mtl_diffuse_color") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// Local variables to store the data values loaded from file.
			float f1, f2, f3;
			// Get 3 float values from rest of the string tokenized above.
			char *temp1end;
			char *temp2end;
			f1 = strtof(token, &temp1end);		// First float value.
			f2 = strtof(temp1end, &temp2end);	// Second float value.
			f3 = strtof(temp2end, NULL);		// Third float value.

			// Set MyModelMtl object diffuse color value.
			curModelMtl->setMaterialDiffuseColor(XMFLOAT3(f1, f2, f3));

			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_diffuse_color : %f, %f, %f\n",
				curModelMtl->getMaterialDiffuseColor().x,
				curModelMtl->getMaterialDiffuseColor().y,
				curModelMtl->getMaterialDiffuseColor().z);
		}
		//----------------------------------------------------------------------
		// mtl_diffuse_intensity
		//----------------------------------------------------------------------
		// Load the "mtl_diffuse_intensity" element float value
		// If tokenized [Key] string equal to "mtl_diffuse_intensity".
		else if (strcmp(token, "mtl_diffuse_intensity") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// String --> Float value.
			float temp = strtof(token, NULL);

			// Set MyModelMtl object diffuse intensity value.
			curModelMtl->setMaterialDiffuseIntensity(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_diffuse_intensity : %f\n",
				curModelMtl->getMaterialDiffuseIntensity());
		}
		//----------------------------------------------------------------------
		// mtl_specular_color
		//----------------------------------------------------------------------
		// Load the "mtl_diffuse_intensity" element XMFLOAT3 value
		// If tokenized [Key] string equal to "mtl_specular_color".
		else if (strcmp(token, "mtl_specular_color") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// Local variables to store the data values loaded from file.
			float f1, f2, f3;
			// Get 3 float values from rest of the string tokenized above.
			char *temp1end;
			char *temp2end;
			f1 = strtof(token, &temp1end);		// First float value.
			f2 = strtof(temp1end, &temp2end);	// Second float value.
			f3 = strtof(temp2end, NULL);		// Third float value.

			// Set MyModelMtl object specular color value.
			curModelMtl->setMaterialSpecularColor(XMFLOAT3(f1, f2, f3));
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_specular_color : %f, %f, %f\n",
				curModelMtl->getMaterialSpecularColor().x,
				curModelMtl->getMaterialSpecularColor().y,
				curModelMtl->getMaterialSpecularColor().z);
		}
		//----------------------------------------------------------------------
		// mtl_specular_intensity
		//----------------------------------------------------------------------
		// Load the "mtl_specular_intensity" element float value
		// If tokenized [Key] string equal to "mtl_specular_intensity".
		else if (strcmp(token, "mtl_specular_intensity") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			// String --> float value.
			float temp = strtof(token, NULL);
			// Set MyModelMtl object specular intensity value.
			curModelMtl->setMaterialSpecularIntensity(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_specular_intensity : %f\n",
				curModelMtl->getMaterialSpecularIntensity());
		}
		//----------------------------------------------------------------------
		// mtl_specular_hardness
		//----------------------------------------------------------------------
		// Load the "mtl_specular_hardness" element float value
		// If tokenized [Key] string equal to "mtl_specular_hardness".
		else if (strcmp(token, "mtl_specular_hardness") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			// String --> float value.
			float temp = strtof(token, NULL);
			// Set MyModelMtl object specular hardness value.
			curModelMtl->setMaterialSpecularHardness(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_specular_hardness : %f\n",
				curModelMtl->getMaterialSpecularHardness());
		}
		//----------------------------------------------------------------------
		// mtl_emit
		//----------------------------------------------------------------------
		// Load the "mtl_emit" element float value
		// If tokenized [Key] string equal to "mtl_emit".
		else if (strcmp(token, "mtl_emit") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			// String --> float value.
			float temp = strtof(token, NULL);
			// Set MyModelMtl object emission value.
			curModelMtl->setMaterialEmit(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_emit : %f\n",
				curModelMtl->getMaterialEmit());
		}
		//----------------------------------------------------------------------
		// mtl_raytrace_transparency_ior
		//----------------------------------------------------------------------
		// Load the "mtl_emit" element float value
		// If tokenized [Key] string equal to "mtl_raytrace_transparency_ior".
		else if (strcmp(token, "mtl_raytrace_transparency_ior") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			// String --> float value.
			float temp = strtof(token, NULL);
			// Set MyModelMtl object raytrace transparency IOR value.
			curModelMtl->setMaterialRaytraceTransparencyIOR(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_raytrace_transparency_ior : %f\n",
				curModelMtl->getMaterialRaytraceTransparencyIOR());
		}
		//----------------------------------------------------------------------
		// mtl_alpha
		//----------------------------------------------------------------------
		// Load the "mtl_alpha" element float value
		// If tokenized [Key] string equal to "mtl_alpha".
		else if (strcmp(token, "mtl_alpha") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");
			// String --> float value.
			float temp = strtof(token, NULL);
			// Set MyModelMtl object alpha value.
			curModelMtl->setMaterialAlpha(temp);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_alpha : %f\n", curModelMtl->getMaterialAlpha());
		}
		//----------------------------------------------------------------------
		// mtl_texture_map_image_path
		//----------------------------------------------------------------------
		// Load the "mtl_texture_map_image_path" element string value
		// If tokenized [Key] string equal to "mtl_texture_map_image_path".
		else if (strcmp(token, "mtl_texture_map_image_path") == 0) {
			// Tokenize again with white space charater to retrieve the rest 
			// of the string.
			token = strtok(NULL, " ");

			// Local buffer.
			char textureMapImageFilePath[BUFSIZ];
			// Store current MTL directory path 
			// to the local buffer.
			strcpy(textureMapImageFilePath, 
				((ModelMtl *)curModelMtl)->getCurrentMtlDirectoyPath());
			// Append '\'.
			strcat(textureMapImageFilePath, "\\");
			// Append "mtl_texture_map_image_path" file name.
			strcat(textureMapImageFilePath, token);

			// Set MyModelMtl object texture image file path value.
			curModelMtl->setMaterialTextureMapImagePath(textureMapImageFilePath);
			_RPT1(0, "MyModelLoader::myMtlLoader::mtl_texture_map_image_path : %s\n",
				curModelMtl->getMaterialTextureMapImagePath());
		}
		// Else loading invalid element.
		else {
			_RPT1(0, "################################################################################\n", 0);
			_RPT1(0, "ERROR::MyModelLoader::myMtlLoader::Loading invalid element!!!\n", 0);
			_RPT1(0, "################################################################################\n", 0);
			throw std::runtime_error("ERROR::MyModelLoader::myMtlLoader::Loading invalid element!!!\n");
			return NULL;
		}
	}
	_RPT1(0, "MyModelMtl END==============================================================================\n", 0);
	// Return the resulting ModelMtl object.
	return curModelMtl;
}

/*
*	Custom armature file (.arm extension) - Opens and reads from custom exported 
*		armature file to initialize the MyModelArmature object which contiains 
*		the armature information values to be used for rendering.
*	<p>
*	This function opens and reads the custom exported armature file on given
*		file path, creates a MyModelAramture object and
*		intialize the data to be held as a armature object
*		by reading in each bone data and creates MyModelArmatureBone object.
*	The elements to be loaded and be initialized onto MyModelArmature object
*		are as follows:
*		count - Number of bone objects to be loaded.
*		and will hold multiple MyModelArmatureBone objects for rendering.
*	The elements to be loaded and be initialized onto MyModelArmatureBone object
*		are as follows:
*		bn - Current bone name.
*		bt - Current bone's tail coordinate value.
*		bh - Current bone's head coordinate value.
*		------------------------------------------------------------------------
*		Here, the main algorithm is to get "count" element to initalize the data
*		strucutre to hold the bones data by passing "count" element value to the
*		MyModelArmature object general constructor, so now the armature bones,
*		MyModelArmatureBone objects are initialized in the data structure and 
*		are ready to store the bone data value in, then start loading the bone's
*		data into each initialized MyModelArmatureBone objects inside 
*		MyModelArmature object's main data structure. There are 3 data will be 
*		loaded onto each MyModelArmatureBone object, is name, tail and head 
*		coordinate values. Whenever the tail and head coordinate is set to the 
*		MyModelArmatureBone object, it will automatically set the first point
*		and second point coordinate inside their Line object, and this Line 
*		object will have all the armature bone's resources and buffer to be 
*		rendered on screen. So I can set the vertex, index and constant buffer
*		of each Line object inside MyModelArmatureBone object to render the 
*		armature bones to the screen.
*		------------------------------------------------------------------------
*	@param		myArmatureFilePath			Custome exported armature file
*											absolute file path to be
*											opened for reading
*	@return		Return a MyModelArmature object initialized with
*					the multiple bone data initialized onto the 
*					MyModelArmatureBone object loaded from the armature file
*					 opened with given file path.
*	@since		ver0022
*/
MyModelArmature *MyModelLoader::myArmatureLoader(char *myArmatureFilePath) {
	// Init resulting MyModelArmature object
	MyModelArmature *curModelArmature = NULL;

	//==========================================================================
	// Init local buffers for current project directory path retrieving.
	//==========================================================================
	// Local buffer to hold the final absolute armature file path to load with.
	char finalArmatureAbsFilePath[FILENAME_MAX];
	std::fill(finalArmatureAbsFilePath,
		finalArmatureAbsFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the armature file path.
	char currentArmatureFilePath[FILENAME_MAX];
	std::fill(currentArmatureFilePath,
		currentArmatureFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the armature file name.
	char currentArmatureFileName[FILENAME_MAX];
	std::fill(currentArmatureFileName,
		currentArmatureFileName + FILENAME_MAX, NULL);

	// Get current working directory path and store it into local buffers.
	if (!GetCurrentDir(currentArmatureFilePath, sizeof(currentArmatureFilePath))) {
		// If failed.
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myArmatureLoader::GetCurrentDir() failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myArmatureLoader::GetCurrentDir() failed!!!\n");
		return NULL;
	}

	//==========================================================================
	// Need to specify to the Debug folder because all the assets are in the 
	// project's Debug folder, but this get current directory function is 
	// retrieving the directory path of current file MyModelLoader.cpp
	// so i concat "\..\Debug" to specify to the Debug folder in current 
	// project folder.
	//==========================================================================
	// Append "\..\Debug".
	strncat_s(
		currentArmatureFilePath, FILENAME_MAX,
		"\\..\\Debug", FILENAME_MAX);

	/* not really required */
	currentArmatureFilePath[sizeof(currentArmatureFilePath) - 1] = '\0';
	//==========================================================================

	// Print current working directory path.
	_RPT1(0, "MyModelLoader::myArmatureLoader::The current working directory is: |%s|\n", currentArmatureFilePath);

	// Copy armature file name to a local buffer.
	strcpy(currentArmatureFileName, myArmatureFilePath);

	// Copy working directory path to another local buffer.
	strncpy_s(finalArmatureAbsFilePath, FILENAME_MAX,
		currentArmatureFilePath, FILENAME_MAX);

	// Concat armature file name onto current working directory path.
	strncat_s(finalArmatureAbsFilePath, FILENAME_MAX,
		currentArmatureFileName, FILENAME_MAX);

	// Print current working directory path.
	_RPT1(0, "MyModelLoader::myArmatureLoader::Loading armature from file: |%s|\n", finalArmatureAbsFilePath);


	// ifstream to open the file with.
	ifstream fin;
	// Local character variable to read from the file.
	char input = '\0';

	// Open the file.
	fin.open(finalArmatureAbsFilePath);

	_RPT1(0, "MyModelArmature START==============================================================================\n", 0);
	_RPT1(0, "MyModelArmature created : %s\n", finalArmatureAbsFilePath);
	_RPT1(0, "MyModelArmature START==============================================================================\n", 0);
	
	// Check if it was successful in opening the armature file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myArmatureLoader::Custom armature file open failed!!! : %s\n", finalArmatureAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myArmatureLoader::Custom armature file open failed!!!");
	}

	// Boolean values to check the data structure is created before storing 
	// values into it.
	bool datastructureCreated = false;

	// Boolean values to check the coordinate system options are loaded to be 
	// used for converting the data values to be stored into the data structure.
	bool coordsystemLoaded = false; // UP and FORWARD vector is loaded.
	bool coordsystemCULoaded = false; // Coordinate system UP vector
	bool coordsystemCFLoaded = false; // Coordinate system FORWARD vector

	// Number of bone name loaded.
	int boneNameCounter = 0;
	// Number of bone tail coordinates loaded.
	int boneTailCounter = 0;
	// Number of bone head coordinates loaded.
	int boneHeadCounter = 0;

	// Read in the armature data values into the MyModelArmature object.
	//*		count - Number of bone objects to be loaded.
	//*		bn - Current bone name.
	//*		bt - Current bone's tail coordinate value.
	//*		bh - Current bone's head coordinate value.
	fin.get(input);
	while (!fin.eof()) {
		//======================================================================
		// Read in number of bones first for data structure creation.
		//======================================================================
		// Create the data structure first using the "count" element loaded, so
		// I can start loading the bone values into the initialized data 
		// structure.
		//------------------------------------------------------------------
		// count - Number of bones in the armature file.
		//------------------------------------------------------------------
		if (!datastructureCreated && input == 'c') {
			fin.get(input);
			if (input == 'o') {
				fin.get(input);
				if (input == 'u') {
					fin.get(input);
					if (input == 'n') {
						fin.get(input);
						if (input == 't') {
							fin.get(input);
							if (input == ' ') {
								// Local variable to hold the loaded data with.
								int tempCount = 0;
								// Read in a integer value.								int tempCount = 0;
								fin >> tempCount;
								
								// Create MyModelArmature object passing bone
								// count so MyModelArmatureBone objects is 
								// initialized in the data structure so i can
								// start loading the bone data values into each
								// MyModelArmatureBone objects.
								curModelArmature
									= new MyModelArmature(tempCount);
								_RPT1(0, "MyModelLoader::myArmatureLoader::Number of bones in armature : %d\n", curModelArmature->getNumArmatureBones());
								
								// Set the data structure creation flag on 
								// if only the data structure inside
								// MyModelArmature object is created 
								// properly before storing values into it.
								if (curModelArmature != NULL && 
									curModelArmature->getNumArmatureBones() 
										> 0) {
									datastructureCreated = true;
								}
							}
						}
					}
				}
			}
		}

		//======================================================================
		// Coordinate system options - CU, CF
		//======================================================================
		// If data structure is created, i can now load the coordinate system
		// options indicated in the armature file, so i can convert the 
		// coordinate values whenver loading a new coordinate. So the coordinate
		// system option values must be set to the current MyModelArmature 
		// object before loading the bone's tail and head coordinate in.
		if (datastructureCreated && !coordsystemLoaded && input == 'C') {
			//------------------------------------------------------------------
			// CU - Coordinate system option UP vector
			//------------------------------------------------------------------
			fin.get(input);
			if (input == 'U') { //  [Up]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;

					// Read "CU" string into local buffer.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';

					//----------------------------------------------------------
					// Need to cast with MyModelObj in order to convert the 
					// tail head coordinate values with coordinate options
					// specified in the file.
					//----------------------------------------------------------
					// Set the coordinate system option UP string onto 
					// MyModelArmature object.
					((MyModelObj *)curModelArmature)
						->set_coordoption_up_str(temp);
					_RPT1(0, "MyModelLoader::myArmatureLoader::CU : %s\n", ((MyModelObj *)curModelArmature)->get_coordoption_up_str());

					// Set coordinate system UP vector string loaded flag on.
					coordsystemCULoaded = true;
				}
			}

			//------------------------------------------------------------------
			// CF - Coordinate system option FORWARD vector
			//------------------------------------------------------------------
			if (input == 'F') { //  [Forward]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;

					// Read "CF" string into local buffer.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';
					//----------------------------------------------------------
					// Need to cast with MyModelObj in order to convert the 
					// tail head coordinate values with coordinate options
					// specified in the file.
					//----------------------------------------------------------
					// Set the coordinate system option FORWARD string onto 
					// MyModelArmature object.
					((MyModelObj *)curModelArmature)
						->set_coordoption_forward_str(temp);
					_RPT1(0, "MyModelLoader::myArmatureLoader::CF : %s\n", ((MyModelObj *)curModelArmature)->get_coordoption_forward_str());
					
					// Set coordinate system FORWARD vector string 
					// loaded flag on.
					coordsystemCFLoaded = true;
				}
			}

			// Set coordinate system options CU and CF string loaded flag on.
			if (coordsystemCULoaded && coordsystemCFLoaded) {
				coordsystemLoaded = true;
			}
		}

		//======================================================================
		// Start loading bone data IF:
		//======================================================================
		//		- If the data structure inside MyModelArmature object 
		//		  is initialized is ready to store bone data value to the
		//		  MyModelArmatureBone objects initialzied inside it.
		//		- If the coordinate system options are loaded onto the 
		//		  MyModelArmature object is ready to convert the coordinate 
		//		  values.
		//======================================================================
		if (datastructureCreated &&		// Data structure created.
			coordsystemLoaded &&		// Coordinate system options loaded.
			curModelArmature != NULL) {
			if (input == 'b') {
				fin.get(input);
				//--------------------------------------------------------------
				// bn - Bone name.
				//--------------------------------------------------------------
				if (input == 'n') {
					fin.get(input);
					if (input == ' ') {
						// Local buffer.
						char temp[BUFSIZ];
						int count = 0;

						// Read bone name string into local buffer.
						while (input != '\n') {
							fin.get(input);
							temp[count] = input;
							count++;
						}
						temp[count - 1] = '\0';

						// Set current armature bone's bone name.
						curModelArmature->getArmatureBoneAtIndex(boneNameCounter)
							->setArmatureBoneName(temp);
						_RPT1(0, "MyModelLoader::myArmatureLoader::bn : |%s|\n", curModelArmature->getArmatureBoneAtIndex(boneNameCounter)->getArmatureBoneName());
						
						// Increment bone counter if a new bone name is loaded.
						boneNameCounter++;
					}
				}
				//--------------------------------------------------------------
				// bt - Bone tail coordinate.
				//--------------------------------------------------------------
				if (input == 't') {
					//----------------------------------------------------------
					// Read in a single vertex (3 floats) and convert the 
					// vertex value  by calling 
					// Util::coordinateSystemConversionFromBlenderToDirectX()
					// function passing current MyModelArmature object for 
					// coordinate system option retrieval and ifstream address  
					// to read 3 float values and return the converted 
					// VertexType pointer.
					//----------------------------------------------------------
					VertexType *resultCoord
						= this->modelLoaderUtils->
						coordinateSystemConversionFromBlenderToDirectX(
							((MyModelObj *)curModelArmature), &fin);
					// Conver the converted VertexType value to XMFLOAT3.
					XMFLOAT3 temp = XMFLOAT3(
						resultCoord->x,
						resultCoord->y,
						resultCoord->z);

					//float x, y, z;
					//fin >> z >> x >> y;
					//x *= -1;

					//// Conver the converted VertexType value to XMFLOAT3.
					//XMFLOAT3 temp = XMFLOAT3(
					//	x, 
					//	y,
					//	z);

					// Set current armature bone's tail coordinate.
					curModelArmature->getArmatureBoneAtIndex(boneTailCounter)
						->setBoneTail(temp);
					_RPT1(0, "MyModelLoader::myArmatureLoader::bt : %f, %f, %f\n",
						curModelArmature->getArmatureBoneAtIndex(boneTailCounter)->getBoneTail().x,
						curModelArmature->getArmatureBoneAtIndex(boneTailCounter)->getBoneTail().y,
						curModelArmature->getArmatureBoneAtIndex(boneTailCounter)->getBoneTail().z);
					// Increment bone tail counter because a bone only 
					// have one tail coordinate.
					boneTailCounter++;
				}
				//--------------------------------------------------------------
				// bh - Bone head coordinate.
				//--------------------------------------------------------------
				if (input == 'h') {
					//----------------------------------------------------------
					// Read in a single vertex (3 floats) and convert the 
					// vertex value  by calling 
					// Util::coordinateSystemConversionFromBlenderToDirectX()
					// function passing current MyModelArmature object for 
					// coordinate system option retrieval and ifstream address  
					// to read 3 float values and return the converted 
					// VertexType pointer.
					//----------------------------------------------------------
					VertexType *resultCoord
						= this->modelLoaderUtils
						->coordinateSystemConversionFromBlenderToDirectX(
						((MyModelObj *)curModelArmature), &fin);

					// Conver the converted VertexType value to XMFLOAT3.
					XMFLOAT3 temp = XMFLOAT3(
						resultCoord->x, 
						resultCoord->y, 
						resultCoord->z);
					// Set current armature bone's head coordinate.
					curModelArmature->getArmatureBoneAtIndex(boneHeadCounter)
						->setBoneHead(temp);
					_RPT1(0, "MyModelLoader::myArmatureLoader::bh [%d]: %f, %f, %f\n", boneHeadCounter,
						curModelArmature->getArmatureBoneAtIndex(boneHeadCounter)->getBoneHead().x,
						curModelArmature->getArmatureBoneAtIndex(boneHeadCounter)->getBoneHead().y,
						curModelArmature->getArmatureBoneAtIndex(boneHeadCounter)->getBoneHead().z);
					// Increment bone tail counter because a bone only 
					// have one tail coordinate.
					boneHeadCounter++;
				}
			}
		}
		// Read in the remainder of the line.
		while (input != '\n') {
			fin.get(input);
		}

		// Start reading the beginning of the next line.
		fin.get(input);
	}
	_RPT1(0, "MyModelArmature END==============================================================================\n", 0);

	// Error handling 1:
	// Data structure to store the data values read from the file is not created
	// properly.
	if (!datastructureCreated) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myArmatureLoader::Data structure creation failed!!! : %s\n", finalArmatureAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myArmatureLoader::Data structure creation failed!!!");
	}
	// Error handling 2:
	// If coordinate system option CU and CF elements are not loaded properly.
	if (!coordsystemLoaded) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myArmatureLoader::Coordinate system options loaded failed!!! : %s\n", finalArmatureAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myArmatureLoader::Coordinate system options loaded failed!!!");
	}

	// Return the resulting MyModelArmature object.
	return curModelArmature;
}
//##############################################################################

/*
*	Custom animation file (.arm extension) - Opens and reads from custom 
*		exported animation file to initialize the MyModelAnimation object which 
*		contiains the animation information values to be used for applying
*		animation onto the existing MyModelArmature object.
*	<p>
*	This function opens and reads the custom exported animation file on given
*		file path, creates a MyModelAnimation object and
*		intialize the data structure to hold the animation bone datas
*		MyModelAnimationBone objects, where each MyModelAnimationBone object 
*		holds a(or multiple) queue type of animation frame data structure to 
*		be used for playing the animation on frame tic.
*	The elements to be loaded and be initialized onto MyModelAnimation object
*		are as follows:
*		Multiple MyModelAniamtionBone object which itself holds the animation 
*		data, so this MyModelAnimation object is the wrapper class to manage
*		all the animation bone in a file to represent an animation file to be
*		applied to the armature bones for animation.
*	The elements to be loaded and be initialized onto MyModelAnimationBone 
*		object are as follows:
*		bn - Current animaitonbone name.
*			Follow by animation frame data in following format: "<()()()()>"
*			which is the XMFLOAT4X4 representation wherer XMFLOAT4 value is 
*			stored in "()".
*			All the animation frame data follow by the bone name, will be 
*			inserted to the animation queue inside current MyModelAnimationBone
*			object with the name loaded just now.
*		------------------------------------------------------------------------
*		Here, the main algorithm is to first initalize the MyModelAnimation 
*		object if animation file opened successfully, and then start loading the
*		animation bone datas. Whenever "bn" element is read a 
*		MyModelAnimationBone object is created using the current 
*		MyModelAnimationBone pointer local variable, so the animation frame data
*		XMFLOAT4X4 value follow by the bone name will be inserted to the 
*		MyModelAnimationBone object's main Queue<XMFLOAT4X4> type data
*		structure. 
*		Then i can apply this MyModelAnimation object to a existing 
*		MyModelArmature object, then loop through the MyModelArmature object
*		to apply the animation to the matching bones using their names, updates
*		set the armature bone's constant buffer world matrix with the XMFLOAT4X4
*		value so the armature bone is rendered with the given animation frame 
*		data, so the armature animates along frame counter.
*		------------------------------------------------------------------------
*	@param		myArmatureFilePath			Custome exported armature file
*											absolute file path to be
*											opened for reading
*	@return		Return a MyModelArmature object initialized with
*					the multiple bone data initialized onto the
*					MyModelArmatureBone object loaded from the armature file
*					 opened with given file path.
*	@since		ver0022
*/
MyModelAnimation *MyModelLoader::myAnimationLoader(char *myAnimationFilePath) {
	// Init resulting MyModelArmature object to return
	MyModelAnimation *curModelAnimation = NULL;

	//==========================================================================
	// Init local buffers for current project directory path retrieving.
	//==========================================================================
	// Local buffer to hold the final absolute animation file path to load with.
	char finalAnimationAbsFilePath[FILENAME_MAX];
	std::fill(finalAnimationAbsFilePath,
		finalAnimationAbsFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the animation file path.
	char currentAnimationFilePath[FILENAME_MAX];
	std::fill(currentAnimationFilePath,
		currentAnimationFilePath + FILENAME_MAX, NULL);
	// Local buffer to hold the animation file name.
	char currentAnimationFileName[FILENAME_MAX];
	std::fill(currentAnimationFileName,
		currentAnimationFileName + FILENAME_MAX, NULL);

	// Get current working directory path and store it into local buffers.
	if (!GetCurrentDir(currentAnimationFilePath, sizeof(currentAnimationFilePath))) {
		// If failed.
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myAnimationLoader::GetCurrentDir() failed!!!\n", 0);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myAnimationLoader::GetCurrentDir() failed!!!\n");
		return NULL;
	}

	//==========================================================================
	// Need to specify to the Debug folder because all the assets are in the 
	// project's Debug folder, but this get current directory function is 
	// retrieving the directory path of current file MyModelLoader.cpp
	// so i concat "\..\Debug" to specify to the Debug folder in current 
	// project folder.
	//==========================================================================
	// Append "\..\Debug".
	strncat_s(
		currentAnimationFilePath, FILENAME_MAX,
		"\\..\\Debug", FILENAME_MAX);

	/* not really required */
	currentAnimationFilePath[sizeof(currentAnimationFilePath) - 1] = '\0';
	//==========================================================================

	// Print current working directory path.
	_RPT1(0, "MyModelLoader::myAnimationLoader::The current working directory is: |%s|\n", currentAnimationFilePath);

	// Copy animation file name to a local buffer.
	strcpy(currentAnimationFileName, myAnimationFilePath);

	// Copy working directory path to another local buffer.
	strncpy_s(finalAnimationAbsFilePath, FILENAME_MAX,
		currentAnimationFilePath, FILENAME_MAX);

	// Concat animation file name onto current working directory path.
	strncat_s(finalAnimationAbsFilePath, FILENAME_MAX,
		currentAnimationFileName, FILENAME_MAX);

	// Print current working directory path.
	_RPT1(0, "MyModelLoader::myAnimationLoader::Loading animation from file: |%s|\n", finalAnimationAbsFilePath);

	// ifstream to open the file with.
	ifstream fin;
	// Local character variable to read from the file.
	char input = '\0';

	// Open the file.
	fin.open(finalAnimationAbsFilePath);

	_RPT1(0, "MyModelAnimation START==============================================================================\n", 0);
	_RPT1(0, "MyModelAnimation created : %s\n", finalAnimationAbsFilePath);
	_RPT1(0, "MyModelAnimation START==============================================================================\n", 0);

	// Check if it was successful in opening the animation file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myAnimationLoader::Animation file open failed!!! : %s\n", finalAnimationAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myAnimationLoader::Animation file open failed!!!");
	}

	// Boolean values to check the coordinate system options are loaded to be 
	// used for converting the data values to be stored into the data structure.
	bool coordsystemLoaded = false; // UP and FORWARD vector is loaded.
	bool coordsystemCULoaded = false; // Coordinate system UP vector
	bool coordsystemCFLoaded = false; // Coordinate system FORWARD vector

	// Boolean values to check the data structure is created before storing 
	// values into it.
	bool datastructureCreated = false;

	// Boolean value to check the new animation bone is created for animation
	// frame data insersion.
	bool newAnimationBone = false;

	// Number of bone loaded from the animation file.
	int boneCounter = 0;

	// Animation frame loaded from the animation file onto current animation 
	// bone.
	int frameCounter = 0;

	//==========================================================================
	// Local pointer variable to keep track of current MyModelAnimationBone 
	// object loading the animation frame data with.
	//==========================================================================
	MyModelAnimationBone *currentAnimBonePtr = NULL;

	//==========================================================================
	// Read in the animation bone data values into the each MyModelAnimationBone
	// object.
	//*		bn - Current animation bone name to insert the animation frame data
	//*			 with.
	//*		bt - Current animation frame bone tail coordinate value.
	//*		bh - Current animation frame bone head coordinate value.
	//*		<()()()()> - Current animation bone world matrix.
	//*		tra - Current animation frame bone translation vector value.
	//*		rot - Current animation frame bone rotation quaternion value.
	//*		sca - Current animation frame bone scaling vector value.
	// Important: Also convert to left hand coordinate system ????
	//==========================================================================
	fin.get(input);
	while (!fin.eof()) {
		//======================================================================
		// Read in number of bones first for data structure creation.
		//======================================================================
		// Create the data structure first using the "count" element loaded, so
		// I can start loading the bone values into the initialized data 
		// structure.
		//------------------------------------------------------------------
		// count - Number of bones in the aniamtion file.
		//------------------------------------------------------------------
		if (!datastructureCreated && input == 'c') {
			fin.get(input);
			if (input == 'o') {
				fin.get(input);
				if (input == 'u') {
					fin.get(input);
					if (input == 'n') {
						fin.get(input);
						if (input == 't') {
							fin.get(input);
							if (input == ' ') {
								// Local variable to hold the loaded data with.
								int tempCount = 0;
								// Read in a integer value.
								fin >> tempCount;

								// Create MyModelAnimation object passing bone
								// count so MyModelAnimationBone objects is 
								// initialized in the data structure so i can
								// start loading the bone data values into each
								// MyModelAnimationBone objects.
								curModelAnimation 
									= new MyModelAnimation();
								_RPT1(0, "MyModelLoader::myAnimationLoader::Number of bones in animation armature : %d\n", tempCount);
								datastructureCreated = true;
							}
						}
					}
				}
			}
		}

		//======================================================================
		// Coordinate system options - CU, CF
		//======================================================================
		// If data structure is created, i can now load the coordinate system
		// options indicated in the armature file, so i can convert the 
		// coordinate values whenver loading a new coordinate. So the coordinate
		// system option values must be set to the current MyModelArmature 
		// object before loading the bone's tail and head coordinate in.
		if (datastructureCreated && !coordsystemLoaded && input == 'C') {
			//------------------------------------------------------------------
			// CU - Coordinate system option UP vector
			//------------------------------------------------------------------
			fin.get(input);
			if (input == 'U') { //  [Up]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;

					// Read "CU" string into local buffer.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';

					//----------------------------------------------------------
					// Need to cast with MyModelObj in order to convert the 
					// tail head coordinate values with coordinate options
					// specified in the file.
					//----------------------------------------------------------
					// Set the coordinate system option UP string onto 
					// MyModelArmature object.
					((MyModelObj *)curModelAnimation)
						->set_coordoption_up_str(temp);
					_RPT1(0, "MyModelLoader::myAnimationLoader::CU : %s\n", ((MyModelObj *)curModelAnimation)->get_coordoption_up_str());

					// Set coordinate system UP vector string loaded flag on.
					coordsystemCULoaded = true;
				}
			}

			//------------------------------------------------------------------
			// CF - Coordinate system option FORWARD vector
			//------------------------------------------------------------------
			if (input == 'F') { //  [Forward]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;

					// Read "CF" string into local buffer.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';
					//----------------------------------------------------------
					// Need to cast with MyModelObj in order to convert the 
					// tail head coordinate values with coordinate options
					// specified in the file.
					//----------------------------------------------------------
					// Set the coordinate system option FORWARD string onto 
					// MyModelArmature object.
					((MyModelObj *)curModelAnimation)
						->set_coordoption_forward_str(temp);
					_RPT1(0, "MyModelLoader::myAnimationLoader::CF : %s\n", ((MyModelObj *)curModelAnimation)->get_coordoption_forward_str());

					// Set coordinate system FORWARD vector string 
					// loaded flag on.
					coordsystemCFLoaded = true;
				}
			}

			// Set coordinate system options CU and CF string loaded flag on.
			if (coordsystemCULoaded && coordsystemCFLoaded) {
				coordsystemLoaded = true;
			}
		}

		//======================================================================
		// Start loading bone data IF:
		//======================================================================
		//		- If the data structure inside MyModelAniamtion object 
		//		  is initialized is ready to store bone data value to the
		//		  MyModelAniamtionBone objects initialzied inside it.
		//		- If the coordinate system options are loaded onto the 
		//		  MyModelAniamtion object is ready to convert the coordinate 
		//		  values.
		//======================================================================
		if (datastructureCreated &&		// Data structure created.
			coordsystemLoaded &&		// Coordinate system options loaded.
			curModelAnimation != NULL) {

			//==================================================================
			// Read in current bone's name "bn" element value
			// Create MyModelAnimationBone object to store current animation  
			// data values appended on next line of "bn" element until next
			// "bn" appears.
			// So whenever is reading "bn" element, a new animation bone will be
			// created, and the following animaiton frame data will be inserted to
			// the animation bone just created.
			//==================================================================
			if (input == 'b') {
				fin.get(input);
				//----------------------------------------------------------
				// bn - Animation bone name.
				//----------------------------------------------------------
				// Allocate a MyModelAnimationBone object using local 
				// "currentAnimBonePtr" pointer, and insert it into the 
				// data structure inside the resulting MyModelAnimation 
				// object allocated onto local variable "curModelAnimation",
				// when "count" attribute is loaded
				if (input == 'n') {
					fin.get(input);
					if (input == ' ') {

						// Local buffer.
						char temp[BUFSIZ];
						int count = 0;

						// Read bone name string into local buffer.
						while (input != '\n') {
							fin.get(input);
							temp[count] = input;
							count++;
						}
						temp[count - 1] = '\0';

						_RPT1(0, "Bone name : %s\n", temp);

						currentAnimBonePtr = NULL;
						// Create MyModelAnimationBone object for animation
						// data insertion onto the local MyModelAnimationBone
						// pointer variable, so i can access it on next loop to
						// insert the animation frame datas.
						currentAnimBonePtr = new MyModelAnimationBone();

						// Set current animation bone name.
						currentAnimBonePtr->setAnimationBoneName(temp);

						// If MyModelAnimationBone object is created properly.
						if (currentAnimBonePtr != NULL) {
							// Inserting current bone to the MyModelAnimation 
							// object's main data structure to manage all the 
							// animation bone inside.
							curModelAnimation->insertAnimationBone(
								currentAnimBonePtr);
						}

						// Increment bone counter.
						boneCounter++;

						newAnimationBone = false;
					}
				}
			}

			//==================================================================
			// Start loading animation frame data 
			// 
			// Pre-condition: Must have a MyModelAnimationBone object 
			//				  initialized onto the MyModelAnimationBone pointer 
			//				  local variable "currentAnimBonePtr" to insert 
			//				  current animation data values being loaded. 
			//==================================================================

			MyModelAnimationBoneData *currentAnimBoneFrameDataPtr = NULL;
			// If current aninmation bone is valid to insert the animation datas.
			if (currentAnimBonePtr != NULL && 
				datastructureCreated && 
				input == '{') {
				_RPT1(0, "Animation Frame START [%d]---------------------------------------------------\n", frameCounter);
				currentAnimBoneFrameDataPtr = new MyModelAnimationBoneData();
				while (input != '}') {
					fin.get(input);

					//==========================================================
					// Start loading animation bone data tail and head 
					// coordinate values indicated as "bt" and "bh" 
					// inside "{}", which means current animation frame.
					//==========================================================
					if (input == 'b') {
						fin.get(input);
						//------------------------------------------------------
						// bt - Bone tail coordinate.
						//------------------------------------------------------
						if (input == 't') {
							//--------------------------------------------------
							// Read in a single vertex (3 floats) and convert  
							// the vertex value  by calling Util::
							// coordinateSystemConversionFromBlenderToDirectX()
							// function passing current MyModelAnimation object  
							// for coordinate system option retrieval and    
							// ifstream address to read 3 float values and   
							// return the converted VertexType pointer.
							//--------------------------------------------------
							VertexType *resultCoord
								= this->modelLoaderUtils->
								coordinateSystemConversionFromBlenderToDirectX(
								((MyModelObj *)curModelAnimation), &fin);
							// Conver the converted VertexType value to XMFLOAT3.
							XMFLOAT3 temp = XMFLOAT3(
								resultCoord->x,
								resultCoord->y,
								resultCoord->z);

							// Set current animation frame data tail coordinate.
							currentAnimBoneFrameDataPtr->boneTail = temp;
							_RPT1(0, "MyModelLoader::myArmatureLoader::bt : %f, %f, %f\n",
								currentAnimBoneFrameDataPtr->boneTail.x,
								currentAnimBoneFrameDataPtr->boneTail.y,
								currentAnimBoneFrameDataPtr->boneTail.z);
						}
						//------------------------------------------------------
						// bh - Bone head coordinate.
						//------------------------------------------------------
						if (input == 'h') {
							//----------------------------------------------------------
							// Read in a single vertex (3 floats) and convert the 
							// vertex value  by calling 
							// Util::coordinateSystemConversionFromBlenderToDirectX()
							// function passing current MyModelArmature object for 
							// coordinate system option retrieval and ifstream address  
							// to read 3 float values and return the converted 
							// VertexType pointer.
							//----------------------------------------------------------
							VertexType *resultCoord
								= this->modelLoaderUtils
								->coordinateSystemConversionFromBlenderToDirectX(
								((MyModelObj *)curModelAnimation), &fin);

							// Conver the converted VertexType value to XMFLOAT3.
							XMFLOAT3 temp = XMFLOAT3(
								resultCoord->x,
								resultCoord->y,
								resultCoord->z);

							// Set current animation frame data tail coordinate.
							currentAnimBoneFrameDataPtr->boneHead = temp;
							_RPT1(0, "MyModelLoader::myArmatureLoader::bt : %f, %f, %f\n",
								currentAnimBoneFrameDataPtr->boneTail.x,
								currentAnimBoneFrameDataPtr->boneTail.y,
								currentAnimBoneFrameDataPtr->boneTail.z);
						}
					}

					//==========================================================
					// Main animation keyframe data informations 
					//==========================================================
					// loc - Pose bone location value in current animation frame 
					// rotq - Pose bone rotation quaternion value in current animation frame 
					// sca - Pose bone scale value in current animation frame

					//----------------------------------------------------------
					// Start loading animation frame bone
					// translation vector value indicated as "loc"
					// inside "{}", which means current animation frame.
					//
					// loc - Pose bone location value in current animation frame 
					//------------------------------------------------------ ---
					if (input == 'l') {
						fin.get(input);
						if (input == 'o') {
							fin.get(input);
							if (input == 'c') {
								fin.get(input);
								if (input == ' ') {
									float x, y, z;
									fin >> z >> y >> x;
									x *= -1;
									XMFLOAT3 temp = XMFLOAT3(x, y, z);

									// Set current animation frame data location vector.
									currentAnimBoneFrameDataPtr->translationVec = temp;
									_RPT1(0, "MyModelLoader::myArmatureLoader::loc : %f, %f, %f\n",
										currentAnimBoneFrameDataPtr->translationVec.x,
										currentAnimBoneFrameDataPtr->translationVec.y,
										currentAnimBoneFrameDataPtr->translationVec.z);
								}
							}
						}
					}
					//----------------------------------------------------------
					// Start loading animation frame bone 
					// rotation quaternion value indicated as "rotq"
					// inside "{}", which means current animation frame.
					//
					// rotq - Pose bone rotation quaternion value in current animation frame 
					//------------------------------------------------------ ---
					if (input == 'r') {
						fin.get(input);
						if (input == 'o') {
							fin.get(input);
							if (input == 't') {
								fin.get(input);
								if (input == 'q') {
									fin.get(input);
									if (input == ' ') {
										float w, x, y, z;
										fin >> w >> z >> y >> x;
										x *= -1;
										XMFLOAT4 temp = XMFLOAT4(w, x, y, z);

										// Set current animation frame data location vector.
										currentAnimBoneFrameDataPtr->rotationQuat = temp;
										_RPT1(0, "MyModelLoader::myArmatureLoader::rotq : %f, %f, %f, %f\n",
											currentAnimBoneFrameDataPtr->rotationQuat.w,
											currentAnimBoneFrameDataPtr->rotationQuat.x,
											currentAnimBoneFrameDataPtr->rotationQuat.y,
											currentAnimBoneFrameDataPtr->rotationQuat.z);
									}
								}
							}
						}
					}
					//----------------------------------------------------------
					// Start loading animation frame bone 
					// rotation quaternion value indicated as "sca"
					// inside "{}", which means current animation frame.
					//
					// sca - Pose bone scale value in current animation frame
					//------------------------------------------------------ ---
					if (input == 's') {
						fin.get(input);
						if (input == 'c') {
							fin.get(input);
							if (input == 'a') {
								fin.get(input);
								if (input == ' ') {
									float x, y, z;
									fin >> z >> y >> x;
									x *= -1;
									XMFLOAT3 temp = XMFLOAT3(x, y, z);

									// Set current animation frame data location vector.
									currentAnimBoneFrameDataPtr->scalingVec = temp;
									_RPT1(0, "MyModelLoader::myArmatureLoader::sca : %f, %f, %f\n",
										currentAnimBoneFrameDataPtr->scalingVec.x,
										currentAnimBoneFrameDataPtr->scalingVec.y,
										currentAnimBoneFrameDataPtr->scalingVec.z);
								}
							}
						}
					}

					//==========================================================
					// Start loading animation frame bone 
					// world matrix indicated as "<()()()()>"
					// inside "{}", which means current animation frame.
					//==========================================================
					if (input == '<') {
						//------------------------------------------------------
						// <()()()()> - Animation frame data XMFLOAT4X4 valueto 
						// be inserted.
						//------------------------------------------------------


						// Row counter for XMFLOAT4X4.
						int rowCount = 0;

						//------------------------------------------------------
						// Current row - <(x,y,z,w)(x,y,z,w)(x,y,z,w)(x,y,z,w)>
						//------------------------------------------------------
						// Read until reached current animation frame data 
						// end character ">"
						// "<()()()()>" to "()()()()" ...
						//------------------------------------------------------
						while (input != '>') {
							fin.get(input);

							//--------------------------------------------------
							// Current column - (x,y,z,w)
							//--------------------------------------------------
							// "<(x,y,z,w)()()()>" --> "x,y,z,w)()()()"
							// Start of the XMFLOAT4X4 first XMFLOAT4 value.
							if (input == '(') {
								// Read in float value strings.

								// Local buffer to store the animation frame 
								// data string
								char temp[MAX_ANIMTION_XMFLOAT4X4_STRING];
								int count = 0;

								// Read until reach to the end character ")" 
								// "x,y,z,w)" --> "x,y,z,w"
								while (input != ')') {
									fin.get(input);
									temp[count] = input;
									count++;

								}

								// C-string end
								temp[count - 1] = '\0';
								//_RPT1(0, "temp : %s\n", temp);

								//----------------------------------------------
								// Local 2D array representing a XMFLOAT4X4 
								// value to store the result animation frame 
								// data loaded from current line
								// "<(XMFLOAT4)(XMFLOAT4)(XMFLOAT4)(XMFLOAT4)>".
								//----------------------------------------------
								float tempArr[NUM_XMFLOAT4X4_ROW][NUM_XMFLOAT4X4_COL];

								// Use this local variable to convert the 
								// c-string values.
								float val;

								// Reset column counter for next row x,y,z,w.
								int colCount = 0;

								//----------------------------------------------
								// Tokenize the c-string "x,y,z,w" to 4 float 
								// values 
								// "x", "y", "z" and "w".
								//----------------------------------------------
								char *token = strtok(temp, ",");
								while (token) {
									// String --> float.
									val = strtof(token, NULL);
									// Store the float value into resulting
									// XMFLOAT4X4 temp array.
									tempArr[rowCount][colCount] = val;

									// Tokenize again with "," to retrieve 
									// next y,z,w values
									token = strtok(NULL, ",");
									//_RPT1(0, "val : %f\n", val);

									// Increment column counter to retrieve 
									// x,y,z,w value
									colCount++;
								}
								// Increment row counter to insert 
								// to proper rows
								rowCount++;

								//----------------------------------------------
								// If row count == 4, means XMFLOAT4X4 is 
								// completly loaded.
								//
								// Print to check the complete loaded values.
								// Convert the loaded temp float[][] 
								// to XMFLOAT4X4 value.
								//
								// And insert the converted XMFLOAT4X4 value 
								// into the main data structure of current 
								// MyModelAnimationBone object initialized 
								// above.
								//----------------------------------------------
								if (rowCount == 4) {
									_RPT1(0, "XMFLOAT4X4 :\n", 0);
									for (int i = 0; i < 4; i++) {
										_RPT1(0, "(%f,%f,%f,%f)", tempArr[i][0], tempArr[i][1], tempArr[i][2], tempArr[i][3]);
									}
									_RPT1(0, "\n", 0);

									// Convert the loaded temp float[][] to XMFLOAT4X4.
									XMFLOAT4X4 dataLoadedToInsert;
									dataLoadedToInsert._11 = tempArr[0][0];
									dataLoadedToInsert._12 = tempArr[0][1];
									dataLoadedToInsert._13 = tempArr[0][2];
									dataLoadedToInsert._14 = tempArr[0][3];
									dataLoadedToInsert._21 = tempArr[1][0];
									dataLoadedToInsert._22 = tempArr[1][1];
									dataLoadedToInsert._23 = tempArr[1][2];
									dataLoadedToInsert._24 = tempArr[1][3];
									dataLoadedToInsert._31 = tempArr[2][0];
									dataLoadedToInsert._32 = tempArr[2][1];
									dataLoadedToInsert._33 = tempArr[2][2];
									dataLoadedToInsert._34 = tempArr[2][3];
									dataLoadedToInsert._41 = tempArr[3][0];
									dataLoadedToInsert._42 = tempArr[3][1];
									dataLoadedToInsert._43 = tempArr[3][2];
									dataLoadedToInsert._44 = tempArr[3][3];

									//// [Z up -X forward] --> ZXY x*-1
									//XMFLOAT4X4 dataLoadedToInsert;
									//dataLoadedToInsert._11 = tempArr[0][2];
									//dataLoadedToInsert._12 = tempArr[0][0] * -1;
									//dataLoadedToInsert._13 = tempArr[0][1];
									//dataLoadedToInsert._14 = tempArr[0][3];
									//dataLoadedToInsert._21 = tempArr[1][2];
									//dataLoadedToInsert._22 = tempArr[1][0] * -1;
									//dataLoadedToInsert._23 = tempArr[1][1];
									//dataLoadedToInsert._24 = tempArr[1][3];
									//dataLoadedToInsert._31 = tempArr[2][2];
									//dataLoadedToInsert._32 = tempArr[2][0] * -1;
									//dataLoadedToInsert._33 = tempArr[2][1];
									//dataLoadedToInsert._34 = tempArr[2][3];
									//dataLoadedToInsert._41 = tempArr[3][2];
									//dataLoadedToInsert._42 = tempArr[3][0] * -1;
									//dataLoadedToInsert._43 = tempArr[3][1];
									//dataLoadedToInsert._44 = tempArr[3][3];

									//------------------------------------------
									// Set current MyModelAnimationBoneData 
									// worl matrix
									//------------------------------------------
									currentAnimBoneFrameDataPtr->worldMatrix =
										dataLoadedToInsert;
								}
							}
						}
					}
				}
				_RPT1(0, "Animation Frame END [%d]---------------------------------------------------\n", frameCounter);
				// Insert current animation frame data 
				// MyModelAnimationBoneData object
				// to the current animation bone 
				// MyModelAnimationBone object's data structure
				currentAnimBonePtr->insertAnimationFrameData(
					currentAnimBoneFrameDataPtr);
				// Increment frame counter, number of frames being loaded to
				// curernt animation bone.
				frameCounter++;

			}
		}
		// Start reading the beginning of the next line.
		fin.get(input);
	}

	_RPT1(0, "Bones inserted : %d\n", boneCounter);
	_RPT1(0, "Frames inserted : %d\n", frameCounter / boneCounter);
	_RPT1(0, "MyModelAnimation END==============================================================================\n", 0);

	// Error handling:
	// Data structure to store the data values read from the file is not created
	// properly.
	if (!datastructureCreated) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::myArmatureLoader::Data structure creation failed!!! : %s\n", finalAnimationAbsFilePath);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::myArmatureLoader::Data structure creation failed!!!");
	}

	return curModelAnimation;
}

/*
*	Read in the number of vertices, texture coordsinates, normal vectors,
*	and faces so that the data structures can be initialized
*	with the exact sizes needed.
*	<p>
*	Code brought from:
*		RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html
*	This function opens and reads the file on given file path,
*		count for the number of vertices, texture coordinates, normals,
*		and faces ("v" element, "vt" element, "vn" element and "f" element),
*		then directly initialize onto the int variables using 
*		their addresses passed as parameters.
*	Then can use them to initialize the data structure
*		with the exact sizes needed.
*
*	@param		filename			OBJ absolute file path
*										to be opened for reading.
*	@param		vertexCount			Address of the integer variable to
*										hold the number of vertices.
*	@param		textureCount		Address of the integer variable to
*										hold the number of
*										texture coordinates.
*	@param		normalCount			Address of the integer variable to
*										hold the number of normals.
*	@param		faceCount			Address of the integer variable to
*										hold the number of faces.
*	@return		Returns false when file can't be opened.
*				Returns true when file opened and reached the end of file.
*	@since		ver0003
*/
bool MyModelLoader::ReadFileCounts(
	char* filename,
	int& vertexCount,	// Integer variable address of "v" element counter.
	int& textureCount,	// Integer variable address of "vt" element counter.
	int& normalCount,	// Integer variable address of "vn" element counter.
	int& faceCount) {	// Integer variable address of "f" element counter.


	// ifstream to open the file with.
	ifstream fin;
	// Local character variable to read from the file.
	char input = '\0';

	// Initialize the counts.
	vertexCount = 0;
	textureCount = 0;
	normalCount = 0;
	faceCount = 0;

	// Open the file.
	fin.open(filename);

	// Check if it was successful in opening the file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::ReadFileCounts::Open file failed!!! : %s\n", filename);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::ReadFileCounts::Open file failed!!!");
	}

	// Check if it was successful in opening the file.
	if (fin.fail() == true) {
		return false;
	}
	// Read from the file and continue to read until the 
	// end of the file is reached.
	fin.get(input);
	while (!fin.eof()) {
		// If the line starts with 'v' then count either the vertex,
		// the texture coordinates, or the normal vector.
		if (input == 'v') {
			fin.get(input);
			if (input == ' ') { vertexCount++; }
			if (input == 't') { textureCount++; }
			if (input == 'n') { normalCount++; }
		}
		// If the line starts with 'f' then increment the face count.
		if (input == 'f') {
			fin.get(input);
			if (input == ' ') { faceCount++; }
		}
		// Otherwise read in the remainder of the line.
		while (input != '\n') {
			fin.get(input);
		}
		// Start reading the beginning of the next line.
		fin.get(input);
	}
	// Close the file.
	fin.close();
	return true;
}

/*
*	Custom WYO file (.wyo extension) - Read the data from the custom exported 
*		WYO file into the local data structures and copy them to the 
*		data structure inside MyModelObj object passed as parameter.
*		
*	<p>
*	Code brought from:
*		RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html
*	This function initializes the local data strcuture to
*		hold the model information datas and then
*		intialize them onto MyModelObj object's member variables
*		by copying the values loaded on local data structures.
*	----------------------------------------------------------------------------
*	To not change the original code brought from the net,
*		I had to design the function in a weird way,
*		by initalizing data onto local data structures and
*		copying them onto the MyModelObj object's member variables.
*	----------------------------------------------------------------------------
*	The elements to be loaded and be initialized onto MyModelObj
*		object are as follows:
*	        --------------------------------------------------------------------
*			CU - Coordinate system UP vector
*			CF - Coordinate system FORWARD vector
*	        --------------------------------------------------------------------
*			v - Vertex coordinate
*			vn - Vertex normal vector coordinate
*			vt - Texture mapping UV coordinate
*			f - Face index
*	----------------------------------------------------------------------------
*	Custom exported coordinate system option:
*			CU - Coordinate system UP vector
*			CF - Coordinate system FORWARD vector
*	This is to convert the coordinate values to match the DirectX 12
*		coordinate system, so i used the "CU" up vector and "CF" forward vector
*		to convert the coordinate values by calling
*		Util::coordinateSystemConversionFromBlenderToDirectX() function.
		// Read in a single vertex (3 floats) and convert the
		// vertex value  by calling
		// Util::coordinateSystemConversionFromBlenderToDirectX()
		// function passing current MyModelObj object for
		// coordinate system option retrieval and ifstream address
		// to read 3 float values and return the converted
		// VertexType pointer.
*	Blender Left handed system [X right Z up Y forward]
*	--> DirectX 12 [X left Y up Z forward]
*	- The algorithm on how to convert them is organized
*		 on a Google Spreadsheet:
*		- Blender export with different coordinate system mechanism:
*		  https://docs.google.com/spreadsheets/d/1-Cgt5TWBoKFWQM679ejoNjBIqWlmTwYSD6QxB4lWCBc/edit#gid=0
*		- Blender export
*		  --> DirectX 12 import with different coordinate system mechanism:
*		  https://docs.google.com/spreadsheets/d/1zarSFgRq6PsNVYPQNASd_uMJoamDMDBFjt2Htn5pDS0/edit#gid=0
*	----------------------------------------------------------------------------
*
*	@pre		WYM material file must be in the same directory as WYO model file
*	@pre		WYM material file must be exported with relative path.
*
*	@param		mainModel				MyModelObj object's pointer to
*											hold all the information datas.
*	@param		filename				WYO absolute file path
*											to be opened for reading.
*	@param		vertexCount				Number of vertices.
*	@param		textureCount			Number of texture coordinates.
*	@param		normalCount				Number of normals.
*	@param		faceCount				Number of faces.
*	@return		Returns false when file can't be opened or
*					data structure initialization failed.
*				Returns true when file opened, data structures are initialized
*					and successfully reached the end of file.
*	@since		ver0003
*/
bool MyModelLoader::LoadDataStructuresMyModelObj(
	MyModelObj *mainModel,
	char* filename,
	int vertexCount,
	int textureCount,
	int normalCount,
	int faceCount) {
	// If file name is NULL.
	if (filename == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::LoadDataStructuresMyModelObj::File name is NULL!!!\n", filename);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::LoadDataStructuresMyModelObj::File name is NULL!!!\n");
		return false;
	}

	// Local data structures to store the file data with.
	VertexType *vertices, *texcoords, *normals;
	FaceType *faces;

	// ifstream to open the file.
	ifstream fin;
	// Local variable to read data from file.
	char input, input2;

	// Local variables used for loading the data from file.
	int vertexIndex, texcoordIndex, normalIndex, faceIndex;
	int vIndex = 0;
	int tIndex = 0;
	int nIndex = 0;

	// ofstream to write a log to the file.
	//ofstream fout;

	// Initialize four local data structures before storing values to it.

	// Vertex array to hold the "v" element values.
	vertices = new VertexType[vertexCount];
	if (!vertices) {
		return false;
	}

	// Texture coordinate array to hold the "vt" element values.
	texcoords = new VertexType[textureCount];
	if (!texcoords) {
		return false;
	}

	// Normal vectors array to hold the "vn" element values.
	normals = new VertexType[normalCount];
	if (!normals) {
		return false;
	}

	// Face indices array to hold the "f" element values.
	faces = new FaceType[faceCount];
	if (!faces) {
		return false;
	}

	// Initialize the indexes local variables.
	vertexIndex = 0;
	texcoordIndex = 0;
	normalIndex = 0;
	faceIndex = 0;

	// Open the file.
	fin.open(filename);

	// Check if it was successful in opening the custom exported OBJ file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::LoadDataStructuresMyModelObj::Open file failed!!! : %s\n", filename);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::LoadDataStructuresMyModelObj::Open file failed!!!");
	}

	// Read in the vertices, texture coordinates, 
	// and normals into the data structures.
	fin.get(input);
	while (!fin.eof()) {
		//----------------------------------------------------------------------
		// mtllib - MTL file name
		//----------------------------------------------------------------------
		if (input == 'm') {
			fin.get(input);
			if (input == 't') { //  [Up]
				fin.get(input);
				if (input == 'l') {
					fin.get(input);
					if (input == 'l') {
						fin.get(input);
						if (input == 'i') {
							fin.get(input);
							if (input == 'b') {
								fin.get(input);
								if (input == ' ') {
									// Local buffer.
									char temp[BUFSIZ];
									int count = 0;

									// Read in the "mtllib" string value.
									while (input != '\n') {
										fin.get(input);
										temp[count] = input;
										count++;
									}
									temp[count - 1] = '\0';
									_RPT1(0, "MyModelLoader::LoadDataStructuresMyModelObj::mtllib: %s\n", temp);
									// Set model MTL relative file name.
									((ModelObj *)mainModel)
										->setMaterialFileName(temp);
								}
							}
						}
					}
				}
			}
		}
		
		if (input == 'C') {
			//------------------------------------------------------------------
			// CU - Coordinate system option UP vector
			//------------------------------------------------------------------
			fin.get(input);
			if (input == 'U') { //  [Up]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;

					// Read in the "CU" string value.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';

					// Set the coordinate system option UP string onto 
					// MyModelObj object.
					mainModel->set_coordoption_up_str(temp);
					_RPT1(0, "MyModelLoader::LoadDataStructuresMyModelObj::CU : %s\n", mainModel->get_coordoption_up_str());
				}
			}
			//------------------------------------------------------------------
			// CF - Coordinate system option FORWARD vector
			//------------------------------------------------------------------
			else if (input == 'F') { //  [Forward]
				fin.get(input);
				if (input == ' ') {
					// Local buffer.
					char temp[SHORT_BUF_SIZ];
					int count = 0;
					// Read in the "CF" string value.
					while (input != '\n') {
						fin.get(input);
						temp[count] = input;
						count++;
					}
					temp[count - 1] = '\0';

					// Set the coordinate system option FORWARD string onto 
					// MyModelObj object.
					mainModel->set_coordoption_forward_str(temp);
					_RPT1(0, "MyModelLoader::LoadDataStructuresMyModelObj::CF : %s\n",
						mainModel->get_coordoption_forward_str());

				}
			}
		}


		if (input == 'v') {
			fin.get(input);
			//------------------------------------------------------------------
			// v - Vertices
			//------------------------------------------------------------------
			if (input == ' ') {
				// Read in the vertices.
				//--------------------------------------------------------------
				// Convert vertex coordinate system data
				//
				// Read in a single vertex (3 floats) and convert the
				// vertex value  by calling
				// Util::coordinateSystemConversionFromBlenderToDirectX()
				// function passing current MyModelObj object for
				// coordinate system option retrieval and ifstream address
				// to read 3 float values and return the converted
				// VertexType pointer.
				//--------------------------------------------------------------
				// Get converted vertex value.
				VertexType *resultCoord 
					= this->modelLoaderUtils
						->coordinateSystemConversionFromBlenderToDirectX(
							mainModel, 
							&fin);

				// Store the converted vertex value into the current vertex 
				// inside vertex array data structure.
				vertices[vertexIndex].x = resultCoord->x;
				vertices[vertexIndex].y = resultCoord->y;
				vertices[vertexIndex].z = resultCoord->z;

				_RPT1(0, "MyModelLoader::LoadDataStructuresMyModelObj::vertices xyz: %f %f %f\n",
					vertices[vertexIndex].x,
					vertices[vertexIndex].y,
					vertices[vertexIndex].z);

				// Increment vertex index counter.
				vertexIndex++;
			}

			//------------------------------------------------------------------
			// vt - Texture coordinates (UV layout)  
			//------------------------------------------------------------------
			if (input == 't') {
				// Read in the texture uv coordinates.
				fin >> texcoords[texcoordIndex].x >> texcoords[texcoordIndex].y;

				// Invert the V texture coordinates to left hand system.
				texcoords[texcoordIndex].y = 1.0f - texcoords[texcoordIndex].y;

				// Increment texture coordinate index counter.
				texcoordIndex++;
			}
			//------------------------------------------------------------------
			// vn - Normal vectors
			//------------------------------------------------------------------
			if (input == 'n') {
				// Read in the normals.
				fin >>
					normals[normalIndex].x >>
					normals[normalIndex].y >>
					normals[normalIndex].z;

				// Invert the Z normal to change to left hand system. ???
				normals[normalIndex].z
					= normals[normalIndex].z * -1.0f;

				// Increment normal vector index counter.
				normalIndex++;
			}
		}

		//----------------------------------------------------------------------
		// f - Indices from faces (eg. f v/t/n)
		//----------------------------------------------------------------------
		// Read in the faces.
		if (input == 'f') {
			fin.get(input);
			if (input == ' ') {
				// If there are no texture coordinates loading as v/n , t = 0.
				if (texcoordIndex <= 0) {
					_RPT1(0, "################################################################################\n", 0);
					_RPT1(0, "ERROR::MyModelLoader::LoadDataStructuresMyModelObj::Import texture coordinate doens not exist!!!\n", 0);
					_RPT1(0, "################################################################################\n", 0);
					// Read the face data in backwards to convert it 
					// to a left hand system from right hand system.
					fin >>
						faces[faceIndex].vIndex3 >> input2 >>
						faces[faceIndex].nIndex3
						>>
						faces[faceIndex].vIndex2 >> input2 >>
						faces[faceIndex].nIndex2
						>>
						faces[faceIndex].vIndex1 >> input2 >>
						faces[faceIndex].nIndex1;

					// Storing 0 if there are no texture coordinate detected
					faces[faceIndex].tIndex3 = (int)1.0f;
					faces[faceIndex].tIndex2 = (int)1.0f;
					faces[faceIndex].tIndex1 = (int)1.0f;

					// Increment face index counter.
					faceIndex++;
				}
				// Read in as normal v/f/n
				else {
					// Read the face data in backwards to convert it 
					// to a left hand system from right hand system.
					fin >>
						faces[faceIndex].vIndex3 >> input2 >>
						faces[faceIndex].tIndex3 >> input2 >>
						faces[faceIndex].nIndex3
						>>
						faces[faceIndex].vIndex2 >> input2 >>
						faces[faceIndex].tIndex2 >> input2 >>
						faces[faceIndex].nIndex2
						>>
						faces[faceIndex].vIndex1 >> input2 >>
						faces[faceIndex].tIndex1 >> input2 >>
						faces[faceIndex].nIndex1;
					// Increment face index counter.
					faceIndex++;
				}

			}
		}

		// Read in the remainder of the line.
		while (input != '\n') {
			fin.get(input);
		}
		// Start reading the beginning of the next line.
		fin.get(input);
	}


	//==========================================================================
	// Copy the loaded local data structure datas onto the data structure inside
	// MyModelObj object since the local data structure is used to load the file
	// it is not stable to hold the data structure created in stack memory.
	//==========================================================================
	((ModelObj *)mainModel)->copyModelVertices(vertices, vertexCount);
	((ModelObj *)mainModel)->copyTexcoords(texcoords, textureCount);
	((ModelObj *)mainModel)->copyNormals(normals, normalCount);
	((ModelObj *)mainModel)->copyFaces(faces, faceCount);
	//==========================================================================

	// Close the file.
	fin.close();

	/*
	//==========================================================================
	// Working wofstream in DirectX (Windows app has limited
	//		access to files for writing or creating)
	// Using terminal to double check if the file is written properly
	// Using this we can check the model OBJ file is
	//		converted properly for further development
	//
	// terminal > type C:\Users\nickj\AppData\Local\Packages\68ea8160-7bb8-469d-8e5d-b335fc6a1085_hc86n47xwparc\LocalState\model.txt
	//==========================================================================
	//auto platformPath
	= Windows::Storage::ApplicationData::Current->RoamingFolder->Path;
	auto platformPath
	= Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring platformPathW(platformPath->Begin());
	std::string convertedPlatformPath(
	platformPathW.begin(),
	platformPathW.end());
	std::string path = convertedPlatformPath + "\\model.txt";

	// ofstream file path
	_RPT1(0, "converted model OBJ file path : %s\n", path.c_str());

	wofstream fout;

	try
	{
	fout.open(path.c_str(), ios_base::out);
	if (fout.is_open())
	{
	//fout << "Writing this to a file.\n";
	//fout.close();
	}
	else
	{
	_RPT1(0, "wofstream::Cannot open file!!!\n", 0);
	}
	}
	catch (const std::exception& ex)
	{
	cout << ex.what();
	}
	//==========================================================================

	// Write out the file header that our model format uses.
	fout << "Vertex Count: " << (faceCount * 3) << endl;
	fout << endl;
	fout << "Data:" << endl;
	fout << endl;

	// Now loop through all the faces and
	// output the three vertices for each face.
	for (int i = 0; i<faceIndex; i++)
	{
	vIndex = faces[i].vIndex1 - 1;
	tIndex = faces[i].tIndex1 - 1;
	nIndex = faces[i].nIndex1 - 1;

	fout <<
	vertices[vIndex].x << ' ' <<
	vertices[vIndex].y << ' ' <<
	vertices[vIndex].z << ' '
	<<
	texcoords[tIndex].x << ' ' <<
	texcoords[tIndex].y << ' '
	<<
	normals[nIndex].x << ' ' <<
	normals[nIndex].y << ' ' <<
	normals[nIndex].z << endl;

	vIndex = faces[i].vIndex2 - 1;
	tIndex = faces[i].tIndex2 - 1;
	nIndex = faces[i].nIndex2 - 1;

	fout <<
	vertices[vIndex].x << ' ' <<
	vertices[vIndex].y << ' ' <<
	vertices[vIndex].z << ' '
	<<
	texcoords[tIndex].x << ' ' <<
	texcoords[tIndex].y << ' '
	<<
	normals[nIndex].x << ' ' <<
	normals[nIndex].y << ' ' <<
	normals[nIndex].z << endl;

	vIndex = faces[i].vIndex3 - 1;
	tIndex = faces[i].tIndex3 - 1;
	nIndex = faces[i].nIndex3 - 1;

	fout <<
	vertices[vIndex].x << ' ' <<
	vertices[vIndex].y << ' ' <<
	vertices[vIndex].z << ' '
	<<
	texcoords[tIndex].x << ' ' <<
	texcoords[tIndex].y << ' '
	<<
	normals[nIndex].x << ' ' <<
	normals[nIndex].y << ' ' <<
	normals[nIndex].z << endl;
	}

	// Close the output file.
	fout.close();
	*/

	// Release the four data structures. 

	// Local vertex data structure.
	if (vertices) {
		delete[] vertices;
		vertices = 0;
	}
	// Local texture coordinates data structure.
	if (texcoords) {
		delete[] texcoords;
		texcoords = 0;
	}
	// Local normal vectors data structure.
	if (normals) {
		delete[] normals;
		normals = 0;
	}
	// Local face indices data structure.
	if (faces) {
		delete[] faces;
		faces = 0;
	}
	_RPT1(0, "==============================================================================\n", 0);
	
	// Return true on success loading the custom exported WYO file.
	return true;
}

/*
*	Standard OBJ file (.obj extension) - Read the data from the standard OBJ
*		file into the local data structures and copy them to the
*		data structure inside ModelObj object passed as parameter.
*	<p>
*	Code brought from:
*		RasterTek Loading Maya 2011 model: http://www.rastertek.com/dx11tut08.html
*	This function initializes the local data strcuture to
*		hold the model information datas and then
*		intialize them onto ModelObj object's member variables
*		by copying the values loaded on local data structures.
*	----------------------------------------------------------------------------
*	To not change the original code brought from the net,
*		I had to design the function in a weird way,
*		by initalizing data onto local data structures and
*		copying them onto the MyModelObj object's member variables.
*	----------------------------------------------------------------------------
*	In this OBJ loader, i did not put the coordinate system conversion code in
*	it, so the model will appear not the way it looked in the modelling engine
*	or other engine, because the coordinate system might differ.
*
*	But instead i converted the vertex coordinate values assuming the 
*	standard OBJ is exported with default coordinate system option from Blender
*	which is [Z up Y forward], so i converted it manually the value is converted
*	to match the DirectX 12 coordinate system which is [Y up Z forward].
*	----------------------------------------------------------------------------
*	The elements to be loaded and be initialized onto ModelObj
*		object are as follows:
*			v - Vertex coordinate
*			vn - Vertex normal vector coordinate
*			vt - Texture mapping UV coordinate
*			f - Face index
*
*	@param		mainModel				ModelObj object's pointer to
*											hold all the information datas.
*	@param		filename				OBJ absolute file path
*											to be opened for reading.
*	@param		vertexCount				Number of vertices.
*	@param		textureCount			Number of texture coordinates.
*	@param		normalCount				Number of normals.
*	@param		faceCount				Number of faces.
*	@return		Returns false when file can't be opened or
*					data structure initialization failed.
*				Returns true when file opened, data structures are initialized
*					and successfully reached the end of file.
*	@since		ver0108
*/
bool MyModelLoader::LoadDataStructuresModelObj(
	ModelObj *mainModel,
	char* filename,
	int vertexCount,
	int textureCount,
	int normalCount,
	int faceCount) {

	// If file name is NULL.
	if (filename == NULL) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::LoadDataStructuresModelObj::File name is NULL!!!\n", filename);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::LoadDataStructuresModelObj::File name is NULL!!!\n");
		return false;
	}

	// Local data structures to store the file data with.
	VertexType *vertices, *texcoords, *normals;
	FaceType *faces;

	// ifstream to open the file.
	ifstream fin;
	// Local variable to read data from file.
	char input, input2;

	// Local variables used for loading the data from file.
	int vertexIndex, texcoordIndex, normalIndex, faceIndex;
	int vIndex = 0;
	int tIndex = 0;
	int nIndex = 0;

	// ofstream to write a log to the file.
	//ofstream fout;

	// Initialize four local data structures before storing values to it.

	// Vertex array to hold the "v" element values.
	vertices = new VertexType[vertexCount];
	if (!vertices) {
		return false;
	}

	// Texture coordinate array to hold the "vt" element values.
	texcoords = new VertexType[textureCount];
	if (!texcoords) {
		return false;
	}

	// Normal vectors array to hold the "vn" element values.
	normals = new VertexType[normalCount];
	if (!normals) {
		return false;
	}

	// Face indices array to hold the "f" element values.
	faces = new FaceType[faceCount];
	if (!faces) {
		return false;
	}

	// Initialize the indexes local variables.
	vertexIndex = 0;
	texcoordIndex = 0;
	normalIndex = 0;
	faceIndex = 0;

	// Open the file.
	fin.open(filename);

	// Check if it was successful in opening the custom exported OBJ file.
	if (fin.fail()) {
		_RPT1(0, "################################################################################\n", 0);
		_RPT1(0, "ERROR::MyModelLoader::LoadDataStructuresModelObj::Open file failed!!! : %s\n", filename);
		_RPT1(0, "################################################################################\n", 0);
		throw std::runtime_error("ERROR::MyModelLoader::LoadDataStructuresModelObj::Open file failed!!!");
	}

	// Read in the vertices, texture coordinates, 
	// and normals into the data structures.
	fin.get(input);
	while (!fin.eof()) {
		//----------------------------------------------------------------------
		// mtllib - MTL file name
		//----------------------------------------------------------------------	
		if (input == 'm') {
			fin.get(input);
			if (input == 't') { //  [Up]
				fin.get(input);
				if (input == 'l') {
					fin.get(input);
					if (input == 'l') {
						fin.get(input);
						if (input == 'i') {
							fin.get(input);
							if (input == 'b') {
								fin.get(input);
								if (input == ' ') {
									// Local buffer.
									char temp[BUFSIZ];
									int count = 0;
									// Read in the "mtllib" string value.
									while (input != '\n') {
										fin.get(input);
										temp[count] = input;
										count++;
									}
									temp[count - 1] = '\0';
									_RPT1(0, "MyModelLoader::LoadDataStructuresModelObj::mtllib: %s\n", temp);
									
									// Set model MTL relative file name.
									mainModel->setMaterialFileName(temp);
								}
							}
						}
					}
				}
			}
		}

		//----------------------------------------------------------------------
		// v - Vertices
		//----------------------------------------------------------------------
		if (input == 'v') {
			fin.get(input);

			//------------------------------------------------------------------
			// v - Vertices
			//------------------------------------------------------------------
			if (input == ' ') {
				//--------------------------------------------------------------
				// Imported from standard OBJ  [Z up Y forward]
				//--------------------------------------------------------------
				// Read in the vertices.
				// Store the converted vertex value into the current vertex 
				// inside vertex array data structure.
				fin >> vertices[vertexIndex].x >> vertices[vertexIndex].y >> vertices[vertexIndex].z;
				
				// Convert the coordinate system assuming the standard OBJ is 
				// exported with default coordinate system option
				// [Z up Y forward]
				vertices[vertexIndex].x *= -1;
				//vertices[vertexIndex].z *= -1;

				_RPT1(0, "MyModelLoader::LoadDataStructuresModelObj::vertices xyz: %f %f %f\n", vertices[vertexIndex].x, vertices[vertexIndex].y, vertices[vertexIndex].z);

				// Increment vertex index counter.
				vertexIndex++;
			}

			//------------------------------------------------------------------
			// vt - Texture coordinates (UV layout)  
			//------------------------------------------------------------------
			if (input == 't') {
				// Read in the texture uv coordinates.
				fin >> texcoords[texcoordIndex].x >> texcoords[texcoordIndex].y;

				// Invert the V texture coordinates to left hand system.
				texcoords[texcoordIndex].y = 1.0f - texcoords[texcoordIndex].y;

				// Increment texture coordinate index counter.
				texcoordIndex++;
			}
			//------------------------------------------------------------------
			// vn - Normals  
			//------------------------------------------------------------------
			if (input == 'n') {
				// Read in the normals.
				fin >> normals[normalIndex].x >> normals[normalIndex].y >> normals[normalIndex].z;

				// Invert the Z normal to change to left hand system.
				normals[normalIndex].z = normals[normalIndex].z * -1.0f;

				// Increment normal vector index counter.
				normalIndex++;
			}
		}

		//----------------------------------------------------------------------
		// Indices from faces (eg. f v1/t1/n1 v2/t2/n2 v3/t3/n3).
		//----------------------------------------------------------------------
		// Read in the faces.
		if (input == 'f') {
			fin.get(input);
			if (input == ' ') {
				// Read the face data in backwards to convert it to 
				// a left hand system from right hand system.
				fin >>
					faces[faceIndex].vIndex3 >> input2 >>
					faces[faceIndex].tIndex3 >> input2 >>
					faces[faceIndex].nIndex3
					>>
					faces[faceIndex].vIndex2 >> input2 >>
					faces[faceIndex].tIndex2 >> input2 >>
					faces[faceIndex].nIndex2
					>>
					faces[faceIndex].vIndex1 >> input2 >>
					faces[faceIndex].tIndex1 >> input2 >>
					faces[faceIndex].nIndex1;
				//_RPT1(0, "faces 123123: %f %f %f\n", faces[faceIndex].vIndex3
				// , faces[faceIndex].tIndex3, faces[faceIndex].nIndex3);

				// Increment face index counter.
				faceIndex++;
			}
		}

		// Read in the remainder of the line.
		while (input != '\n') {
			fin.get(input);
		}

		// Start reading the beginning of the next line.
		fin.get(input);
	}

	//==========================================================================
	// Copy the loaded local data structure datas onto the data structure inside
	// MyModelObj object since the local data structure is used to load the file
	// it is not stable to hold the data structure created in stack memory.
	//==========================================================================
	mainModel->copyModelVertices(vertices, vertexCount);
	mainModel->copyTexcoords(texcoords, textureCount);
	mainModel->copyNormals(normals, normalCount);
	mainModel->copyFaces(faces, faceCount);
	//==========================================================================

	// Close the file.
	fin.close();

	/*
	//==========================================================================
	// Working wofstream in DirectX
	// (Windows app has limited access to files for writing or creating)
	// Using terminal to double check if the file is written properly
	// Using this we can check the model OBJ file is converted properly
	//		for further development
	//
	// terminal > type C:\Users\nickj\AppData\Local\Packages\68ea8160-7bb8-469d-8e5d-b335fc6a1085_hc86n47xwparc\LocalState\model.txt
	//=========================================================================
	//auto platformPath = Windows::Storage::ApplicationData::Current->RoamingFolder->Path;
	auto platformPath = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
	std::wstring platformPathW(platformPath->Begin());
	std::string convertedPlatformPath(platformPathW.begin(), platformPathW.end());
	std::string path = convertedPlatformPath + "\\model.txt";

	// ofstream file path
	_RPT1(0, "converted model OBJ file path : %s\n", path.c_str());

	wofstream fout;

	try
	{
	fout.open(path.c_str(), ios_base::out);
	if (fout.is_open())
	{
	//fout << "Writing this to a file.\n";
	//fout.close();
	}
	else
	{
	_RPT1(0, "wofstream::Cannot open file!!!\n", 0);
	}
	}
	catch (const std::exception& ex)
	{
	cout << ex.what();
	}
	//============================================================

	// Write out the file header that our model format uses.
	fout << "Vertex Count: " << (faceCount * 3) << endl;
	fout << endl;
	fout << "Data:" << endl;
	fout << endl;

	// Now loop through all the faces and output the three vertices for each face.
	for (int i = 0; i<faceIndex; i++)
	{
	vIndex = faces[i].vIndex1 - 1;
	tIndex = faces[i].tIndex1 - 1;
	nIndex = faces[i].nIndex1 - 1;

	fout << vertices[vIndex].x << ' ' << vertices[vIndex].y << ' ' << vertices[vIndex].z << ' '
	<< texcoords[tIndex].x << ' ' << texcoords[tIndex].y << ' '
	<< normals[nIndex].x << ' ' << normals[nIndex].y << ' ' << normals[nIndex].z << endl;

	vIndex = faces[i].vIndex2 - 1;
	tIndex = faces[i].tIndex2 - 1;
	nIndex = faces[i].nIndex2 - 1;

	fout << vertices[vIndex].x << ' ' << vertices[vIndex].y << ' ' << vertices[vIndex].z << ' '
	<< texcoords[tIndex].x << ' ' << texcoords[tIndex].y << ' '
	<< normals[nIndex].x << ' ' << normals[nIndex].y << ' ' << normals[nIndex].z << endl;

	vIndex = faces[i].vIndex3 - 1;
	tIndex = faces[i].tIndex3 - 1;
	nIndex = faces[i].nIndex3 - 1;

	fout << vertices[vIndex].x << ' ' << vertices[vIndex].y << ' ' << vertices[vIndex].z << ' '
	<< texcoords[tIndex].x << ' ' << texcoords[tIndex].y << ' '
	<< normals[nIndex].x << ' ' << normals[nIndex].y << ' ' << normals[nIndex].z << endl;
	}

	// Close the output file.
	fout.close();
	*/

	// Release the four data structures.

	// Local vertex data structure.
	if (vertices) {
		delete[] vertices;
		vertices = 0;
	}
	// Local texture coordinates data structure.
	if (texcoords) {
		delete[] texcoords;
		texcoords = 0;
	}
	// Local normal vectors data structure.
	if (normals) {
		delete[] normals;
		normals = 0;
	}
	// Local face indices data structure.
	if (faces) {
		delete[] faces;
		faces = 0;
	}

	// Return true on success loading the OBJ file.
	return true;
}
