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

    void setup();
    void play();

    explicit Game(Board board)
            :board(board), gameOver(false), direction(Direction::Up), score(0)
    {
    }
    ~Game() = default;

private:
    Board board;
    SnakeBody snake;
    bool gameOver;
    Direction direction;
    unsigned score;

    static char getch();
    Direction getDirection();
};
