//-----------------------------------------------------------------------------
#ifndef _STRAIGHTINPUT_HEADER_
#define _STRAIGHTINPUT_HEADER_

/* straightinput.h */
//-----------------------------------------------------------------------------
/*
*/
class StraightInput: public Input {
protected:
	int _freq;

public:
	StraightInput(int freq);

	void poll(void);

	Moveable* parent;
};

#endif
