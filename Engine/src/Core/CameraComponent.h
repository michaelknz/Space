#pragma once
#include "Component.h"
#include "Math/MathStructs.h"

class TransformComponent;
class Object;

class CameraComponent :public Component {
public:
	CameraComponent(Object* obj);
	~CameraComponent();
	void SetSize(int width, int height);
	Matrix4x4f GetVP();
	void Update() override;
	Component* Copy(Object* obj) override;
private:
	void SetVP();
	Matrix4x4f MakeP();
	Matrix4x4f MakeV();
	int width;
	int height;
	float fov;
	float zFar;
	float zNear;
	Matrix4x4f VP;
	TransformComponent* transform;
};