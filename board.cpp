#include "board.h"

Board::Board()
{
    for (int i = 0; i<3; i++) {
        for (int j=0; j<3; j++) {
            data[i][j] = "N";
        }
    }
}