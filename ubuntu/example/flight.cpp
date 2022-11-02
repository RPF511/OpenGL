
#include <stdio.h>
#include <GL/glut.h>

void pilotview(GLfloat roll, GLfloat pitch, GLfloat yaw){

    glRotatef(-roll,0.0,0.0,1.0);
    glRotatef(-pitch,1.0,0.0,0.0);
    glRotatef(-yaw,0.0,1.0,0.0);

    // gluLookAt(
    //     -pitch, -yaw, 0.0,
    //     0.0,0.0,0.0,
        
    // );

}

void mydisplay(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    pilotview(-45,0,0);
    //default
    // gluLookAt(0,0,0,  0,0,-1,  1,1,0);


    //pilotview(0,-45,0);
    //gluLookAt(0,-0.4,0.2,  0,0.6,-1,  0,1,0);

    //pilotview(0,0,-45);
    //gluLookAt(0.2,0.0,0.3,  -0.6,0.0,-0.6,  0,1,0);

    glutSolidTeapot(0.3);

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Drawing Example");
    glutDisplayFunc(mydisplay);
    glLoadIdentity();
    
    glutMainLoop();
    return 0;
}