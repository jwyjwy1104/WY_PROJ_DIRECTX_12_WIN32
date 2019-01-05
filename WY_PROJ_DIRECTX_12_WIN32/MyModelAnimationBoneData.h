#pragma once

#include <iostream>
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include "d3dx12.h"

// Class description: 
//		This class represents a custom exported aniamtion frame data indicated 
//		inside the "{}" curly brackets inside custom exported animation file 
//		exported through  Blender Python scritp, which holds all the information 
//		can be stored as an animation frame.
//		========================================================================
//		WANIM : Custom exported animation file exported through my custom 
//				animation exporter Blender Python script through Blender.
//		========================================================================
class MyModelAnimationBoneData {
public:
	// bt - Current animaiton frame data bone tail coordinate.
	DirectX::XMFLOAT3 boneTail;
	// bh - Current animaiton frame data bone head coordinate.
	DirectX::XMFLOAT3 boneHead;

	// tra - Current animaiton frame data bone translation vector value.
	DirectX::XMFLOAT3 translationVec;
	// rot - Current animaiton frame data bone rotation quaternion value.
	DirectX::XMFLOAT4 rotationQuat;
	// sca - Current animaiton frame data bone scaling vector value.
	DirectX::XMFLOAT3 scalingVec;

	// <> - Current animaiton frame data bone world matrix. (???)
	DirectX::XMFLOAT4X4 worldMatrix;

public:
	MyModelAnimationBoneData();
	~MyModelAnimationBoneData();


};

