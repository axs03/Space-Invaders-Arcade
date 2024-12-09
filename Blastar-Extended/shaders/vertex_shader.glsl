//
//  vertex_shader.glsl
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/9/24.
//

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
