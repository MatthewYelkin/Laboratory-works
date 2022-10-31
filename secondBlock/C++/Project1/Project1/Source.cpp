#include <iostream>
#include <fstream>

using namespace std;

string getPathOfOutputFile() {
    string path;
    cout << "\n������� ����� ����� ��� ������. ���� ��� �� ����������, �� ����� ������ �������������. \n";
    cin >> path;
    return path;
}

string getPathOfInputFile() {
    string path;
    bool isIncorrect;
    cout << "������� ����� ����� �� ����� ��� �����. \n";
    do {
        isIncorrect = false;
        cin >> path;
        ifstream inpFile(path);
        if (!inpFile.is_open()) {
            isIncorrect = true;
            cout << "����� � ����� ������ �� ����������. ��������� �������.\n";
        }
    } while (isIncorrect);
    return path;
}

void printInfoInFile(int** matrix, int n, int** newMatrix) {
    string path;
    path = getPathOfOutputFile();
    fstream otpFile;
    otpFile.open(path, ios_base::app);
    otpFile << "�������� ���� �������: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            otpFile << matrix[i][j] << "  ";
        }
        otpFile << "\n";
    }
    otpFile << "����� �������:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            otpFile << newMatrix[i][j] << "  ";
        }
        otpFile << endl;
    }
    cout << endl;
    cout << "������ � ���� ��������� �������.";
}

int** getResult(int** matrix, int n) {
    int** newMatrix = new int* [n];
    int lastNum = n / 2;
    for (int i = 0; i < n; i++) {
        newMatrix[i] = new int[n];
    }
    for (int i = 0; i < lastNum; i++) {
        for (int j = 0; j < lastNum; j++) {
            newMatrix[i][j] = matrix[i + n / 2][j + n / 2];
        }
        for (int j = n / 2; j < n; j++) {
            newMatrix[i][j] = matrix[i + n / 2][j - n / 2];
        }
    }
    for (int i = n / 2; i < n; i++) {
        for (int j = 0; j < lastNum; j++) {
            newMatrix[i][j] = matrix[i - n / 2][j];
        }
        for (int j = n / 2; j < n; j++) {
            newMatrix[i][j] = matrix[i - n / 2][j];
        }
    }
    return newMatrix;
}

void printMatrixInConsole(int** matrix, int n) {
    cout << "�������� ���� �������: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

int** getMatrixFromConsole(int n) {
    const int MAX = 10000;
    const int MIN = -10000;
    bool isIncorrect;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "������� �������� �������� �" << i + 1 << j + 1 << ": ";
            do {
                isIncorrect = false;
                cin >> matrix[i][j];
                if (cin.fail()) {
                    cin.clear();
                    while (cin.get() != '\n');
                    isIncorrect = true;
                    cout << "������� �����!" << endl;
                }
                if (!isIncorrect && cin.get() != '\n') {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "������� ���������� �����" << endl;
                    isIncorrect = true;
                }
                if (!isIncorrect && (matrix[i][j] < MIN || matrix[i][j] > MAX)) {
                    isIncorrect = true;
                    cout << "������� ����� � ��������� �� -10000 �� 10000" << endl;
                }
            } while (isIncorrect);
        }
    }
    return matrix;
}

int getOrderFromConsole() {
    int n;
    bool isIncorrect;
    cout << "������� ������� �������: \n";
    do {
        isIncorrect = false;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "������� �����!" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');

            cout << "������� ���������� �����" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (n < 2 || n % 2 != 0)) {
            isIncorrect = true;
            cout << "������� ������ ����� �� ������ 2!" << endl;
        }
    } while (isIncorrect);
    return n;
}

int** getMatrixFromFile(int n, string path) {
    const int MAX = 10000;
    const int MIN = -10000;
    int** matrix = new int* [n];
    bool isIncorrect;
    ifstream inpFile(path);
    inpFile.ignore();
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inpFile >> matrix[i][j];
            if (inpFile.fail() || matrix[i][j] < MIN || matrix[i][j] > MAX) {
                cout << "� ����� ���������� ��� ������� ������������ �������� �������� a" << i + 1 << j + 1 << ". �������� ����� �� -10000 �� 10000. ������� ��� � �������. \n";
                do {
                    isIncorrect = false;
                    cin >> matrix[i][j];
                    if (cin.fail()) {
                        cin.clear();
                        while (cin.get() != '\n');
                        isIncorrect = true;
                        cout << "������� �����!" << endl;
                    }
                    if (!isIncorrect && cin.get() != '\n') {
                        cin.clear();
                        while (cin.get() != '\n');

                        cout << "������� ���������� �����" << endl;
                        isIncorrect = true;
                    }
                    if (!isIncorrect && (matrix[i][j] < MIN || matrix[i][j] > MAX)) {
                        isIncorrect = true;
                        cout << "������� ����� � ��������� �� -10000 �� 10000" << endl;
                    }
                } while (isIncorrect);
                inpFile.clear();
                inpFile.ignore(1, ' ');
            }
        }
    }
    inpFile.close();
    return matrix;
}

int getOrderFromFile(string path) {
    int n;
    ifstream inpFile;
    inpFile.open(path, ios_base::in);
    inpFile >> n;
    if ((inpFile.fail()) || (n < 2) || (n % 2 != 0)) {
        cout << "� ����� ������� ������������ ������� �������. �� ������ ���� ������ � �� ������ 2. ������� ��� � �������.\n";
        n = getOrderFromConsole();
    }
    return n;
}

int** chooseMatrix(int choice, int& n) {
    string inpPath;
    int** matrix = new int* [n];
    if (choice == 1) {
        n = getOrderFromConsole();
        matrix = getMatrixFromConsole(n);
    }
    else {
        inpPath = getPathOfInputFile();
        n = getOrderFromFile(inpPath);
        matrix = getMatrixFromFile(n, inpPath);
    }
    return matrix;
}

int getChoice() {
    bool isIncorrect;
    int choose;
    do {
        isIncorrect = false;
        cin >> choose;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "������� ���������� �����" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');

            cout << "������� ���������� �����" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (choose < 1 || choose > 2)) {
            isIncorrect = true;
            cout << "������� 1 ��� 2" << endl;
        }
    } while (isIncorrect);
    return choose;
}

void outputOfInfo(int choice, int n, int** newMatrix, int** matrix) {
    if (choice == 1) {
        cout << "����� �������: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << newMatrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    if (choice == 2) {
        printInfoInFile(matrix, n, newMatrix);
    }
}

void outputOfTaskInfo() {
    cout << "���� �������������� ���������� ������� ������� 2n. ������� ���������� ���������� ������� n: 1 2\n";
    cout << "                                                                                            3 4\n";
    cout << "�������� ����� �������: 4 3\n";
    cout << "                        1 2\n";
    cout << "����� 2n ������ ���� ������ � �� ������ 2!\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choiceForInput;
    int choiceForOutput;
    int n = 0;
    int** matrix = new int* [n];
    int** newMatrix = new int*[n];
    outputOfTaskInfo();
    cout << "�� ������ ������� ������� ������� (1) ��� ������� � �� ����� (2) ? \n";
    choiceForInput = getChoice();
    matrix = chooseMatrix(choiceForInput, n);
    newMatrix = getResult(matrix, n);
    printMatrixInConsole(matrix, n);
    cout << "�� ������ ������� ���������� � ������� (1) ��� � ���� (2) ? \n";
    choiceForOutput = getChoice();
    outputOfInfo(choiceForOutput, n, newMatrix, matrix);
}