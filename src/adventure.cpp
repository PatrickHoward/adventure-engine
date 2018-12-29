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

#include "command/command.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Adventure Engine is free software licensed under the GNU general public license version    3.\n";

    CommandParser commandSystemParser;

    Command outputCommand;

    string userInput;
    cout << "Please input a command -> ";
    getline(cin, userInput);

    commandSystemParser.parseInput(userInput);
    outputCommand = commandSystemParser.makeCommand();

    cout << outputCommand.name << "\n";
    int argCount = outputCommand.arguments.size();

    for(int i = 0; i < argCount; ++i)
    {   
        cout << outputCommand.arguments[i] << ' ';
    }

    cout << '\n';
    
}

