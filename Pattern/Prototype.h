#pragma once
#include <iostream>

class Monster {
public:
	Monster(int max,int hp):Max_HP(max),HP(hp){}
	virtual	~Monster() = default;
	void print_data() const { printf("Max_HP : %d, HP : %d\n", Max_HP, HP); }
private:
	const int Max_HP;
	const int HP;
};

class Zombi : public Monster {
public:
	Zombi() : Monster(101, 101) {}
	Zombi(int max, int hp) : Monster(max, hp){}

};

class Ghost : public Monster {
public:
	Ghost() : Monster(11, 11) {}
	Ghost(int max, int hp) : Monster(max, hp) {}

};

class Spawner {
public:
	virtual ~Spawner() = default;
	virtual Monster* Spawn() = 0;
};

template<typename T>
class Template_Spawner : public Spawner {
public:
	virtual ~Template_Spawner() = default;
	virtual Monster* Spawn() { return new T(); };

};

using Spawn_Fun = Monster * (*)();
Monster* SpawnZombi() { return new Zombi(); }
Monster* SpawnGhost() { return new Ghost(); }
class Function_Spawner : public Spawner {
public:
	Function_Spawner(Spawn_Fun fun) : fun(fun){}
	virtual ~Function_Spawner() = default;
	virtual Monster* Spawn() { return fun(); };
private:
	Spawn_Fun fun;
};

void Prototype_Main() {
	
	Template_Spawner<Zombi> zombi;
	Template_Spawner<Ghost> ghost;

	Monster* monst = zombi.Spawn();
	monst->print_data();

	monst = ghost.Spawn();
	monst->print_data();

	Function_Spawner f_zombi{ SpawnZombi };
	Function_Spawner f_ghost{ SpawnGhost };

	monst = f_zombi.Spawn();
	monst->print_data();

	monst = f_ghost.Spawn();
	monst->print_data();
}