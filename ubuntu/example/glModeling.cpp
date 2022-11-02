#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    // glPointSize(10.0);
    // glBegin(GL_POINTS);
    //     glVertex2f(-0.5,-0.5);
    //     glVertex2f(0.5,-0.5);
    //     glVertex2f(0.5,0.5);
    //     glVertex2f(-0.5,0.5);
    // glEnd();

    // glLineWidth(5.0);
    // glBegin(GL_LINES);
    //     glVertex2f(-0.5,-0.5);
    //     glVertex2f(0.5,-0.5);
    //     glVertex2f(0.5,0.5);
    //     glVertex2f(-0.5,0.5);
    // glEnd();
    // glBegin(GL_LINES);
    //     glVertex2f(-0.3,-0.3);
    //     glVertex2f(0.3,0.3);
    //     glVertex2f(0.3,-0.3);
    //     glVertex2f(-0.3,0.3);
    // glEnd();

    // glLineWidth(5.0);
    // glBegin(GL_LINE_STRIP);
    //     glVertex2f(-0.5-0.2,-0.5-0.2);
    //     glVertex2f(-0.5+0.2,-0.5-0.2);
    //     glVertex2f(-0.5+0.2,-0.5+0.2);
    //     glVertex2f(-0.5-0.2,-0.5+0.2);
    // glEnd();
    // glBegin(GL_LINE_STRIP);
    //     glVertex2f(0.5-0.2,-0.5+0.2);
    //     glVertex2f(0.5+0.2,-0.5-0.2);
    //     glVertex2f(0.5+0.2,-0.5+0.2);
    //     glVertex2f(0.5-0.2,-0.5-0.2);
    // glEnd();
    // glBegin(GL_LINE_STRIP);
    //     glVertex2f(-0.5-0.2,0.5-0.2);
    //     glVertex2f(-0.5-0.2,0.5+0.2);
    //     glVertex2f(-0.5+0.2,0.5-0.2);
    //     glVertex2f(-0.5+0.2,0.5+0.2);
    // glEnd();
    // glBegin(GL_LINE_STRIP);
    //     glVertex2f(0.5-0.2,0.5-0.2);
    //     glVertex2f(0.5-0.2,0.5+0.2);
    //     glVertex2f(0.5+0.2,0.5+0.2);
    //     glVertex2f(0.5+0.2,0.5-0.2);
    // glEnd();

    glLineWidth(3.0);
    // glBegin(GL_LINE_LOOP);
    //     glVertex2f(-0.5-0.3,0.5-0.3);
    //     glVertex2f(-0.5+0.3,0.5-0.3);
    //     glVertex2f(-0.5+0.3,0.5+0.3);
    //     glVertex2f(-0.5-0.3,0.5+0.3);
    //     glVertex2f(-0.5-0.3,0.5+0.4);
    //     glVertex2f(-0.5-0.2,0.5+0.4);
    // glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(0.5-0.3,0.5-0.3);
        glVertex2f(0.5+0.3,0.5-0.3);
        glVertex2f(0.5+0.3,0.5+0.3);
        glVertex2f(0.5-0.3,0.5+0.3);
        glVertex2f(0.5-0.3,0.5+0.4);
        glVertex2f(0.5-0.2,0.5+0.4);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5-0.3,-0.5-0.3);
        glVertex2f(-0.5+0.3,-0.5-0.3);
        glVertex2f(-0.5+0.3,-0.5+0.3);
        glVertex2f(-0.5-0.3,-0.5+0.3);
        glVertex2f(-0.5-0.3,-0.5+0.4);
        glVertex2f(-0.5-0.2,-0.5+0.4);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.5-0.3,-0.5-0.3);
        glVertex2f(0.5+0.3,-0.5-0.3);
        glVertex2f(0.5+0.3,-0.5+0.3);
        glVertex2f(0.5-0.3,-0.5+0.42);
        glVertex2f(0.5-0.4,-0.5+0.3);
        glVertex2f(0.5-0.1,-0.5+0.45);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.5-0.3,0.5-0.3);
        glVertex2f(-0.5+0.3,0.5-0.3);
        glVertex2f(-0.5+0.3,0.5+0.3);
        glVertex2f(-0.5-0.3,0.5+0.3);
        glVertex2f(-0.5-0.3,0.5+0.4);
        glVertex2f(-0.5-0.2,0.5+0.4);
    glEnd();

    

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Drawing Example");
    
    glutDisplayFunc(mydisplay);
    glOrtho(0.0,0.0,1.0,1.0,-1.0,1.0);
    glutMainLoop();
    return 0;  
}