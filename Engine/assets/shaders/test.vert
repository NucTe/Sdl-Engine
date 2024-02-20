#version 330 core
layout (location = 0) in vec2 aPosition;
uniform vec4 rectColors[10]; // Assuming you have a maximum of 10 rectangles
flat out int rectIndex; // Pass the index of the rectangle to the fragment shader
void main() {
    gl_Position = vec4(aPosition, 0.0, 1.0);
    rectIndex = gl_VertexID / 6; // Assuming each rectangle is drawn with 6 vertices (2 triangles)
}
