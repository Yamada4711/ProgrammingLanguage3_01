#include "DxLib.h"
#include "box.h"
#include "common.h"

Box::Box(int countS)
{
	state = COUNT;

	// �f�t�H���g�ł͋�`�͉E�Ɍ������ē����A�Ƃ���
	moveLeft = false;

	// �f�t�H���g�ł͋�`��`�悵�Ȃ�
	draw = false;

	// �f�t�H���g�ł̓v���C���[�ɐG��Ă��Ȃ�
	touchPlayer = false;

	// �N������܂ł̎��Ԃ���
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
	// ���ꂼ�ꐳ��I�����Ȃ�������G���[��Ԃ��ďI������
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
		// ��΂ɂ����ɂ͓���Ȃ��͂���
		return ERROR_OCCURRED;
	}

	return 0;
}

int Box::GenerateBox()
{
	// ��`�̒����̂����W�̈ʒu�����߂�
	vector2.y = rand() % 200 + 160;

	// ��`�̐����ʒu����ʉE�ɂ��邩���ɂ��邩���߂�
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
	// ��`�����Ɉړ����鑬��
	const int speed = 2;

	// ��`�̒����̂����W���ړ�������
	vector2.x += moveLeft ? -speed : speed;

	return 0;
}

int Box::VerticalMovement()
{
	// ��`���c�Ɉړ����鑬��
	const int speed = 1;

	// ��`�̒����̂����W���ړ�������
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
	// �܂��͍�����W����
	int leftUpX = vector2.x - halfWidth;
	int leftUpY = vector2.y - halfHeight;

	// ���ɉE�����W
	int rightDownX = vector2.x + halfWidth;
	int rightDownY = vector2.y + halfHeight;

	return std::forward_as_tuple(leftUpX, leftUpY, rightDownX, rightDownY);
}