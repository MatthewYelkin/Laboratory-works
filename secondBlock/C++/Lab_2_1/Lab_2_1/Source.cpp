#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int MIN_N = 3;
	const int MAX_N = 15;
	const int MIN_C = -100;
	const int MAX_C = 100;
	bool isIncorrect;
	bool isVipukl;
	int** coordinates = NULL;
	int** vector = NULL;
	int lastNum;
	int n = 0;
	int k = 0;
    int p;
	cout << "Многоугольник задан координатами своих вершин. Определить, является ли данный многоугольник выпуклым.\n";
	do { //Ввод n
		isIncorrect = false;
		cout << "Введите количество вершин многоугольника: ";
		cin >> n;
		if (cin.fail()) {
			isIncorrect = true;
			cout << "Ошибка. Введите корректное число" << '\n';
			cin.clear();
			while (cin.get() != '\n');
		}
		if (!isIncorrect && (n < MIN_N || n > MAX_N)){
			isIncorrect = true;
			cout << "Ошибка. Введите число от 3 до 15" << '\n';
		}
	} while (isIncorrect);
	coordinates = new int*[n]; //Объявление массива координат вершин
	cout << "Введите координаты вершин в порядке обхода по часовой стрелке:\n";
	for (int i = 0; i < n; i++) {
		coordinates[i] = new int[2];
		do { //Ввод координаты x
			isIncorrect = false;
			cout << "Введите x" << i + 1 << ": ";
			cin >> coordinates[i][0];
			if (cin.fail()) {
				isIncorrect = true;
				cout << "Ошибка. Введите корректное число" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			if (!isIncorrect && (coordinates[i][0] < MIN_C || coordinates[i][0] > MAX_C)) {
				isIncorrect = true;
				cout << "Ошибка. Введите число в диапазоне от -100 до 100" << endl;
			}
		} while (isIncorrect);
		do { //Ввод координаты y
			isIncorrect = false;
			cout << "Введите y" << i + 1 << ": ";
			cin >> coordinates[i][1];
			if (cin.fail()) {
				isIncorrect = true;
				cout << "Ошибка. Введите корректное число" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
			if (!isIncorrect && (coordinates[i][1] < MIN_C || coordinates[i][1] > MAX_C)) {
				isIncorrect = true;
				cout << "Ошибка. Введите число в диапазоне от -100 до 100" << endl;
			}
		} while (isIncorrect);
	}
	lastNum = n - 1;
	vector = new int*[n]; //Объявление массива координат векторов
	for (int i = 0; i < n; i++) {
		vector[i] = new int[2];
		if (i == lastNum) { //Вычисление координат последнего вектора
			vector[n - 1][0] = coordinates[0][0] - coordinates[n - 1][0];
			vector[n - 1][1] = coordinates[0][1] - coordinates[n - 1][1];
		}
		else { //Вычисление координат векторов
			vector[i][0] = coordinates[i + 1][0] - coordinates[i][0];
			vector[i][1] = coordinates[i + 1][1] - coordinates[i][1];
		}
	}
	isVipukl = true;
	while (isVipukl && k < lastNum) { //Произведение векторов
		p = vector[k][0] * vector[k + 1][1] - vector[k][1] * vector[k + 1][0];
		if (p > 0) {
			isVipukl = false;
		} 
		else {
			k++;
		}
	}
	if (isVipukl) {
		cout << "Многоугольник выпуклый";
	}
	else {
		cout << "Многоугольник невыпуклый";
	}
	delete[]coordinates;
	delete[]vector;
	return 0;
}