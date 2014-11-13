//----------------------------------------------------------------------
#ifndef _SANDSTORMENTITY_HEADER_
#define _SANDSTORMENTITY_HEADER_

/* sandstormentity.h */
//----------------------------------------------------------------------
class SandstormEntity: public WeaponEntity {
protected:
	int _fpa = 16;
	int _frame = 16;

public:
	SandstormEntity(int x, int y);

	void update(void);
	void draw(void);

	void swingUp(int x, int y);
	void swingDown(int x, int y);
	void swingLeft(int x, int y);
	void swingRight(int x, int y);
};

/* sandstormentity.cpp */
//----------------------------------------------------------------------
SandstormEntity::SandstormEntity(int x, int y): WeaponEntity(x, y, DUSTCLOUD_TILE_00) {
	// nothing
}

void SandstormEntity::update(void) {
	_i = floor(_rect.x/16.0f);
	_j = floor(_rect.y/16.0f);

	if(_frame>0) _frame--;
	if(_tag==DUSTCLOUD_TILE_00&&_frame==0) {
		_frame = _fpa;
		_tag = DUSTCLOUD_TILE_01;
	} else if(_tag==DUSTCLOUD_TILE_01&&_frame==0) {
		_frame = _fpa;
		_tag = DUSTCLOUD_TILE_00;
		active = SDL_FALSE;
		canmove = SDL_TRUE;
	}
}

void SandstormEntity::draw(void) {
	Sprite* spr = SprManager::getRef().getSprite(_tag);

	_rect.w = spr->w;
	_rect.h = spr->h;

	SDL_Rect rect;
	memcpy(&rect, &_rect, sizeof(SDL_Rect));
	//SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x -= 16;
	rect.y -= 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.y += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x -= 32;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.y += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);
}

void SandstormEntity::swingUp(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_tag = DUSTCLOUD_TILE_00;
}

void SandstormEntity::swingDown(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_tag = DUSTCLOUD_TILE_00;
}

void SandstormEntity::swingLeft(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_tag = DUSTCLOUD_TILE_00;
}

void SandstormEntity::swingRight(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_tag = DUSTCLOUD_TILE_00;
}

#endif
