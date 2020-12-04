
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "Day04Challenge2.hpp"

Day04Challenge2::Day04Challenge2() 
{
}

Day04Challenge2::~Day04Challenge2() 
{
}

void Day04Challenge2::Execute() 
{
     std::cout << "Day04 Challenge 2 Execute !" << std::endl;

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

bool Day04Challenge2::ValidatePassport(PersonData data) 
{
     //check all fields are "valid" (see rules) (except for "cid" which is optional)
     bool valid = true;
     
     //byr (Birth Year) - four digits; at least 1920 and at most 2002. 
     bool byrValid = data.byr != "";
     if(!byrValid) return false;
     byrValid &= data.byr.length() == 4;
     int byrYear = std::stoi(data.byr);
     byrValid &= (byrYear >= 1920 && byrYear <= 2002);
     valid &= byrValid;
     if( !valid){return false;} //early exit 

     //iyr (Issue Year) - four digits; at least 2010 and at most 2020.
     bool iyrValid = data.iyr != "";
     if(!iyrValid) return false;
     iyrValid &= data.iyr.length() == 4;
     int iyrYear = std::stoi(data.iyr);
     iyrValid &= (iyrYear >= 2010 && iyrYear <= 2020);
     valid &= iyrValid;
     if( !valid){return false;} //early exit 

     //eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
     bool eyrValid = data.eyr != "";
     if(!eyrValid) return false;
     eyrValid &= data.eyr.length() == 4;
     int eyrYear = std::stoi(data.eyr);
     eyrValid &= (eyrYear >= 2020 && eyrYear <= 2030);
     valid &= eyrValid;
     if( !valid){return false;} //early exit 

     //hgt (Height) - a number followed by either cm or in:
          //If cm, the number must be at least 150 and at most 193.
          //If in, the number must be at least 59 and at most 76.
     //last two chars should not be digits
     bool hgtValid = data.hgt != "";
     if(!hgtValid) return false;
     std::string hgtMeasure = data.hgt.substr(data.hgt.size()-2,2);
     hgtValid &= std::isalpha( hgtMeasure.at(0) ) && std::isalpha( hgtMeasure.at(1) );
     if( hgtValid ){

          std::string hgtValueStr = data.hgt.substr(0,data.hgt.size()-2);
          int hgtValue = std::stoi(hgtValueStr);
          if(hgtMeasure == "in"){
               hgtValid &= (hgtValue >= 59 && hgtValue <= 76); 
          }else if(hgtMeasure == "cm"){
               hgtValid &= (hgtValue >= 150 && hgtValue <= 193); 
          }
     }
     valid &= hgtValid;
     if( !valid){return false;} //early exit 

     //hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
     bool hclValid = data.hcl != "" && data.hcl.length() == 7 && data.hcl.at(0) == '#';
     if(!hclValid) return false;
     std::string hclValue = data.hcl.substr(1,data.hcl.length()-1);
     for (size_t i = 0; i < 6; i++)
     {
          hclValid &= std::isalnum(hclValue.at(i));
     }
     valid &= hclValid;
     if( !valid){return false;} //early exit 

     //ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
     bool eclValid = data.ecl != "";
     eclValid &=     data.ecl == "amb" || 
                         data.ecl == "blu" || 
                         data.ecl == "brn" || 
                         data.ecl == "gry" || 
                         data.ecl == "grn" || 
                         data.ecl == "hzl" || 
                         data.ecl == "oth" ;
     valid &= eclValid;
     if( !valid){return false;} //early exit 


     //pid (Passport ID) - a nine-digit number, including leading zeroes.
     bool pidValid = data.pid != "";
     if( !pidValid) return false;
     pidValid &= data.pid.length() == 9;
     std::string pidValue = data.pid;
     for (auto &&pidChar : pidValue)
     {
          pidValid &= std::isdigit(pidChar);
     }
     valid &= pidValid;

     return valid;
}

PassportPairDataList Day04Challenge2::ParseLine(std::string dataStr) 
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
