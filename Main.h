/*
 * Main.h
 *
 *  Created on: May 1, 2019
 *      Author: zargham
 */

#ifndef MAIN_H_
#define MAIN_H_
#include<iostream>
#include"Mushroom.h"
#include"ScoreBoard.h"
#include"Position.h"
#include"Player.h"
#include"Centipede.h"
#include"MagicSeg.h"
#include"LazySeg.h"
#include"Bomb.h"
#include"Flea.h"
#include"Spider.h"
#include"Scorpions.h"
using namespace std;
class Main {
	Position p;
	Mushroom m[25];
	ScoreBoard s;
	Player pl;
	Bomb b;
	Centipede c;
	Flea f;
	Spider spi;
	Scorpions sco;
	int index[25];
	int a;
public:
	Main();
	void displayMushroom();
	void mush(int *x,int *y);
	void displayscore();
	void displayplayer();
	void pl_vs_spider();
	void Spider_collision_check();
	void displaycentipede();
	void colision_check_for_mushroom();
	void collision_with_flea();
	virtual ~Main();
	Mushroom* getM();
	ScoreBoard& getS();
	void setS(const ScoreBoard& s);
	Position& getP();
	void setP(const Position& p);
	Player& getPl();
	void setPl(const Player& pl);
	Bomb& getB();
	void setB(const Bomb& b);
	Centipede& getC();
	void setC(const Centipede& c);
	Flea& getF() ;
	void setF(const Flea& f);
	int getA() const;
	void setA(int a);
	const int* getIndex() const;
	Spider& getSpi();
	void setSpi(const Spider& spi);
	Scorpions& getSco();
	void setSco(const Scorpions& sco);
};

#endif /* MAIN_H_ */
