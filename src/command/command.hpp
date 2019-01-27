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
#include <queue>
#include <algorithm>

using ArgumentList = std::vector<std::string>;

struct Command
{
    Command()
        : valid(false)
    {
        
    }
    
    Command(std::string& name_)
        : name(name_)
    {
        
    }
    
    Command(std::string& name_, ArgumentList& arguments_)
        : name(name_),
        arguments(arguments_),
        valid(false)
    {
        
    }
    
    std::string name;
    ArgumentList arguments;
    
    bool valid;
};

class CommandParser
{
public:
    CommandParser(std::vector<std::string> validCommands_)
        : validCommands(validCommands_)
    {
        
    }

    Command parse(std::string inputLine);

private:
    Command makeCommand(std::string inputLine);

    void validateCommand(Command checkThis);

    const std::vector<std::string> validCommands;
};

class CommandRunner
{
public:
    CommandRunner(std::vector<std::string> validCommands)
        : parser(validCommands)
    {

    }

    void processInput(std::string& inputLine);

    Command returnActiveCommand();

private:

    CommandParser parser;
    Command activeCommand;
};
