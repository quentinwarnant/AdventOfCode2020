
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <vector>
#include <unordered_map>

#include <utility>
#include <cmath>

#include "Day07Challenge2.hpp"

Day07Challenge2::Day07Challenge2() 
{
}

Day07Challenge2::~Day07Challenge2() 
{
}

void Day07Challenge2::Execute() 
{
     std::cout << "Day07 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day7.txt");
     std::string line;
     
     //a map of string-set<string> pairs where the key indicate a bag type and the value indicates which bag types the "key"-type can be contained in
     std::unordered_map<std::string,std::vector<ContainedBagData>> bagRules;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine;
          
          strLine = iss.str();
          int containerBagColorEndIdx = strLine.find(" bags");
          std::string containerBagColor = strLine.substr(0,containerBagColorEndIdx);

          //+14 for " bags contain " after " bags", string length
          std::string containedBagListStr = strLine.substr(containerBagColorEndIdx+14, 
                                        //+15 as each line ends with a full stop which we want to dismiss
                                        strLine.length() - containerBagColorEndIdx+15);
          //Eg: 4 mirrored fuchsia bags, 4 dotted indigo bags, 3 faded orange bags, 5 plaid crimson bags.
          auto containedBagListIt = containedBagListStr.begin();
          auto currentBagIt = containedBagListIt;
          auto containedBagsList = std::vector<ContainedBagData>(); 

          auto ParseLine = [&currentBagIt,&containedBagsList](std::string::iterator currentPosIt){
               
               auto endStringCheck = std::string( currentBagIt, currentPosIt);
               if(endStringCheck == "no other bags"){
                    return;
               }
               //get a substring of the list from the start of the current bag index to the current iterator pos - ! (to ignore the comma)
               int bagCount = (int)(*currentBagIt) - '0';
               //if bag count is 1 there's no 's' at the end of "bags" in the sentence
               //'4 mirrored fuchsia bags', we want to ignore the trailing word ' bag(s)'
               int bagsWordLength = bagCount == 1 ? 3 : 4;
               //+2 to ignore the quantity of bags
               auto bagType = std::string( currentBagIt+2, currentPosIt-1-(bagsWordLength));
               ContainedBagData containedBagData = {};
               containedBagData.BagType = bagType;
               containedBagData.Count = bagCount;
               containedBagsList.push_back( containedBagData);

               //move the current bag iterator to the current +2 position to start recording the next bag type (", ")
               currentBagIt = currentPosIt+2;
          };

          while( *containedBagListIt != '.' ){
               if(*containedBagListIt == ','){
                    ParseLine(containedBagListIt);
               }
               containedBagListIt++;
          }
          //Add the final bag too
          ParseLine(containedBagListStr.end()-1 );

          bagRules.insert({containerBagColor,containedBagsList});


          std::cout << "" << std::endl;
     }

     //Now we have the bag rules, we need to look which types of bags can contain the specific bag type,
     //or contain bags that can do it themselves.
     const std::string specialType = "shiny gold";
     
     //lambda to call recursively where needed
     std::function<int (std::string)>  FindBagTypesPairContainedInBagType = [&](std::string bagType){
          auto ruleForBagTypeIt = bagRules.find(bagType);
          int count = 1;
          if( ruleForBagTypeIt != bagRules.end() ){

               auto validContainedBagTypesPairs = (*ruleForBagTypeIt).second;

               for (auto &&validContainedBagTypePairs : validContainedBagTypesPairs)
               {
                    //Call function recursively
                    count+=validContainedBagTypePairs.Count * FindBagTypesPairContainedInBagType(validContainedBagTypePairs.BagType);
               }
          }
          return count;
     };

     int totalBagCount = FindBagTypesPairContainedInBagType(specialType) -1;
     
     std::cout << totalBagCount << std::endl;
}
