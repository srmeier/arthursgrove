//-----------------------------------------------------------------------------
#ifndef _D00NODE01_HEADER_
#define _D00NODE01_HEADER_

/* d00node01.h */
//-----------------------------------------------------------------------------
/*
*/
class D00Node01: public WorldNode {
protected:
	int _numofbugs = 24;
	BugEntity* _bug[24];

	WormEntity* _worm;
	BossEntity* _boss;

	void _drawEntities(void);

public:
	D00Node01(void);
	~D00Node01(void);

	void update(void);

	SDL_bool canSpawn(int i, int j);
	Entity* getEntityAt(int i, int j);
};

#endif
