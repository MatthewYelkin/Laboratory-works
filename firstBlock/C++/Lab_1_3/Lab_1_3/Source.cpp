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
    cout << "���� ��� ����������� ����� m � n (1<m<n). ����� ���������� k, ��� ������� m^k>n" << endl;
    do {
        do {
            isIncorrect = false;
            cout << "������� m = ";
            cin >> m;
            if (cin.fail()) {
                isIncorrect = true;
                cout << "������. ������� ���������� �����" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        } while (isIncorrect);

        do {
            isIncorrect = false;
            cout << "������� n = ";
            cin >> n;
            if (cin.fail()) {
                isIncorrect = true;
                cout << "������. ������� ���������� �����" << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
        } while (isIncorrect);
        if (m > n - 1 || m < MIN) {
            isIncorrect = true;
            cout << "������. ������ ����������� ������� 1<m<n" << endl;
        }
    }
    while (isIncorrect);
	k = 0;
    mult = 1;
    while (mult < n + 1) {
        mult *= m;
        k += 1;
    }
	cout << "���������� k, ��� ������� m^k>n: \n" << k;
	return 0;
}