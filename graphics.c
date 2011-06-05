/*
 *	graphics.c
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
#include <SDL/SDL_image.h>
#include <stdio.h>
#include "graphics.h"
#include "game.h"
   
/* init SDL graphics */
int init_graphics(void) {
	
	/* init SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		perror("Faile to init SDL");
		return 1;
	}
   
	/* init font */
	if (TTF_Init()<0) {
		perror("Failed to init font");
		return 1;
	}      
	
	/* init display */
	if ((disp = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE)) == NULL) {
		perror("Can't open display");
		return 1;
	}
	SDL_WM_SetCaption("TicTacToe","resources/icon.ico");
   
	/* load sprites */
	if (load_sprites()==1) {
		return 1;
	}   
  
	return 0;
}

/* load sprites */
int load_sprites(void) {
	rS.w=200;rS.h=200;
	
	x = IMG_Load("resources/x.png");
	if (x != NULL) {
		SDL_SetColorKey(x,SDL_SRCCOLORKEY | SDL_RLEACCEL,SDL_MapRGB(x->format,255,0,255));
	} else {
		perror("Unable to open fog sprite");
		return 1;
	}
	
	o = IMG_Load("resources/o.png");
	if (x != NULL) {
		SDL_SetColorKey(o,SDL_SRCCOLORKEY | SDL_RLEACCEL,SDL_MapRGB(o->format,255,0,255));
	} else {
		perror("Unable to open fog sprite");
		return 1;
	}
	
	back = IMG_Load("resources/grid.png");
	if (back != NULL) {
		rB.x=0;rB.y=0;
		rB.w=600;rB.h=600;
	} else {
		perror("Unable to open fog sprite");
		return 1;
	}
	
	font = TTF_OpenFont("resources/font.ttf",30);
	if (font == NULL) {
		perror("Unable to open font");
		return 1;
	}
   
	return 0;
}


int notify(char * msg) {
   SDL_Color text_color = {80,80,80};
   SDL_Rect rect;
   message = TTF_RenderText_Solid(font, msg, text_color);

   if (message == NULL) {
      perror("TTF_RenderText_Solid() Failed");
      return 1;
   }
   rect.x = 150;
   rect.y = 250;
   draw();
   SDL_BlitSurface(message,NULL,disp,&rect);
   SDL_Flip(disp);
   
   return 0;
}

void draw( void ) {
	int i;
	
	SDL_BlitSurface(back,NULL,disp,&rB);
	for (i=0;i<9;i++) {
		if (field[i]) {
			rS.x=200*(i%3);
			rS.y=200*(i/3);
			if (field[i]==1) SDL_BlitSurface(x,NULL,disp,&rS);
			else SDL_BlitSurface(o,NULL,disp,&rS);
		}
	}
	SDL_Flip(disp);
}
