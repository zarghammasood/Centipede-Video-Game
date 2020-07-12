/*
 * Flea.cpp
 *
 *  Created on: May 5, 2019
 *      Author: zargham
 */

#include "Flea.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
#include"Position.h"

Flea::Flea() {
	// TODO Auto-generated constructor stub

}
void Flea::draw(){
	DrawSquare( this->getP().getX(),this->getP().getY(),15,colors[GREEN]);
}
void Flea::move(){
		this->getP().changeyn(02);
//		if(this->getP().getY()<10)
//			this->getP().setY(2000);
}
void Flea::initial(){
	this->getP().setX(510);
	this->getP().setY(840);
}
Flea::~Flea() {
	// TODO Auto-generated destructor stub
}

