#pragma once
#include "weapons.h"
#include "player.h"

using namespace std;

class enemy {
protected:
	string name;
	int life;
	unsigned dmg;
public:
	enemy(string n, int l, unsigned d);
	virtual void attack(player&) = 0;
	const string getname() const;
	int getlife() const;
	void setlife(int const el);
	unsigned getdamage() const;
};

class zombie :public enemy {

	int zlife;
public:
	zombie(string n, int l, unsigned d, int zl);
	void attack(player& p);
	int getzlife() const;
};

class human :public enemy {

	weapon& hw;
public:
	human(string n, int l, unsigned d, weapon& w);
	void attack(player& p);
	weapon& gethwpn() const;
};
