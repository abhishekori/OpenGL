#include <GL/glut.h>
#include "math.h"
#define DEG2RAD 3.14159/180.0

void DrawEllipse(float radiusX, float radiusY,int posx,int posy)
{
   int i;

   glBegin(GL_POLYGON);

   for(i=0;i<360;i++)
   {
      float rad = i*DEG2RAD;
      glVertex2f(posx+cos(rad)*radiusX,
                  posy+sin(rad)*radiusY);
   }

   glEnd();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1,0.87,0.77);

glPushMatrix();
glRotatef(-10,0,0,1);
DrawEllipse(10,50,-0,0); //left leg
glPopMatrix();

glPushMatrix();
glRotatef(10,0,0,1);
DrawEllipse(10,50,25,-7); //right leg
glPopMatrix();
DrawEllipse(20,50,12,70); //center torso

glPushMatrix();

glRotatef(60,0,0,1);
DrawEllipse(40,10,60,55); // left arm
glPopMatrix();

glPushMatrix();
glRotatef(-60,0,0,1);
DrawEllipse(40,10,-50,75);// right arm
glPopMatrix();

DrawEllipse(15,25,12,135); //head

glPushMatrix();

glColor3f(1,0,0);
glBegin(GL_LINES);
glVertex2f(12,30); // center blood vessel
glVertex2f(12,120);

glVertex2f(12,118); // left line
glVertex2f(-8,90);

glVertex2f(-8,90); // left arm
glVertex2f(-30,60);

glVertex2f(12,118); // right vessel
glVertex2f(50,65);

glVertex2f(12,35); // right down  blood vessel
glVertex2f(25,10);


glVertex2f(25,10);  // right down calf blood vessel
glVertex2f(30,-20);

glVertex2f(12,35); // left down blood vessel
glVertex2f(2,10);

 // left down blood vessel
glVertex2f(2,10);
glVertex2f(-5,-30);

glEnd();
glPopMatrix();

glFlush();
}

void init(){
  glClearColor(1,1,1,1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500,500,-500,500);
}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("human");
  glutDisplayFunc(display);
  init();
  glutMainLoop();
  return 0;
}
