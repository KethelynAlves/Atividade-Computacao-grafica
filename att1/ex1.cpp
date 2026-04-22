#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
//#include <GL/glut.h>
#include <cmath>

//adicionei o GLUT para comparação do que muda entre as bibliotecas

//Exercício 1: Mover um Círculo com o Teclado
//Objetivo: Trocar o quadrado por um círculo e movimentá-lo com as teclas W, A, S, D.

float anguloTriangulo = 0.0f;
float jogadorX = 0.0f, jogadorY = 0.0f;
float velocidade = 0.02f;

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.34f, 0.49f, 0.27f); 
    glVertex2f(jogadorX, jogadorY);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * 3.14159f / 180.0f;
        glVertex2f(jogadorX + (0.25f * cos(rad)*0.75f), jogadorY + 0.25f * sin(rad));
    }
    glEnd(); 

    //glutSwapBuffers();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Atividade círculo - Kethelyn", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window)) {
        // Movimentação do jogador
        
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) jogadorY += velocidade;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) jogadorY -= velocidade;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) jogadorX -= velocidade;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) jogadorX += velocidade;
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

        desenhaCena();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

/*
void keyboard(unsigned char key, int x, int y) {
    if (key == 'w' || key == 'W') { if (jogadorY < limite) jogadorY += velocidade; }
    if (key == 's' || key == 'S') { if (jogadorY > -limite) jogadorY -= velocidade; }
    if (key == 'a' || key == 'A') { if (jogadorX > -limite) jogadorX -= velocidade; }
    if (key == 'd' || key == 'D') { if (jogadorX < limite) jogadorX += velocidade; }
    
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Atividade GLUT - Kethelyn");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glutDisplayFunc(desenhaCena);
    glutKeyboardFunc(keyboard); // Registro da função de teclado

    glutMainLoop();
    return 0;
}
*/
