#pragma once

#include "geom.hpp"

namespace algo
{

/*
Calcul de l'aire grace a la formule de Heron
https://fr.wikipedia.org/wiki/Formule_de_H%C3%A9ron
*/
double calculate_area(const geom::Triangle<double> &triangle)
{
  double AB = geom::Distance(triangle.points[0], triangle.points[1]);
  double BC = geom::Distance(triangle.points[1], triangle.points[2]);
  double CA = geom::Distance(triangle.points[2], triangle.points[0]);

  double p = (AB + BC + CA) / 2.0;
  double s = p * (p - AB) * (p - BC) * (p - CA);

  return std::sqrt(s);
}

double calculate_area(const geom::Rectangle<double> &rectangle)
{
  double AB = geom::Distance(rectangle.points[0], rectangle.points[1]);
  double BC = geom::Distance(rectangle.points[1], rectangle.points[2]);
  
  return AB * BC;
}

double calculate_area(const geom::Square<double> &square)
{
  double AB = geom::Distance(square.points[0], square.points[1]);
  return AB * AB;
}

double calculate_area(const geom::Circle<double> &circle)
{
  return circle.radius * circle.radius * geom::pi;
}

double calculate_area(const geom::Ring<double> &ring)
{
  return calculate_area(ring.outerCircle) - calculate_area(ring.innerCircle);
}

double calculate_perimeter(const geom::Polygon<double> &polygon)
{
  double total = {};
  size_t i = 1;
  for(i = 1; i < polygon.points.size(); ++i)
  {
    total += geom::Distance(polygon.points[i-1], polygon.points[i]);
  }
  if(i > 1)
  {
    total += geom::Distance(polygon.points[0], polygon.points[i-1]);
  }
  return total;
}

double calculate_perimeter(const geom::Triangle<double> &triangle)
{
  double AB = geom::Distance(triangle.points[0], triangle.points[1]);
  double BC = geom::Distance(triangle.points[1], triangle.points[2]);
  double CA = geom::Distance(triangle.points[2], triangle.points[0]);

  return AB + BC + CA;
}

double calculate_perimeter(const geom::Square<double> &triangle)
{
  double AB = geom::Distance(triangle.points[0], triangle.points[1]);
  return AB * 4;
}

double calculate_perimeter(const geom::Rectangle<double> &triangle)
{
  double AB = geom::Distance(triangle.points[0], triangle.points[1]);
  double BC = geom::Distance(triangle.points[1], triangle.points[2]);
  return AB * 2 + BC * 2;
}

double calculate_perimeter(const geom::Circle<double> &circle)
{
  return 2 * geom::pi * circle.radius;
}

double calculate_perimeter(const geom::Ring<double> &ring)
{
  return calculate_perimeter(ring.innerCircle) + calculate_perimeter(ring.outerCircle);
}

}