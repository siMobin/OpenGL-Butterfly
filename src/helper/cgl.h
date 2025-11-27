#include <GL/glut.h>

/**
 * Initializes the OpenGL context for 2D rendering.
 *
 * Sets the clear color to white, the drawing color to black, and clears the color buffer.
 * Sets up an orthogonal projection matrix with the given parameters.
 * Sets the modelview matrix to the identity matrix.
 *
 * @param x1 The minimum x value of the orthogonal projection.
 * @param x2 The maximum x value of the orthogonal projection.
 * @param x3 The minimum y value of the orthogonal projection.
 * @param x4 The maximum y value of the orthogonal projection.
 * @see CGL_Init3D
 */
void CGL_Init2D(float x1, float x2, float x3, float x4)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(x1, x2, x3, x4);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/**
 * Initializes the OpenGL context for 3D rendering.
 *
 * Sets the clear color to white, the drawing color to black, and clears the color and depth buffers.
 * Enables depth testing and sets the depth mask to true.
 * Sets up a perspective projection matrix with the given parameters.
 * Sets the modelview matrix to the identity matrix.
 *
 * @param x1 The minimum x value of the perspective projection.
 * @param x2 The maximum x value of the perspective projection.
 * @param x3 The minimum y value of the perspective projection.
 * @param x4 The maximum y value of the perspective projection.
 * @param x5 The minimum z value of the perspective projection.
 * @param x6 The maximum z value of the perspective projection.
 * @see CGL_Init2D
 * @see CGL_Init3D
 */
void CGL_Init3D(float x1, float x2, float x3, float x4, float x5, float x6)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	glDepthMask(GL_TRUE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(x1, x2, x3, x4, x5, x6);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
