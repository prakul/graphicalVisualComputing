/*
Draw a rectangle. Here only the coordinate of the diagonal is provided.

Signature
void Rectangle(x1: float, y1 : float, x2: float, y2 : float)
   
*/



#include <iostream>
#include <GL/glut.h>

using namespace std;

void init()
{
	glClearColor( 0.0, 1.0, 0.0 , 0.0 );

	glMatrixMode( GL_PROJECTION );
	gluOrtho2D( 0, 200, 0, 250 );
}

void rectangle(float x1, float y1, float x2, float y2 )
{
	glClear( GL_COLOR_BUFFER_BIT );
	glColor3f( 1.0, 0.0, 0.0 );
	glBegin( GL_LINE_LOOP );
		glVertex2f( x1, y1 );
		glVertex2f( x2,  y1 );
		glVertex2f( x2 , y2 );
		glVertex2f( x1, y2 );
	glEnd();
	glFlush();

}



int main( int argc, char ** argv )
{

	glutInit( &argc, argv );

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition( 200, 200 );
	glutInitWindowSize( 300, 400 );
	glutCreateWindow( "Rectangle" );

	init();

	float x1 = 50;
        float y1 = 50;
        float x2 = 80;
        float y2 = 20; 

	rectangle( x1, y1, x2, y2 );
	glutMainLoop();
}
	
