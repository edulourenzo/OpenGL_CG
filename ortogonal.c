#include <GL/glut.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#define WH  640
#define WH2 320
#define MAX 0X3FFFFFFF

typedef struct object_t
{
	int num_vtx;
	int num_line;
	int *list;
	GLint **vtx3;
}object;

void init   (void);
void display(void);
void reshape(int, int);
void new_object(struct object_t*, int, int, ...);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

void new_object(struct object_t *obj, int V, int L, ...)
{
	int i, j, aux;
	va_list valist;

	va_start(valist, V + L);
	obj->num_vtx = V;
	obj->num_line = L;
   obj->list = (int*)malloc(L * sizeof(int));
   obj->vtx3 = (int**)malloc(V * sizeof(int*));
   for(i = 0; i < V; i++)
   {
		obj->vtx3[i] = (int*)malloc(3 * sizeof(int));
		//atribuir (X, Y, Z) ao vetor allocado;
		aux = va_arg(valist, int);
		obj->vtx3[i][0] = (GLint)aux;
		aux = va_arg(valist, int);
		obj->vtx3[i][1] = (GLint)aux;
		aux = va_arg(valist, int);
		obj->vtx3[i][2] = (GLint)aux;
   }
   for(i = 0; i < L; i++)
   {
		aux = arg(valist, int);
		obj->list[i] = aux;
   }
}

void init(void)
{
    //default (GLUT_SINGLE | GLUT_RGBA == GLUT_RGB)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //default (-1, -1);
    glutInitWindowPosition(0, 0);

    //default (300, 300);
    glutInitWindowSize(WH, WH);

    glutCreateWindow("Redimencionamento");

    //default (GL_MODELVIEW);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    //default (-1-1.0, 1.0, -1.0, 1.0)
    //alias de glOrtho sem os limites do eixo z
    gluOrtho2D(-WH2, WH2, -WH2, WH2);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Losango amarelo
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2i(159, 106);
        glVertex2i(212, 159);
        glVertex2i(159, 212);
        glVertex2i(106, 159);
    glEnd();

    //Trapézio verde
    glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(-267, 106);
        glVertex2i( -55, 106);
        glVertex2i(-108, 212);
        glVertex2i(-214, 212);
    glEnd();

    //Octógono azul
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(-179, -215);
        glVertex2i(-143, -215);
        glVertex2i(-107, -179);
        glVertex2i(-107, -143);
        glVertex2i(-143, -107);
        glVertex2i(-179, -107);
        glVertex2i(-215, -143);
        glVertex2i(-215, -179);
    glEnd();

    //Triângulo vermelho
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(106, -214);
        glVertex2i(212, -214);
        glVertex2i(159, -122);
    glEnd();

    glBegin(GL_LINES);
        //Eixo cartesiano branco
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(-MAX,    0);
        glVertex2i( MAX,    0);
        glVertex2i(   0, -MAX);
        glVertex2i(   0,  MAX);

        //Quadrante vermelho(640X640)
        glColor3f(1.0, 0.0, 0.0);
        //Cima
        glVertex2i( 319,  319);
        glVertex2i(-319,  319);
        //Esquerda
        glVertex2i(-319,  319);
        glVertex2i(-319, -319);
        //Baixo
        glVertex2i(-319, -319);
        glVertex2i( 319, -319);
        //Direita
        glVertex2i( 319, -319);
        glVertex2i( 319,  319);
    glEnd();

    glFlush();
}

void reshape(int width, int height)
{
    GLdouble rt;    //Ratio

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width >= height && height != 0)
    {
        rt = (GLdouble)width / height;
        gluOrtho2D(-WH2 * rt, WH2 * rt, -WH2, WH2);
    }
    else if(height > width && width != 0)
    {
        rt = (GLdouble)height / width;
        gluOrtho2D(-WH2, WH2, -WH2 * rt, WH2 * rt);
    }

}
