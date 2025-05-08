#pragma once
#include "common.h"
#include "box.h"

class Player
{
public:
	Player();
	virtual ~Player();


	/// <summary>
	/// ジャンプの処理を続行可能かどうか判断する
	/// </summary>
	/// <returns></returns>
	int JudgeJump();

	/// <summary>
	/// 矩形に着地しているかどうか判定する
	/// </summary>
	/// <returns></returns>
	bool JudgeTouchBox(Box& box);

	/// <summary>
	/// 矩形に触れた状態での落下
	/// </summary>
	int TouchBoxFall();

	/// <summary>
	/// 落下する処理
	/// </summary>
	/// <returns></returns>
	int Fall();

	/// <summary>
	/// プレイヤーのｘ座標を渡す
	/// </summary>
	/// <returns></returns>
	int GetVector2X();
	/// <summary>
	/// プレイヤーのｙ座標を渡す
	/// </summary>
	/// <returns></returns>
	int GetVector2Y();
	/// <summary>
	/// プレイヤーを描画するか否かを渡す
	/// </summary>
	/// <returns></returns>
	bool GetDraw();

private:
	/// <summary>
	/// プレイヤーが上昇する処理
	/// </summary>
	/// <returns></returns>
	int Jump();

private:
	/// <summary>
	/// プレイヤーの中央の座標
	/// </summary>
	struct Vector2
	{
		// プレイヤーのｘ座標
		int x = SCREEN_SIZE_X / 2;
		// プレイヤーのｙ座標
		int y = SCREEN_SIZE_Y / 2 - RATIO_X * RATIO_Y * 2;
	};

	/// <summary>
	/// プレイヤーの中央の座標
	/// </summary>
	Vector2 vector2;

	/// <summary>
	/// プレイヤーのサイズの半分(縦横比１：１)
	/// </summary>
	const int halfSize = RATIO_X * RATIO_Y * 2;

	/// <summary>
	/// 状態管理用
	/// </summary>
	enum State
	{
		// 足場に触れている状態（足場とともに落下している状態）
		TOUCH_BOX,
		// ジャンプキーが押されて飛び上がっている最中
		JUMP,
		// 足場がなくて落下している最中（TOUCH_BOXより落下速度が速い）
		FALL,
		// とげに当たって死んだ
		DEATH,
	};

	/// <summary>
	/// 状態管理用
	/// </summary>
	State state;

	/// <summary>
	/// 二段ジャンプできないようにするための変数
	/// </summary>
	bool jump;

	/// <summary>
	/// 今ジャンプの処理がどれくらい進んだか
	/// </summary>
	int jumpCount;
	/// <summary>
	/// ジャンプの処理を行う時間
	/// </summary>
	const int jumpCountMax = 30;

	/// <summary>
	/// 緩やかに落下する処理を行った回数をカウント
	/// </summary>
	int fallCount;

	/// <summary>
	/// プレイヤーを描画するか否か
	/// </summary>
	bool draw;
};