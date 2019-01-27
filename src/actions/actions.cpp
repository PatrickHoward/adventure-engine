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

#include "actions.hpp"

bool ActionManager::processUserAction(Command command)
{
    bool commandSucceeded = false;

    if(command.name == "go")
    {
        commandSucceeded = playerTravel(command);
    }

    return commandSucceeded;
}

bool ActionManager::playerTravel(Command& command)
{
    if(command.arguments[0] == "north")
    {
        user->attemptTravel(NORTH);
    }
    else if(command.arguments[0] == "south")
    {
        user->attemptTravel(SOUTH);
    }
    else if(command.arguments[0] == "east")
    {
        user->attemptTravel(EAST);
    }
    else if(command.arguments[0] == "west")
    {
        user->attemptTravel(WEST);
    }
    else
    {
        return false; //No conition was satisfied, therefore, the command is invalid.
    }

    return true;
}
