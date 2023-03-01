#include "Game.hpp"
#include "../Resource/Logger.hpp"

Logger logger;

int main() {

    logger.setPath("Config/history.log");
    
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

    logger.Info("LOCALE", setlocale(LC_ALL, NULL));

    Game game;
    
    try {
     
        game.run();
    }
    catch(const std::exception e) {
        std::cerr << e.what();
    }

    logger.Info("EXIT", "Close Programme\n---------------------------------------------");

    return 0;

}