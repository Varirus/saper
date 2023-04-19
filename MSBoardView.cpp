#include "MSBoardView.h"

MSBoardView::MSBoardView(MinesweeperBoard &b)
    : board(b)
{
    initShapes();
    setFontSettings();
}

void MSBoardView::initShapes()
{
    field = sf::RectangleShape(sf::Vector2f(18, 18));
    field.setFillColor(sf::Color(200, 200, 200));
    field.setOutlineColor(sf::Color(50, 50, 50));
    field.setOutlineThickness(2);

    resetButton = sf::RectangleShape(sf::Vector2f((2 * 22 - 4), (2 * 22 - 4)));
    resetButton.setFillColor(sf::Color(10, 220, 30));
    resetButton.setOutlineColor(sf::Color(30, 30, 30));
    resetButton.setOutlineThickness(2);
    resetButton.setPosition(10, (board.getHeight() * 22 + 12));

    finishedText.setFillColor(sf::Color::White);
    finishedText.setPosition(58, (board.getHeight() * 22 + 20));

    resetText.setFillColor(sf::Color::Black);
    resetText.setPosition(11, (board.getHeight() * 22 + 27));
    resetText.setString("Reset");
}

void MSBoardView::setFontSettings()
{
    if (!minesweeperFont.loadFromFile("../mine-sweeper.ttf"))
        minesweeperFont.loadFromFile("mine-sweeper.ttf");
    text.setFont(minesweeperFont);
    text.setCharacterSize(12);
    text.setLetterSpacing(0);
    resetText.setFont(minesweeperFont);
    resetText.setCharacterSize(7);
    finishedText.setFont(minesweeperFont);
    finishedText.setCharacterSize(24);
}

void MSBoardView::setFinishedText()
{
    if (board.getGameState() == FINISHED_LOSS)
    {
        finishedText.setString("LOSS");
        if (board.getWidth() < 7)
            finishedText.setString("L");
    }
    if (board.getGameState() == FINISHED_WIN)
    {
        finishedText.setString("WIN");
        if (board.getWidth() < 7)
            finishedText.setString("W");
    }
}

void MSBoardView::drawField(int row, int col, sf::RenderWindow &win)
{
    text.setPosition(22 * col + 13, 22 * row + 13);
    field.setPosition(22 * col + 10, 22 * row + 10);

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
    {
        text.setFillColor(sf::Color::Black);
        text.setString("*");
        text.setPosition(22 * col + 11, 22 * row + 14);
        win.draw(field);
        win.draw(text);
        return;
    }
    if (fieldInfo == 'F')
    {
        text.setFillColor(sf::Color::Red);
        field.setFillColor(sf::Color(150, 150, 150));
        text.setString("`");
        win.draw(field);
        win.draw(text);
        field.setFillColor(sf::Color(250, 250, 250));
        return;
    }

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

    setFinishedText();
    if (board.getGameState() != RUNNING)
        win.draw(finishedText);
    win.draw(resetButton);
    win.draw(resetText);
}