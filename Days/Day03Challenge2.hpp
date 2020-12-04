#pragma once

#include <string>

class Day03Challenge2
{
public:
    Day03Challenge2();
    ~Day03Challenge2() ;
    void Execute();

    template <size_t rows, size_t cols>
    int CountTrees(bool (&map)[rows][cols], int patternX, int patternY );

};

template<size_t rows, size_t cols>
int Day03Challenge2::CountTrees(bool (&map)[rows][cols], int patternX, int patternY) 
{
     //Traverse map with pattern (eg: 3 Right, 1 down) starting from 0,0 , wrapping when going too far to the right
     int treeCounts = 0;
     int x = 0;
     int y = 0;
     do{
          x += patternX;
          y += patternY;
          //Wrap X
          x = x%cols;

          if(map[y][x] == false){ // Tree found
               treeCounts++;
          }

     }while(y < rows-1);

     return treeCounts;
}