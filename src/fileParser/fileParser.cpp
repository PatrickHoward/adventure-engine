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

#include "fileParser.hpp"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

File::FileParser::FileParser(std::string fileName)
{
  fileStream.open(fileName, std::fstream::in);
  
  std::getline(fileStream, currentLine);
}

void File::FileParser::checkLine()
{
  if(currentLine.substr(0, 2) == "--")
  {
    workingTag = currentLine.substr(1,currentLine.length()-1);
  }
  
}

void File::FileParser::nextLine()
{
    getline(fileStream, currentLine); 
}


