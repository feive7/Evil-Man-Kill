// Global assets
static Texture tex_john;
static Texture tex_john_victory;
static Texture tile_1;
static Texture tile_2;
static Texture tile_3;
static Texture tile_4;

static Shader shader_discard;
static Shader shader_debug_normals;

static Sound snd_gunshot;
static Sound snd_hit;
static Sound snd_step;

static Music music_main;
static Music music_lose;

void LoadGlob() {
	// Textures
	tex_john = LoadTexture("assets/textures/npc_john.png");
	tex_john_victory = LoadTexture("assets/textures/npc_john_victory.png");
	tile_1 = LoadTexture("assets/textures/tile_1.png");
	tile_2 = LoadTexture("assets/textures/tile_2.png");
	tile_3 = LoadTexture("assets/textures/tile_3.png");
	tile_4 = LoadTexture("assets/textures/tile_4.png");

	// Shaders
	shader_discard = LoadShader(NULL, "assets/shaders/discard.fs");
	shader_debug_normals = LoadShader("assets/shaders/normal.vs", "assets/shaders/normal.fs");

	// Sounds
	snd_gunshot = LoadSound("assets/audio/8bitgunshot.wav");
	snd_hit = LoadSound("assets/audio/hit01.wav");
	snd_step = LoadSound("assets/audio/step.wav");

	// Music
	music_main = LoadMusicStream("assets/audio/fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("assets/audio/lost_town.mp3");
	music_lose.looping = true;
}