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
	// nothing
}

void WorldNode::draw(void) {
	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
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
