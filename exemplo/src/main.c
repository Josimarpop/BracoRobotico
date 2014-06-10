/*
 ============================================================================
 Name        : BracoRobotico.c
 Author      : Ronyerison
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <GL/glut.h>
#include <stdlib.h>

static int elbow = 0, hand = 0, finger1 = 0, finger2 = 0, finger3 = 0;
float y1 = 0.0;
int cont = 0, cont1 = 0, cont2 = 0, cont3 = 0;
#define red 1.0, 0.0, 0.0
#define white 1.0, 1.0, 1.0
#define blue 0.0, 0.0, 1.0

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-50, 50, -50, 50, -50, 50);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

//	Barra
	glTranslatef(-2.0, 0.0, 0.0);
	glColor3f(white);
	glPushMatrix();
	glScalef(0.4, 4.0, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();

//	Braco
	glTranslatef(1.2, y1, 0.0);
	glColor3f(white);
	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

//	Cotovelo
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glColor3f(white);
	glPushMatrix();
	glScalef(2.0, 0.2, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

//	Punho
	glTranslatef(1.1, 0.0, 0.0);
	glRotatef((GLfloat) hand, 1.0, 0.0, 0.0);
	glColor3f(red);
	glPushMatrix();
	glScalef(0.2, 1.0, 0.8);
	glutSolidCube(1.0);
	glPopMatrix();

//	Dedo 1

	glTranslatef(0.3, 0.3, -0.3);
	glColor3f(blue);
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glRotatef((GLfloat) finger1, 0.0, 0.5, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glTranslatef(-0.3, -0.3, 0.3);

//	Dedo 2

	glTranslatef(0.3, 0.0, 0.3);
	glColor3f(blue);
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glRotatef((GLfloat) finger2, 0.0, 1.0, 0.0);
	glTranslatef(0.2, 0.0, 0.0);
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	glTranslatef(-0.3, 0.0, -0.3);

//	Dedo 3
	glTranslatef(0.3, -0.3, -0.3);
	glColor3f(blue);
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glRotatef((GLfloat) finger3, 0.0, -0.5, 1.0);
	glTranslatef(0.2, 0.0, 0.0);
	glScalef(0.5, 0.1, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();
	//glTranslatef(-0.3, 0.0, -0.3);

	/* origem volta para o sistema de coordenadas original */
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 'c':
		if (elbow <= 120) {
			elbow = (elbow + 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'C':
		if (elbow >= -120) {
			elbow = (elbow - 5) % 360;
		}
		glutPostRedisplay();
		break;
	case 'p':
		hand = (hand + 5) % 360;
		glutPostRedisplay();
		break;
	case 'P':
		hand = (hand - 5) % 360;
		glutPostRedisplay();
		break;
	case 'o':
		if (y1 < 1.6) {
			y1 = y1 + 0.1;
		}
		glutPostRedisplay();
		break;
	case 'O':
		if (y1 > -1.6) {
			y1 = y1 - 0.1;
		}
		glutPostRedisplay();
		break;
	case 'u':
		if (cont < 8) {
			finger1 = (finger1 - 5) % 360;
			finger2 = (finger2 + 5) % 360;
			finger3 = (finger3 + 5) % 360;
			cont++;
		}
		glutPostRedisplay();
		break;
	case 'U':
		if (cont > -8) {
			finger1 = (finger1 + 5) % 360;
			finger2 = (finger2 - 5) % 360;
			finger3 = (finger3 - 5) % 360;
			cont--;
		}
		glutPostRedisplay();
		break;
	case 'i':
		if (cont1 < 8) {
			finger1 = (finger1 - 5) % 360;
			cont1++;
		}
		glutPostRedisplay();
		break;
	case 'I':
		if (cont1 > -8) {
			finger1 = (finger1 + 5) % 360;
			cont1--;
		}
		glutPostRedisplay();
		break;
	case 'm':
		if (cont2 < 8) {
			finger2 = (finger2 + 5) % 360;
			cont2++;
		}
		glutPostRedisplay();
		break;
	case 'M':
		if (cont2 > -8) {
			finger2 = (finger2 - 5) % 360;
			cont2--;
		}
		glutPostRedisplay();
		break;
	case 't':
		if (cont3 < 8) {
			finger3 = (finger3 + 5) % 360;
			cont3++;
		}
		glutPostRedisplay();
		break;

	case 'T':
		if (cont3 > -8) {
			finger3 = (finger3 - 5) % 360;
			cont3--;
		}
		glutPostRedisplay();
		break;

	case 'a':
		finger1 = 0;
		finger2 = 0;
		finger3 = 0;
		cont = 0;
		glutPostRedisplay();
		break;

	case 'A':
		finger1 = 0;
		finger2 = 0;
		finger3 = 0;
		cont = 0;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

