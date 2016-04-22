#include <GL/glew.h> // Include the GLEW header file
#include <GL/glut.h> // Include the GLUT header file

bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)

bool movingUp = false; // Whether or not we are moving up or down
float yLocation = 0.0f; // Keep track of our position on the y axis.

float yRotationAngle = 0.0f; // The angle of rotation for our object



void display (void) {

glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear the background of our window to red
glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

glTranslatef(0.0f, 0.0f, -5.0f); // Push eveything 5 units back into the scene, otherwise we won't see the primitive

glTranslatef(0.0f, yLocation, 0.0f); // Translate our object along the y axis

//glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f); // Rotate our object around the y axis

glutWireCube(2.0f); // Render the primitive

glFlush(); // Flush the OpenGL buffers to the window

if (movingUp) // If we are moving up
yLocation -= 0.005f; // Move up along our yLocation
else  // Otherwise
yLocation += 0.005f; // Move down along our yLocation

if (yLocation < -3.0f) // If we have gone up too far
movingUp = false; // Reverse our direction so we are moving down
else if (yLocation > 3.0f) // Else if we have gone down too far
movingUp = true; // Reverse our direction so we are moving up

yRotationAngle += 0.005f; // Increment our rotation value

if (yRotationAngle > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
yRotationAngle -= 360.0f; // Subtract 360 degrees off of our rotation
}

void reshape (int width, int height) {
glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)

gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes

glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}



int main (int argc, char **argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
glutInitWindowSize (1000, 1000); // Set the width and height of the window
glutInitWindowPosition (100, 100); // Set the position of the window
glutCreateWindow ("Your first OpenGL Window"); // Set the title for the window

glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

glutIdleFunc(display); // Tell GLUT to use the method "display" as our idle method as well

glutReshapeFunc(); // Tell GLUT to use the method "reshape" for reshaping


glutMainLoop(); // Enter GLUT's main loop
}
