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
	cout << "Определить суммарный объем (л) 12 вложенных друг в друга шаров  со  стенками 5 мм.\n";
	cout << "Внутренний диаметр внутреннего шара равен 10 см. Считать, что шары вкладываются друг\n";
	cout << "в друга без зазоров.\n";
	for (int i = 0; i < n; i++) {
		r += 0.5;
	}
	v = 4.0 / 3 * PI * r * r * r / 1000;
	cout << "Суммарный объем = " << v << "(л)";
	return 0;
}