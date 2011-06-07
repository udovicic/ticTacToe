/*
 *	ai.c
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

#include "ai.h"
#include "game.h"
#include "main.h"

int ai_event( void ) {
	int make_move = -1;
	
	make_move = tryToWin(player);/* if AI can win in next turn, play that move */
	if (make_move==-1) make_move = tryToWin((moves+1)%2+1); /* if player can win in next move, block it */
	if (make_move==-1) make_move = moveSomwhere(); /* play corner, side or center */
	
	field[make_move]=player;
	
	return make_move;
}

int tryToWin( int sym ) {
	int i,j,c,make_move;
	
	/* chek row */
	for (j=0;j<7;j+=3) {
		c=0;
		for (i=j;i<j+3;i++) {
			if (field[i]==0) {
				c++;
				make_move=i;
			}
			if (!(field[i]==sym || field[i]==0)) {
				c=3;
				break;
			}
		}
		if (c==1) return make_move;
	}
	
	/* check col */
	for (j=0;j<3;j++) {
		c=0;
		for (i=j;i<7+j;i+=3) {
			if (field[i]==0) {
				c++;
				make_move=i;
			}
			if (!(field[i]==sym || field[i]==0)) {
				c=3;
				break;
			}
		}
		if (c==1) return make_move;
	}
	
	/* check main diag */
	c=0;
	for (i=0;i<9;i+=4) {
		if (field[i]==0) {
			c++;
			make_move=i;
		}
		if (!(field[i]==sym || field[i]==0)) {
			c=3;
			break;
		}
	}
	if (c==1) return make_move;
	
	/* check anti diag */
	c=0;
	for (i=2;i<7;i+=2) {
		if (field[i]==0) {
			c++;
			make_move=i;
		}
		if (!(field[i]==sym || field[i]==0)) {
			c=3;
			break;
		}
	}
	if (c==1) return make_move;
	
	return -1;
}

int moveSomwhere( void ) { /* play corner, side or center */
	int i, move[] = {0,2,8,6,1,5,7,3,4};
	for (i=0;i<9;i++)
		if (field[ move[i] ] == 0) break;
	
	return move[i];
}
