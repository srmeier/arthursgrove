/* p00node00.cpp */
//-----------------------------------------------------------------------------
/*
*/
P00Node00::P00Node00(void): WorldNode() {
	int tiles[15][20] = {
		{0x08,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x09},
		{0x0C,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x0D},
		{0x0A,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0B},
		{0x3B,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x37},
		{0x38,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x7E,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x80,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x7D,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x81,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x7D,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x81,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x7D,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x85,0x81,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x38,0x84,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x82,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x38},
		{0x3A,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x39}
	};

	_chestEnt = new ChestEntity(16*3, 16*4, SpriteID::CHEST00);
	_barrelEnt = new BarrelEntity(16*18, 16*13, SpriteID::BARREL00);

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_background[j][i] = tiles[j][i];
		}
	}

	reset();
}

//-----------------------------------------------------------------------------
/*
*/
P00Node00::~P00Node00(void) {
	delete _chestEnt;
	delete _barrelEnt;

	for(int i=0; i<_numRocks; i++) {
		delete _rocks[i];
	}
}

//-----------------------------------------------------------------------------
/*
*/
void P00Node00::update(void) {
	WorldNode::update();

	for(int i=0; i<_numRocks; i++) {
		if(_rocks[i]) _rocks[i]->update();
	}
	
	int pi = _player->getI();
	int pj = _player->getJ();

	if(_background[_player->getJ()][_player->getI()] == SpriteID::LADDER00 && !Puzzle00::getRef().onLadder) {
		Overworld::getRef().onLadder = SDL_TRUE;
		_player->allowMovement();
		_player->input->clear();
		Game.state = 0x00;
		reset();
	} else if(_background[_player->getJ()][_player->getI()] != SpriteID::LADDER00) {
		Puzzle00::getRef().onLadder = SDL_FALSE;
	}

	_chestEnt->update();
	_barrelEnt->update();
}

//-----------------------------------------------------------------------------
/*
*/
void P00Node00::reset(void) {
	for(int i=0; i<_numRocks; i++) {
		delete _rocks[i];
		_rocks[i] = NULL;
	}

	int rocks[15][20] = {
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x01,0x01,0x00},
		{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x00},
		{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x01,0x00},
		{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x01,0x00,0x01,0x01,0x01,0x00,0x01,0x00},
		{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x01,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x01,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
	};

	int rock_ind = 0;

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			if(!rocks[j][i]) continue;
			if(rock_ind+1 >= _numRocks) continue;

			_rocks[rock_ind++] = new Rock00Entity(16*i, 16*j);
		}
	}
}

//-----------------------------------------------------------------------------
/*
*/
void P00Node00::_drawEntities(void) {
	for(int i=0; i<_numRocks; i++) {
		if(_rocks[i]) _rocks[i]->draw();
	}

	_chestEnt->draw();
	_barrelEnt->draw();
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool P00Node00::canSpawn(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	int pi = _player->getI();
	int pj = _player->getJ();

	return (SDL_bool) (
		(
		getTile(i,j)==SpriteID::GRASS00 // change
		)
		&&(i!=pi&&j!=pj)
	);
}

//-----------------------------------------------------------------------------
/*
*/
Entity* P00Node00::getEntityAt(int i, int j) {
	for(int k=0; k<_numRocks; k++) {
		if(!_rocks[k]) continue;
		int ri = _rocks[k]->getI();
		int rj = _rocks[k]->getJ();
		if(i==ri&&j==rj) return _rocks[k];
	}

	int ci = _chestEnt->getI();
	int cj = _chestEnt->getJ();
	if(i==ci&&j==cj) return _chestEnt;

	int bi = _barrelEnt->getI();
	int bj = _barrelEnt->getJ();
	if(i==bi&&j==bj) return _barrelEnt;

	return NULL;
}
