#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat xAngle, yAngle;
GLboolean bDepthTest = GL_TRUE;
GLboolean bCullFace = GL_FALSE;
GLboolean iOutline = GL_FALSE;

void MenuCheck(){
    if (bDepthTest)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
    
    if(bCullFace){
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
    }else
        glDisable(GL_CULL_FACE);

    if (!iOutline)
        glPolygonMode(GL_FRONT,GL_LINE);
    else
        glPolygonMode(GL_FRONT,GL_FILL); 
}

void mydisplay(){
    //DEPTH BUFFER CLEAR
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrontFace(GL_CCW);

    MenuCheck();

    glPushMatrix();
    glRotatef(xAngle,1,0,0);
    glRotatef(yAngle,0,1,0);

    glBegin(GL_QUADS);

    glColor3f(1,1,1);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(0.5,-0.5,-0.5);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,-0.5);

    glColor3f(1,0,0);
    glVertex3f(0.5,0.5,-0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,-0.5);

    glColor3f(0,1,0);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,-0.5);
    
    glColor3f(0,0,1);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(-0.5,-0.5,0.5);

    glColor3f(1,1,0);
    glVertex3f(-0.5,0.5,-0.5);
    glVertex3f(-0.5,0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glVertex3f(0.5,0.5,-0.5);

    glColor3f(0,1,1);
    glVertex3f(-0.5,-0.5,-0.5);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,-0.5);

    glEnd();

    glPopMatrix();

    
    glFlush();
}

void Menu(int value){
    switch (value) {
        case 1 :
            bDepthTest = !bDepthTest;
            break;
        case 2 :
            bCullFace = !bCullFace;
            break;
        case 3 :
            iOutline = !iOutline;
            break;
        default :
            break;
    }
    glutPostRedisplay();
}

void KeyBoard(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            xAngle += 2;
            break;
        case GLUT_KEY_DOWN:
            xAngle -= 2;
            break;
        case GLUT_KEY_LEFT:
            yAngle += 2;
            break;
        case GLUT_KEY_RIGHT:
            yAngle -= 2;
            break;

    }
    glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Cube");
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    
    glMatrixMode(GL_PROJECTION);
    
    glutCreateMenu(Menu);
    glutAddMenuEntry("Depth Test",1);
    glutAddMenuEntry("Cull BackFace",2);
    glutAddMenuEntry("Outline Back",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(mydisplay);
    glutSpecialFunc(KeyBoard);

    glutMainLoop();
    return 0;  
}