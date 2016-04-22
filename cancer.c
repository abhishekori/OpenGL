#include<GL/glut.h>
#include<stdio.h>
#include <math.h>

float hexagon_r=20;
float hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy;
void draw_hexagon(float,float);
void drawCircle(float, float , float , int);
void initialize(){
  hexagon_dx=hexagon_r*cos(30.0*M_PI/180.0);
  hexagon_dy=hexagon_r*sin(30.0*M_PI/180.0);
  hexagon_gx=2.0*hexagon_dx;
  hexagon_gy=2.0*hexagon_dx*sin(60.0*M_PI/180.0);
  // printf("%d  %d  %d  %d\n",hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy );
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
  glFlush();
}
/*    void Timer(int iUnused)
{
glutPostRedisplay();
glutTimerFunc(40, Timer, 0);
}*/
void draw_hexagon_grid(float x,float y,int ni,int nj)
{
  int i,j,xy; float x0,shiftP=2.0;
  x-=((float)(ni-1))*hexagon_gx*0.5; // just shift x,y to start position (i=0,j=0)
  x-=((float)(nj-1))*hexagon_dx*0.5;
  y-=((float)(nj-1))*hexagon_gy*0.5;







  for (x0=x,j=0;j<nj;j++,x0+=hexagon_dx+shiftP,x=x0+shiftP,y+=hexagon_gy+shiftP)
  for (i=0;i<ni;i++,x+=hexagon_gx+shiftP){
if(i!=16){


    draw_hexagon(x,y);
    drawCircle(x,y,4.0,20);
	}
}
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.0, 0.0);

  /*  glBegin(GL_POLYGON);
  glVertex2f(50,50);
  glVertex2f(100,50);
  glVertex2f(75,93);
  glVertex2f(35,93);
  glEnd();*/
  draw_hexagon_grid(250,250,10,10);
  glFlush();
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
  glBegin(GL_LINE_LOOP);
  for(int ii = 0; ii < num_segments; ii++)
  {
    float theta = 2.0f * 3.1415926f * (float)ii / (float)(num_segments);//get the current angle

    float x = r * cosf(theta);//calculate the x component
    float y = r * sinf(theta);//calculate the y component

    glVertex2f(x + cx, y + cy);//output vertex

  }
  glEnd();
}
int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  initialize();

  printf("%f  %f  %f  %f boo\n",hexagon_dx,hexagon_dy,hexagon_gx,hexagon_gy );
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Polygon");
  //glutTimerFunc(10, Timer, 0);
  glutDisplayFunc(display);
  glClearColor(1.0,1.0,1.0,1.0);
  gluOrtho2D(0.0,799.0,0.0,799.0);
  glutMainLoop();

  return 1;
}
