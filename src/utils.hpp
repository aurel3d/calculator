#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <string>

namespace utils
{

bool ConvertToDouble(const std::string &value, double &out)
{
  try
  {
    out = std::stod(value);
  }
  catch(const std::exception& e)
  {
    std::cout << e.what() << " Conversion de \"" << value << "\" en double impossible" << std::endl;
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

}