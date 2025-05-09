#pragma once
#include "common.h"

class Draw
{
public:
	Draw();
	virtual ~Draw();

	/// <summary>
	/// 画面に絵を描く関数
	/// </summary>
	int DrawingScreen (const bool drawBox1, const bool drawBox2, const int box1X, const int box1Y, const int box2X, const int box2Y, const bool drawPlayer, const int playerX, const int playerY);

	/// <summary>
	/// とげを描く
	/// </summary>
	/// <returns></returns>
	int DrawThorns();

	/// <summary>
	/// プレイヤーの画像を描画する
	/// </summary>
	/// <param name="gHandle"></param>
	/// <param name="drawPlayer"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="halfSize"></param>
	/// <returns></returns>
	int DrawPlayerCharacter (const bool drawPlayer, const int x = SCREEN_SIZE_X / 2, const int y = SCREEN_SIZE_Y / 2 - RATIO_X * RATIO_Y * 2, const int halfSize = RATIO_X * RATIO_Y * 2);

	/// <summary>
	/// 矩形を描く
	/// </summary>
	/// <param name="x">矩形中央のｘ座標</param>
	/// <param name="y">矩形中央のｙ座標</param>
	/// <param name="width">横幅の半分</param>
	/// <param name="height">縦幅の半分</param>
	/// <returns></returns>
	int DrawRectangle(const bool drawBox, const int x = SCREEN_SIZE_X / 2, const int y = SCREEN_SIZE_Y / 2 + RATIO_Y * 5, const int width = RATIO_X * 15, const int height = RATIO_Y * 5);

private:
	/// <summary>
	/// プレイヤー画像を格納する変数
	/// </summary>
	int gHandle;
};