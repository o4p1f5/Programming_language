#include <stdio.h>
#pragma warning (disable : 4996)

//1 ���Ҽ�
typedef struct _complex // typedef�� ����ؼ� ����ü ����
{
	double real; // ���Ҽ��� �Ǽ���
	double image; // ���Ҽ��� �����
} Complex; // struct _complex == Complex
// ���ο� �ڷ��� 'Complex'
int main()
{
	Complex Z1 = { 0 , 0 }; // ù��° ���Ҽ��� �ޱ� ���� ���� ����
	Complex Z2 = { 0 , 0 }; // �ι�° ���Ҽ��� �ޱ� ���� ���� ����
	Complex Z = { 0 , 0 }; // �� ���Ҽ��� ���ϰ� ���� ���� �ޱ� ���� ���� ����

	printf("ù��° ���Ҽ� �Է� :"); // ù��° ���Ҽ��� �Է��� �ޱ� ���� ���� ���
	scanf("%lf %lf", &Z1.real, &Z1.image); // �Է¹��� ���� Z1�� real�� Z1�� image�� ����
	printf("�ι�° ���Ҽ� �Է� :"); // �ι�° ���Ҽ��� �Է��� �ޱ� ���� ���� ���
	scanf("%lf %lf", &Z2.real, &Z2.image); // �Է¹��� ���� Z2�� real�� Z2�� image�� ����

	Z.real = Z1.real + Z2.real; // Z1�� Z2�� �Ǽ��θ� ���� ���� Z�� �Ǽ��ο� �����Ѵ�.
	Z.image = Z1.image + Z2.image; // Z1�� Z2�� ����θ� ���� ���� Z�� ����ο� �����Ѵ�.

	if (Z.image < 0) // ������� ����� ���� ǥ�ø� ���� ���ǹ� ���
		printf("�� ���Ҽ��� ���� %.2lf - j %.2lf\n", Z.real, -Z.image); // ����ΰ� ������� �� ���� ���
	else
		printf("�� ���Ҽ��� ���� %.2lf + j %.2lf\n", Z.real, Z.image); // ����ΰ� ������ �� ���� ���

	Z.real = Z1.real * Z2.real - Z1.image * Z2.image; // Z1�� Z2�� ������������ ��� �Ǵ� �Ǽ��θ� Z�� �Ǽ��ο� ����
	Z.image = Z1.real * Z2.image + Z1.image * Z2.real; // Z1�� Z2�� ������������ ��� �Ǵ� ����θ� Z�� ����ο� ����

	if (Z.image < 0) // ������� ����� ���� ǥ�ø� ���� ���ǹ� ���
		printf("�� ���Ҽ��� ���� %.2lf - j %.2lf", Z.real, -Z.image); // ����ΰ� ������� �� ���� ���
	else
		printf("�� ���Ҽ��� ���� %.2lf + j %.2lf", Z.real, Z.image); // ����ΰ� ������ �� ���� ���
	return 0;
}

////2 ���Ҽ� ����, ����, ����, ������, �ӷ� ���
//typedef struct _complex // typedef�� ����ؼ� ����ü ����
//{
//	double real; // ���Ҽ��� �Ǽ���
//	double image; // ���Ҽ��� �����
//} Complex; // struct _complex == Complex
//// ���ο� �ڷ��� 'Complex'
//Complex AddComplex(Complex Z1, Complex Z2) // ����
//{
//	Complex Z = { 0 , 0 }; // �� ���Ҽ��� ���� ���� �ޱ� ���� ���� ����
//	Z.real = Z1.real + Z2.real; // Z1�� Z2�� �Ǽ��θ� ���� ���� Z�� �Ǽ��ο� �����Ѵ�.
//	Z.image = Z1.image + Z2.image; // Z1�� Z2�� ����θ� ���� ���� Z�� ����ο� �����Ѵ�.
//	return Z; // Z ��ȯ
//}
//Complex SubComplex(Complex Z1, Complex Z2) // ����
//{
//	Complex Z = { 0 , 0 }; // �� ���Ҽ��� �� ���� �ޱ� ���� ���� ����
//	Z.real = Z1.real - Z2.real; // Z1�� Z2�� �Ǽ��θ� �� ���� Z�� �Ǽ��ο� �����Ѵ�.
//	Z.image = Z1.image - Z2.image; // Z1�� Z2�� ����θ� �� ���� Z�� ����ο� �����Ѵ�.
//	return Z; // Z ��ȯ
//}
//Complex ConjugateComplex(Complex Z3) // �ӷ����Ҽ�
//{
//	Z3.image = -Z3.image; // ������� ��ȣ�� �ٲ۴�.
//	return Z3; // Z ��ȯ
//}
//Complex MulComplex(Complex Z1, Complex Z2) // ����
//{
//	Complex Z = { 0 , 0 }; // �� ���Ҽ��� ���� ���� �ޱ� ���� ���� ����
//	Z.real = Z1.real * Z2.real - Z1.image * Z2.image; // Z1�� Z2�� ������������ ��� �Ǵ� �Ǽ��θ� Z�� �Ǽ��ο� ����
//	Z.image = Z1.real * Z2.image + Z1.image * Z2.real; // Z1�� Z2�� ������������ ��� �Ǵ� ����θ� Z�� ����ο� ����
//	return Z; // Z ��ȯ
//}
//Complex DivComplex(Complex Z1, Complex Z2) // ������
//{
//	Complex Z = { 0 , 0 }; // �� ���Ҽ��� ���� ���� �ޱ� ���� ���� ���� 
//	Complex conjugateZ2 = ConjugateComplex(Z2); // ����ȭ�� ���� �и��� �ӷ����Ҽ��� ����
//	double den = (Z2.real * Z2.real) + (Z2.image * Z2.image); // �и��� ���Ҽ��� �ӷ����Ҽ��� ���� ���� ����
//	Complex MulZ1conZ2 = MulComplex(Z1, conjugateZ2); // ������ ���Ҽ��� �и��� �ӷ����Ҽ��� ���� ���� ����
//	Z.real = MulZ1conZ2.real / den; // ������ �Ǽ��θ� �и�� ���� ���� Z�� �Ǽ��ο� ����
//	Z.image = MulZ1conZ2.image / den; // ������ ����θ� �и�� ���� ���� Z�� ����ο� ����
//	return Z; // Z ��ȯ
//}
//void ComplexPrn(Complex Z3)
//{
//	if (Z3.image < 0) // ������� ����� ���� ǥ�ø� ���� ���ǹ� ���
//		printf("% .2lf - j %.2lf\n", Z3.real, -Z3.image); // ����ΰ� ������� �� ���� ���
//	else
//		printf("% .2lf + j %.2lf\n", Z3.real, Z3.image); // ����ΰ� ������ �� ���� ���
//}
//int main()
//{
//	Complex Z1 = { 0 , 0 }; // ù��° ���Ҽ��� �ޱ� ���� ���� ����
//	Complex Z2 = { 0 , 0 }; // �ι�° ���Ҽ��� �ޱ� ���� ���� ����
//	Complex Z3 = { 0 , 0 }; // �� ���Ҽ��� ��� ���� �ޱ� ���� ���� ����
//
//	printf("���Ҽ� �Է� :"); // ù��° ���Ҽ��� �Է��� �ޱ� ���� ���� ���
//	scanf("%lf %lf", &Z1.real, &Z1.image); // �Է¹��� ���� Z1�� real�� Z1�� image�� ����
//	printf("���Ҽ� �Է� :"); // �ι�° ���Ҽ��� �Է��� �ޱ� ���� ���� ���
//	scanf("%lf %lf", &Z2.real, &Z2.image); // �Է¹��� ���� Z2�� real�� Z2�� image�� ����
//
//	Z3 = AddComplex(Z1, Z2); // �� ���Ҽ��� ���� ���� ����
//	printf("���Ҽ��� ����            "); // ���� ����� ������� �˸��� ���� ���
//	ComplexPrn(Z3); // ���Ҽ� ���
//	Z3 = SubComplex(Z1, Z2); // �� ���Ҽ��� ���� ���� ����
//	printf("���Ҽ��� ����            "); // ���� ����� ������� �˸��� ���� ���
//	ComplexPrn(Z3); // ���Ҽ� ���
//	Z3 = ConjugateComplex(Z1); // Z1���Ҽ��� �ӷ����Ҽ� ��� ���� ����
//	printf("���Ҽ��� �ӷ���          "); // �ӷ����Ҽ��� ������� �˸��� ���� ���
//	ComplexPrn(Z3); // ���Ҽ� ���
//	Z3 = MulComplex(Z1, Z2); // �� ���Ҽ��� ���� ���� ����
//	printf("���Ҽ��� ����            "); // ���� ����� ������� �˸��� ���� ���
//	ComplexPrn(Z3); // ���Ҽ� ���
//	Z3 = DivComplex(Z1, Z2); // �� ���Ҽ��� ������ ���� ����
//	printf("���Ҽ��� �������        "); // �������� ����� ������� �˸��� ���� ���
//	ComplexPrn(Z3); // ���Ҽ� ���
//	return 0;
//}

////3 �л��� ������ ����ϴ� ���α׷�
//typedef struct _score // typedef�� ����ؼ� ����ü ����
//{
//	char name[3]; // �л����� �̸�
//	int korean; // �����
//	int english; // �����
//	int math; // ���м���
//	int total; // ����
//	double average; // ���
//} SCORE; // struct _score == SCORE
//// ���ο� �ڷ��� 'SCORE'
//int main()
//{
//	SCORE A[3] = { {"KBH",100,95,90,0,0},{"SCH",96,87,90,0,0},{"LSH",78,67,87,0,0} }; // ����ü �迭 // �� �л��� �̸��� �����,�����,���м����� �Է��ص�
//	for (int i = 0; i < 3; i++) // ����, ��� ���, ���
//	{
//		A[i].total = A[i].korean + A[i].english + A[i].math; // �� �迭�� ����� ����� ���� ������ ���� ���� ���� ����
//		A[i].average = ((double)A[i].total / 3.00); // �� �迭�� ������ 3���� ���� ��� ���� ����
//		printf("�̸� : %.3s ���� : %3d ���� : %d ���� : %d ���� : %d ��� : %.2lf\n", A[i].name, A[i].korean, A[i].english, A[i].math, A[i].total, A[i].average);
//		// �� �迭�� ��� �������� ������� �����Ͽ� ���
//	}
//	return 0;
//}