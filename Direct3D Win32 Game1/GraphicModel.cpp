#include <DirectXMath.h>
#include "GeometricPrimitive.h"
#include "Effects.h"
#include "pch.h"
#include "GraphicModel.h"

using namespace DirectX;

//GraphicModel::GraphicModel(float p, GeometricPrimitive* m, BasicEffect* e)
//{
//	orbitRadius = p;
//	mesh = m;
//	effect = e;
//}

GraphicModel::GraphicModel(float p, DirectX::GeometricPrimitive* m)
{
	orbitRadius = p;
	mesh = m;
}

void GraphicModel::SetParent(GraphicModel* p)
{
	parent = p;
}

DirectX::XMMATRIX GraphicModel::Update(float rotation)
{
	

	if ( parent != nullptr )
	{
		XMVECTOR normalAxis = XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f);
		XMMATRIX mRot = XMMatrixRotationNormal(normalAxis, rotation);
		XMMATRIX mTrans = XMMatrixTranslation(0.0f, 0.0f, orbitRadius);

		mNew = mTrans * mRot;
		mNew = mNew * parent->mNew;
	}
	else
	{
		mNew = SimpleMath::Matrix::Identity;
	}

	return mNew;


	//effect->SetWorld(mNew);
}

//void GraphicModel::Draw(ID3D11InputLayout* layout, DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj)
//{
//	mesh->Draw(effect, layout);
//	
//}

void GraphicModel::Draw(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj)
{
	mesh->Draw(mNew, view, proj);
}