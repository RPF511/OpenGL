#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    
    glutSolidTeapot(0.3);

    glTranslatef(0.2,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glutSolidTeapot(0.3);
    
    glTranslatef(0.2,0,0.0);
    glRotatef(45,0,0,1);
    glScalef(1.5,1.5,1.0);
    glColor3f(0.0,1.0,0.0);
    glutSolidTeapot(0.3);
    
    glFlush();
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Title");
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}