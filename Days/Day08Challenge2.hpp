#pragma once
#include <string>

class CommandData{
public:
    std::string cmd;
    int arg;
    bool used;
};
class Day08Challenge2
{
public:
    Day08Challenge2();
    ~Day08Challenge2() ;
    void Execute();
    
   
};