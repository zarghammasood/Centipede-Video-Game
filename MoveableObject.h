/*
 * MoveableObject.h
 *
 *  Created on: Apr 30, 2019
 *      Author: zargham
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_
#include<iostream>
#include"GameObject.h"
using namespace std ;
class MoveableObject :public GameObject{
public:
	MoveableObject();
	virtual void move()=0;
	virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */
