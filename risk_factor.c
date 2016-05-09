#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<string.h>

#define RADPERDEG 0.0174533
double theta=0;
int frameNumber =0;


void *fonts[] = { GLUT_BITMAP_9_BY_15,
				  GLUT_BITMAP_TIMES_ROMAN_10,
				  GLUT_BITMAP_TIMES_ROMAN_24,
				  GLUT_BITMAP_HELVETICA_18,
                  GLUT_BITMAP_HELVETICA_12 };

typedef struct Point {
  GLfloat x;
  GLfloat y;
} Point;
void init(){

  glClearColor(1.0,1.0,1.0,1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-300,500,-300,500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 20; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y); // center of circle
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
      x + (radius * cos(i *  twicePi / triangleAmount)),
      y + (radius * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments){
  glLineWidth(1.5f);
  glBegin(GL_LINE_LOOP);
  for(int ii = 0; ii < num_segments; ii++)
  {
    float theta = 2.0f * 3.1415926f * (float)ii / (float)num_segments;//get the current


    float x = r * cosf(theta);//calculate the x component
    float y = r * sinf(theta);//calculate the y component

    glVertex2f(x + cx, y + cy);//output vertex

  }
  glEnd();
}

void drawHollowElipse(GLfloat x, GLfloat y, GLfloat radiusx,GLfloat radiusy){
  int i;
  int lineAmount = 100; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_LINE_LOOP);
  for(i = 0; i <= lineAmount;i++) {
    glVertex2f(
      x + (radiusx * cos(i *  twicePi / lineAmount)),
      y + (radiusy* sin(i * twicePi / lineAmount))
    );
  }
  glEnd();
}
void drawFilledElipse(GLfloat x, GLfloat y, GLfloat radiusx,GLfloat radiusy){
  int i;
  int triangleAmount = 20; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * M_PI;

  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y); // center of circle
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
      x + (radiusx * cos(i *  twicePi / triangleAmount)),
      y + (radiusy * sin(i * twicePi / triangleAmount))
    );
  }
  glEnd();
}

void drawCig(){
  int xLL=20,yLL=40,xLR,yLR;
  /*Point p1={85,230},
  p2={115,230},
  p3={135,350},
  p4={65,350},*/
  double factor=5.0f/6.0f;
  Point p1={-5,-5},
  p2={5,-5},
  p3={5,15},
  p4={-5,15},

  p5={(p3.x+p2.x)/2.0f,(p3.y+p2.y)*factor},
  p6={(p1.x+p4.x)/2.0f,(p1.y+p4.y)*factor};
  double radiusy=1.5;
  //filled part
  glColor3f(.894f, .925f,.89f );
  glBegin(GL_POLYGON);
  glColor3f( .953, .933,.824);
  glVertex2f(p5.x,p5.y);
  glVertex2f(p6.x,p6.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p4.x,p4.y);
  glEnd();

  //  drawFilledElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, 4);
  drawFilledElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);
  glColor3f(0,0,0);
  //  drawHollowElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,8);
  glEnd();

  // outlline of the quadrilateral
  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f( 0,0,0);
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p4.x,p4.y);
  glEnd();

  //lower outline
  drawHollowElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, radiusy);
  glLineWidth(1.0f);

  //filled polygon
  glBegin(GL_POLYGON);
  glColor3f( .953, .933,.824);
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p4.x,p4.y);
  glEnd();

  //lower  ellipse
  drawFilledElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, radiusy);
  drawFilledElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);
  glColor3f(0,0,0);
  drawHollowElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);

  //filled area
  glBegin(GL_POLYGON);
  glColor3f(0.855f,0.651f,0.322f);
  glVertex2f(p4.x,p4.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p5.x,p5.y);
  glVertex2f(p6.x,p6.y);
  glEnd();

  //upper filled elipse
  drawFilledElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);
  drawHollowElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);
  drawFilledElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);
  glColor3f(0,0,0);
  drawHollowElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);


}

void drawCigs(){

  //  glTranslated(-5,0,0);
  for (int i = 0; i < 4; i++) {
    glTranslated(i+12, 0, 0);
    drawCig();
  }
}
void drawFan() {
  int i,frameNumber =0;

  glRotated(frameNumber * (180.0/46), 0, 0, 1);
  glColor3f(.349f, .267f, .231f );
  for (i = 0; i < 3; i++) {
    glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0.5f, 0.4f);
    //glVertex2f(1.5f,0);

    glVertex2f(0.5f, -0.4f);
    /*(glVertex2f(0.3,0.2);
    //   glVertex2f(0.5f, 0.1f);
    glVertex2f(0.7f,0.2);
    glVertex2f(0.5f, -0.1f);*/
    glEnd();
    drawFilledElipse(.5,0,.15,.4);
  }
  double r=.1;
  glColor3f(	.725f, .933f, .871f);
  drawFilledCircle(0,0,(r+.05));
  glColor3f(.349f, .267f, .231f );
  drawFilledCircle(0,0,r);
}

void drawGlass(){
  int xLL=20,yLL=40,xLR,yLR;
  /*Point p1={85,230},
  p2={115,230},
  p3={135,350},
  p4={65,350},*/
  Point p1={-5,-5},
  p2={5,-5},
  p3={5,15},
  p4={-5,15},

  p5={(p3.x+p2.x)/2.0f,(p3.y+p2.y)/2.0f+1.6},
  p6={(p1.x+p4.x)/2.0f,(p1.y+p4.y)/2.0f+1.6};
  double radiusy=1.5;
  //filled part
  glColor3f(.894f, .925f,.89f );
  glBegin(GL_POLYGON);
  glColor3f( .953, .933,.824);
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glVertex2f(p5.x,p5.y);
  glVertex2f(p6.x,p6.y);
  glEnd();

  //  drawFilledElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, 4);
  drawFilledElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);
  glColor3f(0,0,0);
  //  drawHollowElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,8);
  glEnd();


  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP);
  glColor3f( 0,0,0);
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p4.x,p4.y);
  glEnd();

  drawHollowElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, radiusy);
  glLineWidth(1.0f);

  glBegin(GL_POLYGON);
  glColor3f( .953, .933,.824);
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glVertex2f(p3.x,p3.y);
  glVertex2f(p4.x,p4.y);
  glEnd();

  //drawFilledElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, 4);
  drawFilledElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);
  glColor3f(0,0,0);
  drawHollowElipse((p3.x+p4.x)/2,p3.y,(p4.x-p3.x)/2,radiusy);

  //filled area
  glBegin(GL_POLYGON);
  glColor3f(0.757f ,0.471f,0.071f);
  //glColor3f(.89f,.92f,.89f );
  glVertex2f(p1.x,p1.y);
  glVertex2f(p2.x,p2.y);
  glColor3f(.965f,0.733f,0.133f);
  glVertex2f(p5.x,p5.y);
  glVertex2f(p6.x,p6.y);
  glEnd();

  drawFilledElipse((p1.x+p2.x)/2, p1.y, (p2.x-p1.x)/2, radiusy);
  drawFilledElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);

  glColor3f(0.918f,0.675f,0.118f);
  drawHollowElipse((p5.x+p6.x)/2.0f,p5.y,(p6.x-p5.x)/2.0f,radiusy);


}

void setBackgroundColor(){
  int x,y;
  x=300;
  y=300;
  glBegin(GL_POLYGON);
  glColor3f(.9492f, .9255f, .8745f );
  glVertex2f(0-x,0-y);
  glVertex2f(899-x,0-y);

  glColor3f(1.0,1.0,1.0);
  glVertex2f(899-x,599-y);
  glVertex2f(0-x,899-y);
  glEnd();
  glFlush();
}

void drawDisk(double radius) {
  int d;
  glBegin(GL_POLYGON);
  for (d = 0; d < 32; d++) {
    double angle = 2*M_PI/32 * d;
    glVertex2d( radius*cos(angle), radius*sin(angle));
  }
  glEnd();
}

void drawSun() {
  int i;
  //glColor3f(1,1,0);

  // glColor3f( .953, .933,.824);
  glColor3f(.98,.850,.36);
  glLineWidth(3.0f);
  for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
    glRotatef( 360 / 13, 0, 0, 1 ); // Note that the rotations accumulate!
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(75, 0);
    glEnd();
  }
  glLineWidth(1.0f);
  drawDisk(40);
  glColor3f(0,0,0);
}

void Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D){
  double x=x2-x1;
  double y=y2-y1;
  double z=z2-z1;
  double L=sqrt(x*x+y*y+z*z);
  glColor3f(.694f,.859f,.133f);	//69.4, 85.9, 13.3
  GLUquadricObj *quadObj;

  glPushMatrix ();

  glTranslated(x1,y1,z1);
  //rotation

  if(theta<=120){
    theta= (frameNumber * (180.0/46));
  }
  glRotated(-theta, 0, 0, 1);

  if((x!=0)||(y!=0)) {
    glRotated(atan2(y,x)/RADPERDEG,0.,0.,1.);
    glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.,1.,0.);
  } else if (z<0){
    glRotated(180,1.,0.,0.);
  }

  glTranslatef(0,0,L-4*D);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluCylinder(quadObj, 2*D, 0.0, 4*D, 32, 1);
  gluDeleteQuadric(quadObj);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluDisk(quadObj, 0.0, 2*D, 32, 1);
  gluDeleteQuadric(quadObj);

  glTranslatef(0,0,-L+4*D);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluCylinder(quadObj, D, D, L-4*D, 32, 1);
  gluDeleteQuadric(quadObj);

  quadObj = gluNewQuadric ();
  gluQuadricDrawStyle (quadObj, GLU_FILL);
  gluQuadricNormals (quadObj, GLU_SMOOTH);
  gluDisk(quadObj, 0.0, D, 32, 1);
  gluDeleteQuadric(quadObj);

  glPopMatrix ();

}

void drawAxes(GLdouble length){
  glPushMatrix();
  glTranslatef(-length,0,0);
  Arrow(0,0,0, 2*length,0,0, 0.2);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-length,0);
  Arrow(0,0,0, 0,2*length,0, 0.2);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,0,-length);
  Arrow(0,0,0, 0,0,2*length, 0.2);
  glPopMatrix();
}

void doFrame(int v) {
  frameNumber++;
  glutPostRedisplay();
  glutTimerFunc(60,doFrame,0);
}


void drawBitmapText(const char *string, void *font,float x,float y){
  int len, i;
  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (i = 0; i<len; i++)
  {
    glutBitmapCharacter(font, string[i]);
  }
}



void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  //setting background color gradient
  setBackgroundColor();
int x, y;
x=350;
y=350;
  /*
  glColor3f(0,0,0);
  drawCircle(450,480,80,1000);
  drawCircle(450,180,80,1000);
  drawCircle(250,420,80,1300);
  drawCircle(650,420,80,1300);
  drawCircle(100,290,80,1300);
  drawCircle(800,290,80,1300);*/
  glColor3f(	.725f, .933f, .871f);
  //  drawGlass(0,0,0);
  double radius=85;
  drawFilledCircle(450-x,480-y,radius);
  drawFilledCircle(250-x,420-y,radius);
  drawFilledCircle(650-x,420-y,radius);
  drawFilledCircle(100-x,290-y,radius);
  drawFilledCircle(800-x,290-y,radius);

  //drawing glass
  glPushMatrix();
  glTranslated(100-x,275-y,0);
  glScaled(5,5,1);
  drawGlass();
  glPopMatrix();
  //drawing sun
  glPushMatrix();
  glTranslated(250-x,420-y,0);
  glRotated(-frameNumber*.9,0,0,1);
  drawSun();
  glPopMatrix();


  //drawing cigarette
  glPushMatrix();
  glTranslated(385-x,455-y,0);
  glScaled(2,4,1);
  drawCigs();
  glPopMatrix();
  //drawing fan
  glPushMatrix();
  glTranslated(800-x,290-y,0);
  glRotated(-frameNumber*.9,0,0,1);
  glScaled(90,90,1);
  drawFan();
  glPopMatrix();


  //print asbest
  glPushMatrix();
  //glScaled(2,2,0);
  glTranslated(600-x,410-y,0);
  drawBitmapText("ASBEST",fonts[2],1,1);
  glPopMatrix();



  //draw arrow
  glPushMatrix();
  glScalef(.5,.5,0);
  glTranslated(150-x,-(y+70),0);
  Arrow(400,120,0,90,290,0,8);
  glPopMatrix();

  //glFlush();
  glutSwapBuffers();
}

int main(int argc,char* argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(1000,1000);
  glutInitWindowPosition(0,0);
  glutCreateWindow("nframe");
  glutDisplayFunc(display);
  glutTimerFunc(500,doFrame,0);
  init();
  glutMainLoop();
  return 0;
}
