//----------------------------------------------------------------------
#ifndef _BUGENTITY_HEADER_
#define _BUGENTITY_HEADER_

/* bugentity.h */
//----------------------------------------------------------------------
class BugEntity: public Moveable, public Entity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 8;
	int _frame = 8;
	SDL_bool _dying = SDL_FALSE;

public:
	BugEntity(int x, int y);

	void update(void);
	void setPos(int x, int y);
	void hit(int damage);
};

#endif
