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

#include "game.hpp"
#include "rooms/rooms.hpp"
#include "player/player.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Adventure Engine is free software licensed under the GNU general public license version 3.\n";

    cout << "-- The Dungeon --\n";

    //Testing using a basic game without the dungeon builder.
    GameContext setup;

    Room roomA("The first room", "This is the first room.");
    Room roomB("The second room", "This is the second room, the first room is south\n and the third room is north.");
    Room roomC("The third room", "This is the third room, you can only go south to \nthe second room.");
    Room roomD("The fourth room", "This room cannot be accessed");

    std::vector<Room> dungeon;
    dungeon.push_back(roomA);
    dungeon.push_back(roomB);
    dungeon.push_back(roomC);
    dungeon.push_back(roomD);

    dungeon[0].addEdge(NORTH, &dungeon[1], true);
    dungeon[1].addEdge(SOUTH, &dungeon[0], true);
    dungeon[1].addEdge(NORTH, &dungeon[2], true);
    dungeon[2].addEdge(SOUTH, &dungeon[1], true);
    dungeon[1].addEdge(NORTHEAST, &dungeon[3], false);

    Player newPlayer(&dungeon[0]);

    vector<string> validCommands = {"go", "look", "where", "quit"};

    setup.dungeon = dungeon;
    setup.mainPlayer = newPlayer;
    setup.validCommands = validCommands;

    Game activeGame(setup);
    activeGame.playGame();

}

