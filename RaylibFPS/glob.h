#include <items.h>

// Global assets
static Texture TEX_NPC_JOHN;
static Texture TEX_JOHN_VICTORY;
static Texture TEX_NPC_JOHN_CROUCH;
static Texture TEX_TILE_1;
static Texture TEX_TILE_2;
static Texture TEX_TILE_3;
static Texture TEX_TILE_4;
static Texture TEX_TILE_5;
static Texture TEX_TILE_6;
static Texture TEX_FENCE_1;
static Texture TEX_CARDBOARD;
static Texture TEX_PLASTER;
static Texture TEX_MARBLE;
static Texture TEX_WOOD;
static Texture TEX_WOOD_FLOOR;
static Texture TEX_FABRIC;
static Texture TEX_GRASS;
static Texture TEX_METAL;
static Texture TEX_BRICK;
static Texture TEX_NOISE_1;
static Texture TEX_OBJ_BARREL;
static Texture TEX_OBJ_TREE;
static Texture TEX_ITEM_DRUMSTICK;

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

// Global objects
static Item item_drumstick = {
	.name = "Drumstick",
	.texture = &TEX_ITEM_DRUMSTICK,
};

#ifdef _DEBUG
#include <load_glob_debug.h>
#else
#include <load_glob_release.h>
#endif // DEBUG

void UnloadGlob() {
	// Textures
	UnloadTexture(TEX_NPC_JOHN);
	UnloadTexture(TEX_JOHN_VICTORY);
	UnloadTexture(TEX_NPC_JOHN_CROUCH);
	UnloadTexture(TEX_TILE_1);
	UnloadTexture(TEX_TILE_2);
	UnloadTexture(TEX_TILE_3);
	UnloadTexture(TEX_TILE_4);
	UnloadTexture(TEX_TILE_5);
	UnloadTexture(TEX_TILE_6);
	UnloadTexture(TEX_FENCE_1);
	UnloadTexture(TEX_CARDBOARD);
	UnloadTexture(TEX_PLASTER);
	UnloadTexture(TEX_MARBLE);
	UnloadTexture(TEX_WOOD);
	UnloadTexture(TEX_WOOD_FLOOR);
	UnloadTexture(TEX_FABRIC);
	UnloadTexture(TEX_GRASS);
	UnloadTexture(TEX_METAL);
	UnloadTexture(TEX_BRICK);
	UnloadTexture(TEX_NOISE_1);
	UnloadTexture(TEX_OBJ_BARREL);
	UnloadTexture(TEX_OBJ_TREE);
	UnloadTexture(TEX_ITEM_DRUMSTICK);

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