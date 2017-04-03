##HERE i go
##Ups cap
CC = gcc
CFLAGS = -lstdc++ -Wall -c
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
all: 

main: main.o Game.o 
	$(CC) main.o Game.o -o main.out $(SFML_FLAGS) -lstdc++
#game: Game.o
#	$(CC) Game.o -o Game.out $(SFML_FLAGS) -lstdc++
sec: second.o
	$(CC) second.o -o second.out $(SFML_FLAGS) -lstdc++
clean: 
	rm *.out *.o

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS)
Game.o: Game.cpp Game.h
	$(CC) Game.cpp $(CFLAGS)
second.o: second.cpp
	$(CC) second.cpp $(CFLAGS)
