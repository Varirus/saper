#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

struct Field
{
    bool hasMine; // czy ma bombe
    bool hasFlag; // czy ma flage
    bool isRevealed; // czy zostalo odkryte
};

class MinesweeperBoard
{
    Field board[100][100];

    // niezbędne jeśli użyjecie tablicy 2D, ale w każdym
    // przypadku wygodne
    int width;  // rzeczywista szerokość planszy
    int height; // rzeczywista wysokość planszy
    int amountOfBombs; // liczba bomb

public:
    MinesweeperBoard(int h, int w, int bombs); // konstruktor
    void initialize_board(); // Inicjalizacja pustej planszy
    void test_3_fields(); // test 3 pól
    void debug_display() const; // wyswietlanie planszy
};

#endif