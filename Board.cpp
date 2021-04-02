#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;
namespace ariel{

    Board::Board(){
        const unsigned int len = 5;
        //board = vector<vector<char>>();
        for (size_t i = 0; i < len; i++)
        {
            this->board.push_back(vector<char>());
            for (size_t j = 0; j < len; j++)
            {
                this->board[i].push_back('_');
            }
            
        }
    }


    void Board::post (unsigned int r, unsigned int c, Direction direction, std::string po){
        unsigned int rowNum = r+ po.length();
        unsigned int colNum = c + po.length();
        if(direction == Direction::Horizontal){
            rowNum = r;
        }
        else{
            colNum = c;
        }

        if (rowNum >= this->getRows())
        {
            //cout << "rowww : " << (rowNum - this->getRows()+1) << endl;
            resize(false, rowNum - this->getRows()+1);
        }
        if (colNum >= this->getCols())
        {
            //cout << "colll: " << (colNum - this->getCols() +1) <<endl;
            resize(true, colNum - this->getCols() + 1);
        }
        //this->show();
        if(direction == Direction::Horizontal)
        {
            
            for (unsigned int i = 0; i < po.length(); i++)
            {
                
                this->board[r][i + c] = po[i];
            }
        }
        else
        {
            for (unsigned int i = 0; i < po.length(); i++)
            {
                this->board[i + r][c] = po[i];
            }
        }
    }

    void Board::resize(bool cols, unsigned int num)
    {
        if(!cols)
        {
            for (size_t i = 0; i < num; i++)
            {
                this->board.push_back(vector<char>());
                for (size_t j = 0; j < this->board[0].size(); j++)
                {
                    this->board[this->board.size()-1].push_back('_');
                }
            
            }
        }
        else
        {
            for (size_t i = 0; i < this->board.size(); i++)
            {
                for (size_t j = 0; j < num; j++)
                {
                    this->board[i].push_back('_');
                }
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction dr, unsigned int length){
        string str = " ";
        str = "";
        unsigned long i = 0;
        if(dr==ariel::Direction::Horizontal){
            for(i=0;i<length && column+i < this->getCols();i++){
                str += board[row][column+i];
            }
        }
        if(dr==ariel::Direction::Vertical){
            for(i=0;i<length && row + i < this->getRows();i++){
                str += board[row+i][column];
            }
        }
        //cout << "i --------- " << i << endl;
        for (unsigned long k = i; k < length; k++)
        {
            str += '_';
        }
        //cout << "i ******** " << i << endl;
        return str;
    }

    void Board::show(){
        unsigned long i=0;
        unsigned long j = 0;
        for(i=0; i<this->board.size();i++){
            for(j=0;j<this->board[0].size();j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
        cout << endl;
    }
};