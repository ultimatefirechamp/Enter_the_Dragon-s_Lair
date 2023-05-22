#pragma once
#include"SDL.h"
#include<vector>
#include<string>
#include<algorithm>
#include"Tile.h"


struct Path {
	Tile* start;
	Tile* end;

	std::vector<Tile*> open;
	std::vector<Tile*> closed;

	std::vector<Tile*> positions;

	std::vector<SDL_Point> points;

	bool calculated = false;
	bool routed = false;
	bool reached = false;

	bool diagonal = true;

	int index = 0;

	float time = 0.0f;

};

class PathAlgorithm
{
public:
	PathAlgorithm();
	~PathAlgorithm();

	void CalculatePath(Path* &path);

	float CalculateDistance(Tile* start, Tile* end);
	bool CheckTileCorners(Tile* tile, int dir);
	void ResetPath(Path* &path);


private:
	const float m_normalTileDist = 1.0f;
	const float m_diagTileDist = 1.0f;

	float m_timeLimit, m_timeCurrent;
	Uint32 m_oldTicks, m_newTicks;


	bool CalculateTileValue(Tile* _tile, std::vector<Tile*> _sortedTiles, Path*& _path);

	void AddClosedTile(Tile* _tile, std::vector<Tile*>& _closed);
	void AddOpenTile(Tile* _tile, std::vector<Tile*>& _open);
};

