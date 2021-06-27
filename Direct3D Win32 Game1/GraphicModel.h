#pragma once

class GraphicModel
{
	GraphicModel* parent = nullptr;
	float orbitRadius = 0.0f;
	DirectX::GeometricPrimitive* mesh = nullptr;
	//DirectX::BasicEffect* effect = nullptr;
	

public:
	DirectX::XMMATRIX mNew;
	//GraphicModel();
	//GraphicModel(float radius, ID3D11DeviceContext1*);
	//GraphicModel(float orbitRadius, DirectX::GeometricPrimitive* mesh, DirectX::BasicEffect* effect);
	GraphicModel(float orbitRadius, DirectX::GeometricPrimitive* mesh);

	void SetParent(GraphicModel*);
	DirectX::XMMATRIX Update(float);
	//void Draw(ID3D11InputLayout*);
	void Draw(DirectX::SimpleMath::Matrix, DirectX::SimpleMath::Matrix);

};