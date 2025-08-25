// Global assets
static Texture tex_john;
static Texture tex_john_victory;
static Texture tex_john_crouch;
static Texture tile_1;
static Texture tile_2;
static Texture tile_3;
static Texture tile_4;
static Texture tile_5;
static Texture tile_6;

static Shader shader_main;
static int shader_main_viewpos_loc;
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
	UnloadTexture(tile_1);
	UnloadTexture(tile_2);
	UnloadTexture(tile_3);
	UnloadTexture(tile_4);
	UnloadTexture(tile_5);
	UnloadTexture(tile_6);

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