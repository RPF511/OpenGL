#include <stdio.h>
#include <GL/glut.h>

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glBegin(GL_TRIANGLES);
        //front
        glColor3f(1.0,0.0,0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);

        //right
        glColor3f(0.0,1.0,0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, -0.5);

        //back
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, -0.5);

        //left
        glColor3f(1.0,0.0,1.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        
    glEnd();
    
    
    

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutCreateWindow("Drawing Example");
    
    glutDisplayFunc(mydisplay);
    // glOrtho(0.0,0.0,1.0,1.0,-1.0,1.0);
    glRotatef(30,1,1,1);
    
    glutMainLoop();
    return 0;  
}