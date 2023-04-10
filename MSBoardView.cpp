#include <iostream>
#include "MSBoardView.h"

using std::cout;

MSBoardView::MSBoardView(MinesweeperBoard &b)
    : board(b)
{
    field = sf::RectangleShape(sf::Vector2f(30, 30));
    field.setFillColor(sf::Color(200, 200, 200));
    field.setOutlineColor(sf::Color(50, 50, 50));
    field.setOutlineThickness(2);
    setFontSettings();
}

void MSBoardView::setFontSettings()
{

    minesweeperFont.loadFromFile("../mine-sweeper.ttf");
    text.setFont(minesweeperFont);
    text.setCharacterSize(18);
}

void MSBoardView::drawField(int row, int col, sf::RenderWindow &win)
{
    text.setPosition(40 * col + 26, 40 * row + 26);
    field.setPosition(40 * col + 20, 40 * row + 20);

    char fieldInfo = board.getFieldInfo(row, col);
    if (fieldInfo == '_')
    {
        field.setFillColor(sf::Color(100, 100, 100));
        win.draw(field);
        field.setFillColor(sf::Color(250, 250, 250));
        return;
    }
    text.setString(fieldInfo);
    if (fieldInfo == '1')
        text.setFillColor(sf::Color::Blue);
    if (fieldInfo == '2')
        text.setFillColor(sf::Color::Green);
    if (fieldInfo == '3')
        text.setFillColor(sf::Color::Red);
    if (fieldInfo == '4')
        text.setFillColor(sf::Color(130, 130, 150));
    if (fieldInfo == '5')
        text.setFillColor(sf::Color(128, 0, 0));
    if (fieldInfo == '6')
        text.setFillColor(sf::Color(64, 224, 208));
    if (fieldInfo == '7')
        text.setFillColor(sf::Color::Black);
    if (fieldInfo == '8')
        text.setFillColor(sf::Color(240, 240, 240));
    if (fieldInfo == 'x')
        text.setFillColor(sf::Color::Black);
    if (fieldInfo == 'F')
        text.setFillColor(sf::Color::Red);
    if (fieldInfo == ' ')
        text.setFillColor(sf::Color::Red);
    win.draw(field);
    win.draw(text);
}

void MSBoardView::display(sf::RenderWindow &win)
{
    for (int i = 0; i < board.getHeight(); i++)
    {
        for (int j = 0; j < board.getWidth(); j++)
        {
            drawField(i, j, win);
        }
    }
}