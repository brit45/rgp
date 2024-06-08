GCC=g++
STD=-std=c++11

LIB= -L -lsfml -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

OUTPUT=rpg


SRC=\
	src/main.cpp \
	src/Game.cpp \
	src/State.cpp \
	States/GameState.cpp \
	States/MainMenuState.cpp \
	Entities/Entity.cpp \
	Entities/Player.cpp \
	Ressource/Button.cpp \
	Components/MovementComponent.cpp
	

.PHONY: all rpg clean

all : BIN BIN/rpg

BIN/rpg	:
	$(GCC) $(STD) $(SRC) $(LIB) -o BIN/$(OUTPUT)

clean :
	@echo "Suppresion de $(OUTPUT)"
	@rm BIN/$(OUTPUT)

BIN:

	@mkdir -p BIN
