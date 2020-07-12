/*
 * MagicSeg.cpp
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#include "MagicSeg.h"
#include "Board.h"
#include "util.h"
#include"CImg.h"
#include<iostream>
using namespace std ;
MagicSeg::MagicSeg() {
	rad=7;
}
void MagicSeg::move(){

}

int MagicSeg::geterxmag(){
		return this->getP().getX();
}
void MagicSeg::setterxmag(int x){
		this->getP().setX(x);
}
int MagicSeg::geterymag(){
		return this->getP().getY();
}
void MagicSeg::setterymag(int y){
		this->getP().setY(y);
}

int MagicSeg::getRad() const {
	return rad;
}
void MagicSeg::draw(){
	DrawCircle(this->getP().getX(),this->getP().getY(),rad,colors[RED]);
}
void MagicSeg::setRad(int rad) {
	this->rad = rad;
}

MagicSeg::~MagicSeg() {
rad=0;
}

