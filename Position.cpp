/*
 * Position.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#include "Position.h"

Position::Position() {
	x=0;
	y=0;
}
Position::Position(int X,int Y){
	x=X;
	y=Y;
}
void Position::changexp(int X){
	x=x+X;
}
void Position::changexn(int X){
	x=x-X;
}
void Position::changeyp(int Y){
	y=y+Y;
}
void Position::changeyn(int Y){
	y=y-Y;
}

int Position::getX() const {
	return x;
}

void Position::setX(int x) {
	this->x = x;
}

int Position::getY() const {
	return y;
}

void Position::setY(int y) {
	this->y = y;
}

Position::~Position() {
	x=0;
	y=0;
}

