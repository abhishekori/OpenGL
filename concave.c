

#include <GL/gl.h>
#include <GL/glu.h>


int Lists[65536]; // list's number
int Listscount=0;

int Load_GL_objects (QString & filename1,QString &filename2)
{
QFile f(filename1);
QFile o(filename2);

float (*vertex)[2]; // array of points
int (*triangl)[3]; // array of index for triangles;
int *object; // array start pointov triangles;
int vertexcount=0;
int trianglcount=0;
int objectcount=0;

int r,i,j,k;
const char *str;
char temp = 0;


// Read objects from file.

o.open(IO_ReadOnly);
o.readBlock((char *)&vertexcount, sizeof (int));
o.readBlock((char *)&trianglcount, sizeof (int));
o.readBlock((char *)&objectcount, sizeof (int));

o.readBlock((char *)vertex, (sizeof (float))*vertexcount*2);
o.readBlock((char *)triangl, (sizeof (int))*trianglcount*3);
o.readBlock((char *)object, (sizeof (int))*objectcount*2);

o.close();
int h=0;
for (i=0;i<objectcount-1;i++)
{
Lists[Listscount++]=glGenLists(1);h++;
glNewList(Lists[Listscount-1], GL_COMPILE);
glBegin (GL_TRIANGLES);
for(j=object[i];j<object[i+1];j++)
for(k=0;k<3;k++)
{
int vi=triangl[j][k];
glVertex2f (vertex[vi][0],vertex[vi][1]);
}
glEnd ();
glEndList();
}

Lists[Listscount++]=glGenLists(1);
glNewList(Lists[Listscount-1], GL_COMPILE);h++;
glBegin (GL_TRIANGLES);

for(j=object[objectcount-1];j<trianglcount;j++)
for(k=0;k<3;k++)
{
int vi=triangl[j][k];
glVertex2f (vertex[vi][0],vertex[vi][1]);
}
glEnd ();
glEndList();

delete []triangl;
delete []vertex;
delete []object;
return h;


}

void CALLBACK resize(int width,int height)
{
if (width<=height) height=width;
else width=height;
glViewport(0,0,width,height);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
glOrtho(-5,5, -5,5, 2,12);
gluLookAt( 0,0,5, 0,0,0, 0,1,0 );
glMatrixMode( GL_MODELVIEW );
}


void CALLBACK display(void)
{

glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

int s,f;
QString sr;
s=GetTickCount();
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glEnable(GL_POLYGON_SMOOTH);
glColor3f(1,1,1);
glCallLists(1,GL_INT,&(Lists[0]));


glColor3f(0.7,0.7,0.7);
glCallLists(24,GL_INT,&(Lists[1]));

glColor3f(0,0,0);
glCallLists(32,GL_INT,&(Lists[25]));

glColor3f(0,0,0);
glCallLists(47,GL_INT,&(Lists[57]));


glDisable(GL_POLYGON_SMOOTH);
auxSwapBuffers();
f=GetTickCount();
sr.setNum(f-s);
::MessageBox(0,"Time",sr.ascii(),MB_OK);


}

int main( int argc, char **argv )
{

// init OpenGL
auxInitPosition(1, 1, 300, 300);
auxInitDisplayMode( AUX_RGB | AUX_DEPTH | AUX_DOUBLE );
auxInitWindow( "OpenGL Window" );
glEnable(GL_ALPHA_TEST);
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_BLEND);
glEnable(GL_FOG);
glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;

Load_GL_objects(QString("cell_rect.txt"),QString(" cell_rect1.txt"));
Load_GL_objects(QString("cell_fills.txt"),QString( "cell_fills1.txt"));
Load_GL_objects(QString("cell_outlines.txt"),QStri ng("cell_outlines1.txt"));
Load_GL_objects(QString("cell_names.txt"),QString( "cell_names1.txt"));

auxReshapeFunc(resize);
auxMainLoop(display);
auxQuit();

glDeleteLists(Lists[0],Listscount);


return 0;
}
