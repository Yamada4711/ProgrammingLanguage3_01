#include "DxLib.h"
#include "common.h"
#include "draw.h"

/// <summary>
/// エラーメッセージを表示し
/// ５秒待機する
/// </summary>
void ShowErrorMessage()
{
    printfDx("予期せぬエラーが発生しました。５秒後にウィンドウを閉じます");

    // 裏画面の内容を表画面に反映する
    ScreenFlip();

    // ５秒待機
    WaitTimer(5000);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 初期状態ではウィンドウモードにしておく
    ChangeWindowMode(TRUE);

    // 画面モードの設定
    SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

    // 描画可能領域セット
    SetDrawArea(0, 0, SCREEN_SIZE_X - 1, SCREEN_SIZE_Y - 1);

    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }
    // 描画先を表画面にする
    SetDrawScreen(DX_SCREEN_FRONT);

    Draw draw;

    // ゲームの処理を行う
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    while(true)
    {
        // 画面を初期化する
        ClearDrawScreen();
        // 描画先を裏画面にする
        SetDrawScreen(DX_SCREEN_BACK);
        // エラーが起きたら強制終了する
        if (draw.DrawingScreen() != 0)
        {
            // エラーメッセージを表示して
            // 五秒後にウインドウを閉じる
            ShowErrorMessage();
            break;
        }
        else
        {
            // 裏画面の内容を表画面に反映する
            ScreenFlip();
        }
    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}