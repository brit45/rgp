#include "Game.hpp"

Game game;

int main() {

    try {
     
        game.run();
    }
    catch(const std::exception e) {
        std::cerr << e.what();
    }

    return 0;

}