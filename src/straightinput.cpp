/* straightinput.cpp */
//-----------------------------------------------------------------------------
/*
*/
StraightInput::StraightInput(int freq = 48) {
	_freq = freq;
}

//-----------------------------------------------------------------------------
/*
*/
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

	SDL_bool check = (SDL_bool)(pi==i&&pj==j);     // center
	check = (SDL_bool)(check||(pi==i+1&&pj==j));   // right
	check = (SDL_bool)(check||(pi==i-1&&pj==j));   // left
	check = (SDL_bool)(check||(pi==i&&pj==j-1));   // up
	check = (SDL_bool)(check||(pi==i&&pj==j+1));   // down
	check = (SDL_bool)(check||(pi==i+1&&pj==j-1)); // top-right
	check = (SDL_bool)(check||(pi==i-1&&pj==j-1)); // top-left
	check = (SDL_bool)(check||(pi==i-1&&pj==j+1)); // bot-left
	check = (SDL_bool)(check||(pi==i+1&&pj==j+1)); // bot-right

	if(check) _a = SDL_TRUE;
}
