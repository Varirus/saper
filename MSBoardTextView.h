#ifndef MSBOARDTEXTVIEW_H
#define MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView
{
    MinesweeperBoard *board; // wskaźnik na plansze

public:
    MSBoardTextView(MinesweeperBoard &b); // konstruktor
    void display() const;                 // wyświetlenie planszy
};

#endif