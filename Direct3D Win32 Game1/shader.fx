//float4x4 World;
//float4x4 View;
//float4x4 Projection;
//// TODO: add effect parameters here.
//struct VertexShaderInput
//{
//    float4 Position : POSITION0;
//    // TODO: add input channels such as texture
//    // coordinates and vertex colors here.
//};
//struct VertexShaderOutput
//{
//    float4 Position : POSITION0;
//    float4 Color : COLOR0;
//    // TODO: add vertex shader outputs such as colors and texture
//    // coordinates here. These values will automatically be interpolated
//    // over the triangle, and provided as input to your pixel shader.
//};
//VertexShaderOutput VertexShaderFunction(VertexShaderInput input)
//{
//    VertexShaderOutput output;
//    float4 worldPosition = mul(input.Position, World);
//    float4 viewPosition = mul(worldPosition, View);
//    output.Position = mul(viewPosition, Projection);
//
//    // TODO: add your vertex shader code here.
//    output.Color = (0.0f, 0.0f, 0.f, 1.0f);
//    return output;
//}
//float4 PixelShaderFunction(VertexShaderOutput input) : COLOR0
//{
//    // TODO: add your pixel shader code here.
//    return input.Color;//float4(1, 0, 0, 1);
//}
///*






//struct VS_IN
//{
//	float4 pos : POSITION0;
//	float4 col : COLOR0;
//};
//
//struct PS_IN
//{
//	float4 pos : SV_POSITION;
//	float4 col : COLOR;
//};
//
//PS_IN VSMain(VS_IN input)
//{
//	PS_IN output = (PS_IN)0;
//
//	output.pos = input.pos;
//	output.col = input.col;
//
//	 output.col = (0.0f, 0.0f, 0.0f, 0.5f);
//
//	return output;
//}
//
//float4 PSMain(PS_IN input) : SV_Target
//{
//	/*
//	float4 col = input.col;
//#ifdef TEST
//	if (input.pos.x < 400) col = TCOLOR;
//#endif
//	
//	return col;
//	*/
//	return float4(0.0f, 0.0f, 0.0f, 1.0f);
//}

//technique Technique1
//{
//    pass Pass1
//    {
//        // TODO: set renderstates here.
//        VertexShader = compile vs_1_1 VertexShaderFunction();
//        PixelShader = compile ps_1_1 PixelShaderFunction();
//    }
//}
//*/

struct VS_IN
{
	float4 pos : POSITION;
	float4 col : COLOR;
};

struct PS_IN
{
	float4 pos : SV_POSITION;
	float4 col : COLOR;
};

PS_IN VSMain(VS_IN input)
{
	PS_IN output = (PS_IN)0;
	output.pos = input.pos;//mul(float4(input.pos.xyz, 10.f), ConstData.WorldVievProj);
	output.col = (1.0f, 1.0f, 0.0f, 0.5f);// input.col;
	return output;
}



float4 PSMain(PS_IN input) : SV_Target
{
	return float4(0.0f, 0.0f, 0.0f, 1.0f);
}