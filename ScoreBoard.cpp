/*
 * ScoreBoard.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#include "ScoreBoard.h"
#include "Board.h"
#include "util.h"
#include"CImg.h"
#include<string>
#include<sstream>
ScoreBoard::ScoreBoard() {
	lives=2;
}
ScoreBoard::ScoreBoard(int li){
	lives=li;
}

bool ScoreBoard::isdead(){
	if(lives==0)
		return true;
	else if (lives>0)
		return false;
}

int ScoreBoard::getLives() const {
	return lives;
}

void ScoreBoard::setLives(int lives) {
	this->lives = lives;
}

ScoreBoard::~ScoreBoard() {
	}

void ScoreBoard::draw (){

string c;
stringstream d;
d<<lives;
c=d.str();
//DrawString(700, 30, "SCORE = ", colors[MISTY_ROSE]);
//DrawString( 800, 30,a, colors[MISTY_ROSE]);
DrawString(20, 30, "LIVES = ", colors[MISTY_ROSE]);
DrawString( 130, 30, c, colors[MISTY_ROSE]);

}

