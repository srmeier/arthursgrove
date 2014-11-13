/* bugentity.cpp */
//----------------------------------------------------------------------
BugEntity::BugEntity(int x, int y): Moveable(x, y, new RandomInput()), Entity(x, y, BUG_TILE_00) {
	// nothing
}

void BugEntity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;

	if(_dying) {
		if(_frame==0&&_tag==SMALLFLAME_TILE_00) {
			_frame = _fpa;
			_tag = SMALLFLAME_TILE_01;
		} else if(_frame==0&&_tag==SMALLFLAME_TILE_01) {
			_frame = _fpa;
			_tag = BUG_TILE_00;

			active = SDL_FALSE;
			_dying = SDL_FALSE;
		}
	} else {
		if(_frame==0&&_tag==BUG_TILE_00) {
			_frame = _fpa;
			_tag = BUG_TILE_01;
		} else if(_frame==0&&_tag==BUG_TILE_01) {
			_frame = _fpa;
			_tag = BUG_TILE_00;
		}
	}

	_rect.x = _x;
	_rect.y = _y;
}

void BugEntity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_dying = SDL_FALSE;
	_tag = BUG_TILE_00;
	Moveable::setPos(x, y);
}

SDL_bool BugEntity::canMove(int i, int j) {
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

void BugEntity::hit(int damage) {
	if(_dying) return;

	if(damage>0) {
		_frame = _fpa;
		_dying = SDL_TRUE;
		_tag = SMALLFLAME_TILE_00;
	}
}
