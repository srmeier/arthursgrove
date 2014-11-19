/* npc00entity.cpp */
//----------------------------------------------------------------------
Npc00Entity::Npc00Entity(int x, int y): NpcEntity(x, y, NPC_TILE_00, new RandomInput(2*256)) {
	// nothing
}

void Npc00Entity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;
	if(_frame==0&&_tag==NPC_TILE_00) {
		_frame = _fpa;
		_tag = NPC_TILE_01;
	} else if(_frame==0&&_tag==NPC_TILE_01) {
		_frame = _fpa;
		_tag = NPC_TILE_00;
	}

	_rect.x = _x;
	_rect.y = _y;
}

void Npc00Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_tag = NPC_TILE_00;
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

	// will need to write message to player and let him respond
	char str[] = "Hello Hero, this is a test to see how fucking long this string can be and if the implementation will indeed word"; // strings like this carry infor about size
	node->writeMessageToPlayer(this, str);
}
