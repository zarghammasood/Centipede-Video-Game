/*
 * Player.cpp
 *
 *  Created on: May 1, 2019
 *      Author: zargham
 */

#include "Player.h"
#include"Board.h"
#include "util.h"
#include"CImg.h"
#include"Position.h"
#include<string>
#include<sstream>
Player::Player() {
	HighScore=0;
	CurrentScore=0;
}
void Player::move(){

}
void Player::draw (){
	string a;
	stringstream b;
b<<CurrentScore;
a=b.str();
DrawString(700, 30, "SCORE = ", colors[MISTY_ROSE]);
DrawString( 800, 30,a, colors[MISTY_ROSE]);
DrawSquare( this->getP().getX(),this->getP().getY(),20,colors[GREEN]);

}
void Player::initial(){
	getP().setX(60);
	getP().setY(60);
}
void Player::rightmovement(){
	getP().changexp(20);
//	if(getP().getX()<=10)
//		getP().setX(20);
}
void Player::leftmovement(){
	getP().changexn(20);
//	if(getP().getX()>=1010)
//			getP().setX(1000);
}
void Player::upmovement(){
	getP().changeyp(20);
	if(getP().getY()>=300)
			getP().setY(295);
}
void Player::downmovement(){
	getP().changeyn(20);
	if (getP().getY()<=55)
		this->getP().setY(60);

}
long long int Player::getCurrentScore() const {
	return CurrentScore;
}

void Player::setCurrentScore(long long int currentScore) {
	CurrentScore = currentScore;
}

long long int Player::getHighScore() const {
	return HighScore;
}

void Player::setHighScore(long long int highScore) {
	HighScore = highScore;
}
Player::~Player() {
	HighScore=0;
	CurrentScore=0;
}

