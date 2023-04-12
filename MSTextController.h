#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    MinesweeperBoard &board; // Board
    MSBoardTextView &view;   // MSBoardTextView object
public:
    /**
        @brief Construct a new MSTextController object.

        @param b board
        @param v MSBoardTextView object
     */
    MSTextController(MinesweeperBoard &b, MSBoardTextView &v);

    /**
        @brief Function starts the game in terminal.

     */
    void play();
};

#endif