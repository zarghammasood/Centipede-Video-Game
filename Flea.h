/*
 * Flea.h
 *
 *  Created on: May 5, 2019
 *      Author: zargham
 */

#ifndef FLEA_H_
#define FLEA_H_
#include<iostream>
#include"MoveableObject.h"
using namespace std;
class Flea :public MoveableObject{
public:
	Flea();
	void draw();
	void move();
	void initial();
	virtual ~Flea();
};

#endif /* FLEA_H_ */
