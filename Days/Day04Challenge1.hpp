#pragma once

#include <string>

struct PersonData{
    std::string ecl; //eye colour
    std::string byr; //birth year
    std::string iyr; //Issue Year
    std::string eyr; //Expiration year
    std::string hgt; //Height
    std::string hcl; //Hair Color
    std::string pid; //Passport ID
    std::string cid; //Country ID

    void Reset(){
        ecl = byr = iyr = eyr = hgt = hcl = ecl = pid = cid = "";
    }
};

typedef std::vector<std::pair<std::string,std::string>> PassportPairDataList;

class Day04Challenge1
{
public:
    Day04Challenge1();
    ~Day04Challenge1() ;
    void Execute();
    bool ValidatePassport(PersonData data);

    PassportPairDataList ParseLine(std::string dataStr);

};