// Copyright 2018
// Author: Luka Steinbach <luka.steinbach@gmx.de>

#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include "./Ball.h"

// Show a ball on the screen and let it be moved with the arrow keys.
int main(int argc, char** argv) {
  initTerminal();

  // Move according to arrow keys.
  while (true) {
    // Move according to pressed key.
    moveBall(getch());


    drawBall(true);
    refresh();
    // Do nothing for 1000ms.
    usleep(10000);
  }

  // Clean up.
  endwin();
}
