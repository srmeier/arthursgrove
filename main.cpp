/*
g++ -g -std=c++11 main.cpp -o test.exe -I./src -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
.\test.exe

git status
git add .
git commit -m "---"
git push
*/

/*
- need to npc
- need to add more enemies!
- for polymorphism make sure to use "virtual"
*/

//----------------------------------------------------------------------
#define SCREEN_W 320 // 40 -> 20
#define SCREEN_H 240 // 30 -> 15
#define NUM_SPRITES 114
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
#include "drawable.h"
#include "moveable.h"

#include "playerinput.h"
#include "randominput.h"
#include "straightinput.h"

#include "entity.h"
#include "weaponentity.h"
#include "swordentity.h"
#include "sandstormentity.h"
#include "tsunamientity.h"
#include "playerentity.h"
#include "bugentity.h"
#include "wormentity.h"

#include "worldnode.h"
#include "overworld.h"

#include "straightinput.cpp"
#include "tsunamientity.cpp"
#include "playerentity.cpp"
#include "bugentity.cpp"
#include "wormentity.cpp"

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

	/* === */

	while(running) {
		SDL_RenderClear(renderer);
		SDL_FillRect(screen, 0, 0xFF00FF);

		/* === */

		switch(gamestate) {
			case 0: {
				Overworld::getRef().updateNode();
				Overworld::getRef().drawNode();
			} break;

			case 1: {
			} break;
		}

		/* === */

		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, screen);
		SDL_RenderCopy(renderer, tex, NULL, NULL);

		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tex);
	}

	/* === */
	/* === */

	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
	return 0;
}
