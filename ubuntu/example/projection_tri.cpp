#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0f,1.0f, -1.0f, 1.0, 1.0f,10.0f);
    // glOrtho(-1,1,-1,1,1,10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,0.5,-1.5);
    glVertex3f(-0.2,0.0,-1.5);
    glVertex3f(-0.8,0.0,-1.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.5,0.5,-3);
    glVertex3f(0.2,0.0,-3);
    glVertex3f(0.8,0.0,-3);
    glEnd();


    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Cube example");
    glutInitWindowSize(300,300);
    // glutInitWindowPosition(500,100);
    glutDisplayFunc(mydisplay);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    
    glutMainLoop();
    return 0;  
}