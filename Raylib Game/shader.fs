#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

void main() {
    vec4 texelColor = texture(texture0, fragTexCoord);
    float r = texelColor.r;
    float g = texelColor.g;
    float b = texelColor.b;
    float l = (r+g+b)/3;
    texelColor = texelColor + .1 * vec4(fragTexCoord.x,fragTexCoord.y,1,1);
    finalColor = texelColor * fragColor * colDiffuse;
}