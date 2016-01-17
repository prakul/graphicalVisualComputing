/*
Draw a line using closely placed points. If dx is the spacing between 2 points in x, then
dx=|x1-x2|/ Np. Np is the number of points in the line. Now keep changing N and
check the time taken to execute your code (Use Large N).
Plot Time take with respect to N.

Signature:

void line(x1: float, y1 : float, x2: float, y2 : float, Np: int)
*/




#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

void init()
{
        glClearColor( 0.0, 1.0, 0.0 , 0.0 );

        glMatrixMode( GL_PROJECTION );
        gluOrtho2D( 0, 200, 0, 250 );
}

void line( float x1, float y1, float x2, float y2, int n )
{
        glClear( GL_COLOR_BUFFER_BIT );
        glColor3f( 0.0, 0.0, 1.0 );
	float m = abs( y2 - y1 )/ abs( x2 - x1 );
	
	float dx = abs( x2 - x1 ) / n;
	float x = x1,y = y1;
	float c = abs( ( ( x1*y2 ) - ( x2*y1) )/(x2 - x1) ); 
	for  ( int i = 0; i < n; i++ ) {
		x = x + dx;
		y = m*x + c;
        	glBegin( GL_POINTS );
                	glVertex2f( x, y );
        	glEnd();
	}
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

        line( x1, y1, x2, y2, 10 );
	int time;
	time = glutGet( GLUT_ELAPSED_TIME);
	cout << time << endl;
        glutMainLoop();
}
