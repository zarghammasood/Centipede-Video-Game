/*
 * Mushroom.h
 *
 *  Created on: Apr 30, 2019
 *      Author: zargham
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include<iostream>
#include"GameObject.h"
#include<string>
using namespace std ;
class Mushroom : public GameObject{
	int shorts;
	int color;
public:
	Mushroom();
	void draw ();
	bool distroy();
	virtual ~Mushroom();
	int getShorts() const;
	void setShorts(int shots);
	const string& getA() const;
	void setA(const string& a);
	int getColor() const;
	void setColor(int color);
};

#endif /* MUSHROOM_H_ */
