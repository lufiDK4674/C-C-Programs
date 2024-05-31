#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Point;

// Declare a global array of points and a counter for how many there are
Point *points = NULL;
int pointCount = 0;

// Function to calculate line points using the DDA algorithm
void calculateDDALinePoints(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = (int)fmax(fabs(dx), fabs(dy));
    pointCount = steps + 1;

    points = (Point*)malloc(pointCount * sizeof(Point));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++) {
        points[i].x = x;
        points[i].y = y;
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to initialize OpenGL
void initOpenGL() {
    // Set the background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

// Display callback for GLUT
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the drawing color to white

    // Draw the calculated line points
    glBegin(GL_POINTS);
    for (int i = 0; i < pointCount; i++) {
        glVertex2f(points[i].x / 100, points[i].y / 100); // Assuming the coordinates are normalized
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    // Calculate points for the line
    calculateDDALinePoints(0, 0, 50, 50); // Example coordinates

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");

    initOpenGL();

    // Register the display callback
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    free(points); // Clean up allocated memory
    return 0;
}
