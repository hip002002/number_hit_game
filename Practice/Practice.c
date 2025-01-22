#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
	int input_num = 0;
	int answer_num = 0;
	int trial_num = 0;
	int max_num = 100;
	int min_num = 1;
	bool loop_escape_result = false;
	char irregular_message[100] = "NGな値が入力されています。";
	char compare_big_message[100] = "Big";
	char compare_small_message[100] = "Small";
	char compare_bingo_message[100] = "Bingo!";
	char input_message[100] = "プレイヤーの入力値は：";

	srand((unsigned int)time(NULL));
	answer_num = (rand() % max_num) + min_num;

	printf("%d～%dまでの整数を入力してください!\n", min_num, max_num);

	do {
		printf("%s", input_message);
		scanf_s("%d", &input_num);

		if ((input_num < min_num) || (input_num > max_num)) {
			printf("%s\n", irregular_message);
			printf("%d～%dの整数を入れましょう\n", min_num, max_num);
		}
		else {
			if (input_num > answer_num) {
				printf("%s\n", compare_big_message);
				printf("%dより小さい整数を入れましょう\n", input_num);
			}
			else if (input_num < answer_num) {
				printf("%s\n", compare_small_message);
				printf("%dより大きい整数を入れましょう\n", input_num);
			}
			else {
				printf("%s\n", compare_bingo_message);
				loop_escape_result = true;
			}
		}
		trial_num++;
	} while (loop_escape_result = false);

	printf("プレイヤーは%d回で当てることができました。\n", trial_num);
	return 0;
}