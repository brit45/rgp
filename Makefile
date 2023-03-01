GCC=g++
STD=-std=c++20

LIB= -L -lsfml -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

OUTPUT=rpg

SHELL=bash


SRC=\
	app/src/main.cpp \
	app/src/Game.cpp \
	app/States/State.cpp \
	app/States/Game/GameState.cpp \
	app/States/MainMenu/MainMenuState.cpp \
	app/States/Editor/EditorState.cpp \
	app/Entities/Entity.cpp \
	app/Entities/Player/Player.cpp \
	app/Resource/Button.cpp \
	app/Resource/Logger.cpp \
	app/Components/MovementComponent.cpp \
	app/Components/HitboxComponent.cpp \
	app/Components/InfoComponent.cpp \
	app/Components/AnimationComponent.cpp
	

all : generate_rpg

generate_translate : 
	@printf "\033[36m %s\r \033[0m" "GENERATE LOCALES	...."
	@make local_ES local_FR
	@printf "\033[32m %s\n \033[0m" "GENERATE LOCALES	DONE"

generate_rpg	:
	@printf "\033[36m %s\r \033[0m"  "GENERATE BINARY	.... "
	@$(GCC) $(STD) $(SRC)  $(LIB) -o BIN/$(OUTPUT);
	@printf "\033[32m %s\n \033[0m" "GENERATE BINARY	 DONE"

local_FR : 
	@msginit --locale=fr --input="assets/Locales/fr_FR/fr_FR.po" --output="assets/Locales/fr_FR/LC_MESSAGES/main.mo" --no-translator;

local_ES :
	@msginit --locale=es --input="assets/Locales/es_ES/es_ES.po" --output="assets/Locales/es_ES/LC_MESSAGES/main.mo" --no-translator;

clean :
	@echo "[ \033[36mSUPPRESSION BINARY : $(OUTPUT) \t... \033[0m]"
	@rm BIN/$(OUTPUT) -fr
	@echo "[ \033[32mSUPPRESSION BINARY : \t DONE. \033[0m]"
	@echo "[ \033[36mSUPPRESSION LOCALES :  \t... \033[0m]"
	@rm assets/Locales/fr_FR/LC_MESSAGES/main.mo assets/Locales/es_ES/LC_MESSAGES/main.mo -fr
	@echo "[ \033[32mSUPPRESSION LOCALES : \t DONE. \033[0m]"