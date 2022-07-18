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
	const int MAX_ANGLE = 360;
	const float PI = 3.14159265359f;

	float* vertices = nullptr;
	unsigned int* indices = nullptr;

	int centerPointX, centerPointY, radius, angleIncrement;
	int verticesArraySize, indicesArraySize;

	void generateCircle(float* arr);
	void generateTriangleIndices(unsigned int* indices);


public:
	Circle(int centerPointX, int centerPointY, int radius, int angleIncrement);
	~Circle();

	float* getVertices();
	unsigned int* getIndices();

	int getVerticesSize();
	int getIndicesSize();
};