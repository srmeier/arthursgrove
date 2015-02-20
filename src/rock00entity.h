//-----------------------------------------------------------------------------
#ifndef _ROCK00ENTITY_HEADER_
#define _ROCK00ENTITY_HEADER_

/* rock00entity.h */
//-----------------------------------------------------------------------------
/*
*/
class Rock00Entity: public NpcEntity {
protected:
	SDL_bool canMove(int i, int j);

public:
	Rock00Entity(int x, int y);

	void update(void);
	void setPos(int x, int y);

	void interactWith(void);
	void resolveInteraction(PlayerEntity* player);
};

#endif
