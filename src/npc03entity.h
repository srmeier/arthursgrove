//-----------------------------------------------------------------------------
#ifndef _NPC03ENTITY_HEADER_
#define _NPC03ENTITY_HEADER_

/* npc03entity.h */
//-----------------------------------------------------------------------------
/*
*/
class Npc03Entity: public NpcEntity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 14;
	int _frame = 14;

public:
	Npc03Entity(int x, int y);

	void update(void);
	void setPos(int x, int y);

	void interactWith(void);
	void resolveInteraction(PlayerEntity* player);
};

#endif
