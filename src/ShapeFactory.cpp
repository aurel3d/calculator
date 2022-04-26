#include "ShapeFactory.h"

#include <cmath>

#include "exceptions.h"

Triangle ShapeFactory::ConstructTriangleFromLengths(const std::array<double, 3> &lengths)
{
  if( (lengths[0] >= (lengths[1] + lengths[2]))
    ||(lengths[0] <= std::abs(lengths[1] - lengths[2])))
  {
    throw TriangleConstructionError(lengths[0], lengths[1], lengths[2]);
  }

  Point p1 {0.0, 0.0};
  Point p2 {lengths[0], 0.0};
  Point p3 {0.0, 0.0};

  p3.x = (std::pow(lengths[0], 2) + std::pow(lengths[2], 2) - std::pow(lengths[1], 2)) / (2*lengths[0]);
  p3.y = std::sqrt(std::pow(lengths[2], 2) - std::pow(p3.x, 2));

	Triangle out {};
  
  out.SetP1(p1);
  out.SetP2(p2);
  out.SetP3(p3);

	return out;
}

Triangle ShapeFactory::ConstructRectangleTriangleFromLengths(const std::array<double, 2> &lengths)
{
  if( lengths[0] <= 0.0 || lengths[1] <= 0.0)
  {
    throw TriangleConstructionError(lengths[0], lengths[1], 0.0);
  }

  Point p1 {0.0, 0.0};
  Point p2 {lengths[0], 0.0};
  Point p3 {0.0, lengths[1]};

	Triangle out {};

  out.SetP1(p1);
  out.SetP2(p2);
  out.SetP3(p3);

	return out;
}

Square ShapeFactory::ConstructSquareFromLengths(double width)
{
  if(width <= 0.0)
  {
    throw SquareConstructionError(width);
  }

	Square out {};

  out.SetWidth(width);
	
  return out;
}

Rectangle ShapeFactory::ConstructRectangleFromLengths(double width, double height)
{
  if(width <= 0.0)
  {
    throw SquareConstructionError(width);
  }

	Rectangle out {};

  out.SetDimensions(width, height);

	return out;
}

Circle ShapeFactory::ConstructCircleFromRadius(double radius)
{
  if(radius <= 0.0)
  {
    throw CircleConstructionError(radius);
  }

	Circle out {};
  
  out.SetRadius(radius);

  return out;
}

Ring ShapeFactory::ConstructRingFromRadii(double internalRadius, double externalRadius)
{
  if(internalRadius <= 0.0 || externalRadius <= 0.0)
  {
    throw RingConstructionError(internalRadius, externalRadius);
  }

  Ring out {};

  Circle c1, c2;
  c1.SetRadius(internalRadius);
  c2.SetRadius(externalRadius);

  out.SetInternalCircle(c1);
  out.SetExternalCircle(c2);

  return out;
}