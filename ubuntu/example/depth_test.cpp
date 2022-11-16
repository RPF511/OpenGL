#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


void mydisplay(){
    //DEPTH BUFFER CLEAR
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //DEPTH CHECK
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK,GL_LINE);
    glFrustum(-1,1,-1,1,-1,10);
    gluLookAt(0.2,0.2,0.1,0,0,0,0,1,0);



    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f( 0.25,0.25,-0.25);
    glVertex3f( -0.25,0.25,-0.25);
    glVertex3f( -0.25,-0.25,-0.25);
    glVertex3f( 0.25,-0.25,-0.25);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f( 0.5,0.5,-0.5);
    glVertex3f( -0.5,0.5,-0.5);
    glVertex3f( -0.5,-0.5,-0.5);
    glVertex3f( 0.5,-0.5,-0.5);
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