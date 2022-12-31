GCC=g++
STD=-std=c++11

LIB= -L -lsfml -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

OUTPUT=rpg


SRC=\
	app/src/main.cpp \
	app/src/Game.cpp \
	app/src/State.cpp \
	app/States/GameState.cpp \
	app/States/MainMenuState.cpp \
	app/Entities/Entity.cpp \
	app/Entities/Player.cpp \
	app/Ressource/Button.cpp \
	app/Components/MovementComponent.cpp \
	app/Components/AnimationComponent.cpp
	

all : rpg

rpg	:
	$(GCC) $(STD) $(SRC) $(LIB) -o BIN/$(OUTPUT)

clean :
	@echo "Suppresion de $(OUTPUT)"
	@rm BIN/$(OUTPUT)