/*
Draw circle using points.

Signature:
void circle(cx : int, cy : int, radius : int)

*/

#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

using namespace std;

void init()
{
    glClearColor( 1.0, 0.0, 1.0, 0.0 );
	glMatrixMode( GL_PROJECTION );
    gluOrtho2D( 0.0, 200.0, 0.0, 150.0 );
}


void setPixel( int x, int y )
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.0,0.0,0.0);
	glBegin( GL_POINTS );
		glVertex2i( x, y );
	glEnd();
	glFlush();
}

void plot4points(int cx, int cy, int x, int y)
{
  setPixel(cx + x, cy + y);
  if (x != 0) setPixel(cx - x, cy + y);
  if (y != 0) setPixel(cx + x, cy - y);
  if (x != 0 && y != 0) setPixel(cx - x, cy - y);
}

void plot8points(int cx, int cy, int x, int y)
{
  plot4points(cx, cy, x, y);
  if (x != y) plot4points(cx, cy, y, x);
}

// 'cx' and 'cy' denote the offset of the circle centre from the origin.
void circle(int cx, int cy, int radius)
{
  int error = -radius;
  int x = radius;
  int y = 0;
 
  
  while (x >= y)
  {
    plot8points(cx, cy, x, y);
 
    error += y;
    ++y;
    error += y;
 
    if (error >= 0)
    {
      --x;
      error -= x;
      error -= x;
    }
  }
}


int main( int argc, char** argv)
{

        glutInit( &argc, argv );
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
        glutInitWindowPosition( 50, 100 );
        glutInitWindowSize( 800, 800 );
        glutCreateWindow( "circle using mid point" );
        init();
        circle( 70, 70, 50 );

        glutMainLoop();
}