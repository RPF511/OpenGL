#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define width 8
#define height 8

GLubyte MyTexture[width][height][3];
GLfloat ref_plane[] = {1.0,0.0,1.0,0.0};


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

void textureEnvAuto(){

    // glMatrixMode(GL_TEXTURE);
    // glLoadIdentity();
    // glRotatef(45,1,0,1);

    fillMyTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);
    
    // 
    // glTexGeni(GL_S,GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    // glTexGenfv(GL_S,GL_OBJECT_PLANE, ref_plane);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    
}



void mydisplay(){

    glEnable(GL_DEPTH_TEST);

    // textureEnv();

    glColor3f(1,0,0);
    // for quads
    // glBegin(GL_QUADS);
    // glTexCoord2f(0,0); glVertex3f(-0.5,-0.5,0);
    // glTexCoord2f(0,1); glVertex3f(-0.5,0.5,0);
    // glTexCoord2f(1,1); glVertex3f(0.5,0.5,0);
    // glTexCoord2f(1,0); glVertex3f(0.5,-0.5,0);
    // glEnd();

    textureEnvAuto();
    glutSolidSphere(0.5,400,400);
    
    
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