// File name: [stdafx.h] (Copyright to Samil Chai)
// Work Session #0188: 2017-07-18
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
//	- [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//	- [Description]: 
//		This file mostly holds global variables and constant variables.
//	- [Comments]:
//		All the gloabal varaibles and funciton prototype for main.cpp has been 
//			moved to on top of the main.cpp source code, because when i include
//			this file on other class cpp file, it causes 
//			"already defined in main.obj" linking error, so i had to move them
//			to main.cpp.
//		This error is found when i tried to implement MyModelAnimation.cpp
//			Solution:
//				https://www.gamedev.net/forums/topic/512785-already-defined-in-obj---c/
//				Your problem is that you're declaring global variables in 
//				a header file. That's a nono. All an #include statement does is 
//				basically paste the header file into your source code.
//				So if you're declaring a global variable in the header, 
//				basically the compiler is just going to see the same variable 
//				declared in multiple files.
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0002:WY:201707181520]
//------------------------------------------------------------------------------
// File name: [stdafx.h] (Copyright to Samil Chai)
// Work Session #0169: 2017-06-29
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
//	- [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//	- [Description]: 
//		This file mostly holds global variables and constant variables.
//	- [Comments]:
//		Structure added to this file while porting MyModelLoader class from
//			WY_PROJ_DIRECTX_12_ver0128/ModelLoaderHelper.h:
//				VertexType
//				FaceType
//		Constant variables added brought from WY_PROJ_DIRECTX_12_ver0128
//				#define DEFAULT_NUM_DECRIPTORS_IN_HEAP 100;
//				#define MODEL_LOADER_FORMAT_OBJ	100
//				#define MODEL_LOADER_FORMAT_WYO	101
//				#define MAX_NUM_MODELS_PER_SCENE 100
//				#define MAX_NUM_BONES_PER_ARMATURE 50
//
//				#define VERTEX_BUFFER_SIZE 50000
//				#define INDEX_BUFFER_SIZE 50000
//		Collected all the headers into this file and include them, so 
//			i can just include "stdafx.h" to handle all the including 
//			headers and namespaces
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0002_cameraclass_tested_201706272200
//------------------------------------------------------------------------------
// [rev0001:WY:201706291620]
//------------------------------------------------------------------------------
// File name: [stdafx.h] (Copyright to Samil Chai)
// Work Session #0168: 2017-06-27
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
//	- [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//	- [Description]: 
//		This file mostly holds global variables and constant variables.
//	- [Comments]:
//		Camera *mainCamera;
//			- Added to hold all the camera information into one Camera class 
//				object.
//		void mainInit();
//			- Prototype main init function added to hold all the init codes
//				into one function.
//		Commenting out uneccessary camera related global variables once used:
//			DirectX::XMFLOAT4X4 cameraProjMat; // this will store our projection matrix
//			DirectX::XMFLOAT4X4 cameraViewMat; // this will store our view matrix
//			DirectX::XMFLOAT4 cameraPosition; // this is our cameras position vector
//			DirectX::XMFLOAT4 cameraTarget; 
//			DirectX::XMFLOAT4 cameraUp; // the worlds up vector
//	- [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0002_cameraclass_tested_201706272200
//------------------------------------------------------------------------------
// [rev0000:WY:201706272140]
//------------------------------------------------------------------------------
//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers.
#endif

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>

#include <Winsock2.h>
#include <windows.h>
#include <wincodec.h>

#include <direct.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include "d3dx12.h"

#include "main.h"
#include "ShaderStructures.h"

#include <stdio.h>  /*defines FILENAME_MAX */

#if _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#elif __linux__ 
/ *Do linux stuff */
#include <unistd.h>
#define GetCurrentDir getcwd
#else
/ *Error, both can't be defined or undefined same time */
#endif

using namespace std;
using namespace DirectX; // we will be using the directDirectX::XMath library

// direct3d stuff
const int frameBufferCount = 3; // number of buffers we want, 2 for double buffering, 3 for tripple buffering
