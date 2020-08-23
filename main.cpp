#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<string>> data;
bool isOver;

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
    cout <<"X"<<endl;
    cin >> x;
    cout<<"y"<<endl;
    cin >> y;

    data[x][y] = "X";
    
}

int main()
{
    cout << "Hello" << endl;

    while (!isOver)
    {
        newData();
        printData();
        getInput();
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
