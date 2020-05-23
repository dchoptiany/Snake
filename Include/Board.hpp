#include <iostream>
#include <array>
#include <deque>
#include <random>
#include "Coord.hpp"

typedef std::deque<Coord> SnakeBody;

class Board
{
public:
    static const unsigned BOARD_HEIGHT = 10;
    static const unsigned BOARD_WIDTH = 20;

    typedef std::array<std::array<char, BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

    GameBoardArray _board;
    void printBoard();
    void putSnake(const SnakeBody&);
    void initializeBoard();
    void setCell(const Coord&, char);
    bool isEmpty(const Coord&);
    bool isBody(const Coord&);
    bool isApple(const Coord&);
    bool isWall(const Coord&);
    void addApple();

private:
    void makeFrame();
};
