##HERE i go
##Ups cap
CC = gcc
CFLAGS = -lstdc++ -c #-Wall 
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
all: 

main: main.o Game.o 
	$(CC) $(SFML_FLAGS)  main.o Game.o -o main.out -lstdc++
#game: Game.o
#	$(CC) Game.o -o Game.out $(SFML_FLAGS) -lstdc++
sec: second.o interface_class.o cursor_class.o
	$(CC) $(SFML_FLAGS) -lstdc++ interface_class.o cursor_class.o second.o -o second.out 
clean: 
	rm *.out *.o

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS)
Game.o: Game.cpp Game.h
	$(CC) Game.cpp $(CFLAGS)
second.o: second.cpp
	$(CC) second.cpp $(CFLAGS) $(SFML_FLAGS)
interface_class.o: interface_class.cpp interface_class.h
	$(CC) interface_class.cpp $(CFLAGS) $(SFML_FLAGS)
cursor_class.o: cursor_class.h cursor_class.cpp
	$(CC) cursor_class.cpp $(CFLAGS) $(SFML_FLAGS)

