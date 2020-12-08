
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <utility>
#include <cmath>

#include "Day08Challenge2.hpp"

Day08Challenge2::Day08Challenge2() 
{
}

Day08Challenge2::~Day08Challenge2() 
{
}

void Day08Challenge2::Execute() 
{
     std::cout << "Day08 Challenge 2 Execute !" << std::endl;

     std::ifstream file("Data/Day8.txt");
     std::string line;
     
     auto commandList = std::vector<CommandData>();
     while (std::getline(file, line))
     {
          std::istringstream iss(line);
          std::string strLine = iss.str();

          std::string command = strLine.substr(0,3);
          int arg = std::stoi( strLine.substr(4,strLine.length()-4) );

          auto commandData = CommandData{ command, arg, false};
          commandList.push_back(commandData);
     }

     

     //Start program at first command
     int accumulator = 0;
     auto currentCommandIt = commandList.begin();

     std::string commandNameCurrentlyBeingSwapped = "jmp";
     auto FindCommandByName = [commandNameCurrentlyBeingSwapped](CommandData const command ){
          return command.cmd == commandNameCurrentlyBeingSwapped;
     };
     auto commandFixIt = std::find_if(
          commandList.begin(),
          commandList.end(),
          FindCommandByName);
     (*commandFixIt).cmd = "nop"; //Swap command of first instance of jmp to a nop
                    

     do{
          (*currentCommandIt).used = true;

          if((*currentCommandIt).cmd == "jmp"){
               currentCommandIt+=(*currentCommandIt).arg;
          }else if((*currentCommandIt).cmd == "nop"){
               currentCommandIt++;
          }else if((*currentCommandIt).cmd == "acc"){
               accumulator+=(*currentCommandIt).arg;
               currentCommandIt++;
          }

          if( (*currentCommandIt).used ){
               //We've hit an infinite loop, therefore we must re-start the program from the first command...
               currentCommandIt = commandList.begin();
               accumulator = 0; //restart accumulator from 0

               //Reset the used flags
               for (auto &&it : commandList)
               {
                    it.used = false;
               }
               

               //... and make a change to one of the commands
               if(commandNameCurrentlyBeingSwapped == "jmp"){
                    //Restore command to what it used to be
                    (*commandFixIt).cmd = "jmp";
                    //find next occurance
                    commandFixIt = std::find_if(
                                        commandFixIt+1,
                                        commandList.end(),
                                        FindCommandByName);

                    //if we've reached the last of jump commands, let's try by swapping the nop commands
                    if( commandFixIt == commandList.end()){
                         commandNameCurrentlyBeingSwapped = "nop";
                         commandFixIt = std::find_if(
                                        commandList.begin(),
                                        commandList.end(),
                                        FindCommandByName);

                         (*commandFixIt).cmd = "jmp";
                    }else{
                         //Swap command for new program cycle
                         (*commandFixIt).cmd = "nop";
                    }
                    
               }else if(commandNameCurrentlyBeingSwapped == "nop"){
                    //Restore command to what it used to be
                    (*commandFixIt).cmd = "nop";
                    
                    
                    //find next occurance
                    commandFixIt = std::find_if(
                                        commandFixIt+1,
                                        commandList.end(),
                                        FindCommandByName);

                    //if we've reached the last of the nop commands, there were no valid swaps possible, terminate program
                    if( commandFixIt == commandList.end()){
                         break;
                    }else{
                         (*commandFixIt).cmd = "jmp";
                    }
               }
          }

     }while( currentCommandIt < commandList.end() );

     std::cout << accumulator << std::endl;
}
