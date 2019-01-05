#pragma once

// MySpecialModelObjMtl.cpp - Vertex and index buffer view init.
#define VERTEX_BUFFER_SIZE 50000
#define INDEX_BUFFER_SIZE 50000

// main.cpp - Descriptor heap init
#define DEFAULT_NUM_DECRIPTORS_IN_HEAP 100;

// Line.cpp - For Line objects vertex buffer init.
#define DEFAULT_LINE_NUM_POINTS 2

// MyModelLoader.cpp, Util.cpp - For model loader format decision.
#define MODEL_LOADER_FORMAT_OBJ	100
#define MODEL_LOADER_FORMAT_WYO	101

// MyModelArmature.cpp - For models bones init in an armature object.
#define MAX_NUM_BONES_PER_ARMATURE 50

// MyModelAnimationBone.cpp - For default data structure to hold aniamtion datas.
#define MAX_ANIMATION_FRAMES 250
// MyModelAnimation.cpp - For default data structure to hold aniamtion bones.
#define DEFAULT_MAX_NUM_ANIMATION_BONES 10

// MyModelLoader.cpp - For local buffers loading values from file 
//						eg. coordinate system options "CU" and "CF".
#define SHORT_BUF_SIZ 10

// MyModelLoader.cpp - For local buffers loading the XMFLOAT4X4 string values 
//						from loading animation files.
#define MAX_ANIMTION_XMFLOAT4X4_STRING 1000


// MyModelLoader.cpp - For local buffers converting to the XMFLOAT4X4 value.
#define NUM_XMFLOAT4X4_ROW 4
#define NUM_XMFLOAT4X4_COL 4