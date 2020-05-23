#include "Board.h"

void Board::printBoard()
{
    for(int i = 0; i < BOARD_HEIGHT; i++)
    {
        for(int j = 0; j < BOARD_WIDTH; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::putSnake(SnakeBody snake)
{
    for(auto bodypart : snake)
    {
        setCell(bodypart, 'O');
    }
    setCell(snake.front(), '@');
}

void Board::initializeBoard()
{
    for(int y = 0; y < BOARD_HEIGHT; y++)
    {
        for(int x = 0; x < BOARD_WIDTH; x++)
        {
            setCell(Coord(x, y), ' ');
        }
    }
    makeFrame();
}

void Board::makeFrame()
{
    for(int y = 0; y < BOARD_HEIGHT; y++)
    {
        setCell(Coord(0, y), '#');
        setCell(Coord(BOARD_WIDTH - 1, y), '#');
    }

    for(int x = 0; x < BOARD_WIDTH; x++)
    {
        setCell(Coord(x, 0), '#');
        setCell(Coord(x, BOARD_HEIGHT - 1), '#');
    }
}

void Board::setCell(Coord where, const char what)
{
    board[where.y][where.x] = what;
}
