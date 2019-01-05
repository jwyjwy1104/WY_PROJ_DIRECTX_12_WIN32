//struct VS_INPUT
//{
//	float4 pos : POSITION;
//	float4 color: COLOR;
//};
//
//struct VS_OUTPUT
//{
//	float4 pos: SV_POSITION;
//	float4 color: COLOR;
//};
//
//cbuffer ConstantBuffer : register(b0)
//{
//	float4x4 wvpMat;
//};
//
//VS_OUTPUT main(VS_INPUT input)
//{
//	VS_OUTPUT output;
//	output.pos = mul(input.pos, wvpMat);
//	output.color = input.color;
//	return output;
//}


struct VS_INPUT
{
	float4 pos : POSITION;
	float4 color: COLOR;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

struct VS_OUTPUT
{
	float4 pos: SV_POSITION;
	float4 color: COLOR;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

// A constant buffer that stores the three basic column-major matrices for composing geometry.
cbuffer ModelViewProjectionConstantBuffer : register(b0)
{
	matrix model;
	matrix view;
	matrix projection;
	float4x4 wvpMat;
};

VS_OUTPUT main(VS_INPUT input)
{
	VS_OUTPUT output;
	output.pos = mul(input.pos, wvpMat);
	output.color = input.color;

	// Store the texture coordinates for the pixel shader.  
	output.tex = input.tex;

	return output;
}








//
//
//// Per-vertex data used as input to the vertex shader.
//struct VertexShaderInput
//{
//	float4 pos : POSITION;
//	float4 color : COLOR0;
//	float2 tex : TEXCOORD0;
//	float3 normal : NORMAL;
//};
//
//// Per-pixel color data passed through the pixel shader.
//struct PixelShaderInput
//{
//	float4 pos : SV_POSITION;
//	float4 color : COLOR0;
//	float2 tex : TEXCOORD0;
//	float3 normal : NORMAL;
//	float3 lightPos	: LIGHTPOS;
//	float4 worldPosition : WORLDPOSITION;
//	float3 viewDirection : TEXCOORD1;
//};
//
//struct Material {
//	float3 Ke;
//	float3 Ka;
//	float3 Kd;
//	float3 Ks;
//	float  shininess;
//};
//struct Light {
//	float4 position;
//	float4 color;
//};
//
//
//// Simple shader to do vertex processing on the GPU.
//PixelShaderInput main(VertexShaderInput input) {
//	PixelShaderInput output;
//	float4 pos = float4(input.pos, 1.0f);
//
//	float4 worldPosition = mul(input.pos, model);
//	output.worldPosition = worldPosition;
//
//	// Transform the vertex position into projected space.
//	pos = mul(pos, model);
//	pos = mul(pos, view);
//	pos = mul(pos, projection);
//	output.pos = pos;
//
//	// Store the texture coordinates for the pixel shader.  
//	output.tex = input.tex;
//
//	// Pass the color through without modification.
//	output.color = input.color;
//
//	// Calculate the normal vector against the world matrix only.
//	output.normal = mul(input.normal, model);
//
//	// Normalize the normal vector.
//	// output.normal = normalize(output.normal); // When i normalize one half triangle will be gone on a side of the rectangular model
//
//
//	float3 eyePosition = { 0.0f, 1.7f, 7.5f };
//
//	//// Calculate the position of the vertex in the world.
//	//float4 worldPosition = mul(input.position, model);
//
//	// Determine the viewing direction based on the position of the camera and the position of the vertex in the world.
//	output.viewDirection = eyePosition.xyz - worldPosition.xyz;
//
//	// Normalize the viewing direction vector.
//	output.viewDirection = normalize(output.viewDirection);
//
//
//	/*Material shiny;
//	shiny.Ke = float3(0.0, 0.0, 0.0);
//	shiny.Ka = float3(0.1, 0.1, 0.1);
//	shiny.Kd = float3(0.2, 0.4, 0.2);
//	shiny.Ks = float3(0.8, 0.8, 0.8);
//
//	shiny.shininess = 90.0;*/
//
//	return output;
//}

