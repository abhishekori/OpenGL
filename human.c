#include <GL/glut.h>
#include "math.h"
#define DEG2RAD 3.14159/180.0
#include<stdio.h>

void hexagon(int x,int y){
  float rad;
  float hexagon_r=20;

  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);

  glColor3f(0,0.8,0);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
}

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
float yLocation = 0.0f;
float bloby=0,blobx=0,cx1=0,cy1=0;
int ctr=0,ctr1=0,c2=0,c3=0;

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
glColor3f(0,0,0);
	glBegin(GL_POLYGON);
		for(i = 0; i <= 300;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void bloodVessel()
{
  //blood vessel cross section start


  glPushMatrix();

  glBegin(GL_POLYGON);

  glColor3f(1,0,0);

  glVertex2f(300,200);

  glVertex2f(310,20);

  glVertex2f(270,-150);

  glVertex2f(230,-300);

  glVertex2f(290,-300);

  glVertex2f(330,-150);

  glVertex2f(350,20);

  glVertex2f(360,200);

  glVertex2f(410,300);

  glVertex2f(460,330);

  glVertex2f(510,350);

  glVertex2f(510,410);

  glVertex2f(400,360);

  glVertex2f(360,320);

  glVertex2f(300,500);


  glVertex2f(180,500);
  glEnd();

glPopMatrix();

glPushMatrix();

glBegin(GL_LINE_LOOP);

glColor3f(0,0,0);

glVertex2f(300,200);

//glVertex2f(310,20);

//glVertex2f(270,-150);

glVertex2f(230,-300);

glVertex2f(290,-300);

glVertex2f(330,-150);

glVertex2f(350,20);

glVertex2f(360,200);

glVertex2f(395,270);

//glVertex2f(460,330);

glVertex2f(510,350);

glVertex2f(510,410);

glVertex2f(400,360);

glVertex2f(360,320);

glVertex2f(300,500);


glVertex2f(180,500);
glEnd();
glPopMatrix();
}



void humanBody(){
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

}

void blobAnimation(){
  //glPopMatrix();
  //glPushMatrix();
  glColor3f(1,0,0);
  glTranslatef(blobx,bloby,0);
  DrawEllipse(5,5,10,35);
  glPopMatrix();

  //update();
  if(ctr<155)
  {

    bloby+=0.5;
    ctr++;
  }else{
    if(ctr1<40)
    {
      bloby-=0.7;
      blobx-=0.5;
      ctr1++;

    }

  }
}

void cell(int x,int y,int r){
  hexagon(x,y);
  drawHollowCircle(x,y,r);

}

void cellanimation1(){
//  int x1=0,y1=0,ctr1=0,ctr2=0;

glPushMatrix();
  glTranslatef(cx1,cy1,0);
  cell(300,100,5);
  glPopMatrix();
  if(c2<200)
  {
    cy1+=0.5;
    cx1+=0.1;
    c2++;
  }else if(c2<835){
    
      cy1+=0.5;
      cx1-=0.1;
      c2++;


  }
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

humanBody();
blobAnimation();

bloodVessel();

cellanimation1();
glFlush();



}
void init(){
  glClearColor(1,1,1,1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,500,-300,500);
}


void reshape (int width, int height) {
glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
//glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
//glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)

//gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field oS view angle (in degrees), the aspect ratio of our window, and the new and far planes

//glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("human");
  glutDisplayFunc(display);
  glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well

//glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
  init();
  glutMainLoop();
  return 0;
}
