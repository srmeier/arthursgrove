/*
g++ -g -std=c++11 -static-libgcc -static-libstdc++ main.cpp -o arthursgrove.exe -I./src -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
- for polymorphism make sure to use "virtual"
- whenever a new "overworld" is added the player.cpp needs updating
	- so too does rock00entity.cpp
	- so too does chest and barrel
*/

/*
% === %
- the node is responsible for dealing out all the damage? :/

% === %
- the b key press doesn't register while the sword is swinging because moveable
	is only updated if the player can move (and input is linked to moveable
	which sets the keys)
- player can definitely move through NPCs, probably due to location indices not
	updating until the player is already moving
*/

//-----------------------------------------------------------------------------
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//-----------------------------------------------------------------------------
#include "engine.h"
#include "resourcemanager.h"

//-----------------------------------------------------------------------------
#include "input.h"
#include "drawable.h"
#include "moveable.h"

//-----------------------------------------------------------------------------
#include "playerinput.h"
#include "randominput.h"
#include "straightinput.h"

//-----------------------------------------------------------------------------
#include "entity.h"
#include "moveableentity.h"
#include "weaponentity.h"
#include "swordentity.h"
#include "tsunamientity.h"
#include "playerentity.h"
#include "npcentity.h"
#include "sandstormentity.h"
#include "bugentity.h"
#include "npc00entity.h"
#include "npc01entity.h"
#include "npc02entity.h"
#include "npc03entity.h"
#include "rock00entity.h"
#include "signentity.h"
#include "barrelentity.h"
#include "chestentity.h"
#include "wormentity.h"
#include "bossentity.h"

//-----------------------------------------------------------------------------
#include "worldnode.h"
#include "overworld.h"
#include "dungeon00.h"
#include "puzzle00.h"

//-----------------------------------------------------------------------------
#include "overworld/node00.cpp"
#include "overworld/node0A.cpp"
#include "dungeon00/d00node00.cpp"
#include "dungeon00/d00node01.cpp"
#include "puzzle00/p00node00.cpp"

//-----------------------------------------------------------------------------
#include "sandstormentity.cpp"
#include "straightinput.cpp"
#include "tsunamientity.cpp"
#include "playerentity.cpp"
#include "bugentity.cpp"
#include "npc00entity.cpp"
#include "npc01entity.cpp"
#include "npc02entity.cpp"
#include "npc03entity.cpp"
#include "rock00entity.cpp"
#include "signentity.cpp"
#include "barrelentity.cpp"
#include "chestentity.cpp"
#include "wormentity.cpp"
#include "bossentity.cpp"

//-----------------------------------------------------------------------------
int SDL_main(int argc, char* argv[]) {
	// NOTE: initialize the library and start the game
	startGame();

	/* === */

	Sprite* spr = ResourceManager::getRef().getSprite(SpriteID::ICON);
	SDL_SetWindowIcon(Game.window, spr->tile);

	PlayerEntity player(16*3, 16*5);

	Overworld::getRef().addPlayer(&player);
	Dungeon00::getRef().addPlayer(&player);
	Puzzle00::getRef().addPlayer(&player);

	/* === */

	while(Game.running) {
		// NOTE: clear the renderer and screen
		SDL_RenderClear(Game.renderer);
		SDL_FillRect(Game.gfx.screen, 0, 0x00);

		/* === */

		switch(Game.state) {
			case 0x00: {
				/* === */
				Overworld::getRef().updateNode();
				Overworld::getRef().drawNode();
				/* === */
			} break;

			case 0x01: {
				/* === */
				Dungeon00::getRef().updateNode();
				Dungeon00::getRef().drawNode();
				/* === */
			} break;

			case 0x02: {
				/* === */
				Puzzle00::getRef().updateNode();
				Puzzle00::getRef().drawNode();
				/* === */
			} break;
		}

		if(Game.won) {
			SDL_FillRect(Game.gfx.screen, 0, 0x00);
			SDL_Color color = {0xFF,0xFF,0xFF};
			drawText("You Win!", SCREEN_W/2-32-4, SCREEN_H/2-32, color);
		}

		if(player.health==0) {
			SDL_FillRect(Game.gfx.screen, 0, 0x00);
			SDL_Color color = {0xFF,0xFF,0xFF};
			drawText("Game Over!", SCREEN_W/2-32-4, SCREEN_H/2-32, color);
		}

		/* === */

		int pitch;
		void *pixels;

		// NOTE: get the pixels to the streaming texture
		SDL_LockTexture(Game.gfx.texture, NULL, &pixels, &pitch);

		// NOTE: update the pixels on the texture
		SDL_ConvertPixels(
			Game.gfx.screen->w,
			Game.gfx.screen->h,
			Game.gfx.screen->format->format,
			Game.gfx.screen->pixels,
			Game.gfx.screen->pitch,
			SDL_PIXELFORMAT_RGBA8888,
			pixels, pitch
		);

		// NOTE: unlock the texture for drawing
		SDL_UnlockTexture(Game.gfx.texture);

		// NOTE: render the texture to the screen
		SDL_RenderCopy(Game.renderer, Game.gfx.texture, NULL, NULL);
		SDL_RenderPresent(Game.renderer);
	}

	/* === */



	/* === */

	// NOTE: release the libraries and free global resources
	quitGame();
	return 0;
}
