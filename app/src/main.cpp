#include "Game.hpp"
#include "../Resource/Logger.hpp"



int main() {

    

    Logger *log = new Logger();

    log->setPath("Config/history.log");


    log->Info("Start Programme", "---------------------------------------------------");

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

    log->Info("LOCALE", setlocale(LC_ALL, NULL));

    Game game;

    try {
        
        game.run();
    }
    catch(const std::exception e) {
        std::cerr << e.what();
    }

    log->Info("Stop Programme", "---------------------------------------------------\n\n");

    return 0;

}