/*
 * GameObject.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include"Position.h"
class GameObject {
	Position p;
public:
	GameObject();
	GameObject(int X,int Y);
	GameObject(Position P);
	virtual ~GameObject();
	virtual void draw()=0;
	Position& getP();
	void setP(const Position& p);
};

#endif /* GAMEOBJECT_H_ */
