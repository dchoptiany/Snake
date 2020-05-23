#include "Game.hpp"

int main()
{
    Board board;
    Game game(board);
    game.setup();
    game.play();
}
