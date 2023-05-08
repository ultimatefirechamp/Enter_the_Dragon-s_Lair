#include "Map.h"

Map::Map() {
	m_showOpen = false;
	m_showClosed = false;
}

Map::~Map() {
	ClearMap();
}

void Map::ClearMap() {
	for(TileRow* row : map_tiles)
	{
		for(Tile * tile : row->tiles)
		{
			delete tile;
		}
		row->tiles.clear();
		delete row;
	}
	map_tiles.clear();
}

Tile* Map::GetTileInfo(int x, int y) {
	if (map_tiles.at(x)->tiles.at(y) != NULL) {
		return map_tiles.at(x)->tiles.at(y);
	}
	return NULL;
}
Tile* Map::GetSelectedTile() { return NULL; }

bool Map::CheckSurroundings(Tile* tile) { 
	if ((tile->u == NULL || tile->IsWalkable) && (tile->ur == NULL || tile->IsWalkable) && (tile->ul == NULL || tile->IsWalkable)
		&& (tile->d == NULL || tile->IsWalkable) && (tile->dl == NULL || tile->IsWalkable) && (tile->dr == NULL || tile->IsWalkable)
		&& (tile->r == NULL || tile->IsWalkable) && (tile->l == NULL || tile->IsWalkable)) {
		return false;
	}
	return true;
}
void Map::ResetStartEnd() {
	m_startTile = NULL;
	m_endTile = NULL;
}