#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrtho(-3.0,3.0,-3.0,3.0,-1.0,1.0);
    // gluPerspective(90,1,1,10);
    glFrustum(-1,1,-1,1,1,10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-1,0,-2);
    glRotatef(30,1,1,0);
    glutSolidTeapot(0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-4);
    glRotatef(30,1,1,0);
    glColor3f(0,1,0);
    glutSolidTeapot(0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,-6);
    glRotatef(30,1,1,0);
    glColor3f(0,0,1);
    glutSolidTeapot(0.4);
    glPopMatrix();

    


    
    
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