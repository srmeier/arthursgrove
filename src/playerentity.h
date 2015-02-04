//-----------------------------------------------------------------------------
#ifndef _PLAYERENTITY_HEADER_
#define _PLAYERENTITY_HEADER_

/* playerentity.h */
//-----------------------------------------------------------------------------
/*
*/
class PlayerEntity: public Moveable, public Entity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 14;
	int _frame = 14;
	int _oddone = 0;

	int _fish_fpa = 14;
	int _fish_frame = 14;
	SDL_bool _has_fish = SDL_TRUE;
	SDL_bool _on_sea_tile = SDL_FALSE;
	SpriteID _fish_id = SpriteID::FISH00;
	
	SDL_bool _attack_next_free_time = SDL_FALSE;

public:
	PlayerEntity(int x, int y);
	~PlayerEntity(void);

	void update(void);
	void draw(void);
	int getX(void);
	int getY(void);

	Entity* shield;
	SwordEntity* sword;
	WeaponEntity* weapon;
	TsunamiEntity* tsunami;
	SpriteID inventory[7];
};

#endif
