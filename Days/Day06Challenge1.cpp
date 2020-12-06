
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <cmath>

#include "Day06Challenge1.hpp"

Day06Challenge1::Day06Challenge1() 
{
}

Day06Challenge1::~Day06Challenge1() 
{
}

void Day06Challenge1::Execute() 
{
     std::cout << "Day06 Challenge 1 Execute !" << std::endl;

     std::ifstream file("Data/Day6.txt");
     std::string line;
     
     int totalYesCount = 0;
     std::unordered_set<char> groupAnswers;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          strLine = iss.str();
          if( strLine == ""){ // new group
               totalYesCount += groupAnswers.size();
               groupAnswers.clear();
               continue;
          }

          for (auto &&c : strLine)
          {
               groupAnswers.insert(c);
          }

     }
     totalYesCount += groupAnswers.size();// final group
               
     
     std::cout << totalYesCount << std::endl;
}
