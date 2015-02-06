/* npc00entity.cpp */
//-----------------------------------------------------------------------------
/*
*/
Npc00Entity::Npc00Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC00, new RandomInput(2*256)) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
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

//-----------------------------------------------------------------------------
/*
*/
void Npc00Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC00;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Npc00Entity::canMove(int i, int j) {
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
void Npc00Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			if(!node->getPlayer()->hasItem(SpriteID::AMULET00)) {
				char str[] =\
					"Hello, I'm looking for my"\
					"amulet. If you see it be "\
					"sure to let me know!     ";
				node->writeMessageToPlayer(this, str);
			} else {
				char str[] =\
					"Oh good! Thank you for   "\
					"finding my amulet. In    "\
					"return let me show you a "\
					"a secret...              ";
				node->writeMessageToPlayer(this, str);
			}
		} break;

		case 0x01: {
			char str[] =\
				"Be careful down there!   ";
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
void Npc00Entity::resolveInteraction(PlayerEntity* player) {
	switch(_npcState) {
		case 0x00: {
			if(!player->hasItem(SpriteID::AMULET00)) {
				player->input->clear();
				player->allowMovement();
			} else {
				WorldNode* node = Overworld::getRef().getCurNode();
				node->setTile(_i, _j, SpriteID::LADDER00);

				WorldNode* d00node = Dungeon00::getRef().getCurNode();
				d00node->setTile(_i, _j, SpriteID::LADDER00);

				player->takeItem(SpriteID::AMULET00);

				if(moveUp());
				else if(moveDown());
				else if(moveLeft());
				else if(moveRight());

				char str[] =\
					"Also, take this! You will"\
					"need it down there...    ";
				node->writeMessageToPlayer(this, str);

				player->input->clear();
				player->weapon->equipped = SDL_TRUE;

				_npcState++;
			}
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
