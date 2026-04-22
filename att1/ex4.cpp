#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

//Exercício 4: Mover com Setas do Teclado
//Objetivo: Use a função glutSpecialFunc() para controlar o quadrado com as setas do teclado.

float anguloTriangulo = 0.0f;
float jogadorX = 0.0f, jogadorY = 0.0f;
float velocidade = 0.02f;
float corR = 0.34f, corG = 0.49f, corB = 0.27f;

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
    glColor3f(corR, corG, corB);
    glVertex2f(jogadorX - 0.25f, jogadorY - 0.25f);
    glVertex2f(jogadorX + 0.25f, jogadorY - 0.25f);
    glVertex2f(jogadorX + 0.25f, jogadorY + 0.25f);
    glVertex2f(jogadorX - 0.25f, jogadorY + 0.25f);
    glEnd();
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
    float limite = 0.75f;

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
            corR = 0.3f; corG = 0.5f; corB = 0.3f; // Verde questionável
        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
            corR = 0.5f; corG = 0.3f; corB = 0.3f; // Vermelho questionável
        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
            corR = 0.3f; corG = 0.3f; corB = 0.5f; // Azul questionável
        }
        
        // Movimentação do jogador
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            if (jogadorY < limite) jogadorY += velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            if (jogadorY > -limite) jogadorY -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            if (jogadorX > -limite) jogadorX -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            if (jogadorX < limite) jogadorX += velocidade;
        }
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

        desenhaCena();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
