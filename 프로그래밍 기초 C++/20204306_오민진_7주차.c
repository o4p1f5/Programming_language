#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)


////1
//double KineticEnergy(double kg, double ms) // ���� kg,ms�� �̿��� ��������� ���ϴ� �Լ�
//{
//	double E = 1.0 / 2.0 * kg * ms * ms; // ���� kg�� ms�� �׿��� ���� ��갪�� ����
//	return E; // �Լ��� ȣ���� �� ���� E�� ����� ���� ���
//}
// 
//int main() // �����Լ��� ������ �˸�
//{
//	double kg = 0, ms = 0; // �Ǽ��� ���� kg,ms ����
//	printf("����(kg)�� �ӷ� (m/s) �Է� :"); // printf�Լ��� �׿��� ���� �ܼ�â�� ���
//	scanf("%lf %lf", &kg, &ms); // scanf�� �̿��� �Է¹��� ���� ���ʴ�� ���� kg,ms�� ����
//
//	printf("���� %.2lfkg�̰� �ӷ� %.2lf m/s�� ��ü�� ������� : %.2lf [J]", kg, ms, KineticEnergy(kg, ms)); // ���� kg,ms�� �Լ�  KineticEnergy�� ���� kg,ms�� ������ ���� ���� %.2lf�� ���ʴ�� ���� �� printf�Լ��� �̿��� �ܼ�â�� ���
//
//	return 0; // �����Լ��� ���Ḧ �˸�
//}

////2
//double Density(double g, double cm3) // ���� g,cm3�� �̿��� �е��� ���ϴ� �Լ� 
//{
//	double D = g / cm3; // ���� g,cm3�� �̿��� ���� ��갪�� ����
//	return D; // �Լ��� ȣ���� �� ���� D�� ����� ���� ���
//}
//
//int main() // �����Լ��� ������ �˸�
//{
//	double g = 0, cm3 = 0; // �Ǽ��� ���� g,cm3�� ����
//	printf("����(g)�� ����(cm^3) �Է� :"); // printf�Լ��� �׿��� ���� �ܼ�â�� ���
//	scanf("%lf %lf", &g, &cm3); // scanf�Լ��� �̿��� �Է¹��� ���� ���ʴ�� ���� g,cm3�� ����
//
//	printf("���� %.2lfg�̰� ���� %.2lf cm^3�� �е� %.2lf [g/cm^3]", g, cm3, Density(g, cm3)); // ���� g,cm3�� ���� �Լ� Density�� ���� g,cm3�� ������ ����� ���� %.2lf�� ���ʷ� ���� �� printf�Լ��� �̿��� �ܼ�â�� ���.
//	return 0; // �����Լ��� ���Ḧ �˸�
//}

////3
//double HMStoSec(double h, double m, double s) // ���� h,m,s�� �̿��� �������� ����ð��� �� �������� ���ϴ� �Լ�
//{
//	double H = h * 3600.0; // ���� h�� �̿��� ��� ���� ����
//	double M = m * 60.0; // ���� m�� �̿��� ���� ��� ���� ����
//	double P = H + M + s; // ���� H,M,s�� �̿��� ���� ��� ���� ����
//	return P; // �Լ��� ȣ���Ҷ� ���� P�� �ִ� ���� ���
//}
//
//int main() // ���� �Լ��� ������ �˸�
//{
//	double h = 0, m = 0, s = 0; // �Ǽ��� ���� h,m,s����
//	printf("����ð� �� �� �� �Է� :"); // printf�Լ��� �̿��� ���� �ܼ�â�� ���.
//	scanf("%lf %lf %lf", &h, &m, &s); // scanf�� �̿��� �Էµ� ���� ���� h,m,s�� ���ʴ�� �����Ѵ�.
//
//	printf("����ð��� �� %.0lf��", HMStoSec(h, m, s)); // �Լ� HMStoSec�� ���� h,m,s�� ������ ���� ���� %.0lf�� ������ �� printf�Լ��� �̿��� �ܼ�â�� ����.
//
//	return 0; // �����Լ��� ���Ḧ �˸�
//}

//4
double ElectricCharge(double w, double kWh) // ���� w,kWh�� �̿��� �������� ����ϴ� �Լ�
{
	double EW = w + (kWh * 190.0); // ���� w,kWh�� �̿��� ���� ��� ���� ���� EW�� ����
	return EW; // �Լ��� ȣ���Ҷ� ���� EW�� ���� ���
}

int main() // �����Լ��� ������ �˸�
{
	double w, kWh = 0; // �Ǽ��� ���� w,kWh�� ����
	printf("�⺻��� :"); // printf�Լ��� �̿��� ���� �ܼ�â�� ���.
	scanf("%lf", &w); // scanf�Լ��� �̿��� �Է¹��� ���� ���� w�� ����
	printf("�� ��뷮(kwh) :"); // printf�Լ��� �̿��� ���� �ܼ�â�� ���.
	scanf("%lf", &kWh); // scanf�Լ��� �̿��� �Է¹��� ���� ���� kWh�� ����

	printf("������ %.0lf ��", ElectricCharge(w, kWh)); // ElectricCharge�Լ��� ���� w,kWh�� ���������� ������ ���� .0lf�� �������� printf�Լ��� �̿��� �ܼ�â�� ���� ����.

	return 0; // �����Լ��� ���Ḧ �˸�
}