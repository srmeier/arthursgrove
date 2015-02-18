/* npc02entity.cpp */
//-----------------------------------------------------------------------------
/*
- new RandomInput(2*256)
*/
Npc02Entity::Npc02Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC04, NULL) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void Npc02Entity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;
	if(_frame==0&&_id==SpriteID::NPC04) {
		_frame = _fpa;
		_id = SpriteID::NPC05;
	} else if(_frame==0&&_id==SpriteID::NPC05) {
		_frame = _fpa;
		_id = SpriteID::NPC04;
	}

	_rect.x = _x;
	_rect.y = _y;
}

//-----------------------------------------------------------------------------
/*
*/
void Npc02Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC04;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Npc02Entity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	if(node->getEntityAt(i,j) != NULL) return SDL_FALSE;

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	return (SDL_bool) (
		(
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
void Npc02Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {

		default: {
			char str[] =\
				"I have nothing else to   "\
				"say.                     ";
			node->writeMessageToPlayer(this, str);
		} break;
	}

}

//-----------------------------------------------------------------------------
/*
*/
void Npc02Entity::resolveInteraction(PlayerEntity* player) {
	switch(_npcState) {

		default: {
			player->input->clear();
			player->allowMovement();
		} break;
	}
}
