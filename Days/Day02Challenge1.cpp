
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day02Challenge1.hpp"

Day02Challenge1::Day02Challenge1() 
{
}

Day02Challenge1::~Day02Challenge1() 
{
}

void Day02Challenge1::Execute() 
{
     std::cout << "Day02 Challenge 1 Execute !" << std::endl;

     int validPasswordCount = 0;


     std::ifstream file("Data/Day2.txt");
     std::string line;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strRange;
          std::string strtestChar;
          std::string strPassword;
          
          //read line to 3 strings, eg of line: "15-19 k: kkkkkkkkkkkkzkkkkkkk"
          if (!(iss >> strRange >> strtestChar >> strPassword)) { break; }
          
          int dashCharIdx =  strRange.find('-');

          char passwordTestChar = strtestChar.at(0);
          int passwordCharOccuranceMin = std::stoi(strRange.substr(0,dashCharIdx));
          int passwordCharOccuranceMax = std::stoi(strRange.substr(dashCharIdx+1, strRange.length()- (dashCharIdx+1) ));
          std::string passwordValue = strPassword;
          
          if( CheckPasswordIsValid(passwordTestChar, passwordCharOccuranceMin, passwordCharOccuranceMax, passwordValue) ) 
          {
               validPasswordCount++;
          }
     }
     
     std::cout << validPasswordCount << std::endl;

}

bool Day02Challenge1::CheckPasswordIsValid(char passwordTestChar, int charOccuranceMin, int charOccuranceMax, std::string passwordValue)
{
     //Count occurences of test character in password string
     int occurences = 0;
     for(char& c : passwordValue) {
          if( c == passwordTestChar)
          {
               occurences++;
          }
     }

     //return whether it was between min & max (both inclusive)
     return occurences >= charOccuranceMin && occurences <= charOccuranceMax;
}