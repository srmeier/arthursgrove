/* barrelentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
BarrelEntity::BarrelEntity(int x, int y, SpriteID id): NpcEntity(x, y, id, NULL) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
void BarrelEntity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			if(!node->getPlayer()->hasItem(SpriteID::COIN00)) {
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
void BarrelEntity::resolveInteraction(PlayerEntity* player) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		case 0x00: {
			if(!node->getPlayer()->hasItem(SpriteID::COIN00)) {
				SDL_bool done = SDL_FALSE;
				for(int i=0; i<7; i++) {
					if(done) continue;
					if(player->inventory[i] == SpriteID::FRAME08) {
						done = SDL_TRUE;
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
