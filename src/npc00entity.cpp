/* npc00entity.cpp */
//----------------------------------------------------------------------
Npc00Entity::Npc00Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC00, new RandomInput(2*256)) {
	// nothing
}

void Npc00Entity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;
	if(_frame==0&&_id==SpriteID::NPC00) {
		_frame = _fpa;
		_id = SpriteID::NPC01;
	} else if(_frame==0&&_id==SpriteID::NPC01) {
		_frame = _fpa;
		_id = SpriteID::NPC00;
	}

	_rect.x = _x;
	_rect.y = _y;
}

void Npc00Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC00;
	Moveable::setPos(x, y);
}

SDL_bool Npc00Entity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	return (SDL_bool) (
		(
			node->getTile(i,j)==FLOOR_TILE_00 ||
			node->getTile(i,j)==FLOOR_TILE_01 ||
			node->getTile(i,j)==FLOOR_TILE_02 ||
			node->getTile(i,j)==FLOOR_TILE_03 ||
			node->getTile(i,j)==FLOOR_TILE_04 ||
			node->getTile(i,j)==FLOOR_TILE_05 ||
			node->getTile(i,j)==FLOOR_TILE_06 ||
			node->getTile(i,j)==FLOOR_TILE_07 ||
			node->getTile(i,j)==FLOOR_TILE_08
		)
		&&!(i==pi&&j==pj)
	);
}

void Npc00Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	char str[] =\
		"Hello, I'm looking for my"\
		"amulet. If you see it be "\
		"sure to let me know!     ";
	node->writeMessageToPlayer(this, str);
}
