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
    int height;    // rzeczywista wysokość planszy
    int width;     // rzeczywista szerokość planszy
    GameMode mode; // tryb gry

    Field board[100][100]; // tablica pól
    int mineCount;         // ilość bomb
    int unreaveled;        // ilość nieodkrytych pól
    bool firstMove;        // czy pierwszy ruch
    GameState state;       // stan gry

public:
    // getters
    int getWidth() const;           // getter szerokości
    int getHeight() const;          // getter wysokości
    int getMineCount() const;       // getter ilości bomb
    GameState getGameState() const; // getter stan gry

    MinesweeperBoard();                                  // domyślny konstruktor
    explicit MinesweeperBoard(int h, int w, GameMode m); // konstruktor
    void initialize_board();                             // Inicjalizacja pustej planszy
    void setMines();                                     // ustawia bomby w zależności od trybu gry
    void debug_display() const;                          // wyswietlanie planszy

    bool fieldExist(int row, int col) const;   // sprawdza czy pole znajduje sie w planszy
    int countMines(int row, int col) const;    // liczenie min wokół pola
    bool hasFlag(int row, int col) const;      // sprawdzenie flagi na polu
    void toggleFlag(int row, int col);         // zmienia stan flagi na polu
    void revealField(int row, int col);        // odkrywa pole
    void relocateMine(int row, int col);       // zmienia lokalizacje bomby
    bool isRevealed(int row, int col) const;   // sprawdzenie odkrycie pola
    char getFieldInfo(int row, int col) const; // zwraca informacje o polu
};

#endif