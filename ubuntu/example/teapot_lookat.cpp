//ubuntu 20.04 환경에서 작성한 코드로, 헤더파일 명이 다를 수 있습니다.

#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void mydisplay1(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    // glViewport(0,0,300,150);

    glViewport(0,0,150,300);
    gluLookAt(0.0,0.0,0.5,  0.0,0.0,0.0,  0.0,1.0,0.0);
    glutWireTeapot(0.5);
    

    glViewport(150, 0, 150, 300);
    gluLookAt(0, 0, 0.5,  0, 0, 0, 1, 1, 0);
    glutWireTeapot(0.5);


    glFlush();
}

void mydisplay3(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    // glViewport(0,0,300,150);

    glPushMatrix();
    gluLookAt(0,0.3,0,0.4,0,-0.8,0,1,0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.8,0.0,0.8);
        glVertex3f(0.8,0.0,-0.8);
        glVertex3f(-0.8,0.0,-0.8);
        glVertex3f(-0.8,0.0,0.8);
    glEnd();

    glPopMatrix();
    glColor3f(1.0,1.0,1.0);
    glutWireTeapot(0.5);
    


    glFlush();
}
void mydisplay4(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    // glViewport(0,0,300,150);
    glViewport(0,0,150,300);
    gluLookAt(0.0,0.0,0.5,  0.0,0.0,0.0,  0.0,1.0,0.0);
    glutWireTeapot(0.5);
    

    glViewport(150, 0, 150, 300);

    glPushMatrix();
    gluLookAt(0,0.3,0,0.4,0,-0.8,0,1,0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
        glVertex3f(0.8,0.0,0.8);
        glVertex3f(0.8,0.0,-0.8);
        glVertex3f(-0.8,0.0,-0.8);
        glVertex3f(-0.8,0.0,0.8);
    glEnd();

    glPopMatrix();
    glColor3f(1.0,1.0,1.0);
    glutWireTeapot(0.5);
    


    glFlush();
}

void mydisplay2(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    // glViewport(0,0,300,150);

    glViewport(0,0,150,300);
    glPushMatrix();
    gluLookAt(0.0,0.2,0.3,  0.0,0.0,0.0,  0.0,1.0,0.0);
    glutWireTeapot(0.5);
    

    glViewport(150, 0, 150, 300);
    glPopMatrix();
    gluLookAt(0, 1, 0.1, 0, 0, 0, 0, 1, 0);
    glRotatef(90, 0, 1, 0);
    glutWireTeapot(0.5);


    glFlush();
}

// void MyReshape(int NewWidth, int NewHeight){
//     printf("width, height : %d, %d\n",NewWidth,NewHeight);
//     glViewport(0,0,NewWidth, NewHeight);
//     GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
//     GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor,-1.0,-1.0);
// }


int main(int argc, char **argv){
    glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Teapot");
    glClearColor(1.0,0.0,0.0,1.0);
    // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    

    //////////change here to show display 1, 2////////////
    glutDisplayFunc(mydisplay1);
    // glutDisplayFunc(mydisplay2);
    // glutDisplayFunc(mydisplay3);
    // glutDisplayFunc(mydisplay4);



    // glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}