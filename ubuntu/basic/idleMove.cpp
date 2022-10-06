#include <stdio.h>
#include <GL/glut.h>

unsigned char key;
GLfloat dotx = 0.0;
GLfloat doty = 0.0;

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    //middle (0,0)
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,-0.5,0.0);
        glVertex3f(0.5,-0.5,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(-0.5,0.5,0.0);
    glEnd();

    //dot
    glColor3f(1,0,0);
    glPointSize(10);
    glBegin(GL_POINTS);
    // printf("%.3f %.3f\n",dotx,doty);
    glVertex2f(dotx,doty);
    glEnd();

    //when using double buffer;
    glutSwapBuffers();
    // glFlush();
}

void myKeyboardDown(unsigned char KeyPressed , int x, int y){
    key = KeyPressed;
    switch (KeyPressed){
        case 27:
        case 3:
            exit(0); break;
        case 'W':
        case 'w':
            doty = doty + 0.1; mydisplay();break;
        case 'S':
        case 's':
            doty = doty - 0.1; mydisplay();break;
        case 'D':
        case 'd':
            dotx = dotx + 0.1; mydisplay();break;
        case 'A':
        case 'a':
            dotx = dotx - 0.1; mydisplay();break;
        default:
            // mydisplay();
            // printf("key pressed : %5d %5c\n",KeyPressed,KeyPressed); 
            break;
    }
}

void MyIdle(){
    dotx += 0.001;
    glutPostRedisplay();
}

void MyTimer(int Value){
    printf("value : %d\n",Value);
    Value++;
    if(Value ==30){
        Value = 0;
        dotx = 0.0;
    }
    dotx += 0.01;
    glutPostRedisplay();
    glutTimerFunc(40, MyTimer,Value);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Drawing Example");
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(myKeyboardDown);
    // glutIdleFunc(MyIdle);
    glutTimerFunc(40,MyTimer,1);
    glutMainLoop();
    return 0;
}