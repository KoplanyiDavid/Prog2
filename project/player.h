#pragma once
#include "weapons.h"

using namespace std;

class enemy;
class player {
protected:
	string name;
	int life;
	weapon& wpn;
	unsigned damage;
public:
	player(string n, int l, weapon& w, unsigned dam);
	void attack(enemy& e);
	void fistattack(enemy& e);
	const string getname() const;
	int getlife() const;
	void setlife(const int l);
	weapon& getweapon() const;
	unsigned getdamage() const;
};
