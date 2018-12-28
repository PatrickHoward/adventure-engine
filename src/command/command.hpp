/*
   This file is part of adventure-engine.    

    adventure-engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 
*/ 

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <set>


struct Command
{
    Command()
        : valid(false)
    {
        
    }
    
    std::string name;
    bool valid;
    std::vector<std::string> arguments;
};



class LegalCommands
{
public:
    LegalCommands(std::set<std::string> legalCommands_)
        :legalCommands(legalCommands_)
    {
        
    }
    
    bool isLegal(std::string commandWord)
    {
        if(legalCommands.find(commandWord))
        {
            return true;
        }
        
        return false;
    }

private:
    std::set<std::string> legalCommands;

};

class CommandParser
{
public:
    CommandParser()
    {
        
    }
    
    void getInput(std::string userInput)
    {
        inputLine.str(userInput);
        std::string word;
        while(std::getline(getLine, word, ' '))
        {
            splitInputLine.push_back(word);
        }  
    }

    Command getCommand()
    {
        
    }

private:
    std::istringstream inputLine;
    std::vector<std::string> splitInputLine;
};

