//----------------------------------------------------------------------
#ifndef _SWORDENTITY_HEADER_
#define _SWORDENTITY_HEADER_

/* swordentity.h */
//----------------------------------------------------------------------
class SwordEntity: public WeaponEntity {
public:
	SwordEntity(int x, int y);

	void update(void);

	void swingUp(int x, int y);
	void swingDown(int x, int y);
	void swingLeft(int x, int y);
	void swingRight(int x, int y);
};

/* swordentity.cpp */
//----------------------------------------------------------------------
SwordEntity::SwordEntity(int x, int y): WeaponEntity(x, y, SpriteID::ATTACK00) {
	// nothing
}

void SwordEntity::update(void) {
	_i = floor(_rect.x/16.0f);
	_j = floor(_rect.y/16.0f);

	if(_frame>0) _frame--;
	switch(_direc) {
		case 0: {
			if(_id==SpriteID::ATTACK06&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK05;
				_rect.y -= 8*2;
			} else if(_id==SpriteID::ATTACK05&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK00;
				_rect.x += 8*2;
			} else if(_id==SpriteID::ATTACK00&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK01;
				_rect.x += 8*2;
			} else if(_id==SpriteID::ATTACK01&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK02;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK02&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK06;
				active = SDL_FALSE;
				canmove = SDL_TRUE;
			}
		} break;

		case 1: {
			if(_id==SpriteID::ATTACK02&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK03;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK03&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK04;
				_rect.x -= 8*2;
			} else if(_id==SpriteID::ATTACK04&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK07;
				_rect.x -= 8*2;
			} else if(_id==SpriteID::ATTACK07&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK06;
				_rect.y -= 8*2;
			} else if(_id==SpriteID::ATTACK06&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK02;
				active = SDL_FALSE;
				canmove = SDL_TRUE;
			}
		} break;

		case 2: {
			if(_id==SpriteID::ATTACK00&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK05;
				_rect.x -= 8*2;
			} else if(_id==SpriteID::ATTACK05&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK06;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK06&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK07;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK07&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK04;
				_rect.x += 8*2;
			} else if(_id==SpriteID::ATTACK04&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK00;
				active = SDL_FALSE;
				canmove = SDL_TRUE;
			}
		} break;

		case 3: {
			if(_id==SpriteID::ATTACK00&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK01;
				_rect.x += 8*2;
			} else if(_id==SpriteID::ATTACK01&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK02;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK02&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK03;
				_rect.y += 8*2;
			} else if(_id==SpriteID::ATTACK03&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK04;
				_rect.x -= 8*2;
			} else if(_id==SpriteID::ATTACK04&&_frame==0) {
				_frame = _fpa;
				_id = SpriteID::ATTACK00;
				active = SDL_FALSE;
				canmove = SDL_TRUE;
			}
		} break;
	}
}

void SwordEntity::swingUp(int x, int y) {
	_direc = 0;
	setPos(x-8*2, y);
	canmove = SDL_FALSE;
	_id = SpriteID::ATTACK06;
}

void SwordEntity::swingDown(int x, int y) {
	_direc = 1;
	setPos(x+8*2, y);
	canmove = SDL_FALSE;
	_id = SpriteID::ATTACK02;
}

void SwordEntity::swingLeft(int x, int y) {
	_direc = 2;
	setPos(x, y-8*2);
	canmove = SDL_FALSE;
	_id = SpriteID::ATTACK00;
}

void SwordEntity::swingRight(int x, int y) {
	_direc = 3;
	setPos(x, y-8*2);
	canmove = SDL_FALSE;
	_id = SpriteID::ATTACK00;
}

#endif
