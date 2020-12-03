
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Day01Challenge2.hpp"

Day01Challenge2::Day01Challenge2() 
{
    
}

Day01Challenge2::~Day01Challenge2() 
{
}

void Day01Challenge2::Execute() 
{
     std::cout << "Day01 Challenge 2 Execute !" << std::endl;

     std::vector<int> numbers;

     //Parse file to a vector of numbers
     std::ifstream file("Data/Day1.txt");
     std::string line;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string lineValue;
          if (!(iss >> lineValue)) { break; } // error
          numbers.push_back(std::stoi(lineValue));
     }

     const int targetTotal = 2020;
     for (size_t i = 0; i < numbers.size()-2; i++)
     {
          for (size_t j = i+1; j < numbers.size() - 1; j++)
          {
               //skip some numbers that are already beyond target befor considering 3rd loop
               if(numbers.at(i) + numbers.at(j) > targetTotal){
                    continue;
               }

               for (size_t k = j+1; k < numbers.size(); k++)
               {
                    //find a combination of two numbers that sum up to the target total 
                    if( numbers.at(i) + numbers.at(j)  + numbers.at(k) == targetTotal){
                         //Print to multiplication of the two numbers
                         std::cout << numbers.at(i) * numbers.at(j) * numbers.at(k) << std::endl;
                    }
               }
          }
     }
}
