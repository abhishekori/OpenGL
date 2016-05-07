//#include <windows.h>
#include <string.h>
#include <GL/glut.h>
//#include <iostream.h>
//#include <fstream.h>

GLfloat UpwardsScrollVelocity = -10.0;
float view=20.0;

char quote[6][80];
int numberOfQuotes=0,i;

//*********************************************
//*  glutIdleFunc(timeTick);                  *
//*********************************************

void timeTick(void)
{
    if (UpwardsScrollVelocity< -600)
        view-=0.000011;
    if(view < 0) {view=20; UpwardsScrollVelocity = -10.0;}
    //  exit(0);
    UpwardsScrollVelocity -= 0.015;
  glutPostRedisplay();

}


//*********************************************
//* printToConsoleWindow()                *
//*********************************************

void printToConsoleWindow()
{
    int l,lenghOfQuote, i;

    for(  l=0;l<numberOfQuotes;l++)
    {
        lenghOfQuote = (int)strlen(quote[l]);

        for (i = 0; i < lenghOfQuote; i++)
        {
          //cout<<quote[l][i];
        }
          //out<<endl;
    }

}

//*********************************************
//* RenderToDisplay()                       *
//*********************************************

void RenderToDisplay()
{
    int l,lenghOfQuote, i;

    glTranslatef(0.0, -100, UpwardsScrollVelocity);
    glRotatef(-20, 1.0, 0.0, 0.0);
    glScalef(0.1, 0.1, 0.1);



    for(  l=0;l<numberOfQuotes;l++)
    {
        lenghOfQuote = (int)strlen(quote[l]);
        glPushMatrix();
        glTranslatef(-(lenghOfQuote*37), -(l*200), 0.0);
        for (i = 0; i < lenghOfQuote; i++)
        {
            glColor3f((UpwardsScrollVelocity/10)+300+(l*10),(UpwardsScrollVelocity/10)+300+(l*10),0.0);
            glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);
        }
        glPopMatrix();
    }

}
//*********************************************
//* glutDisplayFunc(myDisplayFunction);       *
//*********************************************

void myDisplayFunction(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  RenderToDisplay();
  glutSwapBuffers();
}
//*********************************************
//* glutReshapeFunc(reshape);               *
//*********************************************

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1.0, 1.0, 3200);
  glMatrixMode(GL_MODELVIEW);
}

//*********************************************
//* int main()                                *
//*********************************************


int main()
{
    strcpy(quote[0],"Luke, I am your father!.");
    strcpy(quote[1],"Obi-Wan has taught you well. ");
    strcpy(quote[2],"The force is strong with this one. ");
    strcpy(quote[3],"Alert all commands. Calculate every possible destination along their last known trajectory. ");
    strcpy(quote[4],"The force is with you, young Skywalker, but you are not a Jedi yet.");
    numberOfQuotes=5;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 400);
    glutCreateWindow("StarWars scroller");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glLineWidth(3);

    glutDisplayFunc(myDisplayFunction);
    glutReshapeFunc(reshape);
    glutIdleFunc(timeTick);
    glutMainLoop();

    return 0;
}
