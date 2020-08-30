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

void checkForWinner()
{
    if (board.checkIsWinner())
    {
        gameOver();
    }
}

void checkForTie()
{
    if (board.checkIsBoardFull())
    {
        board.printData();
        cout << "The game ends in a tie!" << endl;
        isOver = true;
    }
}

//should stay here
void getRandomInput()
{
    int x = rand() % 3;
    int y = rand() % 3;

    if (board.returnContents(y, x) == "N")
    {

        board.modify(y, x, "O");

        isXTurn = !isXTurn;
        cout << "AI makes it's move at (" << x << "," << y << ")." << endl;
    }
    else
    {
        getRandomInput();
    }
}

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
            checkForWinner();
            checkForTie();
        }
    }
    else if (input == 1)
    {
        cout << "Welcome to the 1 player version against AI. You go first as X. You can begin!" << endl;
        while (!isOver)
        {
            board.printData();
            getInput();
            checkForWinner();
            checkForTie();
            getRandomInput();
            checkForWinner();
            checkForTie();
        }
    }
    else
    {
        cout << "Welcome to the 1 player version against unbeatable AI. You go first as X. You can begin!" << endl;

        while (!isOver)
        {
            board.printData();
            getInput();
            checkForWinner();
            checkForTie();
            if (!isOver)
            {
                getMove();
                checkForWinner();
                checkForTie();
            }
        }
    }
    return 0;
    exit(0);
}
