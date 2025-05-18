// shaders/particle.vert
#version 120

attribute vec3 position;
attribute vec3 velocity;
attribute vec4 color;

varying vec4 particleColor;

void main() {
    gl_Position = gl_ModelViewProjectionMatrix * vec4(position, 1.0);
    gl_PointSize = 5.0;
    particleColor = color;
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