#include "MSController.h"

MSController::MSController(sf::RenderWindow &w, MinesweeperBoard &b, MSBoardView &v)
    : window(w), board(b), view(v)
{
}

int MSController::getFieldColumn(int mouseX) const
{
    if ((mouseX - 8) < 0)
        return -1;
    return ((mouseX - 8) / 22);
}

int MSController::getFieldRow(int mouseY) const
{
    if ((mouseY - 8) < 0)
        return -1;
    return ((mouseY - 8) / 22);
}
bool MSController::isInResetButton(int mouseX, int mouseY)
{
    if (mouseX >= 10 && mouseX <= 54)
    {
        if (mouseY >= (board.getHeight() * 22 + 12) && mouseX <= (board.getHeight() * 22 + 56))
            return true;
    }
    return false;
}

void MSController::play()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (board.getGameState() == RUNNING)
                        board.revealField(getFieldRow(event.mouseButton.y), getFieldRow(event.mouseButton.x));
                    if (isInResetButton(event.mouseButton.x, event.mouseButton.y))
                    {
                        board.resetBoard();
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (board.getGameState() == RUNNING)
                        board.toggleFlag(getFieldRow(event.mouseButton.y), getFieldRow(event.mouseButton.x));
                }
            }
        }

        window.clear(sf::Color::Black);

        view.display(window);

        window.display();
    }
}