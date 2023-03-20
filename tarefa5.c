#include <GL/glut.h>

#define WH  800
#define WH2 400

void display(void);
void draw   (void);

int main(int argc, char* argv[])
{
    //Inicialização;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(WH, WH);
    glutCreateWindow("Projecao Ortografica");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //VP|1|2|
    //  |3|4|

    //Cima VP(1)
    glViewport(  0, WH2, WH2, WH2);
    glLoadIdentity();
    gluLookAt( 0.0,  1.0,  0.0,
               0.0,  0.0,  0.0,
               0.0,  0.0, -1.0);
    draw();

    /*
    //Esqueda VP(2)
    glViewport(WH2, WH2, WH2, WH2);
    glLoadIdentity();
    gluLookAt(-1.0,  0.0, 0.0,
               0.0,  0.0,  0.0,
               0.0,  1.0,  0.0);
    draw();
    */

    //Frente VP(3)
    glViewport(  0,    0, WH2, WH2);
    glLoadIdentity();
    gluLookAt( 0.0,  0.0, -1.0,
               0.0,  0.0,  0.0,
               1.0,  0.0,  0.0);
    draw();

    //Direita VP(4)
    glViewport(WH2,   0, WH2, WH2);
    glLoadIdentity();
    gluLookAt( 1.0,  0.0,  0.0,
               0.0,  0.0,  0.0,
               0.0,  1.0,  0.0);
    draw();

    glFlush();
}

void draw(void)
{
    //Cubo cortado na diagonal
    //Frete branca
    glBegin(GL_POLYGON);
        glColor3f ( 1.0,  1.0,  1.0);
        glVertex3f( 0.1,  0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f( 0.5,  0.1, -0.5);
    glEnd();

    //Trás amarela
    glBegin(GL_POLYGON);
        glColor3f ( 1.0,  1.0,  0.0);
        glVertex3f( 0.1,  0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5,  0.1,  0.5);
    glEnd();

    //Diagonal roxa
    glBegin(GL_POLYGON);
        glColor3f ( 1.0,  0.0,  1.0);
        glVertex3f( 0.1,  0.5,  0.5);
        glVertex3f( 0.5,  0.1,  0.5);
        glVertex3f( 0.5,  0.1, -0.5);
        glVertex3f( 0.1,  0.5, -0.5);
    glEnd();

    //Direita laranja
    glBegin(GL_POLYGON);
        glColor3f ( 1.0,  0.5,  0.0);
        glVertex3f( 0.5,  0.1, -0.5);
        glVertex3f( 0.5,  0.1,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5, -0.5);
    glEnd();

    //Esquerda vermelho
    glBegin(GL_POLYGON);
        glColor3f ( 1.0,  0.0,  0.0);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5,  0.5);
    glEnd();

    //Cima verde
    glBegin(GL_POLYGON);
        glColor3f ( 0.0,  1.0,  0.0);
        glVertex3f( 0.1,  0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f( 0.1,  0.5,  0.5);
    glEnd();

    //Baixo azul
    glBegin(GL_POLYGON);
        glColor3f ( 0.0,  0.0,  1.0);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);
    glEnd();
}
