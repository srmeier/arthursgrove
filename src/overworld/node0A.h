//-----------------------------------------------------------------------------
#ifndef _NODE0A_HEADER_
#define _NODE0A_HEADER_

/* node0A.h */
//-----------------------------------------------------------------------------
/*
*/
class Node0A: public WorldNode {
protected:
	Npc00Entity* _npc00;

	void _drawEntities(void);

public:
	Node0A(void);
	~Node0A(void);

	void update(void);

	Entity* getEntityAt(int i, int j);
};

/* node0A.cpp */
//-----------------------------------------------------------------------------
/*
*/
Node0A::Node0A(void) {
	int tiles[15][20] = {
		{0x08,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x09},
		{0x0C,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x0D},
		{0x0A,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0B},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x61,0x62,0x62,0x62,0x62,0x62,0x62,0x62,0x6E,0x62,0x63,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x67,0x5E,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x5F,0x60,0x67,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x67,0x64,0x65,0x65,0x65,0x65,0x65,0x65,0x65,0x66,0x67,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x67,0x6D,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6C,0x6B,0x67,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x07,0x68,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x69,0x6A,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15}
	};

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_background[j][i] = tiles[j][i];
		}
	}

	_npc00 = new Npc00Entity(16*7, 16*11);
}

//-----------------------------------------------------------------------------
/*
*/
Node0A::~Node0A(void) {
	delete _npc00;
}

//-----------------------------------------------------------------------------
/*
*/
void Node0A::update(void) {
	WorldNode::update();
	
	int pi = _player->getI();
	int pj = _player->getJ();

	if(pi==9&&pj==9)
		_background[9][9] = SpriteID::DOOR01;
	else _background[9][9] = SpriteID::DOOR00;

	_npc00->update();
}

//-----------------------------------------------------------------------------
/*
*/
void Node0A::_drawEntities(void) {
	_npc00->draw();
}

//-----------------------------------------------------------------------------
/*
*/
Entity* Node0A::getEntityAt(int i, int j) {
	int ni = _npc00->getI();
	int nj = _npc00->getJ();

	if(i==ni&&j==nj) return _npc00;
	else return NULL;
}

#endif
