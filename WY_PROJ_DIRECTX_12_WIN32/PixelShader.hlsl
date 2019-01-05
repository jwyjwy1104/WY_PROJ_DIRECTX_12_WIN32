Texture2D t1 : register(t0);
SamplerState s1 : register(s0);

struct VS_OUTPUT
{
	float4 pos: SV_POSITION;
	float4 color: COLOR;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

float4 main(VS_OUTPUT input) : SV_TARGET
{
	// return interpolated color
	return t1.Sample(s1, input.tex);
//	return input.color;
}

//
//struct VS_OUTPUT
////{
////	float4 pos: SV_POSITION;
////	float4 color: COLOR;
////};
////
////float4 main(VS_OUTPUT input) : SV_TARGET
////{
////	// return interpolated color
////	return input.color;
////}
//
//Texture2D t1 : register(t0);
//SamplerState s1 : register(s0);
//
////Texture2D<float4> shaderTexture : register(t0);
////SamplerState SampleType:register(s0);
//
//struct VS_OUTPUT
//{
//	float4 pos: SV_POSITION;
//	float4 color: COLOR;
//	float2 tex : TEXCOORD0;
//	float3 normal : NORMAL;
//};
//
//float4 main(VS_OUTPUT input) : SV_TARGET
//{
//	//float4 temp = shaderTexture.Sample(SampleType, input.tex);
//	//return temp;
//
//	//return t1.Sample(s1, input.tex);
//
//	//float4 textureColor;
//	//// Sample the pixel color from the texture using the sampler at this texture coordinate location.
//	//textureColor = shaderTexture.Sample(SampleType, input.tex);
//	//return textureColor;
//
//	// return interpolated color
//	//return input.color;
//
//	//float4 val = t1.Sample(s1, input.tex);
//
//	//return val;
//
//	//if (all(input.tex)) {
//	//	return t1.Sample(s1, input.tex);
//	//}
//
//	return input.color;
//
//
//	////float4 val = tex2D(Texture0, tex);
//	//float4 val = t1.Sample(s1, input.tex);
//
//	//// reduce to integer, so components < 1 will become 0
//	//val = trunc(val);
//
//	//// all checks for non-zero, so trunc and 
//	//// then all should mean it was white
//
//	//if (all(val)) {
//	//	// white
//	//	return val;
//
//	//}
//	//else {
//	//	// non-white
//	//	return input.color;
//	//}
//}
//
//
//
//
//
////
////// Per-pixel color data passed through the pixel shader.  
////struct PixelShaderInput
////{
////	float4 pos : SV_POSITION;
////	float3 color : COLOR0;
////	float2 tex : TEXCOORD0;
////	float3 normal : NORMAL;
////	float3 LightPos	: LIGHTPOS;
////	float4 worldPosition : WORLDPOSITION;
////	float3 viewDirection : TEXCOORD1;
////};
////
////Texture2D<float4> shaderTexture : register(t0);
////SamplerState SampleType:register(s0);
////
////// A pass-through function for the (interpolated) color data.  
////float4 main(PixelShaderInput input) : SV_TARGET{
////	// Final pixel color 
////	float4 color = float4(0.0f, 0.0f, 0.0f, 0.0f);
////
////	// Custom input values
////	float3 eyePosition = { 0.0f, 1.7f, 7.5f };
////	float3 lightPosition = { 2.0f, 0.0f, 0.0f };   // NEW
////
////												   ///	float4 diffuse = { 5, 5, 5, 0.0f };
////	float4 ambient = { 1, 1, 1, 1.0 };
////	float3 Ka = { 1.0f, 1.0f, 1.0f };
////	float3 Kd = { 0.64f, 0.64f, 0.64f };
////	float3 Ks = { 0.5f, 0.5f, 0.5f };
////	float3 Ke = { 0.0f, 0.0f, 0.0f };
////	float4 diffuseColor = { 0.64f, 0.64f, 0.64f, 0.0f };
////
////	// Sample the pixel color from the texture using the sampler at this texture coordinate location.
////	float4 textureColor;
////	textureColor = shaderTexture.Sample(SampleType, input.tex) * float4 (input.color, 1.0f);
////
////	//-------------------------------------------------------------------------------------
////	// Ambient lighting
////	//-------------------------------------------------------------------------------------
////	// Set the default output color to the ambient light value for all pixels.
////	// color = ambient;
////
////	//-------------------------------------------------------------------------------------
////	// Diffuse lighting
////	//-------------------------------------------------------------------------------------
////	float3 lightDir = input.worldPosition - lightPosition.xyz;
////	//lightDir = normalize(-lightDir); // Invert the light direction for calculations.
////	lightDir = normalize(-lightDir);
////
////	// Calculate the amount of light on this pixel.
////	float lightIntensity = saturate(dot(input.normal, lightDir)) * 10;
////
////
////	if (lightIntensity > 0.0f) {
////		// Determine the final diffuse color based on the diffuse color and the amount of light intensity.
////		color += (diffuseColor * lightIntensity);
////		//color = saturate(diffuseColor * lightIntensity); // Determine the final amount of diffuse color based on the diffuse color combined with the light intensity.
////	}
////
////	// Saturate the final light color.
////	color = saturate(color);
////
////	//-------------------------------------------------------------------------------------
////	// Specular lighting
////	//-------------------------------------------------------------------------------------
////	// Initialize the specular color.
////	float4 specular = float4(0.0f, 0.0f, 0.0f, 0.0f);
////	// Calculate the reflection vector based on the light intensity, normal vector, and light direction.
////	float3 reflection = normalize(2 * lightIntensity * input.normal - lightDir);
////
////	// Determine the amount of specular light based on the reflection vector, viewing direction, and specular power.
////	specular = pow(saturate(dot(reflection, input.viewDirection)), 1);
////
////	//-------------------------------------------------------------------------------------
////	// Final color calculation
////	//-------------------------------------------------------------------------------------
////	// Multiply the texture pixel and the final diffuse color to get the final pixel color result.
////	color = color * textureColor;
////
////	// Add the specular component
////	color = saturate(color + specular);
////
////
////	//return color;
////
////	return textureColor;
////}
////
////
