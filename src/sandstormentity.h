//-----------------------------------------------------------------------------
#ifndef _SANDSTORMENTITY_HEADER_
#define _SANDSTORMENTITY_HEADER_

/* sandstormentity.h */
//-----------------------------------------------------------------------------
/*
*/
class SandstormEntity: public WeaponEntity {
protected:
	int _fpa = 16;
	int _frame = 16;

public:
	SandstormEntity(int x, int y);

	void update(void);
	void draw(void);

	void swingUp(int x, int y);
	void swingDown(int x, int y);
	void swingLeft(int x, int y);
	void swingRight(int x, int y);
};

#endif
