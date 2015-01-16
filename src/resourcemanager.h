//-----------------------------------------------------------------------------
#ifndef _RESOURCEMANAGER_HEADER_
#define _RESOURCEMANAGER_HEADER_

//-----------------------------------------------------------------------------
#include "spriteid.h"

/* resourcemanager.h */
//-----------------------------------------------------------------------------
class ResourceManager {
private:
	ResourceManager(ResourceManager const&);
	void operator = (ResourceManager const&);

	ResourceManager(void);
	~ResourceManager(void);

	Sprite* _sprites[SpriteID::NUM_SPRITES];

public:
	static ResourceManager& getRef(void) {
		static ResourceManager instance;
		return instance;
	}

	Sprite* getSprite(SpriteID id);
};

/* resourcemanager.cpp */
//-----------------------------------------------------------------------------
ResourceManager::ResourceManager(void) {
	//% === %
	int emptyTile[2*2] = {
		  0,   0,
		  0,   0
	};
	_sprites[SpriteID::EMPTY] = buildSprite(2, 2, emptyTile);

	//% === %
	int boatTile00[6*2] = {
		 97,  98,  99, 100, 101, 102,
		129, 130, 131, 132, 133, 134
	};
	_sprites[SpriteID::BOAT00] = buildSprite(6, 2, boatTile00);

	//% === %
	int frameTile08[2*2] = {
		135, 135,
		135, 135
	};
	_sprites[SpriteID::FRAME08] = buildSprite(2, 2, frameTile08);

	//% === %
	int brickTile00[2*2] = {
		104, 105,
		136, 137
	};
	_sprites[SpriteID::BRICK00] = buildSprite(2, 2, brickTile00);

	//% === %
	int treeTile00[2*2] = {
		106, 107,
		138, 139
	};
	_sprites[SpriteID::TREE00] = buildSprite(2, 2, treeTile00);

	//% === %
	int seaTile00[2*2] = {
		108, 109,
		140, 141
	};
	_sprites[SpriteID::SEA00] = buildSprite(2, 2, seaTile00);

	//% === %
	int sandTile00[2*2] = {
		122, 123,
		154, 155
	};
	_sprites[SpriteID::SAND00] = buildSprite(2, 2, sandTile00);

	//% === %
	int frameTile00[2*2] = {
		110, 144,
		112, 135
	};
	_sprites[SpriteID::FRAME00] = buildSprite(2, 2, frameTile00);

	//% === %
	int frameTile01[2*2] = {
		144, 111,
		135, 113
	};
	_sprites[SpriteID::FRAME01] = buildSprite(2, 2, frameTile01);

	//% === %
	int frameTile02[2*2] = {
		112, 135,
		142, 145
	};
	_sprites[SpriteID::FRAME02] = buildSprite(2, 2, frameTile02);

	//% === %
	int frameTile03[2*2] = {
		135, 113,
		145, 143
	};
	_sprites[SpriteID::FRAME03] = buildSprite(2, 2, frameTile03);

	//% === %
	int frameTile04[2*2] = {
		112, 135,
		112, 135
	};
	_sprites[SpriteID::FRAME04] = buildSprite(2, 2, frameTile04);

	//% === %
	int frameTile05[2*2] = {
		135, 113,
		135, 113
	};
	_sprites[SpriteID::FRAME05] = buildSprite(2, 2, frameTile05);

	//% === %
	int frameTile06[2*2] = {
		144, 144,
		135, 135
	};
	_sprites[SpriteID::FRAME06] = buildSprite(2, 2, frameTile06);

	//% === %
	int frameTile07[2*2] = {
		135, 135,
		145, 145
	};
	_sprites[SpriteID::FRAME07] = buildSprite(2, 2, frameTile07);

	//% === %
	int enemyShipTile00[2*4] = {
		114, 115,
		146, 147,
		116, 117,
		148, 149
	};
	_sprites[SpriteID::ENEMYSHIP00] = buildSprite(2, 4, enemyShipTile00);

	//% === %
	int grassTile00[2*2] = {
		118, 119,
		150, 151
	};
	_sprites[SpriteID::GRASS00] = buildSprite(2, 2, grassTile00);

	//% === %
	int playerTile00[2*2] = {
		120, 121,
		152, 153
	};
	_sprites[SpriteID::PLAYER00] = buildSprite(2, 2, playerTile00);

	//% === %
	int playerTile01[2*2] = {
		124, 125,
		156, 157
	};
	_sprites[SpriteID::PLAYER01] = buildSprite(2, 2, playerTile01);

	//% === %
	int selectBoxTile00[3*4] = {
		110, 144, 111,
		112,   0, 113,
		112,   0, 113,
		142,   0, 143
	};
	_sprites[SpriteID::SELECTBOX00] = buildSprite(3, 4, selectBoxTile00);

	//% === %
	int heartTile00[1*2] = {
		126,
		158
	};
	_sprites[SpriteID::HEART00] = buildSprite(1, 2, heartTile00);

	//% === %
	int coinTile00[1*2] = {
		127,
		159
	};
	_sprites[SpriteID::COIN00] = buildSprite(1, 2, coinTile00);

	//% === %
	int rockTile00[2*2] = {
		161, 162,
		193, 194
	};
	_sprites[SpriteID::ROCK00] = buildSprite(2, 2, rockTile00);

	//% === %
	int attackTile00[2*2] = {
		163, 164,
		195, 196
	};
	_sprites[SpriteID::ATTACK00] = buildSprite(2, 2, attackTile00);

	//% === %
	int attackTile01[2*2] = {
		165, 166,
		197, 198
	};
	_sprites[SpriteID::ATTACK01] = buildSprite(2, 2, attackTile01);

	//% === %
	int attackTile02[2*2] = {
		167, 168,
		199, 200
	};
	_sprites[SpriteID::ATTACK02] = buildSprite(2, 2, attackTile02);

	//% === %
	int attackTile03[2*2] = {
		169, 170,
		201, 202
	};
	_sprites[SpriteID::ATTACK03] = buildSprite(2, 2, attackTile03);

	//% === %
	int attackTile04[2*2] = {
		171, 172,
		203, 204
	};
	_sprites[SpriteID::ATTACK04] = buildSprite(2, 2, attackTile04);

	//% === %
	int attackTile05[2*2] = {
		173, 174,
		205, 206
	};
	_sprites[SpriteID::ATTACK05] = buildSprite(2, 2, attackTile05);

	//% === %
	int attackTile06[2*2] = {
		175, 176,
		207, 208
	};
	_sprites[ATTACK06] = buildSprite(2, 2, attackTile06);

	//% === %
	int attackTile07[2*2] = {
		177, 178,
		209, 210
	};
	_sprites[SpriteID::ATTACK07] = buildSprite(2, 2, attackTile07);

	//% === %

	int shieldTile00[2*2] = {
		179, 180,
		211, 212
	};
	_sprites[SpriteID::SHIELD00] = buildSprite(2, 2, shieldTile00);

	//% === %
	int bugTile00[2*2] = {
		181, 182,
		213, 214
	};
	_sprites[SpriteID::BUG00] = buildSprite(2, 2, bugTile00);

	//% === %
	int bugTile01[2*2] = {
		183, 184,
		215, 216
	};
	_sprites[SpriteID::BUG01] = buildSprite(2, 2, bugTile01);

	//% === %

	int smallflameTile00[2*2] = {
		185, 186,
		217, 218
	};
	_sprites[SpriteID::SMALLFLAME00] = buildSprite(2, 2, smallflameTile00);

	//% === %
	int smallflameTile01[2*2] = {
		187, 188,
		219, 220
	};
	_sprites[SpriteID::SMALLFLAME01] = buildSprite(2, 2, smallflameTile01);

	//% === %
	int playerTile02[2*2] = {
		189, 190,
		221, 222
	};
	_sprites[SpriteID::PLAYER02] = buildSprite(2, 2, playerTile02);

	//% === %
	int playerTile03[2*2] = {
		191, 192,
		223, 224
	};
	_sprites[SpriteID::PLAYER03] = buildSprite(2, 2, playerTile03);

	//% === %
	int playerTile04[2*2] = {
		225, 226,
		257, 258
	};
	_sprites[SpriteID::PLAYER04] = buildSprite(2, 2, playerTile04);

	//% === %
	int playerTile05[2*2] = {
		227, 228,
		259, 260
	};
	_sprites[SpriteID::PLAYER05] = buildSprite(2, 2, playerTile05);

	//% === %
	int playerTile06[2*2] = {
		229, 230,
		261, 262
	};
	_sprites[SpriteID::PLAYER06] = buildSprite(2, 2, playerTile06);

	/*
	//% === %

	int playerTile07[2*2] = {
		231, 232,
		263, 264
	}; buildSprite(PLAYER_TILE_07, 2, 2, playerTile07);

	//% === %

	int playerTile08[2*2] = {
		233, 234,
		265, 266
	}; buildSprite(PLAYER_TILE_08, 2, 2, playerTile08);

	//% === %

	int playerTile09[2*2] = {
		235, 236,
		267, 268
	}; buildSprite(PLAYER_TILE_09, 2, 2, playerTile09);

	//% === %

	int playerTile0A[2*2] = {
		237, 238,
		269, 270
	}; buildSprite(PLAYER_TILE_0A, 2, 2, playerTile0A);

	//% === %

	int playerTile0B[2*2] = {
		239, 240,
		271, 272
	}; buildSprite(PLAYER_TILE_0B, 2, 2, playerTile0B);

	//% === %

	int treeTile01[2*2] = {
		241, 242,
		273, 274
	}; buildSprite(TREE_TILE_01, 2, 2, treeTile01);

	//% === %

	int treeTile02[2*2] = {
		243, 244,
		275, 276
	}; buildSprite(TREE_TILE_02, 2, 2, treeTile02);

	//% === %

	int treeTile03[2*2] = {
		245, 246,
		277, 278
	}; buildSprite(TREE_TILE_03, 2, 2, treeTile03);

	//% === %

	int treeTile04[2*2] = {
		247, 248,
		279, 280
	}; buildSprite(TREE_TILE_04, 2, 2, treeTile04);

	//% === %

	int treeTile05[2*2] = {
		249, 250,
		281, 282
	}; buildSprite(TREE_TILE_05, 2, 2, treeTile05);

	//% === %

	int treeTile06[2*2] = {
		251, 252,
		283, 284
	}; buildSprite(TREE_TILE_06, 2, 2, treeTile06);

	//% === %

	int treeTile07[2*2] = {
		253, 254,
		285, 286
	}; buildSprite(TREE_TILE_07, 2, 2, treeTile07);

	//% === %

	int treeTile08[2*2] = {
		255, 256,
		287, 288
	}; buildSprite(TREE_TILE_08, 2, 2, treeTile08);

	//% === %

	int treeTile09[2*2] = {
		289, 290,
		321, 322
	}; buildSprite(TREE_TILE_09, 2, 2, treeTile09);

	//% === %

	int rockTile01[2*2] = {
		291, 292,
		323, 324
	}; buildSprite(ROCK_TILE_01, 2, 2, rockTile01);

	//% === %

	int rockTile02[2*2] = {
		293, 294,
		325, 326
	}; buildSprite(ROCK_TILE_02, 2, 2, rockTile02);

	//% === %

	int rockTile03[2*2] = {
		295, 296,
		327, 328
	}; buildSprite(ROCK_TILE_03, 2, 2, rockTile03);

	//% === %

	int rockTile04[2*2] = {
		297, 298,
		329, 330
	}; buildSprite(ROCK_TILE_04, 2, 2, rockTile04);

	//% === %

	int rockTile05[2*2] = {
		299, 300,
		331, 332
	}; buildSprite(ROCK_TILE_05, 2, 2, rockTile05);

	//% === %

	int seaTile01[2*2] = {
		301, 302,
		333, 334
	}; buildSprite(SEA_TILE_01, 2, 2, seaTile01);

	//% === %

	int fishTile00[2*2] = {
		303, 304,
		335, 336
	}; buildSprite(FISH_TILE_00, 2, 2, fishTile00);

	//% === %

	int fishTile01[2*2] = {
		305, 306,
		337, 338
	}; buildSprite(FISH_TILE_01, 2, 2, fishTile01);

	//% === %

	int seaTile02[2*2] = {
		307, 308,
		339, 340
	}; buildSprite(SEA_TILE_02, 2, 2, seaTile02);

	//% === %

	int seaTile03[2*2] = {
		309, 310,
		341, 342
	}; buildSprite(SEA_TILE_03, 2, 2, seaTile03);

	//% === %

	int seaTile04[2*2] = {
		311, 312,
		343, 344
	}; buildSprite(SEA_TILE_04, 2, 2, seaTile04);

	//% === %

	int seaTile05[2*2] = {
		313, 314,
		345, 346
	}; buildSprite(SEA_TILE_05, 2, 2, seaTile05);

	//% === %

	int seaTile06[2*2] = {
		315, 316,
		347, 348
	}; buildSprite(SEA_TILE_06, 2, 2, seaTile06);

	//% === %

	int seaTile07[2*2] = {
		317, 318,
		349, 350
	}; buildSprite(SEA_TILE_07, 2, 2, seaTile07);

	//% === %

	int seaTile08[2*2] = {
		319, 320,
		351, 352
	}; buildSprite(SEA_TILE_08, 2, 2, seaTile08);

	//% === %

	int seaTile09[2*2] = {
		353, 354,
		385, 386
	}; buildSprite(SEA_TILE_09, 2, 2, seaTile09);

	//% === %

	int seaTile0A[2*2] = {
		355, 356,
		387, 388
	}; buildSprite(SEA_TILE_0A, 2, 2, seaTile0A);

	//% === %

	int seaTile0B[2*2] = {
		357, 358,
		389, 390
	}; buildSprite(SEA_TILE_0B, 2, 2, seaTile0B);

	//% === %

	int sandTile01[2*2] = {
		359, 360,
		391, 392
	}; buildSprite(SAND_TILE_01, 2, 2, sandTile01);

	//% === %

	int tsunamiTile00[2*2] = {
		361, 362,
		393, 394
	}; buildSprite(TSUNAMI_TILE_00, 2, 2, tsunamiTile00);

	//% === %

	int tsunamiTile01[2*2] = {
		363, 364,
		395, 396
	}; buildSprite(TSUNAMI_TILE_01, 2, 2, tsunamiTile01);

	//% === %

	int wormTile00[2*2] = {
		365, 366,
		397, 398
	}; buildSprite(WORM_TILE_00, 2, 2, wormTile00);

	//% === %

	int wormTile01[2*2] = {
		367, 368,
		399, 400
	}; buildSprite(WORM_TILE_01, 2, 2, wormTile01);

	//% === %

	int dustcloudTile00[2*2] = {
		369, 370,
		401, 402
	}; buildSprite(DUSTCLOUD_TILE_00, 2, 2, dustcloudTile00);

	//% === %

	int dustcloudTile01[2*2] = {
		371, 372,
		403, 404
	}; buildSprite(DUSTCLOUD_TILE_01, 2, 2, dustcloudTile01);

	//% === %

	int guiTile00[2*2] = {
		373, 374,
		405, 406
	}; buildSprite(GUI_TILE_00, 2, 2, guiTile00);

	//% === %

	int guiTile01[2*2] = {
		375, 376,
		407, 408
	}; buildSprite(GUI_TILE_01, 2, 2, guiTile01);

	//% === %

	int guiTile02[2*2] = {
		377, 378,
		409, 410
	}; buildSprite(GUI_TILE_02, 2, 2, guiTile02);

	//% === %

	int heartTile01[2*2] = {
		379, 380,
		411, 412
	}; buildSprite(HEART_TILE_01, 2, 2, heartTile01);

	//% === %

	int guiTile03[2*2] = {
		381, 382,
		413, 414
	}; buildSprite(GUI_TILE_03, 2, 2, guiTile03);

	//% === %

	int frameTile09[19*4] = {
		383, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 452, 384,
		420, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 421,
		420, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 421,
		415, 453, 453, 453, 453, 453, 453, 453, 135, 135, 135, 453, 453, 453, 453, 453, 453, 453, 416
	}; buildSprite(FRAME_TILE_09, 19, 4, frameTile09);

	//% === %

	int frameTile0A[3*4] = {
		417, 418, 419,
		449, 450, 451,
		481, 482, 483,
		513, 514, 515
	}; buildSprite(FRAME_TILE_0A, 3, 4, frameTile0A);

	//% === %

	int foodTile00[2*2] = {
		422, 423,
		454, 455
	}; buildSprite(FOOD_TILE_00, 2, 2, foodTile00);

	//% === %

	int potionTile00[2*2] = {
		424, 425,
		456, 457
	}; buildSprite(POTION_TILE_00, 2, 2, potionTile00);

	//% === %

	int ringTile00[2*2] = {
		426, 427,
		458, 459
	}; buildSprite(RING_TILE_00, 2, 2, ringTile00);

	//% === %

	int scrollTile00[2*2] = {
		428, 429,
		460, 461
	}; buildSprite(SCROLL_TILE_00, 2, 2, scrollTile00);

	//% === %

	int lightTile00[2*2] = {
		430, 431,
		462, 463
	}; buildSprite(LIGHT_TILE_00, 2, 2, lightTile00);

	//% === %

	int ropeTile00[2*2] = {
		432, 433,
		464, 465
	}; buildSprite(ROPE_TILE_00, 2, 2, ropeTile00);

	//% === %

	int keyTile00[2*2] = {
		434, 435,
		466, 467
	}; buildSprite(KEY_TILE_00, 2, 2, keyTile00);

	//% === %

	int floorTile00[2*2] = {
		436, 437,
		468, 469
	}; buildSprite(FLOOR_TILE_00, 2, 2, floorTile00);

	//% === %

	int floorTile01[2*2] = {
		438, 439,
		470, 471
	}; buildSprite(FLOOR_TILE_01, 2, 2, floorTile01);

	//% === %

	int floorTile02[2*2] = {
		440, 441,
		472, 473
	}; buildSprite(FLOOR_TILE_02, 2, 2, floorTile02);

	//% === %

	int wallTile00[2*2] = {
		442, 443,
		474, 475
	}; buildSprite(WALL_TILE_00, 2, 2, wallTile00);

	//% === %

	int wallTile01[2*2] = {
		444, 445,
		476, 477
	}; buildSprite(WALL_TILE_01, 2, 2, wallTile01);

	//% === %

	int wallTile02[2*2] = {
		446, 447,
		478, 479
	}; buildSprite(WALL_TILE_02, 2, 2, wallTile02);

	//% === %

	int floorTile03[2*2] = {
		500, 501,
		532, 533
	}; buildSprite(FLOOR_TILE_03, 2, 2, floorTile03);

	//% === %

	int floorTile04[2*2] = {
		502, 503,
		534, 535
	}; buildSprite(FLOOR_TILE_04, 2, 2, floorTile04);

	//% === %

	int floorTile05[2*2] = {
		504, 505,
		536, 537
	}; buildSprite(FLOOR_TILE_05, 2, 2, floorTile05);

	//% === %

	int wallTile03[2*2] = {
		506, 507,
		538, 539
	}; buildSprite(WALL_TILE_03, 2, 2, wallTile03);

	//% === %

	int wallTile04[2*2] = {
		570, 571,
		602, 603
	}; buildSprite(WALL_TILE_04, 2, 2, wallTile04);

	//% === %

	int wallTile05[2*2] = {
		572, 573,
		604, 605
	}; buildSprite(WALL_TILE_05, 2, 2, wallTile05);

	//% === %

	int wallTile06[2*2] = {
		574, 575,
		606, 607
	}; buildSprite(WALL_TILE_06, 2, 2, wallTile06);

	//% === %

	int floorTile06[2*2] = {
		568, 569,
		600, 601
	}; buildSprite(FLOOR_TILE_06, 2, 2, floorTile06);

	//% === %

	int floorTile07[2*2] = {
		566, 567,
		598, 599
	}; buildSprite(FLOOR_TILE_07, 2, 2, floorTile07);

	//% === %

	int floorTile08[2*2] = {
		564, 565,
		596, 597
	}; buildSprite(FLOOR_TILE_08, 2, 2, floorTile08);

	//% === %

	int doorTile00[2*2] = {
		562, 563,
		594, 595
	}; buildSprite(DOOR_TILE_00, 2, 2, doorTile00);

	//% === %

	int doorTile01[2*2] = {
		560, 561,
		592, 593
	}; buildSprite(DOOR_TILE_01, 2, 2, doorTile01);

	//% === %

	int npcTile00[2*2] = {
		558, 559,
		590, 591
	}; buildSprite(NPC_TILE_00, 2, 2, npcTile00);

	//% === %

	int npcTile01[2*2] = {
		556, 557,
		588, 589
	}; buildSprite(NPC_TILE_01, 2, 2, npcTile01);

	//% === %

	int frameTile0B[20*6] = {
		554, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 584, 555,
		552, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 553,
		552, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 553,
		552, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 553,
		552, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 551, 553,
		586, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 585, 587
	}; buildSprite(FRAME_TILE_0B, 20, 6, frameTile0B);
	*/
}

ResourceManager::~ResourceManager(void) {
	for(int i=0; i<SpriteID::NUM_SPRITES; i++) {
		freeSprite(_sprites[i]);
	}
}

Sprite* ResourceManager::getSprite(SpriteID id) {
	if(id<0||id>=SpriteID::NUM_SPRITES) return NULL;
	return _sprites[id];
}

#endif
