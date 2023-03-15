#include <iostream>
#include "MinesweeperBoard.h"

int main()
{
    MinesweeperBoard saper(10, 10, DEBUG);
    saper.debug_display();
    std::cout << saper.getFieldInfo(2, 0) << std::endl;
    saper.toggleFlag(0,0);
    saper.debug_display();
    saper.revealField(2, 1);
    std::cout << "Odkrywamy pole [1][2], ilość bomb wokół: " << saper.countMines(2,1) << std::endl;
    saper.debug_display();
    return 0;
}