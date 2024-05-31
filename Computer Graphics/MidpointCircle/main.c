#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

// Function to initialize OpenGL
void initOpenGL() {
    // Set the background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

// Midpoint Circle Drawing function
void drawCircleMidpoint(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int decisionParam = 1 - x;

    while (x >= y) {
        glBegin(GL_POINTS);
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY - x);
        glEnd();

        y++;
        if (decisionParam <= 0) {
            decisionParam += 2 * y + 1;
        } else {
            x--;
            decisionParam += 2 * (y - x) + 1;
        }
    }
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Display callback for GLUT
void display() {
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the drawing color to white

    drawCircleMidpoint(0, 0, 100); // Center (0,0) with a visible radius

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing");

    // Initialize GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Error initializing GLEW: %s\n", glewGetErrorString(err));
        return 1;
    }

    initOpenGL();

    // Register callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);
    glutIdleFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
