#version 330 core
in vec4 particleColor;
out vec4 FragColor;

void main() {
    float distance = length(gl_PointCoord - vec2(0.5));
    if (distance > 0.5) discard;
    FragColor = particleColor;
} 