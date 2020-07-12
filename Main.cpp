/*
 * Main.cpp
 *
 *  Created on: May 1, 2019
 *      Author: zargham
 */

#include "Main.h"
#include "Board.h"
#include "util.h"
#include"CImg.h"
#include<cmath>
#include<string>
#include<sstream>

Main::Main(){
	a=0;

}
void Main::mush(int *x,int *y){
	for(int i=0;i<25;i++){
		m[i].getP().setX(x[i]);
		m[i].getP().setY(y[i]);
}
}
void Main::collision_with_flea(){
	float dis1,dis2,dis3;
	dis1=sqrt(pow((b.getP().getX()+7)-(f.getP().getX()+20),2)+pow((b.getP().getY()+7)-(f.getP().getY()+20),2));
	dis2=sqrt(pow((b.getP().getX()+7)-(f.getP().getX()+20),2)+pow((b.getP().getY()+7)-(f.getP().getY()),2));
	dis3=sqrt(pow((b.getP().getX()+7)-(f.getP().getX()),2)+pow((b.getP().getY()+7)-(f.getP().getY()+20),2));
	if(dis1<=30 || dis2<=30 || dis3<=30)
	{
		f.getP().setX(2000);
		f.getP().setY(2000);
		pl.setCurrentScore(pl.getCurrentScore()+900);
	}
	else if(dis1<=20 || dis2<=20 || dis3<=20)
	{
		f.getP().setX(2000);
		f.getP().setY(2000);
		pl.setCurrentScore(pl.getCurrentScore()+600);
	}

	else if (dis1<=10 || dis2<=10 || dis3<=10)
	{
		f.getP().setX(2000);
		f.getP().setY(2000);
		pl.setCurrentScore(pl.getCurrentScore()+300);
	}
//spi.initialspi();

}
void Main::displayMushroom(){
for(int i=0;i<25;i++){
	DrawSquare(m[i].getP().getX(),m[i].getP().getY(),15,colors[m[i].getColor()]);
	if(m[i].distroy())
	{
		m[i].getP().setX(2000);
		m[i].getP().setY(2000);
	}

}
}

void Main::displayscore(){
		s.draw();
		string a,e;
		long long int g,h;
		stringstream b,c;
		g=pl.getCurrentScore();
		h=pl.getHighScore();
		b<<g;
		c<<h;
		a=b.str();
		e=c.str();
		if(s.isdead()){
			DrawSquare( 0,0,10000,colors[GREEN]);
			DrawString(300,500, "Player Score is : ", colors[MISTY_ROSE]);
			DrawString( 470, 500, a, colors[MISTY_ROSE]);
			DrawString(300,450, "Player Highest Score is : ", colors[MISTY_ROSE]);
			DrawString( 550, 450, e, colors[MISTY_ROSE]);
			DrawString(350,600, "GAME OVER ", colors[MISTY_ROSE]);
		}
}
void Main::pl_vs_spider(){
	float dis ;
	dis=sqrt(pow(pl.getP().getX()-spi.getP().getX(),2)+pow(pl.getP().getY()-spi.getP().getY(),2));
	if(dis<=5)
	{
		spi.initialspi();
		pl.setCurrentScore(pl.getCurrentScore()+900);
	}
}
void Main::displaycentipede(){
//int distance[25];
//for(int i=0;i<25;i++)
//	distance[i]=sqrt(pow(m[i].getP().getX()-c.getMag().geterxmag(),2)+pow(m[i].getP().getY()-c.getMag().geterymag(),2));

	c.DrawHead();
	c.DrawBody();
	if(c.getChalna()==1)
	{
		c.getMag().getP().changexn(05);
	}
	if(c.getChalna()==2)
	{
		c.getMag().getP().changexp(05);
	}

	if(c.getMag().geterxmag()<=180)
	{
		c.setChalna(2);
		c.getMag().getP().changeyn(15);
	}
	if(c.getMag().geterxmag()>=1010)
	{
		c.setChalna(1);
		c.getMag().getP().changeyn(15);
	}

//	for(int i=0,i<25;i++)
//		if(distance[i]<=10)
//			c.

	c.getLaz()[0].setterxlaz(c.getMag().geterxmag());
	c.getLaz()[0].setterylaz(c.getMag().geterymag());

for(int i=8;i>=0;i--)
	{
		c.getLaz()[i].setterxlaz(c.getLaz()[i-1].geterxlaz()-20);
		c.getLaz()[i].setterylaz(c.getLaz()[i-1].geterylaz());
	}


}
void Main::colision_check_for_mushroom(){
int distance1[25];
int distance2[25];

for(int i=0;i<25;i++)
{
	distance1[i]=sqrt(pow(m[i].getP().getX()-b.getP().getX(),2)+pow((m[i].getP().getY()-b.getP().getY()),2));
	distance2[i]=sqrt(pow(m[i].getP().getX()-b.getP().getX(),2)+pow((m[i].getP().getY()-b.getP().getY()),2));
}

for(int i=0;i<25;i++)
{
	if(distance1[i]<=10 || distance2[i]<=10)
	{
		m[i].setShorts(m[i].getShorts()+1);
		if(m[i].distroy()==true)
		{
			index[a++]=i;
			m[i].getP().setX(2000);
			m[i].getP().setY(2000);
			b.initial(pl.getP().getX(),pl.getP().getY());
			pl.setCurrentScore(pl.getCurrentScore()+1);
		}
	}
}
}
void Main::Spider_collision_check(){
	float distance;
	distance=sqrt(pow((pl.getP().getX()+20)-(spi.getP().getX()+20),2)+pow((pl.getP().getY()+20)-(spi.getP().getY()+20),2));

	if(s.getLives()==0){
		if(pl.getCurrentScore()>pl.getHighScore())
			pl.setHighScore(pl.getCurrentScore());
		displayscore();
		pl.getP().setX(2000);
		pl.getP().setY(2000);
	}
	else if(distance<=10){
		s.setLives(s.getLives()-1);
		spi.initialspi();
		pl.setHighScore(pl.getCurrentScore());
		displayscore();
	}
}
void Main::displayplayer(){
	pl.draw();
}

Mushroom* Main::getM() {
	return m;
}

ScoreBoard& Main::getS() {
	return s;
}
Position& Main::getP()  {
	return p;
}

Player& Main::getPl() {
	return pl;
}

Centipede& Main::getC(){
	return c;
}

void Main::setC(const Centipede& c) {
	this->c = c;
}

Bomb& Main::getB() {
	return b;
}

void Main::setB(const Bomb& b) {
	this->b = b;
}

void Main::setPl(const Player& pl) {
	this->pl = pl;
}

void Main::setP(const Position& p) {
	this->p = p;
}

void Main::setS(const ScoreBoard& s) {
	this->s = s;
}


Flea& Main::getF() {
	return f;
}

int Main::getA() const {
	return a;
}

Spider& Main::getSpi() {
	return spi;
}

Scorpions& Main::getSco()  {
	return sco;
}

void Main::setSco(const Scorpions& sco) {
	this->sco = sco;
}

void Main::setSpi(const Spider& spi) {
	this->spi = spi;
}

const int* Main::getIndex() const {
	return index;
}

void Main::setA(int a) {
	this->a = a;
}

void Main::setF(const Flea& f) {
	this->f = f;
}

Main::~Main() {

}
