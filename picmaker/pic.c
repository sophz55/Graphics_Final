#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

  int file = open( "pic.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644 );
  int xres = 500;
  int yres = 500;
  int max_color = 255;

  char line[256];
  sprintf( line, "P3 %d %d %d", xres, yres, max_color );
  write( file, line, 256 );

  int i,j,r,g,b;
  
  for (i = 0; i < 500; i++){
    for (j = 0; j< 500; j++ ) {
      r = 255;
      g = j % 256;
      b = i % 256;
      sprintf(line,"%d %d %d ", r, g, b);
      write(file, line, 256 );
    }
  }

  close(file);
  return 0;
}
