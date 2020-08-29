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
    String returnContents(int y, int x);
    void modify(int y, int x, String input);
    private:
    //board will be 3x3
    vector<vector<string>> board;
};