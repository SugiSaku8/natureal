#version 120

varying vec4 particleColor;

void main() {
    float distance = length(gl_PointCoord - vec2(0.5));
    if (distance > 0.5) discard;
    gl_FragColor = particleColor;
} 