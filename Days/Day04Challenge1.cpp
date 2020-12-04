
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day04Challenge1.hpp"

Day04Challenge1::Day04Challenge1() 
{
}

Day04Challenge1::~Day04Challenge1() 
{
}

void Day04Challenge1::Execute() 
{
     std::cout << "Day04 Challenge 1 Execute !" << std::endl;

     auto passportData = std::vector<PersonData>();
     std::ifstream file("Data/Day4.txt");
     std::string line;
     
     PersonData currentPerson;
     currentPerson.Reset();
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          //read line to 3 strings, eg of line: "15-19 k: kkkkkkkkkkkkzkkkkkkk"
          strLine = iss.str();

          if(strLine.length() == 0){ //empty line means next person data
               passportData.push_back(currentPerson);
               //reset currentPerson;
               currentPerson.Reset();
               continue;
          }

          auto dataPairList = ParseLine(strLine);
          //Assign property pairs to currentPerson Data
          for (auto &&dataPair : dataPairList)
          {
               if( dataPair.first == "ecl"){
                    currentPerson.ecl = dataPair.second;
               }else if( dataPair.first == "pid"){
                    currentPerson.pid = dataPair.second;
               }else if( dataPair.first == "eyr"){
                    currentPerson.eyr = dataPair.second;
               }else if( dataPair.first == "hcl"){
                    currentPerson.hcl = dataPair.second;
               }else if( dataPair.first == "byr"){
                    currentPerson.byr = dataPair.second;
               }else if( dataPair.first == "iyr"){
                    currentPerson.iyr = dataPair.second;
               }else if( dataPair.first == "cid"){
                    currentPerson.cid = dataPair.second;
               }else if( dataPair.first == "hgt"){
                    currentPerson.hgt = dataPair.second;
               }
          }
     }

     //don't forget the last person, as the file may not end with a newline
     passportData.push_back(currentPerson);
     
     int validPasswordCount = 0;
     for (auto &&p : passportData)
     {
          if( ValidatePassport(p) ){
               validPasswordCount++;
          }
     }
     
     std::cout << validPasswordCount << std::endl;

}

bool Day04Challenge1::ValidatePassport(PersonData data) 
{
     //check all fields (except for "cid" which is optional for this challenge) are not null
     return data.byr != "" 
          //&& data.cid != "" //-- optional
          && data.ecl != "" 
          && data.eyr != "" 
          && data.hcl != "" 
          && data.hgt != "" 
          && data.iyr != "" 
          && data.pid != "" ;
}

PassportPairDataList Day04Challenge1::ParseLine(std::string dataStr) 
{
     PassportPairDataList data;
     auto ProcessPropertyStr = [&data](std::string propertyDataStr) 
     { 
          int kvpSeparatorIdx = propertyDataStr.find(':');
          auto dataPair = std::make_pair<std::string,std::string>(propertyDataStr.substr(0,kvpSeparatorIdx), 
                                                   propertyDataStr.substr(kvpSeparatorIdx+1,propertyDataStr.length() - (kvpSeparatorIdx+1)) );
          data.push_back(dataPair);
     };

     const char propertySeparator = ' ';
     while (auto separatorPos = dataStr.find(propertySeparator))
     {
          if( separatorPos != std::string::npos)
          {
               auto propertyDataStr = dataStr.substr(0,separatorPos);
               ProcessPropertyStr(propertyDataStr);
               //cut the property from the remainder of the string and continue to parse the line
               dataStr = dataStr.substr(separatorPos+1, dataStr.length() - (separatorPos+1));
          }else{
               //no more separator, still need to process the final entry of property on this line
               ProcessPropertyStr(dataStr);
               
               //before exiting
               break;
          }
     }

     return data;
}
