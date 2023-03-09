#include <iostream>
#include "MinesweeperBoard.h"

using std::cout;

// Konstruktor ustawiający wysokość, szerokość,
// ilość bomb. Inicjalizuje pole oraz wywołuje
// funkcje testową
//
// Parametry: h - wysokość
// w - szerokość
// bombs - ilość bomb
//
// Zwraca: -
//
MinesweeperBoard::MinesweeperBoard(int h, int w, int bombs)
{
    height = h;
    width = w;
    amountOfBombs = bombs;

    initialize_board();
    test_3_fields();
}

// Funkcja inicjalizuje plansze o rozmiarach
// height*width ustawiajac pola na bez bomb,
// bez flag i zakryte.
//
// Parametry: -
//
// Zwraca: -
//
void MinesweeperBoard::initialize_board(){
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
//
// Zwraca: -
//
void MinesweeperBoard::test_3_fields(){
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
//
// Zwraca: -
//
void MinesweeperBoard::debug_display() const{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[";
            if(board[i][j].hasMine)
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