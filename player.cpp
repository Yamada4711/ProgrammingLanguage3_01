#include "DxLib.h"
#include "player.h"

Player::Player()
{
	draw = true;
	jump = false;
	state = JUMP;
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

		int jumpPower = 10;
		jumpPower /= jumpCount / 5 + 1;
		// ジャンプ力は最低でも１になるようにする
		if (jumpPower == 0) jumpPower++;
		jumpCount++;

		// ここでプレイヤーのｙ座標を変更する
		vector2.y -= jumpPower;

		if (jumpCount == jumpCountMax)
		{
			state = FALL;
			fallCount = 0;
		}
	}
	return 0;
}

int Player::JudgeJump()
{
	if (!jump || state == JUMP)
	{
		Jump();
	}
	return 0;
}

int Player::Fall()
{
	if (state == FALL)
	{
		int fallPower = 3;
		if (fallCount < jumpCountMax)
		{
			fallPower /= (jumpCountMax - fallCount) / 5 + 1;
			fallCount++;
		}
		else
		{
			fallPower++;
		}
		vector2.y += fallPower;
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