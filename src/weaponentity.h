//----------------------------------------------------------------------
#ifndef _WEAPONENTITY_HEADER_
#define _WEAPONENTITY_HEADER_

/*
- "swing" is a generic term for "shoot/swing in that direction"
*/

/* weaponentity.h */
//----------------------------------------------------------------------
class WeaponEntity: public Entity {
protected:
	int _i, _j;
	int _direc;
	int _fpa = 4;
	int _frame = 4;

public:
	WeaponEntity(int x, int y, SpriteTag tag);

	virtual void update(void) = 0;

	int getI(void);
	int getJ(void);

	virtual void swingUp(int x, int y) = 0;
	virtual void swingDown(int x, int y) = 0;
	virtual void swingLeft(int x, int y) = 0;
	virtual void swingRight(int x, int y) = 0;

	SDL_bool canmove = SDL_TRUE;
};

/* weaponentity.cpp */
//----------------------------------------------------------------------
WeaponEntity::WeaponEntity(int x, int y, SpriteTag tag): Entity(x, y, tag) {
	// nothing
}

int WeaponEntity::getI(void) {
	return _i;
}

int WeaponEntity::getJ(void) {
	return _j;
}

#endif
