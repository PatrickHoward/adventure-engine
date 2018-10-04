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

#ifndef ROOM
#define ROOM

#include<string>

class Room
{
    std::string roomName;
    std::string roomDesc;
    
    //Items itemsInRoom[5]; //Array of items that exist in a single room.
    //Creatures creaturesAlive[5]; //Array of creatures alive in a single room.

    //Room* exits[4]; //Array of room pointers that point to the repective rooms.
  public:
    
    Room();
    Room(int, int, std::string, std::string);

    
};

#endif
