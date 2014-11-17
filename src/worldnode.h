//----------------------------------------------------------------------
#ifndef _WORLDNODE_HEADER_
#define _WORLDNODE_HEADER_

/* worldnode.h */
//----------------------------------------------------------------------
class WorldNode {
protected:
	int _tiles[15][20];
	PlayerEntity* _player;

	void _drawGUI(void);

public:
	virtual void update(void);
	virtual void draw(void);

	PlayerEntity* getPlayer(void);
	SpriteTag getTile(int i, int j);
	virtual SDL_bool canSpawn(int i, int j);
	virtual Entity* getEntityAt(int i, int j);
	void addPlayerEntity(PlayerEntity* player);
};

/* worldnode.cpp */
//----------------------------------------------------------------------
void WorldNode::update(void) {
	_player->update();
}

void WorldNode::_drawGUI(void) {
	// GUI
	for(int j=0; j<3; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
	}

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
	gui_rect.y -= 16; gui_rect.x += 16*7-8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_09);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("Bag", gui_rect.x+16*4, gui_rect.y+18+8);

	gui_rect.x += 8; gui_rect.y += 8;
	for(int i=0; i<7; i++) {
		spr = SprManager::getRef().getSprite(_player->inventory[i]);
		SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
		gui_rect.x += 16+4;
	}

	// equiped frames
	gui_rect.x = 64+16;
	gui_rect.y = 8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_0A);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	gui_rect.x += 4;
	gui_rect.y += 8;
	spr = SprManager::getRef().getSprite(SHIELD_TILE_00);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("A", gui_rect.x+4, gui_rect.y+18);

	gui_rect.x = 64+16+16+16;
	gui_rect.y -= 8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_0A);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	gui_rect.x += 4;
	gui_rect.y += 8;
	spr = SprManager::getRef().getSprite(ATTACK_TILE_02);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("B", gui_rect.x+4, gui_rect.y+18);
}

void WorldNode::draw(void) {
	for(int j=3; j<15; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
	}

	_player->draw();
	_drawGUI();
}

PlayerEntity* WorldNode::getPlayer(void) {
	return _player;
}

SpriteTag WorldNode::getTile(int i, int j) {
	return (SpriteTag) _tiles[j][i];
}

Entity* WorldNode::getEntityAt(int i, int j) {
	return NULL;
}

void WorldNode::addPlayerEntity(PlayerEntity* player) {
	_player = player;
}

SDL_bool WorldNode::canSpawn(int i, int j) {
	return SDL_TRUE;
}

#endif
