#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1){
    draw_line(x1, y1, x0, y0, s, c);
    return;
  }
  
  int A, B, d, x, y;
  A = y1 - y0; //positive for oct 1,2; negative for oct 7,8
  B = x0 - x1; //negative for all oct
  
  x = x0;
  y = y0;
  
  if (A > 0) {
    if (A < (-1)*B){ //octant 1
      d = 2*A + B;
      A = 2*A;
      B = 2*B;
      while (x <= x1) {
	plot(s, c, x, y);
	if (d > 0) {
	  y += 1;
	  d += B;
	  }
	x += 1;
	d += A;
      }
    }
    else { //octant 2
      d = A + 2*B;
      A = 2*A;
      B = 2*B;
      while (y <= y1) {
	plot(s, c, x, y);
	if (d < 0) {
	  x += 1;
	  d += A;
	}
	y += 1;
	d += B;
      }
    }
  }
  else {
    if ((-1)*A < (-1)*B) { //octant 8
      d = 2*A - B;
      A = 2*A;
      B = 2*B;
      while (x <= x1) {
	plot(s, c, x, y);
	if (d < 0) {
	  y -= 1;
	  d -= B;
	}
	x += 1;
	d += A;
      }
    }
    else { //octant 7
      d = A + 2*B;
      A = 2*A;
      B = 2*B;
      while (y >= y1) {
	plot(s, c, x, y);
	if (d > 0) {
	  x += 1;
	  d += A;
	}
	y -= 1;
	d -= B;
      }
    }
  }  
}

