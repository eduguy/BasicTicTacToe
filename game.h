#include "board.h"
#include <iostream>
#include <string>
#include <utility>

#include <vector>

using namespace std;

class Game
{
public:
    Game();
    void getInput();
    void gameOver();
    void checkForWinner();
    void checkForTie();
    void getRandomInput();
    int getPerfectInput(Board temp, int depth, bool isOTurn);
    void getMove();
    bool checkIsOver();
    void printData();

private:
    bool isOver;
    bool isXTurn;
    // int input;
    Board board;
};