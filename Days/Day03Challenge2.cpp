
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day03Challenge2.hpp"

Day03Challenge2::Day03Challenge2() 
{
}

Day03Challenge2::~Day03Challenge2() 
{
}

void Day03Challenge2::Execute() 
{
     std::cout << "Day03 Challenge 2 Execute !" << std::endl;

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
     
     auto patterns = std::vector<std::pair<int,int>>();
     patterns.push_back(std::make_pair(1,1));
     patterns.push_back(std::make_pair(3,1));
     patterns.push_back(std::make_pair(5,1));
     patterns.push_back(std::make_pair(7,1));
     patterns.push_back(std::make_pair(1,2));

     long treeCountMultiplied = 1;
     for(auto &pattern : patterns){
          int treeCount = CountTrees(map,pattern.first, pattern.second);
          std::cout << treeCount << std::endl;

          treeCountMultiplied *= treeCount;
     }

     std::cout << treeCountMultiplied << std::endl;
}