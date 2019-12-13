#include <stdio.h>

void print(char arr[]) {
	printf("\n");
	printf("  %c | %c  | %c  \n", arr[0], arr[1], arr[2]);
	printf("\n");
	printf("  %c | %c  | %c  \n", arr[3], arr[4], arr[5]);
	printf("\n");
	printf("  %c | %c  | %c  \n", arr[6], arr[7], arr[8]);
	printf("\n");
}
int main() {
	int winner = 0, count = 0;
	int index, flag, i, k, j;
	char sign, data[9];

	for (i = 0; i < 9; i++)
		data[i] = ' ';

	while (count < 9) {
		flag = 0;
		if (count % 2 == 0) {
			sign = 'X';
		}
		else {
			sign = 'O';
		}
		printf("Player %c:\n", sign);
		scanf("%d", &index);
		data[index - 1] = sign;
		count++;
		print(data);

		for (i = 0; i < 9; i++) {
			if (i % 3 == 0)
				flag = 0;

			if (data[i] == sign)
				flag++;

			if (flag == 3) {
				winner = 1;
				printf("Player %c is the winner.\n", sign);
				return 0;
			}
		}

		flag = 0;
		for (i = 0; i < 3; i++) {
			for (k = i; k <= i + 6; k = k + 3) {
				if (data[k] == sign)
					flag++;
			}
			if (flag == 3) {
				winner = 1;
				printf("Player %c is the winner.\n", sign);
				return 0;
			}
			flag = 0;
		}
		if ((data[0] == sign && data[4] == sign && data[8] == sign) ||
			(data[2] == sign && data[4] == sign && data[6] == sign)) {
			winner = 1;
			printf("Player %c is the winner.\n", sign);
			return 0;
		}
	}

	if (!winner)
		printf("The End...Without any winner!\n");
	return 0;
}