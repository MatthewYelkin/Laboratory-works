#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int MIN = 2;
    int m;
    int n;
    int mult;
    int k;
    bool isIncorrect;
    cout << "Даны два натуральных числа m и n (1<m<n). Найти наименьшее k, при котором m^k>n" << endl;
    do {
        do {
            isIncorrect = false;
            cout << "Введите m = ";
            cin >> m;
            if (cin.fail()) {
                isIncorrect = true;
                cout << "Ошибка. Введите корректное число" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        } while (isIncorrect);

        do {
            isIncorrect = false;
            cout << "Введите n = ";
            cin >> n;
            if (cin.fail()) {
                isIncorrect = true;
                cout << "Ошибка. Введите корректное число" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        } while (isIncorrect);
        if (m > n - 1 || m < MIN) {
            isIncorrect = true;
            cout << "Ошибка. Должно выполняться условие 1<m<n" << endl;
        }
    }
    while (isIncorrect);
	k = 0;
    mult = 1;
    while (mult < n + 1) {
        mult *= m;
        k += 1;
    }
	cout << "Наименьшее k, при котором m^k>n: \n" << k;
	return 0;
}