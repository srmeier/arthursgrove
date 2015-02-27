/* npc03entity.cpp */
//-----------------------------------------------------------------------------
/*
*/
Npc03Entity::Npc03Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC00, new RandomInput(2*256)) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void Npc03Entity::update(void) {
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
void Npc03Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC00;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Npc03Entity::canMove(int i, int j) {
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
void Npc03Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			char str[] =\
				"Humm, you must be here   "\
				"for this...              ";
			node->writeMessageToPlayer(this, str);
		} break;

		case 0x01: {
			char str[] =\
				"Seems to be quite the    "\
				"puzzle...                ";
			node->writeMessageToPlayer(this, str);
		} break;

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
void Npc03Entity::resolveInteraction(PlayerEntity* player) {
	switch(_npcState) {
		case 0x00: {
			WorldNode* node = Overworld::getRef().getCurNode();
			node->setTile(_i, _j, SpriteID::LADDER00);

			//WorldNode* d00node = Dungeon00::getRef().getCurNode();
			//d00node->setTile(_i, _j, SpriteID::LADDER00);

			if(moveUp());
			else if(moveDown());
			else if(moveLeft());
			else if(moveRight());

			char str[] =\
				"Maybe you can figure out "\
				"what is going on down    "\
				"there.                   ";
			node->writeMessageToPlayer(this, str);
			player->input->clear();

			_npcState++;
		} break;

		case 0x01: {
			player->input->clear();
			player->allowMovement();
		} break;

		default: {
			player->input->clear();
			player->allowMovement();
		} break;
	}
}
