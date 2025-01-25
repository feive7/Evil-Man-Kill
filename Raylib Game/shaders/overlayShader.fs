#version 330
in vec2 fragTexCoord;
in vec4 fragColor;
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform float time;
out vec4 finalColor;
const vec2 size = vec2(800, 450);
const float samples = 5.0;
const float quality = 2.5;
vec2 snap(vec2 vec, float n) {
    return floor(vec * n) / n;
}
void main() {
    vec2 coords = fragTexCoord;
    vec4 source = texture(texture0, coords);
    finalColor = source*colDiffuse;
}