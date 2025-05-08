#pragma once

class Draw
{
public:
	Draw();
	virtual ~Draw();

	/// <summary>
	/// ‰æ–Ê‚ÉŠG‚ğ•`‚­ŠÖ”
	/// </summary>
	int DrawingScreen(const bool drawBox1, const bool drawBox2,
		const int box1X, const int box1Y, const int box2X, const int box2Y,
		const bool drawPlayer, const int playerX, const int playerY);

private:
	/// <summary>
	/// ƒvƒŒƒCƒ„[‰æ‘œ‚ğŠi”[‚·‚é•Ï”
	/// </summary>
	int gHandle;
};