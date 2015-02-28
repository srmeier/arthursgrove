//-----------------------------------------------------------------------------
#ifndef _PUZZLE00_HEADER_
#define _PUZZLE00_HEADER_

//-----------------------------------------------------------------------------
#include "puzzle00/p00node00.h"

/* puzzle00.h */
//-----------------------------------------------------------------------------
/*
*/
class Puzzle00 {
private:
	Puzzle00(Puzzle00 const&);
	void operator = (Puzzle00 const&);

	Puzzle00(void) {};
	~Puzzle00(void);

	int _i = 0;
	int _j = 0;
	int _w = 1;
	int _h = 1;

	PlayerEntity* _player;
	WorldNode* _nodes[1][1] = {
		{new P00Node00()}
	};

public:
	static Puzzle00& getRef(void) {
		static Puzzle00 instance;
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

/* puzzle00.cpp */
//-----------------------------------------------------------------------------
/*
*/
Puzzle00::~Puzzle00(void) {
	for(int j=0; j<_h; j++) {
		for(int i=0; i<_w; i++) {
			delete _nodes[j][i];
		}
	}
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::updateNode(void) {
	_nodes[_j][_i]->update();
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::drawNode(void) {
	_nodes[_j][_i]->draw();
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::moveTop(void) {
	if(!hasTopNode()) return;
	_j--; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::moveBot(void) {
	if(!hasBotNode()) return;
	_j++; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::moveLeft(void) {
	if(!hasLeftNode()) return;
	_i--; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::moveRight(void) {
	if(!hasRightNode()) return;
	_i++; _nodes[_j][_i]->addPlayerEntity(_player);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Puzzle00::hasTopNode(void) {
	if(_j-1<0) return SDL_FALSE;
	if(_nodes[_j-1][_i]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Puzzle00::hasBotNode(void) {
	if(_j+1>=_h) return SDL_FALSE;
	if(_nodes[_j+1][_i]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Puzzle00::hasLeftNode(void) {
	if(_i-1<0) return SDL_FALSE;
	if(_nodes[_j][_i-1]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool Puzzle00::hasRightNode(void) {
	if(_i+1>=_w) return SDL_FALSE;
	if(_nodes[_j][_i+1]==NULL) return SDL_FALSE;
	return SDL_TRUE;
}

//-----------------------------------------------------------------------------
/*
*/
WorldNode* Puzzle00::getCurNode(void) {
	return _nodes[_j][_i];
}

//-----------------------------------------------------------------------------
/*
*/
SpriteID Puzzle00::getTile(int i, int j) {
	return _nodes[_j][_i]->getTile(i, j);
}

//-----------------------------------------------------------------------------
/*
*/
void Puzzle00::addPlayer(PlayerEntity* player) {
	_player = player;
	_nodes[_j][_i]->addPlayerEntity(player);
}

#endif
