#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    glLoadIdentity();

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2,0.2);
    glVertex2f(-0.4,0.2);
    glVertex2f(-0.4,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();

    glRotatef(45.0,0.0,0.0,1.0);

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.2,0.2);
    glVertex2f(-0.4,0.2);
    glVertex2f(-0.4,0.4);
    glVertex2f(-0.2,0.4);
    glEnd();
//////////////////////////////////////
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.4,0.2);
    glVertex2f(0.4,0.4);
    glVertex2f(0.2,0.4);
    glEnd();

    glTranslatef(0.3,0.3,0.0);
    glRotatef(45.0,0.0,0.0,1.0);
    glTranslatef(-0.3,-0.3,0.0);

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.2,0.2);
    glVertex2f(0.4,0.2);
    glVertex2f(0.4,0.4);
    glVertex2f(0.2,0.4);
    glEnd();


    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Drawing Example");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}