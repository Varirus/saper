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
    // board.toggleFlag(0, 0);
    // board.revealField(2, 1);
    // view.display();
    // std::cout << "DEBUG:" << std::endl;
    // board.debug_display();
    // std::cout << saper.getFieldInfo(2, 0) << std::endl;
    // std::cout << "Odkrywamy pole [1][2], ilość bomb wokół: " << saper.countMines(2, 1) << std::endl;
    // saper.debug_display();
    return 0;
}