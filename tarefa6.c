#include <GL/glut.h>

#define STEP 7.5f

void initGL();
void reshape(int, int);
void display();
void keyboard(unsigned char, int, int);

float angle_x = 0.0f;
float angle_y = 0.0f;
float angle_z = 0.0f;


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    initGL();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;

}

void initGL()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cubo em Projecao de Perspectiva");
    glEnable(GL_DEPTH_TEST);
}

void reshape(int width, int height)
{
    GLdouble aspect;

    if (height == 0)
        height = 1;

    aspect = (GLdouble)width / (GLdouble)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /*
    void gluPerspective(GLdouble fovy,
                        GLdouble aspect,
                        GLdouble zNear,
                        GLdouble zFar);
    */
    gluPerspective(90.0, aspect, 0.1, 100.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Move para o fundo para ser visualizado
	glTranslatef(0.0f, 0.0f, -18.0f);
	glRotatef(angle_x, 1.0f, 0.0f, 0.0f);
    glRotatef(angle_y, 0.0f, 1.0f, 0.0f);
    glRotatef(angle_z, 0.0f, 0.0f, 1.0f);


    glBegin(GL_QUADS);

    //Frente Amarela
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 6.0f,  3.0f,  9.0f);
    glVertex3f(-6.0f,  3.0f,  9.0f);
    glVertex3f(-6.0f, -3.0f,  9.0f);
    glVertex3f( 6.0f, -3.0f,  9.0f);

    //Cima Verde
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 6.0f,  3.0f,  9.0f);
    glVertex3f( 6.0f,  3.0f, -9.0f);
    glVertex3f(-6.0f,  3.0f, -9.0f);
    glVertex3f(-6.0f,  3.0f,  9.0f);

    //Direita Vermelha
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 6.0f,  3.0f,  9.0f);
    glVertex3f( 6.0f, -3.0f,  9.0f);
    glVertex3f( 6.0f, -3.0f, -9.0f);
    glVertex3f( 6.0f,  3.0f, -9.0f);


    //Trás Branca
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f( 6.0f,  3.0f, -9.0f);
    glVertex3f( 6.0f, -3.0f, -9.0f);
    glVertex3f(-6.0f, -3.0f, -9.0f);
    glVertex3f(-6.0f,  3.0f, -9.0f);

    //Baixo Azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 6.0f, -3.0f,  9.0f);
    glVertex3f(-6.0f, -3.0f,  9.0f);
    glVertex3f(-6.0f, -3.0f, -9.0f);
    glVertex3f( 6.0f, -3.0f, -9.0f);

    //Esqueda Laranja
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-6.0f,  3.0f,  9.0f);
    glVertex3f(-6.0f,  3.0f, -9.0f);
    glVertex3f(-6.0f, -3.0f, -9.0f);
    glVertex3f(-6.0f, -3.0f,  9.0f);

    glEnd();  // End of drawing color-cube


    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    //Eixo X
         if(key == 'W' || key == 'w')
        angle_x += STEP;
    else if(key == 'S' || key == 's')
        angle_x -= STEP;

    //Eixo Y
    else if(key == 'D' || key == 'd')
        angle_y += STEP;
    else if(key == 'A' || key == 'a')
        angle_y -= STEP;

    //Eixo Z
    else if(key == 'Q' || key == 'q')
        angle_z += STEP;
    else if(key == 'E' || key == 'e')
        angle_z -= STEP;


    glutPostRedisplay();
}
