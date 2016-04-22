#include<GL/glut.h>
#define DEG2RAD 3.14159/180.0
#include<math.h>

int i;
float rad;
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


void DrawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
{
float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

float tangetial_factor = tanf(theta);

float radial_factor = cosf(theta);


float x = r * cosf(start_angle);//we now start at the start angle
float y = r * sinf(start_angle);

glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
for(int ii = 0; ii < num_segments; ii++)
{
glVertex2f(x + cx, y + cy);

float tx = -y;
float ty = x;

x += tx * tangetial_factor;
y += ty * tangetial_factor;

x *= radial_factor;
y *= radial_factor;
}

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
void draw_single_cell(int x,int y){
	draw_hexagon(x,y);
	drawCircle(x,y,4.0,20);

}
void display(void)
{
	//clear window
	glClear(GL_COLOR_BUFFER_BIT);
	//draw unit square polygon
	  glColor3f(0.5, 0.0, 0.0);
	  draw_hexagon_grid(250,300,7,6);
		draw_single_cell(430,300);
		draw_single_cell(420,250);
		draw_single_cell(380,240);
		draw_single_cell(400,200);
		draw_single_cell(470,240);
		draw_single_cell(450,200);

	glColor3f(1,0,0);
 glBegin(GL_LINES);
DrawArc(165,300,250,200,2,1000000);

glEnd();
 glBegin(GL_LINE_LOOP);
for(i=0;i<360;i++){
	rad=i*DEG2RAD;
	glVertex2f(450+cos(rad)*(20),
							510+sin(rad)*(50));
}
glEnd();
	glFlush();
}

void init()
{
	//set colorr to black
	glClearColor(1,1,1,1);
	//set fill coor to white

	glColor3f(0,0,0);
	//set up standards  orthogonal
	//view with clipping
	//box as cube of side 2 centered at origin
	//this is default view and these statements could
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	  initialize();
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
  return 0;
}
