#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Board
{
    public:
    //create a new board
    Board(); 

    private:
    //board will be 3x3
    vector<vector<string>> data;
};