
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <cmath>

#include "Day10Challenge2.hpp"


Day10Challenge2::Day10Challenge2() 
{
}

Day10Challenge2::~Day10Challenge2() 
{
}

void Day10Challenge2::Execute() 
{
     std::cout << "Day10 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day10.txt");
     std::string line;
     std::set<int> adaptors; 
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();
          adaptors.insert( std::stoi(strLine));
     }

     int currentJoltValue = 0;
     long largestNumber = *(adaptors.rbegin());
     auto adaptorsIt =  adaptors.begin();
     auto adaptorsEndIt = adaptors.end();

     auto leafs = std::map<int,long>();
     std::function<long (std::set<int>::const_iterator)> FindNextPossibleAdaptor = [&](std::set<int>::const_iterator it){
          int currentValue = *it;

          if(currentValue == largestNumber){
               leafs.insert( {currentValue,1L});
               return 1L;
          }

          auto cachedValue = leafs.find(currentValue);
          if(cachedValue != leafs.end()){
               return (*cachedValue).second;
          }
          long arrangements = 0; 
          for (int i = 1; i <= 3; i++)
          {
               it++;
               if( it  == adaptorsEndIt){
                    
                    break;
               }

               if( *it <= (currentValue +3) ){

                    //next adapter is within 3
                    //increment jump count
                    if( (*it - currentValue) <= 3){
                       
                         arrangements+= FindNextPossibleAdaptor(it);
                    }
               }
          }
          leafs.insert( {currentValue,arrangements});
          return arrangements;
     };

     long totalArrangements = FindNextPossibleAdaptor(adaptorsIt);

     std::cout << totalArrangements << std::endl;
}
