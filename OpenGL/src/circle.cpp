#include "circle.h"

#include <math.h>
#include <iostream>
#include <algorithm>

Circle::Circle(int centerPointX, int centerPointY, int radius, int angleIncrement)
	: centerPointX(centerPointX), centerPointY(centerPointY), radius(radius), angleIncrement(angleIncrement)
{
	verticesArraySize = (MAX_ANGLE / angleIncrement) * 2 + 2;
	indicesArraySize = (MAX_ANGLE / angleIncrement) * 3;

	vertices = (float*)_malloca(verticesArraySize * sizeof(float)); // Max Circle Angle / Angle Increment * Number of Positions per index... (0, 3) + (centerPointX, centerPointY)
	indices = (unsigned int*)_malloca(indicesArraySize * sizeof(unsigned int)); // Max Circle Angle / Angle Increment * Number of Positions per index... (0, 3, 4)

	generateCircle(vertices);
	generateTriangleIndices(indices);
}

Circle::~Circle()
{
	_freea(vertices);
	_freea(indices);
	indices = nullptr;
	vertices = nullptr;
}


void Circle::generateCircle(float* arr)
{
	// int center point in array
	arr[0] = (float)centerPointX/100;
	arr[1] = (float)centerPointY/100;

	int index = 2;
	float radian;
	for (float x = 0; x < MAX_ANGLE; x += angleIncrement)
	{
		radian = (x * PI) / 180;
		arr[index] = ((radius * cos(radian)) + centerPointX) / 100; // calculate X coord from cos
		index++;
		arr[index] = ((radius * sin(radian)) + centerPointY) / 100; // calculate Y coord form sin
		index++;
	}
}

void Circle::generateTriangleIndices(unsigned int* indices)
{
	int x = 0;
	unsigned int previous = 1;

	while (x < indicesArraySize)
	{
		if (!(x % 3)) // if [0] or every third index
			indices[x] = 0;
		else if (x >= indicesArraySize - 3) // last set of vertices
		{
			indices[x] = 1; // first index
			x++;
			indices[x] = previous;
		} 
		else
		{
			indices[x] = previous;
			x++;
			indices[x] = ++previous;
		}
		x++;
	}
}

float* Circle::getVertices()
{
	if (vertices)
		return vertices;
	return vertices;
}

unsigned int* Circle::getIndices()
{
	if (indices)
		return indices;
	return indices;
}

int Circle::getVerticesSize()
{
	return verticesArraySize;
}

int Circle::getIndicesSize()
{
	return indicesArraySize;
}