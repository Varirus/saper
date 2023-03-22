#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};
enum GameState
{
    RUNNING,
    FINISHED_WIN,
    FINISHED_LOSS
};

struct Field
{
    bool hasMine;    // czy ma bombe
    bool hasFlag;    // czy ma flage
    bool isRevealed; // czy zostalo odkryte
};

class MinesweeperBoard
{
    Field board[100][100];

    // niezbędne jeśli użyjecie tablicy 2D, ale w każdym
    // przypadku wygodne
    int width;       // rzeczywista szerokość planszy
    int height;      // rzeczywista wysokość planszy
    int mineCount;   // ilość bomb
    GameMode mode;   // tryb gry
    GameState state; // stan gry

public:
    // getters
    int getWidth() const;           // getter szerokości
    int getHeight() const;          // getter wysokości
    int getMineCount() const;       // getter ilości bomb
    GameState getGameState() const; // getter stan gry

    MinesweeperBoard(int h, int w, GameMode mode); // konstruktor
    void setMines();                               // ustawia bomby w zależności od trybu gry
    void initialize_board();                       // Inicjalizacja pustej planszy
    void test_3_fields();                          // test 3 pól
    void debug_display() const;                    // wyswietlanie planszy

    bool fieldExist(int row, int col) const;   // sprawdza czy pole znajduje sie w planszy
    int countMines(int row, int col) const;    // liczenie min wokół pola
    bool hasFlag(int row, int col) const;      // sprawdzenie flagi na polu
    void toggleFlag(int row, int col);         // zmienia stan flagi na polu
    void revealField(int row, int col);        // odkrywa pole
    bool isRevealed(int row, int col) const;   // sprawdzenie odkrycie pola
    char getFieldInfo(int row, int col) const; // zwraca informacje o polu
};

#endif