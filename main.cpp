/*
g++ -g -std=c++11 main.cpp -o test.exe -I./src -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
git commit -m "---"
git push
*/

/*
- for polymorphism make sure to use "virtual"
- interactable entity
	overworld->iteractWith(i,j) (within PlayerEntity->canMove)
*/

//----------------------------------------------------------------------
#define SCREEN_W 320 // 40 -> 20
#define SCREEN_H 240 // 30 -> 15
#define NUM_SPRITES 76
#define SCREEN_NAME "Prototype"
#define SCREEN_SCALE 2

//----------------------------------------------------------------------
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//----------------------------------------------------------------------
#include "typedefs.h"
#include "sprmanager.h"

#include "input.h"
#include "playerinput.h"
#include "randominput.h"

#include "moveable.h"
#include "drawable.h"

#include "entity.h"
#include "weaponentity.h"
#include "swordentity.h"
#include "tsunamientity.h"
#include "playerentity.h"
#include "bugentity.h"

#include "worldnode.h"
#include "overworld.h"

#include "playerentity.cpp"
#include "bugentity.cpp"
#include "tsunamientity.cpp"

//----------------------------------------------------------------------
SDL_bool      running  = SDL_TRUE;
SDL_Window*   window   = NULL;
SDL_Surface*  screen   = NULL;
SDL_Renderer* renderer = NULL;

//----------------------------------------------------------------------
int gamestate = 0;

//----------------------------------------------------------------------
int SDL_main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	srand(time(NULL));
	TTF_Init();

	window = SDL_CreateWindow(
		SCREEN_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_SCALE*SCREEN_W,
		SCREEN_SCALE*SCREEN_H,
		0
	);

	renderer = SDL_CreateRenderer(
		window, -1,
		SDL_RENDERER_ACCELERATED|
		SDL_RENDERER_PRESENTVSYNC
	);

	screen = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H, 24, 0x00, 0x00, 0x00, 0x00);
	SDL_SetColorKey(screen, 1, 0xFF00FF);
	SDL_FillRect(screen, 0, 0xFF00FF);

	/* === */

	PlayerEntity player(16*5, 16*5);
	Overworld::getRef().addPlayer(&player);

	TTF_Font* font = TTF_OpenFont("SDS_8x8.ttf", 8);
	SDL_Color color = {0xFF, 0xFF, 0xFF, 0x00};

	SDL_Surface* text = TTF_RenderText_Solid(font, "123456789ABCDEF123456789ABCDEF12345678", color);
	SDL_Rect rect = {8, 8, text->w, text->h};
	SDL_Rect rect0 = {8, 16, text->w, text->h};
	SDL_Rect rect1 = {8, 16+8, text->w, text->h};
	SDL_Rect rect2 = {8, 16+16, text->w, text->h};

	/* === */

	while(running) {
		SDL_RenderClear(renderer);
		SDL_FillRect(screen, 0, 0xFF00FF);

		/* === */

		switch(gamestate) {
			case 0: {
				Overworld::getRef().updateNode();
				player.update();

				Overworld::getRef().drawNode();
				player.draw();
			} break;

			case 1: {
			} break;
		}

		SDL_BlitSurface(text, NULL, screen, &rect);
		SDL_BlitSurface(text, NULL, screen, &rect0);
		SDL_BlitSurface(text, NULL, screen, &rect1);
		SDL_BlitSurface(text, NULL, screen, &rect2);

		/* === */

		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, screen);
		SDL_RenderCopy(renderer, tex, NULL, NULL);

		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tex);
	}

	/* === */

	SDL_FreeSurface(text);
	TTF_CloseFont(font);

	/* === */

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	TTF_Quit();
	SDL_Quit();
	return 0;
}
