//============================================================================
// Name        : Hammad Javaid -- i21_1661 -- DS_M -- FINAL PROJECT -- .cpp
// Author      : FAST CS Department
// Version     : LATEST..
// Copyright   : java(c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
int menu = 0;
int passenger_line_y=750,passenger_line_yy=780;
int person_circle_x=675,person_circle_y=785;
int passenger_line_y_2=455,passenger_line_yy_2=485;
int person_circle_x_2=475,person_circle_y_2=490;
int passenger_line_y_3=300,passenger_line_yy_3=330;
int person_circle_x_3=825,person_circle_y_3=335;

bool temp_1 = false;
bool temp_2 = false;
bool temp_3 = false;
bool temp_4 = true;
bool temp_5 = true;
bool temp_6 = true;
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
int score = 0;
int xI = 5, yI = 790;
int xx = 10, yy = 830;
int xxx = 35, yyy = 785;
int destination_drop_x;
int destination_drop_y;
int destination_drop_x_1;
int destination_drop_y_1;
int destination_drop_x_2;
int destination_drop_y_2;

bool passenger_1 = true;
bool passenger_2 = true;
bool passenger_3 = true;
void drawCar() {
	DrawSquare(xI, yI, 35, colors[WHITE]);
	DrawCircle(xx,yy,5,colors[RED]);
	DrawCircle(xxx,yy,5,colors[RED]);
	DrawCircle(xx,yyy,5,colors[RED]);
	DrawCircle(xxx,yyy,5,colors[RED]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	glutPostRedisplay();
}
int red_car_x = 970, red_car_y = 50;
int red_circle_x = 975, red_circle_y = 45;
int red_circle_xx = 1000, red_circle_yy = 90;

void red_car()
{
	DrawSquare(red_car_x, red_car_y, 35, colors[BROWN]);
	DrawCircle(red_circle_x,red_circle_y,5,colors[RED]);
	DrawCircle(red_circle_x,red_circle_yy,5,colors[RED]);
	DrawCircle(red_circle_xx,red_circle_y,5,colors[RED]);
	DrawCircle(red_circle_xx,red_circle_yy,5,colors[RED]);
}


int yellow_car_x=610,yellow_car_y=460;
int yellow_circle_x=615,yellow_circle_y=500;
int yellow_circle_xx=640,yellow_circle_yy=455;

void yellow_car()
{
        DrawSquare(yellow_car_x, yellow_car_y, 35, colors[YELLOW]);
	DrawCircle(yellow_circle_x,yellow_circle_y,5,colors[RED]);
	DrawCircle(yellow_circle_xx,yellow_circle_y,5,colors[RED]);
	DrawCircle(yellow_circle_x,yellow_circle_yy,5,colors[RED]);
	DrawCircle(yellow_circle_xx,yellow_circle_yy,5,colors[RED]);
}

int green_car_x=660,green_car_y=260;
int green_circle_x=665,green_circle_y=300;
int green_circle_xx=690,green_circle_yy=255;

void green_car()
{
        DrawSquare(green_car_x, green_car_y, 35, colors[GREEN]);
	DrawCircle(green_circle_x, green_circle_y, 5, colors[RED]);
	DrawCircle(green_circle_xx, green_circle_y, 5, colors[RED]);
	DrawCircle(green_circle_x, green_circle_yy, 5, colors[RED]);
	DrawCircle(green_circle_xx, green_circle_yy , 5 , colors[RED]);
}
//bool flag = true;
/*void moveCar() 
{
	
	if (xI > 10 && flag) {
		xI -= 10;
		xx-=10;
		xxx-=10;
		//cout << "going left"<<xI<<endl;
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		//cout << "go right";
		xI += 10;
		xx-=10;
		xxx-=10;
		if (xI > 900)
			flag = true;
	}
}*/
void red_car_moving()
{
	if( ( red_car_x> 10 && red_car_x<= 980 ) && red_car_y <= 50 )
	{
		red_car_x-=10;
		red_circle_x-=10;
		red_circle_xx-=10;
	}
	else if(( red_car_y>=50 && red_car_y<790) && red_car_x==10)
	{
		red_car_y+=10;
		red_circle_y+=10;
		red_circle_yy+=10;
	}
	else if((red_car_x>=10 && red_car_x<=970) && red_car_y==790) 
	{
		red_car_x+=10;
		red_circle_x+=10;
		red_circle_xx+=10;
	}
	else if(( red_car_y>50 && red_car_y<=790) && red_car_x==980)
	{
		red_car_y-=10;
		red_circle_y-=10;
		red_circle_yy-=10;
	}
}
void yellow_car_moving()
{
	if( (yellow_car_y> 320 && yellow_car_y<= 640 ) && yellow_car_x == 610 )
	{
		yellow_car_y-=10;
		yellow_circle_y-=10;
		yellow_circle_yy-=10;
	}
	else if( ( yellow_car_x> 560 && yellow_car_x<= 610 ) && yellow_car_y == 320)
	{
		yellow_car_x-=10;
		yellow_circle_x-=10;
		yellow_circle_xx-=10;
	}
	else if( ( yellow_car_y> 310 && yellow_car_y< 640 ) && yellow_car_x == 560)
	{
		yellow_car_y+=10;
		yellow_circle_y+=10;
		yellow_circle_yy+=10;
	}
	else if((yellow_car_x>=560 && yellow_car_x<610) && yellow_car_y==640)
	{
		yellow_car_x+=10;
		yellow_circle_x+=10;
		yellow_circle_xx+=10;
	}
}
void green_car_moving()
{
	if( ( green_car_y>= 20 && green_car_y< 350 ) && green_car_x == 660)
	{
		green_car_y+=10;
		green_circle_y+=10;
		green_circle_yy+=10;
	}
	else if( ( green_car_x>= 660 && green_car_x< 710 ) && green_car_y == 350)
	{
		green_car_x+=10;
		green_circle_x+=10;
		green_circle_xx+=10;
	}
	else if( ( green_car_y> 20 && green_car_y<= 350 ) && green_car_x == 710)
	{
		green_car_y-=10;
		green_circle_y-=10;
		green_circle_yy-=10;
	}
	else if( ( green_car_x> 660 && green_car_x<= 710) && green_car_y == 20)
	{
		green_car_x-=10;
		green_circle_x-=10;
		green_circle_xx-=10;
	}
}
void passenger_drawing(int passenger_liney, int passenger_lineyy, int circlex, int circley)
{
	DrawCircle(circlex,circley,5,colors[WHITE]);
	DrawLine( circlex , passenger_liney ,  circlex , passenger_lineyy , 5 , colors[WHITE] );
}

void Destination_drop()
{
	DrawSquare(destination_drop_x, destination_drop_y, 35, colors[GREEN]);
}

void Destination_drop_1()
{
	DrawSquare(destination_drop_x_1, destination_drop_y_1, 35, colors[GREEN]);
}

void Destination_drop_2()
{
	DrawSquare(destination_drop_x_2, destination_drop_y_2, 35, colors[GREEN]);
}	
/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//x,y,width
	if( menu == 0 )
	{
	  DrawString( 300, 500, "Press S for Start ", colors[MISTY_ROSE]);
	  DrawString( 300, 400, "Press C for Score ", colors[MISTY_ROSE]);
	}
	if( menu == 2 )
	{
	  DrawString( 300, 500, "score= "+std::to_string(score), colors[MISTY_ROSE]);
	}
	if( menu == 1 )
	{DrawSquare(100, 700, 50, colors[ORANGE]);
	DrawSquare(150, 700, 50, colors[ORANGE]);
	DrawSquare(200, 700, 50, colors[ORANGE]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(450, 700, 50, colors[ORANGE]);
	DrawSquare(500, 700, 50, colors[ORANGE]);
	DrawSquare(550, 700, 50, colors[ORANGE]);
	DrawSquare(600, 700, 50, colors[ORANGE]);
	DrawSquare(650, 700, 50, colors[ORANGE]);
	DrawSquare(700, 700, 50, colors[ORANGE]);
	DrawSquare(750, 700, 50, colors[ORANGE]);
	DrawSquare(800, 700, 50, colors[ORANGE]);
	DrawSquare(850, 700, 50, colors[ORANGE]);
	DrawSquare(900, 700, 50, colors[ORANGE]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(350, 650, 50, colors[ORANGE]);
	DrawSquare(350, 600, 50, colors[ORANGE]);
	DrawSquare(350, 550, 50, colors[ORANGE]);
	DrawSquare(350, 500, 50, colors[ORANGE]);
	DrawSquare(300, 500, 50, colors[ORANGE]);
	DrawSquare(250, 500, 50, colors[ORANGE]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(150, 500, 50, colors[ORANGE]);
	DrawSquare(150, 450, 50, colors[ORANGE]);
	DrawSquare(150, 400, 50, colors[ORANGE]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(150, 250, 50, colors[ORANGE]);
	DrawSquare(150, 200, 50, colors[ORANGE]);
	DrawSquare(150, 150, 50, colors[ORANGE]);
	DrawSquare(100, 250, 50, colors[ORANGE]);
	DrawSquare(100, 200, 50, colors[ORANGE]);
	DrawSquare(100, 150, 50, colors[ORANGE]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DrawSquare(150, 250, 50, colors[ORANGE]);
	DrawSquare(150, 200, 50, colors[ORANGE]);
	DrawSquare(150, 150, 50, colors[ORANGE]);
	DrawSquare(100, 250, 50, colors[ORANGE]);
	DrawSquare(100, 200, 50, colors[ORANGE]);
	DrawSquare(100, 150, 50, colors[ORANGE]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DrawSquare(250, 300, 50, colors[ORANGE]);
	DrawSquare(250, 250, 50, colors[ORANGE]);
	DrawSquare(250, 200, 50, colors[ORANGE]);
	DrawSquare(250, 150, 50, colors[ORANGE]);
	DrawSquare(250, 100, 50, colors[ORANGE]);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(350, 200, 50, colors[ORANGE]);
	DrawSquare(400, 200, 50, colors[ORANGE]);
	DrawSquare(450, 200, 50, colors[ORANGE]);
	DrawSquare(500, 200, 50, colors[ORANGE]);
	DrawSquare(550, 200, 50, colors[ORANGE]);
	DrawSquare(600, 200, 50, colors[ORANGE]);
	DrawSquare(600, 250, 50, colors[ORANGE]);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(400, 350, 50, colors[ORANGE]);
	DrawSquare(450, 350, 50, colors[ORANGE]);
	DrawSquare(500, 350, 50, colors[ORANGE]);
	DrawSquare(500, 400, 50, colors[ORANGE]);
	DrawSquare(500, 510, 50, colors[ORANGE]);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(650, 550, 50, colors[ORANGE]);
	DrawSquare(650, 600, 50, colors[ORANGE]);
	DrawSquare(650, 500, 50, colors[ORANGE]);
	DrawSquare(650, 450, 50, colors[ORANGE]);
	DrawSquare(650, 400, 50, colors[ORANGE]);
	DrawSquare(700, 500, 50, colors[ORANGE]);
	DrawSquare(750, 500, 50, colors[ORANGE]);
	DrawSquare(800, 500, 50, colors[ORANGE]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(900, 600, 50, colors[ORANGE]);
	DrawSquare(900, 550, 50, colors[ORANGE]);
	DrawSquare(900, 500, 50, colors[ORANGE]);
	DrawSquare(900, 450, 50, colors[ORANGE]);
	DrawSquare(900, 400, 50, colors[ORANGE]);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawSquare(750, 150, 50, colors[ORANGE]);
	DrawSquare(750, 200, 50, colors[ORANGE]);
	DrawSquare(750, 250, 50, colors[ORANGE]);
	DrawSquare(800, 250, 50, colors[ORANGE]);
	DrawSquare(850, 250, 50, colors[ORANGE]);
	DrawSquare(900, 250, 50, colors[ORANGE]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawString( 100, 800, "Score="+std::to_string(score), colors[MISTY_ROSE]);
	DrawLine( 50 , 0 ,  50 , 850 , 5 , colors[MISTY_ROSE] );	
	DrawLine( 100 , 0 ,  100 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 150 , 0 ,  150 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 200 , 0 ,  200 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 250 , 0 ,  250 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 300 , 0 ,  300 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 350 , 0 ,  350 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 400 , 0 ,  400 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 450 , 0 ,  450 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 500 , 0 ,  500 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 550 , 0 ,  550 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 600 , 0 ,  600 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 650 , 0 ,  650 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 700 , 0 ,  700 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 750 , 0 ,  750 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 800 , 0 ,  800 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 850 , 0 ,  850 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 900 , 0 ,  900 , 850 , 5 , colors[MISTY_ROSE] );
	DrawLine( 950 , 0 ,  950 , 850 , 5 , colors[MISTY_ROSE] );
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DrawRoundRect(160,650,25,40,colors[DARK_SEA_GREEN],10);
	DrawRoundRect(210,210,25,40,colors[DARK_SEA_GREEN],10);
	DrawRoundRect(860,150,25,40,colors[DARK_SEA_GREEN],10);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DrawCircle(325,590,10,colors[GREEN]);
	DrawLine( 325 , 550 ,  325 , 580 , 5 , colors[DARK_SEA_GREEN] );	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawCircle(825,490,10,colors[GREEN]);
	DrawLine( 825 , 450 ,  825 , 480 , 5 , colors[DARK_SEA_GREEN] );
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DrawCircle(10,550,5,colors[RED]);
	DrawCircle(10,700,5,colors[RED]);
	DrawCircle(300,550,5,colors[RED]);
	DrawCircle(300,700,5,colors[RED]);
	
	drawCar();
	red_car();
	yellow_car();
	green_car();
	
	if( temp_4 == true)
	{
		passenger_drawing(passenger_line_y, passenger_line_yy,person_circle_x, person_circle_y );	
	}
	
	if( temp_5 == true )
	{
		passenger_drawing(passenger_line_y_2, passenger_line_yy_2, person_circle_x_2, person_circle_y_2 );	
	}
	
	if( temp_6 == true )
	{
		passenger_drawing(passenger_line_y_3, passenger_line_yy_3, person_circle_x_3, person_circle_y_3 );	
	}
	
	if( temp_1 == true )
	{
	  Destination_drop();
	}
	if( temp_5 == true )
	{
	  Destination_drop_1();
	}
	if(temp_3 == true )
	{
	 Destination_drop_2();
	}
	}
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
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if(xI< 18 && xx< 15)
		{
		 xI=5;
		 xx=10;
		 xxx=35;
		 }
		else
		{
		 xI -= 10;
		 xx-=10;
		 xxx-=10;
		}
		if(yI>=700 && yI<=750 && xI>=90 && xI<=250)
		score-=10;
		if(xI>=150 && xI<=185 && yI>=650 && yI<=695)
		score-=10;
		 if(xI>=150 && xI<=200 && yI>=400 && yI<=550)
		score-=10;
		 if(xI>=100 && xI<=200 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=205 && xI<=240 && yI>=210 && yI<=250)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=100 && yI<=355)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=500 && yI<=555)
		score-=10;
		if(xI>=350 && xI<=400 && yI>=500 && yI<=700)
		score-=10;
		if(xI>=450 && xI<=950 && yI>=700 && yI<=750)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=510 && yI<=555)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=350 && yI<=450)
		score-=10;
		if(xI>=400 && xI<=500 && yI>=350 && yI<=400)
		score-=10;
		if(xI>=350 && xI<=600 && yI>=200 && yI<=250)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=200 && yI<=300)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=700 && xI<=850 && yI>=500 && yI<=550)
		score-=10;
		if(xI>=900 && xI<=950 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=750 && xI<=950 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=750 && xI<=800 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=300 && xI<=350 && yI>=550 && yI<=600)
		score-=10;
		if(xI>=800 && xI<=850 && yI>=450 && yI<=500)
		score-=10;
		if(xI>=850 && xI<=900 && yI>=150 && yI<=200)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=450 && yI<=500)
		score-=10;
		cout << "x-axis= " << xI << endl;
		cout << "y-axis= " << yI << endl;
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(xI>960 && xx>950 && xx>940)
		{xI=970;
		xx=975;
		xxx=1000;}
		else
		{xI += 10;
		xx+=10;
		xxx+=10;}
		
		if(yI>=700 && yI<=750 && xI>=70 && xI<=250)
		score-=10;
		if(xI>=150 && xI<=185 && yI>=650 && yI<=695)
		score-=10;
		if(xI>=150 && xI<=200 && yI>=400 && yI<=550)
		score-=10;
		if(xI>=100 && xI<=200 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=205 && xI<=240 && yI>=210 && yI<=250)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=100 && yI<=355)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=500 && yI<=555)
		score-=10;
		if(xI>=350 && xI<=400 && yI>=500 && yI<=700)
		score-=10;
		if(xI>=450 && xI<=950 && yI>=700 && yI<=750)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=510 && yI<=555)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=350 && yI<=450)
		score-=10;
		if(xI>=400 && xI<=500 && yI>=350 && yI<=400)
		score-=10;
		if(xI>=350 && xI<=600 && yI>=200 && yI<=250)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=200 && yI<=300)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=700 && xI<=850 && yI>=500 && yI<=550)
		score-=10;
		if(xI>=900 && xI<=950 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=750 && xI<=950 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=750 && xI<=800 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=300 && xI<=350 && yI>=550 && yI<=600)
		score-=10;
		if(xI>=800 && xI<=850 && yI>=450 && yI<=500)
		score-=10;
		if(xI>=850 && xI<=900 && yI>=150 && yI<=200)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=450 && yI<=500)
		score-=10;
		cout << "x-axis= " << xI << endl;
		cout << "y-axis= " << yI << endl;
				
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		if(yI>770 && yy>800 && yyy>765 )
		{yI=790;
		 yy=830;
		 yyy=785;}
		else{
		yI += 10;
		yy+=10;
		yyy+=10;}
		if(yI>=700 && yI<=750 && xI>=70 && xI<=250)
		score-=10;
		if(xI>=150 && xI<=185 && yI>=650 && yI<=695)
		score-=10;
		if(xI>=150 && xI<=200 && yI>=400 && yI<=550)
		score-=10;
		if(xI>=100 && xI<=200 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=205 && xI<=240 && yI>=210 && yI<=250)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=100 && yI<=355)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=500 && yI<=555)
		score-=10;
		if(xI>=350 && xI<=400 && yI>=500 && yI<=700)
		score-=10;
		if(xI>=450 && xI<=950 && yI>=700 && yI<=750)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=510 && yI<=555)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=350 && yI<=450)
		score-=10;
		if(xI>=400 && xI<=500 && yI>=350 && yI<=400)
		score-=10;
		if(xI>=350 && xI<=600 && yI>=200 && yI<=250)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=200 && yI<=300)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=700 && xI<=850 && yI>=500 && yI<=550)
		score-=10;
		if(xI>=900 && xI<=950 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=750 && xI<=950 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=750 && xI<=800 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=300 && xI<=350 && yI>=550 && yI<=600)
		score-=10;
		if(xI>=800 && xI<=850 && yI>=450 && yI<=500)
		score-=10;
		if(xI>=850 && xI<=900 && yI>=150 && yI<=200)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=450 && yI<=500)
		score-=10;
		cout << "x-axis= " << xI << endl;
		cout << "y-axis= " << yI << endl;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(yI<30  )
		{yI=20;}
		else{
		yI -= 10;
		yy-=10;
		yyy-=10;}
		if(yI>=700 && yI<=750 && xI>=70 && xI<=250)
		score-=10;
		if(xI>=150 && xI<=185 && yI>=650 && yI<=695)
		score-=10;
		if(xI>=150 && xI<=200 && yI>=400 && yI<=550)
		score-=10;
		if(xI>=100 && xI<=200 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=205 && xI<=240 && yI>=210 && yI<=250)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=100 && yI<=355)
		score-=10;
		if(xI>=250 && xI<=300 && yI>=500 && yI<=555)
		score-=10;
		if(xI>=350 && xI<=400 && yI>=500 && yI<=700)
		score-=10;
		if(xI>=450 && xI<=950 && yI>=700 && yI<=750)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=510 && yI<=555)
		score-=10;
		if(xI>=500 && xI<=550 && yI>=350 && yI<=450)
		score-=10;
		if(xI>=400 && xI<=500 && yI>=350 && yI<=400)
		score-=10;
		if(xI>=350 && xI<=600 && yI>=200 && yI<=250)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=200 && yI<=300)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=700 && xI<=850 && yI>=500 && yI<=550)
		score-=10;
		if(xI>=900 && xI<=950 && yI>=400 && yI<=650)
		score-=10;
		if(xI>=750 && xI<=950 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=750 && xI<=800 && yI>=150 && yI<=300)
		score-=10;
		if(xI>=300 && xI<=350 && yI>=550 && yI<=600)
		score-=10;
		if(xI>=800 && xI<=850 && yI>=450 && yI<=500)
		score-=10;
		if(xI>=850 && xI<=900 && yI>=150 && yI<=200)
		score-=10;
		if(xI>=650 && xI<=700 && yI>=250 && yI<=300)
		score-=10;
		if(xI>=600 && xI<=650 && yI>=450 && yI<=500)
		score-=10;
		cout << "x-axis= " << xI << endl;
		cout << "y-axis= " << yI << endl;
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
	if( key =='s' || key =='S')
	{
	
	   menu = 1;
	}
	if( key =='c' || key =='C')
	{
	
	   menu = 2;
	}
	if ( key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}
	if(key==32 && (xI>=655 && xI<=695) && (yI>=750 && yI<=790))
	{
	
		temp_4 = false;
		temp_1 = true;
		person_circle_x = destination_drop_x;
		person_circle_y = destination_drop_y;
		passenger_line_y = destination_drop_y-40;
		passenger_line_yy= destination_drop_y;
	
	}
	else if(key==32 && (xI>=455 && xI<=495) && (yI>=450 && yI<=500))
	{
	
		temp_5 = false;
		temp_2 = true;
		person_circle_x_2 = destination_drop_x_1;
		person_circle_y_2 = destination_drop_y_1;	
		passenger_line_y_2 = destination_drop_y_1-40;
		passenger_line_yy_2 = destination_drop_y_1;
			
	}
	else if( key == 32 && (xI>= 805 && xI<= 845) && (yI>= 300 && yI<= 350))
	{
		
		temp_6 = false;
		temp_3 = true;
		person_circle_x_3 = destination_drop_x_2;
		person_circle_y_3 = destination_drop_y_2;
		passenger_line_y_3=destination_drop_y_2-40;
		passenger_line_yy_3=destination_drop_y_2;
		
			
	}
	if( key == 97 && (xI>= 800 && xI<= 980) && (yI>= 10 && yI<= 250))
	{
		temp_1 = false;
		temp_3 = true;
		score+=10;	
		cout << "A is pressed " << endl;
	}
	else if( key == 97 && (xI>= 300 && xI<= 650) && (yI>= 10 && yI<= 200))
	{
		temp_3 = false;
		temp_6 = true;
		score+=10;	
		cout << "A is pressed " << endl;
	}
	else if( key == 97 && (xI>= 10 && xI<= 300) && (yI>= 550 && yI<= 700))
	{
		temp_2 = false;
		temp_5 = true;
		score+=10;	
		cout << "A is pressed " << endl;
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
	//moveCar();
	red_car_moving();
	yellow_car_moving();
	green_car_moving();
	//cout<<score<<endl;
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
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
void MouseMoved(int x, int y) 
{
	//cout << x << " " << y << endl;
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

	} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
			cout<<"Right Button Pressed"<<endl;
	}
	glutPostRedisplay();
}

// our gateway main function
 
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	destination_drop_x=GetRandInRange(800,980);
	destination_drop_y=GetRandInRange(10,250);
	destination_drop_x_1=GetRandInRange(10,300);
	destination_drop_y_1=GetRandInRange(550,700);
	destination_drop_x_2=GetRandInRange(300,650);
	destination_drop_y_2=GetRandInRange(10,200);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Hammad Javaid"); // set the title of our game window
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
#endif /* RushHour_CPP_ */
