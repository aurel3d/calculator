#include <vector>
#include <math.h>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <algorithm>
#include <exception>
#include <memory>
#include <string>
#include <stdio.h>
#include <type_traits>

#include "exceptions.h"
#include "geom.hpp"
#include "algo.hpp"
#include "utils.hpp"
#include "Shape.h"
#include "ShapeFactory.h"

void DisplayShapeResult(const Shape &shape)
{
  std::cout << "L'aire est : " << shape.Area() << " mm2" << std::endl;
  std::cout << "Le perimetre est : " << shape.Perimeter() << " mm" << std::endl;
}

template<typename T>
void DisplayResult(const T &shape)
{
  static_assert(std::is_base_of_v<geom::Shape2D, T>, "DisplayResult<T> a besoin que T soit de type Shape2D");
  std::cout << "L'aire est : " << algo::calculate_area(shape) << " mm2" << std::endl;
  std::cout << "Le perimetre est : " << algo::calculate_perimeter(shape) << " mm" << std::endl;
}

void InputChoice1()
{
  std::cout << "Saisir la longueur des trois cotes (AB/BC/BA) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 3)
    {
      try
      {
        DisplayResult(geom::make_triangle(lengths[0], lengths[1], lengths[2]));
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << std::endl;
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir trois valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice2()
{
  std::cout << "Saisir la longueur Base et Hauteur (Base/Hauteur) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      try
      {
        DisplayResult(geom::make_rectangleTriangle(lengths[0], lengths[1]));
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << std::endl;
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir deux valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice3()
{
  std::cout << "Saisir la longueur Base et Cote (Base/Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      try
      {
        DisplayResult(geom::make_isoscelesTriangle(lengths[0], lengths[1]));
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << std::endl;
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir deux valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice4()
{
  std::cout << "Saisir la longueur du Cote (Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      try
      {
        DisplayResult(geom::make_equilateralTriangle(lengths[0]));
      } 
      catch(const TriangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir une valeur" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice5()
{
  std::cout << "Saisir la longueur du Cote (Cote) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      try
      {
        DisplayResult(geom::make_square(lengths[0]));
      } 
      catch(const SquareConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir une valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice6()
{
  std::cout << "Saisir la largeur et la hauteur (Largeur/Hauteur) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      try
      {
        DisplayResult(geom::make_rectangle(lengths[0], lengths[1]));
      } 
      catch(const RectangleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir deux valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice7()
{
  std::cout << "Saisir le rayon (Rayon) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      try
      {
        DisplayResult(geom::make_circle(lengths[0]));
      } 
      catch(const CircleConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir une valeur" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void InputChoice8()
{
  std::cout << "Saisir rayon interieur et rayon exterieur (Rayon/Rayon) : ";
  std::string value;
  std::cin >> value;
  std::vector<double> lengths;
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      try
      {
        DisplayResult(geom::make_ring(lengths[0], lengths[1]));
      } 
      catch(const RingConstructionError& e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else
    {
      std::cout << "Erreur : Il faut saisir deux valeurs" << std::endl; 
    }
  }
  else
  {
    std::cout << "Les donnees saisies ne sont pas correctes" << std::endl;
  }
}

void Example()
{
  try
  {
    std::cout << "Triangle 1/2/3" << std::endl;
    Triangle t = ShapeFactory::ConstructTriangleFromLengths({1, 2, 3});
    DisplayShapeResult(t);
  }
  catch(const TriangleConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    std::cout << "Triangle 20/30/30" << std::endl;
    Triangle t = ShapeFactory::ConstructTriangleFromLengths({20, 30, 30});
    DisplayShapeResult(t);
  }
  catch(const TriangleConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    std::cout << "Rectangle 10/20" << std::endl;
    Rectangle r = ShapeFactory::ConstructRectangleFromLengths(10, 20);
    DisplayShapeResult(r);
  }
  catch(const RectangleConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    std::cout << "Square 30" << std::endl;
    Square s = ShapeFactory::ConstructSquareFromLengths(30);
    DisplayShapeResult(s);
  }
  catch(const SquareConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    std::cout << "Circle 10" << std::endl;
    Circle c = ShapeFactory::ConstructCircleFromRadius(10);
    DisplayShapeResult(c);
  }
  catch(const CircleConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }

  try
  {
    std::cout << "Ring 10/20" << std::endl;
    Ring r = ShapeFactory::ConstructRingFromRadii(10, 20);
    DisplayShapeResult(r);
  }
  catch(const RingConstructionError& e)
  {
    std::cerr << e.what() << '\n';
  }
}


const char* choices = 
  "#################################\n"
  "Toutes les les logeurs sont en mm\n"
  "Les surfaces sont en mm2\n"
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
  Example();

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
        std::cout << "Cette commande n'existe pas" << std::endl;
      }
    }
  }

  return 0;
}