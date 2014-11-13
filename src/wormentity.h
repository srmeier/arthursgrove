//----------------------------------------------------------------------
#ifndef _WORMENTITY_HEADER_
#define _WORMENTITY_HEADER_

/* wormentity.h */
//----------------------------------------------------------------------
class WormEntity: public Moveable, public Entity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 16;
	int _frame = 16;
	int _attack_delay = 0;
	SDL_bool _dying = SDL_FALSE;
	SDL_bool _attacking = SDL_FALSE;
	SDL_bool _attack_next_chance = SDL_FALSE;

public:
	WormEntity(int x, int y);
	~WormEntity(void);

	void update(void);
	void draw(void);
	void setPos(int x, int y);
	void hit(int damage);

	WeaponEntity* weapon;
};

#endif
