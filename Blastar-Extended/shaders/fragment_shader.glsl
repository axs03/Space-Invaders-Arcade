//
//  fragment_shader.glsl
//  Blastar-Extended
//
//  Created by Aman Sahu on 12/9/24.
//

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
