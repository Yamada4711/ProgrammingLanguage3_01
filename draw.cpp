#include "DxLib.h"
#include "draw.h"

/// <summary>
/// プレイヤー画像を設定する
/// </summary>
/// <returns></returns>
int SetPlayerGraph()
{
	return LoadGraph("BunnyGirlAnimation01.bmp");
}

Draw::Draw()
{
	// プレイヤー画像を設定する
	gHandle = SetPlayerGraph();
}

Draw::~Draw()
{
	DeleteGraph(gHandle);
}



/// <summary>
/// とげを描く
/// </summary>
/// <returns></returns>
int Draw::DrawThorns()
{
	// とげの横幅(必ず2の倍数にすること)(固定)
	const int width = RATIO_X * 10;
	// とげの縦幅(固定)
	const int height = RATIO_Y * 15;

	// とげの描画を開始するXの位置(固定)
	const int startPosX = 0;
	// とげの描画を終わるXの位置(固定)
	const int endPosX = SCREEN_SIZE_X;

	// とげの底面の位置(固定)
	const int bottomPos = SCREEN_SIZE_Y;

	// とげを描画する回数(可変)
	int drawMax = (endPosX - startPosX) / width;

	// とげの色を指定 4/17時点では黄色(固定)
	const unsigned int color = GetColor(255, 255, 0);

	// 三角形の描画関数の引数の値を
	// 三角形の左下、右下、上の順に
	// 初期化する
	
	// x座標(可変)
	int x1 = startPosX,
		x2 = x1 + width,
		x3 = x1 + (width / 2);

	// y座標(固定)
	const int y1 = bottomPos,
		y2 = y1,
		y3 = bottomPos - height;

	// とげを描画する回数が0になるまでとげの描画を行う
	while (drawMax > 0)
	{
		if (x1 < startPosX || x2 > endPosX)
		{
			printfDx("エラー：draw.cppのDrawThorns関数が範囲外にとげを描こうとしているようだ");
			return ERROR_OCCURRED;
		}
		// とげの三角形の描画を行う
		DrawTriangle(x1, y1, x2, y2, x3, y3, color, TRUE);

		// 次のとげの位置を指定する(xのみ変更)
		x1 += width, x2 += width, x3 += width;

		// とげを描画する回数を１減らす
		drawMax--;
	}
	return 0;
}

/// <summary>
/// 矩形を描く
/// </summary>
/// <param name="x">矩形中央のｘ座標</param>
/// <param name="y">矩形中央のｙ座標</param>
/// <param name="width">横幅の半分</param>
/// <param name="height">縦幅の半分</param>
/// <returns></returns>
int Draw::DrawRectangle (const bool drawBox, const int x, const int y, const int width, const int height)
{
	if (drawBox)
	{
		// 矩形の色を指定する（青色）（固定）
		const unsigned int color = GetColor(0, 0, 255);

		// 矩形を描画する座標を指定する(固定)
		const int x1 = x - width, y1 = y - height;
		const int x2 = x + width - 1, y2 = y + height - 1;
		DrawBox(x1, y1, x2, y2, color, TRUE);
	}
	return 0;
}

/// <summary>
/// キャラクター画像のサイズを調整しつつ描画する
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="gHandle"></param>
/// <returns></returns>
int Draw::DrawPlayerCharacter (const bool drawPlayer, const int x, const int y, const int halfSize)
{
	if (drawPlayer)
	{
		// 画像読み込みがちゃんとできているかどうか確認する
		if (gHandle == -1)
		{
			printfDx("エラー：グラフィックデータの読み込みに失敗しているよ");
			return ERROR_OCCURRED;
		}

		// プレイヤーを描画する位置
		const int x1 = x - halfSize, y1 = y - halfSize,
			x2 = x + halfSize, y2 = y + halfSize;

		DrawExtendGraph(x1, y1, x2, y2, gHandle, TRUE);
	}
	return 0;
}



//int Draw::DrawingScreen(const bool drawBox1, const bool drawBox2,
//	const int box1X, const int box1Y, const int box2X, const int box2Y,
//	const bool drawPlayer, const int playerX, const int playerY)
//{
//	// とげを描く
//	if (DrawThorns() != 0) return ERROR_OCCURRED;
//
//	// 矩形1を描く
//	if (drawBox1)
//	{
//		if (DrawRectangle(drawBox1, box1X, box1Y) != 0) return ERROR_OCCURRED;
//	}
//	// 矩形2を描く
//	if (drawBox2)
//	{
//		if (DrawRectangle(drawBox2, box2X, box2Y) != 0) return ERROR_OCCURRED;
//	}
//	// 矩形3を描く
//	if (DrawRectangle(true , SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2 + RATIO_Y * 5) != 0) return ERROR_OCCURRED;
//
//	// プレイヤーを描画する
//	if (DrawPlayerCharacter(gHandle, drawPlayer, playerX, playerY) != 0) return ERROR_OCCURRED;
//
//	return 0;
//}