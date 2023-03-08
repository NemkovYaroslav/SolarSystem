#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(GameObject* parent)
{
	this->parent = parent;
}
GameObject::~GameObject()
{
	for (const auto& component : components)
	{
		delete component;
	}
	components.clear();
}

void GameObject::Initialize()
{
	for (const auto& component : components)
	{
		component->Initialize();
	}
}

void GameObject::Update(float deltaTime)
{
	for (const auto& component : components)
	{
		component->Update();
	}
}

void GameObject::UpdateWorld()
{
	world = Matrix::CreateFromQuaternion(rotation) * Matrix::CreateTranslation(position);
	if (parent)
	{
		world *= parent->GetWorld();
	}
}

Matrix GameObject::GetWorld() const        { return world;    }
Quaternion GameObject::GetRotation() const { return rotation; }
Vector3 GameObject::GetPosition() const    { return position; }
void GameObject::SetWorld(const Vector3& newPosition, const Quaternion& newRotation) { rotation = newRotation; position = newPosition; UpdateWorld(); }
void GameObject::SetRotation(const Quaternion& newRotation)                          { rotation = newRotation;                         UpdateWorld(); }
void GameObject::SetPosition(const Vector3& newPosition)                             { position = newPosition;                         UpdateWorld(); }