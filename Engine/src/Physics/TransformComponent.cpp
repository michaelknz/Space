#include "TransformComponent.h"
#include "Math/MatrixOperations.h"

TransformComponent::TransformComponent(Object* obj)
	:Component(obj), position(), rotation(), scale(1.0f, 1.0f, 1.0f)
{
	comp_name = "transform";
}

TransformComponent::~TransformComponent()
{

}

Component* TransformComponent::Copy(Object* obj)
{
	TransformComponent* output = new TransformComponent(object);
	*output = *this;
	output->object = obj;
	return output;
}

void TransformComponent::SetPosition(const Vector3f& pos)
{
	position = pos;
}

void TransformComponent::SetRotation(const Vector3f& rot)
{
	rotation = rot;
}

void TransformComponent::SetScale(const Vector3f& scale)
{
	this->scale = scale;
}

Vector3f TransformComponent::GetPosition()
{
	return position;
}

Vector3f TransformComponent::GetRotation()
{
	return rotation;
}

Vector3f TransformComponent::GetScale()
{
	return scale;
}

Matrix4x4f TransformComponent::GetM()
{
	return MatrixOperations::Translate(position) * MatrixOperations::Rotation(rotation) * MatrixOperations::Scale(scale);
}

void TransformComponent::Update()
{

}