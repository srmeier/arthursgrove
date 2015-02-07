//-----------------------------------------------------------------------------
#ifndef _OVERWORLD_HEADER_
#define _OVERWORLD_HEADER_

//-----------------------------------------------------------------------------
#include "overworld/node00.h"
#include "overworld/node01.h"
#include "overworld/node02.h"
#include "overworld/node03.h"
#include "overworld/node04.h"
#include "overworld/node05.h"
#include "overworld/node06.h"
#include "overworld/node07.h"
#include "overworld/node08.h"
#include "overworld/node09.h"
#include "overworld/node0A.h"
#include "overworld/node0B.h"
#include "overworld/node0C.h"
#include "overworld/node0D.h"
#include "overworld/node0E.h"
#include "overworld/node0F.h"

/* overworld.h */
//-----------------------------------------------------------------------------
/*
*/
class Overworld {
private:
	Overworld(Overworld const&);
	void operator = (Overworld const&);

	Overworld(void) {};
	~Overworld(void);

	int _i = 2;
	int _j = 1;
	int _w = 4;
	int _h = 4;

	PlayerEntity* _player;
	WorldNode* _nodes[4][4] = {
		{new Node04(), new Node03(), new Node05(), new Node07()},
		{new Node02(), new Node00(), new Node01(), new Node08()},
		{new Node0F(), new Node0C(), new Node0D(), new Node0E()},
		{new Node06(), new Node0B(), new Node0A(), new Node09()}
	};

public:
	static Overworld& getRef(void) {
		static Overworld instance;
		return instance;
	}

	SDL_bool onLadder = SDL_FALSE;

	void updateNode(void);
	void drawNode(void);

	void moveTop(void);
	void moveBot(void);
	void moveLeft(void);
	void moveRight(void);

	SDL_bool hasTopNode(void);
	SDL_bool hasBotNode(void);
	SDL_bool hasLeftNode(void);
	SDL_bool hasRightNode(void);

	WorldNode* getCurNode(void);
	SpriteID getTile(int i, int j);
	void addPlayer(PlayerEntity* player);
};

/* overworld.cpp */
//-----------------------------------------------------------------------------
/*
*/
Overworld::~Overworld(void) {
	for(int j=0; j<_h; j++) {
		for(int i=0; i<_w; i++) {
			delete _nodes[j][i];
		}
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::updateNode(void) {
	_nodes[_j][_i]->update();
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::drawNode(void) {
	_nodes[_j][_i]->draw();
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::moveTop(void) {
	if(!hasTopNode()) return;
	_j--; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::moveBot(void) {
	if(!hasBotNode()) return;
	_j++; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::moveLeft(void) {
	if(!hasLeftNode()) return;
	_i--; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::moveRight(void) {
	if(!hasRightNode()) return;
	_i++; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Overworld::hasTopNode(void) {
	if(_j-1<0) return SDL_FALSE;
	if(_nodes[_j-1][_i]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Overworld::hasBotNode(void) {
	if(_j+1>=_h) return SDL_FALSE;
	if(_nodes[_j+1][_i]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Overworld::hasLeftNode(void) {
	if(_i-1<0) return SDL_FALSE;
	if(_nodes[_j][_i-1]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Overworld::hasRightNode(void) {
	if(_i+1>=_w) return SDL_FALSE;
	if(_nodes[_j][_i+1]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
WorldNode* Overworld::getCurNode(void) {
	return _nodes[_j][_i];
}

//-----------------------------------------------------------------------------
/*
*/
SpriteID Overworld::getTile(int i, int j) {
	return _nodes[_j][_i]->getTile(i, j);
}

//-----------------------------------------------------------------------------
/*
*/
void Overworld::addPlayer(PlayerEntity* player) {
	_player = player;
	_nodes[_j][_i]->addPlayerEntity(player);
}

#endif
