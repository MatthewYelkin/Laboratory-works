#include <iostream>
#include <fstream>

using namespace std;

string getPathOfOutputFile() {
    string path;
    cout << "\nВведите адрес файла для вывода. Если его не существует, он будет создан автоматически. \n";
    cin >> path;
    return path;
}

string getPathOfInputFile() {
    string path;
    bool isIncorrect;
    cout << "Введите адрес файла на диске для ввода. \n";
    do {
        isIncorrect = false;
        cin >> path;
        ifstream inpFile(path);
        if (!inpFile.is_open()) {
            isIncorrect = true;
            cout << "Файла с таким именем не существует. Повторите попытку.\n";
        }
    } while (isIncorrect);
    return path;
}

void printInfoInFile(int** matrix, int n, int** newMatrix) {
    string path;
    path = getPathOfOutputFile();
    fstream otpFile;
    otpFile.open(path, ios_base::app);
    otpFile << "Заданная вами матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            otpFile << matrix[i][j] << "  ";
        }
        otpFile << "\n";
    }
    otpFile << "Новая матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            otpFile << newMatrix[i][j] << "  ";
        }
        otpFile << endl;
    }
    cout << endl;
    cout << "Запись в файл проведена успешно.";
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
    cout << "Заданная вами матрица: \n";
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
            cout << "Введите значение элемента а" << i + 1 << j + 1 << ": ";
            do {
                isIncorrect = false;
                cin >> matrix[i][j];
                if (cin.fail()) {
                    cin.clear();
                    while (cin.get() != '\n');
                    isIncorrect = true;
                    cout << "Введите число!" << endl;
                }
                if (!isIncorrect && cin.get() != '\n') {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Введите корректное число" << endl;
                    isIncorrect = true;
                }
                if (!isIncorrect && (matrix[i][j] < MIN || matrix[i][j] > MAX)) {
                    isIncorrect = true;
                    cout << "Введите число в диапозоне от -10000 до 10000" << endl;
                }
            } while (isIncorrect);
        }
    }
    return matrix;
}

int getOrderFromConsole() {
    int n;
    bool isIncorrect;
    cout << "Введите порядок матрицы: \n";
    do {
        isIncorrect = false;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n');
            isIncorrect = true;
            cout << "Введите число!" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');

            cout << "Введите корректное число" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (n < 2 || n % 2 != 0)) {
            isIncorrect = true;
            cout << "Введите четное число не меньше 2!" << endl;
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
                cout << "В файле отсутсвует или введено некорректное значение элемента a" << i + 1 << j + 1 << ". Диапозон ввода от -10000 до 10000. Введите его в консоль. \n";
                do {
                    isIncorrect = false;
                    cin >> matrix[i][j];
                    if (cin.fail()) {
                        cin.clear();
                        while (cin.get() != '\n');
                        isIncorrect = true;
                        cout << "Введите число!" << endl;
                    }
                    if (!isIncorrect && cin.get() != '\n') {
                        cin.clear();
                        while (cin.get() != '\n');

                        cout << "Введите корректное число" << endl;
                        isIncorrect = true;
                    }
                    if (!isIncorrect && (matrix[i][j] < MIN || matrix[i][j] > MAX)) {
                        isIncorrect = true;
                        cout << "Введите число в диапозоне от -10000 до 10000" << endl;
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
        cout << "В файле записан некорректный порядок матрицы. Он должен быть четный и не меньше 2. Введите его в консоль.\n";
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
            cout << "Введите корректное число" << endl;
        }
        if (!isIncorrect && cin.get() != '\n') {
            cin.clear();
            while (cin.get() != '\n');

            cout << "Введите корректное число" << endl;
            isIncorrect = true;
        }
        if (!isIncorrect && (choose < 1 || choose > 2)) {
            isIncorrect = true;
            cout << "Введите 1 или 2" << endl;
        }
    } while (isIncorrect);
    return choose;
}

void outputOfInfo(int choice, int n, int** newMatrix, int** matrix) {
    if (choice == 1) {
        cout << "Новая матрица: " << endl;
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
    cout << "Дана действительная квадратная матрица порядка 2n. Цифрами обозначены подматрицы порядка n: 1 2\n";
    cout << "                                                                                            3 4\n";
    cout << "Получить новую матрицу: 4 3\n";
    cout << "                        1 2\n";
    cout << "Число 2n должно быть четное и не меньше 2!\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choiceForInput;
    int choiceForOutput;
    int n = 0;
    int** matrix = new int* [n];
    int** newMatrix = new int*[n];
    outputOfTaskInfo();
    cout << "Вы хотите создать матрицу вручную (1) или считать её из файла (2) ? \n";
    choiceForInput = getChoice();
    matrix = chooseMatrix(choiceForInput, n);
    newMatrix = getResult(matrix, n);
    printMatrixInConsole(matrix, n);
    cout << "Вы хотите вывести информацию в консоли (1) или в файл (2) ? \n";
    choiceForOutput = getChoice();
    outputOfInfo(choiceForOutput, n, newMatrix, matrix);
}