//----------------------------------------------------------------------
#ifndef _INPUT_HEADER_
#define _INPUT_HEADER_

/* input.h */
//----------------------------------------------------------------------
class Input {
protected:
	SDL_bool _up;
	SDL_bool _down;
	SDL_bool _left;
	SDL_bool _right;
	SDL_bool _a, _b;

public:
	Input(void);

	void clear(void);
	virtual void poll(void) = 0;
	SDL_bool isDown(const char* key);
	void setKey(const char* key, SDL_bool isdown);
};

/* input.cpp */
//----------------------------------------------------------------------
Input::Input(void) {
	clear();
}

void Input::clear(void) {
	_a     = SDL_FALSE;
	_b     = SDL_FALSE;
	_up    = SDL_FALSE;
	_down  = SDL_FALSE;
	_left  = SDL_FALSE;
	_right = SDL_FALSE;
}

SDL_bool Input::isDown(const char* key) {
	if(!strcmp(key, "up")) {
		return _up;
	} else if(!strcmp(key, "down")) {
		return _down;
	} else if(!strcmp(key, "left")) {
		return _left;
	} else if(!strcmp(key, "right")) {
		return _right;
	} else if(!strcmp(key, "a")) {
		return _a;
	} else if(!strcmp(key, "b")) {
		return _b;
	}
}

void Input::setKey(const char* key, SDL_bool isdown) {
	if(!strcmp(key, "up")) {
		_up = isdown;
	} else if(!strcmp(key, "down")) {
		_down = isdown;
	} else if(!strcmp(key, "left")) {
		_left = isdown;
	} else if(!strcmp(key, "right")) {
		_right = isdown;
	} else if(!strcmp(key, "a")) {
		_a = isdown;
	} else if(!strcmp(key, "b")) {
		_b = isdown;
	}
}

#endif
