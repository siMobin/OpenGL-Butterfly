#include <GL/glut.h>

float BUTTERFLY_WING_INCREMENT = 0.2;
float BUTTERFLY_WING_MAX_ANGLE = 70;
float BUTTERFLY_WING_MIN_ANGLE = 0;

//
float BUTTERFLY_WING_ANGLE = 0;
bool BUTTERFLY_WING_STATE = false;

float BUTTERFLY_TRANSLATE_X = 0;
float BUTTERFLY_TRANSLATE_Y = 0;

float BUTTERFLY_PREVIOUS_X = 0;
float BUTTERFLY_PREVIOUS_Y = 0;

float BUTTERFLY_POSDIFF_X;
float BUTTERFLY_POSDIFF_Y;

void drawButterfly();
void drawButterflyWing();
void drawBufferflyWingPart();
void drawButterflyWingCircle(float, float, float);
void drawButterflyBody();
void drawButterflyAntena();
void followMousePointer(float, float);

/**
 * @brief Draws a butterfly with flapping wings
 * @details This function draws a butterfly with two flapping wings. The
 * angle of the wings can be controlled by the global variables
 * BUTTERFLY_WING_ANGLE, BUTTERFLY_WING_MAX_ANGLE, and
 * BUTTERFLY_WING_MIN_ANGLE. The wings will flap up and down
 * based on the current angle and the maximum and minimum angles allowed.
 * The butterfly body is also drawn in the middle, with a gray color.
 */
void drawButterfly()
{

	// Draw butterfly Antena
	glPushMatrix();
	glColor3f(0.1, 0.1, 0);
	drawButterflyAntena();
	glRotatef(180, 0, 1, 0);
	drawButterflyAntena();
	glPopMatrix();

	// Change the state of wing based on BUTTERFLY_WING_STATE & Maximum Angle allowed
	if (BUTTERFLY_WING_ANGLE > BUTTERFLY_WING_MAX_ANGLE)
		BUTTERFLY_WING_STATE = true;
	else if (BUTTERFLY_WING_ANGLE < BUTTERFLY_WING_MIN_ANGLE)
		BUTTERFLY_WING_STATE = false;
	if (BUTTERFLY_WING_STATE)
		BUTTERFLY_WING_ANGLE -= BUTTERFLY_WING_INCREMENT;
	else
		BUTTERFLY_WING_ANGLE += BUTTERFLY_WING_INCREMENT;

	// Left wing
	glPushMatrix();
	glRotatef(BUTTERFLY_WING_ANGLE, 0, 1, 0);
	drawButterflyWing();
	glPopMatrix();

	// Right wing
	glPushMatrix();
	glRotatef(180 - BUTTERFLY_WING_ANGLE, 0, 1, 0);
	drawButterflyWing();
	glPopMatrix();

	// Draw butterfly Body
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
	drawButterflyBody();
	glRotatef(180, 0, 1, 0);
	drawButterflyBody();
	glPopMatrix();
}

/**
 * @brief Draws a butterfly's antenna.
 * @details Draws a butterfly's antenna using a quadratic Bezier curve.
 * The curve is defined by four points: (0.01, 0.3, 0), (0.02, 0.5, 0), (0.4, 0.8, 0), and (0, -0.1, 0).
 */
void drawButterflyAntena()
{
	float butterflyDepth = 0;
	CURVE curve;
	curve.p1.x = 0.01;
	curve.p1.y = 0.3;
	curve.p1.z = butterflyDepth;
	curve.p2.x = 0.02;
	curve.p2.y = 0.5;
	curve.p2.z = butterflyDepth;
	curve.p3.x = 0.4;
	curve.p3.y = 0.8;
	curve.p3.z = butterflyDepth;
	curve.p4.x = 0;
	curve.p4.y = -0.1;
	curve.p4.z = butterflyDepth;
	drawQuadraticCurveUsing(curve, GL_POLYGON);
}

/**
 * @brief Draws a butterfly's body
 * @details Draws a butterfly's body using two cubic Bezier curves.
 * The first curve is defined by four points: (0, 0.3, 0), (0.125, 0.3, 0), (0.0725, -0.15, 0), and (0, -0.1, 0).
 * The second curve is defined by four points: (0, 0.2, 0), (0.1, -0.3, 0), (0.025, -0.55, 0), and (0, -0.5, 0).
 */
void drawButterflyBody()
{
	float butterflyDepth = 0;
	CURVE curve;
	curve.p1.x = 0;
	curve.p1.y = 0.3;
	curve.p1.z = butterflyDepth;
	curve.p2.x = 0.125;
	curve.p2.y = 0.3;
	curve.p2.z = butterflyDepth;
	curve.p3.x = 0.0725;
	curve.p3.y = -0.15;
	curve.p3.z = butterflyDepth;
	curve.p4.x = 0;
	curve.p4.y = -0.1;
	curve.p4.z = butterflyDepth;
	drawCubicCurveUsing(curve, GL_POLYGON);
	curve.p1.x = 0;
	curve.p1.y = 0.2;
	curve.p1.z = butterflyDepth;
	curve.p2.x = 0.1;
	curve.p2.y = -0.3;
	curve.p2.z = butterflyDepth;
	curve.p3.x = 0.025;
	curve.p3.y = -0.55;
	curve.p3.z = butterflyDepth;
	curve.p4.x = 0;
	curve.p4.y = -0.5;
	curve.p4.z = butterflyDepth;
	drawCubicCurveUsing(curve, GL_POLYGON);
}

/**
 * @brief Draws a circle for a butterfly's wing.
 * @details Draws a circle for a butterfly's wing using the given radius, translation x, and translation y.
 * @param radius The radius of the circle.
 * @param tranX The translation on the x-axis for the circle.
 * @param transY The translation on the y-axis for the circle.
 */
void drawButterflyWingCircle(float radius, float tranX, float transY)
{
	CIRCLE c;
	c.radius = radius;
	c.transX = tranX;
	c.transY = transY;
	c.transZ = 0;
	drawCircleUsing(c, GL_POLYGON);
}

/**
 * @brief Draws a butterfly's wing.
 * @details Draws a butterfly's wing using the drawButterflyWingCircle function.
 */
void drawButterflyWing()
{
	glPushMatrix();
	glColor3f(0, 0, 0.2);
	drawBufferflyWingPart();
	glColor3f(1, 1, 0.5);
	glScalef(0.9, 0.93, 0.9);
	drawBufferflyWingPart();
	glColor3f(0, 1, 0.5);
	drawButterflyWingCircle(0.13, 0.48, 0.28);
	drawButterflyWingCircle(0.14, 0.25, -0.4);
	glPopMatrix();
}

/**
 * @brief Draws a butterfly's wing.
 * @details Draws a butterfly's wing using two cubic Bezier curves.
 * The first curve is the top wing, defined by four points: (0, 0.2, 0), (0.8, 0.9, 0), (1.5, 0.0, 0), and (0, -0.4, 0).
 * The second curve is the bottom wing, defined by four points: (0, 0, 0), (1.0, -0.4, 0), (0.2, -1.4, 0), and (0, -0.4, 0).
 */
void drawBufferflyWingPart()
{
	float butterflyDepth = 0;
	CURVE curve;
	// Top Wing
	curve.p1.x = 0;
	curve.p1.y = 0.2;
	curve.p1.z = butterflyDepth;
	curve.p2.x = 0.8;
	curve.p2.y = 0.9;
	curve.p2.z = butterflyDepth;
	curve.p3.x = 1.5;
	curve.p3.y = 0.0;
	curve.p3.z = butterflyDepth;
	curve.p4.x = 0;
	curve.p4.y = -0.4;
	curve.p4.z = butterflyDepth;
	drawCubicCurveUsing(curve, GL_POLYGON);
	// Bottom Wing
	curve.p1.x = 0;
	curve.p1.y = 0;
	curve.p1.z = butterflyDepth;
	curve.p2.x = 1.0;
	curve.p2.y = -0.4;
	curve.p2.z = butterflyDepth;
	curve.p3.x = 0.2;
	curve.p3.y = -1.4;
	curve.p3.z = butterflyDepth;
	curve.p4.x = 0;
	curve.p4.y = -0.4;
	curve.p4.z = butterflyDepth;
	drawCubicCurveUsing(curve, GL_POLYGON);
}
