#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

//Exercício 5: Múltiplos Objetos Independentes
//Objetivo: Adicione dois quadrados com cores diferentes. Use teclas WASD para mover um, e 
//IJKL para mover o outro.

float anguloTriangulo = 0.0f;
float jogadorX = -0.5f, jogadorY = 0.0f;
float jogador2X = 0.5f, jogador2Y = 0.5f;
float velocidade = 0.02f;

void desenhaQuadrado(float x, float y, float r, float g, float b) {
    glPushMatrix();

    glTranslated(x, y, 0.0f);
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f( 0.1f, -0.1f);
    glVertex2f( 0.1f,  0.1f);
    glVertex2f(-0.1f,  0.1f);
    glEnd();

    glPopMatrix();
}

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    desenhaQuadrado(jogadorX, jogadorY, 0.3f, 0.5f, 0.3f); // Quadrado 1
    desenhaQuadrado(jogador2X, jogador2Y, 0.5f, 0.3f, 0.3f); // Quadrado 2
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

        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
            if (jogador2Y < limite) jogador2Y += velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
            if (jogador2Y > -limite) jogador2Y -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
            if (jogador2X > -limite) jogador2X -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            if (jogador2X < limite) jogador2X += velocidade;
        }
        
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

        desenhaCena();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
