#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "weapons.h"
#include "enemies.h"
#include "player.h"

using namespace std;

int main()
{
	cout << "Initializing weapons..." << endl;
	meele baseballb(8, 8, 3, "baseballbaton", "meele");
	gun pistol(65, 6, 2, "pistol", 16);
	cout << "Initializing enemy..." << endl;
	human h("human", 100, 1, baseballb);
	zombie z("zombie", 200, 25, 50);
	cout << "Your enemies are: " << h.getname() << z.getname() << endl;
	cout << "Initializing player..." << endl;
	player p1("player1", 100, baseballb, 4);
	player p2("player2", 100, pistol, 4);
	int a;
	cout << "Choose a player: 1. player1 (baseballbaton), 2. player2 (pistol)" << endl;
	cin >> a;
	if (a == 1)
	{
		cout << "Your weapon is: " << p1.getweapon().getname() << endl << "Type of weapon: meele" << endl;
		cout << "What do you want to do? (attack, run)" << endl;
		string v;
		cin >> v;
		if (v == "run") {
			cout << "You survived the day." << endl;
		}
		if (v == "attack") {
			cout << "Who do you want to attack? (1: human, 2: zombie)" << endl;
			int a;
			cin >> a;
			if (a == 1) //p1 vs h
			{
				while (p1.getlife() > 0 && h.getlife() > 0) { //ciklikus összecsapások
					if (p1.getweapon().getdu() > 0)
					{
						cout << "You attack: " << endl;
						p1.attack(h);
						p1.getweapon().usegun();
						cout << "Human's life remaining: " << h.getlife() << endl;
						cout << "Weapon durability remaining: " << p1.getweapon().getdu() << endl;
						if (h.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Human attack: " << endl;
						h.attack(p1);
						cout << "Your life remaining: " << p1.getlife() << endl;
						if (p1.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
					if (p1.getweapon().getdu() < 1)
					{
						cout << "You attack with fists: " << endl;
						p1.fistattack(h);
						cout << "Human's life remaining: " << h.getlife() << endl;
						if (h.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Human attack: " << endl;
						h.attack(p1);
						cout << "Your life remaining: " << p1.getlife() << endl;
						if (p1.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
				}
			}
			if (a == 2) //p1 vs z
			{
				while (p1.getlife() > 0 && z.getlife() > 0) { //ciklikus összecsapások 
					if (p1.getweapon().getdu() > 0)
					{
						cout << "You attack: " << endl;
						p1.attack(z);
						p1.getweapon().usegun();
						cout << "Zombie's life remaining: " << z.getlife() << endl;
						cout << "Weapon durability remaining: " << p1.getweapon().getdu() << endl;
						if (z.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Zombie attack: " << endl;
						z.attack(p1);
						cout << "Your life remaining: " << p1.getlife() << endl;
						if (p1.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
					if (p1.getweapon().getdu() < 1)
					{
						cout << "You attack with fists: " << endl;
						p1.fistattack(z);
						cout << "Zombie's life remaining: " << z.getlife() << endl;
						if (z.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Zombie attack: " << endl;
						z.attack(p1);
						cout << "Your life remaining: " << p1.getlife() << endl;
						if (p1.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}

				}
			}
			/*else {
				cout << "ERROR" << endl;
			}*/
		}
		/*else {
			cout << "ERROR" << endl;
		}*/
	}
	if (a == 2) //p2
	{
		cout << "Your weapon is: " << p2.getweapon().getname() << endl << "Type of weapon: gun" << endl;
		cout << "What do you want to do? (attack, run)" << endl;
		string v;
		cin >> v;
		if (v == "run") {
			cout << "You survived the day" << endl;
		}
		if (v == "attack") {
			cout << "Who do you want to attack? (1: human, 2: zombie)" << endl;
			int a;
			cin >> a;
			if (a == 1) //p2 vs h
			{
				while (p2.getlife() > 0 && h.getlife() > 0 && pistol.getbullet() > 0) { //ciklikus összecsapások
					if (p2.getweapon().getdu() > 0)
					{
						cout << "You attack: " << endl;
						p2.attack(h);
						p2.getweapon().usegun();
						cout << "Human's life remaining: " << h.getlife() << endl;
						cout << "Weapon durability remaining: " << p2.getweapon().getdu() << endl;
						if (h.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Human attack: " << endl;
						h.attack(p2);
						cout << "Your life remaining: " << p2.getlife() << endl;
						if (p2.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
					if (p2.getweapon().getdu() < 1)
					{
						cout << "You attack with fists: " << endl;
						p2.fistattack(h);
						cout << "Human's life remaining: " << h.getlife() << endl;
						if (h.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Human attack: " << endl;
						h.attack(p2);
						cout << "Your life remaining: " << p2.getlife() << endl;
						if (p2.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}

				}
			}
			if (a == 2) //p2 vs z
			{
				while (p2.getlife() > 0 && z.getlife() > 0 && pistol.getbullet() > 0) { //ciklikus összecsapások
					if (p2.getweapon().getdu() > 0)
					{
						cout << "You attack: " << endl;
						p2.attack(z);
						p2.getweapon().usegun();
						cout << "Zombie's life remaining: " << z.getlife() << endl;
						cout << "Weapon durability remaining: " << p2.getweapon().getdu() << endl;
						if (z.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Zombie attack: " << endl;
						z.attack(p2);
						cout << "Your life remaining: " << p2.getlife() << endl;
						if (p2.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
					if (p2.getweapon().getdu() < 1)
					{
						cout << "You attack with fists: " << endl;
						p2.fistattack(z);
						cout << "Zombie's life remaining: " << z.getlife() << endl;
						if (z.getlife() <= 0)
						{
							cout << "Your enemy is dead." << endl;
							break;
						}
						cout << "Zombie attack: " << endl;
						z.attack(p2);
						cout << "Your life remaining: " << p2.getlife() << endl;
						if (p2.getlife() <= 0)
						{
							cout << "You are dead." << endl;
							break;
						}
					}
				}
			}
			/*else {
				cout << "ERROR" << endl;
			}*/
		}
		/*else {
			cout << "ERROR" << endl;
		}*/
	}
	/*else {
		cout << "ERROR" << endl;
	}*/
}
	