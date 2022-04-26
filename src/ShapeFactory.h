#pragma once

#include <array>

#include "Shape.h"

class ShapeFactory
{
public:
	
	static Triangle ConstructTriangleFromLengths(const std::array<double, 3> &lengths); 
	static Triangle ConstructRectangleTriangleFromLengths(const std::array<double, 2> &lengths);
	static Square ConstructSquareFromLengths(double width);
	static Rectangle ConstructRectangleFromLengths(double width, double height);
	static Circle ConstructCircleFromRadius(double radius);
	static Ring ConstructRingFromRadii(double internalRadius, double externalRadius);

};