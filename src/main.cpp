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

#include "exceptions.h"
#include "utils.hpp"
#include "ShapeFactory.h"
#include "Shape.h"

void DisplayResult(const Shape &shape)
{
  std::cout << "L'aire est : " << shape.Area() << " mm2 \n";
  std::cout << "Le perimetre est : " << shape.Perimeter() << " mm \n";
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
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 3, arrayOfLength.begin());

      try
      {
        Triangle t = ShapeFactory::ConstructTriangleFromLengths(arrayOfLength);
        DisplayResult(t);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      std::array<double, 2> arrayOfLength = {};
      std::copy_n(lengths.begin(), 2, arrayOfLength.begin());

      try
      {
        Triangle t = ShapeFactory::ConstructRectangleTriangleFromLengths(arrayOfLength);
        DisplayResult(t);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 2, arrayOfLength.begin());
      arrayOfLength[2] = lengths[1];
      try
      {
        Triangle t = ShapeFactory::ConstructTriangleFromLengths(arrayOfLength);
        DisplayResult(t);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      std::array<double, 3> arrayOfLength = {};
      std::copy_n(lengths.begin(), 1, arrayOfLength.begin());
      arrayOfLength[1] = lengths[0];
      arrayOfLength[2] = lengths[0];
      try
      {
        Triangle t = ShapeFactory::ConstructTriangleFromLengths(arrayOfLength);
        DisplayResult(t);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      double width = lengths[0];
      try
      {
        Square s = ShapeFactory::ConstructSquareFromLengths(width);
        DisplayResult(s);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      double width = lengths[0];
      double height = lengths[1];
      try
      {
        Rectangle r = ShapeFactory::ConstructRectangleFromLengths(width, height, r);
        DisplayResult(r);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 1)
    {
      double radius = lengths[0];
      try
      {
        Circle c = ShapeFactory::ConstructCircleFromRadius(radius);
        DisplayResult(c);
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
  if(utils::ConvertStringToLength(value, lengths))
  {
    if(lengths.size() == 2)
    {
      double radius1 = lengths[0];
      double radius2 = lengths[1];
      try
      {
        Ring r = ShapeFactory::ConstructRingFromRadii(radius1, radius2);
        DisplayResult(r);
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
        std::cout << "Cette commande n'existe pas\n";
      }
    }
  }

  return 0;
}