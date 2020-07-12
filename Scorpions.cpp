/*
 * Scorpions.cpp
 *
 *  Created on: May 6, 2019
 *      Author: zargham
 */

#include "Scorpions.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
#include"GameObject.h"
Scorpions::Scorpions() {
getP().setY(550);
}
void Scorpions::move (){
	DrawCircle( this->getP().getX(),this->getP().getY(),07,colors[RED]);
}
void Scorpions::draw(){
	this->getP().setX(this->getP().getX()+1);
//	this->getP().setY(this->getP().getY()+1);
	if(this->getP().getX()>=1010)
		this->getP().setX(10);
}
Scorpions::~Scorpions() {

}

