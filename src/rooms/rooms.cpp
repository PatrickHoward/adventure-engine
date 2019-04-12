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
#include "rooms.hpp"

Edge::Edge()
{
    enabled = false;
}

void Room::addEdge(Direction direction, Room* toRoom, bool enableEdge)
{
    edges[direction].destination = toRoom;
    edges[direction].enabled = enableEdge;

}

void Room::delEdge(Direction direction)
{
    edges[direction].destination = nullptr;
    edges[direction].enabled = false;

}

bool Room::hasEdge(Direction direction) const
{
    if(edges[direction].destination != nullptr)
    {
        return true;
    }
    return false;
}

bool Room::edgeEnabled(Direction movement)
{
    if(edges[movement].enabled)
    {
        return true;
    }

    return false;
}

Room* Room::getRoom(Direction direction)
{
    if(hasEdge(direction))
    {
        return edges[direction].destination;
    }

    return nullptr;

}