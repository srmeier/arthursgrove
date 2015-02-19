/* signentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
SignEntity::SignEntity(int x, int y, char* str): NpcEntity(x, y, SpriteID::SIGN00, NULL) {
	_str = NULL;
	int n = strlen(str);

	_str = (char*) malloc(sizeof(char)*(n+1));

	memcpy(_str, str, n);
	_str[n] = '\0';
}

//-----------------------------------------------------------------------------
/*
*/
SignEntity::~SignEntity(void) {
	free(_str);
	_str = NULL;
}

//-----------------------------------------------------------------------------
/*
*/
void SignEntity::interactWith(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		default: {
			node->writeMessageToPlayer(this, _str);
		} break;
	}

}

//-----------------------------------------------------------------------------
/*
*/
void SignEntity::resolveInteraction(PlayerEntity* player) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	switch(_npcState) {
		default: {
			player->input->clear();
			player->allowMovement();
		} break;
	}
}
