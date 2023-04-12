#include <iostream>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSBoardView.h"
#include "MSController.h"

int main()
{
    MinesweeperBoard board(10, 10, EASY);

    /* SFML */
    sf::RenderWindow window(sf::VideoMode(board.getWidth() * 22 + 16, board.getHeight() * 22 + 16), "Saper", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30);
    MSBoardView view(board);

    MSController controller(window, board, view);

    controller.play();

    return 0;

    /* Terminal */
    //
    // MSBoardTextView view(board);
    // MSTextController ctrl(board, view);
    // board.debug_display();
    // ctrl.play();
    // return 0;
}
