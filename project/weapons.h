#pragma once
#include <string>

using namespace std;

class weapon {
protected:
	unsigned damage;
	int durability;
	unsigned handling;
	string name;
public:
	weapon(unsigned d, int du, unsigned h, string n);
	virtual void usegun() = 0;
	unsigned getdamage() const;
	const string getname() const;
	int getdu() const;
	unsigned geth() const;
	virtual unsigned getbullet() const = 0;
};

class meele : public weapon {

	string type;
public:
	meele(unsigned d, int du, unsigned h, string n, string t);
	void usegun();
	unsigned getbullet() const;
};

class gun :public weapon {

	unsigned bullet;
public:
	gun(unsigned d, int du, unsigned h, string n, unsigned bn);
	void usegun();
	unsigned getbullet() const;
};
