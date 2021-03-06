//-----------------------------------------------------------------------------
#ifndef _D00NODE00_HEADER_
#define _D00NODE00_HEADER_

/* d00node00.h */
//-----------------------------------------------------------------------------
/*
*/
class D00Node00: public WorldNode {
protected:
	int _numofbugs = 12;
	BugEntity* _bug[12];

	WormEntity* _worm;

	void _drawEntities(void);

public:
	D00Node00(void);
	~D00Node00(void);

	void update(void);

	SDL_bool canSpawn(int i, int j);
	Entity* getEntityAt(int i, int j);
};

#endif
