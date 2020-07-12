/*
 * Position.h
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
protected:
	int x;
	int y;
public:
	Position();
	Position(int ,int);
	virtual ~Position();
	void changexp(int X);
	void changexn(int X);
	void changeyp(int Y);
	void changeyn(int Y);
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

#endif /* POSITION_H_ */
