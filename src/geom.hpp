#pragma once

#include <vector>
#include <array>
#include <math.h>

#include "exceptions.h"

namespace geom
{

constexpr double pi = 3.14159265358979323846;

struct Shape2D
{
};

template<typename T>
struct Point2D
{
	T x = {};
	T y = {};
};

template<typename T>
T Distance(const Point2D<T> &p1, const Point2D<T> &p2)
{
	return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

template<typename T>
struct Polygon : public Shape2D
{
	using PolygonPoint = Point2D<T>;

	Polygon(const std::vector<PolygonPoint> &t_points):
		points { t_points }
	{
	}

	std::vector<PolygonPoint> points = {};
};

template<typename T>
struct Circle : public Shape2D
{
	Circle(T t_radius):
		radius { t_radius }
	{
	}
	T radius;
};

template<typename T>
struct Ring : public Shape2D
{
	Ring(const Circle<T>& t_innerCircle, const Circle<T>& t_outerCircle):
		innerCircle { t_innerCircle },
		outerCircle { t_outerCircle }
	{}

	Circle<T> innerCircle;
	Circle<T> outerCircle;
};


template<typename T>
struct Triangle : public Shape2D
{
	using PointType = Point2D<T>;

	Triangle(const std::array<PointType, 3>& t_points):
		points { t_points }
	{
	}

	Triangle(Triangle&& other):
		points { std::move(other.points) }
	{
	}

	Triangle(const Triangle& other):
		points { other.points }
	{
	}

	std::array<PointType, 3> points = {};
};

template<typename T>
struct Square : public Shape2D
{
	using PointType = Point2D<T>;

	Square(const std::array<PointType, 4>& t_points):
		points { t_points }
	{	
	}

	std::array<PointType, 4> points = {};
};

template<typename T>
struct Rectangle : public Shape2D
{
	using PointType = Point2D<T>;

	Rectangle(const std::array<PointType, 4>& t_points):
		points { t_points }
	{
	}

	std::array<PointType, 4> points = {};
};

template<typename T>
Triangle<T> make_triangle(T AB, T BC, T CA)
{
	if( (AB >= (BC +CA))
    ||(AB <= std::abs(BC - CA)))
  {
    throw TriangleConstructionError(AB, BC, CA);
  } 

	Point2D<T> p1 {0.0, 0.0};
  Point2D<T> p2 {AB, 0.0};
  Point2D<T> p3 {0.0, 0.0};

  p3.x = (std::pow(AB, 2) + std::pow(CA, 2) - std::pow(BC, 2)) / (2*AB);
  p3.y = std::sqrt(std::pow(CA, 2) - std::pow(p3.x, 2));

	Triangle<T> t = {{p1, p2, p3}};
	return t;
}

template<typename T> 
Triangle<T> make_rectangleTriangle(T base, T height)
{
	if(base <= 0.0 || height <= 0.0)
  {
    throw TriangleConstructionError(base, height, 0.0);
  } 

	Point2D<T> p1 {0.0, 0.0};
  Point2D<T> p2 {base, 0.0};
  Point2D<T> p3 {0.0, height};

	return Triangle<T> {{p1, p2, p3}};
}

template<typename T>
Triangle<T> make_isoscelesTriangle(T base, T side)
{
	return make_triangle(base, side, side);
}

template<typename T>
Triangle<T> make_equilateralTriangle(T side)
{
	return make_triangle(side, side, side);
}

template<typename T>
Rectangle<T> make_rectangle(T width, T height)
{
	if(width <= 0.0 || height <= 0.0)
  {
    throw RectangleConstructionError(width, height);
  }

	Point2D<T> p1 {0.0, 0.0};
  Point2D<T> p2 {width, 0.0};
  Point2D<T> p3 {width, height};
  Point2D<T> p4 {0.0, height};

	Rectangle<T> r = {{p1, p2, p3, p4}};
	return r;
}

template<typename T> 
Square<T> make_square(T width)
{
	if(width <= 0.0)
  {
    throw SquareConstructionError(width);
  }

	Point2D<T> p1 {0.0, 0.0};
  Point2D<T> p2 {width, 0.0};
  Point2D<T> p3 {width, width};
  Point2D<T> p4 {0.0, width};

	Square<T> r = {{p1, p2, p3, p4}};
	return r;
}

template<typename T>
Circle<T> make_circle(T radius)
{
	if(radius <= 0.0)
  {
    throw CircleConstructionError(radius);
  }


	Circle<T> c = {radius};
	return c;
}

template<typename T>
Ring<T> make_ring(T innerRadius, T outerRadius)
{
	if(innerRadius <= 0.0 || outerRadius <= 0.0)
  {
    throw RingConstructionError(innerRadius, outerRadius);
  }

	Ring<T> r = {Circle{innerRadius}, Circle{outerRadius}};
	return r;
}

}