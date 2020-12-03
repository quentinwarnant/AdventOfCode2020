
#include "Days/Day01Challenge1.hpp"
#include "Days/Day01Challenge2.hpp"
#include "Days/Day02Challenge1.hpp"
#include "Days/Day02Challenge2.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <tuple>
#include <array>


int main()
{
    //Day 1
    //Challenge 1
    // auto day01Chal01 = std::make_unique<Day01Challenge1>();
    // day01Chal01->Execute();

    //Challenge 2
    // auto day01Chal02 = std::make_unique<Day01Challenge2>();
    // day01Chal02->Execute();

    //Day 2
    //Challenge 1
    //auto day02Chal01 = std::make_unique<Day02Challenge1>();
    //day02Chal01->Execute();
    
    //Challenge 2
    auto day02Chal02 = std::make_unique<Day02Challenge2>();
    day02Chal02->Execute();


    return 0; // result unused?

}