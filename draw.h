#pragma once
#include "common.h"

class Draw
{
public:
	Draw();
	virtual ~Draw();

	/// <summary>
	/// ��ʂɊG��`���֐�
	/// </summary>
	int DrawingScreen (const bool drawBox1, const bool drawBox2, const int box1X, const int box1Y, const int box2X, const int box2Y, const bool drawPlayer, const int playerX, const int playerY);

	/// <summary>
	/// �Ƃ���`��
	/// </summary>
	/// <returns></returns>
	int DrawThorns();

	/// <summary>
	/// �v���C���[�̉摜��`�悷��
	/// </summary>
	/// <param name="gHandle"></param>
	/// <param name="drawPlayer"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="halfSize"></param>
	/// <returns></returns>
	int DrawPlayerCharacter (const bool drawPlayer, const int x = SCREEN_SIZE_X / 2, const int y = SCREEN_SIZE_Y / 2 - RATIO_X * RATIO_Y * 2, const int halfSize = RATIO_X * RATIO_Y * 2);

	/// <summary>
	/// ��`��`��
	/// </summary>
	/// <param name="x">��`�����̂����W</param>
	/// <param name="y">��`�����̂����W</param>
	/// <param name="width">�����̔���</param>
	/// <param name="height">�c���̔���</param>
	/// <returns></returns>
	int DrawRectangle(const bool drawBox, const int x = SCREEN_SIZE_X / 2, const int y = SCREEN_SIZE_Y / 2 + RATIO_Y * 5, const int width = RATIO_X * 15, const int height = RATIO_Y * 5);

private:
	/// <summary>
	/// �v���C���[�摜���i�[����ϐ�
	/// </summary>
	int gHandle;
};