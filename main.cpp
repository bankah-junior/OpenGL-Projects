/*
* NAME: BANKAH ANTHONY BEKOE
* INDEX NUMBER: SRI.41.008.040.21
* COURSE: CE273
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;
int frameNumber = 0;

/*
 * Draw a 32-sided regular polygon as an approximation for a circular disk.
 * (This is necessary since OpenGL has no commands for drawing ovals, circles,
 * or curves.)  The disk is centred at (0,0) with a radius given by the
 * parameter.
 */
void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

/*
 * Draw a wheel, centered at (0,0) and with radius 1. The wheel has 15 spokes
 * that rotate in a clockwise direction as the animation proceeds.
 */
void wheelCar_1() {        // Wheel 1
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);
	glRotatef(-frameNumber*20,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}
	glEnd();
}

void wheelCar_2() {        // Wheel 2
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);
	glRotatef(frameNumber*20,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}
	glEnd();
}

// Draw two cars each consisting of two wheels.
void car_1() {
    // INSERTING WHEELS FROM THE drawWheel method
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	wheelCar_1();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	wheelCar_1();
	glPopMatrix();
	glColor3f(0,0,1);

	// CAR BODY
	glBegin(GL_POLYGON);
	glVertex2f(-2.5f,0);
	glVertex2f(2.5f,0);
	glColor3f(1,1,1);
	glVertex2f(2.5f,0.8f);
	glVertex2f(2.6f,0.8f);
	glVertex2f(2.6f,1.5f);
	glVertex2f(2.5f,1.5f);
	glColor3f(0,0,1);
	glVertex2f(2.3f,2); // back Pole
	glVertex2f(2.3f,3);
	glVertex2f(2.5f,3);
	glVertex2f(2.5f,3.1f);
	glVertex2f(2.3f,3.1f);
	glVertex2f(2.3f,3);
	glVertex2f(2.2f,3);
	glVertex2f(2.2f,2);
	glVertex2f(2,2);
	glVertex2f(1,3.5f);
	glVertex2f(-0.5f,3.5f);
	glVertex2f(-1.5f,2);
	glVertex2f(-2.5f,2);
	glColor3f(1,1,1);
	glVertex2f(-2.5f,1.5f);
	glVertex2f(-2.6f,1.5f);
	glVertex2f(-2.6f,1);
	glVertex2f(-2.5f,1);
	glVertex2f(2.5f,0);
	glEnd();
}

void car_2() {
    // INSERTING WHEELS FROM THE drawWheel method
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	wheelCar_2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	wheelCar_2();
	glPopMatrix();
	glColor3f(1,0,0);

	// CAR BODY
	glBegin(GL_POLYGON);
	glVertex2f(-2.5f,0);
	glVertex2f(2.5f,0);
	glColor3f(1,1,1);
	glVertex2f(2.5f,1);
	glVertex2f(2.6f,1);
	glVertex2f(2.6f,1.5f);
	glVertex2f(2.5f,1.5f);
	glColor3f(1,0.0,0.0);
	glVertex2f(2.5f,2);
	glVertex2f(1.5f,2);
	glVertex2f(0.5f,3.5f);
	glVertex2f(-1.0f,3.5f);
	glVertex2f(-2,2);
	glVertex2f(-2.5f,2);
	glColor3f(1,1,1);
	glVertex2f(-2.5f,1.5f);
	glVertex2f(-2.6f,1.5f);
	glVertex2f(-2.6f,0.8f);
	glVertex2f(-2.5f,0.8f);
	glVertex2f(2.5f,0);
	glEnd();
}


/* Draw a sun with radius 0.3 centred at (0.5,0).  There are also 13 rays which extend outside from the sun */
void drawSun() {
	int i;
	glColor3f(0.9f,0.7f,0.07f);
	for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 360 / 13, 0, 0, 1 ); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(0.5, 0);  // Starting point of ray from the sun
		glVertex2f(0.85f, 0);      // Length of the ray
		glEnd();
	}
	drawDisk(0.3);  // Creating the circle of the sun with the drawDisk function and 0.3 as the radius
	glColor3f(0,0,0);
}

/*Draw a windmill, consisting of a pole and three vanes.  The pole extends from the
 * point (0,0) to (0,3).  The vanes radiate out from (0,3). */
void drawWindmill() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);  // Drawing the stand of the windmill
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0/46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0,0);    // Drawing the vanes of the windmill
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

// This function is called when the image needs to be redrawn. It draws the current frame of the animation.
void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();

	glColor3f(0.33f, 0.49f, 0.27f);     /* Draw three green triangles to form a ridge of hills in the background */
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(1.5f,1.65f);
	glVertex2f(5,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(3,2.1f);
	glVertex2f(7,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(4,1.5f);
	glVertex2f(15,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(6,1.2f);
	glVertex2f(20,-1);
	glEnd();

	glColor3f(0.4f, 0.4f, 0.5f);    /* Draw a bluish-gray rectangle to represent the road. */
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.4f);
	glVertex2f(7,-0.4f);
	glVertex2f(7,0.4f);
	glVertex2f(0,0.4f);
	glEnd();

	glLineWidth(6);  // Set the line width to be 6 pixels.
	glColor3f(1,1,1);   /* Draw a white line to represent the stripe down the middle of the road. */
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(7,0);
	glEnd();
	glLineWidth(1);  // Reset the line width to be 1 pixel.

	// Draw the sun.
	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();

	// Draw three windmills.
	glPushMatrix();
	glTranslated(0.75,1,0);
	glScaled(0.6,0.6,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.2,1.6,0);
	glScaled(0.4,0.4,1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.7,0.8,0);
	glScaled(0.7,0.7,1);
	drawWindmill();
	glPopMatrix();

	// Draw the two cars.
	glPushMatrix();
	glTranslatef(10 + 13*(-frameNumber % 300) / 300.0,0.5,0);   // Moving from the positive to the negative side of the axis
	glScaled(0.3,0.3,1);
	car_1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3 + 13*(frameNumber % 300) / 300.0, 0, 0);   // Moving from the negative to the positive side of the axis
	glScaled(0.3,0.3,1);
	car_2();
	glPopMatrix();

	glutSwapBuffers();

}  // end display

// This function is set as the glutTimerFunc to drive the animation
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

// This method is called from main() to initialize OpenGL.
void init() {
	glClearColor(0.5f, 0.5f, 1, 1);
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Road with windmills and moving cars in opposite direction");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);

    glutMainLoop();
    return 0;
}

