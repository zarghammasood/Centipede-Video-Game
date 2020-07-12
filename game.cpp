//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "util.h"
#include"Main.h"
#include"GameObject.h"
#include"ScoreBoard.h"
#include"Mushroom.h"
#include"Player.h"
#include"Centipede.h"
#include"MagicSeg.h"
#include"LazySeg.h"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
Board *b;
Main m;
void player_centipede_check(){
	for(int i=0;i<9;i++)
	{
		if(m.getC().getLaz()[i].geterxlaz()==m.getPl().getP().getX() && m.getC().getLaz()[i].geterylaz()==m.getPl().getP().getY())
		{
		m.displayscore();
		}
		else if((m.getC().getLaz()[i].geterxlaz()+20 && m.getC().getLaz()[i].geterylaz()+20)==(m.getPl().getP().getY()+10))
		{
		m.displayscore();
			}
		else if(m.getC().getLaz()[i].geterxlaz()+20==m.getPl().getP().getX() && m.getC().getLaz()[i].geterylaz()==m.getPl().getP().getY())
			{
			m.displayscore();
				}
		else if(m.getC().getLaz()[i].geterxlaz()==m.getPl().getP().getX() && m.getC().getLaz()[i].geterylaz()+20==m.getPl().getP().getY())
			{
			m.displayscore();
			}
	}

}
void game(){
	//Drawing Player
		m.getPl().draw();
	//Displaying Score
		m.displayscore();
	//Drawing mushroom
		m.displayMushroom();
	//Drawing Centipede
		m.displaycentipede();
	//Function to Check collision of Player and Centipede
		player_centipede_check();
	//	Fire Gun
		m.getB().move();
		m.getB().draw();
	//Collision Check of Mushroom and fire
		m.colision_check_for_mushroom();
	//Collision Check for Spider and player
		m.Spider_collision_check();
	//Generation of Flea
	if(m.getA()==10){
			m.getF().initial();
			srand(time(NULL));
			for(int i=0;i<10;i++){
				m.getM()[m.getIndex()[i]].getP().setX(rand()%1020);
				m.getM()[m.getIndex()[i]].getP().setY(rand()%500+230);
//				m.getM()[m.getIndex()[i]].getP().setX(400);
//				m.getM()[m.getIndex()[i]].getP().setY(400);
				m.getSco().getP().setX(0);
			}

			m.setA(0);

		}

	m.getF().draw();
	m.getF().move();
	//Spider
	m.getSpi().draw();
	m.getSpi().move();
	//Scorpions
	m.getSco().draw();
	m.getSco().move();
	int asd ;
	asd=sqrt(pow(m.getSco().getP().getX()-m.getB().getP().getX(),2)+pow(m.getSco().getP().getY()-m.getB().getP().getY(),2));
if(asd<=10){
	m.getPl().setCurrentScore(m.getPl().getCurrentScore()+1000);
	m.getSco().getP().setX(2000);
}



	//Collision with Flea
		m.collision_with_flea();

	//Giving Extra lives
		if(m.getPl().getCurrentScore()==10000)
			m.getS().setLives(m.getS().getLives()+1);
		if(m.getPl().getCurrentScore()==12000)
				m.getS().setLives(m.getS().getLives()+2);
		if(m.getPl().getCurrentScore()==15000)
				m.getS().setLives(m.getS().getLives()+3);
		if(m.getPl().getCurrentScore()==20000)
				m.getS().setLives(m.getS().getLives()+4);

// Drawing Boader
	DrawLine( 0 , 55 ,  1020 , 55, 10 , colors[MISTY_ROSE] );
	DrawLine( 0 , 0 , 0 ,840, 10 , colors[MISTY_ROSE] );
	DrawLine( 1020 , 0 ,  1020 , 840, 10 , colors[MISTY_ROSE] );
	DrawLine( 0, 840 ,  1020 ,840, 10 , colors[MISTY_ROSE] );

}

void GameDisplay(){
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.2/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
//	for (int counter1=0;counter1<130;counter1++)
//   		for (int counter2=0;counter2<86;counter2++)
//	    	{
//				DrawSquare(counter1*10,counter2*11,10,colors[AQUA]);
//		}
game();

	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		m.getPl().leftmovement();
	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		m.getPl().rightmovement();
	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		m.getPl().upmovement();
	}else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		m.getPl().downmovement();
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{

			m.getB().getP().setX(m.getPl().getP().getX()+10);
			m.getB().getP().setY(m.getPl().getP().getY());

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
//
//int game [130][86];
//for (int counter1=0;counter1<130;counter1++)
//	for (int counter2=0;counter2<86;counter2++)
//	{
//		game[counter1][counter2]=0;
//	}
	int x[25],y[25];
	srand(time(NULL));
	for(int i=0;i<25;i++)
	{
		x[i]=rand()%1020;
		y[i]=rand()%500+310;
	}
		m.mush(x,y);
		m.getPl().initial();
		m.getC().inital();
		m.getSpi().initialspi();
	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
