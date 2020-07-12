/*
 * Spider.h
 *
 *  Created on: May 6, 2019
 *      Author: zargham
 */

#ifndef SPIDER_H_
#define SPIDER_H_
#include<iostream>
#include"MoveableObject.h"
class Spider : public MoveableObject{
	int trna;
public:
	Spider();
	void draw();
	void move();
	void initialspi();
	virtual ~Spider();
};

#endif /* SPIDER_H_ */
