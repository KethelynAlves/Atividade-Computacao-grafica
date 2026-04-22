#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

//Exercício 3: Mudar a Cor com Teclas Numéricas
//Objetivo: Permitir que o usuário altere a cor do quadrado com as teclas 1, 2, 3.

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
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

        desenhaCena();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
