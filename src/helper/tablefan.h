

float TABLEFAN_SPEED = 0.8;
float TABLEFAN_SPEED_STEP = 0;
float TABLEFAN_ROTATION_STEP = 0;
bool TABLEFAN_STATE = false;

void drawTableFan();
void drawTableFanBase();
void drawTableFanBase2();
void drawTableFanBlade();
void drawtablefanBladeAssembly();

/**
 * @brief Draws the table fan base and the rotating blades.
 *
 * Draws the table fan base and the rotating blades. The blades are rotated
 * based on the TABLEFAN_ROTATION_STEP variable. If the rotation step is
 * greater than 120, the rotation step is decreased until it reaches -120.
 * If the rotation step is less than -120, the rotation step is increased until
 * it reaches 120.
 *
 * @see TABLEFAN_ROTATION_STEP
 */
void drawTableFan()
{
	drawTableFanBase();

	glPushMatrix();
	if (TABLEFAN_ROTATION_STEP > 120)
		TABLEFAN_STATE = true;
	else if (TABLEFAN_ROTATION_STEP < -120)
		TABLEFAN_STATE = false;
	if (!TABLEFAN_STATE)
	{
		TABLEFAN_ROTATION_STEP += 0.03;
		glRotatef(TABLEFAN_ROTATION_STEP, 0, 1, 0);
	}
	else
	{
		TABLEFAN_ROTATION_STEP -= 0.03;
		glRotatef(TABLEFAN_ROTATION_STEP, 0, 1, 0);
	}

	drawTableFanBase2();
	glPopMatrix();
}

/**
 * @brief Draws the table fan blade.
 *
 * Draws the table fan blade using a cubic curve defined by four points.
 * The blade is colored blue and is drawn using the GL_POLYGON and
 * GL_QUADS primitives.
 *
 * @see drawCubicCurveUsing
 * @see drawShadedRectangleAt
 * @see CURVE
 * @see fanBlade
 */
void drawTableFanBlade()
{
	CURVE curve;
	// Top Wing
	curve.p1.x = 0.2;
	curve.p1.y = 0.5;
	curve.p1.z = -0.3;
	curve.p2.x = 0.2;
	curve.p2.y = 1;
	curve.p2.z = -0.3;
	curve.p3.x = -0.2;
	curve.p3.y = 1;
	curve.p3.z = 0.3;
	curve.p4.x = -0.2;
	curve.p4.y = 0.5;
	curve.p4.z = 0.3;
	glColor3f(0.1, 0.6, 1);
	drawCubicCurveUsing(curve, GL_POLYGON);
	drawShadedRectangleAt(fanBlade[0], fanBlade[1], fanBlade[2], fanBlade[3], GL_QUADS, 0, 1, 0.4);
}

/**
 * @brief Draws the table fan base.
 *
 * Draws the table fan base using a cube and a cuboid defined by eight points.
 * The cube is colored blue and is drawn using the GL_QUADS primitive.
 * The cuboid is colored brown and is drawn using the GL_POLYGONS primitive.
 *
 * @see CUBE
 * @see drawCuboidAtPos
 * @see drawCuboidAt
 * @see fanBase
 */
void drawTableFanBase()
{
	CUBE cube;
	cube.posX = -0.2;
	cube.posY = -0.3;
	cube.posZ = -0.3;
	cube.width = 0.4;
	cube.height = 0.1;
	cube.breadth = 0.5;
	drawCuboidAtPos(cube, GL_QUADS);

	drawCuboidAt(fanBase[0], fanBase[1], fanBase[2], fanBase[3], fanBase[4], fanBase[5], fanBase[6], fanBase[7], GL_POLYGON);
}

/**
 * @brief Draws the table fan base version 2.
 *
 * Draws the table fan base using 4 cylinders, 1 for the base, 1 for the
 * connector, 1 for the connector head and 1 for the fan blade holder.
 * The base is colored brown, the connector is colored grey, the connector head
 * is colored light grey and the fan blade holder is colored blue.
 * The fan blade is colored blue and is drawn using the GL_POLYGONS and
 * GL_QUADS primitives. The fan blade holder is colored blue and is drawn
 * using the GL_QUADS primitive.
 *
 * @see drawShadedCylinderUsing
 * @see drawShadedRectangleAt
 * @see drawtablefanBladeAssembly
 */
void drawTableFanBase2()
{

	glColor3f(1.0, 0.6, 0.4);
	glPushMatrix();
	glTranslatef(0, 0.5, -0.15);

	CYLINDER cylinder;
	cylinder.baseRadius = 0.15;
	cylinder.topRadius = 0.1;
	cylinder.height = 0.4;
	cylinder.slices = 32;
	cylinder.stacks = 32;
	drawShadedCylinderUsing(cylinder, true, 1, 0.6, 0.4);
	// draw connector
	cylinder.baseRadius = 0.02;
	cylinder.topRadius = 0.02;
	cylinder.height = 0.1;
	cylinder.slices = 32;
	cylinder.stacks = 32;
	glPushMatrix();
	glTranslatef(0, 0, -0.10);
	drawShadedCylinderUsing(cylinder, true, 0.8, 1, 0.6);
	glPopMatrix();

	// draw connectorHead
	cylinder.baseRadius = 0.08;
	cylinder.topRadius = 0.08;
	cylinder.height = 0.05;
	cylinder.slices = 32;
	cylinder.stacks = 32;
	glPushMatrix();
	glTranslatef(0, 0, -0.11);
	drawShadedCylinderUsing(cylinder, true, 1, 1, 0.4);
	glPopMatrix();

	// draw connectorHead
	cylinder.baseRadius = 0.07;
	cylinder.topRadius = 0.07;
	cylinder.height = 0.02;
	cylinder.slices = 32;
	cylinder.stacks = 32;
	glPushMatrix();
	glTranslatef(0, 0, -0.115);
	drawShadedCylinderUsing(cylinder, true, 1, 0.5, 0.4);
	glPopMatrix();
	/*
	// draw connectorHead
	cylinder.baseRadius = 0.07;
	cylinder.topRadius = 0.07;
	cylinder.height = 0.02;
	cylinder.slices = 32;
	cylinder.stacks = 32;
	glPushMatrix();
	glTranslatef(0, 0, -0.195);
	drawShadedCylinderUsing(cylinder, true, 1, 0.7, 0.3);
	glPopMatrix();*/

	glColor3f(0.1, 0.6, 1);
	glScalef(1, 1, 0.2);
	glTranslatef(0, 0, -0.45);
	glutWireSphere(0.5, 32, 10);
	glPushMatrix();
	glRotatef(TABLEFAN_SPEED_STEP, 0, 0, 1);
	TABLEFAN_SPEED_STEP += TABLEFAN_SPEED;
	drawtablefanBladeAssembly();
	glPopMatrix();
	glPopMatrix();
}

/**
 * @brief Draws a table fan's blade assembly.
 *
 * Draws a table fan's blade assembly by drawing three blades
 * equally spaced around the z-axis.
 *
 * The blades are drawn using the drawTableFanBlade() function and
 * are scaled to 0.6 times their original size.
 * The blades are then rotated by 120 and 240 degrees around the
 * z-axis to create the assembly.
 */
void drawtablefanBladeAssembly()
{
	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);
	drawTableFanBlade();
	glPushMatrix();
	glRotatef(120, 0, 0, 1);
	drawTableFanBlade();
	glPopMatrix();
	glPushMatrix();
	glRotatef(240, 0, 0, 1);
	drawTableFanBlade();
	glPopMatrix();
	glPopMatrix();
}
