//----------------------------------------------------------------------
#ifndef _ENTITY_HEADER_
#define _ENTITY_HEADER_

/* entity.h */
//----------------------------------------------------------------------
class Entity: public Drawable {
public:
	Entity(int x, int y, SpriteTag tag);
	~Entity(void);

	virtual void update(void);
	virtual void setPos(int x, int y);

	SDL_bool active = SDL_TRUE;
};

/* entity.cpp */
//----------------------------------------------------------------------
Entity::Entity(int x, int y, SpriteTag tag): Drawable(tag) {
	_rect.x = x;
	_rect.y = y;
}

Entity::~Entity(void) {
	// nothing
}

void Entity::update(void) {
	// nothing
}

void Entity::setPos(int x, int y) {
	// idea being that if you set a new position the ent should be active
	active = SDL_TRUE;

	_rect.x = x;
	_rect.y = y;
}

#endif
