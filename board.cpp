#include "board.h"

Board::Board()
{
    vector<string> temp;
    temp.push_back("N");
    temp.push_back("N");
    temp.push_back("N");
    data.push_back(temp);
    data.push_back(temp);
    data.push_back(temp);
}

void Board::printData()
{
    cout << "________" << endl;

    cout << "  0 1 2" << endl;
    // cout << "-----" << endl;
    cout << "0|" << data[0][0] << " " << data[0][1] << " " << data[0][2] << "|" << endl;
    cout << "1|" << data[1][0] << " " << data[1][1] << " " << data[1][2] << "|" << endl;
    cout << "2|" << data[2][0] << " " << data[2][1] << " " << data[2][2] << "|" << endl;
    cout << "________" << endl;
}

String Board::returnContents(int y, int x) {
    return data[y][x];
}

void Board::modify(int y, int x, String input) {
    data[y][x] = input;
}