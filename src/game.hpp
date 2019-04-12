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
#include <vector>
#include <string>

#include "actions/actions.hpp"
#include "command/command.hpp"
#include "rooms/rooms.hpp"
#include "player/player.hpp"

struct GameContext
{
    std::vector<std::string> validCommands;
    std::vector<Room> dungeon;

    Player mainPlayer;
};

class Game
{
public:
    Game(GameContext context)
        : commandRunner(context.validCommands),
        active(true)
    {
        dungeon = context.dungeon;
        mainPlayer = context.mainPlayer;
        actionManager.setPlayer(&mainPlayer);
    }

    void playGame()
    {

        while(active)
        {
            if(mainPlayer.getRoom()->visited == false)
            {
                std::cout << "====== " << mainPlayer.whereAmI() << " ======" << '\n';
                std::cout << mainPlayer.lookAround() << '\n';

                mainPlayer.getRoom()->visited = true;
            }
            else
            {
                std::cout << "====== " << mainPlayer.whereAmI() << " ======" << '\n';

            }
        
            std::string input;
            std::cout << "> ";
            std::getline(std::cin, input);

            commandRunner.processInput(input);
            std::string eventOutput;
            eventOutput = actionManager.processUserAction(commandRunner.returnActiveCommand());

            std::cout << eventOutput << "\n";            
            std::cout << '\n';

            if(commandRunner.returnActiveCommand().name == "quit")
            {
                active = false;
            }
        }
    }

    
private:

    ActionManager actionManager;
    CommandRunner commandRunner;
    std::vector<Room> dungeon;
    Player mainPlayer;
    
    bool active;
};

