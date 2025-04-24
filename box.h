#pragma once
#include "common.h"

class Box
{
public:
	Box();
	~Box();

	/// <summary>
	/// ��`�̏�Ԃ��m�F���ēK�؂Ȋ֐����Ă�
	/// </summary>
	/// <returns></returns>
	int ManagementBox();

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

	/// <summary>
	/// ��`�̐i�s�����͍��ł��邩�ۂ�
	/// </summary>
	bool moveLeft;

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
	};

	/// <summary>
	/// ��`�̏�ԊǗ��p
	/// </summary>
	State state;
};