//-----------------------------------------------------------------------------
#ifndef _SIGNENTITY_HEADER_
#define _SIGNENTITY_HEADER_

/* signentity.h */
//-----------------------------------------------------------------------------
/*
*/
class SignEntity: public NpcEntity {
protected:
	char* _str;

public:
	SignEntity(int x, int y, char* str);
	~SignEntity(void);

	void interactWith(void);
	void resolveInteraction(PlayerEntity* player);
};

#endif
