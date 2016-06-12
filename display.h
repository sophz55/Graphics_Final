#ifndef DISPLAY_H
#define DISPLAY_H

#include "matrix.h"

void init_z_buffer( struct matrix* zb );
void plot( screen s, color c, int x, int y, int z, struct matrix *zb );
void clear_screen( screen s);
void save_ppm( screen s, char *file);
void save_extension( screen s, char *file);
void display( screen s);

color change_color( int i );
#endif
