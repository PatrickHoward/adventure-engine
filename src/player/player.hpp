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

#include "../rooms/rooms.hpp"

class Player
{
public:
    Player()
    {
        playerRoom = nullptr;
    }

    Player(Room* startingRoom)
        : playerRoom(startingRoom)
    {

    }

    std::string attemptTravel(Direction movementTowards)
    {
        if(playerRoom->hasEdge(movementTowards))
        {
            if(playerRoom->edgeEnabled(movementTowards))
            {
                movePlayer(playerRoom->getRoom(movementTowards));
                return "OK";
            }

            return "Its locked.";

        }

        return "I can't go that way.";

    }

    std::string whereAmI()
    {
        return playerRoom->roomName;
    }

    std::string lookAround()
    {
        return playerRoom->roomDesc;
    }

private:
    void movePlayer(Room* destination)
    {
        playerRoom = destination;
    }

    Room* playerRoom;    
};