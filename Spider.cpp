/*
 * Spider.cpp
 *
 *  Created on: May 6, 2019
 *      Author: zargham
 */

#include "Spider.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
Spider::Spider() {
	trna=1;
}
void Spider::move(){
	if(trna ==1){
		getP().changeyp(1);
		getP().changexp(1);
	}
	if(trna==2)
	{
		getP().changexp(1);
		getP().changeyn(1);
	}
	if(getP().getX()>=1010)
		getP().setX(10);
	if(getP().getY()>=300)
		trna=2;
	if(getP().getY()<=65)
		trna=1;

}
void Spider::initialspi(){
getP().setX(0);
getP().setY(60);
}
void Spider::draw(){
	DrawSquare( getP().getX(),getP().getY(),20,colors[RED]);
}

Spider::~Spider() {
	// TODO Auto-generated destructor stub
}

