//-----------------------------------------------------------------------------
#ifndef _NPC02ENTITY_HEADER_
#define _NPC02ENTITY_HEADER_

/* npc02entity.h */
//-----------------------------------------------------------------------------
/*
*/
class Npc02Entity: public NpcEntity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 14;
	int _frame = 14;

public:
	Npc02Entity(int x, int y, Input* input);

	void update(void);
	void setPos(int x, int y);

	void interactWith(void);
	void resolveInteraction(PlayerEntity* player);
};

#endif
