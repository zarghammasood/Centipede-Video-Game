/*
 * Bomb.h
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#ifndef BOMB_H_
#define BOMB_H_
#include<iostream>
#include"MoveableObject.h"
class Bomb :public MoveableObject{
public:
	Bomb();
	void draw();
	void initial (int x, int y);
	void move();
	virtual ~Bomb();
};

#endif /* BOMB_H_ */
