#include <vector>
#include <math.h>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <algorithm>
#include <exception>
#include <memory>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
    sprintf_s(message, 200, "Impossible de creer un triangle avec les valeurs %f %f %f", m_Side1, m_Side2, m_Side3);
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
    sprintf_s(message, 200, "Impossible de creer un carre avec la valeur %f", m_Width);
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
    sprintf_s(message, 200, "Impossible de creer un carre avec la valeurs %f %f", m_Width, m_Height);
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
    sprintf_s(message, 200, "Impossible de creer un cercle avec la valeurs %f", m_Radius);
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
    sprintf_s(message, 200, "Impossible de creer une couronne avec les valeurs %f %f", m_Radius1, m_Radius2);
    return message;
  }
};

struct Point
{
  double x = {};
  double y = {};
};

double Distance(const Point &p1, const Point &p2)
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

class Shape
{
public:
  Shape() {}

  virtual double Area() = 0;
  virtual double Perimeter() = 0;
};

class Polygon : public Shape
{
public:
  Polygon() {}

  double Perimeter() override
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

protected:
  std::vector<Point> m_Points;
};

class Triangle : public Polygon
{

  /*   

          P2
          /\
         /  \
        /    \
       /      \
      /        \
     /          \
    /            \
    P0-----------P1

  */


public:
  Triangle() 
  {
    m_Points = { Point{}, Point{}, Point{} };
  }

  void SetP1(const Point &point)
  {
    m_Points[0] = point;
  }

  void SetP2(const Point &point)
  {
    m_Points[1] = point;
  }

  void SetP3(const Point &point)
  {
    m_Points[2] = point;
  }

  /*
  Calcul de l'aire grace a la formule de Heron
  https://fr.wikipedia.org/wiki/Formule_de_H%C3%A9ron
  */
  double Area() override
  {
    double AB = Distance(m_Points[0], m_Points[1]);
    double BC = Distance(m_Points[1], m_Points[2]);
    double CA = Distance(m_Points[2], m_Points[0]);

    double p = (AB + BC + CA) / 2.0;
    double s = p * (p - AB) * (p - BC) * (p - CA);

    return std::sqrt(s);
  }
};

class Rectangle : public Polygon
{

  /*
     (0, height)    (width, height)
      P3-------------P2
      |              |
      |              |
      |              |
      P0-------------P1
     (0,0)          (width, 0)
  
  */

public:
  Rectangle()
  {
    m_Points = { Point{}, Point{}, Point{}, Point{} };
  }

  void SetDimensions(double width, double height)
  {
    m_Points[1] = Point{ width, 0.0     };
    m_Points[2] = Point{ width, height  };
    m_Points[3] = Point{ 0.0,   height  };
  }

  double Area() override
  {
    double width = Distance(m_Points[0], m_Points[1]);
    double height = Distance(m_Points[1], m_Points[2]);

    return width * height;
  }

};

class Square : public Polygon
{

  /*
     (0, width)    (width, width)
      P3-------------P2
      |              |
      |              |
      |              |
      P0-------------P1
     (0,0)          (width, 0)
  
  */

public:
  Square()
  {
    m_Points = { Point{}, Point{}, Point{}, Point{} };
  }

  void SetWidth(double width)
  {
    m_Points[1] = Point{ width, 0.0     };
    m_Points[2] = Point{ width, width  };
    m_Points[3] = Point{ 0.0,   width  };
  }

  double Area() override
  {
    double width = Distance(m_Points[0], m_Points[1]);

    return std::pow(width, 2);
  }

};

class Circle : public Shape
{
public:
  Circle():
    m_Radius {}
  {

  }

  void SetRadius(double radius)
  {
    m_Radius = radius;
  }

  double Area() override
  {
    return M_PI * std::pow(m_Radius, 2);
  }

  double Perimeter() override
  {
    return 2 * M_PI * m_Radius;
  }

private:
  double m_Radius;
};

class Ring : public Shape
{
public:
  Ring():
    m_ExternalCircle{},
    m_InternalCircle{}
  {

  }

  void SetExternalCircle(const Circle &circle)
  {
    m_ExternalCircle = circle;
  }

  void SetInternalCircle(const Circle &circle)
  {
    m_ExternalCircle = circle;
  }

  double Area() override
  {
    return m_ExternalCircle.Area() - m_InternalCircle.Area();
  }

  double Perimeter() override
  {
    return m_ExternalCircle.Perimeter() + m_InternalCircle.Perimeter();
  }

private:
  Circle m_ExternalCircle;
  Circle m_InternalCircle;
};

bool ConvertToDouble(const std::string &value, double &out)
{
  try
  {
    out = std::stod(value);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return false;
  }

  return true;
}

bool ConvertStringToLength(const std::string &str, std::vector<double> &values)
{
  std::string currentLength;
  for(size_t i = 0; i < str.size(); ++i)
  {
    if(str[i] != '/')
    {
      currentLength.push_back(str[i]);
    }
    else
    {
      double value = {};
      if(ConvertToDouble(currentLength, value))
      {
        values.push_back(value);
      }
      else
      {
        return false;
      }
      currentLength.clear();
    }
  }

  double value = {};
  if(ConvertToDouble(currentLength, value))
  {
    values.push_back(value);
  }
  else
  {
    return false;
  }
  
  return true;
}

void ConstructTriangleFromLengths(const std::array<double, 3> &lengths, Triangle &out)
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

  out.SetP1(p1);
  out.SetP2(p2);
  out.SetP3(p3);
}

void ConstructRectangleTriangleFromLengths(const std::array<double, 2> &lengths, Triangle &out)
{
  if( lengths[0] <= 0.0 || lengths[1] <= 0.0)
  {
    throw TriangleConstructionError(lengths[0], lengths[1], 0.0);
  } 

  Point p1 {0.0, 0.0};
  Point p2 {lengths[0], 0.0};
  Point p3 {0.0, lengths[1]};

  out.SetP1(p1);
  out.SetP2(p2);
  out.SetP3(p3);
}

void ConstructSquareFromLengths(double width, Square &out)
{
  if(width <= 0.0)
  {
    throw SquareConstructionError(width);
  }

  out.SetWidth(width);
}

void ConstructRectangleFromLengths(double width, double height, Rectangle &out)
{
  if(width <= 0.0)
  {
    throw SquareConstructionError(width);
  }

  out.SetDimensions(width, height);
}

void ConstructCircleFromRadius(double radius, Circle &out)
{
  if(radius <= 0.0)
  {
    throw CircleConstructionError(radius);
  }

  out.SetRadius(radius);
}

void ConstructRingFromRadii(double internalRadius, double externalRadius, Ring &out)
{
  if(internalRadius <= 0.0 || externalRadius <= 0.0)
  {
    throw RingConstructionError(internalRadius, externalRadius);
  }

  Circle c1, c2;
  c1.SetRadius(internalRadius);
  c2.SetRadius(externalRadius);

  out.SetInternalCircle(c1);
  out.SetExternalCircle(c2);
}

void InputChoice1()
{
  std::cout << "Saisir la longueur des trois cotes (AB/BC/BA) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 3)
    {
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 3, arrayOfLength.begin());

      try
      {
        Triangle t {};
        ConstructTriangleFromLengths(arrayOfLength, t);
        std::cout << "L'air du triangle est : " << t.Area() << "\n";
        std::cout << "Le perimetre du triangle est : " << t.Perimeter() << "\n";
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire trois valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice2()
{
  std::cout << "Saisir la longueur Base et Hauteur (Base/Hauteur) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      std::array<double, 2> arrayOfLength = {};
      std::copy_n(lengths.begin(), 2, arrayOfLength.begin());

      try
      {
        Triangle t {};
        ConstructRectangleTriangleFromLengths(arrayOfLength, t);
        std::cout << "L'air du triangle est : " << t.Area() << "\n";
        std::cout << "Le perimetre du triangle est : " << t.Perimeter() << "\n";
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire trois valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice3()
{
  std::cout << "Saisir la longueur Base et Cote (Base/Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 2, arrayOfLength.begin());
      arrayOfLength[2] = lengths[1];
      try
      {
        Triangle t {};
        ConstructTriangleFromLengths(arrayOfLength, t);
        std::cout << "L'air du triangle est : " << t.Area() << "\n";
        std::cout << "Le perimetre du triangle est : " << t.Perimeter() << "\n";
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire trois valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice4()
{
  std::cout << "Saisir la longueur du Cote (Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 1, arrayOfLength.begin());
      arrayOfLength[1] = lengths[0];
      arrayOfLength[2] = lengths[0];
      try
      {
        Triangle t {};
        ConstructTriangleFromLengths(arrayOfLength, t);
        std::cout << "L'air du triangle est : " << t.Area() << "\n";
        std::cout << "Le perimetre du triangle est : " << t.Perimeter() << "\n";
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire trois valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice5()
{
  std::cout << "Saisir la longueur du Cote (Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      double width = lengths[0];
      try
      {
        Square s {};
        ConstructSquareFromLengths(width, s);
        std::cout << "L'air du carre est : " << s.Area() << "\n";
        std::cout << "Le perimetre du carre est : " << s.Perimeter() << "\n";
      } 
      catch(const SquareConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire trois valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice6()
{
  std::cout << "Saisir la longueur de la largeur et de la hauteur (Largeur/Hauteur) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      double width = lengths[0];
      double height = lengths[1];
      try
      {
        Rectangle r {};
        ConstructRectangleFromLengths(width, height, r);
        std::cout << "L'air du carre est : " << r.Area() << "\n";
        std::cout << "Le perimetre du carre est : " << r.Perimeter() << "\n";
      } 
      catch(const SquareConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire deux valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice7()
{
  std::cout << "Saisir la longueur du rayon (Rayon) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      double radius = lengths[0];
      try
      {
        Circle c {};
        ConstructCircleFromRadius(radius, c);
        std::cout << "L'air du cercle est : " << c.Area() << "\n";
        std::cout << "Le perimetre du cercle est : " << c.Perimeter() << "\n";
      } 
      catch(const CircleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire une valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}

void InputChoice8()
{
  std::cout << "Saisir Rayon interrieur et rayon exterieur (Rayon/Rayon) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      double radius1 = lengths[0];
      double radius2 = lengths[1];
      try
      {
        Ring r {};
        ConstructRingFromRadii(radius1, radius2, r);
        std::cout << "L'air du cercle est : " << r.Area() << "\n";
        std::cout << "Le perimetre du cercle est : " << r.Perimeter() << "\n";
      } 
      catch(const RingConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisire deux valeurs"; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes\n";
  }
}


const char* choices = 
  "Toutles les logeurs sont en mm\n"
  "Les longueurs sont saparees par des / (slash)\n"
  "Choix de la forme\n"
  "1 - Triangle quelconque\n"
  "2 - Triangle rectanle\n"
  "3 - Triangle isocel\n"
  "4 - Triangle equilateral\n"
  "5 - Carre\n"
  "6 - Rectangle\n"
  "7 - Cercle\n"
  "8 - Couronne\n"
  "9 - Exit\n";

int main(int argc, char** argv)
{
  std::cout << choices << std::endl;

  bool running = true;

  while(running)
  {
    std::cout << "Choix de la forme : ";
    std::string choice;
    std::cin >> choice;

    if(!choice.empty())
    {
      if(choice == "1")
      {
        InputChoice1();
      }
      else if(choice == "2")
      {
        InputChoice2();
      }
      else if(choice == "3")
      {
        InputChoice3();
      }
      else if(choice == "4")
      {
        InputChoice4();
      }
      else if(choice == "5")
      {
        InputChoice5();
      }
      else if(choice == "6")
      {
        InputChoice6();
      }
      else if(choice == "7")
      {
        InputChoice7();
      }
      else if(choice == "8")
      {
        InputChoice8();
      }
      else if(choice == "9")
      {
        running = false;
        break;
      }
      else
      {
        std::cout << "Cette commande n'exister pas\n";
      }
    }
  }

  return 0;
}