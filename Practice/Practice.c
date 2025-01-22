#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int input_num = 0;
	int answer_num = 0;
	int trial_num = 0;
	int max_num = 100;
	int min_num = 1;
	int loop_escape_num = 0;
	char irregular_message[100] = "NG�Ȓl�����͂���Ă��܂��B";
	char compare_big_message[100] = "Big";
	char compare_small_message[100] = "Small";
	char compare_bingo_message[100] = "Bingo!";

	srand((unsigned int)time(NULL));
	answer_num = (rand() % max_num) + min_num;

	printf("%d�`%d�܂ł̐�������͂��Ă�������!\n", min_num, max_num);

	do {
		printf("�v���C���[�̓��͒l�́F");
		scanf_s("%d", &input_num);

		if ((input_num < min_num) || (input_num > max_num)) {
			printf("%s\n", irregular_message);
			printf("%d�`%d�̐��������܂��傤orz\n", min_num, max_num);
		}
		else {
			if (input_num > answer_num) {
				printf("%s\n", compare_big_message);
				printf("%d��菬�����l�����܂��傤orz\n", input_num);
			}
			else if (input_num < answer_num) {
				printf("%s\n", compare_small_message);
				printf("%d���傫���l�����܂��傤orz\n", input_num);
			}
			else {
				printf("%s\n", compare_bingo_message);
				loop_escape_num = 1;
			}
		}
		trial_num++;
	} while (loop_escape_num != 1);

	printf("�v���C���[��%d��œ��Ă邱�Ƃ��ł��܂����B\n", trial_num);
	return 0;
}