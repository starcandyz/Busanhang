#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>

#define LEN_MIN 15
#define LEN_MAX 50
#define PROB_MIN 10
#define PROB_MAX 90

int main(void) {
	srand((unsigned int)time(NULL));

	printf("-------------------------------------------------------------\n");
	printf("-------------------�λ��� start------------------------------\n");
	printf("--------------------20242401---------------------------------\n\n\n");

	Sleep(2000);


	int len, C, Z, M, p;
	printf("train length(15~50)>>");  scanf_s("%d", &len);
	printf("percentile probability 'p'(10~90)>>"); scanf_s("%d", &p);
	M = len - 2; Z = len - 3; C = len - 6;//�� ������ �Ҵ��ϴ� ���� ��ġ��ȣ. 0���� ����.

	if (len > LEN_MAX || len <LEN_MIN || p > PROB_MAX || p < PROB_MIN) { exit(0); }//�Է°� �߸��Ǹ� ����



	//�ʱ� ���� ���
	for (int i = 0; i <= len - 1; i++) { printf("#"); }
	printf("\n");//first line

	printf("#");
	for (int i = 1; i < C; i++) { printf(" "); }
	printf("C");
	for (int i = C + 1; i < Z; i++) { printf(" "); }
	printf("Z");
	for (int i = Z + 1; i < M; i++) { printf(" "); }
	printf("M"); printf("#");  printf("\n");//second line

	for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
	printf("\n\n\n");



	while (1) {//Ȧ�� �� �ù��̳� ���� ���� ����


		int r = rand() % 100; //citizen staying or moving
		if (p <= r && r < 100) { C--; }
		else { C; }

		int k = rand() % 100; //zombie staying or moving
		if (0 <= k && k < p) { Z--; }
		else { Z; }

		//���� ���� ���
		for (int i = 0; i <= len - 1; i++) { printf("#"); } //first line
		printf("\n");

		printf("#"); //second line
		for (int i = 1; i < C; i++) { printf(" "); }
		printf("C");
		for (int i = C + 1; i < Z; i++) { printf(" "); }
		printf("Z");
		for (int i = Z + 1; i < M; i++) { printf(" "); }
		printf("M"); printf("#");  printf("\n");

		for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
		printf("\n\n\n");

		//Ȧ�� �� �ù�, ���� ���� ���
		if (p <= r && r < 100) { printf("citizen : %d -> %d\n", C + 1, C); }
		else { printf("citizen : stay %d\n", C); }

		if (0 <= k && k < p) { printf("zombie : %d -> %d\n", Z + 1, Z); }
		else { printf("zombie : stay %d\n", Z); }
		printf("\n\n\n");
		//Ȧ�� �� ��
		if (Z - C == 1 || C == 1) { break; }
		Sleep(4000);



		//¦�� �� �ù� ���� ���� (����� ¦�� �Ͽ� �������� �ʴ´�.)
		int h = rand() % 100;
		if (p <= h && h < 100) { C--; }
		else { C; }

		//���� ���� ���

		for (int i = 0; i <= len - 1; i++) { printf("#"); } //first line
		printf("\n");

		printf("#"); //second line
		for (int i = 1; i < C; i++) { printf(" "); }
		printf("C");
		for (int i = C + 1; i < Z; i++) { printf(" "); }
		printf("Z");
		for (int i = Z + 1; i < M; i++) { printf(" "); }
		printf("M"); printf("#");  printf("\n");

		for (int i = 0; i <= len - 1; i++) { printf("#"); } //third line
		printf("\n\n\n");

		//¦�� �� �ù�, ���� ���� ���
		if (p <= h && h < 100) { printf("citizen : %d -> %d\n", C + 1, C); }
		else { printf("citizen : stay %d\n", C); }

		printf("zombie : stay %d (cannot move)\n", Z);
		printf("\n\n\n");
		//¦�� �� ��

		if (Z - C == 1 || C == 1) { break; }
		Sleep(4000);
	}

	if (Z - C == 1) { printf("GAME OVER!\nCitizen(s) has(have) been attaked by a zombie"); }
	if (C == 1) { printf("STAGE CLEAR!\ncitizen(s) escaped to the next train"); }



	return 0;
}