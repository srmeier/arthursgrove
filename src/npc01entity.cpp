/* npc01entity.cpp */
//-----------------------------------------------------------------------------
/*
*/
Npc01Entity::Npc01Entity(int x, int y): NpcEntity(x, y, SpriteID::NPC02, NULL) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void Npc01Entity::update(void) {
	Moveable::update();

	if(_frame>0) _frame--;
	if(_frame==0&&_id==SpriteID::NPC02) {
		_frame = _fpa;
		_id = SpriteID::NPC03;
	} else if(_frame==0&&_id==SpriteID::NPC03) {
		_frame = _fpa;
		_id = SpriteID::NPC02;
	}

	_rect.x = _x;
	_rect.y = _y;
}

//-----------------------------------------------------------------------------
/*
*/
void Npc01Entity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	_id = SpriteID::NPC02;
	Moveable::setPos(x, y);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Npc01Entity::canMove(int i, int j) {
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
void Npc01Entity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			if(node->getPlayer()->hasItem(SpriteID::COIN00)) {
				char str[] =\
					"I'll be taking that coin "\
					"Thanks!                  "\
					"In return you can have   "\
					"this ugly amulet. Hehe   ";
				node->writeMessageToPlayer(this, str);
			} else {
				char str[] =\
					"Hey, I will trade you    "\
					"this stupid amulet for a "\
					"pretty coin... I found it"\
					"here I swear! Hehe       ";
				node->writeMessageToPlayer(this, str);
			}
		} break;

		default: {
			char str[] =\
				"Thanks again for the     "\
				"coin. Hehe               ";
			node->writeMessageToPlayer(this, str);
		} break;
	}

}

//-----------------------------------------------------------------------------
/*
*/
void Npc01Entity::resolveInteraction(PlayerEntity* player) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			if(node->getPlayer()->hasItem(SpriteID::COIN00)) {
				int ind = 0;
				player->takeItem(SpriteID::COIN00, &ind);
				player->inventory[ind] = SpriteID::AMULET00;

				_npcState++;
			}

			player->input->clear();
			player->allowMovement();
		} break;

		default: {
			player->input->clear();
			player->allowMovement();
		} break;
	}
}
