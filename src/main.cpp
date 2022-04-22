#include <vector>
#include <math.h>
#include <iostream>
#include <array>

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

bool ConvertToDouble(const std::string &value)
{
  try
  {
    std::stod(value);
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
  for(int i = 0; i < str.size(); ++i)
  {
    if(str[i] != '/')
    {
      currentLength.push_back(str[i]);
    }
    else
    {
      double value = {};
      if(ConvertToDouble(currentLength))
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
  if(ConvertToDouble(currentLength))
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

}

int main(int argc, char** argv)
{
  bool running = true;

  while(running)
  {
    std::cout << "Choix de la forme\n";
    std::cout << "1 - Triangle quelconque\n";
    std::cout << "2 - Triangle rectanle\n";
    std::cout << "3 - Triangle isocel\n";
    std::cout << "4 - Carre\n";
    std::cout << "5 - Rectangle\n";
    std::cout << "6 - Cercle\n";
    std::cout << "7 - Couronne\n";
    std::cout << "8 - Exit\n";

    std::string choice;
    std::cin >> choice;

    if(!choice.empty())
    {
      if(choice == "1")
      {
        std::cout << "Saisir la longueur des cotes (5.5/2/3.2)\n";
        std::string value;
        std::cin >> value;
        std::vector<double> lengths;
        if(ConvertStringToLength(value, lengths))
        {
          if(lengths.size() == 3)
          {

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