#include "DxLib.h"
#include "player.h"
#include "tuple"

Player::Player()
{
	draw = true;
	jump = false;
	state = DEFAULTS;
	jumpCount = 0;
	fallCount = 0;
}

Player::~Player()
{
}

int Player::Jump()
{
	if (state == JUMP)
	{
		if (!jump) jump = true;

		int jumpPower = 1 * jumpPowerMultiplier; // マリオっぽいジャンプにする
		//printfDx("jumpPower : %d", jumpPower); // ジャンプ力を確認するためのやつ（消していい）
		if (jumpPower > 100) jumpPower = 100; // ジャンプ力を制限する
		jumpPower /= jumpCount + 1 / 5 + 1; // ジャンプ力が滑らかに減少するようにする
		//// ジャンプ力は最低でも１になるようにする
		if (jumpPower == 0) jumpPower++;
		jumpCount++;

		// ここでプレイヤーのｙ座標を変更する
		vector2.y -= jumpPower;

		if (jumpCount >= jumpCountMax)
		{
			jumpCount = 0;
			state = FALL;
		}
		return 0;
	}
	return -1;
}

int Player::JudgeJump(const int countPushJumpButton)
{
	if ((!jump || state == JUMP) && state != DEATH)
	{
		if (state != JUMP) state = JUMP;
		jumpPowerMultiplier = countPushJumpButton;
		Jump();
	}
	return 0;
}

int Player::Fall()
{
	if (state == FALL)
	{
		int fallPower = 2;
		/*if (fallCount < jumpCountMax)
		{
			fallPower /= (jumpCountMax - fallCount) / 5 + 1;
			fallCount++;
		}
		else
		{
			fallPower++;
		}*/
		vector2.y += fallPower;
	}
	else if (fallCount != 0) fallCount = 0;
	return 0;
}

bool Player::JudgeTouchBox(Box& box)
{
	// 矩形の座標を入れる
	int boxLeftUpX, boxLeftUpY, boxRightDownX, boxRightDownY;
	std::tie(boxLeftUpX, boxLeftUpY, boxRightDownX, boxRightDownY) = box.GetBoxCoordinate();

	// プレイヤーの座標を入れる
	int leftUpX = vector2.x - halfSize,
		//leftUpY = vector2.y - halfSize,
		rightDownX = vector2.x + halfSize,
		rightDownY = vector2.y + halfSize;

	// 高さの当たり判定
	// 横の当たり判定
	// ジャンプ動作中は当たり判定が発動しないようにする
	// 空中ジャンプはありにしておく(二段ジャンプは禁止)
	if ((rightDownY <= boxLeftUpY + 5 && rightDownY >= boxLeftUpY - 2) &&
		(leftUpX <= boxRightDownX - 3 && rightDownX >= boxLeftUpX + 3) &&
		state != JUMP && state != DEFAULTS)
	{
		if (jump)
		{
			jump = false;
			//printfDx("jump ; %d", jump);
		}
		if (state != TOUCH_BOX)
		{
			state = TOUCH_BOX;
		}
		return true;
	}
	else
	{
		//if (state == TOUCH_BOX) state = FALL;
		return false;
	}
}

int Player::TouchBoxFall()
{
	//printfDx("state = %d", state);
	if (state == TOUCH_BOX)
	{
		const int fallPower = 1;
		vector2.y += fallPower;
	}
	return 0;
}

int Player::JudgeDeath()
{
	if (vector2.y > SCREEN_SIZE_Y - RATIO_Y * 15)
	{
		state = DEATH;
		printfDx("PlayerDeath");
	}
	return 0;
}

int Player::GetVector2X()
{
	return vector2.x;
}

int Player::GetVector2Y()
{
	return vector2.y;
}

bool Player::GetDraw()
{
	return draw;
}