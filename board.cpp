#include "board.h"

Board::Board()
{
    vector<string> temp;
    temp.push_back("N");
    temp.push_back("N");
    temp.push_back("N");
    board.push_back(temp);
    board.push_back(temp);
    board.push_back(temp);
}

void Board::printData()
{
    cout << "________" << endl;

    cout << "  0 1 2" << endl;
    // cout << "-----" << endl;
    cout << "0|" << board[0][0] << " " << board[0][1] << " " << board[0][2] << "|" << endl;
    cout << "1|" << board[1][0] << " " << board[1][1] << " " << board[1][2] << "|" << endl;
    cout << "2|" << board[2][0] << " " << board[2][1] << " " << board[2][2] << "|" << endl;
    cout << "________" << endl;
}

string Board::returnContents(int y, int x) {
    return board[y][x];
}

void Board::modify(int y, int x, string input) {
    board[y][x] = input;
}