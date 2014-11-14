//----------------------------------------------------------------------
#ifndef _NODE0B_HEADER_
#define _NODE0B_HEADER_

/* node0B.h */
//----------------------------------------------------------------------
class Node0B: public WorldNode {
protected:
	int _fpa = 32;
	int _sea_frame = 32;

public:
	Node0B(void);

	void update(void);
};

/* node0B.cpp */
//----------------------------------------------------------------------
Node0B::Node0B(void) {
	int tiles[15][20] = {
		{0x08,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x09},
		{0x0C,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x0D},
		{0x0A,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0B},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x03,0x03,0x03,0x48,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
		{0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15}
	};

	for(int j=0; j<15; j++) {
		for(int i=0; i<20; i++) {
			_tiles[j][i] = tiles[j][i];
		}
	}
}

void Node0B::update(void) {
	WorldNode::update();
	
	if(_sea_frame>0) _sea_frame--;
	if(_sea_frame==0) {
		_sea_frame = _fpa;
		for(int j=3; j<15; j++) {
			for(int i=0; i<20; i++) {
				if(_tiles[j][i]==SEA_TILE_00) _tiles[j][i] = SEA_TILE_01;
				else if(_tiles[j][i]==SEA_TILE_01) _tiles[j][i] = SEA_TILE_00;

				if(_tiles[j][i]==SEA_TILE_02) _tiles[j][i] = SEA_TILE_03;
				else if(_tiles[j][i]==SEA_TILE_03) _tiles[j][i] = SEA_TILE_02;

				if(_tiles[j][i]==SEA_TILE_04) _tiles[j][i] = SEA_TILE_05;
				else if(_tiles[j][i]==SEA_TILE_05) _tiles[j][i] = SEA_TILE_04;

				if(_tiles[j][i]==SEA_TILE_06) _tiles[j][i] = SEA_TILE_07;
				else if(_tiles[j][i]==SEA_TILE_07) _tiles[j][i] = SEA_TILE_06;

				if(_tiles[j][i]==SEA_TILE_08) _tiles[j][i] = SEA_TILE_09;
				else if(_tiles[j][i]==SEA_TILE_09) _tiles[j][i] = SEA_TILE_08;

				if(_tiles[j][i]==SEA_TILE_0A) _tiles[j][i] = SEA_TILE_0B;
				else if(_tiles[j][i]==SEA_TILE_0B) _tiles[j][i] = SEA_TILE_0A;
			}
		}
	}
}

#endif
