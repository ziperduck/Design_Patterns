#pragma once
#include <iostream>

using Mash = char*;
using Texture = std::string;

using Vector = int;

using Color = int;

class Tree {
public:

private:
	Mash mesh_;
	Texture bark_;
	Texture leaves_;

	int height_;
	Vector position_;
	Color barkTint_;
	Color leafTint_;
};

class Mash_Tree {
public:

private:
	Mash mesh_;
	Texture bark_;
	Texture leaves_;
};

class Light_Tree {
public:

private:
	Mash_Tree* model_;

	int height_;
	Vector position_;
	Color barkTint_;
	Color leafTint_;
};

enum class Terrain {
	TERRAIN_GRASS,
	TERRAIN_HILL,
	TERRAIN_RIVER
};

class Map {
	Terrain tiles[20][20];
};

class Light_Terrain {
public:
	Light_Terrain(int movement, bool water,const Texture text) 
		:movement_(movement),
		water_(water),
		text_(text){}

	int getmovement() { return movement_; }
	bool getwater() { return water_; }
	Texture gettext() { return text_; }

private:
	int movement_;
	bool water_;
	Texture text_;
};

class Light_Map {
public:
	Light_Map()
		:hill_(1,false,"hill"),
		grass_(2,false,"grass"),
		river_(3,true,"water") {

	}
	Light_Terrain gettile(int x, int y) { return *tiles_[x][y]; }
private:
	Light_Terrain hill_;
	Light_Terrain grass_;
	Light_Terrain river_;

	Light_Terrain* tiles_[20][20];
};

void Chater3_Main() {

}