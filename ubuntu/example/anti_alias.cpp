#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


bool bAlias = false;


void mydisplay(){
    //DEPTH BUFFER CLEAR
    glClear(GL_COLOR_BUFFER_BIT);

    //blendig On
    glEnable(GL_BLEND);

    if(bAlias){
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    }
    else{
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

    glPointSize(10);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(0,0.8);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8,0.7);
    glVertex2f(0.8,0.5);
    glEnd();
    
    glFlush();
}

void Menu(int value){
    switch (value) {
        case 1 :
            bAlias = true;
            break;
        case 2 :
            bAlias = false;
            break;
        default :
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
    glutAddMenuEntry("Alias ON",1);
    glutAddMenuEntry("Alias OFF",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;  
}