//----------------------------------------------------------------------
#ifndef _DRAWABLE_HEADER_
#define _DRAWABLE_HEADER_

//----------------------------------------------------------------------
extern SDL_Surface* screen;

/* drawable.h */
//----------------------------------------------------------------------
class Drawable {
protected:
	SDL_Rect _rect;
	SDL_bool _todraw;
	SpriteID _id;

public:
	Drawable(SpriteID id);

	virtual void draw(void);
};

/* drawable.cpp */
//----------------------------------------------------------------------
Drawable::Drawable(SpriteID id) {
	_id = id;
}

void Drawable::draw(void) {
	Sprite* spr = ResourceManager::getRef().getSprite(_id);

	_rect.w = spr->w;
	_rect.h = spr->h;

	SDL_Rect rect;
	memcpy(&rect, &_rect, sizeof(SDL_Rect));
	
	// for some reason SDL_BlitSurface mods the rect
	SDL_BlitSurface(spr->tile, NULL, Game.gfx.screen, &rect);
}

#endif
