#include <stdio.h>
#pragma warning (disable : 4996)

//1 // �л��� ������ ����ϴ� ���α׷�
typedef struct s_core // �л����� ������ ���� ����ü ����
{
	char name[3]; // �л����� �̸�
	int korean; // �����
	int english; // �����
	int math; // ���м���
	int total; // ����
	double average; // ���
}Score; // Score��� ���ο� �ڷ��� ����
void InputScore(Score* arr, int n) // �л����� ������ �Է¹ޱ� ���� �Լ�
{
	for (int i = 0; i < n; i++)
	{
		printf("%d��° �л� ���� �Է�\n", i + 1); // �Է� ����
		printf("�̸� :"); scanf("%s", &(arr + i)->name); // �Է¹��� �̸��� �ڷ����� Score�� arr[i]�� name�� ����
		printf("���� :"); scanf("%d", &(arr + i)->korean); // �Է¹��� ������� �ڷ����� Score�� arr[i]�� korean�� ����
		printf("���� :"); scanf("%d", &(arr + i)->english); // �Է¹��� ������� �ڷ����� Score�� arr[i]�� english�� ����
		printf("���� :"); scanf("%d", &(arr + i)->math); // �Է¹��� ���м����� �ڷ����� Score�� arr[i]�� math�� ����
		(arr + i)->total = (arr + i)->korean + (arr + i)->english + (arr + i)->math; // arr[i]�� korean�� english�� math�� ��� ���� ���� arr[i]�� total�� ����
		(arr + i)->average = ((double)(arr + i)->total / 3.00); // �� ������ ����� ���� ���� arr[i]�� average�� ����
	}
}
void PrnScore(Score* arr, int n) // ��ü �л����� ������ ����ϴ� �Լ�
{
	for (int i = 0; i < n; i++)
	{
		printf("%d��° �л� ���� �̸� : %s ���� : %3d ���� : %3d ���� : %3d ���� : %3d ��� : %.2lf\n", i + 1, (arr + i)->name, (arr + i)->korean, (arr + i)->english, (arr + i)->math, (arr + i)->total, (arr + i)->average);
	    // �� �л��� ������ ��� ���
	}
}
int FindScore(Score* arr, char* name, int n) // ���ϴ� �л��� ������ ����ϴ� �Լ�
{
	for (int i = 0; i < n; i++)
	{
		int ret = strcmp((arr + i)->name, name); // ���� arr�� �ִ� �̸� �� �Է¹��� name�� ���� �̸��� �ִ��� �Ǵ��ϴ� ���ڿ� �Լ� ���
		// ������ ret�� 0 ����, �ٸ��� ret�� 0�� �ƴ� �� ����
		if (ret == 0) // �̸��� ���� �� �ִٸ�
		{
			// �� �л��� ���� ���
			printf("%s �л� ���� �̸� : %s ���� : %d ���� : %d ���� : %d ���� : %d ��� : %.2lf\n", (arr + i)->name, (arr + i)->name, (arr + i)->korean, (arr + i)->english, (arr + i)->math, (arr + i)->total, (arr + i)->average);
			return 1; // 1�� ������
		}
		else if (ret != 0) // �̸��� ���� �� ���ٸ�
		{
			continue; // ���� �ε����� �̸��� ��
		}
	}
	printf("%s �л��� �����ϴ�.\n", name); // ���� �̸��� ���� �ݺ����� ���������� �ȴٸ� name�� ���� �̸��� ���ٰ� ���
	return -1; // 1�� ������
}
int main()
{
	Score arr[3] = { 0 }; // �л����� ������ ���� ����ü �迭 arr ����
	int sel = 0; // �� ���� Ž���� ������ �˾Ƴ� ���� ����
	while (1)
	{
		printf("==============================\n"); // ���м� ���
		printf("1 . �л� ���� �Է�\n"); // 1���� �л��� ���� �Է�
		printf("2 . �л� ���� Ȯ��\n"); // 2���� �л��� ���� ��ü Ȯ��
		printf("3 . �л� ���� ã��\n"); // 3���� ���ϴ� �л��� ���� ���
		printf("4 . ����\n"); // 4���� ���α׷� ����
		printf("==============================\n"); // ���м� ���
		printf(">> "); // ��ȣ�� �ޱ� ���� ���к�ȣ ���
		scanf("%d", &sel); // Ž���� ��ȣ�� sel�� ����
		if (sel == 1) // sel�� 1�̶��
		{
			printf("�л� ���� �Է�\n"); // �л����� ������ �Է¹ޱ� ���� ���� ���
			InputScore(arr, 3); // InputScore �Լ��� �̿��Ͽ� �л����� ������ �Է¹���
		}
		else if (sel == 2) // sel�� 2�̶��
		{
			PrnScore(arr, 3); // ��� �л��� ������ ���
		}
		else if (sel == 3) // sel�� 3�̶��
		{
			while (1) // ���ϴ� �л��� ���� ���
			{
				char name[10] = { 0 }; // ã����� �л��� �̸��� ������ ���ڿ� �迭
				printf("ã�� ���� �л� �̸� :"); // �̸��� �Է¹��� ���� ���
				scanf("%s", name); // �Է¹��� �̸��� name�� ����
				int cnt = FindScore(arr, name, 3); // FindScore �Լ��� �̿��Ͽ� �Է¹��� �̸��� ���� arr�� ������ִ� �̸���� ���� ���� �ִ��� �Ǵ��Ͽ�
				// ���� �� �ִٸ� �� �л��� ������ ����ϰ� cnt�� 1�� ����
				// ���� �� ���ٸ� cnt�� -1�� ����
				if (cnt == 1) // cnt�� 1�̶��
				{
					break; // while�� ��������
				}
				else if (cnt == -1) // cnt�� -1�̶��
				{
					continue; // ã�� ���� �̸��� �ٽ� �Է¹����� while���� ó������ ���ư�
				}
			}
		}
		else // sel�� 1,2,3�� �ƴ϶��
		{
			printf("����\n"); // ���α׷� ���Ḧ �˸��� ���� ���
			break; // while�� ��������
		}
	}
	return 0; // main�� ����
}
