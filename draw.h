#pragma once

class Draw
{
public:
	Draw();
	~Draw();
	/// <summary>
	/// ��ʂɊG��`���֐�
	/// </summary>
	int DrawingScreen();

private:
	/// <summary>
	/// �v���C���[�摜���i�[����ϐ�
	/// </summary>
	int gHandle;
};