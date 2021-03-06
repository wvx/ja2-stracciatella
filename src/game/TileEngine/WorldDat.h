#ifndef WORLD_DAT_H
#define WORLD_DAT_H

#include "Types.h"
#include "TileDat.h"
#include "World_Tileset_Enums.h"

#include <string_theory/string>


typedef void (*TILESET_CALLBACK)(void);


struct TILESET
{
	ST::string       zName;
	CHAR8            TileSurfaceFilenames[NUMBEROFTILETYPES][32];
	UINT8            ubAmbientID;
	TILESET_CALLBACK MovementCostFnc;
};



extern TILESET gTilesets[NUM_TILESETS];


void InitEngineTilesets(void);


// THESE FUNCTIONS WILL SET TERRAIN VALUES - CALL ONE FOR EACH TILESET
void SetTilesetOneTerrainValues(void);

#endif
