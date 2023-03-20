#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WH  800
#define WH2 400

void init   (void);
void display(void);
void octant (int, int, int, int);
void circle (int, int, int);

GLubyte Color[3];
int X, Y, R;



int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));


    glutInit(&argc, argv);

    init();

    //Cor aleatória;
    Color[0] = rand() % 256;
    Color[1] = rand() % 256;
    Color[2] = rand() % 256;
    printf("COLOR: (%3d, %3d, %3d)\n", Color[0], Color[1], Color[2]);

    //Circulo aleatório;
    X = rand() % WH - WH2;
    Y = rand() % WH - WH2;
    R = rand() % WH2;
    printf("CIRCLE: (%3d, %3d, %3d)\n", X, Y, R);


    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

void init(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);

    glutInitWindowSize(WH, WH);

    glutCreateWindow("Circunferência");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-WH2, WH2, -WH2, WH2);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3ubv(Color);

    circle(X, Y, R);

    glFlush();
}



void octant(int xp, int yp, int dx, int dy)
{
    glBegin(GL_POINTS);
        glVertex2i( xp + dx,  yp + dy);
        glVertex2i( xp + dx, -yp + dy);
        glVertex2i(-xp + dx,  yp + dy);
        glVertex2i(-xp + dx, -yp + dy);
        glVertex2i( yp + dx,  xp + dy);
        glVertex2i( yp + dx, -xp + dy);
        glVertex2i(-yp + dx,  xp + dy);
        glVertex2i(-yp + dx, -xp + dy);
    glEnd();
}

void circle(int xc, int yc, int radius)
{
    int x, y;
    float delta;

    x = 0;
    y = radius;
    delta = (5.0 / 4.0) - radius;

    octant(x, y, xc, yc);
    //arco do 1º octante;
    //de 90 ate 45 graus;
    while(x < y)
    {
        //ponto fora do circulo;
        //ou ponto na circunferência;
        if(delta >= 0)
        {//Sudeste;
            delta += 2.0 * (x - y) + 5.0;
            x++; //direita;
            y--; //baixo;
        }
        //ponto dentro do circulo;
        else
        {//Leste;
            delta += 2.0 * x + 3.0;
            x++;  //direita;
        }
        octant(x, y, xc, yc);
    }


}
