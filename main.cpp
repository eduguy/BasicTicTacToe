#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<string>> data;
bool isOver;
bool isXTurn;
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
int main()
{
    cout << "Hello" << endl;
    isXTurn = true;
    newData();

    while (!isOver)
    {
        printData();
        getInput();
        printData();
        checkIsBoardFull();
        checkIsWinner();
    }

    return 0;
}

// # Loop through turns until the game is over
// loop forever:
//   # TODO: hmm I'm not sure how best to do this
//   # right now. No problem, I'll come back later.
//   current_player = ???

//   # Print the current state of the board
//   render(board)

//   # Get the move that the current player is going
//   # to make.
//   move_co_ords = get_move()

//   # Make the move that we calculated above
//   make_move(board, move_co_ords, current_player)

//   # Work out if there's a winner
//   winner = get_winner(board)

//   # If there is a winner, crown them the champion
//   # and exit the loop.
//   if winner is not None:
//     print "WINNER IS %s!!" % winner
//     break

//   # If there is no winner and the board is full,
//   # exit the loop.
//   if is_board_full(board):
//     print "IT'S A DRAW!!"
//     break

//   # Repeat until the game is over
