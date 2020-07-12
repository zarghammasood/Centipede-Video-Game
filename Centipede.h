/*
 * Centipede.h
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_
#include<iostream>
#include"MoveableObject.h"
#include"MagicSeg.h"
#include"LazySeg.h"
using namespace std;
class Centipede :public MoveableObject {
	MagicSeg mag;
	LazySeg laz[9];
	int chalna;
public:
	Centipede();
	void DrawHead();
	void DrawBody();
	void move ();
	void draw();
	void inital();
	virtual ~Centipede();
	MagicSeg& getMag() ;
	void setMag(const MagicSeg& mag);
//	void SetLaz(int index);
	int getChalna() ;
	void setChalna(int chalna);
	 LazySeg* getLaz();
};

#endif /* CENTIPEDE_H_ */
