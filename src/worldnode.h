//----------------------------------------------------------------------
#ifndef _WORLDNODE_HEADER_
#define _WORLDNODE_HEADER_

/* worldnode.h */
//----------------------------------------------------------------------
class WorldNode {
protected:
	int _tiles[15][20];
	PlayerEntity* _player;

public:
	virtual void update(void);
	virtual void draw(void);

	PlayerEntity* getPlayer(void);
	SpriteTag getTile(int i, int j);
	virtual SDL_bool canSpawn(int i, int j);
	void addPlayerEntity(PlayerEntity* player);
};

/* worldnode.cpp */
//----------------------------------------------------------------------
void WorldNode::update(void) {
	_player->update();
}

void WorldNode::draw(void) {
	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
	}

	_player->draw();

	Sprite* spr;

	// heart near top
	SDL_Rect gui_rect = {8, 8, 16, 16};
	spr = SprManager::getRef().getSprite(HEART_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	// bar at bottom
	gui_rect.x = 8; gui_rect.y = 24;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_00);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_02);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	// inventory
	gui_rect.y -= 16+2; gui_rect.x += 16*15;
	spr = SprManager::getRef().getSprite(FRAME_TILE_09);

	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	gui_rect.y += 16+4;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	for(int i=0; i<5; i++) {
		gui_rect.y -= 16+4; gui_rect.x -= 16+4;
		SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
		gui_rect.y += 16+4;
		SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	}
}

PlayerEntity* WorldNode::getPlayer(void) {
	return _player;
}

SpriteTag WorldNode::getTile(int i, int j) {
	return (SpriteTag) _tiles[j][i];
}

void WorldNode::addPlayerEntity(PlayerEntity* player) {
	_player = player;
}

SDL_bool WorldNode::canSpawn(int i, int j) {
	return SDL_TRUE;
}

#endif
