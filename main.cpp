#include "DxLib.h"
#include "common.h"
#include "draw.h"
#include "box.h"
#include "player.h"
#include "ctime"

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

    srand((unsigned int)time(NULL));

    Draw draw;

    Box box1(0), box2(120); // 最初にboxを発生させるタイミングを指定

    Player player;
    
    // ジャンプボタンを押し続けた時間を計測する変数
    int countPushJumpButton = 0;

    // ゲームの処理を行う
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    while(true)
    {
        // プレイヤーの生存確認
        player.JudgeDeath();

        // 画面を初期化する
        ClearDrawScreen();
        // 描画先を裏画面にする
        SetDrawScreen(DX_SCREEN_BACK);

        box1.CountStart();
        box2.CountStart();

        // 当たり判定の確認
        box1.SetTouchPlayer(player.JudgeTouchBox(box1));
        box2.SetTouchPlayer(player.JudgeTouchBox(box2));

        // 矩形を移動させる
        box1.ManagementBox();
        box2.ManagementBox();


        // プレイヤーがジャンプ中じゃなければ落下させる ( -1 = ジャンプしてない)
        if (player.Jump() == -1)
        {
        }
            player.Fall();
            player.TouchBoxFall();

        // スペースキーでジャンプする
        if (CheckHitKey(KEY_INPUT_SPACE) == 1)
        {
            countPushJumpButton++;
        }
        else if (countPushJumpButton > 0)
        {
            player.JudgeJump(countPushJumpButton);
            countPushJumpButton = 0; // ボタンを押し続けた時間をリセットする
        }



        // エラーが起きたら強制終了する
        if (draw.DrawingScreen(box1.GetDraw(), box2.GetDraw(),
            box1.GetVector2X(), box1.GetVector2Y(), box2.GetVector2X(), box2.GetVector2Y(),
            player.GetDraw(), player.GetVector2X(), player.GetVector2Y()) != 0)
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