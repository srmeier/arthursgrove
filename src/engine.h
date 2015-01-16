//-----------------------------------------------------------------------------
#ifndef _ENGINE_HEADER_
#define _ENGINE_HEADER_

//-----------------------------------------------------------------------------
#define SPRITE_W 8
#define SPRITE_H 8
#define SCREEN_W 320 // 40 -> 20
#define SCREEN_H 240 // 30 -> 15
#define NUM_TILES (1024+1)
#define SCREEN_NAME "Prototype"
#define SCREEN_SCALE 2

//-----------------------------------------------------------------------------
typedef struct {
	int w, h;
	SDL_Surface* tile;
} Sprite;

//-----------------------------------------------------------------------------
struct {
	bool running;
	uint8_t state;
	SDL_Window* window;
	SDL_Renderer* renderer;
	struct {
		TTF_Font* font6;
		TTF_Font* font8;
		SDL_Surface* screen;
		SDL_Texture* texture;
		SDL_Surface* tiles[NUM_TILES];
	} gfx;
} Game = {};

//-----------------------------------------------------------------------------
void startGame(void) {
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0) {
		fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
		exit(-1);
	}

	if(TTF_Init()==-1) {
		fprintf(stderr, "TTF_Init: %s\n", TTF_GetError());
		exit(-1);
	}

	Game.window = SDL_CreateWindow(
		SCREEN_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_SCALE*SCREEN_W,
		SCREEN_SCALE*SCREEN_H,
		0
	);

	Game.renderer = SDL_CreateRenderer(
		Game.window, -1,
		SDL_RENDERER_ACCELERATED|
		SDL_RENDERER_PRESENTVSYNC
	);

	SDL_RendererInfo tempRenInfo;

	SDL_GetRendererInfo(Game.renderer, &tempRenInfo);
	if(!(tempRenInfo.flags & SDL_RENDERER_PRESENTVSYNC)) {
		fprintf(stderr, "SDL_CreateRenderer: failed to set Vsync.\n");
		exit(-1);
	}

	Game.gfx.screen = SDL_CreateRGBSurface(0, SCREEN_W, SCREEN_H, 32, 0x00, 0x00, 0x00, 0x00);

	Game.gfx.texture = SDL_CreateTexture(
		Game.renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		Game.gfx.screen->w,
		Game.gfx.screen->h
	);

	Game.gfx.font6 = TTF_OpenFont("SDS_6x6.ttf", 8);
	Game.gfx.font8 = TTF_OpenFont("SDS_8x8.ttf", 8);

	SDL_Surface* tempSurface = SDL_LoadBMP("spritesheet.bmp");

	int i, x, y;
	SDL_Rect tempRect = {0, 0, SPRITE_W, SPRITE_H};
	for(i=0; i<NUM_TILES; i++) {
		Game.gfx.tiles[i] = SDL_CreateRGBSurface(0, SPRITE_W, SPRITE_H, 24, 0x00, 0x00, 0x00, 0x00);
		if(i!=0) {
			x = (i-1)%(tempSurface->w/SPRITE_W);
			y = (i-x)/(tempSurface->w/SPRITE_W);
			tempRect.x = SPRITE_W*x, tempRect.y = SPRITE_H*y;
			SDL_BlitSurface(tempSurface, &tempRect, Game.gfx.tiles[i], NULL);
		}
	}

	SDL_FreeSurface(tempSurface);
	tempSurface = NULL;

	srand(time(NULL));
	Game.running = SDL_TRUE;
}

//-----------------------------------------------------------------------------
void quitGame(void) {
	int i;
	for(i=0; i<NUM_TILES; i++) {
		SDL_FreeSurface(Game.gfx.tiles[i]);
		Game.gfx.tiles[i] = NULL;
	}

	TTF_CloseFont(Game.gfx.font6);
	Game.gfx.font6 = NULL;

	TTF_CloseFont(Game.gfx.font8);
	Game.gfx.font8 = NULL;

	SDL_DestroyTexture(Game.gfx.texture);
	Game.gfx.texture = NULL;

	SDL_FreeSurface(Game.gfx.screen);
	Game.gfx.screen = NULL;

	SDL_DestroyRenderer(Game.renderer);
	Game.renderer = NULL;

	SDL_DestroyWindow(Game.window);
	Game.window = NULL;

	TTF_Quit();

	SDL_Quit();
}

//-----------------------------------------------------------------------------
Sprite* buildSprite(int w, int h, int inds[]) {
	Sprite* spr = (Sprite*)malloc(sizeof(Sprite));

	spr->w = w;
	spr->h = h;

	spr->tile = SDL_CreateRGBSurface(0, SPRITE_W*w, SPRITE_H*h, 24, 0x00, 0x00, 0x00, 0x00);

	SDL_SetColorKey(spr->tile, 1, 0xFF00FF);
	SDL_FillRect(spr->tile, 0, 0xFF00FF);

	SDL_Rect rect = {0, 0, SPRITE_W, SPRITE_H};
	for(int j=0; j<h; j++) {
		for(int i=0; i<w; i++) {
			rect.x = SPRITE_W*i, rect.y = SPRITE_H*j;
			SDL_BlitSurface(Game.gfx.tiles[inds[w*j+i]], NULL, spr->tile, &rect);
		}
	}

	return spr;
}

//-----------------------------------------------------------------------------
void freeSprite(Sprite* spr) {
	spr->w = 0;
	spr->h = 0;

	SDL_FreeSurface(spr->tile);
	spr->tile = NULL;
}

//-----------------------------------------------------------------------------
void drawText(const char* str, int x, int y, SDL_Color color, int size = 8) {
	if(!str) return;

	SDL_Surface* text;
	if(size==6) text = TTF_RenderText_Solid(Game.gfx.font6, str, color);
	else text = TTF_RenderText_Solid(Game.gfx.font8, str, color);

	SDL_Rect rect = {x, y, text->w, text->h};
	SDL_BlitSurface(text, NULL, Game.gfx.screen, &rect);

	SDL_FreeSurface(text);
}

#endif
