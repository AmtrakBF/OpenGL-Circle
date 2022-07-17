#include "cirlce.h"

#include <math.h>
#include <iostream>
#include <algorithm>

Circle::Circle(int centerPointX, int centerPointY, int radius, float* outVertices[], unsigned int* outIndices[])
	: centerPointX(centerPointX), centerPointY(centerPointY), radius(radius)
{
	generateCircle(outVertices);
	generateTriangles(outIndices);
}


void Circle::generateCircle(float* arr[])
{
	int index = 0;
	float radian;
	for (int x = 0; x < THETA; x += SIN_COS_INCREMENT)
	{
		radian = (x * PI) / 180;
		(*arr)[index] = ((radius * cos(radian)) + centerPointX) / 100; 
		index++;
		(*arr)[index] = ((radius * sin(radian)) + centerPointY) / 100; 
		index++;
	}

	float origin_x = centerPointX;
	float origin_y = centerPointY;

	for (float x = origin_x - radius; x < origin_x + radius; x += 1.0f)
	{
		(*arr)[index] = x;
		index++;
		(*arr)[index] = (sqrtf((radius * radius - ((x - origin_x) * (x - origin_x)))) + origin_y) / 100;
		index++;
		(*arr)[index] = x;
		index++;
		(*arr)[index] = (-sqrtf((radius * radius - ((x - origin_x) * (x - origin_x)))) + origin_y) / 100;
		index++;
	}
}

void Circle::generateTriangles(unsigned int* indices[])
{
	int x = 0;
	unsigned int previous = 1;

	while (x < VERTEX_ARRAY_SIZE * 3)
	{
		if (!(x % 3))
			(*indices)[x] = 0;
		else
		{
			(*indices)[x] = previous;
			x++;
			(*indices)[x] = ++previous;
		}
		x++;
	}
}