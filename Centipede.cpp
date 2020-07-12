/*
 * Centipede.cpp
 *
 *  Created on: May 3, 2019
 *      Author: zargham
 */

#include "Centipede.h"
#include"MagicSeg.h"
#include"LazySeg.h"
#include "Board.h"
#include "util.h"
#include"CImg.h"
#include<iostream>
using namespace std ;

Centipede::Centipede() {
	chalna =1;
}
void Centipede::move (){

}
void Centipede::draw(){

}

void Centipede::inital(){
	mag.setterxmag(510);
	mag.setterymag(830);
	for(int i=0;i<9;i++)
	{
		laz[i].setterxlaz(mag.geterxmag()-50);
		laz[i].setterylaz(mag.geterymag());
	}
}
void Centipede::DrawHead(){
	DrawCircle(mag.geterxmag(),mag.geterymag(),mag.getRad(),colors[RED]);
}
void Centipede::DrawBody(){
	for(int i=0;i<9;i++)
	DrawCircle(laz[i].geterxlaz(),laz[i].geterylaz(),laz[i].getRadius(),colors[RED]);
}
MagicSeg& Centipede::getMag() {
	return mag;
}

int Centipede::getChalna()  {
	return chalna;
}

void Centipede::setChalna(int chalna) {
	this->chalna = chalna;
}

LazySeg* Centipede::getLaz() {
	return laz;
}

void Centipede::setMag(const MagicSeg& mag) {
	this->mag = mag;
}

Centipede::~Centipede() {
	// TODO Auto-generated destructor stub
}

