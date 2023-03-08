#include "KatamariObject.h"
#include "RenderComponent.h"

KatamariObject::KatamariObject(KatamariObject* parent) : GameObject(parent)
{
	this->rotationAxis = Vector3::UnitY;
	this->orbitAxis = Vector3::UnitY;
	this->rotationSpeed = 0;
	this->orbitSpeed = 0;
	this->rotator = Quaternion::Identity;
	this->orbitalRotation = Quaternion::Identity;
}

void KatamariObject::CreateCube(float sideSize)
{
	renderComponent = new RenderComponent("../Shaders/MyVeryFirstShader.hlsl", D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	renderComponent->AddCube(sideSize);
	components.push_back(renderComponent);
}
void KatamariObject::CreateSphere(float radius, int sliceCount, int stackCount, DirectX::XMFLOAT4 color)
{
	renderComponent = new RenderComponent("../Shaders/MyVeryFirstShader.hlsl", D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	renderComponent->AddSphere(radius, sliceCount, stackCount, color);
	components.push_back(renderComponent);
}

void KatamariObject::Initialize()
{
	orbitAxis.Normalize();
	rotationAxis.Normalize();
	GameObject::Initialize();
}

void KatamariObject::Update(float deltaTime)
{
	rotator *= Quaternion::CreateFromAxisAngle(rotationAxis, rotationSpeed * deltaTime);
	SetRotation(rotator);
	orbitalRotation *= Quaternion::CreateFromAxisAngle(orbitAxis, orbitSpeed * deltaTime);
	renderComponent->World = GetWorld();
	GameObject::Update(deltaTime);
}

void KatamariObject::UpdateWorld()
{
	world = Matrix::CreateFromQuaternion(GameObject::GetRotation()) * Matrix::CreateTranslation(GameObject::GetPosition());
	if (parent)
	{
		//world *= parent->GetWorld();
		world *= Matrix::CreateFromQuaternion(orbitalRotation) * Matrix::CreateTranslation(parent->GetPosition());
	}
}

Vector3 KatamariObject::GetPosition() const
{
	if (parent)
	{
		return Vector3::Transform(GameObject::GetPosition(), Matrix::CreateFromQuaternion(orbitalRotation) * Matrix::CreateTranslation(parent->GetPosition()));
	}
	return GameObject::GetPosition();
}