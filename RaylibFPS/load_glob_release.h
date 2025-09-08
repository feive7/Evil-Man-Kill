#include <assets/textures/TILE_1.h>
#include <assets/textures/TILE_2.h>
#include <assets/textures/TILE_3.h>
#include <assets/textures/TILE_4.h>
#include <assets/textures/TILE_5.h>
#include <assets/textures/TILE_6.h>
#include <assets/textures/npc_john.h>
#include <assets/textures/npc_john_crouch.h>
#include <assets/textures/npc_john_victory.h>
#include <assets/textures/NOISE_1.h>
#include <assets/textures/BRICK.h>
#include <assets/textures/METAL.h>
#include <assets/textures/MARBLE.h>
#include <assets/textures/PLASTER.h>
#include <assets/textures/CARDBOARD.h>
#include <assets/textures/WOOD.h>
#include <assets/textures/WOOD_floor.h>
#include <assets/textures/FABRIC.h>
#include <assets/textures/GRASS.h>
#include <assets/textures/gravel.h>
#include <assets/textures/stone.h>
#include <assets/textures/item_drumstick.h>
#include <assets/audio/bitgunshot.h>
#include <assets/audio/hit01.h>
#include <assets/audio/step.h>
#include <assets/audio/coin.h>
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
uniform vec3 viewTarget;

// Output fragment color
out vec4 finalColor;
float fakelight(vec3 normal, vec3 direction) {
    float matcap = -dot(normal,direction);
    return matcap * 0.5 + 0.453;
}
// NOTE: Add your custom variables here
void main() {
    vec4 texelColor = texture(texture0, fragTexCoord);
    if(texelColor.a < 0.9) discard;

    // Direction from fragment to camera
    vec3 toView = normalize(viewTarget - viewPos);

    // Dot only based on angle (no distance factor)
    float light = fakelight(fragNormal, toView);

    finalColor = texelColor * colDiffuse * fragColor;
    finalColor.rgb *= light;
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
Texture LoadTextureFromCode(void* data, int width, int height, int format = 4) {
	Image img = {
		.data = data,
		.width = width,
		.height = height,
		.mipmaps = 1,
		.format = format,
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
	TEX_NPC_JOHN = LoadTextureFromCode(NPC_JOHN_DATA, NPC_JOHN_WIDTH, NPC_JOHN_HEIGHT);
	TEX_JOHN_VICTORY = LoadTextureFromCode(NPC_JOHN_VICTORY_DATA, NPC_JOHN_VICTORY_WIDTH, NPC_JOHN_VICTORY_HEIGHT);
	TEX_NPC_JOHN_CROUCH = LoadTextureFromCode(NPC_JOHN_CROUCH_DATA, NPC_JOHN_CROUCH_WIDTH, NPC_JOHN_CROUCH_HEIGHT);
	TEX_TILE_1 = LoadTextureFromCode(TILE_1_DATA, TILE_1_WIDTH, TILE_1_HEIGHT);
	TEX_TILE_2 = LoadTextureFromCode(TILE_2_DATA, TILE_2_WIDTH, TILE_2_HEIGHT);
	TEX_TILE_3 = LoadTextureFromCode(TILE_3_DATA, TILE_3_WIDTH, TILE_3_HEIGHT);
	TEX_TILE_4 = LoadTextureFromCode(TILE_4_DATA, TILE_4_WIDTH, TILE_4_HEIGHT);
	TEX_TILE_5 = LoadTextureFromCode(TILE_5_DATA, TILE_5_WIDTH, TILE_5_HEIGHT);
	TEX_TILE_6 = LoadTextureFromCode(TILE_6_DATA, TILE_6_WIDTH, TILE_6_HEIGHT);
	TEX_NOISE_1 = LoadTextureFromCode(NOISE_1_DATA, NOISE_1_WIDTH, NOISE_1_HEIGHT);
	TEX_BRICK = LoadTextureFromCode(BRICK_DATA, BRICK_WIDTH, BRICK_HEIGHT);
	TEX_METAL = LoadTextureFromCode(METAL_DATA, METAL_WIDTH, METAL_HEIGHT);
	TEX_MARBLE = LoadTextureFromCode(MARBLE_DATA, MARBLE_WIDTH, MARBLE_HEIGHT);
	TEX_PLASTER = LoadTextureFromCode(PLASTER_DATA, PLASTER_WIDTH, PLASTER_HEIGHT);
	TEX_CARDBOARD = LoadTextureFromCode(CARDBOARD_DATA, CARDBOARD_WIDTH, CARDBOARD_HEIGHT);
	TEX_WOOD = LoadTextureFromCode(WOOD_DATA, WOOD_WIDTH, WOOD_HEIGHT);
	TEX_WOOD_FLOOR = LoadTextureFromCode(WOOD_FLOOR_DATA, WOOD_FLOOR_WIDTH, WOOD_FLOOR_HEIGHT);
	TEX_FABRIC = LoadTextureFromCode(FABRIC_DATA, FABRIC_WIDTH, FABRIC_HEIGHT);
	TEX_GRASS = LoadTextureFromCode(GRASS_DATA, GRASS_WIDTH, GRASS_HEIGHT);
	TEX_GRAVEL = LoadTextureFromCode(GRAVEL_DATA, GRAVEL_WIDTH, GRAVEL_HEIGHT, GRAVEL_FORMAT);
	TEX_STONE = LoadTextureFromCode(STONE_DATA, STONE_WIDTH, STONE_HEIGHT, STONE_FORMAT);
	TEX_ITEM_DRUMSTICK = LoadTextureFromCode(ITEM_DRUMSTICK_DATA, ITEM_DRUMSTICK_WIDTH, ITEM_DRUMSTICK_HEIGHT, ITEM_DRUMSTICK_FORMAT);

	GenTextureMipmaps(&TEX_BRICK);
	GenTextureMipmaps(&TEX_METAL);
	GenTextureMipmaps(&TEX_GRAVEL);
	SetTextureFilter(TEX_BRICK, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_METAL, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_GRAVEL, RL_TEXTURE_FILTER_TRILINEAR);

	// Shaders
	shader_main = LoadShaderFromMemory(MAIN_VERTEX_SHADER, MAIN_FRAGMENT_SHADER);
	shader_main_viewpos_loc = GetShaderLocation(shader_main, "viewPos");
	shader_main_viewtarget_loc = GetShaderLocation(shader_main, "viewTarget");

	// Sounds
	snd_gunshot = LoadSoundFromCode(BITGUNSHOT_DATA, BITGUNSHOT_FRAME_COUNT, BITGUNSHOT_SAMPLE_RATE, BITGUNSHOT_SAMPLE_SIZE, BITGUNSHOT_CHANNELS);
	snd_hit = LoadSoundFromCode(HIT01_DATA, HIT01_FRAME_COUNT, HIT01_SAMPLE_RATE, HIT01_SAMPLE_SIZE, HIT01_CHANNELS);
	snd_step = LoadSoundFromCode(STEP_DATA, STEP_FRAME_COUNT, STEP_SAMPLE_RATE, STEP_SAMPLE_SIZE, STEP_CHANNELS);
	snd_land = LoadSound("assets/audio/jumpland.wav");
	snd_collect = LoadSoundFromCode(COIN_DATA, COIN_FRAME_COUNT, COIN_SAMPLE_RATE, COIN_SAMPLE_SIZE, COIN_CHANNELS);
	//snd_land = LoadSoundFromCode(STEP_DATA, STEP_FRAME_COUNT, STEP_SAMPLE_RATE, STEP_SAMPLE_SIZE, STEP_CHANNELS);

	// Music
	music_main = LoadMusicStream("assets/audio/fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("assets/audio/lost_town.mp3");
	music_lose.looping = true;
}