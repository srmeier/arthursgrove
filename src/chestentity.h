//-----------------------------------------------------------------------------
#ifndef _CHESTENTITY_HEADER_
#define _CHESTENTITY_HEADER_

/* chestentity.h */
//-----------------------------------------------------------------------------
class ChestEntity: public NpcEntity {
protected:
	int _npcState = 0;
	int _plGotTreasure = SDL_FALSE;

public:
	ChestEntity(int x, int y, SpriteID id);

	virtual void interactWith(void);
	virtual void resolveInteraction(PlayerEntity* player);
};

#endif
