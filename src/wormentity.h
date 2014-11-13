//----------------------------------------------------------------------
#ifndef _WORMENTITY_HEADER_
#define _WORMENTITY_HEADER_

/* wormentity.h */
//----------------------------------------------------------------------
class WormEntity: public Moveable, public Entity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 8;
	int _frame = 8;
	SDL_bool _dying = SDL_FALSE;

public:
	WormEntity(int x, int y);

	void update(void);
	void setPos(int x, int y);
	void hit(int damage);
};

#endif
