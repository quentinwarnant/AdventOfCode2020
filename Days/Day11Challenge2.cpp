
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <cmath>

#include "Day11Challenge2.hpp"


Day11Challenge2::Day11Challenge2() 
{
}

Day11Challenge2::~Day11Challenge2() 
{
}

void Day11Challenge2::Execute() 
{
     std::cout << "Day11 Challenge 1 Execute !" << std::endl;

     std::ifstream file("Data/Day11.txt");
     int row = 0;
     std::string line;
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();
          m_chairLayout.push_back(std::vector<Cell>());

          for(int i = 0; i < strLine.length(); i++){
               char cellChar =  strLine.at(i);
               Cell c = cellChar == '.' ? Cell::Floor : (cellChar == 'L' ? Cell::Seat_Empty : Cell::Seat_Occupied);
               m_chairLayout[row].push_back(c);
          }

          row++;
     }

     int32_t iterations = 0;
     while( ProcessLayout() > 0 ){
          iterations++;
     }

     //Count occupied seats
     unsigned int occupiedSeats = 0;
     for (auto &&col : m_chairLayout){
          for (auto &&chair : col){
               if( chair == Cell::Seat_Occupied){
                    occupiedSeats++;
               }
          }
          
     }
     

     std::cout << "itterations: " << iterations << ", occupied seats: " << occupiedSeats << std::endl;
}

int32_t Day11Challenge2::ProcessLayout() 
{
     int32_t amountOfChairChanges = 0;
     int32_t rowCount = m_chairLayout.size(); 
     int32_t colsCount = m_chairLayout[0].size();

     //don't edit the original layout until we've completely processed the data in a separate layout
     ChairLayout newLayout = m_chairLayout;
     for(int32_t row = 0; row < rowCount; row++){
          for(int32_t col = 0; col < colsCount; col++){
               if(m_chairLayout[row][col] == Cell::Floor){
                    continue;
               }

               if(m_chairLayout[row][col] == Cell::Seat_Empty){
                    if( AdjecentSeatsOccupiedCount(row,col, rowCount, colsCount) == 0){
                         newLayout[row][col] = Cell::Seat_Occupied;
                         amountOfChairChanges++;
                    }
                    continue;
               }

               if(m_chairLayout[row][col] == Cell::Seat_Occupied){
                    if( AdjecentSeatsOccupiedCount(row,col, rowCount, colsCount) >= 5){
                         newLayout[row][col] = Cell::Seat_Empty;
                         amountOfChairChanges++;
                    }
               }

          }
     }

     //override the cached layout with the newly processed layout
     m_chairLayout = newLayout;

     return amountOfChairChanges;
}

int32_t Day11Challenge2::AdjecentSeatsOccupiedCount(int32_t row, int32_t col, int32_t rowCount, int32_t colsCount) {
    
     int32_t count = 0;
    
     //8 directions: UL,U,UP,L,R,DL,D,DR
     auto directionModifiers = std::vector<std::pair<int,int>>{
          std::make_pair<int,int>(-1,1),
          std::make_pair<int,int>(0,1),
          std::make_pair<int,int>(1,1),
          std::make_pair<int,int>(-1,0),
          std::make_pair<int,int>(1,0),
          std::make_pair<int,int>(-1,-1),
          std::make_pair<int,int>(0,-1),
          std::make_pair<int,int>(1,-1)
     };


     for (auto &&dirMod : directionModifiers){
          for(int offsetAmount = 1; ; offsetAmount++){
               int offsetCoordRow = row + (dirMod.first * offsetAmount);
               int offsetCoordCol = col + (dirMod.second * offsetAmount);

               //If we're out of the allowed coordinates, we stop this direction
               if( offsetCoordRow <0){ break;}
               if( offsetCoordRow >= rowCount){break;}
               if( offsetCoordCol <0){ break;}
               if( offsetCoordCol >= colsCount){break;}

               //If we find a valid cell...

               //...and it's occupied, increase the counter and break out of this direction loop
               if(m_chairLayout[offsetCoordRow][offsetCoordCol] == Cell::Seat_Occupied){
                    count++;
                    break;
               }
               
               //... or a free seat cell, we stop looking in this dir
               if(m_chairLayout[offsetCoordRow][offsetCoordCol] == Cell::Seat_Empty){
                    break;
               }

               //... otherwise this is a floor cell , which we look further ignore
    
          }
     }

     return count;
}
