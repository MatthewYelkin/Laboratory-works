#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const double PI = 3.1415;
	double v;
	double d;
	double r;
	int n;
	d = 10.0;
	r = d / 2;
	n = 12;
	cout << "���������� ��������� ����� (�) 12 ��������� ���� � ����� �����  ��  �������� 5 ��.\n";
	cout << "���������� ������� ����������� ���� ����� 10 ��. �������, ��� ���� ������������ ����\n";
	cout << "� ����� ��� �������.\n";
	for (int i = 0; i < n; i++) {
		r += 0.5;
	}
	v = 4.0 / 3 * PI * r * r * r / 1000;
	cout << "��������� ����� = " << v << "(�)";
	return 0;
}