#include <iostream>

using namespace std;

void findNum(int* arr, int size) {
    const int Factor = 2;
    int h = 2, m = 0, q = 0;
    do {
        h = h * Factor + m;
        if (h < 10) {
            m = 0;
        }
        else {
            h = h - 10;
            m = 1;
        }
        q += 1;
        arr[q] = h; 
    } while (h != 2 || m != 0);
}

    void printArr(int* arr) {
        cout << "Минимальное число:\n";
        for (int i = 18; i > 0; i--) {
            cout << arr[i];
        }
    }

int main(){
    setlocale(LC_ALL, "Russian");
    const int Size = 100;
    int* num = new int[Size];
    findNum(num, Size);
    printArr(num);
	return 0;
}