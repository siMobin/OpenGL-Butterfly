

#include <math.h>
#include <string.h>

GLUquadricObj *IDquadric;

/**
 * Draws the rectangle at given 4 vertices (X,Y,Z)
 *
 * @param v0 The v0.
 * @param v1 The v1.
 * @param v2 The v2.
 * @param v3 The v3.
 * @param fillType Type of the fill.
 */
void drawRectangleAt(float *v0, float *v1, float *v2, float *v3, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(v0[0], v0[1], v0[2]);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();
}

/**
 * Draws a shaded rectangle at given 4 vertices (X,Y,Z)
 *
 * @param v0 The v0.
 * @param v1 The v1.
 * @param v2 The v2.
 * @param v3 The v3.
 * @param fillType Type of the fill.
 * @param colRed The red color component.
 * @param colGreen The green color component.
 * @param colBlue The blue color component.
 */
void drawShadedRectangleAt(float *v0, float *v1, float *v2, float *v3, GLfloat fillType, float colRed, float colGreen, float colBlue)
{
	glColor3f(colRed, colGreen - 0.3, colBlue - 0.5);
	glBegin(fillType);
	glVertex3f(v0[0], v0[1], v0[2]);
	glColor3f(colRed, colGreen, colBlue);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();
}

/**
 * Draws a rectangle at given 4 vertices (X,Y,Z)
 * @param p0X X coordinate of the first vertex.
 * @param p0Y Y coordinate of the first vertex.
 * @param p0Z Z coordinate of the first vertex.
 * @param p1X X coordinate of the second vertex.
 * @param p1Y Y coordinate of the second vertex.
 * @param p1Z Z coordinate of the second vertex.
 * @param p2X X coordinate of the third vertex.
 * @param p2Y Y coordinate of the third vertex.
 * @param p2Z Z coordinate of the third vertex.
 * @param p3X X coordinate of the fourth vertex.
 * @param p3Y Y coordinate of the fourth vertex.
 * @param p3Z Z coordinate of the fourth vertex.
 * @param fillType Type of the fill.
 */
void drawRectangleAtV(float p0X, float p0Y, float p0Z, float p1X, float p1Y, float p1Z, float p2X, float p2Y, float p2Z, float p3X, float p3Y, float p3Z, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(p0X, p0Y, p0Z);
	glVertex3f(p1X, p1Y, p1Z);
	glVertex3f(p2X, p2Y, p2Z);
	glVertex3f(p3X, p3Y, p3Z);
	glEnd();
}

/**
 * Draws the rectangle at given position (posX, posY, posZ) and given size (width, height)
 *
 * @param rect The rectangle to draw.
 * @param fillType Type of the fill.
 */

void drawRectangleAtPos(RECTANGLE rect, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(rect.posX, rect.posY, rect.posZ);
	glVertex3f(rect.posX + rect.width, rect.posY, rect.posZ);
	glVertex3f(rect.posX + rect.width, rect.posY + rect.height, rect.posZ);
	glVertex3f(rect.posX, rect.posY + rect.height, rect.posZ);
	glEnd();
}

/**
 * Draws a cuboid given its vertices.
 *
 * The cuboid is drawn in a cycle of blue, green, and purple, with each face of the cuboid having a different color.
 *
 * @param v0 The first vertex (bottom-left-front).
 * @param v1 The second vertex (bottom-left-back).
 * @param v2 The third vertex (bottom-right-back).
 * @param v3 The fourth vertex (bottom-right-front).
 * @param v4 The fifth vertex (top-left-front).
 * @param v5 The sixth vertex (top-left-back).
 * @param v6 The seventh vertex (top-right-back).
 * @param v7 The eighth vertex (top-right-front).
 * @param fillType The type of fill to use when drawing the cuboid.
 */
void drawCuboidAt(float *v0, float *v1, float *v2, float *v3, float *v4, float *v5, float *v6, float *v7, GLfloat fillType)
{
	drawRectangleAt(v0, v3, v2, v1, fillType);
	glColor3f(1.0, 0.5, 0.6);
	drawRectangleAt(v3, v7, v6, v2, fillType);
	glColor3f(1.0, 0.5, 1);
	drawRectangleAt(v7, v4, v5, v6, fillType);
	glColor3f(0, 0.5, 0.8);
	drawRectangleAt(v4, v0, v1, v5, fillType);
	glColor3f(1.0, 0.5, 0.9);
	drawRectangleAt(v1, v2, v6, v5, fillType);
	glColor3f(0, 0.5, 0.4);
	drawRectangleAt(v0, v3, v7, v4, fillType);
}

/**
 * Draws a cuboid given its position and dimensions.
 *
 * The cuboid is drawn with different colors on each face, with
 * the front face being yellow, the top face being green, the
 * right face being purple, the bottom face being blue, the
 * left face being red, and the back face being orange.
 *
 * @param cube The cuboid to draw, with its position (posX, posY, posZ)
 * and its dimensions (width, height, breadth).
 * @param fillType The type of fill to use when drawing the cuboid.
 */
void drawCuboidAtPos(CUBE cube, GLfloat fillType)
{
	glColor3f(1.0, 0.7, 0.1);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ, fillType);
	glColor3f(1.0, 0.5, 0.6);
	drawRectangleAtV(cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, fillType);
	glColor3f(1.0, 0, 1);
	drawRectangleAtV(cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
	glColor3f(0, 0.5, 0.1);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
	glColor3f(1.0, 0.5, 0.2);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY, cube.posZ + cube.breadth, fillType);
	glColor3f(0, 0.5, 0.4);
	drawRectangleAtV(cube.posX, cube.posY + cube.height, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
}

/**
 * Draws a circle using the given CIRCLE object and fill type.
 *
 * @param circle The circle to draw, with its position (transX, transY, transZ),
 * and its radius.
 * @param fillType The type of fill to use when drawing the circle.
 */
void drawCircleUsing(CIRCLE circle, GLfloat fillType)
{
	glBegin(fillType);
	for (int i = 0; i < 180; i++)
	{
		circle.posX = circle.radius * cos((float)i);
		circle.posY = circle.radius * sin((float)i);
		glVertex3f(circle.posX + circle.transX, circle.posY + circle.transY, circle.transZ);

		circle.posX = circle.radius * cos(i + 0.1);
		circle.posY = circle.radius * sin(i + 0.1);
		glVertex3f(circle.posX + circle.transX, circle.posY + circle.transY, circle.transZ);
	}
	glEnd();
}

/**
 * Draws a cylinder using the given CYLINDER object and fill type.
 *
 * @param cylinder The cylinder to draw, with its base radius, top radius, height, slices, and stacks.
 * @param fillCaps Whether to fill the caps of the cylinder with a disk.
 */
void drawCylinderUsing(CYLINDER cylinder, bool fillCaps)
{
	CIRCLE circle;
	IDquadric = gluNewQuadric();			  // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(IDquadric, GLU_SMOOTH); // Create Smooth Normals ( NEW )
	gluQuadricTexture(IDquadric, GL_TRUE);	  // Create Texture Coords ( NEW )

	gluCylinder(IDquadric, cylinder.baseRadius, cylinder.topRadius, cylinder.height, cylinder.slices, cylinder.stacks);
	if (fillCaps)
	{
		circle.radius = cylinder.baseRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = 0;
		glColor3f(1.0, 0.6, 1);
		drawCircleUsing(circle, GL_POLYGON);
		circle.radius = cylinder.topRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = cylinder.height;
		glColor3f(1.0, 0.6, 1);
		drawCircleUsing(circle, GL_POLYGON);
	}
}

void drawShadedCylinderUsing(CYLINDER cylinder, bool fillCaps, float colRed, float colGreen, float colBlue)
{
	CIRCLE circle;
	IDquadric = gluNewQuadric();			  // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(IDquadric, GLU_SMOOTH); // Create Smooth Normals ( NEW )
	gluQuadricTexture(IDquadric, GL_TRUE);	  // Create Texture Coords ( NEW )
	glColor3f(colRed, colGreen, colBlue);
	gluCylinder(IDquadric, cylinder.baseRadius, cylinder.topRadius, cylinder.height, cylinder.slices, cylinder.stacks);
	if (fillCaps)
	{
		circle.radius = cylinder.baseRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = 0;
		glColor3f(colRed - 0.05, colGreen - 0.15, colBlue - 0.15);
		drawCircleUsing(circle, GL_POLYGON);
		circle.radius = cylinder.topRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = cylinder.height;
		glColor3f(colRed - 0.05, colGreen - 0.15, colBlue - 0.15);
		drawCircleUsing(circle, GL_POLYGON);
	}
}

/**
 * Draws a cubic Bezier curve based on the given points.
 * @param curve The points which define the cubic Bezier curve.
 * @param fillType The type of fill to use when drawing the curve, e.g. GL_POLYGON
 */
void drawCubicCurveUsing(CURVE curve, GLfloat fillType)
{
	glBegin(fillType);
	for (float t = 0; t <= 1; t += 0.01)
	{
		float x = (1 - t) * (1 - t) * (1 - t) * curve.p1.x + 3 * (1 - t) * (1 - t) * t * curve.p2.x + 2 * (1 - t) * t * t * curve.p3.x + t * t * t * curve.p4.x;
		float y = (1 - t) * (1 - t) * (1 - t) * curve.p1.y + 3 * (1 - t) * (1 - t) * t * curve.p2.y + 2 * (1 - t) * t * t * curve.p3.y + t * t * t * curve.p4.y;
		float z = (1 - t) * (1 - t) * (1 - t) * curve.p1.z + 3 * (1 - t) * (1 - t) * t * curve.p2.z + 2 * (1 - t) * t * t * curve.p3.z + t * t * t * curve.p4.z;
		glVertex3f(x, y, z);
	}
	glEnd();
}

/**
 * Draws a quadratic Bezier curve based on the given points.
 * @param curve The points which define the quadratic Bezier curve.
 * @param fillType The type of fill to use when drawing the curve, e.g. GL_POLYGON
 */
void drawQuadraticCurveUsing(CURVE curve, GLfloat fillType)
{
	glBegin(fillType);
	for (float t = 0; t <= 1; t += 0.05)
	{
		float x = (1 - t) * (1 - t) * curve.p1.x + 2 * (1 - t) * t * curve.p2.x + t * t * curve.p3.x;
		float y = (1 - t) * (1 - t) * curve.p1.y + 2 * (1 - t) * t * curve.p2.y + t * t * curve.p3.y;
		float z = (1 - t) * (1 - t) * curve.p1.z + 2 * (1 - t) * t * curve.p2.z + t * t * curve.p3.z;
		glVertex3f(x, y, z);
	}
	glEnd();
}

/**
 * Draws the given text string at the specified position (x, y, z) using the GLUT_BITMAP_TIMES_ROMAN_24 font.
 *
 * @param s The text string to draw.
 * @param x The x-coordinate of the position where the text should be drawn.
 * @param y The y-coordinate of the position where the text should be drawn.
 * @param z The z-coordinate of the position where the text should be drawn.
 */
void drawTextUsing(STRING s, float x, float y, float z)
{
	glRasterPos3f(x, y, z);
	for (unsigned int i = 0; i < strlen(s.text); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.text[i]);
	}
}