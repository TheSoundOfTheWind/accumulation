#include <stdio.h>
#include <GL/glut.h>

int main(int argc, char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(300,300);

    glutInitWindowPosition(100,100);

    glutCreateWindow("OpenGL Version");
    const GLubyte* name = glGetString(GL_VENDOR);
    const GLubyte* biaoshifu = glGetString(GL_RENDERER); 
    const GLubyte* OpenGLVersion =glGetString(GL_VERSION);
    const GLubyte* gluVersion= gluGetString(GLU_VERSION); 
    printf("OpenGL Implementation vendor name: %s\n", name);
    printf("Render identifier: %s\n", biaoshifu);
    printf("OpenGL Version number of the implementation: %s\n",OpenGLVersion );
    printf("OGLUTool library version: %s\n", gluVersion);
    return 0;
}
