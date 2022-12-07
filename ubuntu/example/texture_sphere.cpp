#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define width 8
#define height 8

GLubyte MyTexture[width][height][3];

void fillMyTexture(){
    int s, t;
    for(s = 0; s <width; s++){
        for(t=0; t<height; t++){
            GLubyte Intensity = ((s+t)%2)*255;

            MyTexture[s][t][0] = Intensity;
            MyTexture[s][t][1] = Intensity;
            MyTexture[s][t][2] = Intensity;
        }
    }
}

void textureEnv(){
    fillMyTexture();

    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

    glEnable(GL_TEXTURE_2D);
}


void mydisplay(){

    glEnable(GL_DEPTH_TEST);

    textureEnv();

    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex3f(-0.5,-0.5,0);
    glTexCoord2f(0,1); glVertex3f(-0.5,0.5,0);
    glTexCoord2f(1,1); glVertex3f(0.5,0.5,0);
    glTexCoord2f(1,0); glVertex3f(0.5,-0.5,0);
    glEnd();
    
    
    glFlush();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("sphere");
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    
    glutDisplayFunc(mydisplay);

    glutMainLoop();
    return 0;  
}