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