#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
//#include <GL/glut.h>
#include <cmath>

/*
Objetivo: Usar as primitivas de linha do OpenGL e modificar o estado do 
rasterizador para alterar como os pixels são desenhados. - - - - 
Crie uma janela básica usando GLUT. 
Dentro da função de desenho (display), utilize a primitiva GL_LINES para 
desenhar o contorno de uma nave espacial simples (ou um controle de 
videogame) usando apenas retas conectadas. 
Use a função glLineWidth(5.0f); antes do glBegin e observe o que 
acontece com a espessura. 
Ative o modo de linha tracejada usando glEnable(GL_LINE_STIPPLE); e 
configure o padrão com glLineStipple(1, 0x00FF);. Rode o programa 
e veja como o OpenGL "quebra" a rasterização da reta. 
*/

void desenhaCena() {
    glLineWidth(5.0f);
    glLineStipple(1, 0x00FF);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.5f, 0.3f);
        glVertex2f(0.5f, 0.3f);
    glEnd(); 

    glDisable(GL_LINE_STIPPLE);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.9f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.5f, -0.9f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);


    glLineWidth(3.0f);
    glLineStipple(1, 0x00FF);
    
    glEnable(GL_LINE_STIPPLE);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 210; i <= 330; i += 5) {
            float rad = i * M_PI / 180.0f;
            float x = 0.6f * cos(rad);
            float y = 0.6f * sin(rad) + 0.6f;
            glVertex2f(x, y);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for (int i = 30; i <= 150; i += 5) {
            float rad = i * M_PI / 180.0f;
            float x = 0.6f * cos(rad);
            float y = 0.6f * sin(rad);
            glVertex2f(x, y);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for (int i = 10; i <= 170; i += 5) {
            float rad = i * M_PI / 180.0f;
            float x = 0.25f * cos(rad);
            float y = 0.5f * sin(rad) + 0.45f;
            glVertex2f(x, y);
        }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Atividade Nave do Vale - Kethelyn", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        desenhaCena();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



/* 

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5.0f);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    //linha do meio
    glVertex2f(-0.5f, 0.3f);
    glVertex2f(0.5f, 0.3f);
    glEnd(); 
    
    glDisable(GL_LINE_STIPPLE);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.9);//esquerda
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.9f);//direita 
    
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.0f);//ponta
        glEnd();
        
    glDisable(GL_LINE_STIPPLE);
}

void desenhaCurvas() {
    glLineWidth(3.0f);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    
    //curva base
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 210; i <= 330; i += 5) {
        float rad = i * M_PI / 180.0f;
        float x = 0.6f * cos(rad);
        float y = 0.6f * sin(rad)+0.6f;//+0.2f
        glVertex2f(x, y);
    }
    glEnd();
    
    //curva teto
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 30; i <= 150; i += 5) {
            float rad = i * M_PI / 180.0f;
            float x = 0.6f * cos(rad);
            float y = 0.6f * sin(rad);
            glVertex2f(x, y);
        }
        glEnd();

        //capsula
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        for (int i = 10; i <= 170; i += 5) {
            float rad = i * M_PI / 180.0f;
            float x = 0.25f * cos(rad);
            float y = 0.5f * sin(rad)+0.45f;//+0.05f
            glVertex2f(x, y);
        }
        glEnd();
    }
    
    
    void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaCena();
    desenhaCurvas();
    glutSwapBuffers();
}

void inicializa() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundo preto
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Atividade Nave do Vale - Kethelyn");

    glutDisplayFunc(display);
    
    inicializa();
    
    glutMainLoop();
    
    return 0;
}

*/