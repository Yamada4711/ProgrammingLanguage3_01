#include "DxLib.h"
#include "common.h"
#include "draw.h"
#include "box.h"
#include "player.h"
#include "ctime"
#include "vector"


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

    //Box box1(0), box2(120); // 最初にboxを発生させるタイミングを指定

    std::vector<Box> box(1);

    int countBox = 0; // ステージ上に存在するボックスの数を記録しておく変数

    Player player;
    
    // ジャンプボタンを押し続けた時間を計測する変数
    int countPushJumpButton = 0;

    // ゲームの処理を行う
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    while(true)
    {
        int boxSize = (int)box.size();
        for (int i = 0; i < boxSize; i++)
        {
            // box が地面に落ちたらオブジェクトを消す
            if (box.at(i).JudgeErase())
            {
                box.at(i).~Box();
                boxSize--;
                i--;
            }
        }

        // プレイヤーの生存確認
        player.JudgeDeath();

        // 画面を初期化する
        ClearDrawScreen();
        // 描画先を裏画面にする
        SetDrawScreen(DX_SCREEN_BACK);

        //box1.CountStart();
        //box2.CountStart();

        // 当たり判定の確認
        for (int i = 0; i < box.size(); i++)
        {
            bool touchBox = box.at(i).GetTouchPlayer();
            box.at(i).SetTouchPlayer(player.JudgeTouchBox(box.at(i)));
            if (touchBox != box.at(i).GetTouchPlayer())
            {
                Box boxSub;
                box.push_back(boxSub);
            }
        }

        // 矩形を移動させる
        for (int i = 0; i < box.size(); i++)
        {
            box.at(i).ManagementBox();
        }


        // プレイヤーがジャンプ中じゃなければ落下させる ( -1 = ジャンプしてない)
        player.Jump();
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
        /*if (draw.DrawingScreen(box1.GetDraw(), box2.GetDraw(),
            box1.GetVector2X(), box1.GetVector2Y(), box2.GetVector2X(), box2.GetVector2Y(),
            player.GetDraw(), player.GetVector2X(), player.GetVector2Y()) != 0)*/
       
        
        if (draw.DrawThorns() != 0 || // とげを描く
            draw.DrawRectangle(true) != 0 || // プレイヤーの初期位置の足場を描画する
            draw.DrawPlayerCharacter(player.GetDraw(), player.GetVector2X(), player.GetVector2Y()) != 0) // プレイヤーを描画する
        { 
            // エラーメッセージを表示して
            // 五秒後にウインドウを閉じる
            ShowErrorMessage();
            DxLib_End();
        }
        else
        {
            for (int i = 0; i < box.size(); i++)
            {
                if (draw.DrawRectangle(box.at(i).GetDraw(), box.at(i).GetVector2X(), box.at(i).GetVector2Y()) != 0)
                {
                    // エラーメッセージを表示して
                    // 五秒後にウインドウを閉じる
                    ShowErrorMessage();
                    DxLib_End();
                }
            }
            // 裏画面の内容を表画面に反映する
            ScreenFlip();
        }
    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}