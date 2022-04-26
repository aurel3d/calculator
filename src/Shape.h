#pragma once

#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Point
{
  double x = {};
  double y = {};
};

double Distance(const Point &p1, const Point &p2);

class Shape
{
public:
  Shape();

  virtual double Area() const = 0;
  virtual double Perimeter() const = 0;
};

class Polygon : public Shape
{
public:
  Polygon();

  double Perimeter() const override;

protected:
  std::vector<Point> m_Points;
};

class Triangle : public Polygon
{

public:
  Triangle();

  void SetP1(const Point &point);
  void SetP2(const Point &point);
  void SetP3(const Point &point);

  double Area() const override;
};

class Rectangle : public Polygon
{
public:
  Rectangle();

  void SetDimensions(double width, double height);
	
  double Area() const override;

};

class Square : public Polygon
{
public:
  Square();

  void SetWidth(double width);

  double Area() const override;

};

class Circle : public Shape
{
public:
  Circle();

  void SetRadius(double radius);

  double Area() const override;
  double Perimeter() const override;

private:
  double m_Radius;
};

class Ring : public Shape
{
public:
  Ring();

  void SetExternalCircle(const Circle &circle);
  void SetInternalCircle(const Circle &circle);

  double Area() const override;
  double Perimeter() const override;

private:
  Circle m_ExternalCircle;
  Circle m_InternalCircle;
};