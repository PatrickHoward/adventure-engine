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

#include "actions.hpp"

using namespace std;

string ActionManager::processUserAction(Command command)
{
    string output;

    if(command.name == "go")
    {
        output = playerTravel(command);
    }
      else if(command.name == "look")
    {
        output = playerLookAround();
    }
    else if(command.name == "where")
    {
        output = playerWhereAmI();
    }
    else if(command.name == "quit")
    {
        output = quitGame();
    }

    return output;
}

string ActionManager::playerTravel(Command& command)
{
    if(command.arguments[0] == "north")
    {
        return user->attemptTravel(NORTH);
    }
    else if(command.arguments[0] == "south")
    {
        return user->attemptTravel(SOUTH);
    }
    else if(command.arguments[0] == "east")
    {
        return user->attemptTravel(EAST);
    }
    else if(command.arguments[0] == "west")
    {
        return user->attemptTravel(WEST);
    }
    else if(command.arguments[0] == "northwest")
    {
        return user->attemptTravel(NORTHWEST);
    }
    else if(command.arguments[0] == "northeast")
    {
        return user->attemptTravel(NORTHEAST);
    }
    else if(command.arguments[0] == "southwest")
    {
        return user->attemptTravel(SOUTHWEST);
    }
    else if(command.arguments[0] == "southeast")
    {
        return user->attemptTravel(SOUTHEAST);
    }
    else
    {
        return "I don't know how to go" + command.arguments[0];
    }
}

string ActionManager::playerLookAround()
{
    return user->lookAround();
}

string ActionManager::playerWhereAmI()
{
    return user->whereAmI();
}

string ActionManager::quitGame()
{
    return "Goodbye!";
}