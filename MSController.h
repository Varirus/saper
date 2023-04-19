#ifndef MSCONTROLLER_H
#define MSCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardView.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class MSController
{

    sf::RenderWindow &window; // Window
    MinesweeperBoard &board;  // Board
    MSBoardView &view;        // MSBoardView object

public:
    /**
        @brief Construct a new MSController object.

        @param w window
        @param b board
        @param v MSBoardView object
     */
    MSController(sf::RenderWindow &w, MinesweeperBoard &b, MSBoardView &v);

    /**
        @brief Function calculates field row depending on mouse X coordinate.

        @param mouseX mouse X coordinate

        @return column number
     */
    int getFieldColumn(int mouseX) const;

    /**
        @brief Function calculates field row depending on mouse Y coordinate.

        @param mouseY mouse Y coordinate

        @return row number
     */
    int getFieldRow(int mouseY) const;

    /**
        @brief Function calculates field row depending on mouse Y coordinate.

        @param mouseX mouse X coordinate
        @param mouseY mouse Y coordinate

        @return \b True - if mouse is on the reset button \n
        @return \b False - if mouse isn't on the reset button \n
     */
    bool isInResetButton(int mouseX, int mouseY);

    /**
        @brief Function starts the game in SFML.
     */
    void play();
};

#endif