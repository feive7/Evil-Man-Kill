#version 330
in vec2 fragTexCoord;
in vec4 fragColor;
uniform sampler2D texture0;
uniform vec4 colDiffuse;
out vec4 finalColor;
const vec2 size = vec2(800, 450);
const float samples = 5.0;
const float quality = 2.5;

void main() {
    vec4 source = texture(texture0, fragTexCoord);
    finalColor = source*colDiffuse;
}