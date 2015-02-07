/* d00node00.cpp */
//-----------------------------------------------------------------------------
/*
*/
D00Node00::D00Node00(void): WorldNode() {
	int tiles[15][20] = {
		{0x08,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x09},
		{0x0C,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x0D},
		{0x0A,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0B},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x79,0x62,0x6E,0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x7A,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x67,0x5E,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x60,0x67,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x67,0x64,0x65,0x65,0x65,0x65,0x65,0x65,0x65,0x66,0x67,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x67,0x6D,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6B,0x67,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x77,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x78,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76},
		{0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76,0x76}
	};

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_background[j][i] = tiles[j][i];
		}
	}
}

//-----------------------------------------------------------------------------
/*
*/
D00Node00::~D00Node00(void) {}

//-----------------------------------------------------------------------------
/*
*/
void D00Node00::update(void) {
	WorldNode::update();
	
	int pi = _player->getI();
	int pj = _player->getJ();

	if(pi==10&&pj==8)
		_background[8][10] = SpriteID::DOOR01;
	else _background[8][10] = SpriteID::DOOR00;

	if(_background[_player->getJ()][_player->getI()] == SpriteID::LADDER00 && !Dungeon00::getRef().onLadder) {
		Overworld::getRef().onLadder = SDL_TRUE;
		_player->allowMovement();
		_player->input->clear();
		Game.state = 0x00;
	} else if(_background[_player->getJ()][_player->getI()] != SpriteID::LADDER00) {
		Dungeon00::getRef().onLadder = SDL_FALSE;
	}
}

//-----------------------------------------------------------------------------
/*
*/
void D00Node00::_drawEntities(void) {}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool D00Node00::canSpawn(int i, int j) {
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
Entity* D00Node00::getEntityAt(int i, int j) {
	return NULL;
}