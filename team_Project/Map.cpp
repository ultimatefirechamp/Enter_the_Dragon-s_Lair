#include"stdafx.h"
#include "Map.h"

Map::Map() {
	m_showOpen = false;
	m_showClosed = false;
}

Map::~Map() {
	ClearMap();
}

void Map::ClearMap() {
	for (TileRow* row : map_tiles)
	{
		for (Tile* tile : row->tiles)
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

void Map::SetTile() {
	for (int x = 0; x < map_tiles.size(); x++) {
		for (int y = 0; y < map_tiles[x]->tiles.size(); y++) {
			if (x == 0 && y == 0) { // LEFTUP CORNER
				map_tiles[x]->tiles[y]->u = NULL;
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = NULL;
				map_tiles[x]->tiles[y]->ur = NULL;
				map_tiles[x]->tiles[y]->dl = NULL;
				map_tiles[x]->tiles[y]->dr = map_tiles[x + 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = NULL;
			}
			else if (x == map_tiles.size() - 1 && y == 0) {//RIGHTUP CORNER
				map_tiles[x]->tiles[y]->u = NULL;
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = NULL;
				map_tiles[x]->tiles[y]->ur = NULL;
				map_tiles[x]->tiles[y]->dl = map_tiles[x - 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->dr = NULL;
				map_tiles[x]->tiles[y]->r = NULL;
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
			else if (x == 0 && y == map_tiles[x]->tiles.size() - 1) {//LEFTDOWN CORNER
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = NULL;
				map_tiles[x]->tiles[y]->ul = NULL;
				map_tiles[x]->tiles[y]->ur = map_tiles[x + 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->dl = NULL;
				map_tiles[x]->tiles[y]->dr = NULL;
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = NULL;
			}
			else if (x == map_tiles.size() - 1 && y == map_tiles[x]->tiles.size() - 1) {//RIGHTDOWN CORNER
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = NULL;
				map_tiles[x]->tiles[y]->ul = map_tiles[x - 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->ur = NULL;
				map_tiles[x]->tiles[y]->dl = NULL;
				map_tiles[x]->tiles[y]->dr = NULL;
				map_tiles[x]->tiles[y]->r = NULL;
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
			else if (y == 0) {//UPBOUND EXCEPT CORNER
				map_tiles[x]->tiles[y]->u = NULL;
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = NULL;
				map_tiles[x]->tiles[y]->ur = NULL;
				map_tiles[x]->tiles[y]->dl = map_tiles[x - 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->dr = map_tiles[x + 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
			else if (y == map_tiles[0]->tiles.size() - 1) {//DOWNBOUND EXCEPT CORNER
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = NULL;
				map_tiles[x]->tiles[y]->ul = map_tiles[x - 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->ur = map_tiles[x + 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->dl = NULL;
				map_tiles[x]->tiles[y]->dr = NULL;
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
			else if (x == 0) {//LEFTBOUND EXCEPT CORNER
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = NULL;
				map_tiles[x]->tiles[y]->ur = map_tiles[x + 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->dl = NULL;
				map_tiles[x]->tiles[y]->dr = map_tiles[x + 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = NULL;
			}
			else if (x == map_tiles.size() - 1) {//RIGHTBOUND EXCEPT CORNER
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = map_tiles[x - 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->ur = NULL;
				map_tiles[x]->tiles[y]->dl = map_tiles[x - 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->dr = NULL;
				map_tiles[x]->tiles[y]->r = NULL;
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
			else {
				map_tiles[x]->tiles[y]->u = map_tiles[x]->tiles[y - 1];
				map_tiles[x]->tiles[y]->d = map_tiles[x]->tiles[y + 1];
				map_tiles[x]->tiles[y]->ul = map_tiles[x - 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->ur = map_tiles[x + 1]->tiles[y - 1];
				map_tiles[x]->tiles[y]->dl = map_tiles[x - 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->dr = map_tiles[x + 1]->tiles[y + 1];
				map_tiles[x]->tiles[y]->r = map_tiles[x + 1]->tiles[y];
				map_tiles[x]->tiles[y]->l = map_tiles[x - 1]->tiles[y];
			}
		}
	}
}