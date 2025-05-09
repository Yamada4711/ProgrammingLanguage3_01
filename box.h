#pragma once
#include "common.h"
#include "tuple"

class Box
{
public:
	Box(int countS);
	Box();
	virtual ~Box();

	/// <summary>
	/// ��`�̏�Ԃ��m�F���ēK�؂Ȋ֐����Ă�
	/// </summary>
	/// <returns></returns>
	int ManagementBox();

	/// <summary>
	/// �v���C���[�ɐG��Ă��邩�ۂ���ϐ��ɓ����
	/// </summary>
	/// <returns></returns>
	int SetTouchPlayer(bool touch);

	/// <summary>
	/// �����W�擾�p
	/// </summary>
	/// <returns></returns>
	int GetVector2X();
	/// <summary>
	/// �����W�擾�p
	/// </summary>
	/// <returns></returns>
	int GetVector2Y();
	/// <summary>
	/// �`�悷�邩�ǂ����擾�p
	/// </summary>
	/// <returns></returns>
	bool GetDraw();

	/// <summary>
	/// �N�������܂ł̎��Ԃ��J�E���g�_�E��
	/// </summary>
	/// <returns></returns>
	int CountStart();

	/// <summary>
	/// ��`�̍�����W�ƉE�����W��Ԃ��֐�<����x y, �E��x y>
	/// </summary>
	/// <returns></returns>
	std::tuple<int, int, int, int> GetBoxCoordinate();

	/// <summary>
	/// �v���C���[�ɐG��Ă��邩�ۂ����擾
	/// </summary>
	/// <returns></returns>
	bool GetTouchPlayer();

	/// <summary>
	/// ���݂�state��ERASE�ł��邩�ۂ�
	/// </summary>
	/// <returns></returns>
	bool JudgeErase();

private:
	/// <summary>
	/// ��`�𐶐�����
	/// </summary>
	/// <returns></returns>
	int GenerateBox();

	/// <summary>
	/// ��`�����ړ�������֐�
	/// </summary>
	/// <returns></returns>
	int LateralMovement();

	/// <summary>
	/// ��`���c�ړ�������֐�
	/// </summary>
	/// <returns></returns>
	int VerticalMovement();

	/// <summary>
	/// ��`�����ł�����
	/// </summary>
	/// <returns></returns>
	int EraseBox();

private:
	// ��`�̒����̍��W
	struct Vector2
	{
		int x = 0;
		int y = RATIO_Y * 60;
	};

	/// <summary>
	/// ��`��`�悷�邩�ۂ�
	/// </summary>
	bool draw;

	int countStart;

	/// <summary>
	/// ��`�̐i�s�����͍��ł��邩�ۂ�
	/// </summary>
	bool moveLeft;

	/// <summary>
	/// �v���C���[�ɐG��Ă��邩�ۂ�
	/// </summary>
	bool touchPlayer;

	/// <summary>
	/// ��`�̒����̍��W
	/// </summary>
	Vector2 vector2;

	/// <summary>
	/// ��`�̉����̔����̒l
	/// </summary>
	const int halfWidth = RATIO_X * 15;
	/// <summary>
	/// ��`�̏c���̔����̒l
	/// </summary>
	const int halfHeight = RATIO_Y * 5;

	/// <summary>
	/// ��`�̏�ԊǗ��p
	/// </summary>
	enum State
	{
		// ��ȁi���̋�`�𐶐�����j
		EMPTY,

		// ���ړ���
		LATERAL_MOVEMENT,

		// ������
		VARTICAL_MOVEMENT,

		// ���ł�����
		ERASE,

		// �N���ҋ@���
		COUNT
	};

	/// <summary>
	/// ��`�̏�ԊǗ��p
	/// </summary>
	State state;
};