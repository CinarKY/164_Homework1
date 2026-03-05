/***********************************
   CTIS164 Lab-Man
***********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define WINDOW_WIDTH  902
#define WINDOW_HEIGHT 902
#define PI  3.14159265

// To draw a filled circle, centered at (x,y) with radius r
void circle(int x, int y, int r) {
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		angle = 2 * PI * i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}

// Display text with variables.
void vprint(int x, int y, void* font, const char* string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, str[i]);
}

void vprint2(int x, int y, float size, const char* string, ...) {
	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(size, size, 1);

	glLineWidth(3);
	int len, i;
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
	glPopMatrix();
}

// To display onto window using OpenGL commands
void display() {
	printf("Function DISPLAY\n");
	// Clear window to black
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3ub(96, 96, 96); // Gray
	// Horizontal grid lines
	for (int y = -400; y <= 400; y += 40) {
		glVertex2f(-400, y);
		glVertex2f(400, y);
	}
	// Vertical grid lines
	for (int x = -400; x <= 400; x += 40) {
		glVertex2f(x, -400);
		glVertex2f(x, 400);
	}
	glEnd();

	glColor3ub(255, 255, 0); // Yellow lines
	glLineWidth(3);
	glBegin(GL_LINES);
	// Horizontal axis line
	glVertex2f(-400, 0);
	glVertex2f(400, 0);
	// Vertical axis line
	glVertex2f(0, -400);
	glVertex2f(0, 400);
	glEnd();

	// Yellow quad (body)
	glBegin(GL_QUADS);
	glVertex2f(-100, 0);
	glVertex2f(0, 100);
	glVertex2f(100, 0);
	glVertex2f(0, -100);
	glEnd();

	// Green circle (head)
	glColor3ub(102, 204, 0); // Green
	circle(0, 240, 80);

	// Red rectangle (mouth)
	glColor3ub(204, 0, 0); // Red
	glBegin(GL_POLYGON);
	glVertex2f(-50, 190);
	glVertex2f(-50, 220);
	glVertex2f(50, 220);
	glVertex2f(50, 190);
	glEnd();

	// Red triangle (nose)
	glBegin(GL_TRIANGLES);
	glVertex2f(-30, 230);
	glVertex2f(30, 230);
	glVertex2f(0, 250);
	glEnd();

	// Black circles (eyes)
	glColor3ub(0, 0, 0); // Black
	circle(-40, 260, 10);
	circle(40, 260, 10);

	// Red rectangle
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-100, 380);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(100, 380);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(100, 340);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-100, 340);
	glEnd();

	glColor3ub(0, 255, 255); // Blue
	vprint(-60, -200, GLUT_BITMAP_TIMES_ROMAN_24, "Hi There!!!");

	glutSwapBuffers();
}


void display3() {
	printf("Function DISPLAY3\n");
	// Clear window to blue
	glClearColor(0, 0.9, 0.9, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3ub(96, 96, 96); // Gray
	// Horizontal grid lines
	for (int y = -400; y <= 400; y += 40) {
		glVertex2f(-400, y);
		glVertex2f(400, y);
	}
	// Vertical grid lines
	for (int x = -400; x <= 400; x += 40) {
		glVertex2f(x, -400);
		glVertex2f(x, 400);
	}
	glEnd();

	glColor3ub(0, 0, 255); // Blue lines
	glLineWidth(3);
	glBegin(GL_LINES);
	// Horizontal axis line
	glVertex2f(-400, 0);
	glVertex2f(400, 0);
	// Vertical axis line
	glVertex2f(0, -400);
	glVertex2f(0, 400);
	glEnd();

	// Blue quad (body)
	glBegin(GL_QUADS);
	glVertex2f(-100, 0);
	glVertex2f(0, 100);
	glVertex2f(100, 0);
	glVertex2f(0, -100);
	glEnd();

	// Green circle (head)
	glColor3ub(102, 204, 0); // Green
	circle(0, 240, 80);

	// Red rectangle (mouth)
	glColor3ub(204, 0, 0); // Red
	glBegin(GL_POLYGON);
	glVertex2f(-50, 190);
	glVertex2f(-50, 220);
	glVertex2f(50, 220);
	glVertex2f(50, 190);
	glEnd();

	// Red triangle (nose)
	glBegin(GL_TRIANGLES);
	glVertex2f(-30, 230);
	glVertex2f(30, 230);
	glVertex2f(0, 250);
	glEnd();

	// Black circles (eyes)
	glColor3ub(0, 0, 0); // Black
	circle(-40, 260, 10);
	circle(40, 260, 10);

	// Red rectangle
	glBegin(GL_POLYGON);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-100, 380);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(100, 380);
	glColor3ub(51, 25, 0); // Brown
	glVertex2f(100, 340);
	glColor3ub(204, 0, 0); // Red
	glVertex2f(-100, 340);
	glEnd();

	glColor3ub(1, 1, 1); // Black
	vprint(-130, -200, GLUT_BITMAP_TIMES_ROMAN_24, "Lower RIGHT");

	glutSwapBuffers();
}

void display4() {
	printf("Function DISPLAY4\n");
	glClearColor(0, 1, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3ub(255, 229, 204);
	glRectf(-250, 250, 250, -250);

	glColor3ub(0, 0, 0);
	circle(0, 0, 50);

	glColor3ub(1, 1, 1); // Black
	vprint2(-160, 300, 0.4, "Upper LEFT");

	glutSwapBuffers();
}

void display5() {
	printf("Function DISPLAY5\n");
	glClearColor(1, 1, 0, 0); // Yellow
	glClear(GL_COLOR_BUFFER_BIT);

	// Draws a rectangle in the middle of the window.
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-100, -100);
	glVertex2f(-100, 100);
	glVertex2f(100, 100);
	glVertex2f(100, -100);
	glEnd();

	glColor3ub(1, 1, 1); // Black
	vprint2(-160, 300, 0.4, "Upper RIGHT");

	glutSwapBuffers();
}

// Key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
void onKey(unsigned char key, int x, int y) {
	// Exit when ESC is pressed.
	if (key == 27)
		exit(0);
	// To refresh the window it calls display() function
	glutPostRedisplay();
}

void onClick(int button, int state, int x, int y) {
	if (state == GLUT_UP)
		printf("\n\tx = %d,   y = %d\n\n", x, y);
}

// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
void onResize(int w, int h) {
	printf("Event: RESIZE New width: %d height: %d\n", w, h);
	/*
	   glViewport(0, 0, w, h);
	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	   glMatrixMode(GL_MODELVIEW);
	*/
	glEnable(GL_SCISSOR_TEST);
	glViewport(w / 2, h / 2, w / 2, h / 2);
	glScissor(w / 2, h / 2, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
	display5();

	glViewport(0, h / 2, w / 2, h / 2);
	glScissor(0, h / 2, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
	display4();

	glViewport(w / 2, 0, w / 2, h / 2);
	glScissor(w / 2, 0, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
	display3();

	glViewport(0, 0, w / 2, h / 2);
	glScissor(0, 0, w / 2, h / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(900, 5);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("CTIS164 Lab-Man");

	// Display Events
	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	// Mouse Events
	glutMouseFunc(onClick);

	// Keyboard Events
	glutKeyboardFunc(onKey);

	glutMainLoop();
	return 0;
}