// Copyright 2018
// Author: Luka Steinbach <luka.steinbach@gmx.de>

#include <ncurses.h>
#include <math.h>
#include "./Ball.h"

// ___________________________________________________________________________
float x;
float y;
float rx;
float ry;
float vel;
float accel;
float vector[2] = {0, 0};

// ___________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  x = 1;
  y = 1;
  rx = 10.0;
  ry = 5.0;
  vector[0] = 2;
  vector[1] = 2;
  accel = 0.5;
  vel = 0.0;
}


// ___________________________________________________________________________
void drawBall(bool color) {
  if (color == true) {
    attron(A_REVERSE);
    for (int dx = -rx; dx <= +rx; dx++) {
      for (int dy = -ry; dy <= +ry; dy++) {
         if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
           mvprintw(y + dy, x + dx, " ");
         }
      }
    }
    attroff(A_REVERSE);
  } else {
    attroff(A_REVERSE);
    for (int dx = -rx; dx <= +rx; dx++) {
      for (int dy = -ry; dy <= +ry; dy++) {
         if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
           mvprintw(y + dy, x + dx, " ");
         }
      }
    }
    attron(A_REVERSE);
  }
}

// ___________________________________________________________________________
float moveBall(int code) {
  drawBall(false);
  switch (code) {
    case KEY_LEFT:
      vector[0] -= 1;
      break;
    case KEY_RIGHT:
      vector[0] += 1;
      break;
    case KEY_UP:
      accel -= 1;
      break;
    case KEY_DOWN:
      accel += 1;
      break;
    case 27:
      return -1;
      break;
  }
  checkBorders();
  vel = sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
  vector[1] += accel / 4;
  x += vector[0];
  y += vector[1];
  return vel;
}

// ___________________________________________________________________________
void checkBorders() {
  if (x < 0 || y < 0 || x > COLS || y > LINES) {
    if (sqrt(vector[0] * vector[0] + vector[1] * vector[1]) > 0) {
      vector[0] = vector[0] * 0.9;
      vector[1] = vector[1] * 0.9;
    }
    if (x < 0) {
      vector[0] *= -1;
      x = 0;
    }
    if (x > COLS) {
      vector[0] *= -1;
      x = COLS;
    }
    if (y < 0) {
      vector[1] *= -1;
      y = 0;
    }
    if (y > LINES) {
      vector[1] *= -1;
      y = LINES;
    }
  }
}
