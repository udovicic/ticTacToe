/*
 *	game.c
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
#include "game.h"
 
int game_block( void ) { 
   SDL_PollEvent(&event);
   if (event.type == SDL_QUIT ) return 0;
   if (event.key.keysym.sym == SDLK_ESCAPE ) return 0;
   return 1;   
}

void init_game( void ) {
	int i;
	for (i=0;i<9;i++) field[i]=0;
	
	drop_dead=0;
	player=1;
	moves=0;
}

int game_alive( void ) {
	if (drop_dead) return 0;
	return 1;
}

int player_event( void ) {
	int i=-1;
	while (i==-1) {
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {drop_dead=1; i--;};
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				i=event.button.x/200;
				i=i + ((event.button.y/200)*3);
				if (field[i]==0) {
					field[i]=player;
					moves++;
					drop_dead = check_end(i);
				}
			}
		}
	}
	return i;
}

int check_end( int last_move ) {
	int i;
	
	for (i=last_move-last_move%3; i<last_move+(3-last_move%3); i++) /* check row */
		if (field[i]!=player) break;
	if (i==last_move+(3-last_move%3)) return 1;
	
	for (i=last_move%3; i<9; i+=3) /* check col */
		if (field[i]!=player) break;
	if (i>=9) return 1;
	
	for (i=0;i<9;i+=4) /* check main diag */
		if (field[i]!=player) break;
	if (i>9) return 1;
	
	for (i=2;i<7;i+=2) /* chek anti diag */
		if (field[i]!=player) break;
	if (i>7) return 1;
		
	if (moves==9) return 2; /* no more moves? */
	
	return 0;
}
void game_doMagic( void ) {
	
}
