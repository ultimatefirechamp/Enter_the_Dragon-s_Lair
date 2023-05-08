#pragma once
#include"Tile.h"
#include<vector>

class Tile;


class Map
{
	std::vector<std::vector<Tile*>> map_tiles();
	
};

