#pragma once
#include "common.h"

class Box
{
public:
	Box();
	~Box();

	/// <summary>
	/// 矩形の状態を確認して適切な関数を呼ぶ
	/// </summary>
	/// <returns></returns>
	int ManagementBox();

	/// <summary>
	/// ｘ座標取得用
	/// </summary>
	/// <returns></returns>
	int GetVector2X();
	/// <summary>
	/// ｙ座標取得用
	/// </summary>
	/// <returns></returns>
	int GetVector2Y();
	/// <summary>
	/// 描画するかどうか取得用
	/// </summary>
	/// <returns></returns>
	bool GetDraw();

private:
	/// <summary>
	/// 矩形を生成する
	/// </summary>
	/// <returns></returns>
	int GenerateBox();

	/// <summary>
	/// 矩形を横移動させる関数
	/// </summary>
	/// <returns></returns>
	int LateralMovement();

	/// <summary>
	/// 矩形を縦移動させる関数
	/// </summary>
	/// <returns></returns>
	int VerticalMovement();

	/// <summary>
	/// 矩形を消滅させる
	/// </summary>
	/// <returns></returns>
	int EraseBox();

private:
	// 矩形の中央の座標
	struct Vector2
	{
		int x = 0;
		int y = RATIO_Y * 60;
	};

	/// <summary>
	/// 矩形を描画するか否か
	/// </summary>
	bool draw;

	/// <summary>
	/// 矩形の進行方向は左であるか否か
	/// </summary>
	bool moveLeft;

	/// <summary>
	/// 矩形の中央の座標
	/// </summary>
	Vector2 vector2;

	/// <summary>
	/// 矩形の横幅の半分の値
	/// </summary>
	const int halfWidth = RATIO_X * 15;
	/// <summary>
	/// 矩形の縦幅の半分の値
	/// </summary>
	const int halfHeight = RATIO_Y * 5;

	/// <summary>
	/// 矩形の状態管理用
	/// </summary>
	enum State
	{
		// 空席（次の矩形を生成する）
		EMPTY,

		// 横移動中
		LATERAL_MOVEMENT,

		// 落下中
		VARTICAL_MOVEMENT,

		// 消滅させる
		ERASE,
	};

	/// <summary>
	/// 矩形の状態管理用
	/// </summary>
	State state;
};