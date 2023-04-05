#include <iostream>
#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSBoardView.h"

int main()
{
    MinesweeperBoard board(10, 10, EASY);

    /* SFML */
    //

    sf::RenderWindow window(sf::VideoMode(board.getWidth() * 40 + 30, board.getHeight() * 40 + 30), "Saper");
    window.setFramerateLimit(30);
    MSBoardView view(board);
    sf::Clock clk;
    board.toggleFlag(3,3);
    board.revealField(5, 4);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(clk.getElapsedTime().asMilliseconds() > 500){
            board.revealField(rand() % 10, rand() % 10);
            if(board.getGameState() == RUNNING){
                clk.restart();
            }
        }
        window.clear(sf::Color::Black);
        view.display(window);

        window.display();
    }

    /* Terminal */
    //
    // MSBoardTextView view(board);
    // MSTextController ctrl(board, view);
    // board.debug_display();
    // ctrl.play();
    // return 0;
}
