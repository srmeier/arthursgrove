//----------------------------------------------------------------------
#ifndef _NODE0C_HEADER_
#define _NODE0C_HEADER_

/* node0C.h */
//----------------------------------------------------------------------
class Node0C: public WorldNode {
protected:
	int _fpa = 32;
	int _sea_frame = 32;

public:
	Node0C(void);

	void update(void);
};

/* node0C.cpp */
//----------------------------------------------------------------------
Node0C::Node0C(void) {
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
		{0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x44,0x44,0x44,0x46,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07}
	};

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_background[j][i] = tiles[j][i];
		}
	}
}

void Node0C::update(void) {
	WorldNode::update();
	
	if(_sea_frame>0) _sea_frame--;
	if(_sea_frame==0) {
		_sea_frame = _fpa;
		for(int j=3; j<15; j++) {
			for(int i=0; i<20; i++) {
				if(_background[j][i]==SpriteID::SEA00) _background[j][i] = SpriteID::SEA01;
				else if(_background[j][i]==SpriteID::SEA01) _background[j][i] = SpriteID::SEA00;

				if(_background[j][i]==SpriteID::SEA02) _background[j][i] = SpriteID::SEA03;
				else if(_background[j][i]==SpriteID::SEA03) _background[j][i] = SpriteID::SEA02;

				if(_background[j][i]==SpriteID::SEA04) _background[j][i] = SpriteID::SEA05;
				else if(_background[j][i]==SpriteID::SEA05) _background[j][i] = SpriteID::SEA04;

				if(_background[j][i]==SpriteID::SEA06) _background[j][i] = SpriteID::SEA07;
				else if(_background[j][i]==SpriteID::SEA07) _background[j][i] = SpriteID::SEA06;

				if(_background[j][i]==SpriteID::SEA08) _background[j][i] = SpriteID::SEA09;
				else if(_background[j][i]==SpriteID::SEA09) _background[j][i] = SpriteID::SEA08;

				if(_background[j][i]==SpriteID::SEA0A) _background[j][i] = SpriteID::SEA0B;
				else if(_background[j][i]==SpriteID::SEA0B) _background[j][i] = SpriteID::SEA0A;
			}
		}
	}
}

#endif
