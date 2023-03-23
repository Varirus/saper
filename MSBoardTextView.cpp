#include <iostream>
#include "MSBoardTextView.h"

using std::cout;

MSBoardTextView::MSBoardTextView(MinesweeperBoard & b)
    : board(b)
{

}

void MSBoardTextView::display() const{
    for (int i = 0; i < board.getHeight(); i++)
    {
        for (int j = 0; j < board.getWidth(); j++)
        {
            cout << "[" << board.getFieldInfo(i, j) << "]";
        }
        std::endl(cout);
    }
}