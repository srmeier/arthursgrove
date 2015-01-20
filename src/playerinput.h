//-----------------------------------------------------------------------------
#ifndef _PLAYERINPUT_HEADER_
#define _PLAYERINPUT_HEADER_

/* playerinput.h */
//-----------------------------------------------------------------------------
/*
*/
class PlayerInput: public Input {
public:
	void poll(void);
};

/* playerinput.cpp */
//-----------------------------------------------------------------------------
/*
*/
void PlayerInput::poll(void) {
	Input::poll();

	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT: {
				Game.running = SDL_FALSE;
			} break;
			
			case SDL_KEYDOWN: {
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE: Game.running = SDL_FALSE; break;
					case SDLK_UP: _up = SDL_TRUE; break;
					case SDLK_DOWN: _down = SDL_TRUE; break;
					case SDLK_LEFT: _left = SDL_TRUE; break;
					case SDLK_RIGHT: _right = SDL_TRUE; break;
					case SDLK_LCTRL: _a = SDL_TRUE; break;
					case SDLK_LALT: _b = SDL_TRUE; break;
				}
			} break;

			case SDL_KEYUP: {
				switch(event.key.keysym.sym) {
					case SDLK_UP: _up = SDL_FALSE; break;
					case SDLK_DOWN: _down = SDL_FALSE; break;
					case SDLK_LEFT: _left = SDL_FALSE; break;
					case SDLK_RIGHT: _right = SDL_FALSE; break;
					case SDLK_LCTRL: _a = SDL_FALSE; break;
					case SDLK_LALT: _b = SDL_FALSE; break;
				}
			} break;
		}
	}
}

#endif
