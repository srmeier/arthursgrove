/* bugentity.cpp */
//----------------------------------------------------------------------
BugEntity::BugEntity(int x, int y): Moveable(x, y, new RandomInput()), Entity(x, y, SpriteID::BUG00) {
	// nothing
}

void BugEntity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;

	if(_dying) {
		if(_frame==0&&_id==SpriteID::SMALLFLAME00) {
			_frame = _fpa;
			_id = SpriteID::SMALLFLAME01;
		} else if(_frame==0&&_id==SpriteID::SMALLFLAME01) {
			_frame = _fpa;
			_id = SpriteID::BUG00;

			active = SDL_FALSE;
			_dying = SDL_FALSE;
		}
	} else {
		if(_frame==0&&_id==SpriteID::BUG00) {
			_frame = _fpa;
			_id = SpriteID::BUG01;
		} else if(_frame==0&&_id==SpriteID::BUG01) {
			_frame = _fpa;
			_id = SpriteID::BUG00;
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
	_id = SpriteID::BUG00;
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
		node->getTile(i,j)==SpriteID::GRASS00 ||
		node->getTile(i,j)==SpriteID::SAND00  ||
		node->getTile(i,j)==SpriteID::SEA00   ||
		node->getTile(i,j)==SpriteID::BRICK00
		)
		&&!(i==pi&&j==pj)
	);
}

void BugEntity::hit(int damage) {
	if(_dying) return;

	if(damage>0) {
		_frame = _fpa;
		_dying = SDL_TRUE;
		_id = SpriteID::SMALLFLAME00;
	}
}
