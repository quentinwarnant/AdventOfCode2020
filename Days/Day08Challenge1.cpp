
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "Day08Challenge1.hpp"

Day08Challenge1::Day08Challenge1() 
{
}

Day08Challenge1::~Day08Challenge1() 
{
}

void Day08Challenge1::Execute() 
{
     std::cout << "Day08 Challenge 1 Execute !" << std::endl;

     std::ifstream file("Data/Day8.txt");
     std::string line;
     
     auto commandList = std::vector<CommandData>();
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();

          std::string command = strLine.substr(0,3);
          int arg = std::stoi( strLine.substr(4,strLine.length()-4) );

          auto commandData = CommandData{ command, arg, false};
          commandList.push_back(commandData);
     }

     //Start program at first command
     int accumulator = 0;
     auto currentCommandIt = commandList.begin();
     do{
          (*currentCommandIt).used = true;

          if((*currentCommandIt).cmd == "jmp"){
               currentCommandIt+=(*currentCommandIt).arg;
          }else if((*currentCommandIt).cmd == "nop"){
               currentCommandIt++;
          }else if((*currentCommandIt).cmd == "acc"){
               accumulator+=(*currentCommandIt).arg;
               currentCommandIt++;
          }

     }while( (*currentCommandIt).used == false);


     std::cout << accumulator << std::endl;
}
