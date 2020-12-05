
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>

#include "Day05Challenge1.hpp"

Day05Challenge1::Day05Challenge1() 
{
}

Day05Challenge1::~Day05Challenge1() 
{
}

void Day05Challenge1::Execute() 
{
     std::cout << "Day05 Challenge 1 Execute !" << std::endl;

     std::ifstream file("Data/Day5.txt");
     std::string line;
     
     int highestSeatID = 0;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          strLine = iss.str();

          int seatId = -1;
          std::string rowStr = strLine.substr(0,7);
          std::string columnStr = strLine.substr(7,9);
          
          int seatRowMin = 0;
          int seatRowMax = 127;
          int seatColMin = 0;
          int seatColMax = 7;
          
          
          for(int i = 0; i < 7; i++){
               if(rowStr.at(i) == 'F'){
                    seatRowMax -= std::pow(2,7-i-1);
               }else{
                    seatRowMin += std::pow(2,7-i-1);
               }
          }
          for(int i = 0; i < 3; i++){
               if(columnStr.at(i) == 'L'){
                    seatColMax -= std::pow(2,3-i-1);
               }else{
                    seatColMin += std::pow(2,3-i-1);
               }
          }

          seatId = (seatRowMin * 8)+seatColMin;
          if( seatId > highestSeatID){
               highestSeatID = seatId;
          }

     }

     
     std::cout << highestSeatID << std::endl;
}
