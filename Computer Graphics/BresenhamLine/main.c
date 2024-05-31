#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>

// Function to initialize OpenGL
void initOpenGL() {
    // Set the background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

// Bresenham line drawing function
void drawLineBresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2; /* error value e_xy */

    while (1) {
        glBegin(GL_POINTS);
        glVertex2i(x0, y0); // Set the pixel
        glEnd();

        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }
}

// Display callback for GLUT
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set the drawing color to white

    // Adjust these parameters to fit your viewport and desired line start/end points
    int x0 = 150, y0 = 150, x1 = 400, y1 = 300;

    // Transform coordinates to fit the OpenGL viewport
    int viewportWidth = 640, viewportHeight = 480;
    x0 -= viewportWidth / 2; y0 -= viewportHeight / 2;
    x1 -= viewportWidth / 2; y1 -= viewportHeight / 2;

    // Apply simple scaling if necessary
    float scaleFactor = 0.01f; // Example scale factor, adjust as needed
    glScalef(scaleFactor, scaleFactor, 1.0f);

    drawLineBresenham(x0, y0, x1, y1);

    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");

    initOpenGL();

    // Register the display callback
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
