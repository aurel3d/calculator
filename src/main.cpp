#include <vector>
#include <math.h>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <algorithm>

struct Point
{
  double x = {};
  double y = {};
};

double Distance(const Point &p1, const Point &p2)
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p2.y, 2));
}

class Shape
{
public:
  Shape() {}

  virtual double Area() = 0;
};

class Polygon : public Shape
{
public:
  Polygon() {}

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

private:
  double m_Radius;
};

class Annulus : public Shape
{
public:
  Annulus():
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

private:
  Circle m_ExternalCircle;
  Circle m_InternalCircle;
};

bool ConvertToDouble(const std::string &value, double &out)
{
  std::cout << "Convert to double " << value << "\n";
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

Triangle ConstructTriangleFromLengths(const std::array<double, 3> &lengths)
{
  std::cout << lengths[0] << " " << lengths[1] << " " << lengths[2] << "\n";

  Point p1 {0.0, 0.0};
  Point p2 {lengths[0], 0.0};
  Point p3 {0.0, 0.0};

  p3.y = (std::pow(lengths[0], 2) + std::pow(lengths[2], 2) - std::pow(lengths[1], 2)) / (2*lengths[0]);
  p3.x = std::sqrt(std::pow(lengths[2], 2) - std::pow(p3.y, 2));

  Triangle t {};
  t.SetP1(p1);
  t.SetP2(p2);
  t.SetP3(p3);

  std::cout << "P1 " << p1.x << " " << p1.y << "\n";
  std::cout << "P2 " << p2.x << " " << p2.y << "\n";
  std::cout << "P3 " << p3.x << " " << p3.y << "\n";

  return t;
}

const char* choices = 
  "Choix de la forme\n"
  "1 - Triangle quelconque\n"
  "2 - Triangle rectanle\n"
  "3 - Triangle isocel\n"
  "4 - Carre\n"
  "5 - Rectangle\n"
  "6 - Cercle\n"
  "7 - Couronne\n"
  "8 - Exit\n";

int main(int argc, char** argv)
{

  std::cout << choices << std::flush;

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
        std::cout << "Saisir la longueur des cotes (5.5/2/3.2) : ";
        std::string value;
        std::cin >> value;
        std::vector<double> lengths;
        if(ConvertStringToLength(value, lengths))
        {
          if(lengths.size() == 3)
          {
            std::cout << "Lengths " << lengths[0] << " " << lengths[1] << " " << lengths[2] << "\n";
            std::array<double, 3> arrayOfLength = {};
            std::copy_n(lengths.begin(), 3, arrayOfLength.begin());

            Triangle t = ConstructTriangleFromLengths(arrayOfLength);

            std::cout << "L'air du triangle est : " << t.Area() << "\n";
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
      else if(choice == "8")
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