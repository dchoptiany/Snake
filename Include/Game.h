#include "Board.h"
#include <termios.h>
#include <unistd.h>
#include <termios.h>

class Game
{
public:
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        None
    };

    Board board;
    SnakeBody snake;
    bool gameOver;
    Game::Direction direction = Game::Direction::None;

    void setup();
    void play();
    Direction getDirection();

private:
    char getch();
};
