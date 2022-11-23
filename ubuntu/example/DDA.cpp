
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void DrawPixel(int x, int y){
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void LineDraw(float x1, float y1, float x2, float y2){
    float m,x,y;
    float dx = x2-x1;
    float dy = y2-y1;
    m = dy /dx;
    y = y1;

    if (m < 1){
        for (float x = x1; x <= x2 ; x ++){
            DrawPixel(x, round(y));
            y+= m;
        }
    }
}

void mydisplay(){
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,0,0);
    LineDraw(25,25,80,70);

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Drawing Example");
    glutDisplayFunc(mydisplay);
    glLoadIdentity();

    gluOrtho2D(0,100,0,100);
    
    glutMainLoop();
    return 0;
}