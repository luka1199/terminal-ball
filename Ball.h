// Copyright 2018
// Author: Luka Steinbach <luka.steinbach@gmx.de>

#ifndef BALL_H_
#define BALL_H_

// Position and radii.
extern float x;
extern float y;
extern float rx;
extern float ry;
extern float vel;
extern float vector[2];

// Initialize screen and global variables.
void initTerminal();

// Draw the ball.
void drawBall(bool color);

// Move the ball.
float moveBall(int code);

// Checks if ball went over one of the borders
void checkBorders();


#endif  // BALL_H_
