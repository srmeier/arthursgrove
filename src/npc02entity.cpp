/* npc02entity.cpp */
//-----------------------------------------------------------------------------
/*
*/
Npc02Entity::Npc02Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC00, new RandomInput(2*256)) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void Npc02Entity::update(void) {
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

//-----------------------------------------------------------------------------
/*
*/
void Npc02Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC00;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Npc02Entity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	return (SDL_bool) (
		(
			node->getTile(i,j)==SpriteID::FLOOR00 ||
			node->getTile(i,j)==SpriteID::FLOOR01 ||
			node->getTile(i,j)==SpriteID::FLOOR02 ||
			node->getTile(i,j)==SpriteID::FLOOR03 ||
			node->getTile(i,j)==SpriteID::FLOOR04 ||
			node->getTile(i,j)==SpriteID::FLOOR05 ||
			node->getTile(i,j)==SpriteID::FLOOR06 ||
			node->getTile(i,j)==SpriteID::FLOOR07 ||
			node->getTile(i,j)==SpriteID::FLOOR08
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
