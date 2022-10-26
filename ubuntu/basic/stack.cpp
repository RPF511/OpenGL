#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    glutSolidTeapot(0.1);

    glTranslatef(0.2,0.2,0.0);
    glutSolidTeapot(0.1);

    glTranslatef(0.2,-0.2,0.0);
    glutSolidTeapot(0.1);

    glRotatef(45,0,0,1);
    glutSolidTeapot(0.1);

    glScalef(1.5,1.5,1.0);
    glutSolidTeapot(0.1);

    glPopMatrix();
    glTranslatef(0.0,-0.2,0.0);
    glutSolidTeapot(0.1);
    
    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Title");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}