#include <DirectXMath.h>
#include "GeometricPrimitive.h"
#include "Effects.h"
#include "pch.h"
#include "GraphicModel.h"

using namespace DirectX;

GraphicModel::GraphicModel(float p, GeometricPrimitive* m, BasicEffect* e)
{
	orbitRadius = p;
	mesh = m;
	effect = e;
}

void GraphicModel::SetParent(GraphicModel* p)
{
	parent = p;
}

void GraphicModel::Update(float rotation)
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


	effect->SetWorld(mNew);
}

void GraphicModel::Draw(ID3D11InputLayout* layout)
{
	mesh->Draw(effect, layout);
}