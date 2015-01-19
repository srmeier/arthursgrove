/* tsunamientity.cpp */
//----------------------------------------------------------------------
TsunamiEntity::TsunamiEntity(int x, int y): WeaponEntity(x, y, SpriteID::TSUNAMI00) {
	// nothing
}

void TsunamiEntity::update(void) {
	_i = floor((_rect.x+8.0f)/16.0f);
	_j = floor((_rect.y+8.0f)/16.0f);

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	if(!(
		node->getTile(_i,_j)==SpriteID::SEA00||
		node->getTile(_i,_j)==SpriteID::SEA01||
		node->getTile(_i,_j)==SpriteID::SEA02||
		node->getTile(_i,_j)==SpriteID::SEA03||
		node->getTile(_i,_j)==SpriteID::SEA04||
		node->getTile(_i,_j)==SpriteID::SEA05||
		node->getTile(_i,_j)==SpriteID::SEA06||
		node->getTile(_i,_j)==SpriteID::SEA07||
		node->getTile(_i,_j)==SpriteID::SEA08||
		node->getTile(_i,_j)==SpriteID::SEA09||
		node->getTile(_i,_j)==SpriteID::SEA0A||
		node->getTile(_i,_j)==SpriteID::SEA0B
	)) active = SDL_FALSE;

	if(_frame>0) _frame--;
	if(_frame==0&&_id==SpriteID::TSUNAMI00) {
		_frame = _fpa;
		_id = SpriteID::TSUNAMI01;
	} else if(_frame==0&&_id==SpriteID::TSUNAMI01) {
		_frame = _fpa;
		_id = SpriteID::TSUNAMI00;
	}

	switch(_direc) {
		case 0: _rect.y -= 1; break;
		case 1: _rect.y += 1; break;
		case 2: _rect.x -= 1; break;
		case 3: _rect.x += 1; break;
	}
}

void TsunamiEntity::swingUp(int x, int y) {
	_direc = 0;
	setPos(x, y-8*2);
	_id = SpriteID::TSUNAMI00;
}

void TsunamiEntity::swingDown(int x, int y) {
	_direc = 1;
	setPos(x, y+8*2);
	_id = SpriteID::TSUNAMI00;
}

void TsunamiEntity::swingLeft(int x, int y) {
	_direc = 2;
	setPos(x-8*2, y);
	_id = SpriteID::TSUNAMI00;
}

void TsunamiEntity::swingRight(int x, int y) {
	_direc = 3;
	setPos(x+8*2, y);
	_id = SpriteID::TSUNAMI00;
}
