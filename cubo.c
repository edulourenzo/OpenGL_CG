#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WH  800
#define WH2 400
#define MAX 0X3FFFFFFF


void init   (void);
void display(void);
//void reshape(int, int);
void randColor(GLubyte[3]);

GLubyte Color[3];



int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));


    glutInit(&argc, argv);

    init();

    glutDisplayFunc(display);
    //glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

void init(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0, 0);

    glutInitWindowSize(WH, WH);

    glutCreateWindow("Projeção Ortogonal");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    gluOrtho2D(-WH2, WH2, -WH2, WH2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    randColor(Color);
    glColor3ubv(Color);
    printf("\nCOLOR: (%3d, %3d, %3d)\n", Color[0], Color[1], Color[2]);

    glBegin(GL_POLYGON);
        glVertex3i(-100,  100, -100);
        glVertex3i(-100, -100, -100);
        glVertex3i( 100, -100, -100);
        glVertex3i( 100,    0, -100);
        glVertex3i(   0,  100, -100);

    glEnd();

    glFlush();
}



void randColor(GLubyte C[3])
{
    //Cor aleatória;
    C[0] = rand() % 256;
    C[1] = rand() % 256;
    C[2] = rand() % 256;
}


/*void reshape(int width, int height)
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

}*/
