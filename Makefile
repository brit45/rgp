GCC=g++
STD=-std=c++20

LIB= -L -lsfml -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

OUTPUT=rpg


SRC=\
	app/src/main.cpp \
	app/src/Game.cpp \
	app/States/State.cpp \
	app/States/Game/GameState.cpp \
	app/States/MainMenu/MainMenuState.cpp \
	app/States/Editor/EditorState.cpp \
	app/Entities/Entity.cpp \
	app/Entities/Player/Player.cpp \
	app/Ressource/Button.cpp \
	app/Components/MovementComponent.cpp \
	app/Components/HitboxComponent.cpp \
	app/Components/InfoComponent.cpp \
	app/Components/AnimationComponent.cpp
	

all : local_FR local_ES rpg

rpg	:
	@echo  "[ \033[36mGENERATE BINARY : $(OUTPUT) \t... \033[0m]"
	@$(GCC) $(STD) $(SRC)  $(LIB) -o BIN/$(OUTPUT)
	@echo "[ \033[32mGENERATE BINARY : \t DONE. \033[0m]"

local_FR : 
	@echo "[ \033[36mGENERATE LOCALES : FR \t... \033[0m]"
	@msginit --locale=fr --input="assets/Locales/fr_FR/fr_FR.po" --output="assets/Locales/fr_FR/LC_MESSAGES/main.mo" --no-translator
	@echo "[ \033[32mGENERATE LOCALES : \t DONE \033[0m]"

local_ES :
	@echo "[ \033[36mGENERATE LOCALES : ES \t... \033[0m]"
	@msginit --locale=es --input="assets/Locales/es_ES/es_ES.po" --output="assets/Locales/es_ES/LC_MESSAGES/main.mo" --no-translator
	@echo "[ \033[32mGENERATE LOCALES : \t DONE \033[0m]"

clean :
	@echo "[ \033[36mSUPPRESSION BINARY : $(OUTPUT) \t... \033[0m]"
	@rm BIN/$(OUTPUT) -fr
	@echo "[ \033[32mSUPPRESSION BINARY : \t DONE. \033[0m]"
	@echo "[ \033[36mSUPPRESSION LOCALES :  \t... \033[0m]"
	@rm assets/Locales/fr_FR/LC_MESSAGES/main.mo assets/Locales/es_ES/LC_MESSAGES/main.mo -fr
	@echo "[ \033[32mSUPPRESSION LOCALES : \t DONE. \033[0m]"