#version 330 core
flat in int rectIndex; // Input index of the rectangle
uniform vec4 rectColors[10]; // Same array of colors
out vec4 FragColor;
void main() {
    FragColor = rectColors[rectIndex]; // Use the color based on the index
}
