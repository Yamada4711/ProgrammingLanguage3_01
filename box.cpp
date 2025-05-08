#include "DxLib.h"
#include "box.h"
#include "common.h"

Box::Box(int countS)
{
	state = COUNT;

	// デフォルトでは矩形は右に向かって動く、とする
	moveLeft = false;

	// デフォルトでは矩形を描画しない
	draw = false;

	// デフォルトではプレイヤーに触れていない
	touchPlayer = false;

	// 起動するまでの時間を代入
	countStart = countS;
}

Box::~Box()
{

}

int Box::CountStart()
{
	if (countStart > 0)
	{
		countStart--;
	}
	else if (countStart != -1)
	{
		state = EMPTY;
		draw = true;
		countStart = -1;
	}
	return 0;
}

int Box::ManagementBox()
{
	// それぞれ正常終了しなかったらエラーを返して終了する
	switch (state)
	{
	case Box::EMPTY:
		if (GenerateBox() != 0)
		{
			return ERROR_OCCURRED;
		}
		else
		{
			touchPlayer = false;
			state = LATERAL_MOVEMENT;
		}
		break;

	case Box::LATERAL_MOVEMENT:
		if (LateralMovement() != 0)
		{
			return ERROR_OCCURRED;
		}
		else if (vector2.x > SCREEN_SIZE_X + halfWidth || vector2.x < 0 - halfWidth)
		{
			state = ERASE;
		}
		break;

	case Box::VARTICAL_MOVEMENT:
		if (VerticalMovement() != 0)
		{
			return ERROR_OCCURRED;
		}
		else if (vector2.y >= SCREEN_SIZE_Y)
		{
			state = ERASE;
		}
		break;

	case Box::ERASE:
		if (EraseBox() != 0)
		{
			return ERROR_OCCURRED;
		}
		else
		{
			state = EMPTY;
		}
		break;

	default:
		// 絶対にここには入らないはずだ
		return ERROR_OCCURRED;
	}

	return 0;
}

int Box::GenerateBox()
{
	// 矩形の中央のｙ座標の位置を決める
	vector2.y = rand() % 200 + 160;

	// 矩形の生成位置を画面右にするか左にするか決める
	if (rand() % 2 == 1)
	{
		vector2.x = halfWidth;
		moveLeft = false;
	}
	else
	{
		vector2.x = SCREEN_SIZE_X - halfWidth;
		moveLeft = true;
	}

	draw = true;

	return 0;
}

int Box::LateralMovement()
{
	// 矩形が横に移動する速さ
	const int speed = 2;

	// 矩形の中央のｘ座標を移動させる
	vector2.x += moveLeft ? -speed : speed;

	return 0;
}

int Box::VerticalMovement()
{
	// 矩形が縦に移動する速さ
	const int speed = 1;

	// 矩形の中央のｙ座標を移動させる
	vector2.y += speed;

	return 0;
}

int Box::EraseBox()
{
	draw = false;
	vector2.x = NULL;
	vector2.y = NULL;
	return 0;
}

int Box::SetTouchPlayer(bool touch)
{
	if (touch)
	{
		if (!touchPlayer)
		{
			touchPlayer = true;
			state = VARTICAL_MOVEMENT;
		}
	}
	return 0;
}

int Box::GetVector2X()
{
	return vector2.x;
}

int Box::GetVector2Y()
{
	return vector2.y;
}

bool Box::GetDraw()
{
	return draw;
}

std::tuple<int, int, int, int> Box::GetBoxCoordinate()
{
	// まずは左上座標から
	int leftUpX = vector2.x - halfWidth;
	int leftUpY = vector2.y - halfHeight;

	// 次に右下座標
	int rightDownX = vector2.x + halfWidth;
	int rightDownY = vector2.y + halfHeight;

	return std::forward_as_tuple(leftUpX, leftUpY, rightDownX, rightDownY);
}