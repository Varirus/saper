#ifndef MSBOARDVIEW_H
#define MSBOARDVIEW_H
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>

class MSBoardView
{
    MinesweeperBoard &board; // plansza
    sf::RectangleShape field;
    sf::Text text;
    sf::Font minesweeperFont;

public:
    MSBoardView(MinesweeperBoard &b);    // konstruktor
    void display(sf::RenderWindow &win); // wyświetlenie planszy
    void setFontSettings();              // Ustawia domyślne ustawienia czcionki
    void drawField(int row, int col, sf::RenderWindow &win); // Ustawia tekst dla danej komórki
};

#endif