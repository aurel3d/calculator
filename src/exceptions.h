#pragma once

#include <exception>
#include <stdio.h>
#include <stdlib.h>

struct TriangleConstructionError : public std::exception
{
  double m_Side1;
  double m_Side2;
  double m_Side3;
  
  TriangleConstructionError(double side1, double side2, double side3):
    m_Side1 {side1},
    m_Side2 {side2},
    m_Side3 {side3}
  {
  }

	const char* what() const throw()
  {
    char *message = (char*)malloc(200 * sizeof(char*));
    snprintf(message, 200, "Impossible de creer un triangle : %f %f %f", m_Side1, m_Side2, m_Side3);
    return message;
  }
};

struct SquareConstructionError : public std::exception
{
  double m_Width;
  
  SquareConstructionError(double width):
    m_Width(width)
  {
  }

	const char* what() const throw()
  {
    char *message = (char*)malloc(200 * sizeof(char*));
    snprintf(message, 200, "Impossible de creer un carre : %f", m_Width);
    return message;
  }
};

struct RectangleConstructionError : public std::exception
{
  double m_Width;
  double m_Height;
  
  RectangleConstructionError(double width, double height):
    m_Width(width),
    m_Height(height)
  {
  }

	const char* what() const throw()
  {
    char *message = (char*)malloc(200 * sizeof(char*));
    snprintf(message, 200, "Impossible de creer un rectangle : %f %f", m_Width, m_Height);
    return message;
  }
};

struct CircleConstructionError : public std::exception
{
  double m_Radius;
  
  CircleConstructionError(double radius):
    m_Radius(radius)
  {
  }

	const char* what() const throw()
  {
    char *message = (char*)malloc(200 * sizeof(char*));
    snprintf(message, 200, "Impossible de creer un cercle : %f", m_Radius);
    return message;
  }
};

struct RingConstructionError : public std::exception
{
  double m_Radius1;
  double m_Radius2;
  
  RingConstructionError(double radius1, double radius2):
    m_Radius1(radius1),
    m_Radius2(radius2)
  {
  }

	const char* what() const throw()
  {
    char *message = (char*)malloc(200 * sizeof(char*));
    snprintf(message, 200, "Impossible de creer une couronne : %f %f", m_Radius1, m_Radius2);
    return message;
  }
};