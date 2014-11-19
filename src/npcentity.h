//----------------------------------------------------------------------
#ifndef _NPCENTITY_HEADER_
#define _NPCENTITY_HEADER_

/* npcentity.h */
//----------------------------------------------------------------------
class NpcEntity: public MoveableEntity {
public:
	NpcEntity(int x, int y, SpriteTag tag, Input* input);

	virtual void interactWith(void);
};

/* npcentity.cpp */
//----------------------------------------------------------------------
NpcEntity::NpcEntity(int x, int y, SpriteTag tag, Input* input): MoveableEntity(x, y, tag, input) {
	// nothing
}

void NpcEntity::interactWith(void) {
	// nothing
}

#endif
