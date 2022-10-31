import java.io.*;
import java.util.Scanner;

public class Main {
    public static Scanner in = new Scanner(System.in);

    public static int readCountRoots() {
        final int MIN_COUNT = 2;
        final int MAX_COUNT = 10;
        int tmpCountRoots = 0;
        boolean isIncorrect;
        do {
            isIncorrect = false;
            System.out.print("Введите количество неизвестных системы уравнений(целое число в диапазоне от 2 до 10): ");
            if (!in.hasNextInt()) {
                isIncorrect = true;
                in.next();
                System.out.println("Ошибка ввода. Введены некорректные данные!");
            } else {
                tmpCountRoots = in.nextInt();
                if (tmpCountRoots < MIN_COUNT || tmpCountRoots > MAX_COUNT) {
                    System.out.println("Ошибка ввода. Введите число в диапазоне от 2 до 10!");
                    isIncorrect = true;
                }
            }
        } while (isIncorrect);
        return tmpCountRoots;
    }

    public static int takeChoice(String OutputText) {
        boolean isIncorrect;
        int choice = 0;
        do {
            isIncorrect = false;
            System.out.println(OutputText);
            if (!in.hasNextInt()) {
                isIncorrect = true;
                in.next();
                System.out.println("Ошибка. Введены некорректные данные!");
            } else {
                choice = in.nextInt();
                if ((choice != 0) && (choice != 1)) {
                    System.out.println("Ошибка. Введите 0 или 1.");
                    isIncorrect = true;
                }
            }
        } while (isIncorrect);
        return choice;
    }

    public static float inputMatrixCell() {
        final int MIN_VALUE = -5000;
        final int MAX_VALUE = 5000;
        boolean isIncorrect;
        float tmpValue = 0;
        do {
            isIncorrect = false;
            if (!in.hasNextInt()) {
                isIncorrect = true;
                in.next();
                System.out.println("Ошибка ввода. Повторите ввод.");
            } else {
                tmpValue = in.nextFloat();
                if (tmpValue < MIN_VALUE || tmpValue > MAX_VALUE){
                    isIncorrect = true;
                    System.out.println("Ошибка ввода. Введите количество неизвестных в диапазоне от -5000 до 5000.");
                }
            }
        } while (isIncorrect);
        return tmpValue;
    }

    public static void readMatrix(int tmpCountRoots, float[][] tmpMatrix) {
        int lastNum = (tmpCountRoots + 1);
        for (int i = 0; i < tmpCountRoots; i++) {
            for (int j = 0; j < lastNum; j++) {
                System.out.print("Введите элемент " + (i + 1) + " строки и " + (j + 1)
                        + " столбца: ");
                tmpMatrix[i][j] = inputMatrixCell();
            }
        }
    }

    public static float[][] cInput() {
        int tmpCountRoots;
        tmpCountRoots = readCountRoots();
        float[][] tmpMatrix = new float[tmpCountRoots][tmpCountRoots + 1];
        readMatrix(tmpCountRoots, tmpMatrix);
        return tmpMatrix;
    }

    public static void writeMatrixInC(float[][] tmpMatrix) {
        int lastNum = tmpMatrix.length + 1;
        System.out.println("Вы ввели матрицу:");
        for (int i = 0; i < tmpMatrix.length; i++) {
            for (int j = 0; j < lastNum; j++) {
                System.out.print(tmpMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void moveStrings(float[][] tmpMatrix, int firstRow, int secondRow) {
        int lastNum = tmpMatrix.length + 1;
        float r;
        if ((firstRow < lastNum) && (secondRow < lastNum)) {
            for (int j = 0; j < lastNum; j++) {
                r = tmpMatrix[secondRow][j];
                tmpMatrix[secondRow][j] = tmpMatrix[firstRow][j];
                tmpMatrix[firstRow][j] = r;
            }
        }
    }

    public static void newMatrix(float[][] tmpMatrix) {
        int tmpI, lastNum1, lastNum2;
        float k;
        lastNum1 = tmpMatrix.length - 1;
        lastNum2 = tmpMatrix.length + 1;
        for (int j = 0; j < tmpMatrix.length; j++) {
            if ((tmpMatrix[j][j] == 0) && (j < lastNum1)) {
                tmpI = j + 1;
                do {
                    if (tmpMatrix[tmpI][j] != 0) {
                        moveStrings(tmpMatrix, j, tmpI);
                    }
                } while ((tmpI < tmpMatrix.length) && (tmpMatrix[j][j] == 0));
            }
            for (int i = (j + 1); i < tmpMatrix.length; i++) {
                k = tmpMatrix[i][j] / tmpMatrix[j][j];
                for (int m = j; m < lastNum2; m++) {
                    tmpMatrix[i][m] = tmpMatrix[i][m] - k * tmpMatrix[j][m];
                }
            }
        }
    }

    public static float[] findRoots(float[][] tmpMatrix) {
        int tmpCountRoots = tmpMatrix.length;
        float[] tmpRoots = new float[tmpCountRoots];
        float sum;
        for (int i = tmpCountRoots - 1; i > -1; i--) {
            sum = 0;
            for (int j = i + 1; j < tmpCountRoots; j++) {
                sum = sum + tmpRoots[j] * tmpMatrix[i][j];
            }
            if (tmpMatrix[i][i] == 0) {
                tmpRoots[i] = 0;
            } else {
                tmpRoots[i] = (tmpMatrix[i][tmpCountRoots] - sum) / tmpMatrix[i][i];
            }
        }
        return tmpRoots;
    }

    public static float[] gaussM(float[][] tmpMatrix) {
        writeMatrixInC(tmpMatrix);
        newMatrix(tmpMatrix);
        return findRoots(tmpMatrix);
    }

    public static void writeRoots(float[] roots) {
        int tmpCountRoots = roots.length;
        System.out.println("Корни уравнения равны ");
        for (int i = 0; i < tmpCountRoots; i++) {
            System.out.print(roots[i] + " ");
        }
        System.out.println();
    }

    public static String inputFilePath() {
        String filePath;
        boolean isIncorrect;
        do {
            System.out.println("Введите путь к файлу и его название.");
            isIncorrect = false;
            filePath = in.next();
            File file = new File(filePath);
            if (!file.exists()) {
                System.out.println("Ошибка ввода имени файла.");
                isIncorrect = true;
            }
        } while (isIncorrect);
        return filePath;
    }

    public static float[][] inputFromFile() throws FileNotFoundException {
        final int MIN_COUNT = 2;
        final int MAX_COUNT = 10;
        final int MIN_VALUE = -5000;
        final int MAX_VALUE = 5000;
        float[][] tmpMatrix;
        FileReader fr = new FileReader(inputFilePath());
        Scanner reader = new Scanner(fr);
        int tmpCountRoots, lastNum;
        if (!reader.hasNextInt()) {
            System.out.println("Ошибка. Введены некорректные данные!");
            tmpCountRoots = readCountRoots();
            reader.next();
        } else {
            tmpCountRoots = reader.nextInt();
            if (tmpCountRoots < MIN_COUNT || tmpCountRoots > MAX_COUNT){
                System.out.println("Ошибка ввода. Введите количество неизвестных в диапазоне от 2 до 10.");
                tmpCountRoots = readCountRoots();
            }
        }
        tmpMatrix = new float[tmpCountRoots][tmpCountRoots + 1];
        lastNum = tmpMatrix.length + 1;
        for (int i = 0; i < tmpMatrix.length; i++) {
            for (int j = 0; j < lastNum; j++) {
                if (!reader.hasNextFloat()) {
                    System.out.println("Ошибка чтения коэфициента из файла. Введите элемент " + (i + 1) + " строки и " + (j + 1) + " столбца c клавиатуры ");
                    tmpMatrix[i][j] = inputMatrixCell();
                    reader.next();
                } else {
                    tmpMatrix[i][j] = reader.nextFloat();
                    if (tmpMatrix[i][j] < MIN_VALUE || tmpMatrix[i][j] > MAX_VALUE){
                        System.out.println("Ошибка ввода. Введите количество неизвестных в диапазоне от -5000 до 5000.");
                        tmpMatrix[i][j] = readCountRoots();
                    }
                }
            }
        }
        reader.close();
        return tmpMatrix;
    }

    public static void outputInFile(float[] tmpRoots) throws IOException {
        String fileName;
        if (takeChoice("Вы хотите сохранить результат программы в файл ? (0 - Да / 1 - Нет).") == 0) {
            fileName = inputFilePath();
            FileWriter writer = new FileWriter(fileName);
            writer.append("Корни уравнения: ");
            for (int i = 0; i < tmpRoots.length; i++) {
                writer.append("X").append(String.valueOf(i + 1)).append("=").append(String.format("%.02f", tmpRoots[i])).append("; ");
            }
            writer.close();
            System.out.println("Корни сохранены в файл : " + fileName);
        }
    }

    public static float[][] input() throws FileNotFoundException {
        float[][] tmpMatrix;
        if (takeChoice("Нажмите 0, если хотите считать информацию из консоли, 1, если из файла.") == 0) {
            tmpMatrix = cInput();
        } else {
            tmpMatrix = inputFromFile();
        }
        return tmpMatrix;
    }

    public static void printTaskInfo(){
        System.out.println("Данная программа выполняет 'прямой ход' в решении системы алгебраических уравнений методом Гаусса.");
        System.out.println("Примечание: этот метод применим только для матриц, определитель которой отличен от нуля.");
    }

    public static void main(String[] args) throws IOException {
        float[][] matrix ;
        float[] roots;
        printTaskInfo();
        matrix = input();
        roots = gaussM(matrix);
        writeRoots(roots);
        outputInFile(roots);
    }
}