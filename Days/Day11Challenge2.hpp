#pragma once
#include <vector>

class Day11Challenge2
{
public:
    Day11Challenge2();
    ~Day11Challenge2();
    void Execute();


private:
    enum Cell
    {
        Floor,
        Seat_Empty,
        Seat_Occupied
    }; 

    typedef std::vector<std::vector<Cell>> ChairLayout;

    int32_t ProcessLayout();
    int32_t AdjecentSeatsOccupiedCount(int32_t row, int32_t col, int32_t rowCount, int32_t colsCount);
    
    ChairLayout m_chairLayout;
};