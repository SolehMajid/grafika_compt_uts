#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <time.h>
#include <maze.h>

Maze maze;

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (maze.grid[y][x].wall)
            {
                glRecti(
                    maze.grid[y][x].x1,
                    maze.grid[y][x].y1,
                    maze.grid[y][x].x2,
                    maze.grid[y][x].y2);
            }
        }
    }

    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH * CELL_SIZE, 0, HEIGHT * CELL_SIZE);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.1, 0.0, 1.0);
}

int main(int argc, char *argv[])
{

    srand(time(NULL));
    initMaze(&maze);
    divide(&maze, 0, 0, WIDTH, HEIGHT);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    // glutInitWindowPosition(100,100);
    glutCreateWindow("Segitiga Titik");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
