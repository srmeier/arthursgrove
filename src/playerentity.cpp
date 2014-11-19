/* playerentity.cpp */
//----------------------------------------------------------------------
PlayerEntity::PlayerEntity(int x, int y): Moveable(x, y, new PlayerInput()), Entity(x, y, PLAYER_TILE_00) {
	shield = new Entity(x, y, SHIELD_TILE_00);

	sword = new SwordEntity(x, y-8*2);
	sword->active = SDL_FALSE;

	tsunami = new TsunamiEntity(x, y);
	tsunami->active = SDL_FALSE;

	for(int i=0; i<7; i++) inventory[i] = EMPTY_TILE;

	inventory[0] = FOOD_TILE_00;
	inventory[1] = SCROLL_TILE_00;
	inventory[2] = RING_TILE_00;
	inventory[3] = POTION_TILE_00;
	inventory[4] = LIGHT_TILE_00;
	inventory[5] = ROPE_TILE_00;
	inventory[6] = KEY_TILE_00;
}

PlayerEntity::~PlayerEntity(void) {
	delete shield;
	delete sword;
	delete tsunami;
}

void PlayerEntity::update(void) {
	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

	if(
		node->getTile(_i,_j)==SEA_TILE_00||
		node->getTile(_i,_j)==SEA_TILE_01||
		node->getTile(_i,_j)==SEA_TILE_02||
		node->getTile(_i,_j)==SEA_TILE_03||
		node->getTile(_i,_j)==SEA_TILE_04||
		node->getTile(_i,_j)==SEA_TILE_05||
		node->getTile(_i,_j)==SEA_TILE_06||
		node->getTile(_i,_j)==SEA_TILE_07||
		node->getTile(_i,_j)==SEA_TILE_08||
		node->getTile(_i,_j)==SEA_TILE_09||
		node->getTile(_i,_j)==SEA_TILE_0A||
		node->getTile(_i,_j)==SEA_TILE_0B
	) _on_sea_tile = SDL_TRUE;
	else _on_sea_tile = SDL_FALSE;

	if(_on_sea_tile) weapon = tsunami;
	else weapon = sword;

	int old_direc = _movedirec;
	if(weapon->canmove) Moveable::update();

	if(old_direc!=_movedirec) {
		// setup for new move direction animation
		switch(_movedirec) {
			case 0: _tag = PLAYER_TILE_03; break;
			case 1: _tag = PLAYER_TILE_00; break;
			case 2: _tag = PLAYER_TILE_06; break;
			case 3: _tag = PLAYER_TILE_09; break;
		}
	}

	if(_attack_next_free_time&&!_moving) {
		switch(_movedirec) {
			case 0: weapon->swingUp(_x, _y); break;
			case 1: weapon->swingDown(_x, _y); break;
			case 2: weapon->swingLeft(_x, _y); break;
			case 3: weapon->swingRight(_x, _y); break;
		} _attack_next_free_time = SDL_FALSE;
	}

	if(weapon->active)
		weapon->update();
	else {
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

		if(input->isDown("a")&&!_attack_next_free_time&&!weapon->active) {
			shield->setPos(_x, _y);
		} else shield->active = SDL_FALSE;
	}

	if(_frame>0) _frame--;
	switch(_movedirec) {
		case 0: {
			if(_tag==PLAYER_TILE_03&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _tag = PLAYER_TILE_04;
				else _tag = PLAYER_TILE_05;
			} else if(_tag==PLAYER_TILE_04&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_03;
			} else if(_tag==PLAYER_TILE_05&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_03;
			}
		} break;
		case 1: {
			if(_tag==PLAYER_TILE_00&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _tag = PLAYER_TILE_01;
				else _tag = PLAYER_TILE_02;
			} else if(_tag==PLAYER_TILE_01&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_00;
			} else if(_tag==PLAYER_TILE_02&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_00;
			}
		} break;
		case 2: {
			if(_tag==PLAYER_TILE_06&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _tag = PLAYER_TILE_07;
				else _tag = PLAYER_TILE_08;
			} else if(_tag==PLAYER_TILE_07&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_06;
			} else if(_tag==PLAYER_TILE_08&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_06;
			}
		} break;
		case 3: {
			if(_tag==PLAYER_TILE_09&&_frame==0) {
				_oddone++;
				_frame = _fpa;
				if(_oddone%2==0) _tag = PLAYER_TILE_0A;
				else _tag = PLAYER_TILE_0B;
			} else if(_tag==PLAYER_TILE_0A&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_09;
			} else if(_tag==PLAYER_TILE_0B&&_frame==0) {
				_frame = _fpa;
				_tag = PLAYER_TILE_09;
			}
		} break;
	}

	_rect.x = _x;
	_rect.y = _y;
}

void PlayerEntity::draw(void) {

	if(_on_sea_tile) {		
		if(_fish_frame>0) _fish_frame--;
		if(_fish_frame==0) {
			_fish_frame = _fish_fpa;
			if(_fish_tag==FISH_TILE_00) _fish_tag = FISH_TILE_01;
			else _fish_tag = FISH_TILE_00;
		}

		SDL_Rect rect = {_rect.x, _rect.y+8, 8*2, 8*2};
		Sprite* fish_spr = SprManager::getRef().getSprite(_fish_tag);
		SDL_BlitSurface(fish_spr->tile, NULL, screen, &rect);

		Sprite* spr;
		switch(_movedirec) {
			case 0: spr = SprManager::getRef().getSprite(PLAYER_TILE_03); break;
			case 1: spr = SprManager::getRef().getSprite(PLAYER_TILE_00); break;
			case 2: spr = SprManager::getRef().getSprite(PLAYER_TILE_06); break;
			case 3: spr = SprManager::getRef().getSprite(PLAYER_TILE_09); break;
		}

		if(_fish_tag==FISH_TILE_01) _rect.y -= 2;
		SDL_BlitSurface(spr->tile, NULL, screen, &_rect);

	} else {
		Drawable::draw();
	}

	if(shield->active) shield->draw();
	if(weapon->active) weapon->draw();
}

int PlayerEntity::getX(void) {
	return _rect.x;
}

int PlayerEntity::getY(void) {
	return _rect.y;
}

SDL_bool PlayerEntity::canMove(int i, int j) {
	if(_attack_next_free_time) return SDL_FALSE;

	Overworld& overworld = Overworld::getRef();
	WorldNode* node = overworld.getCurNode();

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

	return (SDL_bool) ((
		node->getTile(i,j)==GRASS_TILE_00 ||
		node->getTile(i,j)==SAND_TILE_00  ||
		((
		node->getTile(i,j)==SEA_TILE_00   ||
		node->getTile(i,j)==SEA_TILE_01   ||
		node->getTile(i,j)==SEA_TILE_02   ||
		node->getTile(i,j)==SEA_TILE_03   ||
		node->getTile(i,j)==SEA_TILE_04   ||
		node->getTile(i,j)==SEA_TILE_05   ||
		node->getTile(i,j)==SEA_TILE_06   ||
		node->getTile(i,j)==SEA_TILE_07   ||
		node->getTile(i,j)==SEA_TILE_08   ||
		node->getTile(i,j)==SEA_TILE_09   ||
		node->getTile(i,j)==SEA_TILE_0A   ||
		node->getTile(i,j)==SEA_TILE_0B
		)&&_has_fish)||
		node->getTile(i,j)==BRICK_TILE_00 ||
		node->getTile(i,j)==FLOOR_TILE_00 ||
		node->getTile(i,j)==FLOOR_TILE_01 ||
		node->getTile(i,j)==FLOOR_TILE_02 ||
		node->getTile(i,j)==FLOOR_TILE_03 ||
		node->getTile(i,j)==FLOOR_TILE_04 ||
		node->getTile(i,j)==FLOOR_TILE_05 ||
		node->getTile(i,j)==FLOOR_TILE_06 ||
		node->getTile(i,j)==FLOOR_TILE_07 ||
		node->getTile(i,j)==FLOOR_TILE_08 ||
		node->getTile(i,j)==DOOR_TILE_00
	)&&check);
}
