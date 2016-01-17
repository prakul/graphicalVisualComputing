/*
Draw a point 

Signature:
void point(x: float, y : float)

*/
#include <GL/glut.h>
#include <iostream>

using namespace std;

void init()
{
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	
	glMatrixMode( GL_PROJECTION );
	gluOrtho2D( 0.0, 200.0, 0.0, 150.0 );
}

void point(void)
{
	float x;
	float y;

	glClear(GL_COLOR_BUFFER_BIT );
	glColor3f( 1.0, 1.0, 1.0 );
	glBegin( GL_POINTS );
		cin >> x;
		cin >> y; 
		glVertex2i( x, y );
	glEnd();

	glFlush();
}
	
int main( int argc, char** argv)
{

	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition( 50, 100 );
	glutInitWindowSize( 400, 300 );
	glutCreateWindow( "Point" );

	init();
	glutDisplayFunc( point );

	glutMainLoop();
}
