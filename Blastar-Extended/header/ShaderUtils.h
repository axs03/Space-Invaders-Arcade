//
//  ShaderUtil.h
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/9/24.
//

#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

#include <GL/glew.h>
#include <iostream>

GLuint compileShader(const char* source, GLenum type);
GLuint createShaderProgram(const char* vertexSource, const char* fragmentSource);

#endif
