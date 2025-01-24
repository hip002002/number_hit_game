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

	printf("%d�`%d�܂ł̐�������͂��Ă�������!\n", ANSWER_MIN_NUM, ANSWER_MAX_NUM);

	while (bingo_result == false) {
		trial_num++;
		printf("�v���C���[�̓��͒l�́F");
		fgets(input_string, sizeof(input_string), stdin);
		input_string[strcspn(input_string, "\n")] = '\0';
		input_long_num = strtol(input_string, &input_string_endptr, 10);
		input_int_num = input_long_num;
		if (*input_string_endptr == '\0' && input_string[0] != '\0') {
			if ((input_int_num < ANSWER_MIN_NUM) || (input_int_num > ANSWER_MAX_NUM)) {
				printf("NG�Ȓl�����͂���Ă��܂��B\n");
				printf("%d�`%d�̐��������܂��傤\n", ANSWER_MIN_NUM, ANSWER_MAX_NUM);
			}
			else if (input_int_num > answer_num) {
				printf("Big\n");
				printf("%d��菬�������������܂��傤\n", input_int_num);
			}
			else if (input_int_num < answer_num) {
				printf("Small\n");
				printf("%d���傫�����������܂��傤\n", input_int_num);
			}
			else {
				printf("Bingo!\n");
				bingo_result = true;
			}
		}
		else {
			printf("���l�݂̂̓��͂�����Ă܂���B���l����͂��Ă��������B\n");
		}
	} 
	printf("�v���C���[��%d��œ��Ă邱�Ƃ��ł��܂����B\n", trial_num);
	return 0;
}