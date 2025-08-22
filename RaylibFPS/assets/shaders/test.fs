#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform vec3 viewPos;

// Output fragment color
out vec4 finalColor;

// NOTE: Add your custom variables here
void main() {
    vec4 texelColor = texture(texture0, fragTexCoord);
    
    float NdotL = dot(viewPos - fragPosition, fragNormal) / length(viewPos - fragPosition);

    finalColor = texelColor * colDiffuse * fragColor;
    finalColor.rgb *= NdotL;
}
