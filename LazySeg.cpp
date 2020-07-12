/*
 * LazySeg.cpp
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#include "LazySeg.h"
#include "Board.h"
#include "util.h"
#include"CImg.h"
#include<iostream>
using namespace std ;

LazySeg::LazySeg() {
	radius =7;
	getP().setX(510);
	getP().setY(830);
}
void LazySeg::move(){

}
int LazySeg::geterxlaz(){
		return this->getP().getX();
}
void LazySeg::setterxlaz(int x){
		this->getP().setX(x);
}
int LazySeg::geterylaz(){
		return this->getP().getY();
}
void LazySeg::setterylaz(int y){
		this->getP().setY(y);
}

int LazySeg::getRadius() const {
	return radius;
}
void LazySeg::draw(){
	DrawCircle(this->getP().getX(),this->getP().getY(),radius,colors[RED]);
}
void LazySeg::setRadius(int radius) {
	this->radius = radius;
}

LazySeg::~LazySeg() {
radius =0;
}

