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
    board.initializeBoard();

    snake.push_front(Coord(5, 8));
    snake.push_front(Coord(5, 7));
    snake.push_front(Coord(5, 6));

    board.putSnake(snake);
    board.addApple();
    board.printBoard();
}

Game::Direction Game::getDirection()
{
    char ch = getch();

    switch(std::tolower(ch))
    {
        case 'w':
        {
            if(!(Coord(snake.front().x, snake.front().y - 1) == snake.at(1)))
            {
                return Direction::Up;
            }
            return Direction::None;
        }
        case 's':
        {
            if(!(Coord(snake.front().x, snake.front().y + 1) == snake.at(1)))
            {
                return Direction::Down;
            }
            return Direction::None;
        }
        case 'a':
        {
            if(!(Coord(snake.front().x - 1, snake.front().y) == snake.at(1)))
            {
                return Direction::Left;
            }
            return Direction::None;
        }
        case 'd':
        {
            if(!(Coord(snake.front().x + 1, snake.front().y) == snake.at(1)))
            {
                return Direction::Right;
            }
            return Direction::None;
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
        direction = getDirection();

        switch(direction)
        {
            case Direction::Up:
            {
                if(board.isWall(Coord(snake.front().x, snake.front().y - 1)) || board.isBody(Coord(snake.front().x, snake.front().y - 1)))
                {
                    gameOver = true;
                }
                if(board.isApple(Coord(snake.front().x, snake.front().y - 1)))
                {
                    ++score;
                    board.addApple();
                }
                else
                {
                    board.setCell(snake.back(), '.');
                    snake.pop_back();
                }
                snake.push_front(Coord(snake.front().x, snake.front().y - 1));
                break;
            }
            case Direction::Down:
            {
                if(board.isWall(Coord(snake.front().x, snake.front().y + 1)) || board.isBody(Coord(snake.front().x, snake.front().y + 1)))
                {
                    gameOver = true;
                }
                if(board.isApple(Coord(snake.front().x, snake.front().y + 1)))
                {
                    ++score;
                    board.addApple();
                }
                else
                {
                    board.setCell(snake.back(), '.');
                    snake.pop_back();
                }
                snake.push_front(Coord(snake.front().x, snake.front().y + 1));
                break;
            }
            case Direction::Left:
            {
                if(board.isWall(Coord(snake.front().x - 1, snake.front().y)) || board.isBody(Coord(snake.front().x - 1, snake.front().y)))
                {
                    gameOver = true;
                }
                if(board.isApple(Coord(snake.front().x - 1, snake.front().y)))
                {
                    ++score;
                    board.addApple();
                }
                else
                {
                    board.setCell(snake.back(), '.');
                    snake.pop_back();
                }
                snake.push_front(Coord(snake.front().x - 1, snake.front().y));
                break;
            }
            case Direction::Right:
            {
                if(board.isWall(Coord(snake.front().x + 1, snake.front().y)) || board.isBody(Coord(snake.front().x + 1, snake.front().y)))
                {
                    gameOver = true;
                }
                if(board.isApple(Coord(snake.front().x + 1, snake.front().y)))
                {
                    ++score;
                    board.addApple();
                }
                else
                {
                    board.setCell(snake.back(), '.');
                    snake.pop_back();
                }
                snake.push_front(Coord(snake.front().x + 1, snake.front().y));
                break;
            }
            default:
            {
                break;
            }
        }
        board.putSnake(snake);
        board.printBoard();
        std::cout << "Score: " << score << std::endl;
    }
    std::cout << "Game over!" << std::endl;
    std::cout << "Your score: " << score << std::endl;
}
