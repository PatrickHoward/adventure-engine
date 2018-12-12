#include <iostream>
#include <string>

using namespace std;

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

class Room
{
public:

    struct Edge
    {
        Edge()
        {
            enabled = false;
        }

        bool enabled;
        Room* destination;
    };

    Room(string roomName_, string roomDesc_)
        :roomName(roomName_),
        roomDesc(roomDesc_)
    {

    }

    Room(string roomName_, string roomDesc_, Room* edges_[])
        : roomName(roomName_),
        roomDesc(roomDesc_)
    {

    }

    void addEdge(Direction direction, Room* toRoom, bool enableEdge)
    {
        edges[direction].destination = toRoom;
        edges[direction].enabled = enableEdge;

    }

    void delEdge(Direction direction)
    {
        edges[direction].destination = nullptr;
        edges[direction].enabled = false;

    }

    bool hasEdge(Direction direction)
    {
        if(edges[direction].destination != nullptr)
        {
            return true;
        }

        return false;
    }

    Edge getEdge(Direction direction)
    {
        return edges[direction];
    }

    string roomName;
    string roomDesc;

private:

    Edge edges[8];
};

struct Person
{
    Person()
    {

    }

    Person(Room* currentRoom_)
        : currentRoom(currentRoom_)
    {

    }

    void placePerson(Room* moveRoom)
    {
        currentRoom = moveRoom;
    }

    void movePerson(Direction direction)
    {
        if(currentRoom->hasEdge(direction))
        {
            Room::Edge newLoc = currentRoom->getEdge(direction);
            if(newLoc.enabled == true)
            {
                currentRoom = newLoc.destination;   
            }        

            return;
        }
    }

    void lookAround()
    {
        cout << currentRoom->roomName << '\n';
        cout << currentRoom->roomDesc << '\n';

    }

    Room* currentRoom;
};

class Dungeon
{
public:

private:

Person player;

}defaultDungeon;

int main()
{

    Room room1("First Room", "This is the first room.");
    Room room2("Second Room", "This is the second room.");
    Room room3("To the right of first room", "This is the third room");

    Person guy(&room1);
    guy.lookAround();

    room1.addEdge(NORTH, &room2, true);
    room1.addEdge(EAST, &room3, true);

    room2.addEdge(SOUTH, &room1, true);

    room3.addEdge(WEST, &room1, true);
    
    guy.movePerson(NORTH);
    guy.lookAround();

    guy.movePerson(SOUTH);
    guy.lookAround();

    guy.movePerson(EAST);
    guy.lookAround();   

}