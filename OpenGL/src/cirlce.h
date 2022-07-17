#pragma once

class Circle
{
public:
	struct vertex
	{
		float x, y;
	};

	struct vertex3
	{
		unsigned int a, b, c;
	};

private:
	const int THETA = 360;
	const int SIN_COS_INCREMENT = 10;
	const int VERTEX_ARRAY_SIZE = THETA / SIN_COS_INCREMENT;
	const float PI = 3.14159265359f;

	int centerPointX, centerPointY, radius;

	void generateCircle(float* arr[]);
	void generateTriangles(unsigned int* indices[]);

public:
	Circle(int centerPointX, int centerPointY, int radius, float* outVertices[], unsigned* outIndices[]);

};