#include "Shape.h"

#include <math.h>
#include <cmath>

double Distance(const Point &p1, const Point &p2)
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


/**
 * @brief Construct a new Shape:: Shape object
 * 
 */
Shape::Shape()
{
}


/**
 * @brief Construct a new Polygon:: Polygon object
 * 
 */
Polygon::Polygon() 
{
}

double Polygon::Perimeter() const
{
	double total = {};
	size_t i = 1;
	for(i = 1; i < m_Points.size(); ++i)
	{
		total += Distance(m_Points[i-1], m_Points[i]);
	}
	if(i > 1)
	{
		total += Distance(m_Points[0], m_Points[i-1]);
	}
	return total;
}


/**
 * @brief Construct a new Triangle:: Triangle object
 * 
 */
Triangle::Triangle()
{
	m_Points = { Point{}, Point{}, Point{} };
}

void Triangle::SetP1(const Point &point)
{
	m_Points[0] = point;
}

void Triangle::SetP2(const Point &point)
{
	m_Points[1] = point;
}

void Triangle::SetP3(const Point &point)
{
	m_Points[2] = point;
}

double Triangle::Area() const
{
	double AB = Distance(m_Points[0], m_Points[1]);
	double BC = Distance(m_Points[1], m_Points[2]);
	double CA = Distance(m_Points[2], m_Points[0]);

	double p = (AB + BC + CA) / 2.0;
	double s = p * (p - AB) * (p - BC) * (p - CA);

	return std::sqrt(s);
}


/**
 * @brief Construct a new Rectangle:: Rectangle object
 * 
 */
Rectangle::Rectangle()
{
	m_Points = { Point{}, Point{}, Point{}, Point{} };
}

void Rectangle::SetDimensions(double width, double height)
{
	m_Points[1] = Point{ width, 0.0     };
	m_Points[2] = Point{ width, height  };
	m_Points[3] = Point{ 0.0,   height  };
}

double Rectangle::Area() const
{
	double width = Distance(m_Points[0], m_Points[1]);
	double height = Distance(m_Points[1], m_Points[2]);

	return width * height;
}


/**
 * @brief Construct a new Square:: Square object
 * 
 */
Square::Square()
{
	m_Points = { Point{}, Point{}, Point{}, Point{} };
}

void Square::SetWidth(double width)
{
	m_Points[1] = Point{ width, 0.0     };
	m_Points[2] = Point{ width, width  };
	m_Points[3] = Point{ 0.0,   width  };
}

double Square::Area() const
{
	double width = Distance(m_Points[0], m_Points[1]);

	return std::pow(width, 2);
}


/**
 * @brief Construct a new Circle:: Circle object
 * 
 */
Circle::Circle():
  m_Radius {}
{
}

void Circle::SetRadius(double radius)
{
	m_Radius = radius;
}

double Circle::Area() const
{
	return M_PI * std::pow(m_Radius, 2);
}

double Circle::Perimeter() const
{
	return 2 * M_PI * m_Radius;
}


/**
 * @brief Construct a new Ring:: Ring object
 * 
 */
Ring::Ring():
	m_ExternalCircle{},
	m_InternalCircle{}
{
}

void Ring::SetExternalCircle(const Circle &circle)
{
	m_ExternalCircle = circle;
}

void Ring::SetInternalCircle(const Circle &circle)
{
	m_ExternalCircle = circle;
}

double Ring::Area() const
{
	return m_ExternalCircle.Area() - m_InternalCircle.Area();
}

double Ring::Perimeter() const
{
	return m_ExternalCircle.Perimeter() + m_InternalCircle.Perimeter();
}
