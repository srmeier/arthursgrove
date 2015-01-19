//----------------------------------------------------------------------
#ifndef _INPUT_HEADER_
#define _INPUT_HEADER_

/* input.h */
//-----------------------------------------------------------------------------
/*
*/
class Input {
protected:
	SDL_bool _up;
	SDL_bool _down;
	SDL_bool _left;
	SDL_bool _right;
	SDL_bool _a, _b;

	SDL_bool _upc;
	SDL_bool _downc;
	SDL_bool _leftc;
	SDL_bool _rightc;
	SDL_bool _ac, _bc;

public:
	Input(void);

	void clear(void);
	virtual void poll(void);
	SDL_bool isDown(const char* key);
	SDL_bool isPressed(const char* key);
	void setKey(const char* key, SDL_bool isdown);
};

/* input.cpp */
//-----------------------------------------------------------------------------
/*
*/
Input::Input(void) {
	clear();
}

//-----------------------------------------------------------------------------
/*
- used to clear the input class to its original state
*/
void Input::clear(void) {
	_a      = SDL_FALSE;
	_b      = SDL_FALSE;
	_up     = SDL_FALSE;
	_down   = SDL_FALSE;
	_left   = SDL_FALSE;
	_right  = SDL_FALSE;

	_ac     = SDL_FALSE;
	_bc     = SDL_FALSE;
	_upc    = SDL_FALSE;
	_downc  = SDL_FALSE;
	_leftc  = SDL_FALSE;
	_rightc = SDL_FALSE;
}

//-----------------------------------------------------------------------------
/*
- this prevents the one frame delay on key presses (because the checks have one
	run into the Input::isPressed() to be set to SDL_FALSE)
*/
void Input::poll(void) {
	if(!_up) _upc = SDL_FALSE;
	if(!_down) _downc = SDL_FALSE;
	if(!_left) _leftc = SDL_FALSE;
	if(!_right) _rightc = SDL_FALSE;
	if(!_a) _ac = SDL_FALSE;
	if(!_b) _bc = SDL_FALSE;
}

//-----------------------------------------------------------------------------
/*
- used to check whether a particular key is down
*/
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

//-----------------------------------------------------------------------------
/*
- used to check whether a particular key is pressed
*/
SDL_bool Input::isPressed(const char* key) {
	if(!strcmp(key, "up")) {
		if(_up&&!_upc) {
			_upc = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_up) _upc = SDL_FALSE;
		return SDL_FALSE;
	} else if(!strcmp(key, "down")) {
		if(_down&&!_downc) {
			_downc = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_down) _downc = SDL_FALSE;
		return SDL_FALSE;
	} else if(!strcmp(key, "left")) {
		if(_left&&!_leftc) {
			_leftc = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_left) _leftc = SDL_FALSE;
		return SDL_FALSE;
	} else if(!strcmp(key, "right")) {
		if(_right&&!_rightc) {
			_rightc = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_right) _rightc = SDL_FALSE;
		return SDL_FALSE;
	} else if(!strcmp(key, "a")) {
		if(_a&&!_ac) {
			_ac = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_a) _ac = SDL_FALSE;
		return SDL_FALSE;
	} else if(!strcmp(key, "b")) {
		if(_b&&!_bc) {
			_bc = SDL_TRUE;
			return SDL_TRUE;
		} else if(!_b) _bc = SDL_FALSE;
		return SDL_FALSE;
	}
}

//-----------------------------------------------------------------------------
/*
- used to set whether a key is up of down
- this is used by AI and user input
*/
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
