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

#include "../command/command.hpp"
#include "../player/player.hpp"

enum ActionTokens
{
    unprocessesed,
    go,
    look,
    where,
    take,
    use,
    quit
};

class ActionManager
{
public:
    ActionManager()
    {

    }

    ActionManager(Player* player_)
        : user(player_)
    {

    }

    void setPlayer(Player* player_)
    {
        user = player_;
    }

    std::string processUserAction(Command command);

private:
    std::string playerTravel(Command& command);
    std::string playerLookAround();
    std::string playerWhereAmI();

    std::string quitGame();

    Player* user;
    
};
