#version 330 core
layout (location = 0) in vec2 aPosition;
uniform mat4 viewProjection;
out vec2 fragTexCoord;

void main() {
    gl_Position = viewProjection * vec4(aPosition, 0.0, 1.0);
    fragTexCoord = aPosition;
}
