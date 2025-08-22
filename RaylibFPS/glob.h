// Global assets
static Texture tex_john;
static Texture tex_john_victory;
static Texture tile_1;
static Texture tile_2;
static Texture tile_3;
static Texture tile_4;

static Shader shader_discard;

static Sound snd_gunshot;
static Sound snd_hit;
static Sound snd_step;

static Music music_main;
static Music music_lose;

void LoadGlob() {
	// Textures
	tex_john = LoadTexture("npc_john.png");
	tex_john_victory = LoadTexture("npc_john_victory.png");
	tile_1 = LoadTexture("tile_1.png");
	tile_2 = LoadTexture("tile_2.png");
	tile_3 = LoadTexture("tile_3.png");
	tile_3 = LoadTexture("tile_4.png");

	// Shaders
	shader_discard = LoadShader(NULL, "discard.fs");

	// Sounds
	snd_gunshot = LoadSound("8bitgunshot.wav");
	snd_hit = LoadSound("hit01.wav");
	snd_step = LoadSound("step.wav");

	// Music
	music_main = LoadMusicStream("fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("lost_town.mp3");
	music_lose.looping = true;
}