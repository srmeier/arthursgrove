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
	SDL_bool _disable;

	int _fmovedirec;
	SDL_bool _forceMove;

public:
	Moveable(int x, int y, Input* _input);
	~Moveable(void);

	virtual void update(void);
	void setPos(int x, int y);

	int getI(void);
	int getJ(void);

	void allowMovement(void);
	void preventMovement(void);

	SDL_bool moveUp(void);
	SDL_bool moveDown(void);
	SDL_bool moveLeft(void);
	SDL_bool moveRight(void);

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
	if(!_input) _disable = SDL_TRUE;
	else _disable = SDL_FALSE;

	_moveframe = 0;
	_movedirec = 1;

	_moving = SDL_FALSE;
	_tomove = SDL_TRUE;

	_forceMove = SDL_FALSE;
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
	if(_disable) return;

	if(!_forceMove) input->poll();
	if(!_tomove&&!_moving) return;

	_i = floor(_x/16.0f);
	_j = floor(_y/16.0f);

	if(_moveframe>0) _moveframe--;
	else if(_moving) {
		_moving = SDL_FALSE;
	}

	if(!_moving) {
		if(_forceMove) {
			if((_fmovedirec==0)&&canMove(_i, _j-1)) {
				_moving = SDL_TRUE;
				_forceMove = SDL_FALSE;
				_moveframe = 16-1;
				_movedirec = 0;
			} else if((_fmovedirec==1)&&canMove(_i, _j+1)) {
				_moving = SDL_TRUE;
				_forceMove = SDL_FALSE;
				_moveframe = 16-1;
				_movedirec = 1;
			} else if((_fmovedirec==2)&&canMove(_i-1, _j)) {
				_moving = SDL_TRUE;
				_forceMove = SDL_FALSE;
				_moveframe = 16-1;
				_movedirec = 2;
			} else if((_fmovedirec==3)&&canMove(_i+1, _j)) {
				_moving = SDL_TRUE;
				_forceMove = SDL_FALSE;
				_moveframe = 16-1;
				_movedirec = 3;
			}
		} else {
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

	//_moveframe = 0;
	//_movedirec = 0;

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
	setPos(16*_i, 16*_j);

	_tomove = SDL_FALSE;
	_moving = SDL_FALSE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Moveable::moveUp(void) {
	_forceMove = canMove(_i, _j-1);
	_fmovedirec = 0;

	return _forceMove;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Moveable::moveDown(void) {
	_forceMove = canMove(_i, _j+1);
	_fmovedirec = 1;

	return _forceMove;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Moveable::moveLeft(void) {
	_forceMove = canMove(_i-1, _j);
	_fmovedirec = 2;

	return _forceMove;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Moveable::moveRight(void) {
	_forceMove = canMove(_i+1, _j);
	_fmovedirec = 3;

	return _forceMove;
}

#endif
