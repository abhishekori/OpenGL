#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#define DEG2RAD 3.14159/180.0
//FIRST FRAME BEGIN
float hexagon_r=20;
float op=0,maincount=0;
float hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy;
void draw_hexagon(float,float);
void drawCircle(float, float , float , int);

void drawCancerCells(float,float,int,int);



void initialize(){

  hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  hexagon_gx=2.0*hexagon_dx;
  hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);
  // printf("%d  %d  %d  %d\n",hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy );
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 20; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_POLYGON);
  glVertex2f(x, y); // center of circle
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
      x + (radius * cos(i *  twicePi / triangleAmount)),
      y + (radius * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}

void draw_hexagon(float x,float y)
{
  glBegin(GL_LINE_LOOP);
  glVertex2f(x-hexagon_dx,y-hexagon_dy);
  glVertex2f(x-hexagon_dx,y+hexagon_dy);
  glVertex2f(x           ,y+hexagon_r );
  glVertex2f(x+hexagon_dx,y+hexagon_dy);
  glVertex2f(x+hexagon_dx,y-hexagon_dy);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
  //glFlush();
  drawCircle(x,y,4.0,20);
}
float f1op=1;
void drawCancerCell(float x,float y,float dx,float dy)
{

  int r =( rand() % 20)/10.0f;
  dx*=r;
  dy*=r;
  glColor4f(0.831f,0.608f,0.627f,f1op);
  glBegin(GL_POLYGON);
  glVertex2f(x-hexagon_dx-2*dx,y-hexagon_dy+dy);
  glVertex2f(x-hexagon_dx+dx,y+hexagon_dy+dy);
  glVertex2f(x     +dx      ,y+hexagon_r );
  glVertex2f(x+hexagon_dx-dx,y+hexagon_dy-dy);
  glVertex2f(x+hexagon_dx-dx,y-hexagon_dy+dx);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();

  glColor4f(0.612f,0.220f,0.290f,f1op);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x-hexagon_dx-2*dx,y-hexagon_dy+dy);
  glVertex2f(x-hexagon_dx+dx,y+hexagon_dy+dy);
  glVertex2f(x     +dx      ,y+hexagon_r );
  glVertex2f(x+hexagon_dx-dx,y+hexagon_dy-dy);
  glVertex2f(x+hexagon_dx-dx,y-hexagon_dy+dx);
  glVertex2f(x           ,y-hexagon_r );
  glEnd();
  glColor4f(0.596f,0.537f,0.494f,f1op);
  drawFilledCircle(x,y,4);
  glFlush();
}

void draw_hexagon_grid(float x,float y,int ni,int nj)
{
  int i,j; float x0,shiftP=2.0;
  x-=((float)(ni-1))*hexagon_gx*0.5; // just shift x,y to start position (i=0,j=0)
  x-=((float)(nj-1))*hexagon_dx*0.5;
  y-=((float)(nj-1))*hexagon_gy*0.5;
  //x1=x+15*hexagon_gx*0.5,y1=y+9*hexagon_gx*0.5;
  for (x0=x,j=0;j<nj;j++,x0+=hexagon_dx+shiftP,x=x0+shiftP,y+=hexagon_gy+shiftP)
  for (i=0;i<ni;i++,x+=hexagon_gx+shiftP){
    draw_hexagon(x,y);
  }
}

  void drawCircle(float cx, float cy, float r, int num_segments)
  {
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
      float theta = 2.0f * 3.1415926f * (float)ii / (float)(num_segments);//get the current angle

      float x = r * cosf(theta);//calculate the x component
      float y = r * sinf(theta);//calculate the y component

      glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
  }

//FIRST FRAME DONE

//SECONE FRAME START
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


//SECOND FAME END
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.0, 0.0);


  draw_hexagon_grid(0,0,10,10);


glPushMatrix();
//glColor4f(1,1,1,f1op);
  drawCancerCell(100,100,1,1);
  drawCancerCell(100,60,1,1);
  drawCancerCell(130,50,1,1);
  drawCancerCell(140,90,1,1);
  drawCancerCell(170,90,1,1);
  drawCancerCell(100,10,1,1);
  drawCancerCell(70,40,1,1);



  glPopMatrix();

  glFlush();
  if(maincount<100)
  {
    maincount+=100;
  }else{
    glClearColor(1,1,1,1);
  }
  //f1op+=0.5;
//  glutSwapBuffers();
}
void init(){
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(1,1,1,1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,500,-300,500);
}

int main(int argc, char** argv)
{
//   glutInit(&argc,argv);
//
//
//
//   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
//   glutInitWindowSize(1000,1000);
//   //  glutInitWindowPosition(0,0);
//   glutCreateWindow("Polygon");
//   //glutTimerFunc(10, Timer, 0);
//   glutDisplayFunc(display);
//   glEnable(GL_BLEND);
// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//   glClearColor(1.0,1.0,1.0,1.0);
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   gluOrtho2D(-300,500.0,-300,500.0);
//   glutMainLoop();
glutInit(&argc,argv);
glutInitWindowSize(1000,1000);
glutCreateWindow("human");
initialize();
glutDisplayFunc(display);
glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well

//glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
init();
glutMainLoop();
return 0;


}
