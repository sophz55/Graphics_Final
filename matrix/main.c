#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
//#include "parser.h"

int main() {

  screen s;
  clear_screen(s);
  color c;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 1);
  transform = new_matrix(4, 4);

  add_edge(edges, XRES / 16, YRES / 8, 0, XRES / 8, YRES / 16, 0);
  add_edge(edges, XRES / 8, YRES / 16, 0, XRES * 5/16, YRES * 3/8, 0 );
  add_edge(edges, XRES * 5/16, YRES * 3/8, 0, XRES * 3/8, YRES * 5/16, 0 );
  add_edge(edges, XRES * 3/8, YRES * 5/16, 0, XRES / 16, YRES / 8, 0 );  
  
  transform = make_rotZ( 60.0 );
  print_matrix(transform);
  int i;
  for(i = 0; i < 50; i++){
    c.red = 0;
    c.green = 5*i;
    c.blue = 255 - 5*i;

    matrix_mult(transform, edges);
    draw_lines(edges,s,c);
    scalar_mult(1.05, edges);
  }

  free_matrix( transform );
  free_matrix( edges );

  save_extension(s, "matrix.png");
}  
