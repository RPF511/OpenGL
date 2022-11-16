#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK,GL_LINE);
    glFrustum(-1,1,-1,1,-1,10);

    glBegin(GL_TRIANGLES);
    glVertex3f( 0.1,0.1,0.0);
    glVertex3f( 0.3, 0.1, 0.0);
    glVertex3f( 0.2, 0.3, 0.0 );
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.2,0.0,0.0);
    glVertex3f(-0.1,-0.2,0.0);
    glVertex3f(-0.3,-0.2,0.0);
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