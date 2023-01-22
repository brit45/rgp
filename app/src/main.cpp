#include "Game.hpp"

int main() {
    
    bindtextdomain("main", "assets/Locales");
    textdomain("main");
    bind_textdomain_codeset("main","UTF-8");
    bool check_local = false;
    int i = 0;

    const char *list_local[] = {
        "fr_FR.UTF-8",
        "es_ES.UTF-8",
    };

    while(!check_local) {
        check_local = (setlocale(LC_ALL, list_local[i])? true : false);
    }

    std::cout << "[ INFO|LOCALE ]\t->\t" << setlocale(LC_ALL, NULL) << std::endl;
    Game game;
    
    try {
     
        game.run();
    }
    catch(const std::exception e) {
        std::cerr << e.what();
    }

    std::cout << "[ INFO|DEBUG ]\t->\tClose programme." << std::endl;

    return 0;

}