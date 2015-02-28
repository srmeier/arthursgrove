//-----------------------------------------------------------------------------
#ifndef _NODE0A_HEADER_
#define _NODE0A_HEADER_

/* node0A.h */
//-----------------------------------------------------------------------------
/*
*/
class Node0A: public WorldNode {
protected:
	Npc03Entity* _npc00;

	void _drawEntities(void);

public:
	Node0A(void);
	~Node0A(void);

	void update(void);

	Entity* getEntityAt(int i, int j);
};

#endif
