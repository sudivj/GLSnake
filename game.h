// Game Logic //

#include <iostream>
#include <math.h>
#include <GL/glut.h>

#define WIDTH 20
#define HEIGHT 21
#define DEMX 1.0
#define DEMY 1.0

__time_t t;

int gameplay = 1;
int score = 0;

float playerPosX = 0;
float playerPosY = 0;
float fruitPosX = 0;
float fruitPosY = 0;
float delay_action = 0;

int last_Key = 3;
int previous_Key;

// Spawn Fruit //
// Spawns the fruit in a random position.

void spawnFruit()
{
    while (1)
    {
        srand((unsigned)time(&t));
        if (fruitPosX == playerPosX && fruitPosY == playerPosY)
        {
            fruitPosX = rand() % WIDTH;
            fruitPosX = fruitPosX - 1;
            fruitPosY  = rand() % HEIGHT;
            fruitPosY = fruitPosY - 2;
        }
        else
        {
            fruitPosX = rand() % (WIDTH  - 1);
            //fruitPosX = fruitPosX - 1;
            fruitPosY  = rand() % (HEIGHT - 2);
            //fruitPosY = fruitPosY - 2;
            break;
        }
    }
    
}

// Death //
// Checks whether the player is colliding with the walls.

void death(void)
{
    if ((playerPosX + 1) < 1)
    {
        gameplay = 0;
    }
    else if ((playerPosX + 1) > WIDTH - 1)
    {
        gameplay = 0;
    }
    else if ((playerPosY + 1) < 1)
    {
        gameplay = 0;
    }
    else if ((playerPosY + 1) > HEIGHT - 2)
    {
        gameplay = 0;
    }
    else
    {
        gameplay = 1;
    }
}

// Eating Fruit //

void eatFruit()
{
    if (playerPosX == fruitPosX && playerPosY == fruitPosY)
    {
        spawnFruit();
        score = score + 1;
    }
    
}

// Player Movement

//      KEY MAP
//      ------- 
// Right Arrow Key == 1
// Left Arrow Key  == 2
// Up Arrow Key    == 3
// Down Arrow Key  == 4 

void movement()
{
    delay_action = delay_action + 0.05;
    if (previous_Key != last_Key)
    {
        delay_action = 0.9;
        previous_Key = last_Key;
    }
    if (delay_action > 1)
    {
        if (last_Key == 1)
        {
            playerPosX = playerPosX + 1;
            death();
        }
        else if (last_Key == 2)
        {
            playerPosX = playerPosX - 1;
            death();
        }
        else if (last_Key == 3)
        {
            playerPosY = playerPosY + 1;
            death();
        }
        else if (last_Key == 4)
        {
            playerPosY = playerPosY - 1;
            death();
        }
        eatFruit();
        delay_action = 0;
    }
    glutPostRedisplay();
}

// Player Logic //

void logic(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        if (last_Key != 2)
        {
            last_Key = 1;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        if (last_Key != 1)
        {
            last_Key = 2;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        if (last_Key != 4)
        {
            last_Key = 3;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        if (last_Key != 3)
        {
            last_Key = 4;
        }
        glutPostRedisplay();
        break;
    default:
        last_Key = last_Key;
        break;
    }
}