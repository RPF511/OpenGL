#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define width 8
#define height 8
#define MOUSE_SENSITIVITY 0.1

GLint onClick = 0;
GLint initX = 0;
GLint initY = 0;
GLfloat rotate_angle_x = 0;
GLfloat rotate_angle_y = 0;


void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glRotatef(rotate_angle_x,0,1,0);
    glRotatef(rotate_angle_y,1,0,0);
    glutWireCube(0.7);
    
    
    glFlush();
}

void mouseButton(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        onClick = 1;
        initX = x;
        initY = y;
    }else{
        onClick = 0;
    }
}

void mouseMotion(int x, int y){
    if(onClick){
        // printf("%d %d\n",x,y);
        rotate_angle_x =(GLfloat) ((x - initX)*MOUSE_SENSITIVITY + 360);
        if(rotate_angle_x > 360) rotate_angle_x -= 360;
        rotate_angle_y =(GLfloat) ((y - initY)*MOUSE_SENSITIVITY + 360);
        if(rotate_angle_y > 360) rotate_angle_y -= 360;
        glutPostRedisplay();
    }
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("sphere");
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);

    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);
    
    glutDisplayFunc(mydisplay);


    glutMainLoop();
    return 0;  
}