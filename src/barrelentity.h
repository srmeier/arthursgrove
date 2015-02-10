//-----------------------------------------------------------------------------
#ifndef _BARRELENTITY_HEADER_
#define _BARRELENTITY_HEADER_

/* barrelentity.h */
//-----------------------------------------------------------------------------
class BarrelEntity: public NpcEntity {
protected:
	int _npcState = 0;

public:
	BarrelEntity(int x, int y, SpriteID id);

	virtual void interactWith(void);
	virtual void resolveInteraction(PlayerEntity* player);
};

#endif
