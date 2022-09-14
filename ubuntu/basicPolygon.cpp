#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //middle (0,0)
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.0);
        glVertex3f(0.5,-0.5,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(-0.5,0.5,0.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Drawing Example");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}