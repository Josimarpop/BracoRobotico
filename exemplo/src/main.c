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
#include <time.h>
#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void calcularEquacao(int xMax,int xMin,int yMax, int yMin);

GLint x1 = 40;
GLint y1 = 100;
GLint x2 = 100;
GLint y2 = 100;

GLint x3 = 150;
GLint y3 = 150;
GLint x4 = 150;
GLint y4 = 200;

float coefAngular, coefLinear;

GLint mov = 1;

GLfloat r, g, b;

int main(int argc, char** argv)
{
	srand(time(NULL));
	printf("Linha 1 \nValor x1: ");
	scanf("%d", &x1);
	printf("Valor y1: ");
	scanf("%d", &y1);
	printf("Valor x2: ");
	scanf("%d", &x2);
	printf("Valor y2: ");
	scanf("%d", &y2);
	printf("Linha 2 \nValor x3: ");
	scanf("%d", &x3);
	printf("Valor y3: ");
	scanf("%d", &y3);
	printf("Valor x4: ");
	scanf("%d", &x4);
	printf("Valor y4: ");
	scanf("%d", &y4);

	if(x4 != x3 && y4 != y3){
		calcularEquacao(x4,x3,y4,y3);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(256, 256);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Desenhando uma linha");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void init(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho (0, 256, 0, 256, -1 , 1);
	r = 0.0;
	g = 0.0;
	b = 1.0;
}
void display(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glColor3f (1.0, 0.0, 0.0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	glBegin(GL_LINES);
	glColor3f (r, g, b);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();

	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		y1 += mov ;
		y2 += mov ;;
		display();
		break;
	case 'A':
		y1 += mov ;
		y2 += mov ;;
		display();
		break;
	case 'z':
		y1 += -mov ;
		y2 += -mov ;;
		display();
		break;
	case 'Z':
		y1 += -mov ;
		y2 += -mov ;;
		display();
		break;
	case 'q':
		x1 += -mov ;
		x2 += -mov ;;
		display();
		break;
	case 'Q':
		x1 += -mov ;
		x2 += -mov ;;
		display();
		break;
	case 'w':
		x1 += mov ;
		x2 += mov ;;
		display();
		break;
	case 'W':
		x1 += mov ;
		x2 += mov ;;
		display();
		break;
	case 'f':
		if(x3 > x4 ){
			x3 += mov ;
			x4 += -mov ;
		}else if(x3 < x4){
			x3 += -mov ;
			x4 += mov ;
		}
		if(x3 != x4){
			if(y3 > y4){
				y3 = coefAngular * x3 + coefLinear;
				y4 = coefAngular * x4 + coefLinear;
			}else if(y4 > y3){
				y4 = coefAngular * x4 + coefLinear;
				y3 = coefAngular * x3 + coefLinear;
			}
		}else{
			if(y3 > y4){
				y3 += mov;
				y4 += -mov;
			}else if(y4 > y3){
				y4 += mov;
				y3 += -mov;
			}
		}
		display();
		break;

	case 'F':
		if(x3 > x4 ){
			x3 += mov ;
			x4 += -mov ;
		}else if(x3 < x4){
			x3 += -mov ;
			x4 += mov ;
		}
		if(x3 != x4){
			if(y3 > y4){
				y3 = coefAngular * x3 + coefLinear;
				y4 = coefAngular * x4 + coefLinear;
			}else if(y4 > y3){
				y4 = coefAngular * x4 + coefLinear;
				y3 = coefAngular * x3 + coefLinear;
			}
		}else{
			if(y3 > y4){
				y3 += mov;
				y4 += -mov;
			}else if(y4 > y3){
				y4 += mov;
				y3 += -mov;
			}
		}
		display();
		break;
	case 'v':
		if(x3 < x4 && x3+mov != x4-mov){
			x3 += mov ;
			x4 += -mov ;
		}else if(x3 > x4 && x3-mov != x4+mov){
			x3 += -mov ;
			x4 += mov ;
		}
		if(y3 != y4){
			if(x3 != x4){
				y3 = coefAngular * x3 + coefLinear;
			   	y4 = coefAngular * x4 + coefLinear;
			}else{
				if(y3 > y4 && y3-mov != y4+mov){
					y3 += -mov;
				   	y4 += mov;
				}else if(y4 > y3 && y4-mov != y3+mov){
					y4 += -mov;
				   	y3 += mov;
			   	}
			}
		}



		display();
		break;
	case 'V':
		if(x3 < x4 && x3+mov != x4-mov){
			x3 += mov ;
			x4 += -mov ;
		}else if(x3 > x4 && x3-mov != x4+mov){
			x3 += -mov ;
			x4 += mov ;
		}
		if(y3 != y4){
			if(x3 != x4){
				y3 = coefAngular * x3 + coefLinear;
			   	y4 = coefAngular * x4 + coefLinear;
			}else{
				if(y3 > y4 && y3-mov != y4+mov){
					y3 += -mov;
				   	y4 += mov;
				}else if(y4 > y3 && y4-mov != y3+mov){
					y4 += -mov;
				   	y3 += mov;
			   	}
			}
		}
		display();
		break;
	case 'c':
		r = (float)rand() / (float)RAND_MAX;
		g = (float)rand() / (float)RAND_MAX;
		b = (float)rand() / (float)RAND_MAX;
		display();
		break;
	case 'C':
		r = (float)rand() / (float)RAND_MAX;
		g = (float)rand() / (float)RAND_MAX;
		b = (float)rand() / (float)RAND_MAX;
		display();
		break;
	case 'b':
		init();
		display();
		break;
	case 'B':
		init();
		display();
		break;
	}

}


void calcularEquacao(int xMax,int xMin,int yMax, int yMin){
	coefAngular = (float)(yMax - yMin)/(float)(xMax - xMin);
	coefLinear = yMin - coefAngular * xMin;
}













