#include <iostream>
#include <cmath>
#include <ctime>
#include <string.h>
#include "MinesweeperBoard.h"

using std::cout;

int MinesweeperBoard::getWidth() const { return width; }
int MinesweeperBoard::getHeight() const { return height; }
int MinesweeperBoard::getMineCount() const { return mineCount; }
GameState MinesweeperBoard::getGameState() const { return state; }
GameMode MinesweeperBoard::getGameMode() const { return mode; }

MinesweeperBoard::MinesweeperBoard(int h, int w, GameMode m)
    : height(h), width(w), mode(m)
{
    resetBoard();
}

void MinesweeperBoard::initialize_board()
{
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

void MinesweeperBoard::setMines()
{
    if (mode == DEBUG)
    {
        // Caly wiersz 1 ma miny
        for (int i = 0; i < width; i++)
        {
            board[0][i].hasMine = true;
        }
        mineCount = width;
        return;
    }
    if (mode == EASY)
        mineCount = std::ceil(0.1 * (width * height));

    if (mode == NORMAL)
        mineCount = std::ceil(0.2 * (width * height));

    if (mode == HARD)
        mineCount = std::ceil(0.3 * (width * height));

    srand(time(0));
    for (int i = 0; i < mineCount; i++)
    {
        int rand_row = rand() % height;
        int rand_col = rand() % width;

        if (!(board[rand_row][rand_col].hasMine))
            board[rand_row][rand_col].hasMine = true;

        else
            i--;
    }
}

void MinesweeperBoard::debug_display() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[";
            if (board[i][j].hasMine)
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

bool MinesweeperBoard::fieldExist(int row, int col) const
{
    if (row >= height || row < 0 || col >= width || col < 0)
    {
        return false;
    }
    return true;
}

int MinesweeperBoard::countMines(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return -1;
    }
    if (!(isRevealed(row, col)))
    {
        return -1;
    }

    int mineAround = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (fieldExist(row + i, col + j))
            {
                if (board[row + i][col + j].hasMine)
                {
                    mineAround++;
                }
            }
        }
    }
    return mineAround;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return false;
    }
    if (isRevealed(row, col))
    {
        return false;
    }
    if (!(board[row][col].hasFlag))
    {
        return false;
    }
    return true;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (!(fieldExist(row, col)))
    {
        return;
    }
    if (isRevealed(row, col))
    {
        return;
    }
    if (state == FINISHED_LOSS || state == FINISHED_WIN)
    {
        return;
    }
    if (hasFlag(row, col))
    {
        board[row][col].hasFlag = false;
        return;
    }
    board[row][col].hasFlag = true;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (!(fieldExist(row, col)))
    {
        return;
    }
    if (isRevealed(row, col))
    {
        return;
    }
    if (hasFlag(row, col))
    {
        return;
    }
    if (state == FINISHED_LOSS || state == FINISHED_WIN)
    {
        return;
    }

    // First move rule
    if (height * width == unreaveled)
    {
        if (board[row][col].hasMine && mode != DEBUG)
        {
            relocateMine(row, col);
        }
    }

    board[row][col].isRevealed = true;
    unreaveled--;

    // Recursive reveal for field with no mines around.
    recursiveReveal(row, col);

    // Lose Condition
    if (board[row][col].hasMine)
    {
        state = FINISHED_LOSS;
        return;
    }

    // Win Condition
    if (unreaveled == mineCount)
    {
        toggleFlagOnRemainingFields();
        state = FINISHED_WIN;
    }
}

void MinesweeperBoard::recursiveReveal(int row, int col)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (countMines(row, col) == 0)
            {
                revealField(row + i, col + j);
            }
        }
    }
}

void MinesweeperBoard::relocateMine(int row, int col)
{
    board[row][col].hasMine = false;
    bool isSet = false;
    while (!isSet)
    {
        int rand_row = rand() % height;
        int rand_col = rand() % width;

        if (row != rand_row && col != rand_col)
        {
            if (!(board[rand_row][rand_col].hasMine))
            {
                board[rand_row][rand_col].hasMine = true;
                isSet = true;
            }
        }
    }
}

void MinesweeperBoard::toggleFlagOnRemainingFields()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (!isRevealed(i, j) && !hasFlag(i, j))
            {
                toggleFlag(i, j);
            }
        }
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return false;
    }
    if (!(board[row][col].isRevealed))
    {
        return false;
    }
    return true;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return '#';
    }
    if (!(isRevealed(row, col)))
    {
        if (hasFlag(row, col))
        {
            return 'F';
        }
        return '_';
    }
    if (board[row][col].hasMine)
    {
        return 'x';
    }
    int mines = countMines(row, col);
    if (mines == 0)
    {
        return ' ';
    }
    // ASCII convertion
    mines += 48;
    return mines;
}

void MinesweeperBoard::resetBoard()
{
    unreaveled = height * width;
    state = RUNNING;
    initialize_board();
    setMines();
}