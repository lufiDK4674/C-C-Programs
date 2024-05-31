#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

void initGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black and opaque
}

void midpointEllipse(int rx, int ry, int xc, int yc) {
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy) {
        // Print points based on 4-way symmetry
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);


    // Plotting points of region 2
    while (y >= 0) {
        // Print points based on 4-way symmetry
        glVertex2i(x + xc, y + yc);
        glVertex2i(-x + xc, y + yc);
        glVertex2i(x + xc, -y + yc);
        glVertex2i(-x + xc, -y + yc);

        // Checking and updating parameter
        // based on algorithm
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glLoadIdentity(); // Reset the model-view matrix

    // Set up the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);

    // Draw the ellipse
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_POINTS);
    midpointEllipse(100, 60, 0, 0); // rx, ry, center_x, center_y
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(500, 500); // Set window size
    glutInitWindowPosition(50, 50); // Set window position
    glutCreateWindow("Midpoint Ellipse Algorithm"); // Create window with the given title

    glewExperimental = GL_TRUE;
    glewInit();

    glutDisplayFunc(display); // Register display callback handler for window re-paint
    initGL(); // Our own OpenGL initialization
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
