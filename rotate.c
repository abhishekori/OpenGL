#include<GL/glut.h>
float spin = 0;
void square()
{

 glBegin(GL_POLYGON);
  glVertex2f(-100,-100);
  glVertex2f(-100,100);
  glVertex2f(100,100);
  glVertex2f(100,-100);
 glEnd();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_LINES);
 glVertex2f(300,400);
 glVertex2f(400,400);
 glEnd();
 glPushMatrix();
 glRotatef(spin,0,0,1);
 glTranslatef(200,200,0);
 square();
 glPopMatrix();
 glFlush();
}
void init()
{
	glClearColor(1,1,1,1);
	glColor3f(0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

void idle()
{
 spin += 1;
 if(spin>360) spin -= 360;
 glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
        glutIdleFunc(idle);
	init();
	glutMainLoop();
}
