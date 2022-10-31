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
		cout << "Введите день недели" << endl;
		cin >> number;
		if (cin.fail()) {
			isIncorrect = true;
			cout << "Ошибка. Введите корректное число" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		if (!isIncorrect && (number < MIN || number > MAX)) {
			isIncorrect = true;
			cout << "Ошибка. Введите число в диапазоне от 1 до 7" << endl;
		}
	} while (isIncorrect);
	switch (number) {
	case 1:
		cout << "Понедельник";
		break;
	case 2:
		cout << "Вторник";
		break;
	case 3:
		cout << "Среда";
		break;
	case 4:
		cout << "Четверг";
		break;
	case 5:
		cout << "Пятница";
		break;
	case 6:
		cout << "Суббота";
		break;
	case 7:
		cout << "Воскресенье";
		break;
	}
	return 0;
}
