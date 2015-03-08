/* chestentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
ChestEntity::ChestEntity(int x, int y, SpriteID id): NpcEntity(x, y, id, NULL) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void ChestEntity::interactWith(void) {
	WorldNode* node = NULL;

	switch(Game.state) {
		case 0x00: {
			Overworld& overworld = Overworld::getRef();
			node = overworld.getCurNode();
		} break;

		case 0x01: {
			Dungeon00& dungeon00 = Dungeon00::getRef();
			node = dungeon00.getCurNode();
		} break;

		case 0x02: {
			Puzzle00& puzzle00 = Puzzle00::getRef();
			node = puzzle00.getCurNode();
		} break;
	}

	switch(_npcState) {
		case 0x00: {
			if(!node->getPlayer()->hasItem(SpriteID::COIN00) && !_plGotTreasure) {
				char str[] =\
					"Oh nice! I found a coin. ";
				node->writeMessageToPlayer(this, str);
			} else {
				char str[] =\
					"Nothing here.            ";
				node->writeMessageToPlayer(this, str);
			}
		} break;

		default: {
			char str[] =\
				"Nothing here.            ";
			node->writeMessageToPlayer(this, str);
		} break;
	}

}

//-----------------------------------------------------------------------------
/*
*/
void ChestEntity::resolveInteraction(PlayerEntity* player) {
	WorldNode* node = NULL;

	switch(Game.state) {
		case 0x00: {
			Overworld& overworld = Overworld::getRef();
			node = overworld.getCurNode();
		} break;

		case 0x01: {
			Dungeon00& dungeon00 = Dungeon00::getRef();
			node = dungeon00.getCurNode();
		} break;

		case 0x02: {
			Puzzle00& puzzle00 = Puzzle00::getRef();
			node = puzzle00.getCurNode();
		} break;
	}

	switch(_npcState) {
		case 0x00: {
			if(!node->getPlayer()->hasItem(SpriteID::COIN00) && !_plGotTreasure) {
				SDL_bool done = SDL_FALSE;
				for(int i=0; i<7; i++) {
					if(done) continue;
					if(player->inventory[i] == SpriteID::FRAME08) {
						done = SDL_TRUE;
						_plGotTreasure = SDL_TRUE;
						player->inventory[i] = SpriteID::COIN00;
					}
				}
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
