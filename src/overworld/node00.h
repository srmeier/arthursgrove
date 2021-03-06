//-----------------------------------------------------------------------------
#ifndef _NODE00_HEADER_
#define _NODE00_HEADER_

/* node00.h */
//-----------------------------------------------------------------------------
/*
*/
class Node00: public WorldNode {
protected:
	int _numofbugs = 4;
	BugEntity* _bug[4];
	Npc00Entity* _npc00;

	void _drawEntities(void);

public:
	Node00(void);
	~Node00(void);

	void update(void);

	SDL_bool canSpawn(int i, int j);
	Entity* getEntityAt(int i, int j);
};

#endif
