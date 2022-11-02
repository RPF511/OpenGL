//Reshape several Viewports by using global variables

#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


GLfloat MyMatrix[16];


void mydisplay(){
    
    glClear(GL_COLOR_BUFFER_BIT);

    // glMatrixMode(GL_MODELVIEW);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glTranslatef(3.0,4.0,0.0);
    glTranslatef(0.0,0.0,1.0);

    glGetFloatv(GL_MODELVIEW_MATRIX, MyMatrix);

    for(int i = 0; i< 16 ; i++){
        if(i%4 == 0){
            printf("\n");
            
        }
        printf("%7d = %.1f",i, MyMatrix[i]);
    }
    putchar('\n');


    glFlush();
}


void MyReshape(int NewWidth, int NewHeight){
    //printf("width, height : %d, %d\n",NewWidth,NewHeight);
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