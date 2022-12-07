#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


bool bAlias = false;

void init_light(void){
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    // GLfloat lit_pos[4] = {0,0,0,0};
    // GLfloat lit_amb[4] = {0.5,0,0,0};
    GLfloat lit_pos[4] = {5,5,-8,1}; 
    GLfloat lit_dif[4] = {0.5,0,0,0}; 
    GLfloat lit_spc[4] = {1,1,1,0};
    

    glLightfv(GL_LIGHT0, GL_POSITION, lit_pos);
    // glLightfv(GL_LIGHT0,GL_AMBIENT, lit_amb);
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lit_spc);
}

void mydisplay(){

    glEnable(GL_DEPTH_TEST);
    // GLfloat mat_amb[4] = {0.3,0,0,0}; //amb reflection
    GLfloat mat_dif[4] = {1,0,0,0};

    GLfloat mat_spc[4] = {0.5,0.5,0.5,0};
    GLfloat mat_emi[4] = {0.5,0,0,0};
    GLfloat mat_shi[1] = {10};

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb);
    // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif);

    //texture
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spc);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emi);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shi);


    glTranslatef(0,0,-15);

    glutSolidTorus(2,7,100,100);
    
    glFlush();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("LIGHT");
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    
    glutDisplayFunc(mydisplay);
    init_light();

    glutMainLoop();
    return 0;  
}