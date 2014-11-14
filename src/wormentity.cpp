/* wormentity.cpp */
//----------------------------------------------------------------------
WormEntity::WormEntity(int x, int y): Moveable(x, y, new StraightInput()), Entity(x, y, WORM_TILE_00) {
	((StraightInput*) input)->parent = this;

	weapon = new SandstormEntity(0, 0);
	weapon->active = SDL_FALSE;
}

WormEntity::~WormEntity(void) {
	delete weapon;
}

void WormEntity::draw(void) {
	Sprite* spr = SprManager::getRef().getSprite(_tag);

	_rect.w = spr->w;
	_rect.h = spr->h;

	SDL_Rect rect;
	memcpy(&rect, &_rect, sizeof(SDL_Rect));
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);

	if(weapon->active) weapon->draw();
}

void WormEntity::update(void) {
	Moveable::update();

	if(weapon->active) weapon->update();
	else _tomove = SDL_TRUE;

	SDL_bool check = (SDL_bool) (active&&!_dying);
	if(_attack_next_chance&&!_moving&&!weapon->active&&_attack_delay==0&&check) {

		_tomove = SDL_FALSE;
		_attack_delay = 72;
		_attack_next_chance = SDL_FALSE;

		switch(_movedirec) {
			case 0: weapon->swingUp(_x, _y); break;
			case 1: weapon->swingDown(_x, _y); break;
			case 2: weapon->swingLeft(_x, _y); break;
			case 3: weapon->swingRight(_x, _y); break;
		}
	}
	
	if(_attack_delay>0) _attack_delay--;
	if(input->isDown("a")&&!_attack_next_chance&&_attack_delay==0) {
		_attack_delay = 32;
		_attack_next_chance = SDL_TRUE;
	}

	if(_frame>0) _frame--;
	if(_dying) {
		if(_frame==0&&_tag==SMALLFLAME_TILE_00) {
			_frame = _fpa;
			_tag = SMALLFLAME_TILE_01;
		} else if(_frame==0&&_tag==SMALLFLAME_TILE_01) {
			_frame = _fpa;
			_tag = WORM_TILE_00;

			active = SDL_FALSE;
			_dying = SDL_FALSE;
		}
	} else {
		if(_frame==0&&_tag==WORM_TILE_00) {
			_frame = _fpa;
			_tag = WORM_TILE_01;
		} else if(_frame==0&&_tag==WORM_TILE_01) {
			_frame = _fpa;
			_tag = WORM_TILE_00;
		}
	}

	_rect.x = _x;
	_rect.y = _y;
}

void WormEntity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_dying = SDL_FALSE;
	_tag = WORM_TILE_00;
	Moveable::setPos(x, y);
}

SDL_bool WormEntity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;
	if(_dying) return SDL_FALSE;

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	return (SDL_bool) (
		(
		node->getTile(i,j)==GRASS_TILE_00 ||
		node->getTile(i,j)==SAND_TILE_00  ||
		node->getTile(i,j)==SEA_TILE_00   ||
		node->getTile(i,j)==BRICK_TILE_00
		)
		&&!(i==pi&&j==pj)
	);
}

void WormEntity::hit(int damage) {
	if(_dying) return;

	if(damage>0) {
		_frame = _fpa;
		_dying = SDL_TRUE;
		_tag = SMALLFLAME_TILE_00;
	}
}
