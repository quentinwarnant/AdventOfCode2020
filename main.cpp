
#include "Days/Day01Challenge1.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <tuple>
#include <array>


int main()
{
    auto bleh = std::string{"my name is Q"};
    //auto bleh{std::string{"my name is Q"}};
    //std::string bleh{"my name is Q"};
    std::cout << "hello world" << std::endl;

    bleh.append(" and I'm programming in c++ yay");
    std::cout << bleh << std::endl;

    auto day01Chal01 = std::make_unique<Day01Challenge1>();
    day01Chal01->Execute();

    //const char *cstringExample {"helllo from an old school cstring"};
    //const char cstringExample2[]{'h','e','y','\0'};
    //const std::array<char,4> modernArray = {'h','e','y','o'}; 
    //printf( "cstring: %s\n", cstringExample);

  //  std::cin >> end;

    return 0; // result unused?

}