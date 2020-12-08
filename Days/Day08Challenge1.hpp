#pragma once

#include <string>

struct CommandData{
    std::string cmd;
    int arg;
    bool used;
};

class Day08Challenge1
{
public:
    Day08Challenge1();
    ~Day08Challenge1() ;
    void Execute();
   
};