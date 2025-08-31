// Global assets
static Texture tex_john;
static Texture tex_john_victory;
static Texture tex_john_crouch;
static Texture TILE_1;
static Texture TILE_2;
static Texture TILE_3;
static Texture TILE_4;
static Texture TILE_5;
static Texture TILE_6;
static Texture FENCE_1;
static Texture CARDBOARD;
static Texture PLASTER;
static Texture MARBLE;
static Texture WOOD;
static Texture WOOD_FLOOR;
static Texture FABRIC;
static Texture GRASS;
static Texture METAL;
static Texture BRICK;
static Texture NOISE_1;

static Shader shader_main;
static int shader_main_viewpos_loc;
static int shader_main_viewtarget_loc;
static Shader shader_debug_normals;

static Sound snd_gunshot;
static Sound snd_hit;
static Sound snd_step;
static Sound snd_land;

static Music music_main;
static Music music_lose;

#ifdef _DEBUG
#include <load_glob_debug.h>
#else
#include <load_glob_release.h>
#endif // DEBUG

void UnloadGlob() {
	// Textures
	UnloadTexture(tex_john);
	UnloadTexture(tex_john_victory);
	UnloadTexture(tex_john_crouch);
	UnloadTexture(TILE_1);
	UnloadTexture(TILE_2);
	UnloadTexture(TILE_3);
	UnloadTexture(TILE_4);
	UnloadTexture(TILE_5);
	UnloadTexture(TILE_6);
	UnloadTexture(FENCE_1);
	UnloadTexture(CARDBOARD);
	UnloadTexture(PLASTER);
	UnloadTexture(MARBLE);
	UnloadTexture(WOOD);
	UnloadTexture(WOOD_FLOOR);
	UnloadTexture(FABRIC);
	UnloadTexture(GRASS);
	UnloadTexture(METAL);
	UnloadTexture(BRICK);
	UnloadTexture(NOISE_1);

	// Shaders
	UnloadShader(shader_main);
	UnloadShader(shader_debug_normals);

	// Sounds
	UnloadSound(snd_gunshot);
	UnloadSound(snd_hit);
	UnloadSound(snd_step);
	UnloadSound(snd_land);

	// Music
	UnloadMusicStream(music_main);
	UnloadMusicStream(music_lose);
}

bool ClosestRayCollision(RayCollision& source, RayCollision compare) {
	if (compare.hit && (!source.hit || compare.distance < source.distance)) {
		source = compare;
		return true;
	}
	return false;
}

static Camera camera = { 0 };