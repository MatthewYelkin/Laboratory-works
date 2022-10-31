#include <iostream>

using namespace std;

void main() {
    setlocale(LC_ALL, "Russian");
    int n;
    int sum;
    const int MIN = 1;
    const int MAX = 100;
    bool isIncorrect = false;
    n = 0;
    sum = 0;
    cout << "Вычислить A1+2A2+3A3+...+NAN. Диапазон ввода - от 1 до 100." << endl;
    do {
        isIncorrect = false;
        cout << "Введите N: ";
        cin >> n;
        if (cin.fail()) {
            isIncorrect = true;
            cout << "Ошибка. Введите корректное число" << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
        if (!isIncorrect && (n < MIN || n > MAX)) {
            isIncorrect = true;
            cout << "Ошибка. Введите число в диапазоне от 1 до 100" << endl;
        }
    } while (isIncorrect);
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        do {
            isIncorrect = false;
            cout << "Введите A" << i + 1 << ": ";
            cin >> arr[i];
            if (cin.fail()) {
                isIncorrect = true;
                cout << "Ошибка. Введите корректное число" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            if (!isIncorrect && (arr[i] < MIN || arr[i] > MAX)) {
                isIncorrect = true;
                cout << "Ошибка. Введите число в диапазоне от 1 до 100" << endl;
            }
        } while (isIncorrect);
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i] * (i + 1);
    }
    cout << "Сумма: " << sum;
    
}