#pragma once


// << スクリーンサイズ関係の値 >>

// 画面比率をX:Y＝４：３にする
#define RATIO_X 4
// 画面比率をX:Y＝４：３にする
#define RATIO_Y 3

// 画面サイズの倍率(必ず10の倍数にすること)
#define SCREEN_MAGNIFICATION 200

// 画面のX方向の大きさ
#define SCREEN_SIZE_X RATIO_X * SCREEN_MAGNIFICATION
// 画面のY方向の大きさ
#define SCREEN_SIZE_Y RATIO_Y * SCREEN_MAGNIFICATION


// << エラーが起きたときの処理に使う値 >>
#define ERROR_OCCURRED -1;