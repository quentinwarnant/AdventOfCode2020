
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day02Challenge2.hpp"

Day02Challenge2::Day02Challenge2() 
{
}

Day02Challenge2::~Day02Challenge2() 
{
}

void Day02Challenge2::Execute() 
{
     std::cout << "Day02 Challenge 2 Execute !" << std::endl;

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
          int charAToTestIdx = std::stoi(strRange.substr(0,dashCharIdx));
          int charBToTestIdx = std::stoi(strRange.substr(dashCharIdx+1, strRange.length()- (dashCharIdx+1) ));
          std::string passwordValue = strPassword;
          
          if( CheckPasswordIsValid(passwordTestChar, charAToTestIdx, charBToTestIdx, passwordValue) ) 
          {
               validPasswordCount++;
          }
     }
     
     std::cout << validPasswordCount << std::endl;

}

bool Day02Challenge2::CheckPasswordIsValid(char passwordTestChar, int charAToTestIdx, int charBToTestIdx, std::string passwordValue)
{
     //return whether only 1 (exclusive or) of the two test character indices equals the test character
     bool charATestSuccessful = passwordValue.at(charAToTestIdx-1) == passwordTestChar;
     bool charBTestSuccessful = passwordValue.at(charBToTestIdx-1) == passwordTestChar;
     
     return  charATestSuccessful ^ charBTestSuccessful;
}