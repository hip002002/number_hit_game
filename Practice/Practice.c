#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ANSWER_MAX_NUM 100
#define ANSWER_MIN_NUM 1

int main(void) {
	char input_string[100];
	long input_long_num = 0;
	int input_int_num = 0;
	int answer_num = 0;
	int trial_num = 0;
	bool bingo_result = false;
	char* input_string_endptr;

	srand((unsigned int)time(NULL));
	answer_num = (rand() % (ANSWER_MAX_NUM -ANSWER_MIN_NUM +1)) + ANSWER_MIN_NUM;

	printf("%d～%dまでの整数を入力してください!\n", ANSWER_MIN_NUM, ANSWER_MAX_NUM);

	while (bingo_result == false) {
		trial_num++;
		printf("プレイヤーの入力値は：");
		fgets(input_string, sizeof(input_string), stdin);
		input_string[strcspn(input_string, "\n")] = '\0';
		input_long_num = strtol(input_string, &input_string_endptr, 10);
		input_int_num = input_long_num;
		if (*input_string_endptr == '\0' && input_string[0] != '\0') {
			if ((input_int_num < ANSWER_MIN_NUM) || (input_int_num > ANSWER_MAX_NUM)) {
				printf("NGな値が入力されています。\n");
				printf("%d～%dの整数を入れましょう\n", ANSWER_MIN_NUM, ANSWER_MAX_NUM);
			}
			else if (input_int_num > answer_num) {
				printf("Big\n");
				printf("%dより小さい整数を入れましょう\n", input_int_num);
			}
			else if (input_int_num < answer_num) {
				printf("Small\n");
				printf("%dより大きい整数を入れましょう\n", input_int_num);
			}
			else {
				printf("Bingo!\n");
				bingo_result = true;
			}
		}
		else {
			printf("数値のみの入力がされてません。数値を入力してください。\n");
		}
	} 
	printf("プレイヤーは%d回で当てることができました。\n", trial_num);
	return 0;
}