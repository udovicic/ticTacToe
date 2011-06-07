/*
 *	main.c
 * 
 *	Copyright 2011 Stjepan Udovičić <udovicic.stjepan@gmail.com>
 *	      
 *	This file is part of TicTacToe.
 *
 *	TicTacToe is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	TicTacToe is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with TicTacToe.  If not, see <http://www.gnu.org/licenses/>.
 */	 
           
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "graphics.h"
#include "game.h"
#include "ai.h"
#include "main.h"

int main( int nargs, char *args[] ) {
	
	int nAI, last_move;
	char *program;
	/* licence info */
	printf("TicTacToe is free software: you can redistribute it and/or modify "
			"it under the terms of the GNU General Public License as published by "
			"the Free Software Foundation, either version 3 of the License, or "
			"(at your option) any later version.\n"
			"Source code available at http://code.udovicic.org/tictactoe\n\n");
	
	nAI=0;
	program = args[0];
	/* read program parameters from command line */
	while ((nargs>1) && (args[1][0]=='-')) {
		switch(args[1][1]) {
			case 'a': nAI=atoi(&args[1][2]);break;
			default:
				printf("Usage\n  %s <options>\n"
						"  -a<n>\t\t Number of AI players(0/1/2)\n",program);
				return 0;
				break;
		}
		
		nargs--;
		args++;
	}
	
	/* begin game with SDL */
	if (init_graphics()) {
		go_away();
		return 1;
	}
	
	/* init game variables */
	init_game();

	/* game loop */
	while(game_alive()) {
		draw(); /* draw screen */
		if ((player==0 && nAI!=0) || (nAI==2) )
			last_move=ai_event();
		else
			last_move=player_event();
			
		check_end( last_move ); /* wait for player input and check end */
		player=moves%2+1; /* change current player */
	}
	
	if (game_alive()==2) /* game draw */
		notify("- GAME DRAW -");
	else /* report winner */
		if (player==1)
			notify("O win!");
		else
			notify("X win!");
			
	/* exit loop */
	while (game_block());
	
	go_away(); 
	return 0;
}

void go_away( void ) {
	SDL_Quit();
	TTF_Quit();
}
