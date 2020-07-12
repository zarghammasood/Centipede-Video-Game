/*
 * GameObject.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: zargham
 */

#include "GameObject.h"

GameObject::GameObject() {
p.setX(0);
p.setY(0);
}

 Position& GameObject::getP() {
	return p;
}

void GameObject::setP(const Position& p) {
	this->p = p;
}

GameObject::~GameObject() {
	p.setX(0);
	p.setY(0);
}
GameObject::GameObject(int X,int Y){
	p.setX(X);
	p.setY(Y);
}
GameObject::GameObject(Position P){
this->p=P;
}
