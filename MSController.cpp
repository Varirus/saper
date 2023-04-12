#include "MSController.h"

MSController::MSController(sf::RenderWindow &w, MinesweeperBoard &b, MSBoardView &v)
    : window(w), board(b), view(v)
{
}

int MSController::getFieldColumn(int mouseX)
{
    if ((mouseX - 8) < 0)
        return -1;
    return ((mouseX - 8) / 22);
}

int MSController::getFieldRow(int mouseY)
{
    if ((mouseY - 8) < 0)
        return -1;
    return ((mouseY - 8) / 22);
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