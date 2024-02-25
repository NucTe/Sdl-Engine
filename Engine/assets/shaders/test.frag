#version 330 core
flat in int rectIndex;
uniform vec4 rectColors[10];
out vec4 FragColor;

void main() {
    if (rectIndex == -1) {
        FragColor = vec4(1.0);
    } else {
        FragColor = rectColors[rectIndex];
    }
}
