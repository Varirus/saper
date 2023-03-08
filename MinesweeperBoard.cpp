#include <iostream>
#include "MinesweeperBoard.h"

using std::cout;

MinesweeperBoard::MinesweeperBoard(int h, int w, int bombs)
{
    height = h;
    width = w;
    amountOfBombs = bombs;

    initialize_board();
    test_3_fields();
}

void MinesweeperBoard::initialize_board(){
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].hasFlag = false;
            board[i][j].hasMine = false;
            board[i][j].isRevealed = false;
        }
    }
}

void MinesweeperBoard::test_3_fields(){
    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasFlag = true;
    board[0][2].hasMine = true;
}

void MinesweeperBoard::debug_display() const{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[";
            if(board[i][j].hasMine)
                cout << "M";
            else
                cout << ".";
            if (board[i][j].isRevealed)
                cout << "o";
            else
                cout << ".";
            if (board[i][j].hasFlag)
                cout << "f";
            else
                cout << ".";
            cout << "]";
        }
        std::endl(cout);
    }
}