/* rock00entity.cpp */
//-----------------------------------------------------------------------------
/*
- new RandomInput(2*256)
*/
Rock00Entity::Rock00Entity(int x, int y): NpcEntity(x, y, SpriteID::ROCK06, NULL) {
	_interacting = SDL_FALSE;
}

//-----------------------------------------------------------------------------
/*
*/
void Rock00Entity::update(void) {
	Moveable::update();

	_rect.x = _x;
	_rect.y = _y;

	if(_interacting && !_moving) {
		Overworld& overworld = Overworld::getRef();
		WorldNode* node = overworld.getCurNode();

		PlayerEntity* player = node->getPlayer();

		_interacting = SDL_FALSE;
		resolveInteraction(player);
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Rock00Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::ROCK06;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Rock00Entity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	WorldNode* node = NULL;

	switch(Game.state) {
		case 0x00: {
			Overworld& overworld = Overworld::getRef();
			node = overworld.getCurNode();
		} break;

		case 0x02: {
			Puzzle00& puzzle00 = Puzzle00::getRef();
			node = puzzle00.getCurNode();
		} break;
	}

	if(node->getEntityAt(i,j) != NULL) return SDL_FALSE;

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	return (SDL_bool) (
		(
			node->getTile(i,j)==SpriteID::DIRT00 ||
			node->getTile(i,j)==SpriteID::DIRT01 ||
			node->getTile(i,j)==SpriteID::DIRT02 ||
			node->getTile(i,j)==SpriteID::DIRT03 ||
			node->getTile(i,j)==SpriteID::DIRT04 ||
			node->getTile(i,j)==SpriteID::DIRT05 ||
			node->getTile(i,j)==SpriteID::DIRT06 ||
			node->getTile(i,j)==SpriteID::DIRT07 ||
			node->getTile(i,j)==SpriteID::DIRT08 ||
			node->getTile(i,j)==SpriteID::DIRT09 ||
			node->getTile(i,j)==SpriteID::DIRT0A ||
			node->getTile(i,j)==SpriteID::DIRT0B ||
			node->getTile(i,j)==SpriteID::DIRT0C ||
			node->getTile(i,j)==SpriteID::DIRT0D
		)
		&&!(i==pi&&j==pj)
	);
}

//-----------------------------------------------------------------------------
/*
*/
void Rock00Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	int pi = node->getPlayer()->getI();
	int pj = node->getPlayer()->getJ();

	int hasMoved = 0;

	switch(_npcState) {
		default: {
			if((pj-1) == _j) hasMoved |= (int) moveUp();
			else if((pj+1) == _j) hasMoved |= (int) moveDown();
			else if((pi-1) == _i) hasMoved |= (int) moveLeft();
			else if((pi+1) == _i) hasMoved |= (int) moveRight();
		} break;
	}

	if(hasMoved) {
		_interacting = SDL_TRUE;
		node->getPlayer()->input->clear();
		node->getPlayer()->preventMovement();
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Rock00Entity::resolveInteraction(PlayerEntity* player) {
	switch(_npcState) {
		default: {
			player->input->clear();
			player->allowMovement();
		} break;
	}
}
