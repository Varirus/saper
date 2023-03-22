#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    MinesweeperBoard *board; // wskaźnik na plansze
    MSBoardTextView *view;   // wskaźnik na wyświetlacz
public:
    MSTextController(MinesweeperBoard &b, MSBoardTextView &v); // konstruktor
    void play();                                               // odpalanie gry
};

#endif