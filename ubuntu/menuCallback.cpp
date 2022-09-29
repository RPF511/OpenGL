#include <stdio.h>
#include <GL/glut.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;

void mydisplay(){
    // glClearColor(0.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,0.0,0.5);
    // if (IsSphere)
    //     glutWireSphere(0.2,15,15);
    // else
    //     glutWireTorus(0.1,0.3,40,20);

    if (IsSmall){
        if (IsSphere)
            glutWireSphere(0.2,15,15);
        else
            glutWireTorus(0.1,0.3,40,20);
    }else{
        if (IsSphere)
            glutWireSphere(0.4,15,15);
        else
            glutWireTorus(0.2,0.5,40,20);
    }
    
    glFlush();


}

void MySubMenu(int entryID){
    if(entryID == 1)
        IsSmall = true;
    else if (entryID == 2)
        IsSmall = false;
    glutPostRedisplay();
}

void MyMainMenu(int entryID){
    if(entryID == 1)
        IsSphere = true;
    else if (entryID == 2)
        IsSphere = false;
    else if (entryID == 3)
        exit(0);
    glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500, 100);
    glutCreateWindow("MenuCallback");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySubMenuID = glutCreateMenu(MySubMenu);
    glutAddMenuEntry("Small", 1);
    glutAddMenuEntry("Big", 2);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("Draw Sphere", 1);
    glutAddMenuEntry("Draw Torus", 2);
    glutAddSubMenu("Change Size", MySubMenuID);
    glutAddMenuEntry("Exit", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}