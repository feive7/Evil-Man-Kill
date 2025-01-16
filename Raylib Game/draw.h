void DrawText3D(std::string str, Vector3 pos, float size, Camera camera) {
	float distanceToText = Vector3Distance(pos, camera.position);
	float fontSize = size / distanceToText;
	Vector2 projected = GetWorldToScreen(pos, camera);
	projected = Vector2Subtract(projected, { fontSize * (str.length()) / 4,0 });
	DrawText(str.c_str(), projected.x, projected.y, fontSize, RED);
}