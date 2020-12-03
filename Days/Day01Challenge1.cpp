
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Day01Challenge1.hpp"

Day01Challenge1::Day01Challenge1() 
{
    
}

Day01Challenge1::~Day01Challenge1() 
{
}

void Day01Challenge1::Execute() 
{
     std::cout << "Day01 Challenge 1 Execute !" << std::endl;

     std::vector<int> numbers;

     std::ifstream file("Data/Challenge1Data.txt");
     std::string line;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string lineValue;
          if (!(iss >> lineValue)) { break; } // error

          // process pair (a,b)
          //std::cout << lineValue << std::endl;
          numbers.push_back(std::stoi(lineValue));
     }

     const int targetTotal = 2020;
     for (size_t i = 0; i < numbers.size()-1; i++)
     {
          for (size_t j = i+1; j < numbers.size() - i; j++)
          {
               //find a combination of two numbers that sum up to the target total 
               if( numbers.at(i) + numbers.at(j) == targetTotal){
                    //Print to multiplication of the two numbers
                    std::cout << numbers.at(i) * numbers.at(j) << std::endl;
               }
          }
     }
}
