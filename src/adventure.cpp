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

#include <iostream>
#include <string>

#include "rooms/rooms.hpp"
#include "player/player.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Adventure Engine is free software licensed under the GNU general public license version    3.\n";
    
    
    //Simply testing the functionality of the rooms and moving a "player" from room to room.
    Room room1("This is a new room", "Blerg");
    Room room2("This is another room", "Bleerg");
    Room room3("This is a third room", "Bleeerg");

    room1.addEdge(NORTH, &room2, true);
    room1.addEdge(SOUTH, &room3, true);

    room2.addEdge(NORTH, &room3, false);

    room3.addEdge(SOUTH, &room2, true);

    Player mainPlayer(&room1);

    cout << mainPlayer.whereAmI() << '\n';
    cout << mainPlayer.attemptTravel(SOUTH) << '\n';
    cout << mainPlayer.attemptTravel(SOUTH) << '\n';
    cout << mainPlayer.attemptTravel(NORTH) << '\n';

}

