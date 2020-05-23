#include "Board.h"

void Board::printBoard()
{
    system("clear");
    for(unsigned i = 0; i < BOARD_HEIGHT; i++)
    {
        for(unsigned j = 0; j < BOARD_WIDTH; j++)
        {
            std::cout << _board.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

void Board::putSnake(const SnakeBody& snake)
{
    for(auto bodypart : snake)
    {
        setCell(bodypart, 'o');
    }
    setCell(snake.front(), 'O');
}

void Board::initializeBoard()
{
    for(unsigned y = 0; y < BOARD_HEIGHT; y++)
    {
        for(unsigned x = 0; x < BOARD_WIDTH; x++)
        {
            setCell(Coord(x, y), '.');
        }
    }
    makeFrame();
}

void Board::makeFrame()
{
    for(unsigned y = 0; y < BOARD_HEIGHT; y++)
    {
        setCell(Coord(0, y), '#');
        setCell(Coord(BOARD_WIDTH - 1, y), '#');
    }

    for(unsigned x = 0; x < BOARD_WIDTH; x++)
    {
        setCell(Coord(x, 0), '#');
        setCell(Coord(x, BOARD_HEIGHT - 1), '#');
    }
}

void Board::setCell(const Coord& where, const char what)
{
    _board.at(where.y).at(where.x) = what;
}

bool Board::isEmpty(const Coord& coord)
{
    return _board.at(coord.y).at(coord.x) == '.';
}

bool Board::isBody(const Coord& coord)
{
    return _board.at(coord.y).at(coord.x) == 'o';
}

bool Board::isApple(const Coord& coord)
{
    return _board.at(coord.y).at(coord.x) == '@';
}

bool Board::isWall(const Coord& coord)
{
    return _board.at(coord.y).at(coord.x) == '#';
}

void Board::addApple()
{
    static std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<unsigned> x(1, BOARD_HEIGHT - 1);
    static std::uniform_int_distribution<unsigned> y(1, BOARD_WIDTH - 1);

    Coord coord = Coord(y(rng), x(rng));

    if(isEmpty(coord))
    {
        setCell(coord, '@');
    }
    else
    {
        addApple();
    }
}
