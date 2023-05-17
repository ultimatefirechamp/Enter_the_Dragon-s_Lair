#include"stdafx.h"
#include "Pathfinding.h"

bool SortTiles(const Tile* _i, const Tile* _j)
{
	return _i->fVal < _j->fVal;
}

PathAlgorithm::PathAlgorithm() {
	m_timeLimit = 1.0/600.0f;
}

PathAlgorithm::~PathAlgorithm() {}

void PathAlgorithm::CalculatePath(Path* &path) {
	m_timeCurrent = 0;
	m_newTicks = SDL_GetTicks();
	while (m_timeCurrent < m_timeLimit) {
		m_oldTicks = m_newTicks;
		m_newTicks = SDL_GetTicks();
		m_timeCurrent += (m_newTicks - m_oldTicks) / 1000.0f;
		path->time += (m_newTicks - m_oldTicks) / 1000.0f;
		if (!path->calculated) {
			if (path->open.size() > 0) {
				std::sort(path->open.begin(), path->open.end(), SortTiles);
				std::vector<Tile*> tileCheck = path->open;
				float CheckVal = tileCheck.at(0)->fVal;

				for (Tile* tile : tileCheck) {
					if (tile->fVal == CheckVal) {
						if (CalculateTileValue(tile, tileCheck, path)) {
							break;
						}
					}
					else {
						break;
					}
				}

			}
			else {
				path->calculated = true;
				path->routed = true;
				path->reached = false;
				break;
			}
			if (path->calculated) {
				break;
			}
		}
	}
}

bool PathAlgorithm::CalculateTileValue(Tile* tile, std::vector<Tile*> sortedTiles, Path*& path) {
	int loop = 8;
	if (!path->diagonal) {
		loop = 4;
	}

	for (int i = 0; i < loop; i++) {
		Tile* affector;
		int diag = 0;
		switch (i)
		{
		default:
		case 0:
			affector = tile->u;
			break;
		case 1:
			affector = tile->l;
			break;
		case 2:
			affector = tile->r;
			break;
		case 3:
			affector = tile->d;
			break;
		case 4:
			affector = tile->ul;
			diag = 1;
			break;
		case 5:
			affector = tile->ur;
			diag = 2;
			break;
		case 6:
			affector = tile->dl;
			diag = 3;
			break;
		case 7:
			affector = tile->dr;
			diag = 4;
			break;
		}
		if (affector != NULL) {
			if (affector == path->end){ //&& CheckTileCorners(tile, diag)) {
				path->calculated = true;
				path->reached = true;

				affector->parent = tile;
				Tile* traceback = affector;
				while (traceback != path->start) {
					path->positions.push_back(traceback);
					traceback = traceback->parent;
					/*if (path->positions.size() == path->closed.size()) {
						break;
					}*/
				}

				path->positions.push_back(path->start);
				path->index = path->positions.size() - 1;
				path->routed = true;
				return true;
			}
			else {
				if (!affector->closed && affector->IsWalkable && affector->onCharacter == NULL){ //&& CheckTileCorners(tile, diag)) {
					affector->hVal = CalculateDistance(affector, path->end);
					if (diag != 0) {
						affector->gVal = m_diagTileDist * affector->parameter;
					}
					else {
						affector->gVal = m_normalTileDist * affector->parameter;
					}
					affector->fVal = affector->gVal + affector->hVal;
					if (!affector->open) {
						AddOpenTile(affector, path->open);
						affector->parent = tile;
					}
				}
			}
		}
	}
	
	path->open.erase(path->open.begin());
	AddClosedTile(tile, path->closed);
	return false;

}

bool PathAlgorithm::CheckTileCorners(Tile* tile, int dir) { 

	switch (dir) {
	default:
		return true;
		break;
	case 1:
		if (tile->u == NULL || tile->l == NULL)
		{
			return false;
		}
		if (tile->u->IsWalkable && tile->l->IsWalkable)
		{
			return true;
		}
		break;
	case 2:
		if (tile->u == NULL || tile->r == NULL) {
			return false;
		}
		if (tile->u->IsWalkable && tile->r->IsWalkable) {
			return true;
		}
	case 3:
		if (tile->d == NULL || tile->l == NULL)
		{
			return false;
		}
		if (tile->d->IsWalkable && tile->l->IsWalkable)
		{
			return true;
		}
		break;
	case 4:
		if (tile->d == NULL || tile->r == NULL)
		{
			return false;
		}
		if (tile->d->IsWalkable && tile->r->IsWalkable)
		{
			return true;
		}
		break;
	}
	return false;
}

float PathAlgorithm::CalculateDistance(Tile* start, Tile* end) {
	float xVal = start->mapX - end->mapX;
	float yVal = start->mapY - end->mapY;
	if (xVal == 1 || yVal == 1) {
		return 1;
	}
}

void PathAlgorithm::AddOpenTile(Tile* tile, std::vector<Tile*>& open) {
	open.push_back(tile);
	open.back()->open = true;
	open.back()->closed = false;
}

void PathAlgorithm::AddClosedTile(Tile* tile, std::vector<Tile*>& close) {
	close.push_back(tile);
	close.back()->open = false;
	close.back()->closed = true;
}

void PathAlgorithm::ResetPath(Path*& path) {
	for (Tile* tile : path->open) {
		tile->open = false;
		tile->closed = false;
		tile->parent = NULL;
		tile->gVal = 0;
		tile->hVal = 0;
		tile->fVal = 0;
	}
	path->open.clear();
	for (Tile* tile : path->closed) {
		tile->open = false;
		tile->closed = false;
		tile->parent = NULL;
		tile->gVal = 0;
		tile->hVal = 0;
		tile->fVal = 0;
	}
	path->closed.clear();
	for (Tile* tile : path->positions) {
		tile->open = false;
		tile->closed = false;
		tile->parent = NULL;
		tile->gVal = 0;
		tile->hVal = 0;
		tile->fVal = 0;
	}
	path->positions.clear();
	path->points.clear();
	path->calculated = false;
	path->routed = false;
	path->reached = false;
	path->index = 0;
	path->time = 0.0f;
	path->start = NULL;
	path->end = NULL;
}

