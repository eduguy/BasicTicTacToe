#include "game.h"

Game::Game() {
    isOver = false;
    isXTurn = true;
}

void Game::printData(){
    board.printData();
}

bool Game::checkIsOver(){
    return isOver;
}
void Game::getInput()
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
void Game::gameOver()
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

void Game::checkForWinner()
{
    if (board.checkIsWinner())
    {
        gameOver();
    }
}

void Game::checkForTie()
{
    if (board.checkIsBoardFull())
    {
        board.printData();
        cout << "The game ends in a tie!" << endl;
        isOver = true;
    }
}

//should stay here
void Game::getRandomInput()
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
int Game::getPerfectInput(Board temp, int depth, bool isOTurn)

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
void Game::getMove()
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


