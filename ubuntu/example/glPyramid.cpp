#include <stdio.h>
#include <GL/glut.h>

GLfloat MyVertices[][3] = {{0.0, 0.5, 0.0},{-0.5, -0.5, 0.5},{0.5, -0.5, 0.5},{0.5, -0.5, -0.5},{0.5, -0.5, -0.5}};
GLfloat MyColors [][3] = {{1,1,0},{0,1,0},{0,0,1},{1,0,1},{0,1,1}};
// GLubyte MyVertexList[] = {0,1,2,  0,2,3,  0,3,4,  0,4,1,  1,4,3,2};
GLubyte MyVertexList[] = {0,1,2,5,3,4};

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);

    glRotatef(30.0,1.0,1.0,1.0);
    // for(GLint i = 0 ; i < 5 ; i++){
    //     glDrawElements(GL_TRIANGLE_FAN,4, GL_UNSIGNED_BYTE, &MyVertexList[3*i]);
    // }
    //or
    glDrawElements(GL_TRIANGLE_FAN, 6, GL_UNSIGNED_BYTE, &MyVertexList);

    glFlush();
}
void mydisplayex(){
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