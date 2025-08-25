void LoadGlob() {
	// Textures
	tex_john = LoadTexture("assets/textures/npc_john.png");
	tex_john_victory = LoadTexture("assets/textures/npc_john_victory.png");
	tex_john_crouch = LoadTexture("assets/textures/npc_john_crouch.png");
	tile_1 = LoadTexture("assets/textures/tile_1.png");
	tile_2 = LoadTexture("assets/textures/tile_2.png");
	tile_3 = LoadTexture("assets/textures/tile_3.png");
	tile_4 = LoadTexture("assets/textures/tile_4.png");
	tile_5 = LoadTexture("assets/textures/tile_5.png");
	tile_6 = LoadTexture("assets/textures/tile_6.png");

	// Shaders
	shader_main = LoadShader("assets/shaders/main.vs", "assets/shaders/main.fs");
	shader_main_viewpos_loc = GetShaderLocation(shader_main, "viewPos");
	shader_debug_normals = LoadShader("assets/shaders/normal.vs", "assets/shaders/normal.fs");

	// Sounds
	snd_gunshot = LoadSound("assets/audio/bitgunshot.wav");
	snd_hit = LoadSound("assets/audio/hit01.wav");
	snd_step = LoadSound("assets/audio/step.wav");

	// Music
	music_main = LoadMusicStream("assets/audio/fight_looped.wav");
	music_main.looping = true;
	music_lose = LoadMusicStream("assets/audio/lost_town.mp3");
	music_lose.looping = true;
}