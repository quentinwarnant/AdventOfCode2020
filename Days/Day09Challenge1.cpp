
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "Day09Challenge1.hpp"

typedef long long dataNumber;

Day09Challenge1::Day09Challenge1() 
{
}

Day09Challenge1::~Day09Challenge1() 
{
}

void Day09Challenge1::Execute() 
{
     std::cout << "Day09 Challenge 1 Execute !" << std::endl;

     std::ifstream file("Data/Day9.txt");
     std::string line;
     auto dataList = std::vector<dataNumber>();
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();
          auto dataNum = std::stoll(strLine);
          dataList.push_back(dataNum);
     }

     const unsigned int dataSeriesLength = 25;
     auto bottomIt = dataList.begin();
     auto topIt = bottomIt + dataSeriesLength; 
     auto currentIt = topIt+1;
     auto currentValue = *currentIt;

     auto endIt =  dataList.end();

  
     while(currentIt != endIt){

          bool found = false;
          for (auto it = bottomIt; it < topIt; it++ )
          {
               for (auto it2 = it+1; it2 <= topIt; it2++ )
               {
                    if( *it+*it2 == currentValue){
                         found = true;
                         break;
                    }
               }

               if( found ){
                    break;
               }
          }
          

          if( !found){
               //didn't find a possible combination, exit
               break;
          }

          bottomIt++;
          topIt++; 
          currentIt++;
          currentValue = *currentIt;
          
     }

     std::cout << currentValue << std::endl;
}
