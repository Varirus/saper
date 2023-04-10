#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView
{
    MinesweeperBoard &board; // board

public:
    /**
     * @brief Construct a new MSBoardTextView object
     * 
     * @param b board
     */
    MSBoardTextView(MinesweeperBoard &b);

    /**
     * @brief Displays board view in terminal for the player.
     * 
     */
    void display() const;
};

#endif