#pragma once

#include <string>

class Day02Challenge1
{
public:
    Day02Challenge1();
    ~Day02Challenge1() ;
    void Execute();
    bool CheckPasswordIsValid(char passwordTestChar, int charOccuranceMin, int charOccuranceMax, std::string passwordValue);

};