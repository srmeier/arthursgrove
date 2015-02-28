//-----------------------------------------------------------------------------
#ifndef _P00NODE00_HEADER_
#define _P00NODE00_HEADER_

/* p00node00.h */
//-----------------------------------------------------------------------------
/*
*/
class P00Node00: public WorldNode {
protected:
	int _numRocks = 4;
	Rock00Entity* _rocks[4];

	void _drawEntities(void);

public:
	P00Node00(void);
	~P00Node00(void);

	void update(void);
	void reset(void);

	SDL_bool canSpawn(int i, int j);
	Entity* getEntityAt(int i, int j);
};

#endif
