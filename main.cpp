#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main()
{

    MinesweeperBoard board(5, 6, HARD);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);
    board.debug_display();

    ctrl.play();
    return 0;
}