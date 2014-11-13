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
	SpriteTag _tag;

public:
	Drawable(SpriteTag tag);

	void draw(void);
};

/* drawable.cpp */
//----------------------------------------------------------------------
Drawable::Drawable(SpriteTag tag) {
	_tag = tag;
}

void Drawable::draw(void) {
	Sprite* spr = SprManager::getRef().getSprite(_tag);

	_rect.w = spr->w;
	_rect.h = spr->h;

	SDL_Rect rect;
	memcpy(&rect, &_rect, sizeof(SDL_Rect));
	
	// for some reason SDL_BlitSurface mods the rect
	SDL_BlitSurface(spr->tile, NULL, screen, &rect);
}

#endif
