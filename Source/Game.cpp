#include "Game.h"

char Game::getch()
{
    char ch = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
    if(read(0, &ch, 1) < 0)
    perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
    printf("%c\n", ch);
    return ch;
}

void Game::setup()
{
    gameOver = false;
    direction = Game::Direction::None;

    board.initializeBoard();

    snake.push_back(Coord(5, 6));
    snake.push_back(Coord(5, 7));
    snake.push_back(Coord(5, 8));

    board.putSnake(snake);
}

Game::Direction Game::getDirection()
{
    char ch = getch();

    switch(std::tolower(ch))
    {
        case 'w':
        {
            return Direction::Up;
        }
        case 's':
        {
            return Direction::Down;
        }
        case 'a':
        {
            return Direction::Left;
        }
        case 'd':
        {
            return Direction::Right;
        }
        default:
        {
            return Direction::None;
        }
    }
}

void Game::play()
{
    while(!gameOver)
    {
        while(direction == Game::Direction::None)
        {
            getDirection();
        }
    }
}
