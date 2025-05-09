#include "DxLib.h"
#include "draw.h"

/// <summary>
/// �v���C���[�摜��ݒ肷��
/// </summary>
/// <returns></returns>
int SetPlayerGraph()
{
	return LoadGraph("BunnyGirlAnimation01.bmp");
}

Draw::Draw()
{
	// �v���C���[�摜��ݒ肷��
	gHandle = SetPlayerGraph();
}

Draw::~Draw()
{
	DeleteGraph(gHandle);
}



/// <summary>
/// �Ƃ���`��
/// </summary>
/// <returns></returns>
int Draw::DrawThorns()
{
	// �Ƃ��̉���(�K��2�̔{���ɂ��邱��)(�Œ�)
	const int width = RATIO_X * 10;
	// �Ƃ��̏c��(�Œ�)
	const int height = RATIO_Y * 15;

	// �Ƃ��̕`����J�n����X�̈ʒu(�Œ�)
	const int startPosX = 0;
	// �Ƃ��̕`����I���X�̈ʒu(�Œ�)
	const int endPosX = SCREEN_SIZE_X;

	// �Ƃ��̒�ʂ̈ʒu(�Œ�)
	const int bottomPos = SCREEN_SIZE_Y;

	// �Ƃ���`�悷���(��)
	int drawMax = (endPosX - startPosX) / width;

	// �Ƃ��̐F���w�� 4/17���_�ł͉��F(�Œ�)
	const unsigned int color = GetColor(255, 255, 0);

	// �O�p�`�̕`��֐��̈����̒l��
	// �O�p�`�̍����A�E���A��̏���
	// ����������
	
	// x���W(��)
	int x1 = startPosX,
		x2 = x1 + width,
		x3 = x1 + (width / 2);

	// y���W(�Œ�)
	const int y1 = bottomPos,
		y2 = y1,
		y3 = bottomPos - height;

	// �Ƃ���`�悷��񐔂�0�ɂȂ�܂łƂ��̕`����s��
	while (drawMax > 0)
	{
		if (x1 < startPosX || x2 > endPosX)
		{
			printfDx("�G���[�Fdraw.cpp��DrawThorns�֐����͈͊O�ɂƂ���`�����Ƃ��Ă���悤��");
			return ERROR_OCCURRED;
		}
		// �Ƃ��̎O�p�`�̕`����s��
		DrawTriangle(x1, y1, x2, y2, x3, y3, color, TRUE);

		// ���̂Ƃ��̈ʒu���w�肷��(x�̂ݕύX)
		x1 += width, x2 += width, x3 += width;

		// �Ƃ���`�悷��񐔂��P���炷
		drawMax--;
	}
	return 0;
}

/// <summary>
/// ��`��`��
/// </summary>
/// <param name="x">��`�����̂����W</param>
/// <param name="y">��`�����̂����W</param>
/// <param name="width">�����̔���</param>
/// <param name="height">�c���̔���</param>
/// <returns></returns>
int Draw::DrawRectangle (const bool drawBox, const int x, const int y, const int width, const int height)
{
	if (drawBox)
	{
		// ��`�̐F���w�肷��i�F�j�i�Œ�j
		const unsigned int color = GetColor(0, 0, 255);

		// ��`��`�悷����W���w�肷��(�Œ�)
		const int x1 = x - width, y1 = y - height;
		const int x2 = x + width - 1, y2 = y + height - 1;
		DrawBox(x1, y1, x2, y2, color, TRUE);
	}
	return 0;
}

/// <summary>
/// �L�����N�^�[�摜�̃T�C�Y�𒲐����`�悷��
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="gHandle"></param>
/// <returns></returns>
int Draw::DrawPlayerCharacter (const bool drawPlayer, const int x, const int y, const int halfSize)
{
	if (drawPlayer)
	{
		// �摜�ǂݍ��݂������Ƃł��Ă��邩�ǂ����m�F����
		if (gHandle == -1)
		{
			printfDx("�G���[�F�O���t�B�b�N�f�[�^�̓ǂݍ��݂Ɏ��s���Ă����");
			return ERROR_OCCURRED;
		}

		// �v���C���[��`�悷��ʒu
		const int x1 = x - halfSize, y1 = y - halfSize,
			x2 = x + halfSize, y2 = y + halfSize;

		DrawExtendGraph(x1, y1, x2, y2, gHandle, TRUE);
	}
	return 0;
}



//int Draw::DrawingScreen(const bool drawBox1, const bool drawBox2,
//	const int box1X, const int box1Y, const int box2X, const int box2Y,
//	const bool drawPlayer, const int playerX, const int playerY)
//{
//	// �Ƃ���`��
//	if (DrawThorns() != 0) return ERROR_OCCURRED;
//
//	// ��`1��`��
//	if (drawBox1)
//	{
//		if (DrawRectangle(drawBox1, box1X, box1Y) != 0) return ERROR_OCCURRED;
//	}
//	// ��`2��`��
//	if (drawBox2)
//	{
//		if (DrawRectangle(drawBox2, box2X, box2Y) != 0) return ERROR_OCCURRED;
//	}
//	// ��`3��`��
//	if (DrawRectangle(true , SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2 + RATIO_Y * 5) != 0) return ERROR_OCCURRED;
//
//	// �v���C���[��`�悷��
//	if (DrawPlayerCharacter(gHandle, drawPlayer, playerX, playerY) != 0) return ERROR_OCCURRED;
//
//	return 0;
//}