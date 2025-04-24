#include "DxLib.h"
#include "common.h"
#include "draw.h"
#include "box.h"
#include "player.h"
#include "ctime"

/// <summary>
/// �G���[���b�Z�[�W��\����
/// �T�b�ҋ@����
/// </summary>
void ShowErrorMessage()
{
    printfDx("�\�����ʃG���[���������܂����B�T�b��ɃE�B���h�E����܂�");

    // ����ʂ̓��e��\��ʂɔ��f����
    ScreenFlip();

    // �T�b�ҋ@
    WaitTimer(5000);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ������Ԃł̓E�B���h�E���[�h�ɂ��Ă���
    ChangeWindowMode(TRUE);

    // ��ʃ��[�h�̐ݒ�
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

    // �`��\�̈�Z�b�g
    SetDrawArea(0, 0, SCREEN_SIZE_X - 1, SCREEN_SIZE_Y - 1);

    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
    }
    // �`����\��ʂɂ���
    SetDrawScreen(DX_SCREEN_FRONT);

    srand((unsigned int)time(NULL));

    Draw draw;

    Box box1, box2;

    Player player;

    // �Q�[���̏������s��
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    while(true)
    {
        // ��ʂ�����������
        ClearDrawScreen();
        // �`���𗠉�ʂɂ���
        SetDrawScreen(DX_SCREEN_BACK);

        box1.ManagementBox();
        box2.ManagementBox();

        player.JudgeJump();
        player.Fall();

        // �G���[���N�����狭���I������
        if (draw.DrawingScreen(box1.GetDraw(), box2.GetDraw(),
            box1.GetVector2X(), box1.GetVector2Y(), box2.GetVector2X(), box2.GetVector2Y(),
            player.GetDraw(), player.GetVector2X(), player.GetVector2Y()) != 0)
        {
            // �G���[���b�Z�[�W��\������
            // �ܕb��ɃE�C���h�E�����
            ShowErrorMessage();
            break;
        }
        else
        {
            // ����ʂ̓��e��\��ʂɔ��f����
            ScreenFlip();
        }
    }

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}