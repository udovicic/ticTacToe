SRCS = main.c graphics.c game.c ai.c
HEADS = graphics.h game.h ai.h
OBJS = main.o graphics.o game.o ai.o
TRGT = ticTacToe

CC = gcc
CFLAGS = -g -pedantic -Wall -c $(SRCS) `sdl-config --cflags`
LFLAGS = -o $(TRGT) `sdl-config --libs` -lSDL_image -lSDL_ttf

$(TRGT): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)

$(OBJS): $(SRCS) $(HEADS)
	$(CC) $(CFLAGS) $(SRCS)

clean mrproper:
	rm $(OBJS) $(TRGT)
