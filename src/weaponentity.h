//-----------------------------------------------------------------------------
#ifndef _WEAPONENTITY_HEADER_
#define _WEAPONENTITY_HEADER_

/* weaponentity.h */
//-----------------------------------------------------------------------------
/*
- "swing" is a generic term for "shoot/swing in that direction"
*/
class WeaponEntity: public Entity {
protected:
	int _i, _j;
	int _direc;
	int _fpa = 4;
	int _frame = 4;

public:
	WeaponEntity(int x, int y, SpriteID id);

	virtual void update(void) {};

	int getI(void);
	int getJ(void);

	virtual void swingUp(int x, int y) {};
	virtual void swingDown(int x, int y) {};
	virtual void swingLeft(int x, int y) {};
	virtual void swingRight(int x, int y) {};

	SDL_bool canmove = SDL_TRUE;
	SDL_bool equipped = SDL_FALSE;
};

/* weaponentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
WeaponEntity::WeaponEntity(int x, int y, SpriteID id): Entity(x, y, id) {
	// nothing
}

//-----------------------------------------------------------------------------
/*
*/
int WeaponEntity::getI(void) {
	return _i;
}

//-----------------------------------------------------------------------------
/*
*/
int WeaponEntity::getJ(void) {
	return _j;
}

#endif
