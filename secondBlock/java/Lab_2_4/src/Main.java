import java.util.Scanner;
import java.io.*;

public class Main {
    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int choiceForInput;
        int choiceForOutput;
        int n;
        int[][] newMatrix;
        int[][] matrix;
        String inpPath;
        outputOfTaskInfo();
        System.out.println("Вы хотите создать матрицу вручную (1) или считать её из файла (2) ? ");
        choiceForInput = getChoice();
        if (choiceForInput == 1) {
            n = getOrderFromConsole();
            matrix = getMatrixFromConsole(n);
        }
        else {
            inpPath = getPathOfInputFile();
            n = getOrderFromFile(inpPath);
            matrix = getMatrixFromFile(n, inpPath);
        }
        newMatrix = getResult(matrix, n);
        printMatrixInConsole(matrix, n);
        System.out.println("Вы хотите вывести информацию в консоли (1) или в файл (2) ?");
        scan.nextLine();
        choiceForOutput = getChoice();
        outputOfInfo(choiceForOutput, n, newMatrix, matrix);
        scan.close();
    }

    static void outputOfTaskInfo() {
        System.out.println("Дана действительная квадратная матрица порядка 2n. Цифрами обозначены подматрицы порядка n: 1 2");
        System.out.println("                                                                                            3 4");
        System.out.println("Получить новую матрицу: 4 3");
        System.out.println("                        1 2");
        System.out.println("Число 2n должно быть четное и не меньше 2!\n");
    }

    static void outputOfInfo(int choice, int n, int[][] newMatrix, int[][] matrix) {
        if (choice == 1) {
            System.out.println("Новая матрица: ");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(newMatrix[i][j] + "  ");
                }
                System.out.println();
            }
            System.out.println();
        }
        if (choice == 2) {
            printInfoInFile(matrix, n, newMatrix);
        }
    }

    static int getChoice() {
        int choice = 0;
        boolean isIncorrect;
        do {
            isIncorrect = false;
            try {
                choice = Integer.parseInt(scan.nextLine());
            } catch (Exception e) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите 1 или 2.");
            }
            if ((!isIncorrect) && (choice != 1) && (choice != 2) ) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите 1 или 2.");
            }
        } while (isIncorrect);
        return choice;
    }

    static String getPathOfInputFile() {
        String path;
        boolean isIncorrect;
        System.out.println("Введите имя файла для чтения матрицы: ");
        do {
            isIncorrect = false;
            path = scan.nextLine();
            File file = new File(path);
            if (!file.exists()) {
                System.out.println("Файл с таким именем не найден. Повторите попытку ввода. ");
                isIncorrect = true;
            }
        } while (isIncorrect);
        return path;
    }

    static int getOrderFromFile(String path) {
        int n;
        try {
            File file = new File(path);
            Scanner in = new Scanner(file);
            n = Integer.parseInt(in.nextLine());
            in.close();
        } catch (Exception e) {
            System.out.println("Указано неверное значение порядка матрицы. Включен ввод через консоль.");
            n = getOrderFromConsole();
        }
        if (n < 2 || n % 2 != 0) {
            System.out.println("Указано неверное значение порядка матрицы. Включен ввод через консоль.");
            n = getOrderFromConsole();
        }
        return n;
    }

    static int getOrderFromConsole() {
        int n = 0;
        boolean isIncorrect;
        System.out.println("Введите порядок матрицы: ");
        do {
            isIncorrect = false;
            try {
                n = Integer.parseInt(scan.nextLine());
            } catch (Exception e) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите корректное значение!");
            }
            if ((!isIncorrect) && (n < 2 || n % 2 != 0)) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите четное натуральное число не меньшее 2");
            }
        } while (isIncorrect);
        return n;
    }

    static int[][] getMatrixFromConsole(int n) {
        final int MIN = -10000;
        final int MAX = 10000;
        int[][] matrix = new int[n][n];
        boolean isIncorrect;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println("Введите значение элемента а" + (i + 1) + (j + 1));
                do {
                    isIncorrect = false;
                    try {
                        matrix[i][j] = Integer.parseInt(scan.next());
                    } catch (Exception e) {
                        isIncorrect = true;
                        System.out.println("Ошибка! Введите число и повторите попытку");
                    }
                    if ((!isIncorrect) && (matrix[i][j] < MIN || matrix[i][j] > MAX)){
                        isIncorrect = true;
                        System.out.println("Введите число от -10000 до 10000");
                    }
                } while (isIncorrect);
            }
        }
        return matrix;
    }

    static int getElemFromConsole() {
        final int MAX = 10000;
        final int MIN = -10000;
        int elem = 0;
        boolean isIncorrect;
        do {
            isIncorrect = false;
            try {
                elem = Integer.parseInt(scan.nextLine());
            } catch (Exception e) {
                System.out.println("Ошибка! Введите число.");
                isIncorrect = true;
            }
            if (!isIncorrect && (elem < MIN || elem > MAX)){
                isIncorrect = true;
                System.out.println("Введите число от -10000 до 10000!");
            }
        } while (isIncorrect);
        return elem;
    }

    static int[][] getMatrixFromFile(int n, String path) throws FileNotFoundException {
        int [][] matrix = new int[n][n];
        File file = new File(path);
        Scanner in = new Scanner(file);
        in.nextLine();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                try {
                    matrix[i][j] = Integer.parseInt(in.next());
                } catch (Exception e) {
                    System.out.println("В файле неверно введён элемент" + (i + 1) + (j + 1) + " Введите его в консоль. ");
                    matrix[i][j] = getElemFromConsole();
                }
            }
        }
        in.close();
        return matrix;
    }

    static void printMatrixInConsole(int[][] matrix, int n) {
        System.out.println("Введённая вами матрица: ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + "   ");
            }
            System.out.println();
        }
    }

    static int[][] getResult(int[][] matrix, int n) {
        int[][] newMatrix = new int[n][n];
        int lastNum = n / 2;
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

    static void printInfoInFile(int[][] matrix, int n, int[][] newMatrix) {
        String outputPath;
        boolean isIncorrect;
        do {
            isIncorrect = false;
            System.out.println("Введите путь файла для вывода. Если файла не существует, он будет создан. ");
            outputPath = scan.nextLine();
            if (!outputPath.contains(".txt")) {
                outputPath = outputPath + ".txt";
            }
            try (FileWriter writer = new FileWriter(outputPath)) {
                writer.append("Введенная вами матрица:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        writer.append(matrix[i][j] + "  ");
                    }
                    writer.append("\n");
                }
                writer.append("Новая матрица: \n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        writer.append(newMatrix[i][j] + "  ");
                    }
                    writer.append("\n");
                }
                System.out.println("Запись в файл успешно проведена.");
            } catch (IOException e) {
                System.out.println("При записи произошла ошибка.");
                isIncorrect = true;
            }
        } while (isIncorrect);
    }
}