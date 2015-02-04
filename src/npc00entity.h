//-----------------------------------------------------------------------------
#ifndef _NPC00ENTITY_HEADER_
#define _NPC00ENTITY_HEADER_

/* npc00entity.h */
//-----------------------------------------------------------------------------
/*
*/
class Npc00Entity: public NpcEntity {
protected:
	SDL_bool canMove(int i, int j);

	int _fpa = 14;
	int _frame = 14;

public:
	Npc00Entity(int x, int y);

	void update(void);
	void setPos(int x, int y);

	void interactWith(void);
};

#endif
