#include <GL/glut.h>
#include "math.h"
#define DEG2RAD 3.14159/180.0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
float op=0;
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
void output(int x, int y,const char *string)
{
  //char string[100]="GLUT_BITMAP_TIMES_ROMAN_10";
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i<len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	}

}

void verticleLine(int x,int y1,int y2)
{
  glBegin(GL_LINES);
glVertex2f(x,y1);
glVertex2f(x,y2);
  glEnd();
}

void hexagonCancer(int x,int y){
  float rad;
  float hexagon_r=15;




  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0)-5;
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0)+2;
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0)+10;

  glColor3f(1,0.5,0);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
  }


void drawCircle(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
glColor3f(r,g,b);
	glBegin(GL_POLYGON);
		for(i = 0; i <= 300;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}

void drawCircleCancer(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
glColor4f(r,g,b,op);
	glBegin(GL_POLYGON);
		for(i = 0; i <= 300;i++) {
			glVertex2f(
			    x + (radius * cos(i *  twicePi / lineAmount)),
			    y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
void CellCancer(int x,int y)
{
hexagonCancer(x,y);
  drawCircle(x,y,2,1,0,0);
}
void cell(int x,int y){
  hexagon(x,y);
  drawCircle(x,y,5,1,0,0);
  //drawCircle(x+10,y+5,10,1,0.5,0);
}
void cancerCellM(int x,int y){
  drawCircleCancer(20+x,10+y,13,1,1,0);
  drawCircleCancer(35+x,10+y,13,1,1,0);
  drawCircleCancer(30+x,20+y,10,1,1,0);
  drawCircleCancer(20+x,25+y,13,1,1,0);
  drawCircleCancer(15+x,10+y,10,1,1,0);
  drawCircleCancer(23+x,14+y,5,1,0,0);
}
void cancerCellB(int x,int y){
  drawCircle(20+x,10+y,13,1,1,0);
  drawCircle(35+x,10+y,13,1,1,0);
  drawCircle(30+x,20+y,10,1,1,0);
  drawCircle(20+x,25+y,13,1,1,0);
  drawCircle(15+x,10+y,10,1,1,0);
  drawCircle(23+x,14+y,5,1,0,0);
}
void melignant(){
  cancerCellM(230,100);
  cancerCellM(210,140);
  cancerCellM(174,170);
  cancerCellM(170,215);
  cancerCellM(195,255);
  cancerCellM(230,280);
  cancerCellM(270,270);
  cancerCellM(290,230);
  cancerCellM(275,120);
  cancerCellM(300,160);

}
void secondSet(){
  for(int i=0;i<5;i++)
  {
    hexagon(100+(i*30),100);
    drawCircle(100+(i*30),100,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(110+(i*30),140);
    drawCircle(110+(i*30),140,5,1,0,0);
  }

  for(int i=0;i<3;i++)
  {
    hexagon(100+(i*30),180);
    drawCircle(100+(i*30),180,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(100+(i*30),220);
    drawCircle(100+(i*30),220,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(80+(i*30),260);
    drawCircle(80+(i*30),260,5,1,0,0);
  }

  for(int i=0;i<5;i++)
  {
    hexagon(100+(i*30),310);
    drawCircle(100+(i*30),310,5,1,0,0);
  }

  melignant();


  glPushMatrix();

  CellCancer(230,200);
  CellCancer(250,200);
glPopMatrix();

glPushMatrix();
  CellCancer(280,220);
  CellCancer(270,180);
glPopMatrix();

glPushMatrix();
  CellCancer(230,250);
  CellCancer(290,170);
glPopMatrix();

glPushMatrix();
  CellCancer(250,240);
  CellCancer(270,150);
  glPopMatrix();
//cell(265,250);
// hexagon(230,100);
// hexagon(210,140);
// hexagon(174,170);
// hexagon(170,215);
// hexagon(195,255);
// hexagon(230,280);
// hexagon(270,270);
// hexagon(290,230);
// hexagon(275,120);
// hexagon(300,160);

}


void firstSet(){
  for(int i=0;i<5;i++)
  {
    hexagon(-250+(i*30),310);
    drawCircle(-250+(i*30),310,5,1,0,0);
  }

  for(int i=0;i<4;i++)
  {
    hexagon(-250+(i*30),260);
    drawCircle(-250+(i*30),260,5,1,0,0);
  }

  for(int i=0;i<3;i++)
  {
    hexagon(-250+(i*30),220);
    drawCircle(-250+(i*30),220,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-250+(i*30),170);
    drawCircle(-250+(i*30),170,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-250+(i*30),130);
    drawCircle(-250+(i*30),130,5,1,0,0);
  }

  for(int i=0;i<2;i++)
  {
    hexagon(-250+(i*30),90);
    drawCircle(-250+(i*30),90,5,1,0,0);
  }
  for(int i=0;i<4;i++)
  {
    hexagon(-250+(i*30),40);
    drawCircle(-250+(i*30),40,5,1,0,0);
  }

  for(int i=0;i<5;i++)
  {
    hexagon(-250+(i*30),0);
    drawCircle(-250+(i*30),0,5,1,0,0);
  }
cell(-90,10);
cell(-60,40);
cell(-45,80);
cell(-85,290);
cell(-65,250);
cell(-45,220);

cancerCellB(-130,65);
cancerCellB(-170,90);
cancerCellB(-170,140);
cancerCellB(-140,160);
cancerCellB(-150,110);
cancerCellB(-130,120);
cancerCellB(-100,130);
}
int c=0,f=1;
void display(){

glClear(GL_COLOR_BUFFER_BIT);
firstSet();
secondSet();
output(-150,400,"BENIGN TUMOR");
verticleLine(-100,380,150);
if(op<=1)
{
op+=0.002;
}else{
output(250,400,"MELIGNANT TUMOR");
verticleLine(320,380,250);
}

glFlush();

}


void init(){
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(1,1,1,1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,500,-300,500);
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
