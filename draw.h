#pragma once

class Draw
{
public:
	Draw();
	virtual ~Draw();

	/// <summary>
	/// ��ʂɊG��`���֐�
	/// </summary>
	int DrawingScreen(const bool drawBox1, const bool drawBox2,
		const int box1X, const int box1Y, const int box2X, const int box2Y,
		const bool drawPlayer, const int playerX, const int playerY);

private:
	/// <summary>
	/// �v���C���[�摜���i�[����ϐ�
	/// </summary>
	int gHandle;
};