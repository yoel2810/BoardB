#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"

using ariel::Direction;
using namespace std;

namespace ariel
{
    class Board
    {
        private:
            void resize(bool cols, unsigned int numb);
        
        public:
            vector<vector<char>> board; // the board

            unsigned int getRows() { return this->board.size(); }
            unsigned int getCols() { return this->board[0].size(); }
            
            Board(/*unsigned int r = 500, unsigned int c = 500*/);

            void post (unsigned int r, unsigned int c, Direction direction, std::string po);

            std::string read (unsigned int row, unsigned int column, Direction dr, unsigned int length);

            void show ();
    };
};