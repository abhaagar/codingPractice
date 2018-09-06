#include "Wall.h"
#include "global.h"

//---- Wall ---------------------------------------------------------

Wall::Wall() : MapSite() { }

Wall::~Wall() { }

void Wall::Enter() {
	/* Um Code erweitern, falls Maze fuer Spiel verwendet wird */
}

void Wall::Print(int indent) {
	PrintIndent(indent);
	printf("Wall:\n");

	MapSite::Print(indent+2);
}
