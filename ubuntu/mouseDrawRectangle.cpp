#include <stdio.h>
#include <GL/glut.h>

GLfloat TopLeftX = 0.0; GLfloat TopLeftY = 0.0; GLfloat BottomRightX = 0.0; GLfloat BottomRightY = 0.0;
GLint ViewportX=300; GLint ViewportY=300;
// int isDraw = 0;

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glViewport(0,0,ViewportX,ViewportY);
    glClear(GL_COLOR_BUFFER_BIT);
    // //viewport 300 150
    

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
        glVertex3f(TopLeftX / ViewportX, (ViewportY - TopLeftY) / ViewportY, 0.0);
        glVertex3f(TopLeftX / ViewportX, (ViewportY - BottomRightY) / ViewportY, 0.0);
        glVertex3f(BottomRightX / ViewportX, (ViewportY - BottomRightY) / ViewportY, 0.0);
        glVertex3f(BottomRightX / ViewportX, (ViewportY - TopLeftY) / ViewportY, 0.0);
    glEnd();


    glFlush();
}


void myReshape(int NewWidth, int NewHeight){
    // printf("width, height : %d, %d\n",NewWidth,NewHeight);
    glViewport(0,0,NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat) NewWidth / (GLfloat) 300;
    GLfloat HeightFactor = (GLfloat) NewHeight / (GLfloat) 300;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor,-1.0,-1.0);
}

void myMouseClick(GLint Button, GLint State, GLint X, GLint Y){
    // if(isDraw) isDraw = 0;
    // else isDraw = 1;
    // printf("isDraw %d\n",isDraw);
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN){
        TopLeftX = X;
        TopLeftY = Y;
    }
}

void MyMouseDraw(GLint X, GLint Y){
    BottomRightX = X;
    BottomRightY = Y;
    glutPostRedisplay();
    // if(isDraw){
    //     BottomRightX = X;
    //     BottomRightY = Y;
    //     glutPostRedisplay();
    // }
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    glutCreateWindow("OpenGL Sample DisplayWinodw");
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
    // //viewport 300 150
    // glOrtho(-2.0,2.0,-1.0,1.0,-1.0,1.0);
    
    glutDisplayFunc(mydisplay);
    glutMouseFunc(myMouseClick);
    glutMotionFunc(MyMouseDraw);
    // glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}