#include <iostream>
#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v)
{
    board = &b;
    view = &v;
}

void MSTextController::play(){
    std::cout << "o - odkrycie pola" << std::endl;
    std::cout << "f - oflagowanie pola" << std::endl;
    int col, row;
    char action;
    while(board->getGameState() == RUNNING){
        view->display();
        std::cout << "Podaj kolumne:" << std::endl;
        std::cin >> col;
        std::cout << "Podaj rząd:" << std::endl;
        std::cin >> row;
        std::cout << "Podaj żądaną akcje [o lub f]:" << std::endl;
        std::cin >> action;
        if(action == 'f'){
            board->toggleFlag(row-1, col-1);
        }
        if (action == 'o')
        {
            board->revealField(row-1, col-1);
        }
    }
    if (board->getGameState() == FINISHED_WIN)
        std::cout << "Wygrałeś/aś" << std::endl;
    if (board->getGameState() == FINISHED_LOSS)
        std::cout << "Przegrałeś/aś" << std::endl;
    view->display();
}