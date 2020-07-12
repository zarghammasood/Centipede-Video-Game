/*
 * ScoreBoard.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_
#include<iostream>
#include"GameObject.h"
using namespace std;
class ScoreBoard : public GameObject{
	int lives;
public:
	ScoreBoard();
	ScoreBoard(int li);
	bool isdead();
	virtual ~ScoreBoard();
	int getLives() const;
	void setLives(int lives);
	void draw();
};

#endif /* SCOREBOARD_H_ */
