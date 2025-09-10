#include <items.h>

// Global assets

// NPC Textures
static Texture TEX_NPC_JOHN;
static Texture TEX_JOHN_VICTORY;
static Texture TEX_NPC_JOHN_CROUCH;

// Debug tiles
static Texture TEX_TILE_1;
static Texture TEX_TILE_2;
static Texture TEX_TILE_3;
static Texture TEX_TILE_4;
static Texture TEX_TILE_5;
static Texture TEX_TILE_6;

// Fence Textures
static Texture TEX_FENCE_1;

// Toon Textures
static Texture TEX_CARDBOARD;
static Texture TEX_PLASTER;
static Texture TEX_MARBLE;
static Texture TEX_WOOD;
static Texture TEX_WOOD_FLOOR;
static Texture TEX_STONE;
static Texture TEX_FABRIC;
static Texture TEX_GRASS;

// Realistic Textures
static Texture TEX_METAL;
static Texture TEX_BRICK;
static Texture TEX_NOISE_1;
static Texture TEX_GRAVEL;
static Texture TEX_CONCRETE;
static Texture TEX_PLASTIC;

// Object Textures
static Texture TEX_OBJ_BARREL;
static Texture TEX_OBJ_TREE;
static Texture TEX_OBJ_TREE_1;

// Item Textures
static Texture TEX_ITEM_DRUMSTICK;

static Shader shader_main;
static int shader_main_viewpos_loc;
static int shader_main_viewtarget_loc;
static Shader shader_debug_normals;

static Sound snd_gunshot;
static Sound snd_hit;
static Sound snd_step;
static Sound snd_land;
static Sound snd_collect;
static Sound snd_victory;

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
	UnloadTexture(TEX_STONE);
	UnloadTexture(TEX_FABRIC);
	UnloadTexture(TEX_GRASS);
	UnloadTexture(TEX_METAL);
	UnloadTexture(TEX_BRICK);
	UnloadTexture(TEX_CONCRETE);
	UnloadTexture(TEX_NOISE_1);
	UnloadTexture(TEX_GRAVEL);
	UnloadTexture(TEX_PLASTIC);
	UnloadTexture(TEX_OBJ_BARREL);
	UnloadTexture(TEX_OBJ_TREE);
	UnloadTexture(TEX_OBJ_TREE_1);
	UnloadTexture(TEX_ITEM_DRUMSTICK);

	// Shaders
	UnloadShader(shader_main);
	UnloadShader(shader_debug_normals);

	// Sounds
	UnloadSound(snd_gunshot);
	UnloadSound(snd_hit);
	UnloadSound(snd_step);
	UnloadSound(snd_land);
	UnloadSound(snd_collect);
	UnloadSound(snd_victory);

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

static void SetSoundPosition(Camera listener, Sound sound, Vector3 position, float maxDist) {
	// Calculate direction vector and distance between listener and sound source
	Vector3 direction = Vector3Subtract(position, listener.position);
	float distance = Vector3Length(direction);

	// Apply logarithmic distance attenuation and clamp between 0-1
	float attenuation = 1.0f / (1.0f + (distance / maxDist));
	attenuation = Clamp(attenuation, 0.0f, 1.0f);

	// Calculate normalized vectors for spatial positioning
	Vector3 normalizedDirection = Vector3Normalize(direction);
	Vector3 forward = Vector3Normalize(Vector3Subtract(listener.target, listener.position));
	Vector3 right = Vector3Normalize(Vector3CrossProduct(listener.up, forward));

	// Reduce volume for sounds behind the listener
	float dotProduct = Vector3DotProduct(forward, normalizedDirection);
	if (dotProduct < 0.0f) attenuation *= (1.0f + dotProduct * 0.5f);

	// Set stereo panning based on sound position relative to listener
	float pan = 0.5f + 0.5f * Vector3DotProduct(normalizedDirection, right);

	// Apply final sound properties
	SetSoundVolume(sound, 1.0f / distance);
	SetSoundPan(sound, pan);
}
inline bool FuzzyLess(float a, float b, float thresh = 1.0f) {
	return a < b + thresh;
}
inline bool FuzzyGreater(float a, float b, float thresh = 1.0f) {
	return a > b - thresh;
}
inline bool FeatherEqual(float a, float b, float thresh = 1.0f) {
	return FuzzyLess(a, b, thresh) && FuzzyGreater(a, b, thresh);
}

static int score = 0;
static Camera camera = { 0 };
Screen startscreen = {
	WHITE,
	"Token Collector Demo",
	"Find 8 tokens through out the 3 maps currently in the game.",
	BLACK,
#ifdef _DEBUG
	false, // If debug, ignore start screen
#endif
};
Screen victoryscreen = {
	{0,255,0,120},
	"You have collected all tokens!",
	"That's all there is to this demo",
	GREEN,
};