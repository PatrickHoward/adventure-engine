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

#include <string>
#include <vector>

#include "command.hpp"

Command CommandParser::parse(std::string inputLine)
{
    Command newcmd = makeCommand(inputLine);
    validateCommand(newcmd);
    return newcmd;
}

Command CommandParser::makeCommand(std::string inputLine)
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

    std::transform(newCommand.name.begin(), newCommand.name.end(), newCommand.name.begin(), ::tolower);

    for(int i = 0; i < (int)newCommand.arguments.size(); ++i)
    {
        std::transform(newCommand.arguments[i].begin(), newCommand.arguments[i].end(), newCommand.arguments[i].begin(), ::tolower);
    }
    
    return newCommand;
}

void CommandParser::validateCommand(Command checkThis)
{
    for(int i = 0; i < (int)validCommands.size(); ++i)
    {
        if(validCommands[i] == checkThis.name)
        {
            checkThis.valid = true;
            return;
        }
    }
}

void CommandRunner::processInput(std::string& inputLine)
{
    Command newCommand;
    newCommand = parser.parse(inputLine);
    activeCommand = newCommand;
}

Command CommandRunner::returnActiveCommand()
{
    return activeCommand;   
}
