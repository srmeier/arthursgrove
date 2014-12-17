//----------------------------------------------------------------------
#ifndef _WORLDNODE_HEADER_
#define _WORLDNODE_HEADER_

/* worldnode.h */
//----------------------------------------------------------------------
class WorldNode {
protected:
	int _tiles[15][20];
	PlayerEntity* _player;
	int _messageAButnFlash;
	char* _messageForPlayer1;
	char* _messageForPlayer2;
	char* _messageForPlayer3;
	NpcEntity* _interactingNpc;
	SDL_bool _writingMessageToPlayer;

	void _drawGUI(void);
	virtual void _drawEntities(void) {};

public:
	WorldNode(void);
	~WorldNode(void);

	virtual void update(void);
	virtual void draw(void);

	PlayerEntity* getPlayer(void);
	SpriteTag getTile(int i, int j);
	virtual SDL_bool canSpawn(int i, int j);
	virtual void writeMessageToPlayer(NpcEntity* npcentity, const char* message);
	virtual Entity* getEntityAt(int i, int j);
	void addPlayerEntity(PlayerEntity* player);
};

/* worldnode.cpp */
//----------------------------------------------------------------------
WorldNode::WorldNode(void) {
	_player = NULL;
	_messageAButnFlash = 32;
	_messageForPlayer1 = NULL;
	_messageForPlayer2 = NULL;
	_messageForPlayer3 = NULL;
	_writingMessageToPlayer = SDL_FALSE;
}

WorldNode::~WorldNode(void) {
	free(_messageForPlayer1);
	_messageForPlayer1 = NULL;
	free(_messageForPlayer2);
	_messageForPlayer2 = NULL;
	free(_messageForPlayer3);
	_messageForPlayer3 = NULL;
}

void WorldNode::update(void) {
	_player->update();

	if(_writingMessageToPlayer) {
		if(_player->input->isDown("b")) {
			_writingMessageToPlayer = SDL_FALSE;

			_interactingNpc->allowMovement();
			_interactingNpc->resolveInteraction(_player);
		}
	}
}

void WorldNode::_drawGUI(void) {
	// back-drop
	for(int j=0; j<3; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
	}

	if(_writingMessageToPlayer) {
		int drawx = 16*(_interactingNpc->getI()-9);
		int drawy = 16*(_interactingNpc->getJ()-3);
		SDL_Color color = {0x00, 0x00, 0x00, 0x00};

		Sprite* spr = SprManager::getRef().getSprite(FRAME_TILE_0B);
		SDL_Rect rect = {drawx, drawy, spr->w, spr->h};
		SDL_BlitSurface(spr->tile, NULL, screen, &rect);

		SprManager& sprmanager = SprManager::getRef();
		sprmanager.drawText(_messageForPlayer1, drawx+4, drawy+4, color, 6);
		sprmanager.drawText(_messageForPlayer2, drawx+4, drawy+4+6, color, 6);
		sprmanager.drawText(_messageForPlayer3, drawx+4, drawy+4+12, color, 6);

		static int on = 1;
		if(_messageAButnFlash>0) _messageAButnFlash--;
		else {
			_messageAButnFlash = 32;
			if(on) on = 0; else on = 1;
		}

		if(on) sprmanager.drawText("Press B", drawx, drawy+18, color, 6);
	}

	// GUI
	Sprite* spr;
	SDL_Color color = {0xFF, 0xFF, 0xFF, 0x00};

	// heart near top
	SDL_Rect gui_rect = {8, 8, 16, 16};
	spr = SprManager::getRef().getSprite(HEART_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	// bar at bottom
	gui_rect.x = 8; gui_rect.y = 24;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_00);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_01);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	gui_rect.x += 16;
	spr = SprManager::getRef().getSprite(GUI_TILE_03);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	spr = SprManager::getRef().getSprite(GUI_TILE_02);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);

	// inventory
	gui_rect.y -= 16; gui_rect.x += 16*7-8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_09);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("Bag", gui_rect.x+16*4, gui_rect.y+18+8, color);

	gui_rect.x += 8; gui_rect.y += 8;
	for(int i=0; i<7; i++) {
		spr = SprManager::getRef().getSprite(_player->inventory[i]);
		SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
		gui_rect.x += 16+4;
	}

	// equiped frames
	gui_rect.x = 64+16;
	gui_rect.y = 8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_0A);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	gui_rect.x += 4;
	gui_rect.y += 8;
	spr = SprManager::getRef().getSprite(SHIELD_TILE_00);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("A", gui_rect.x+4, gui_rect.y+18, color);

	gui_rect.x = 64+16+16+16;
	gui_rect.y -= 8;
	spr = SprManager::getRef().getSprite(FRAME_TILE_0A);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	gui_rect.x += 4;
	gui_rect.y += 8;
	spr = SprManager::getRef().getSprite(ATTACK_TILE_02);
	SDL_BlitSurface(spr->tile, NULL, screen, &gui_rect);
	SprManager::getRef().drawText("B", gui_rect.x+4, gui_rect.y+18, color);
}

void WorldNode::draw(void) {
	for(int j=3; j<15; j++) {
		for(int i=0; i<20; i++) {
			Sprite* spr = SprManager::getRef().getSprite((SpriteTag) _tiles[j][i]);
			SDL_Rect rect = {16*i, 16*j, spr->w, spr->h};
			SDL_BlitSurface(spr->tile, NULL, screen, &rect);
		}
	}

	_player->draw();
	
	_drawEntities();
	_drawGUI();
}

PlayerEntity* WorldNode::getPlayer(void) {
	return _player;
}

SpriteTag WorldNode::getTile(int i, int j) {
	return (SpriteTag) _tiles[j][i];
}

void WorldNode::writeMessageToPlayer(NpcEntity* npcentity, const char* message) {
	if(!message) return;

	_interactingNpc = npcentity;
	_writingMessageToPlayer = SDL_TRUE;

	free(_messageForPlayer1);
	_messageForPlayer1 = NULL;
	free(_messageForPlayer2);
	_messageForPlayer2 = NULL;
	free(_messageForPlayer3);
	_messageForPlayer3 = NULL;

	int n = 0;
	int lineLen = 25;
	int L = strlen(message);
	int l = strlen(message);

	while(l>0&&n<3) {
		switch(n) {
			case 0: {
				if(L<lineLen) {
					_messageForPlayer1 = (char*) malloc(sizeof(char)*(l+1));
					memcpy(_messageForPlayer1, message, sizeof(char)*l);
					_messageForPlayer1[l] = '\0';
				} else {
					_messageForPlayer1 = (char*) malloc(sizeof(char)*(lineLen+1));
					memcpy(_messageForPlayer1, message, sizeof(char)*lineLen);
					_messageForPlayer1[lineLen] = '\0';
				}
			} break;

			case 1: {
				if(L<2*lineLen) {
					_messageForPlayer2 = (char*) malloc(sizeof(char)*(l+1));
					memcpy(_messageForPlayer2, (message+lineLen), sizeof(char)*l);
					_messageForPlayer2[l] = '\0';
				} else {
					_messageForPlayer2 = (char*) malloc(sizeof(char)*(lineLen+1));
					memcpy(_messageForPlayer2, (message+lineLen), sizeof(char)*lineLen);
					_messageForPlayer2[lineLen] = '\0';
				}
			} break;

			case 2: {
				if(L<3*lineLen) {
					_messageForPlayer3 = (char*) malloc(sizeof(char)*(l+1));
					memcpy(_messageForPlayer3, (message+2*lineLen), sizeof(char)*l);
					_messageForPlayer3[l] = '\0';
				} else {
					_messageForPlayer3 = (char*) malloc(sizeof(char)*(lineLen+1));
					memcpy(_messageForPlayer3, (message+2*lineLen), sizeof(char)*lineLen);
					_messageForPlayer3[lineLen] = '\0';
				}
			} break;
		}

		n++;
		l -= lineLen;
	}

	_messageAButnFlash = 32;
	_player->preventMovement();
	_interactingNpc->preventMovement();
}

Entity* WorldNode::getEntityAt(int i, int j) {
	return NULL;
}

void WorldNode::addPlayerEntity(PlayerEntity* player) {
	_player = player;
}

SDL_bool WorldNode::canSpawn(int i, int j) {
	return SDL_TRUE;
}

#endif
