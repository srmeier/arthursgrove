//----------------------------------------------------------------------
#ifndef _MOVEABLEENTITY_HEADER_
#define _MOVEABLEENTITY_HEADER_

/* moveableentity.h */
//----------------------------------------------------------------------
class MoveableEntity: public Moveable, public Entity {
protected:
	virtual SDL_bool canMove(int i, int j);

public:
	MoveableEntity(int x, int y, SpriteID id, Input* input);

	void update(void);
	void setPos(int x, int y);
};

/* moveableentity.cpp */
//----------------------------------------------------------------------
MoveableEntity::MoveableEntity(int x, int y, SpriteID id, Input* input): Moveable(x, y, input), Entity(x, y, id) {
	// nothing
}

void MoveableEntity::update(void) {
	Moveable::update();

	_rect.x = _x;
	_rect.y = _y;
}

void MoveableEntity::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;

	active = SDL_TRUE;
	Moveable::setPos(x, y);
}

SDL_bool MoveableEntity::canMove(int i, int j) {
	if(i<0||i>=20||j<0||j>=15) return SDL_FALSE;
	return SDL_TRUE;
}

#endif
