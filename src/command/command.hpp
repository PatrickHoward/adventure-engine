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

#include <string>
#include <iostream>
#include <vector>

using argumentList = std::vector<std::string>;

struct Command
{
    Command()
        : valid(false)
    {
        
    }
    
    Command(std::string name_)
        : name(name_)
    {
        
    }
    
    Command(std::string name_, argumentList arguments_)
        : name(name_),
        arguments(arguments_),
        valid(false)
    {
        
    }
    
    std::string name;
    argumentList arguments;
    
    bool valid;
};

class CommandParser
{
public:
    CommandParser()
    {
        
        
    }
    
    Command makeCommand(std::string inputLine)
    {
        Command newCommand;
        
        std::size_t spaceCharPos = inputLine.find(' ');
        
        newCommand.name = inputLine.substr(0, spaceCharPos);
        inputLine.erase(0, spaceCharPos + 1);
        
        while(!inputLine.empty())
        {
            spaceCharPos = inputLine.find(' ');
            
            if(spaceCharPos != std::string::npos)
            {
                newCommand.arguments.push_back(inputLine.substr(0, spaceCharPos));
                inputLine.erase(0, spaceCharPos + 1);   
            }
            else
            {
                newCommand.arguments.push_back(inputLine.substr(0, inputLine.length()));
                inputLine.erase(0, inputLine.length());
            }
            
            
        }
        
        return newCommand;
    }
    
private:
    
};
