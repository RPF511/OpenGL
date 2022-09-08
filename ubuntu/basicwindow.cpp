#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Title");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}