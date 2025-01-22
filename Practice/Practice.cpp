#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	// 変数宣言
	int g_player_num = 0;  //プレイヤーの指定する数値
	int g_cpu_num = 0;  //CPUのランダムで指定する数値
	int i = 0; //プレイヤーの試行回数

	// CPU側の乱数を設定
	srand((unsigned int)time(NULL));
	g_cpu_num = rand() % 100 + 1;

	// ユーザーが入力範囲を把握するために表示
	printf("1～100までの整数を入力してください!\n");

	// プレイヤーの数当てループ
	do {
		// プレイヤー側の数値の入力
		printf("プレイヤーの入力値は：");
		scanf_s("%d", &g_player_num);

		// 入力値が範囲外である時
		if (g_player_num < 1 || g_player_num > 100) {
			// NGメッセージの表示
			printf("NGな値が入力されています。\n");
			printf("1～100の整数を入れましょうorz\n");
		}
		// 入力値が1～100の整数である時
		else {
			// プレイヤーとCPUの数値の比較
			// プレイヤーの数値がCPUの数値より大きい場合
			if (g_player_num > g_cpu_num) {
				// プレイヤーがCPUより大きい値である表示
				printf("Big\n");
				printf("%dより小さい値を入れましょうorz\n", g_player_num);
			}
			// プレイヤーの数値がCPUの数値より小さい場合
			else if (g_player_num < g_cpu_num) {
				// プレイヤーがCPUより小さい値である表示
				printf("Small\n");
				printf("%dより大きい値を入れましょうorz\n", g_player_num);
			}
			// プレイヤーが一致する数値をあてた場合
			else {
				// プレイヤーが一致する数値をあてた際の表示
				printf("Bingo!\n");
			}

		}
		i++;
	} while (g_player_num != g_cpu_num);

	// プレイヤーの試行回数を表示
	printf("プレイヤーは%d回で当てることができました。\n", i);
	return 0;
}