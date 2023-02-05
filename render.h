// Rendering Functions //

#include <iostream>
#include <string>
#include <string.h>
#include <GL/glut.h>
#include "game.h"
#include "write-score.h"

using namespace std;

// Print Given Text //

void print_text(float x, float y, char string[], int number)
{
    int n = number;
    int count = 0;
    do
    {
        n /= 10;
        ++count;
    } while (n != 0);    
    char *int_str;
    int_str = (char*)malloc((count * 2) * sizeof(char));
    sprintf(int_str, "%d", number);
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    int len, i;
    len = strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
    len = strlen(int_str);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int_str[i]);
    }
    glEnd();
    glFlush();
}

// Demolish Window(id) //

void destroy_window(void)
{
    if (gameplay == 0)
    {
        glutDestroyWindow(glutGetWindow());
        writeDate(score);
        cout << "Score = " << score << endl;
    }
}

// Player Shape Render //

void player()
{
    movement();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(playerPosX, playerPosY);
        glVertex2f(playerPosX + DEMX, playerPosY);
        glVertex2f(playerPosX + DEMX, playerPosY + DEMY);
        glVertex2f(playerPosX, playerPosY + DEMY);
    glEnd();
    glFlush();
}

// Fruit Shape Render //

void fruit()
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(fruitPosX, fruitPosY);
        glVertex2f(fruitPosX + DEMX, fruitPosY);
        glVertex2f(fruitPosX + DEMX, fruitPosY + DEMY);
        glVertex2f(fruitPosX, fruitPosY + DEMY);
    glEnd();
    glFlush();
}

// Text Area //

void text_box()
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0, HEIGHT - 2.0);
        glVertex2f( WIDTH, HEIGHT - 2.0);
        glVertex2f( WIDTH, HEIGHT);
        glVertex2f( 0.0, HEIGHT);
    glEnd();
    glFlush();
}

// Render Game //

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    text_box();
    print_text(0.0, 19.4, "SCORE = ", score);
    fruit();
    player();
    glutSwapBuffers();
    destroy_window();
}



void init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    
    glutCreateWindow("GLsnake");

    glClearColor(0, 0, 0 ,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH - 1, 0, HEIGHT - 1);
    glutSpecialFunc(logic);

    glutDisplayFunc(render);
    
    glutMainLoop();
}