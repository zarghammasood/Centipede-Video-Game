/*
 * Mushroom.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: zargham
 */

#include "Mushroom.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
#include"GameObject.h"
Mushroom::Mushroom() {
	shorts=0;
	color=20;
}
void Mushroom :: draw (){
}
bool Mushroom ::distroy(){
	if(shorts>=2)
		return true ;
	else if(shorts<2)
		return false;
}
int Mushroom::getShorts() const {
	return shorts;
}

void Mushroom::setShorts(int shorts) {
	this->shorts = shorts;
}

Mushroom::~Mushroom() {
}

int Mushroom::getColor() const {
	return color;
}

void Mushroom::setColor(int color) {
	this->color = color;
}
