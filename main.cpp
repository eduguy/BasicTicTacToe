#include <iostream>
#include <utility>
#include <vector>
#include "main.h"
using namespace std;

// vector<vector<string>> data;
bool isOver;
bool isXTurn;
int input;
Board board;

//board class
// void newData()
// {
//     vector<string> temp;
//     temp.push_back("N");
//     temp.push_back("N");
//     temp.push_back("N");
//     data.push_back(temp);
//     data.push_back(temp);
//     data.push_back(temp);
//     // cout << "MOD" << endl;
// }

// void printData()
// {
//     cout << "________" << endl;

//     cout << "  0 1 2" << endl;
//     // cout << "-----" << endl;
//     cout << "0|" << data[0][0] << " " << data[0][1] << " " << data[0][2] << "|" << endl;
//     cout << "1|" << data[1][0] << " " << data[1][1] << " " << data[1][2] << "|" << endl;
//     cout << "2|" << data[2][0] << " " << data[2][1] << " " << data[2][2] << "|" << endl;
//     cout << "________" << endl;
// }
//
//most of the stuff can be moved to board. can recombine the checkwinner and tie methods and use their return values to modify isover/isxturn, will also limit duplication

//stay here
void getInput()
{
    int x;
    int y;
    cout << "What coordinate is your next move?" << endl;
    cout << "Enter in the X Value." << endl;
    cin >> x;
    cout << "Enter in the Y value." << endl;
    cin >> y;

    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        cout << "Invalid move, try again." << endl;
        getInput();
    }
    else if (board.returnContents(y, x) == "N")
    {
        if (isXTurn)
        {
            // data[y][x] = "X";
            board.modify(y, x, "X");
        }
        else
        {
            // data[y][x] = "O";
            board.modify(y, x, "O");
        }
        isXTurn = !isXTurn;
    }
    else
    {
        cout << "Space already full, try again" << endl;
        board.printData();
        getInput();
    }
}
void gameOver()
{
    isOver = true;
    if (!isXTurn)
    {
        board.printData();

        cout << "X WINS" << endl;
    }
    else
    {
        board.printData();

        cout << "O WINS" << endl;
    }
    exit(0);
}

//should stay here
void getRandomInput()
{
    int x = rand() % 3;
    int y = rand() % 3;

    if (board.returnContents(y, x) == "N")
    {

        // data[y][x] = "O";
        board.modify(y, x, "O");

        isXTurn = !isXTurn;
        cout << "AI makes it's move at (" << x << "," << y << ")." << endl;
    }
    else
    {
        getRandomInput();
    }
}

// bool checkWinnerAI(vector<vector<string>> temp)
// {
//     //check rows
//     for (int i = 0; i < 3; i++)
//     {
//         if ((temp[i][0] == "X" && temp[i][1] == "X" && temp[i][2] == "X") || (temp[i][0] == "O" && temp[i][1] == "O" && temp[i][2] == "O"))
//         {
//             // cout << "ROW" << endl;

//             return true;
//         }
//     }

//     //check columns
//     for (int i = 0; i < 3; i++)
//     {
//         if ((temp[0][i] == "X" && temp[1][i] == "X" && temp[2][i] == "X") || (temp[0][i] == "O" && temp[1][i] == "O" && temp[2][i] == "O"))
//         {
//             // cout << "COLUMN" << endl;

//             return true;
//         }
//     }

//     //check diagnals

//     if ((temp[0][0] == "X" && temp[1][1] == "X" && temp[2][2] == "X") || (temp[0][0] == "O" && temp[1][1] == "O" && temp[2][2] == "O"))
//     {
//         // cout << "LTOR" << endl;

//         return true;
//     }
//     if ((temp[0][2] == "X" && temp[1][1] == "X" && temp[2][0] == "X") || (temp[0][2] == "O" && temp[1][1] == "O" && temp[2][0] == "O"))
//     {
//         // cout << "RTOL" << endl;

//         return true;
//     }

//     return false;
// }

// bool checkTieAI(vector<vector<string>> temp)
// {
//     for (vector<string> vec : temp)
//     {
//         for (string str : vec)
//         {
//             if (str == "N")
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

//stay here
int getPerfectInput(Board temp, int depth, bool isOTurn)

{
    if (temp.checkIsWinner())
    {
        if (!isOTurn)
        {
            return 10 - depth;
        }
        else
        {
            return -10 + depth;
        }
    }
    else if (temp.checkIsBoardFull())
    {
        return 0;
    }
    else

    {

        // cout<<"past if statements"<<endl;
        if (isOTurn)
        {
            int bestMoveScore = -100;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (temp.returnContents(i, j) == "N")
                    {
                        //i want to maximize the score of O
                        temp.modify(i, j, "O");
                        int maxScore = getPerfectInput(temp, depth++, false);
                        temp.modify(i, j, "N"); //the issue was I wasn't resetting the board after each time I tried a move, so the AI wasn't able to properly get the optimal move
                        bestMoveScore = max(maxScore, bestMoveScore);
                    }
                }
            }
            return bestMoveScore;
        }
        else
        {
            int bestMoveScore = 100;
            //minimize
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (temp.returnContents(i, j) == "N")
                    {
                        temp.modify(i, j, "X");
                        int minScore = getPerfectInput(temp, depth++, true);
                        temp.modify(i, j, "N"); //the issue was I wasn't resetting the board after each time I tried a move, so the AI wasn't able to properly get the optimal move

                        bestMoveScore = min(minScore, bestMoveScore);
                    }
                }
            }

            return bestMoveScore;
        }

        // return getPerfectInput(temp, depth++, !isOTurn);
    }
    //if (checkwinner(temp))
    // {
    //     return (-10 - depth) or (10-depth) depdning on if O or X won;
    // }
    //else if (gameTIe) {
    //     return 0-depth;
    // }
    // else {
    // vector vec = getMove(temp, isOTurn);
    // getPerfectInput(vecotrwithrandommove, depth++,~isturn);
    // }
}

//stay here
void getMove()
{

    int moveX;
    int moveY;
    int bestScoreSoFar = -1000; //arbitrary
    // vector<vector<string>> temp1 = data;
    Board temp1 = board;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp1.returnContents(i, j) == "N")
            {
                temp1.modify(i, j, "O");
                int score = getPerfectInput(temp1, 0, false);
                temp1.modify(i, j, "N"); //the issue was I wasn't resetting the board after each time I tried a move, so the AI wasn't able to properly get the optimal move

                if (score > bestScoreSoFar)
                {

                    bestScoreSoFar = score;
                    moveX = j;
                    moveY = i;
                }
            }
        }
    }

    // cout << "BSF" << bestScoreSoFar<<endl;
    isXTurn = !isXTurn;
    cout << "AI makes it's move at (" << moveX << "," << moveY << ")." << endl;
    board.modify(moveY, moveX, "O");

    //get all unused spaces
    // for (unused spaces :board) {
    //     fill with X/O,
    //     getperfectmove with all the board options
    // }}

    //return the temp board that gives the highest score
    //replace global board with temp board
}

int main()
{
    cout << "Hello. Welcome to my tic tac toe game! Press 1 for 1 player against simple AI, 2 for 2 player, and 3 to play 1 player against the unbeatable AI!" << endl;
    isXTurn = true;
    // newData();
    cin >> input;
    if (input == 2) //will use this to switch between single and multiplayer mode
    {
        cout << "Welcome to the 2 player version. X goes first. You can begin!" << endl;
        while (!isOver)
        {
            board.printData();
            getInput();
            board.checkIsBoardFull();
            board.checkIsWinner();
        }
    }
    else if (input == 1)
    {
        cout << "Welcome to the 1 player version against AI. You go first as X. You can begin!" << endl;
        while (!isOver)
        {
            board.printData();
            getInput();
            // cout << "got your input" << endl;
            board.checkIsWinner();
            board.checkIsBoardFull();
            getRandomInput();
            // cout << "got cpu input" << endl;
            board.checkIsWinner();
            board.checkIsBoardFull();
        }
    }
    else
    {
        cout << "Welcome to the 1 player version against unbeatable AI. You go first as X. You can begin!" << endl;

        while (!isOver)
        {
            board.printData();
            getInput();
            board.checkIsWinner();
            board.checkIsBoardFull();
            if (!isOver)
            {
                getMove();
                board.checkIsWinner();
                board.checkIsBoardFull();
            }
        }
    }
    return 0;
    exit(0);
}
