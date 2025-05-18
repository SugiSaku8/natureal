// shaders/particle.vert
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 particleColor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    particleColor = aColor;
    gl_PointSize = 5.0;
}

// shaders/particle.frag
#version 330 core
in vec4 particleColor;
out vec4 FragColor;

void main() {
    float distance = length(gl_PointCoord - vec2(0.5));
    if (distance > 0.5) discard;
    FragColor = particleColor;
}