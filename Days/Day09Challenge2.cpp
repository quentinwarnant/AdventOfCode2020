
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

#include <utility>
#include <cmath>

#include "Day09Challenge2.hpp"

typedef long long dataNumber;

Day09Challenge2::Day09Challenge2() 
{
}

Day09Challenge2::~Day09Challenge2() 
{
}

void Day09Challenge2::Execute() 
{
     std::cout << "Day09 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day9.txt");
     std::string line;
     auto dataList = std::vector<dataNumber>();
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();
          auto dataNum = std::stoll(strLine);
          dataList.push_back(dataNum);
     }

     const unsigned int dataSeriesLength = 25;
     auto bottomIt = dataList.begin();
     auto topIt = bottomIt + dataSeriesLength; 
     auto currentIt = topIt+1;
     auto currentValue = *currentIt;

     auto endIt =  dataList.end();

  
     while(currentIt != endIt){

          bool found = false;
          for (auto it = bottomIt; it < topIt; it++ )
          {
               for (auto it2 = it+1; it2 <= topIt; it2++ )
               {
                    if( *it+*it2 == currentValue){
                         found = true;
                         break;
                    }
               }

               if( found ){
                    break;
               }
          }
          

          if( !found){
               //didn't find a possible combination, exit
               break;
          }

          bottomIt++;
          topIt++; 
          currentIt++;
          currentValue = *currentIt;
          
     }

     dataNumber targetTotal = currentValue;

     //Now we must find a contiguous set of values that sum to the total of the currentValue
     //having them ordered will help  as we need to then add the smallest & largest numbers together to form the final answer
     auto contiguousNumbers = std::set<dataNumber>();
     auto contiguoutCurrentBottomIt = dataList.begin();
     int maxContiguousSeriesLength = dataList.size()-1;
     dataNumber contiguousTotal = 0;
     while(contiguoutCurrentBottomIt < dataList.end() ){
          contiguousNumbers.clear();
          contiguousTotal = *contiguoutCurrentBottomIt;
          contiguousNumbers.insert(*contiguoutCurrentBottomIt);

          for (int i = 0; i < maxContiguousSeriesLength; i++)
          {
               auto contiguousSeriesIt = contiguoutCurrentBottomIt+1+i;

               contiguousTotal+= *contiguousSeriesIt;
               contiguousNumbers.insert(*contiguousSeriesIt);

               if( contiguousTotal < targetTotal){
                    continue;
               }else if(contiguousTotal >= targetTotal){
                    break;
               }
          }

          if(contiguousTotal == targetTotal){
               break; // Found contiguous series, exit loop
          }else{
               contiguoutCurrentBottomIt++;
               maxContiguousSeriesLength--;
               continue;
          }
     }
     
     dataNumber finalAnswer = ( *contiguousNumbers.begin() ) + (*contiguousNumbers.rbegin());

     std::cout << finalAnswer << std::endl;
}
