#include <iostream>
#include "game.h"
using namespace std;
int input;

int main()
{
    Game game;
    cout << "Hello. Welcome to my tic tac toe game! Press 1 for 1 player against simple AI, 2 for 2 player, and 3 to play 1 player against the unbeatable AI!" << endl;
    // isXTurn = true;
    // newData();
    cin >> input;
    if (input == 2) //will use this to switch between single and multiplayer mode
    {
        cout << "Welcome to the 2 player version. X goes first. You can begin!" << endl;
        while (!game.checkIsOver())
        {
            game.printData();
            game.getInput();
            game.checkForWinner();
            game.checkForTie();
        }
    }
    else if (input == 1)
    {
        cout << "Welcome to the 1 player version against AI. You go first as X. You can begin!" << endl;
        while (!game.checkIsOver())
        {
            game.printData();
            game.getInput();
            game.checkForWinner();
            game.checkForTie();
            game.getRandomInput();
            game.checkForWinner();
            game.checkForTie();
        }
    }
    else
    {
        cout << "Welcome to the 1 player version against unbeatable AI. You go first as X. You can begin!" << endl;

        while (!game.checkIsOver())
        {
            game.printData();
            game.getInput();
            game.checkForWinner();
            game.checkForTie();
            if (!game.checkIsOver())
            {
                game.getMove();
                game.checkForWinner();
                game.checkForTie();
            }
        }
    }
    return 0;
    exit(0);
}
