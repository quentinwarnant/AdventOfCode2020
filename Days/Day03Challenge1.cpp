
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day03Challenge1.hpp"

Day03Challenge1::Day03Challenge1() 
{
}

Day03Challenge1::~Day03Challenge1() 
{
}

void Day03Challenge1::Execute() 
{
     std::cout << "Day03 Challenge 1 Execute !" << std::endl;

     int validPasswordCount = 0;

     bool map[323][31];
     std::ifstream file("Data/Day3.txt");
     std::string line;
     int row = 0;
     int column = 0;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          //read line to 3 strings, eg of line: "15-19 k: kkkkkkkkkkkkzkkkkkkk"
          if (!(iss >> strLine)) { break; }
         
          for(char& c : strLine){
               map[row][column] = c == '.'; //Open space
               column++;
          }
          row++;
          column = 0;
     }
     
     //Traverse map with pattern of 3 Right, 1 down, starting from 0,0 , wrapping when going too far to the right
     int treeCounts = 0;
     int x = 0;
     int y = 0;
     do{
          x += 3;
          y += 1;
          //Wrap X
          x = x%31;

          if(map[y][x] == false){ // Tree found
               treeCounts++;
          }

     }while(y < 323);

     std::cout << treeCounts << std::endl;

}
