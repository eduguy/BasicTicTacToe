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



//data[Y VALUE][X VALUE]

bool Board::checkIsWinner()
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X") || (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O"))
        {
            // cout << "ROW" << endl;

            // gameOver();
            return true;
        }
    }

    //check columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X") || (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O"))
        {
            // cout << "COLUMN" << endl;

            // gameOver();
                        return true;

        }
    }

    //check diagnals

    if ((board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") || (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O"))
    {
        // cout << "LTOR" << endl;

        // gameOver();
                    return true;

    }
    if ((board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X") || (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O"))
    {
        // cout << "RTOL" << endl;

        // gameOver();
                    return true;

    }

    return false;
}

bool Board::checkIsBoardFull()
{
    for (vector<string> vec : board)
    {
        for (string str : vec)
        {
            if (str == "N")
            {
                return false;
            }
        }
    }
    

    return true;

}

