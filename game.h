/*
 *	game.h
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

#ifndef GAME_H
#define GAME

#include <SDL/SDL.h>

SDL_Event event;
int drop_dead, /* for end game event */
	player, /* current player */
	moves, /* count moves */
	field[9]; /* battlefield */
 
void init_game( void );
int game_block( void );
int game_alive( void );
void game_event( void );
void game_doMagic( void );
int check_end( int last_move );

#endif
