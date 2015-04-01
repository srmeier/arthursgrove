//-----------------------------------------------------------------------------
#ifndef _BOSSENTITY_HEADER_
#define _BOSSENTITY_HEADER_

/* bossentity.h */
//-----------------------------------------------------------------------------
/*
*/
class BossEntity: public Moveable, public Entity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 16;
	int _frame = 16;
	int _attack_delay = 0;
	int _damage_delay = 20;

	SDL_bool _attacking = SDL_FALSE;
	SDL_bool _attack_next_chance = SDL_FALSE;

public:
	BossEntity(int x, int y);
	~BossEntity(void);

	void update(void);
	void draw(void);
	void setPos(int x, int y);
	void hit(int damage);

	int _health = 4;

	SDL_bool _dying = SDL_FALSE;
	WeaponEntity* weapon;
};

#endif
