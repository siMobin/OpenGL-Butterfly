
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
/// Libraries to Create Custom Graphics
#include "helper/const.h"
#include "helper/cgl.h"
#include "helper/draw.h"
#include "helper/butterfly.h"
#include "helper/tablefan.h"
#include "helper/star.h"

void disp();
void idle();
void displayStars(int);
void keyboard(unsigned char, int, int);
void passiveMouse(int, int);

/**
 * Main entry point of the application.
 *
 * Initializes GLUT, sets up the display parameters,
 * registers callback functions for the display, passive motion,
 * keyboard events, and idle loop.
 * Finally, enters the GLUT main loop.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return 0 if successful, non-zero otherwise.
 */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("CG Demo");
	glutDisplayFunc(disp);
	glutPassiveMotionFunc(passiveMouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	// Stars will be displayed with some delay
	glutTimerFunc(100, displayStars, 1);
	glutMainLoop();
}

/**
 * Main Display Function
 * @returns void
 */
void disp()
{
	/// Intialize Window Properties
	CGL_Init3D(-HALF_SCREEN_WIDTH, HALF_SCREEN_WIDTH, -HALF_SCREEN_HEIGHT, HALF_SCREEN_HEIGHT, 0, 10);

	// Draw Stars
	glPushMatrix();
	glTranslatef(-1, -1, 0.2);
	glScalef(5, 5, 1);
	drawStars();
	glPopMatrix();

	// Draw Table fan
	glDepthMask(GL_TRUE);
	glPushMatrix();
	// Set the Position & Rotation
	glRotatef(20, -1, 1, 0);
	glTranslatef(0, 0, 0.2);
	// Set the size of the Table fan
	glScalef(0.8, 0.8, 0.8);

	drawTableFan();
	glPopMatrix();

	// Draw Butterfly
	glDepthMask(GL_FALSE);
	glPushMatrix();
	// Set the Position, Rotation & Size of Butterfly
	glTranslatef(BUTTERFLY_TRANSLATE_X, BUTTERFLY_TRANSLATE_Y, -0.5);
	glScalef(0.25, 0.25, 0.5);
	glRotatef(45, 1, 0, 1);
	drawButterfly();
	glPopMatrix();

	// Draw Instruction (aka Breaking News)
	if (INSTRUCTION_POS > 4)
		INSTRUCTION_POS = -1;
	else
		INSTRUCTION_POS += 0.0005;
	STRING instruction;
	instruction.text = "Press R to show/hide stars";
	glPushMatrix();
	drawTextUsing(instruction, INSTRUCTION_POS, -0.95, -0.61);
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glFlush();
	glutSwapBuffers();
}

/**
 * @brief Updates the position of the butterfly based on the mouse position.
 *
 * This function is called whenever the mouse is moved. It updates the position of the butterfly based on the mouse position.
 *
 * @param x The x-coordinate of the mouse position.
 * @param y The y-coordinate of the mouse position.
 */

void passiveMouse(int x, int y)
{
	BUTTERFLY_TRANSLATE_Y = ((float)(HALF_SCREEN_HEIGHT - y) / (HALF_SCREEN_HEIGHT));
	BUTTERFLY_TRANSLATE_X = ((float)(x - HALF_SCREEN_WIDTH) / (HALF_SCREEN_WIDTH));
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'R' || key == 'r')
	{
		if (STARS_ENABLE == false)
		{
			STARS_ENABLE = true;
			STARS_DISPLAY_NOW = true;
		}
		else
			STARS_ENABLE = false;
	}
}

/**
 *
 * This function is called with a GLUT timer to display the stars after a certain delay.
 * The stars are displayed until the next call to this function.
 * If the user presses the 'R' key, this function is called to display/hide the stars.
 */
void displayStars(int val)
{
	glutTimerFunc(150, displayStars, 10);
	STARS_DISPLAY_NOW = true;
	glutPostRedisplay();
}

/**
 * This function is called whenever the main loop is idle. It posts a redisplay to the GLUT library to redraw the window.
 *
 */
void idle()
{
	glutPostRedisplay();
}
