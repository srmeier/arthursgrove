/* playerentity.cpp */
//-----------------------------------------------------------------------------
/*
*/
PlayerEntity::PlayerEntity(int x, int y): Moveable(x, y, new PlayerInput()), Entity(x, y, SpriteID::PLAYER00) {
	sword = new SwordEntity(x, y-8*2);
	sword->active = SDL_FALSE;

	shield = new WeaponEntity(x, y, SpriteID::SHIELD00);
	shield->active = SDL_FALSE;

	tsunami = new TsunamiEntity(x, y);
	tsunami->active = SDL_FALSE;

	weapon = sword;

	for(int i=0; i<7; i++) inventory[i] = SpriteID::FRAME08;
	
	//inventory[0] = SpriteID::COIN00;
	/*
	inventory[0] = SpriteID::FOOD00;
	inventory[1] = SpriteID::SCROLL00;
	inventory[2] = SpriteID::RING00;
	inventory[3] = SpriteID::POTION00;
	inventory[4] = SpriteID::LIGHT00;
	inventory[5] = SpriteID::ROPE00;
	inventory[6] = SpriteID::KEY00;
	*/
}

//-----------------------------------------------------------------------------
/*
*/
PlayerEntity::~PlayerEntity(void) {
	delete shield;
	delete sword;
	delete tsunami;
}

//-----------------------------------------------------------------------------
/*
*/
void PlayerEntity::update(void) {
	WorldNode* node = NULL;

	switch(Game.state) {
		case 0x00: {
			Overworld& overworld = Overworld::getRef();
			node = overworld.getCurNode();
		} break;

		case 0x01: {
			Dungeon00& dungeon00 = Dungeon00::getRef();
			node = dungeon00.getCurNode();
		} break;

		case 0x02: {
			Puzzle00& puzzle00 = Puzzle00::getRef();
			node = puzzle00.getCurNode();
		} break;
	}

	if(
		node->getTile(_i,_j)==SpriteID::SEA00||
		node->getTile(_i,_j)==SpriteID::SEA01||
		node->getTile(_i,_j)==SpriteID::SEA02||
		node->getTile(_i,_j)==SpriteID::SEA03||
		node->getTile(_i,_j)==SpriteID::SEA04||
		node->getTile(_i,_j)==SpriteID::SEA05||
		node->getTile(_i,_j)==SpriteID::SEA06||
		node->getTile(_i,_j)==SpriteID::SEA07||
		node->getTile(_i,_j)==SpriteID::SEA08||
		node->getTile(_i,_j)==SpriteID::SEA09||
		node->getTile(_i,_j)==SpriteID::SEA0A||
		node->getTile(_i,_j)==SpriteID::SEA0B
	) _on_sea_tile = SDL_TRUE;
	else _on_sea_tile = SDL_FALSE;

	if(_on_sea_tile) weapon = tsunami;
	else weapon = sword;

	int old_direc = _movedirec;
	if(weapon->canmove || !weapon->equipped) Moveable::update();

	if(old_direc!=_movedirec) {
		// setup for new move direction animation
		switch(_movedirec) {
			case 0: _id = SpriteID::PLAYER03; break;
			case 1: _id = SpriteID::PLAYER00; break;
			case 2: _id = SpriteID::PLAYER06; break;
			case 3: _id = SpriteID::PLAYER09; break;
		}
	}

	// no need to check for attacks if the player can't move (i.e. talking with NPC)
	if(_tomove) {
		if(_attack_next_free_time&&!_moving) {
			switch(_movedirec) {
				case 0: weapon->swingUp(_x, _y); break;
				case 1: weapon->swingDown(_x, _y); break;
				case 2: weapon->swingLeft(_x, _y); break;
				case 3: weapon->swingRight(_x, _y); break;
			} _attack_next_free_time = SDL_FALSE;
		}

		if(tsunami->active && weapon!=tsunami) {
			tsunami->update();
		}

		if(weapon->active)
			weapon->update();
		else {
			if(weapon->equipped) {
				if(input->isDown("b")&&!_moving) {
					switch(_movedirec) {
						case 0: weapon->swingUp(_x, _y); break;
						case 1: weapon->swingDown(_x, _y); break;
						case 2: weapon->swingLeft(_x, _y); break;
						case 3: weapon->swingRight(_x, _y); break;
					}
				} else if(input->isDown("b")&&_moving) {
					_attack_next_free_time = SDL_TRUE;
				}
			}

			if(shield->equipped) {
				if(input->isDown("a")&&!_attack_next_free_time&&!weapon->active) {
					shield->setPos(_x, _y);
				} else shield->active = SDL_FALSE;
			}
		}
	}

	if(_frame>0) _frame--;
	switch(_movedirec) {
		case 0: {
			if(_id==SpriteID::PLAYER03&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _id = SpriteID::PLAYER04;
				else _id = SpriteID::PLAYER05;
			} else if(_id==SpriteID::PLAYER04&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER03;
			} else if(_id==SpriteID::PLAYER05&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER03;
			}
		} break;
		case 1: {
			if(_id==SpriteID::PLAYER00&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _id = SpriteID::PLAYER01;
				else _id = SpriteID::PLAYER02;
			} else if(_id==SpriteID::PLAYER01&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER00;
			} else if(_id==SpriteID::PLAYER02&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER00;
			}
		} break;
		case 2: {
			if(_id==SpriteID::PLAYER06&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _id = SpriteID::PLAYER07;
				else _id = SpriteID::PLAYER08;
			} else if(_id==SpriteID::PLAYER07&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER06;
			} else if(_id==SpriteID::PLAYER08&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER06;
			}
		} break;
		case 3: {
			if(_id==SpriteID::PLAYER09&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _id = SpriteID::PLAYER0A;
				else _id = SpriteID::PLAYER0B;
			} else if(_id==SpriteID::PLAYER0A&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER09;
			} else if(_id==SpriteID::PLAYER0B&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::PLAYER09;
			}
		} break;
	}

	_rect.x = _x;
	_rect.y = _y;
}

//-----------------------------------------------------------------------------
/*
*/
void PlayerEntity::draw(void) {

	if(_on_sea_tile) {		
		if(_fish_frame>0) _fish_frame--;
		if(_fish_frame==0) {
			_fish_frame = _fish_fpa;
			if(_fish_id==SpriteID::FISH00) _fish_id = SpriteID::FISH01;
			else _fish_id = SpriteID::FISH00;
		}

		SDL_Rect rect = {_rect.x, _rect.y+8, 8*2, 8*2};
		Sprite* fish_spr = ResourceManager::getRef().getSprite(_fish_id);
		SDL_BlitSurface(fish_spr->tile, NULL, Game.gfx.screen, &rect);

		Sprite* spr;
		switch(_movedirec) {
			case 0: spr = ResourceManager::getRef().getSprite(SpriteID::PLAYER03); break;
			case 1: spr = ResourceManager::getRef().getSprite(SpriteID::PLAYER00); break;
			case 2: spr = ResourceManager::getRef().getSprite(SpriteID::PLAYER06); break;
			case 3: spr = ResourceManager::getRef().getSprite(SpriteID::PLAYER09); break;
		}

		if(_fish_id==SpriteID::FISH01) _rect.y -= 2;
		SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &_rect);

	} else {
		Drawable::draw();
	}

	if(shield->active) shield->draw();
	if(weapon->active) weapon->draw();

	if(tsunami->active && weapon!=tsunami) {
		tsunami->draw();
	}
}

//-----------------------------------------------------------------------------
/*
*/
int PlayerEntity::getX(void) {
	return _rect.x;
}

//-----------------------------------------------------------------------------
/*
*/
int PlayerEntity::getY(void) {
	return _rect.y;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool PlayerEntity::canMove(int i, int j) {
	if(_attack_next_free_time) return SDL_FALSE;

	WorldNode* node = NULL;

	switch(Game.state) {
		case 0x00: {
			Overworld& overworld = Overworld::getRef();
			node = overworld.getCurNode();

			if(j<3&&overworld.hasTopNode()) {
				_y += 16*12;
				overworld.moveTop();
				weapon->active = SDL_FALSE;
			} else if(j>=15&&overworld.hasBotNode()) {
				_y -= 16*12;
				overworld.moveBot();
				weapon->active = SDL_FALSE;
			} else if(i<0&&overworld.hasLeftNode()) {
				_x += 16*20;
				overworld.moveLeft();
				weapon->active = SDL_FALSE;
			} else if(i>=20&&overworld.hasRightNode()) {
				_x -= 16*20;
				overworld.moveRight();
				weapon->active = SDL_FALSE;
			}
		} break;

		case 0x01: {
			Dungeon00& dungeon00 = Dungeon00::getRef();
			node = dungeon00.getCurNode();

			if(j<3&&dungeon00.hasTopNode()) {
				_y += 16*12;
				dungeon00.moveTop();
				weapon->active = SDL_FALSE;
			} else if(j>=15&&dungeon00.hasBotNode()) {
				_y -= 16*12;
				dungeon00.moveBot();
				weapon->active = SDL_FALSE;
			} else if(i<0&&dungeon00.hasLeftNode()) {
				_x += 16*20;
				dungeon00.moveLeft();
				weapon->active = SDL_FALSE;
			} else if(i>=20&&dungeon00.hasRightNode()) {
				_x -= 16*20;
				dungeon00.moveRight();
				weapon->active = SDL_FALSE;
			}
		} break;

		case 0x02: {
			Puzzle00& puzzle00 = Puzzle00::getRef();
			node = puzzle00.getCurNode();

			if(j<3&&puzzle00.hasTopNode()) {
				_y += 16*12;
				puzzle00.moveTop();
				weapon->active = SDL_FALSE;
			} else if(j>=15&&puzzle00.hasBotNode()) {
				_y -= 16*12;
				puzzle00.moveBot();
				weapon->active = SDL_FALSE;
			} else if(i<0&&puzzle00.hasLeftNode()) {
				_x += 16*20;
				puzzle00.moveLeft();
				weapon->active = SDL_FALSE;
			} else if(i>=20&&puzzle00.hasRightNode()) {
				_x -= 16*20;
				puzzle00.moveRight();
				weapon->active = SDL_FALSE;
			}
		} break;
	}

	SDL_bool check = SDL_TRUE;
	Entity* ent = node->getEntityAt(i, j);

	// check for NPC
	NpcEntity* npc_ent = dynamic_cast<NpcEntity*> (ent);

	if(npc_ent) {
		int ei = npc_ent->getI();
		int ej = npc_ent->getJ();
		check  = (SDL_bool) (i!=ei&&j!=ej);

		npc_ent->interactWith();
	}

	return (SDL_bool) (
		(
			node->getTile(i,j)==SpriteID::GRASS00  ||
			node->getTile(i,j)==SpriteID::SAND00   ||
			node->getTile(i,j)==SpriteID::PIT00    ||
			node->getTile(i,j)==SpriteID::LADDER00 ||
			node->getTile(i,j)==SpriteID::DIRT00   ||
			node->getTile(i,j)==SpriteID::DIRT01   ||
			node->getTile(i,j)==SpriteID::DIRT02   ||
			node->getTile(i,j)==SpriteID::DIRT03   ||
			node->getTile(i,j)==SpriteID::DIRT04   ||
			node->getTile(i,j)==SpriteID::DIRT05   ||
			node->getTile(i,j)==SpriteID::DIRT06   ||
			node->getTile(i,j)==SpriteID::DIRT07   ||
			node->getTile(i,j)==SpriteID::DIRT08   ||
			node->getTile(i,j)==SpriteID::DIRT09   ||
			node->getTile(i,j)==SpriteID::DIRT0A   ||
			node->getTile(i,j)==SpriteID::DIRT0B   ||
			node->getTile(i,j)==SpriteID::DIRT0C   ||
			node->getTile(i,j)==SpriteID::DIRT0D   ||
		(
			(
				node->getTile(i,j)==SpriteID::SEA00   ||
				node->getTile(i,j)==SpriteID::SEA01   ||
				node->getTile(i,j)==SpriteID::SEA02   ||
				node->getTile(i,j)==SpriteID::SEA03   ||
				node->getTile(i,j)==SpriteID::SEA04   ||
				node->getTile(i,j)==SpriteID::SEA05   ||
				node->getTile(i,j)==SpriteID::SEA06   ||
				node->getTile(i,j)==SpriteID::SEA07   ||
				node->getTile(i,j)==SpriteID::SEA08   ||
				node->getTile(i,j)==SpriteID::SEA09   ||
				node->getTile(i,j)==SpriteID::SEA0A   ||
				node->getTile(i,j)==SpriteID::SEA0B
			)&&_has_fish)||
			node->getTile(i,j)==SpriteID::BRICK00 ||
			node->getTile(i,j)==SpriteID::FLOOR00 ||
			node->getTile(i,j)==SpriteID::FLOOR01 ||
			node->getTile(i,j)==SpriteID::FLOOR02 ||
			node->getTile(i,j)==SpriteID::FLOOR03 ||
			node->getTile(i,j)==SpriteID::FLOOR04 ||
			node->getTile(i,j)==SpriteID::FLOOR05 ||
			node->getTile(i,j)==SpriteID::FLOOR06 ||
			node->getTile(i,j)==SpriteID::FLOOR07 ||
			node->getTile(i,j)==SpriteID::FLOOR08 ||
			node->getTile(i,j)==SpriteID::DOOR00
		)&&check
	);
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool PlayerEntity::hasItem(SpriteID id) {
	for(int i=0; i<7; i++) {
		if(inventory[i] == id) {
			return SDL_TRUE;
		}
	} return SDL_FALSE;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool PlayerEntity::takeItem(SpriteID id) {
	int _ind = 0;
	SDL_bool hasitem = SDL_FALSE;

	for(int i=0; i<7; i++) {
		if(inventory[i] == id) {
			_ind = i;
			hasitem = SDL_TRUE;
		}
	}

	if(hasitem) inventory[_ind] = SpriteID::FRAME08;

	return hasitem;
}

//-----------------------------------------------------------------------------
/*
*/
SDL_bool PlayerEntity::takeItem(SpriteID id, int* ind) {
	int _ind = 0;
	SDL_bool hasitem = SDL_FALSE;

	for(int i=0; i<7; i++) {
		if(inventory[i] == id) {
			_ind = i;
			hasitem = SDL_TRUE;
		}
	}

	if(hasitem) inventory[_ind] = SpriteID::FRAME08;
	if(ind) *ind = _ind;

	return hasitem;
}

//-----------------------------------------------------------------------------
/*
*/
void PlayerEntity::hit(int damage) {
	/*
	if(_dying) return;

	if(damage>0) {
		_frame = _fpa;
		_dying = SDL_TRUE;
		_id = SpriteID::SMALLFLAME00;
	}
	*/
}
