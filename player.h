#pragma once
#include "common.h"
#include "box.h"

class Player
{
public:
	Player();
	virtual ~Player();


	/// <summary>
	/// �W�����v�̏����𑱍s�\���ǂ������f����
	/// </summary>
	/// <returns></returns>
	int JudgeJump();

	/// <summary>
	/// ��`�ɒ��n���Ă��邩�ǂ������肷��
	/// </summary>
	/// <returns></returns>
	bool JudgeTouchBox(Box& box);

	/// <summary>
	/// ��`�ɐG�ꂽ��Ԃł̗���
	/// </summary>
	int TouchBoxFall();

	/// <summary>
	/// �������鏈��
	/// </summary>
	/// <returns></returns>
	int Fall();

	/// <summary>
	/// �v���C���[�̂����W��n��
	/// </summary>
	/// <returns></returns>
	int GetVector2X();
	/// <summary>
	/// �v���C���[�̂����W��n��
	/// </summary>
	/// <returns></returns>
	int GetVector2Y();
	/// <summary>
	/// �v���C���[��`�悷�邩�ۂ���n��
	/// </summary>
	/// <returns></returns>
	bool GetDraw();

private:
	/// <summary>
	/// �v���C���[���㏸���鏈��
	/// </summary>
	/// <returns></returns>
	int Jump();

private:
	/// <summary>
	/// �v���C���[�̒����̍��W
	/// </summary>
	struct Vector2
	{
		// �v���C���[�̂����W
		int x = SCREEN_SIZE_X / 2;
		// �v���C���[�̂����W
		int y = SCREEN_SIZE_Y / 2 - RATIO_X * RATIO_Y * 2;
	};

	/// <summary>
	/// �v���C���[�̒����̍��W
	/// </summary>
	Vector2 vector2;

	/// <summary>
	/// �v���C���[�̃T�C�Y�̔���(�c����P�F�P)
	/// </summary>
	const int halfSize = RATIO_X * RATIO_Y * 2;

	/// <summary>
	/// ��ԊǗ��p
	/// </summary>
	enum State
	{
		// ����ɐG��Ă����ԁi����ƂƂ��ɗ������Ă����ԁj
		TOUCH_BOX,
		// �W�����v�L�[��������Ĕ�яオ���Ă���Œ�
		JUMP,
		// ���ꂪ�Ȃ��ė������Ă���Œ��iTOUCH_BOX��藎�����x�������j
		FALL,
		// �Ƃ��ɓ������Ď���
		DEATH,
	};

	/// <summary>
	/// ��ԊǗ��p
	/// </summary>
	State state;

	/// <summary>
	/// ��i�W�����v�ł��Ȃ��悤�ɂ��邽�߂̕ϐ�
	/// </summary>
	bool jump;

	/// <summary>
	/// ���W�����v�̏������ǂꂭ�炢�i�񂾂�
	/// </summary>
	int jumpCount;
	/// <summary>
	/// �W�����v�̏������s������
	/// </summary>
	const int jumpCountMax = 30;

	/// <summary>
	/// �ɂ₩�ɗ������鏈�����s�����񐔂��J�E���g
	/// </summary>
	int fallCount;

	/// <summary>
	/// �v���C���[��`�悷�邩�ۂ�
	/// </summary>
	bool draw;
};