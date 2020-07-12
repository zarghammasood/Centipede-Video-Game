/*
 * Scorpions.h
 *
 *  Created on: May 6, 2019
 *      Author: zargham
 */

#ifndef SCORPIONS_H_
#define SCORPIONS_H_
#include<iostream>
#include"MoveableObject.h"
using namespace std ;
class Scorpions :public MoveableObject{
public:
	Scorpions();
	void move ();
	void draw();
	virtual ~Scorpions();
};

#endif /* SCORPIONS_H_ */
