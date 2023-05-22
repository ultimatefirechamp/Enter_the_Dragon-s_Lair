#pragma once
#include"Tile.h"
#include<vector>

class Tile;

struct TileRow {
	std::vector<Tile*> tiles;
};

class Map
{
public:
	Map();
	~Map();
	
	Tile* GetTileInfo(int x, int y);
	Tile* GetSelectedTile();

	bool GetShowOpen() { return false; }
	std::vector<TileRow*>& GetMap() {
		return map_tiles;
	}

	void SetTile();

private:
	bool m_showOpen, m_showClosed;
	std::vector<TileRow*> map_tiles;

	Tile* m_startTile;
	Tile* m_endTile;

	bool CheckSurroundings(Tile* tile);
	void ClearMap();
	void ResetStartEnd();

};

