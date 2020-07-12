/*
 * MagicSeg.h
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#ifndef MAGICSEG_H_
#define MAGICSEG_H_
#include<iostream>
#include"Position.h"
#include"GameObject.h"
#include"MoveableObject.h"
using namespace std ;
class MagicSeg :public MoveableObject{
	int rad ;
public:

	MagicSeg();
	void draw();
	void move();
	int geterxmag();
	void setterxmag(int x);
	int geterymag();
	void setterymag(int y);
	virtual ~MagicSeg();
	int getRad() const;
	void setRad(int rad);
};

#endif /* MAGICSEG_H_ */
