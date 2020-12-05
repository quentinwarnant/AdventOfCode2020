
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>

#include "Day05Challenge2.hpp"

Day05Challenge2::Day05Challenge2() 
{
}

Day05Challenge2::~Day05Challenge2() 
{
}

void Day05Challenge2::Execute() 
{
     std::cout << "Day05 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day5.txt");
     std::string line;
     
     std::vector<int> seats;
    
          
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          strLine = iss.str();

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

          int seatId = (seatRowMin * 8)+seatColMin;
          seats.push_back(seatId);
      
     }

     //Sort seats
     std::sort(seats.begin(), seats.end() );
         
     //find empty seat
     int emptySeatId = FindEmptySeat(seats);

     
     std::cout << emptySeatId << std::endl;
}

int Day05Challenge2::FindEmptySeat(std::vector<int> seats) 
{
     for (size_t i = 0; i < seats.size(); i++)
     {
          //first "row" of plane doesn't exist, so there's an offset of 8
          //if this index (+offset) doesn't match the seat ID, we've missed a seat, ie the previous digit doesn't feature in the seats list/vector
          if( seats.at(i) != i+8){ 
               return seats.at(i)-1; 
          }
     }
     
     return -1;
}
