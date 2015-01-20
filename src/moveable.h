//-----------------------------------------------------------------------------
#ifndef _MOVEABLE_HEADER_
#define _MOVEABLE_HEADER_

/* moveable.h */
//-----------------------------------------------------------------------------
/*
- this component provides basic entity movement from one grid point to the next
	grid point
*/
class Moveable {
protected:
	virtual SDL_bool canMove(int i, int j);

	int _x, _y;
	int _i, _j;
	int _moveframe;
	int _movedirec;
	SDL_bool _moving;
	SDL_bool _tomove;

public:
	Moveable(int x, int y, Input* _input);
	~Moveable(void);

	virtual void update(void);
	void setPos(int x, int y);

	int getI(void);
	int getJ(void);

	void allowMovement(void);
	void preventMovement(void);

	Input* input;
};

/* moveable.cpp */
//-----------------------------------------------------------------------------
/*
- set the components x and y along with the input responsible for moving the
	component
*/
Moveable::Moveable(int x, int y, Input* _input) {
	_x = x;
	_y = y;

	_i = floor(_x/16.0f);
	_j = floor(_y/16.0f);

	input = _input;

	_moveframe = 0;
	_movedirec = 1;

	_moving = SDL_FALSE;
	_tomove = SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
Moveable::~Moveable(void) {
	delete input;
}

//-----------------------------------------------------------------------------
/*
- this is a virtual function which each class is required to set unless the
	entity can move everywhere
*/
SDL_bool Moveable::canMove(int i, int j) {
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
void Moveable::update(void) {
	input->poll();
	
	if(!_tomove&&!_moving) return;

	_i = floor(_x/16.0f);
	_j = floor(_y/16.0f);

	if(_moveframe>0) _moveframe--;
	else if(_moving) {
		_moving = SDL_FALSE;
	}

	if(!_moving) {
		if(input->isDown("up")&&canMove(_i, _j-1)) {
			_moving = SDL_TRUE;
			_moveframe = 16-1;
			_movedirec = 0;
		} else if(input->isDown("down")&&canMove(_i, _j+1)) {
			_moving = SDL_TRUE;
			_moveframe = 16-1;
			_movedirec = 1;
		} else if(input->isDown("left")&&canMove(_i-1, _j)) {
			_moving = SDL_TRUE;
			_moveframe = 16-1;
			_movedirec = 2;
		} else if(input->isDown("right")&&canMove(_i+1, _j)) {
			_moving = SDL_TRUE;
			_moveframe = 16-1;
			_movedirec = 3;
		}
	}

	if(_moving) {
		switch(_movedirec) {
			case 0: _y--; break;
			case 1: _y++; break;
			case 2: _x--; break;
			case 3: _x++; break;
		}
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Moveable::setPos(int x, int y) {
	_x = x;
	_y = y;

	_i = floor(_x/16.0f);
	_j = floor(_y/16.0f);

	_moveframe = 0;
	_movedirec = 0;

	_moving = SDL_FALSE;
	_tomove = SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
- get the x coordinate
*/
int Moveable::getI(void) {
	return _i;
}

//-----------------------------------------------------------------------------
/*
- get the y coordinate
*/
int Moveable::getJ(void) {
	return _j;
}

//-----------------------------------------------------------------------------
/*
- allow the entity to move
*/
void Moveable::allowMovement(void) {
	_tomove = SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
- prevent the entity from move
*/
void Moveable::preventMovement(void) {
	_tomove = SDL_FALSE;
}

#endif
