void LoadGlob() {
	// Textures
	TEX_NPC_JOHN = LoadTexture("assets/textures/npc_john.png");
	TEX_JOHN_VICTORY = LoadTexture("assets/textures/npc_john_victory.png");
	TEX_NPC_JOHN_CROUCH = LoadTexture("assets/textures/npc_john_crouch.png");
	TEX_TILE_1 = LoadTexture("assets/textures/tile_1.png");
	TEX_TILE_2 = LoadTexture("assets/textures/tile_2.png");
	TEX_TILE_3 = LoadTexture("assets/textures/tile_3.png");
	TEX_TILE_4 = LoadTexture("assets/textures/tile_4.png");
	TEX_TILE_5 = LoadTexture("assets/textures/tile_5.png");
	TEX_TILE_6 = LoadTexture("assets/textures/tile_6.png");
	TEX_FENCE_1 = LoadTexture("assets/textures/fence_1.png");
	TEX_CARDBOARD = LoadTexture("assets/textures/cardboard.jpg");
	TEX_PLASTER = LoadTexture("assets/textures/plaster.jpg");
	TEX_MARBLE = LoadTexture("assets/textures/marble.jpg");
	TEX_WOOD = LoadTexture("assets/textures/wood.jpg");
	TEX_WOOD_FLOOR = LoadTexture("assets/textures/wood_floor.jpg");
	TEX_STONE = LoadTexture("assets/textures/stone.jpg");
	TEX_FABRIC = LoadTexture("assets/textures/fabric.jpg");
	TEX_GRASS = LoadTexture("assets/textures/grass.jpg");
	TEX_METAL = LoadTexture("assets/textures/metal.jpg");
	TEX_BRICK = LoadTexture("assets/textures/brick.png");
	TEX_NOISE_1 = LoadTexture("assets/textures/noise_1.png");
	TEX_GRAVEL = LoadTexture("assets/textures/gravel.png");
	TEX_OBJ_BARREL = LoadTexture("assets/textures/obj_barrel.png");
	TEX_OBJ_TREE = LoadTexture("assets/textures/obj_tree.png");
	TEX_OBJ_TREE_1 = LoadTexture("assets/textures/obj_tree_1.png");
	TEX_ITEM_DRUMSTICK = LoadTexture("assets/textures/item_drumstick.png");

	GenTextureMipmaps(&TEX_BRICK);
	GenTextureMipmaps(&TEX_METAL);
	GenTextureMipmaps(&TEX_TILE_4);
	GenTextureMipmaps(&TEX_GRAVEL);
	GenTextureMipmaps(&TEX_OBJ_TREE_1);
	GenTextureMipmaps(&TEX_ITEM_DRUMSTICK);
	SetTextureFilter(TEX_BRICK, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_METAL, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_TILE_4, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_GRAVEL, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_OBJ_TREE_1, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureFilter(TEX_ITEM_DRUMSTICK, RL_TEXTURE_FILTER_TRILINEAR);
	SetTextureWrap(TEX_ITEM_DRUMSTICK, TEXTURE_WRAP_CLAMP);

	// Shaders
	shader_main = LoadShader("assets/shaders/main.vs", "assets/shaders/main.fs");
	shader_main_viewpos_loc = GetShaderLocation(shader_main, "viewPos");
	shader_main_viewtarget_loc = GetShaderLocation(shader_main, "viewTarget");
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