#include <GL/glut.h>
#include "math.h"
#define DEG2RAD 3.14159/180.0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
float op=0,sc1op=1;

//SECOND SCENE START
void hexagon(int x,int y){
  float rad;
  float hexagon_r=20;

  float hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  float hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  float hexagon_gx=2.0*hexagon_dx;
  float hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);

  glColor4f(0,0.8,0,sc1op);
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

  glColor4f(1,0.5,0,sc1op);
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
glColor4f(r,g,b,sc1op);
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
int c=0,f=1;

//SECOND SCENE END

//THIRD SCENE START

void horzontalLine(int Lx1,int Lx2,int Ly){
  glBegin(GL_LINES);
  glVertex2f(Lx1,Ly);
  glVertex2f(Lx2,Ly);
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
float bloby=0,blobx=0,cx1=0,cy1=0,cx2=0,cy2=0;
int c0=0,c1=0,c2=0,c3=0;


void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius,int r,int g,int b){
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

void bloodVessel()
{
  //blood vessel cross section start


  glPushMatrix();

  glBegin(GL_POLYGON);

  glColor3f(1,0,0);

  glVertex2f(300,200); //1
  glVertex2f(310,20);

  glVertex2f(270,-150); //2
  glVertex2f(230,-300);

  glVertex2f(290,-300); //3
  glVertex2f(330,-150);

  glVertex2f(350,20); //4
  glVertex2f(360,200);

  glVertex2f(410,300); //5
  glVertex2f(460,330);

  glVertex2f(510,350); //6
  glVertex2f(510,430);

  glVertex2f(400,360); //7
  glVertex2f(360,320);

  glVertex2f(300,500); //8
  glVertex2f(180,500);
  glEnd();

glPopMatrix();

glPushMatrix();

glBegin(GL_LINE_LOOP);

glColor3f(0,0,0);

glVertex2f(300,200); //1
//glVertex2f(310,20);

//glVertex2f(270,-150); //2
glVertex2f(230,-300);

glVertex2f(290,-300); //3
glVertex2f(330,-150);

glVertex2f(350,20); //4
glVertex2f(360,200);

glVertex2f(395,270); //5
//glVertex2f(460,330);

glVertex2f(510,350); //6
glVertex2f(510,430);

glVertex2f(400,360); //7
glVertex2f(360,320);

glVertex2f(300,500); //8
glVertex2f(180,500);
glEnd();
glPopMatrix();
glPushMatrix();
glColor3f(0,0,0);
output(30,-100,"BLOOD VESSEL");
horzontalLine(175,300,-90);
output(30,450,"MELIGNANT");

glPopMatrix();

}



void humanBody(){
  glColor3f(1,0.87,0.77);
  glPushMatrix();
  glRotatef(-10,0,0,1);
  DrawEllipse(10,50,0,0); //left leg
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
  if(c0<155)
  {

    bloby+=0.5;
    c0++;
  }else if(c1<40)
    {
      bloby-=0.7;
      blobx-=0.5;
      c1++;

  }else{
    glPushMatrix();
    glColor3f(0,0,0);
    output(-270,70,"New tumour");
    output(-270,40,"METASTASIS");
    horzontalLine(-110,-15,85);
    glPopMatrix();
  }
}

void cell(int x,int y,int r){
  hexagon(x,y);
  drawHollowCircle(x,y,r,0,0,0);

}
 void cancerCell(int x,int y){
   int r=15,R=1,G=1,B=0;

   drawHollowCircle(x,y,r,R,G,B);
   drawHollowCircle(x+15,y,r,R,G,B);
   drawHollowCircle(x+5,y-15,r,R,G,B);
   drawHollowCircle(x+13,y-3,r,R,G,B);
  drawHollowCircle(x,y+16,r,R,G,B); // nucleus
   drawHollowCircle(x+3,y,5,0,1,1);

 }
void cellanimation1(){
//  int x1=0,y1=0,ctr1=0,ctr2=0;

glPushMatrix();
  glTranslatef(cx1,cy1,0);
  cancerCell(300,100);
  cancerCell(335,120);
  glPopMatrix();

  glPushMatrix(); // second set of cells
  glTranslatef(cx2,cy2,0);
  cancerCell(330,35);
  cancerCell(320,0);
  glPopMatrix();

  if(c2<200)
  {
    cy1+=0.5;
    cx1+=0.1;

    c2++;
  }else if(c2<835){

      cy1+=0.5;
      cx1-=0.15;

      c2++;


  }

  if(c3<350){
    cy2+=0.5;
    cx2+=0.01;
    c3++;
  }else if(c3<500){
    cy2+=0.68;
    cx2+=0.35;
    c3++;
  }else if(c3<700){
    cy2+=0.50;
    cx2+=0.70;
    c3++;
  }
}

void normalCells(){
  cell(80,30,5);
  cell(80,65,5);
  cell(135,65,5);
  cell(170,65,5);
  cell(195,65,5);
  cell(265,85,5);
  cell(280,120,5);

  cell(100,100,5);
  cell(130,130,5);
  cell(160,160,5);
  cell(190,190,5);
  cell(220,220,5);
  cell(260,240,5);

  cell(170,105,5);
  cell(215,145,5);
  cell(100,185,5);
  cell(110,215,5);
  cell(120,255,5);
  for(int i=0;i<7;i++)
  {
    cell(100+(i*35),0,5);
  }

}



//THIRD SCENE END
void init(){
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(1,1,1,1);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,500,-300,500);
}
int scount=0;
void display(){

glClear(GL_COLOR_BUFFER_BIT);

if(scount==1)
{
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
  // SECOND SCENE FUNCTIONS START
  }


}
if(scount==2)
{
  //printf("yes\n");
  humanBody();
  blobAnimation();

  bloodVessel();

  normalCells();

  cellanimation1();

}

glFlush();

}

void NormalKey(GLubyte key, GLint x, GLint y)
{
  if(key=='B')
  {
  scount=1;
  //glutPostRedisplay();
  }

  if(key=='C')
  {
    scount=2;
  //  display();
    //glutPostRedisplay();
  //  break;
  }

}

int main(int argc,char **argv){
  glutInit(&argc,argv);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("human");
  glutDisplayFunc(display);
  glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well

//glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
glutKeyboardFunc(NormalKey);
  init();
  glutMainLoop();
  return 0;
}
