#pragma once

struct Vector3f
{
public:
	float x, y, z;

	Vector3f() = default;
	Vector3f(float pos_x, float pos_y, float pos_z);
	~Vector3f();
};
