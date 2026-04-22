#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

//Exercício 2: Limitar o Movimento dentro da Tela
//Objetivo: Modifique o código base para impedir
//que o quadrado saia da área visível da janela.


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
        // Movimentação do jogador
        
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            if (jogadorY < limite) jogadorY += velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            if (jogadorY > -limite) jogadorY -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            if (jogadorX > -limite) jogadorX -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
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
