//-----------------------------------------------------------------------------
#ifndef _TSUNAMIENTITY_HEADER_
#define _TSUNAMIENTITY_HEADER_

/* tsunamientity.h */
//-----------------------------------------------------------------------------
/*
*/
class TsunamiEntity: public WeaponEntity {
public:
	TsunamiEntity(int x, int y);

	void update(void);

	void swingUp(int x, int y);
	void swingDown(int x, int y);
	void swingLeft(int x, int y);
	void swingRight(int x, int y);
};

#endif
