#ifndef MSBOARDVIEW_H
#define MSBOARDVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

class MSBoardView
{
    MinesweeperBoard &board;  // Board
    sf::RectangleShape field; // Field squares
    sf::Text text;            // Field info text
    sf::Font minesweeperFont; // Font

public:
    /**
        @brief Construct a new MSBoardView object. Sets font and field squares settings.

        @param b MinesweeperBoard object
     */
    MSBoardView(MinesweeperBoard &b);

    /**
        @brief Function displays board on the window.

        @param win render window
     */
    void display(sf::RenderWindow &win);

    /**
        @brief Set the Font default settings/

     */
    void setFontSettings();

    /**
        @brief Function draws field on the window.

        @param row row number
        @param col column number
        @param win render window
     */
    void drawField(int row, int col, sf::RenderWindow &win);
};

#endif