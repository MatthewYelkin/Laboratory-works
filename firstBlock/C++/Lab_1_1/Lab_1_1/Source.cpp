#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	const int MIN = 1;
	const int MAX = 7;
	int number;
	bool isIncorrect;
	do {
		isIncorrect = false;
		cout << "������� ���� ������" << endl;
		cin >> number;
		if (cin.fail()) {
			isIncorrect = true;
			cout << "������. ������� ���������� �����" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		if (!isIncorrect && (number < MIN || number > MAX)) {
			isIncorrect = true;
			cout << "������. ������� ����� � ��������� �� 1 �� 7" << endl;
		}
	} while (isIncorrect);
	switch (number) {
	case 1:
		cout << "�����������";
		break;
	case 2:
		cout << "�������";
		break;
	case 3:
		cout << "�����";
		break;
	case 4:
		cout << "�������";
		break;
	case 5:
		cout << "�������";
		break;
	case 6:
		cout << "�������";
		break;
	case 7:
		cout << "�����������";
		break;
	}
	return 0;
}
