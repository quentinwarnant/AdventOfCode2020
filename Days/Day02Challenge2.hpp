#pragma once

#include <string>

class Day02Challenge2
{
public:
    Day02Challenge2();
    ~Day02Challenge2() ;
    void Execute();
    bool CheckPasswordIsValid(char passwordTestChar, int charAToTestIdx, int charBToTestIdx, std::string passwordValue);

};