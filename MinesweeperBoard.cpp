#include <iostream>
#include <cmath>
#include "MinesweeperBoard.h"

using std::cout;

// Konstruktor ustawiający wysokość, szerokość,
// ilość bomb. Inicjalizuje pole oraz wywołuje
// funkcje testową
//
// Parametry: h - wysokość
// w - szerokość
// m - tryb gry
//
// Zwraca: -
//
MinesweeperBoard::MinesweeperBoard(int h, int w, GameMode m)
{
    height = h;
    width = w;
    mode = m;
    state = RUNNING;

    initialize_board();
    //test_3_fields();
    setMines();
}

// Gettery
int MinesweeperBoard::getWidth() const { return width; }
int MinesweeperBoard::getHeight() const { return height; }
int MinesweeperBoard::getMineCount() const { return mineCount; }
GameState MinesweeperBoard::getGameState() const { return state; }

// Funkcja na podstawie trybu gry
// ustawia ilość bomb na planszy
//
// Parametry: -
// Zwraca: -
//
void MinesweeperBoard::setMines()
{
    if (mode == DEBUG)
    {
        // Caly wiersz 1 ma miny
        for (int i = 0; i < width; i++)
        {
            board[0][i].hasMine = true;
        }
        
        return;
    }
    if (mode == EASY)
        mineCount = std::ceil(0.1 * (width * height));
    
    if (mode == NORMAL)
        mineCount = std::ceil(0.2 * (width * height));

    if (mode == HARD)
        mineCount = std::ceil(0.3 * (width * height));

    srand(time(0));
    for (int i = 0; i < mineCount; i++)
    {
        int rand_col = rand() % height;
        int rand_row = rand() % width;

        if (!(board[rand_col][rand_row].hasMine))
            board[rand_col][rand_row].hasMine = true;

        else
            i--;
    }
}

// Funkcja inicjalizuje plansze o rozmiarach
// height*width ustawiajac pola na bez bomb,
// bez flag i zakryte.
//
// Parametry: -
// Zwraca: -
//
void MinesweeperBoard::initialize_board()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            board[i][j].hasFlag = false;
            board[i][j].hasMine = false;
            board[i][j].isRevealed = false;
        }
    }
}

// Funkcja ustawia na 3 polach flagi,
// bomby i odkrycia w celach testowych.
//
// Parametry: -
// Zwraca: -
//
void MinesweeperBoard::test_3_fields()
{
    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasFlag = true;
    board[0][2].hasMine = true;
}

// Funkcja wyswietla w terminalu plansze
// sapera, a na kazdym polu czy znajduje sie mina,
// czy pole jest odkryte oraz czy jest oflagowane
//
// Parametry: -
// Zwraca: -
//
void MinesweeperBoard::debug_display() const
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[";
            if (board[i][j].hasMine)
                cout << "M";
            else
                cout << ".";
            if (board[i][j].isRevealed)
                cout << "o";
            else
                cout << ".";
            if (board[i][j].hasFlag)
                cout << "f";
            else
                cout << ".";
            cout << "]";
        }
        std::endl(cout);
    }
}

// Funkcja zwraca czy pole [col][row]
// jest w planszy
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: true, jeśli pole w planszy
// false, gdy:
// - pole poza planszą
//
bool MinesweeperBoard::fieldExist(int row, int col) const
{
    if (row >= width || row < 0 || col >= height || col < 0)
    {
        return false;
    }
    return true;
}

// Funkcja zlicza ilość bomb wokół
// podanego pola [col][row].
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: ilość bomb
// -1, gdy pole poza planszą
// -1, gdy pole nieodkryte
//
int MinesweeperBoard::countMines(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return -1;
    }
    if (!(isRevealed(row, col)))
    {
        return -1;
    }

    int mineAround = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                break;
            }
            if (fieldExist(row + i, col + j))
            {
                if (board[col + j][row + i].hasMine)
                {
                    mineAround++;
                }
            }
        }
    }
    return mineAround;
}

// Funkcja zwraca czy pole [col][row]
// ma na sobie flage.
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: true, jeśli pole ma na sobie flage
// false, gdy:
// - pole poza planszą
// - nie ma flagi
// - pole odkryte
//
bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return false;
    }
    if (isRevealed(row, col))
    {
        return false;
    }
    if (!(board[col][row].hasFlag))
    {
        return false;
    }
    return true;
}

// Funkcja nadaje flage polu[col][row],
// które nie zostało odkryte.
// Nie robi nic, gdy:
// - pole odkryte
// - pole poza planszą
// - gra zakończona
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: -
//
void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (!(fieldExist(row, col)))
    {
        return;
    }
    if (isRevealed(row, col))
    {
        return;
    }
    if (state == FINISHED_LOSS || state == FINISHED_WIN)
    {
        return;
    }
    if (hasFlag(row, col))
    {
        board[col][row].hasFlag = false;
    }
    board[col][row].hasFlag = true;
}

// Funkcja odkrywa pole[col][row].
// Nie robi nic, gdy:
// - pole odkryte
// - pole poza planszą
// - gra zakończona
// - flaga na polu
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: -
//
void MinesweeperBoard::revealField(int row, int col)
{
    if (!(fieldExist(row, col)))
    {
        return;
    }
    if (isRevealed(row, col))
    {
        return;
    }
    if (hasFlag(row, col))
    {
        return;
    }
    if (state == FINISHED_LOSS || state == FINISHED_WIN)
    {
        return;
    }
    if (!(board[col][row].hasMine))
    {
        board[col][row].isRevealed = true;
    }
    // TODO if first player action, then relocate bomb [NOT IN DEBUG]
    board[col][row].isRevealed = true;
    state = FINISHED_LOSS;
}

// Funkcja zwraca czy pole [col][row]
// zostalo odkryte.
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: true, jeśli pole odkryte
// false, gdy:
// - pole poza planszą
// - pole nieodkryte
//
bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return false;
    }
    if (!(board[col][row].isRevealed))
    {
        return false;
    }
    return true;
}

// Funkcja zwraca informacje o polu [col][row].
//
// Parametry: row - numer rzedu
// col - numer kolumny
//
// Zwraca: '#' - pole poza planszą
// 'F' - nieodkryte, flaga
// '_' - nieodkryte, bez flagi
// 'x' - odkryte, mina
// ' ' - odkryte, bez min wokół
// '1 ..... 8' - odkryte, miny wokół
//
char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (!(fieldExist(row, col)))
    {
        return '#';
    }
    if (!(isRevealed(row, col)))
    {
        if (hasFlag(row, col))
        {
            return 'F';
        }
        return '_';
    }
    if (board[col][row].hasMine)
    {
        return 'x';
    }
    int mines = countMines(row, col);
    if (mines == 0)
    {
        return ' ';
    }
    mines += 48;
    return mines;
}