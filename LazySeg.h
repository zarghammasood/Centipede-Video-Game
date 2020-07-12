/*
 * LazySeg.h
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#ifndef LAZYSEG_H_
#define LAZYSEG_H_
#include<iostream>
#include"Position.h"
#include"GameObject.h"
#include"MoveableObject.h"
using namespace std ;

class LazySeg :public MoveableObject {
	int radius;
public:
	LazySeg();
	void draw();
	void move();
	int geterxlaz();
	void setterxlaz(int x);
	int geterylaz();
	void setterylaz(int y);
	virtual ~LazySeg();
	int getRadius() const;
	void setRadius(int radius);
};

#endif /* LAZYSEG_H_ */
