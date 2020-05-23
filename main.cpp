#include "Game.h"

int main()
{
    Board board;
    Game game(board);
    game.setup();
    game.play();
}
