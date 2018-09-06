#include "MapSite.h"

//---- MapSite ---------------------------------------------------------

MapSite::MapSite() : Object() { }

MapSite::~MapSite() { }

void MapSite::Print(int indent) {
	PrintIndent(indent);
	printf("MapSite:\n");
	
	Object::Print(indent+2);
}
