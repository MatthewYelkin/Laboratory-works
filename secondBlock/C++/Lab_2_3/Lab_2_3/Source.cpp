#include <iostream>
#include <fstream>

using namespace std;

float** setLength(int tmpCountRoots) {
    int i;
    int lastNum;
    float** tmpMatrix;
    tmpMatrix = new float* [tmpCountRoots];
    lastNum = tmpCountRoots + 1;
    for (i = 0; i < lastNum; i++) {
        tmpMatrix[i] = new float[tmpCountRoots + 1];
    }
    return tmpMatrix;
}

int takeChoice(string outputText) {
    int choice;
    bool isIncorrect;
    do {
        isIncorrect = false;
        cout << outputText << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "Ошибка. Введите корректные данные!" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Ошибка. Введите корректные данные!" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (choice < 0 || choice > 1)) {
            isIncorrect = true;
            cout << "Ошибка. Введите 0 или 1!" << endl;
        }
    } while (isIncorrect);
    return choice;
}

int readCountRoots() {
    const int MIN_COUNT = 2;
    const int MAX_COUNT = 10;
    bool isIncorrect;
    int tmpCountRoots;
    do {
        isIncorrect = false;
        cout << "Введите количество неизвестных системы уравнений(целое число в диапазоне от 2 до 10): ";
        cin >> tmpCountRoots;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "Ошибка. Введите корректные данные!" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Ошибка. Введите корректные данные!" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (tmpCountRoots < MIN_COUNT || tmpCountRoots > MAX_COUNT)) {
            isIncorrect = true;
            cout << "Ошибка. Диапазон ввода от 2 до 10." << endl;
        }
    } while (isIncorrect);
    return tmpCountRoots;
}

float inputMatrixCell() {
    const int MIN_VALUE = -5000;
    const int MAX_VALUE = 5000;
    bool isIncorrect;
    float tmpValue;
    do {
        isIncorrect = false;
        cin >> tmpValue;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "Ошибка. Введите корректные данные!" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Ошибка. Введите корректные данные!" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (tmpValue < MIN_VALUE || tmpValue > MAX_VALUE)) {
            isIncorrect = true;
            cout << "Ошибка. Диапазон ввода от -5000 до 5000." << endl;
        }
    } while (isIncorrect);
    return tmpValue;
}

void readMatrix(int tmpCountRoots, float** tmpMatrix) {
    int i;
    int j;
    int lastNum = tmpCountRoots + 1;
    for (i = 0; i < tmpCountRoots; i++) {
        for (j = 0; j < lastNum; j++) {
            cout << "Введите элемент " << i + 1 << " строки и " << j + 1 << " столбца. ";
            tmpMatrix[i][j] = inputMatrixCell();
        }
    }
}

void writeRoots(int tmpCountRoots, float* roots) {
    int i;
    cout << "Корни уравнения равны: ";
    for (i = 0; i < tmpCountRoots; i++) {
        cout << roots[i] << " ";
    }
    cout << endl;
}

string inputFilePath() {
    bool isIncorrect;
    string filePath;
    do {
        cout << "Введите путь к файлу и его название." << endl;
        isIncorrect = false;
        cin >> filePath;
        ifstream F(filePath);
        if (!F.is_open()) {
            cout << "Ошибка ввода имени файла." << endl;
            isIncorrect = true;
        }
        F.close();
    } while (isIncorrect);
    return filePath;
}

float** inputFromFile(int* tmpCountRoots) {
    const int MIN_COUNT = 2;
    const int MAX_COUNT = 10;
    const int MIN_VALUE = -5000;
    const int MAX_VALUE = 5000;
    float** tmpMatrix;
    int i;
    int j;
    int lastNum;
    ifstream F;
    F.open(inputFilePath());
    F >> *tmpCountRoots;
    if (F.fail() || (*tmpCountRoots < MIN_COUNT) || (* tmpCountRoots > MAX_COUNT)) {
        cout << "Ошибка ввода. Введите количество неизвестных в диапазоне от 2 до 10."
            << endl;
        *tmpCountRoots = readCountRoots();
    }
    lastNum = *tmpCountRoots + 1;
    tmpMatrix = setLength(*tmpCountRoots);
    for (i = 0; i < *tmpCountRoots; i++) {
        for (j = 0; j < lastNum; j++) {
            F >> tmpMatrix[i][j];
            if (F.fail() || (tmpMatrix[i][j] < MIN_VALUE) || (tmpMatrix[i][j] > MAX_VALUE)) {
                cout << "Ошибка чтения коэфициента из файла. Введите коэфициент " << i + 1 << " строки " << j + 1 << " столбца с клавиатуры" << endl;
                tmpMatrix[i][j] = inputMatrixCell();
                F.clear();
                F.ignore(1, ' ');
            }
        }
    }
    F.close();
    return tmpMatrix;
}

void writeMatrixInConsol(int tmpCountRoots, float** tmpMatrix) {
    int i;
    int j;
    cout << "Вы ввели матрицу:" << endl;
    for (i = 0; i < tmpCountRoots; i++) {
        for (j = 0; j < (tmpCountRoots + 1); j++) {
            cout << tmpMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void moveStrings(float** tmpMatrix, int firstRow, int secondRow, int tmpCountRoots) {
    int j;
    float r;
    if ((firstRow < (tmpCountRoots + 1)) && (secondRow < (tmpCountRoots + 1))) {
        for (j = 0; j < (tmpCountRoots + 1); j++) {
            r = tmpMatrix[secondRow][j];
            tmpMatrix[secondRow][j] = tmpMatrix[firstRow][j];
            tmpMatrix[firstRow][j] = r;
        }
    }
}

void newMatrix(int tmpCountRoots, float** tmpMatrix) {
    int i;
    int j;
    int m;
    int tmpI;
    float k;
    int lastNum;
    lastNum = tmpCountRoots + 1;
    for (j = 0; j < tmpCountRoots; j++) {
        if (tmpMatrix[j][j] == 0 && j < (tmpCountRoots - 1)) {
            tmpI = j + 1;
            do {
                if (tmpMatrix[tmpI][j] != 0) {
                    moveStrings(tmpMatrix, j, tmpI, tmpCountRoots);
                }
            } while ((tmpI < tmpCountRoots + 1) && (tmpMatrix[j][j] == 0));
        }
        for (i = j + 1; i < tmpCountRoots; i++) {
            k = tmpMatrix[i][j] / tmpMatrix[j][j];
            for (m = j; m < lastNum; m++) {
                tmpMatrix[i][m] = tmpMatrix[i][m] - k * tmpMatrix[j][m];
            }
        }
    }
}

float* findRoots(int tmpCountRoots, float** tmpMatrix) {
    float* tmpRoots = new float[tmpCountRoots];
    int i;
    int j;
    float sum;
    for (i = (tmpCountRoots - 1); i > -1; i--) {
        sum = 0;
        for (j = (i + 1); j < tmpCountRoots; j++) {
            sum = sum + tmpRoots[j] * tmpMatrix[i][j];
        }
        if (tmpMatrix[i][i] == 0) {
            tmpRoots[i] = 0;
        }
        else {
            tmpRoots[i] = (tmpMatrix[i][tmpCountRoots] - sum) / tmpMatrix[i][i];
        }
    }
    return tmpRoots;
}

float* gaussM(int tmpCountRoots, float** tmpMatrix) {
    writeMatrixInConsol(tmpCountRoots, tmpMatrix);
    newMatrix(tmpCountRoots, tmpMatrix);
    return findRoots(tmpCountRoots, tmpMatrix);
}

void outputInFile(int tmpCountRoots, float* tmpRoots) {
    string saveFile;
    ofstream F;
    if (takeChoice("Вы хотите сохранить результат программы в файл ? (0 - Да / 1 - Нет).") == 0) {
        saveFile = inputFilePath();
        F.open(saveFile, ios_base::app);
        F << "\nКорни уравнения равны: " << endl;
        for (int i = 0; i < tmpCountRoots; i++) {
            F << tmpRoots[i] << " ";
        }
        F.close();
        cout << "Корни сохранены в файл : " << saveFile;
    }
}

float** consolInput(int* tmpCountRoots) {
    float** tmpMatrix;
    int tmp = readCountRoots();
    *tmpCountRoots = tmp;
    tmpMatrix = setLength(*tmpCountRoots);
    readMatrix(*tmpCountRoots, tmpMatrix);
    return tmpMatrix;
}

float** Input(int* tmpCountRoots) {
    float** tmpMatrix;

    if (takeChoice("Нажмите 0, если хотите считывать информацию из консоли, 1, если из файла.") == 0) {
        tmpMatrix = consolInput(tmpCountRoots);
    }
    else {
        tmpMatrix = inputFromFile(tmpCountRoots);
    }
    return tmpMatrix;
}

void printTaskInfo() {
    cout << "Данная программа выполняет 'прямой ход' в решении системы алгебраических уравнений методом Гаусса." << endl;
    cout << "Примечание : этот метод применим только для матриц, определитель которой отличен от нуля." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    float** matrix = new float* [1];
    float* roots;
    int* countRoots = new int;
    printTaskInfo();
    matrix = Input(countRoots);
    roots = gaussM((*countRoots), matrix);
    writeRoots((*countRoots), roots);
    outputInFile((*countRoots), roots);
}