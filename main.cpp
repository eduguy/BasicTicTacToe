#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<string>> data;
bool isOver;
bool isXTurn;
int input;

void newData()
{
    vector<string> temp;
    temp.push_back("N");
    temp.push_back("N");
    temp.push_back("N");
    data.push_back(temp);
    data.push_back(temp);
    data.push_back(temp);
    // cout << "MOD" << endl;
}

void printData()
{
    cout << "-----" << endl;
    cout << "|" << data[0][0] << data[0][1] << data[0][2] << "|" << endl;
    cout << "|" << data[1][0] << data[1][1] << data[1][2] << "|" << endl;
    cout << "|" << data[2][0] << data[2][1] << data[2][2] << "|" << endl;
    cout << "-----" << endl;
}

void getInput()
{
    int x;
    int y;
    cout << "What coordinate is your next move?" << endl;
    cout << "X" << endl;
    cin >> x;
    cout << "y" << endl;
    cin >> y;

    if (data[y][x] == "N")
    {
        if (isXTurn)
        {
            data[y][x] = "X";
        }
        else
        {
            data[y][x] = "O";
        }
        isXTurn = !isXTurn;
    }
    else
    {
        cout << "Space already full, try again" << endl;
        printData();

        getInput();
    }
}

//data[Y VALUE][X VALUE]

void checkIsWinner()
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        if (data[i][0] == "X" && data[i][1] == "X" && data[i][2] == "X" || data[i][0] == "O" && data[i][1] == "O" && data[i][2] == "O")
        {
            isOver = true;
            cout << "YOU WINN" << endl;
            return;
        }
    }

    //check columns
    for (int i = 0; i < 3; i++)
    {
        if (data[0][i] == "X" && data[1][i] == "X" && data[2][i] == "X" || data[0][i] == "O" && data[1][i] == "O" && data[2][i] == "O")
        {
            isOver = true;
            cout << "YOU WIN" << endl;
            return;
        }
    }

    //check diagnals

    if (data[0][0] == "X" && data[1][1] == "X" && data[2][2] == "X" || data[0][0] == "Y" && data[1][1] == "Y" && data[2][2] == "Y")
    {
        isOver = true;
        cout << "YOU WIN" << endl;
        return;
    }
    if (data[0][2] == "X" && data[1][1] == "X" && data[0][2] == "X" || data[0][2] == "Y" && data[1][1] == "Y" && data[0][2] == "Y")
    {
        isOver = true;
        cout << "YOU WIN" << endl;
        return;
    }
}

void checkIsBoardFull()
{
    for (vector<string> vec : data)
    {
        for (string str : vec)
        {
            if (str == "N")
            {
                return;
            }
        }
    }

    isOver = true;
}

void getAIInput()
{
    int x = rand() % 2;
    int y = rand() % 2;

    if (data[y][x] == "N")
    {
        if (isXTurn)
        {
            data[y][x] = "X";
        }
        else
        {
            data[y][x] = "O";
        }
        isXTurn = !isXTurn;
        cout << "AI makes it's move at (" << x << "," << y << ")" << endl;
    }
    else
    {
        getAIInput();
    }
}
int main()
{
    cout << "Hello. Welcome to my tic tac toe game! Press 1 for 1 player and 2 for 2 player!" << endl;
    isXTurn = true;
    newData();
    cin >> input;
    if (input == 2) //will use this to switch between single and multiplayer mode
    {
        cout << "Welcome to the 2 player version. X goes first. You can begin!";
        while (!isOver)
        {
            printData();
            getInput();
            checkIsBoardFull();
            checkIsWinner();
        }
    }
    else
    {
        cout << "Welcome to the 1 player version against AI. You go first as X. You can begin!" << endl;
        while (!isOver)
        {
            printData();
            getInput();
            checkIsWinner();
            checkIsBoardFull();
            getAIInput();
            checkIsWinner();
            checkIsBoardFull();
        }
    }
    return 0;
    exit(0);
}
