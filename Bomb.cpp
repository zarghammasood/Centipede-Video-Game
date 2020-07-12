/*
 * Bomb.cpp
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#include "Bomb.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
#include"Position.h"

Bomb::Bomb() {

}
void Bomb::initial (int x,int y){
	this->getP().setX(x);
	this->getP().setY(y);
}
void Bomb::draw(){

	DrawCircle(this->getP().getX(),this->getP().getY(),7,colors[RED]);
}
void Bomb::move(){
	if(this->getP().getY()<860){
				this->getP().changeyp(10);
			}

}
Bomb::~Bomb() {
	// TODO Auto-generated destructor stub
}

