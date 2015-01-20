//-----------------------------------------------------------------------------
#ifndef _RANDOMINPUT_HEADER_
#define _RANDOMINPUT_HEADER_

/* randominput.h */
//-----------------------------------------------------------------------------
/*
*/
class RandomInput: public Input {
protected:
	int _freq;

public:
	RandomInput(int freq);

	void poll(void);
};

/* randominput.cpp */
//-----------------------------------------------------------------------------
/*
- sets how frequently the input should be set to a random direction
*/
RandomInput::RandomInput(int freq = 256) {
	_freq = freq;
}

//-----------------------------------------------------------------------------
/*
*/
void RandomInput::poll(void) {
	clear();
	switch(rand()%_freq) {
		case 0: _up = SDL_TRUE; break;
		case 1: _down = SDL_TRUE; break;
		case 2: _left = SDL_TRUE; break;
		case 3: _right = SDL_TRUE; break;
		default: clear(); break;
	}
}

#endif
