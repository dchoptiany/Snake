#include <iostream>
#include <array>
#include <deque>
#include "Coord.h"

typedef std::deque<Coord> SnakeBody;

class Board
{
public:
    static const unsigned BOARD_HEIGHT = 10;
    static const unsigned BOARD_WIDTH = 20;

    typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

    void printBoard();
    void putSnake(SnakeBody snake);
    void initializeBoard();

private:
    void makeFrame();
    void setCell(Coord, char);
    GameBoardArray board;
};
