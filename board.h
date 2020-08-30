#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Board
{
    public:
    //create a new board
    Board(); 
    void printData();
    string returnContents(int y, int x);
    void modify(int y, int x, string input);
    bool checkIsWinner();
    bool checkIsBoardFull();

    private:
    //board will be 3x3
    vector<vector<string>> board;
};