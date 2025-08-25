#include <assets/textures/tile_1.h>
#include <assets/textures/tile_2.h>
#include <assets/textures/tile_3.h>
#include <assets/textures/tile_4.h>
#include <assets/textures/tile_5.h>
#include <assets/textures/tile_6.h>
#include <assets/textures/npc_john.h>
#include <assets/textures/npc_john_crouch.h>
#include <assets/textures/npc_john_victory.h>
#include <assets/audio/bitgunshot.h>
#include <assets/audio/hit01.h>
#include <assets/audio/step.h>
#define MAIN_VERTEX_SHADER R"(#version 330

in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;
in vec4 vertexColor;

uniform mat4 mvp;
uniform mat4 matModel;
uniform mat4 matNormal;

out vec3 fragPosition;
out vec2 fragTexCoord;
out vec4 fragColor;
out vec3 fragNormal;

void main() {
	fragPosition = vec3(matModel * vec4(vertexPosition, 1.0));
	fragTexCoord = vertexTexCoord;
	fragColor = vertexColor;
	fragNormal = normalize(vec3(matNormal * vec4(vertexNormal, 1.0)));

	gl_Position = mvp * vec4(vertexPosition, 1.0);
})"
#define MAIN_FRAGMENT_SHADER R"(#version 330

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
    
    if(texelColor.a < 0.9) discard;

    float NdotL = dot(viewPos - fragPosition, fragNormal) / length(viewPos - fragPosition) * 2.5;
    //float NdotL = 1.0;

    finalColor = texelColor * colDiffuse * fragColor;
    finalColor.rgb *= NdotL;
})"
void ConvertImageToCode(const char* filename) {
	Image img = LoadImage(filename);
	std::string truefilename(GetFileNameWithoutExt(filename));
	std::string filepath(GetDirectoryPath(filename));
	std::string outfilename = filepath + "/" + truefilename + ".h";
	ExportImageAsCode(img, outfilename.c_str());
}
void ConvertWaveToCode(const char* filename) {
	Wave wav = LoadWave(filename);
	std::string truefilename(GetFileNameWithoutExt(filename));
	std::string filepath(GetDirectoryPath(filename));
	std::string outfilename = filepath + "/" + truefilename + ".h";
	ExportWaveAsCode(wav, outfilename.c_str());
}
Texture LoadTextureFromCode(void* data, int width, int height) {
	Image img = {
		.data = data,
		.width = width,
		.height = height,
		.mipmaps = 1,
		.format = 4,
	};
	Texture texture = LoadTextureFromImage(img);
	return texture;
}
Sound LoadSoundFromCode(void* data, unsigned int frameCount, unsigned int sampleRate, unsigned int sampleSize, unsigned int channels) {
	Wave wav = {
		.frameCount = frameCount,
		.sampleRate = sampleRate,
		.sampleSize = sampleSize,
		.channels = channels,
		.data = data,
	};
	Sound sound = LoadSoundFromWave(wav);
	return sound;
}
void LoadGlob() {
	// Textures
	tex_john = LoadTextureFromCode(NPC_JOHN_DATA, NPC_JOHN_WIDTH, NPC_JOHN_HEIGHT);
	tex_john_victory = LoadTextureFromCode(NPC_JOHN_VICTORY_DATA, NPC_JOHN_VICTORY_WIDTH, NPC_JOHN_VICTORY_HEIGHT);
	tex_john_crouch = LoadTextureFromCode(NPC_JOHN_CROUCH_DATA, NPC_JOHN_CROUCH_WIDTH, NPC_JOHN_CROUCH_HEIGHT);
	TILE_1 = LoadTextureFromCode(TILE_1_DATA, TILE_1_WIDTH, TILE_1_HEIGHT);
	TILE_2 = LoadTextureFromCode(TILE_2_DATA, TILE_2_WIDTH, TILE_2_HEIGHT);
	TILE_3 = LoadTextureFromCode(TILE_3_DATA, TILE_3_WIDTH, TILE_3_HEIGHT);
	TILE_4 = LoadTextureFromCode(TILE_4_DATA, TILE_4_WIDTH, TILE_4_HEIGHT);
	TILE_5 = LoadTextureFromCode(TILE_5_DATA, TILE_5_WIDTH, TILE_5_HEIGHT);
	TILE_6 = LoadTextureFromCode(TILE_6_DATA, TILE_6_WIDTH, TILE_6_HEIGHT);

	// Shaders
	shader_main = LoadShaderFromMemory(MAIN_VERTEX_SHADER, MAIN_FRAGMENT_SHADER);
	shader_main_viewpos_loc = GetShaderLocation(shader_main, "viewPos");
	shader_debug_normals = LoadShader("assets/shaders/normal.vs", "assets/shaders/normal.fs");

	// Sounds
	snd_gunshot = LoadSoundFromCode(BITGUNSHOT_DATA, BITGUNSHOT_FRAME_COUNT, BITGUNSHOT_SAMPLE_RATE, BITGUNSHOT_SAMPLE_SIZE, BITGUNSHOT_CHANNELS);
	snd_hit = LoadSoundFromCode(HIT01_DATA, HIT01_FRAME_COUNT, HIT01_SAMPLE_RATE, HIT01_SAMPLE_SIZE, HIT01_CHANNELS);
	snd_step = LoadSoundFromCode(STEP_DATA, STEP_FRAME_COUNT, STEP_SAMPLE_RATE, STEP_SAMPLE_SIZE, STEP_CHANNELS);
	snd_land = LoadSound("assets/audio/jumpland.wav");
	//snd_land = LoadSoundFromCode(STEP_DATA, STEP_FRAME_COUNT, STEP_SAMPLE_RATE, STEP_SAMPLE_SIZE, STEP_CHANNELS);

	// Music
	music_main = LoadMusicStream("assets/audio/fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("assets/audio/lost_town.mp3");
	music_lose.looping = true;
}