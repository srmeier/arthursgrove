/* sandstormentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
SandstormEntity::SandstormEntity(int x, int y): WeaponEntity(x, y, SpriteID::DUSTCLOUD00) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::update(void) {
	_i = floor(_rect.x/16.0f);
	_j = floor(_rect.y/16.0f);

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	if(_i-1==pi&&_j-1==pj)
		player->hit(1);
	if(_i+0==pi&&_j-1==pj)
		player->hit(1);
	if(_i+1==pi&&_j-1==pj)
		player->hit(1);

	if(_i-1==pi&&_j+1==pj)
		player->hit(1);
	if(_i+0==pi&&_j+1==pj)
		player->hit(1);
	if(_i+1==pi&&_j+1==pj)
		player->hit(1);

	if(_i-1==pi&&_j+0==pj)
		player->hit(1);
	if(_i+1==pi&&_j+0==pj)
		player->hit(1);

	if(_frame>0) _frame--;
	if(_id==SpriteID::DUSTCLOUD00&&_frame==0) {
		_frame = _fpa;
		_id = SpriteID::DUSTCLOUD01;
	} else if(_id==SpriteID::DUSTCLOUD01&&_frame==0) {
		_frame = _fpa;
		_id = SpriteID::DUSTCLOUD00;
		active = SDL_FALSE;
		canmove = SDL_TRUE;
	}
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::draw(void) {
	Sprite* spr = ResourceManager::getRef().getSprite(_id);

	_rect.w = spr->w;
	_rect.h = spr->h;

	SDL_Rect rect;
	memcpy(&rect, &_rect, sizeof(SDL_Rect));
	//SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	rect.x -= 16;
	rect.y -= 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.y += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.x -= 32;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.y += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);

	rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::swingUp(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_id = SpriteID::DUSTCLOUD00;
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::swingDown(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_id = SpriteID::DUSTCLOUD00;
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::swingLeft(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_id = SpriteID::DUSTCLOUD00;
}

//-----------------------------------------------------------------------------
/*
*/
void SandstormEntity::swingRight(int x, int y) {
	setPos(x, y);
	canmove = SDL_FALSE;
	_id = SpriteID::DUSTCLOUD00;
}
