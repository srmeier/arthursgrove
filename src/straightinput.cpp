/* straightinput.cpp */
//----------------------------------------------------------------------
StraightInput::StraightInput(int freq = 32) {
	_freq = freq;
}

void StraightInput::poll(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	PlayerEntity* player = node->getPlayer();

	int pi = player->getI();
	int pj = player->getJ();

	int i = parent->getI();
	int j = parent->getJ();
	
	clear();
	switch(rand()%_freq) {
		case 0: {
			if(pj<j) _up = SDL_TRUE;
		} break;
		case 1: {
			if(pj>j) _down = SDL_TRUE;
		} break;
		case 2: {
			if(pi<i) _left = SDL_TRUE;
		} break;
		case 3: {
			if(pi>i) _right = SDL_TRUE;
		} break;

		default: clear(); break;
	}
}
