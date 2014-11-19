//----------------------------------------------------------------------
#ifndef _NPCENTITY_HEADER_
#define _NPCENTITY_HEADER_

/* npcentity.h */
//----------------------------------------------------------------------
class NpcEntity: public MoveableEntity {
public:
	NpcEntity(int x, int y, SpriteTag tag, Input* input);

	virtual void interactWith(void);
	virtual void resolveInteraction(PlayerEntity* player);
};

/* npcentity.cpp */
//----------------------------------------------------------------------
NpcEntity::NpcEntity(int x, int y, SpriteTag tag, Input* input): MoveableEntity(x, y, tag, input) {
	// nothing
}

void NpcEntity::interactWith(void) {
	// nothing
}

void NpcEntity::resolveInteraction(PlayerEntity* player) {
	player->input->clear();
	player->allowMovement();
}

#endif