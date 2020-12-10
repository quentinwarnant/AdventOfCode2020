
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <cmath>

#include "Day10Challenge1.hpp"


Day10Challenge1::Day10Challenge1() 
{
}

Day10Challenge1::~Day10Challenge1() 
{
}

void Day10Challenge1::Execute() 
{
     std::cout << "Day10 Challenge 1 Execute !" << std::endl;

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
     int oneJumpCount = 0;
     int threeJumpCount = 0;
     
     auto adaptorsIt =  adaptors.begin();
     auto adaptorsEndIt = adaptors.end();
     while( adaptorsIt != adaptorsEndIt )
     {
          int adaptorJoltValue = *adaptorsIt;
          int joltDiff =  adaptorJoltValue - currentJoltValue;
          if( joltDiff == 1){
               oneJumpCount++;
          }else if(joltDiff == 3){
               threeJumpCount++;
          }
          currentJoltValue = adaptorJoltValue;

          adaptorsIt++;
          //if reached the end of the adaptors            
          if( adaptorsIt == adaptorsEndIt){

               //device internal adaptor is 3 higher than highest adaptor
               threeJumpCount++;
               break; // done
          }
     }

     int total = oneJumpCount * threeJumpCount;

     std::cout << "one jumps: " << oneJumpCount << " three jumps: " << threeJumpCount << std::endl;
     std::cout << total << std::endl;
}
