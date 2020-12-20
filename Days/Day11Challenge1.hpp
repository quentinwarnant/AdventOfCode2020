#pragma once
#include <vector>

class Day11Challenge1
{
public:
    Day11Challenge1();
    ~Day11Challenge1();
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