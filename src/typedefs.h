//----------------------------------------------------------------------
#ifndef _TYPEDEFS_HEADER_
#define _TYPEDEFS_HEADER_

/* sprites */
//----------------------------------------------------------------------
typedef enum {
	EMPTY_TILE,         // 0x00
	BRICK_TILE_00,      // 0x01
	TREE_TILE_00,       // 0x02
	SEA_TILE_00,        // 0x03
	SAND_TILE_00,       // 0x04
	BOAT_TILE_00,       // 0x05
	COIN_TILE_00,       // 0x06
	GRASS_TILE_00,      // 0x07
	FRAME_TILE_00,      // 0x08
	FRAME_TILE_01,      // 0x09
	FRAME_TILE_02,      // 0x0A
	FRAME_TILE_03,      // 0x0B
	FRAME_TILE_04,      // 0x0C
	FRAME_TILE_05,      // 0x0D
	FRAME_TILE_06,      // 0x0E
	FRAME_TILE_07,      // 0x0F
	HEART_TILE_00,      // 0x10
	PLAYER_TILE_00,     // 0x11
	PLAYER_TILE_01,     // 0x12
	ENEMYSHIP_TILE_00,  // 0x13
	SELECTBOX_TILE_00,  // 0x14
	ROCK_TILE_00,       // 0x15
	FRAME_TILE_08,      // 0x16
	ATTACK_TILE_00,     // 0x17
	ATTACK_TILE_01,     // 0x18
	ATTACK_TILE_02,     // 0x19
	ATTACK_TILE_03,     // 0x1A
	ATTACK_TILE_04,     // 0x1B
	ATTACK_TILE_05,     // 0x1C
	ATTACK_TILE_06,     // 0x1D
	ATTACK_TILE_07,     // 0x1E
	SHIELD_TILE_00,     // 0x1F
	BUG_TILE_00,        // 0x20
	BUG_TILE_01,        // 0x21
	SMALLFLAME_TILE_00, // 0x22
	SMALLFLAME_TILE_01, // 0x23
	PLAYER_TILE_02,     // 0x24
	PLAYER_TILE_03,     // 0x25
	PLAYER_TILE_04,     // 0x26
	PLAYER_TILE_05,     // 0x27
	PLAYER_TILE_06,     // 0x28
	PLAYER_TILE_07,     // 0x29
	PLAYER_TILE_08,     // 0x2A
	PLAYER_TILE_09,     // 0x2B
	PLAYER_TILE_0A,     // 0x2C
	PLAYER_TILE_0B,     // 0x2D
	TREE_TILE_01,       // 0x2E
	TREE_TILE_02,       // 0x2F
	TREE_TILE_03,       // 0x30
	TREE_TILE_04,       // 0x31
	TREE_TILE_05,       // 0x32
	TREE_TILE_06,       // 0x33
	TREE_TILE_07,       // 0x34
	TREE_TILE_08,       // 0x35
	TREE_TILE_09,       // 0x36
	ROCK_TILE_01,       // 0x37
	ROCK_TILE_02,       // 0x38
	ROCK_TILE_03,       // 0x39
	ROCK_TILE_04,       // 0x3A
	ROCK_TILE_05,       // 0x3B
	SEA_TILE_01,        // 0x3C
	FISH_TILE_00,       // 0x3D
	FISH_TILE_01,       // 0x3E
	SEA_TILE_02,        // 0x3F
	SEA_TILE_03,        // 0x40
	SEA_TILE_04,        // 0x41
	SEA_TILE_05,        // 0x42
	SEA_TILE_06,        // 0x43
	SEA_TILE_07,        // 0x44
	SEA_TILE_08,        // 0x45
	SEA_TILE_09,        // 0x46
	SEA_TILE_0A,        // 0x47
	SEA_TILE_0B,        // 0x48
	SAND_TILE_01,       // 0x49
	TSUNAMI_TILE_00,    // 0x4A
	TSUNAMI_TILE_01,    // 0x4B
	WORM_TILE_00,       // 0x4C
	WORM_TILE_01,       // 0x4D
	DUSTCLOUD_TILE_00,  // 0x4E
	DUSTCLOUD_TILE_01,  // 0x4F
	GUI_TILE_00,        // 0x50
	GUI_TILE_01,        // 0x51
	GUI_TILE_02,        // 0x52
	HEART_TILE_01,      // 0x53
	GUI_TILE_03,        // 0x54
	FRAME_TILE_09,      // 0x55
	FRAME_TILE_0A,      // 0x56
	FOOD_TILE_00,       // 0x57
	POTION_TILE_00,     // 0x58
	RING_TILE_00,       // 0x59
	SCROLL_TILE_00,     // 0x5A
	LIGHT_TILE_00,      // 0x5B
	ROPE_TILE_00,       // 0x5C
	KEY_TILE_00,        // 0x5D
	FLOOR_TILE_00,      // 0x5E
	FLOOR_TILE_01,      // 0x5F
	FLOOR_TILE_02,      // 0x60
	WALL_TILE_00,       // 0x61
	WALL_TILE_01,       // 0x62
	WALL_TILE_02,       // 0x63
	FLOOR_TILE_03,      // 0x64
	FLOOR_TILE_04,      // 0x65
	FLOOR_TILE_05,      // 0x66
	WALL_TILE_03,       // 0x67
	WALL_TILE_04,       // 0x68
	WALL_TILE_05,       // 0x69
	WALL_TILE_06,       // 0x6A
	FLOOR_TILE_06,      // 0x6B
	FLOOR_TILE_07,      // 0x6C
	FLOOR_TILE_08,      // 0x6D
	DOOR_TILE_00,       // 0x6E
	DOOR_TILE_01,       // 0x6F
	NPC_TILE_00,        // 0x70
	NPC_TILE_01,        // 0x71
	FRAME_TILE_0B
} SpriteTag;

//----------------------------------------------------------------------
typedef struct {
	int w, h;
	SDL_Surface* tile;
} Sprite;

#endif
