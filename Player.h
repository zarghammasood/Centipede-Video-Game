/*
 * Player.h
 *
 *  Created on: May 1, 2019
 *      Author: zargham
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<iostream>
#include<string>
#include"MoveableObject.h"
using namespace std ;
class Player :public MoveableObject{
	long long int HighScore;
	long long int CurrentScore;
public:
	Player();
	virtual ~Player();
	void draw ();
	void move();
	void initial();
	void rightmovement();
	void leftmovement();
	void upmovement();
	void downmovement();
	long long int getCurrentScore() const;
	void setCurrentScore(long long int currentScore);
	long long int getHighScore() const;
	void setHighScore(long long int highScore);
};

#endif /* PLAYER_H_ */
