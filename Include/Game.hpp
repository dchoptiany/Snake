#include <termios.h>
#include <unistd.h>
#include <termios.h>
#include <fstream>
#include "Board.hpp"

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

    explicit Game(const Board&);
    ~Game() = default;

private:
    Board board;
    SnakeBody snake;
    bool gameOver;
    Direction direction;
    unsigned score;
    unsigned highscore;

    static char getch();
    Direction getDirection();
    static unsigned loadHighscore();
    void saveHighscore() const;
    void reset();
};
