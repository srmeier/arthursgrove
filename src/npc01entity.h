//-----------------------------------------------------------------------------
#ifndef _NPC01ENTITY_HEADER_
#define _NPC01ENTITY_HEADER_

/* npc01entity.h */
//-----------------------------------------------------------------------------
/*
*/
class Npc01Entity: public NpcEntity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 14;
	int _frame = 14;

public:
	Npc01Entity(int x, int y);

	void update(void);
	void setPos(int x, int y);

	void interactWith(void);
	void resolveInteraction(PlayerEntity* player);
};

#endif
