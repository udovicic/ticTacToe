/*
 *	ai.h
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

#ifndef AI_H
#define AI_H

int ai_event( void );
int tryToWin( int sym );
int tryToBlock( void );
int moveSomwhere( void );

#endif
