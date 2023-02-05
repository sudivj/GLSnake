// Main //

#include <iostream>
#include <GL/glut.h>
#include "render.h"

using namespace std;

int main(int argc, char **argv)
{
    spawnFruit();
    while (gameplay)
    {
        init(argc, argv);
        death();
    }
    glutDestroyWindow(glutGetWindow());

    return 0;
}