//
//  main.cpp
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/2/24.
//

#include "/opt/local/include/GL/glut.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Game.h"
#include "utils.h"
#include "Background.h"
#include "ShaderUtils.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

Player player = {400.0f, 50.0f, 50.0f, 50.0f};
vector<Projectile> bullets;
vector<Enemy> enemies;
vector<Explosion> explosions;

bool leftKeyPressed = false;
bool rightKeyPressed = false;

float screenShakeTime = 0.0f;


GLuint shaderProgram;
const char* vertexSource = R"(
#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_texCoords;

out vec2 v_texCoords;
out vec4 v_position;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
    v_texCoords = a_texCoords;
    v_position = u_model * vec4(a_position, 1.0);
    gl_Position = u_projection * u_view * v_position;
}
)";

const char* fragmentSource = R"(
#version 330 core

uniform sampler2D u_image;
uniform vec3 ambient_light; // set as (0.3, 0.3, 0.3), night!

in vec2 v_texCoords;
in vec4 v_position;

uniform vec2 point_light_pos;
uniform vec3 point_light_col;
uniform float point_light_intensity;

out vec4 FragColor;

void main() 
{
    vec4 frag_color = texture(u_image, v_texCoords);
    if(frag_color.a < 1.0)
        discard;

    float distance = length(point_light_pos - v_position.xy);
    float diffuse = 0.0;

    if (distance <= point_light_intensity)
        diffuse =  1.0 - abs(distance / point_light_intensity);

    FragColor = vec4(min(frag_color.rgb * ((point_light_col * diffuse) + ambient_light), frag_color.rgb), 1.0);
}
)";

void initShaders() {
    shaderProgram = createShaderProgram(vertexSource, fragmentSource);
}


void timer(int value) {
    movePlayer(player, leftKeyPressed, rightKeyPressed);
    updateBullets(bullets);
    updateEnemies(enemies);
    updateExplosions(explosions);

    checkCollisions(bullets, enemies, explosions);

    if (rand() % 500 < 5) {
        spawnEnemy(enemies);
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboardDown(unsigned char key, int x, int y) {
    if (key == 'a') leftKeyPressed = true;
    if (key == 'd') rightKeyPressed = true;
    if (key == ' ') fireBullet(bullets, player.x, player.y, player.width);
}

void keyboardUp(unsigned char key, int x, int y) {
    if (key == 'a') leftKeyPressed = false;
    if (key == 'd') rightKeyPressed = false;
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); // fixes viewport moving down after shake

    // screen shake effect
    if (screenShakeTime > 0.0f) {
        float shakeAmount = 5.0f; // shake intensity
        float offsetX = (rand() % 100 / 100.0f - 0.5f) * shakeAmount;
        float offsetY = (rand() % 100 / 100.0f - 0.5f) * shakeAmount;
        glTranslatef(offsetX, offsetY, 0.0f);
        screenShakeTime -= 0.016f;
    }

    glUseProgram(shaderProgram);

    // Set the ambient light
    GLint ambientLightLoc = glGetUniformLocation(shaderProgram, "ambient_light");
    glUniform3f(ambientLightLoc, 0.3f, 0.3f, 0.3f);

    // Set the point light properties
    GLint pointLightPosLoc = glGetUniformLocation(shaderProgram, "point_light_pos");
    glUniform2f(pointLightPosLoc, -0.4f, 0.3f);

    GLint pointLightColLoc = glGetUniformLocation(shaderProgram, "point_light_col");
    glUniform3f(pointLightColLoc, 0.999f, 0.999f, 0.999f);

    GLint pointLightIntensityLoc = glGetUniformLocation(shaderProgram, "point_light_intensity");
    glUniform1f(pointLightIntensityLoc, 0.4f);

    // Set the texture
    GLint imageLoc = glGetUniformLocation(shaderProgram, "u_image");
    glUniform1i(imageLoc, 0); // Texture unit 0

    // Bind the texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, player.textureID);

    // Set model, view, and projection matrices
    GLint modelLoc = glGetUniformLocation(shaderProgram, "u_model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "u_view");
    GLint projectionLoc = glGetUniformLocation(shaderProgram, "u_projection");

    glm::mat4 modelMatrix = glm::mat4(1.0f); // model matrix
    glm::mat4 viewMatrix = glm::mat4(1.0f); // view matrix
    glm::mat4 projectionMatrix = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f); // projection matrix

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    // Draw your objects
    drawPlayer(player, 180);
    drawBullets(bullets);
    drawEnemies(enemies);
    drawStars();
    drawExplosions(explosions);

    glUseProgram(0);

    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    srand(time(0));
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Blastar Extended");

    glewInit();

    initShaders();

    initStars(150);
    init(player, enemies);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}

