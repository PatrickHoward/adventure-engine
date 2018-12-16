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

enum Direction
{
    NORTH,
    NORTHEAST,
    EAST,
    SOUTHEAST,
    SOUTH,
    SOUTHWEST,
    WEST,
    NORTHWEST    
};

struct Edge;

class Room
{
public:
    Room(std::string roomName_, std::string roomDesc_)
        :roomName(roomName_),
        roomDesc(roomDesc_)
    {

    }

    Room(std::string roomName_, std::string roomDesc_, Room* edges_[])
        : roomName(roomName_),
        roomDesc(roomDesc_)
    {

    }

    void addEdge(Direction direction, Room* toRoom, bool enableEdge);

    void delEdge(Direction direction);

    bool hasEdge(Direction direction) const;

    Room* getRoom(Direction direction);

    std::string roomName;
    std::string roomDesc;

private:
    Edge edges[8];

};

struct Edge
{
    Edge();

    bool enabled;
    Room* destination;
};