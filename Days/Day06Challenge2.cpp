
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <stdexcept>

#include "Day06Challenge2.hpp"

Day06Challenge2::Day06Challenge2() 
{
}

Day06Challenge2::~Day06Challenge2() 
{
}

void Day06Challenge2::Execute() 
{
     std::cout << "Day06 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day6.txt");
     std::string line;
     
     int totalYesCount = 0;
     std::unordered_map<char,int> groupAnswers;
     int groupSize = 0;

     auto ProcessGroupAnswers = [&totalYesCount](std::unordered_map<char,int> answers, int groupSize){
          for (auto &&i : answers)
          {
               if( i.second == groupSize){
                    totalYesCount++;
               }
          }
     };

     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          strLine = iss.str();
          if( strLine == ""){ // new group
               // for (auto &&i : groupAnswers)
               // {
               //      if( i.second == groupSize){
               //           totalYesCount++;
               //      }
               // }
               ProcessGroupAnswers(groupAnswers, groupSize);
               
               groupAnswers.clear();
               groupSize = 0;
               continue;
          }

          groupSize++;

          for (auto &&c : strLine)
          {
               if(groupAnswers.find(c) == groupAnswers.end() ){ //answer not listed yet
                    groupAnswers.insert({c,1});
               }else{
                    groupAnswers[c]++; //already listed, increment count
               }
          }

     }
     //final group
     ProcessGroupAnswers(groupAnswers, groupSize);
                              
     
     std::cout << totalYesCount << std::endl;
}
