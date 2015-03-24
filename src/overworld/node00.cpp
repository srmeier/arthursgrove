/* node00.cpp */
//-----------------------------------------------------------------------------
/*
*/
Node00::Node00(void): WorldNode() {
	int tiles[15][20] = {
		{0x08,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x09},
		{0x0C,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x0D},
		{0x0A,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0B},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x30,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x30,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x30,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x30,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E,0x2E},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x31,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32,0x32},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x61,0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x63,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x67,0x5E,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x60,0x67,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x67,0x64,0x65,0x65,0x65,0x65,0x65,0x65,0x65,0x66,0x67,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x67,0x6D,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6B,0x67,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x68,0x69,0x69,0x6E,0x69,0x69,0x69,0x69,0x69,0x69,0x6A,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x38,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x3B}
	};

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_background[j][i] = tiles[j][i];
		}
	}

	/*
	for(int i=0; i<_numofbugs; i++) {
		SDL_bool bugSet = SDL_FALSE;

		while(!bugSet) {
			int ni = rand()%20;
			int nj = rand()%(15-4)+3;

			if(getTile(ni,nj)==SpriteID::GRASS00) {
				bugSet = SDL_TRUE;
				_bug[i] = new BugEntity(16*ni, 16*nj);
			}
		}
	}
	*/

	_npc00 = new Npc00Entity(16*17, 16*9);
}

//-----------------------------------------------------------------------------
/*
*/
Node00::~Node00(void) {
	/*
	for(int i=0; i<_numofbugs; i++) {
		delete _bug[i];
	}
	*/

	delete _npc00;
}

//-----------------------------------------------------------------------------
/*
*/
void Node00::update(void) {
	WorldNode::update();
	
	int pi = _player->getI();
	int pj = _player->getJ();

	if(pi==11&&pj==12)
		_background[12][11] = SpriteID::DOOR01;
	else _background[12][11] = SpriteID::DOOR00;

	/*
	for(int i=0; i<_numofbugs; i++) {
		int bi = _bug[i]->getI();
		int bj = _bug[i]->getJ();

		if(bi==pi&&bj==pj) {
			_bug[i]->hit(1);
		} else if(_player->weapon->active) {
			int si = _player->weapon->getI();
			int sj = _player->weapon->getJ();
			
			if(bi==si&&bj==sj) _bug[i]->hit(1);
		}

		_bug[i]->update();
	}
	*/

	_npc00->update();

	if(_background[_player->getJ()][_player->getI()] == SpriteID::LADDER00 && !Overworld::getRef().onLadder) {
		Dungeon00::getRef().onLadder = SDL_TRUE;
		_player->allowMovement();
		_player->input->clear();
		Game.state = 0x01;
	} else if(_background[_player->getJ()][_player->getI()] != SpriteID::LADDER00) {
		Overworld::getRef().onLadder = SDL_FALSE;
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Node00::_drawEntities(void) {
	/*
	for(int i=0; i<_numofbugs; i++)
		if(_bug[i]->active) _bug[i]->draw();
	*/

	_npc00->draw();
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Node00::canSpawn(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	int pi = _player->getI();
	int pj = _player->getJ();

	int ni = _npc00->getI();
	int nj = _npc00->getJ();

	return (SDL_bool) (
		(
		getTile(i,j)==SpriteID::GRASS00
		)
		&&(i!=pi&&j!=pj)
		&&(i!=ni&&j!=nj)
	);
}

//-----------------------------------------------------------------------------
/*
*/
Entity* Node00::getEntityAt(int i, int j) {
	int ni = _npc00->getI();
	int nj = _npc00->getJ();

	if(i==ni&&j==nj) return _npc00;
	else return NULL;
}
