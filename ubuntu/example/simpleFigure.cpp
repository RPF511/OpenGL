//Reshape several Viewports by using global variables

#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


int Width, Height;

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    // glViewport(0,0,300,150);

    glRotatef(30,1,1,1);
    glViewport(0,0,Width/2,Height/2);
    glColor3f(1, 1, 1);
    glutWireSphere(0.5,10,6);
    

    glViewport(Width/2, Height/2, Width/2, Height/2);
    glColor3f(1, 1, 1);
    glutWireTorus(0.2,0.7,5,10);
    

    glFlush();
}


void MyReshape(int NewWidth, int NewHeight){
    printf("width, height : %d, %d\n",NewWidth,NewHeight);
    Width = NewWidth;
    Height = NewHeight;
    glViewport(0,0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
    GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor,-1.0,-1.0);
}




int main(int argc, char **argv){

    // int weight, height;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    glutCreateWindow("OpenGL Sample DisplayWinodw");
    glClearColor(0.5,0.0,0.7,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
    // //viewport 300 150
    // glOrtho(-2.0,2.0,-1.0,1.0,-1.0,1.0);
    
    glutDisplayFunc(mydisplay);
    
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}

