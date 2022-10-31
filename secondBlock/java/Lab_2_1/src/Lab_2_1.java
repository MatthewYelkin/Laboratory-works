import java.util.Scanner;

public class Lab_2_1 {
    public static void main(String[] args) {
        int n = 0;
        int p;
        int k = 0;
        int lastNum;
        final int MIN_N = 3;
        final int MAX_N = 15;
        final int MIN_C = -100;
        final int MAX_C = 100;
        boolean isIncorrect, isVipukl;
        Scanner input = new Scanner(System.in);
        System.out.println("Многоугольник задан координатами своих вершин. Определить, является ли данный многоугольник выпуклым.");
        do {
            System.out.print("Введите количество вершин многоугольника: ");
            isIncorrect = false;
            try {
                n = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Проверьте корректность введенных данных!");
                isIncorrect = true;
            }
            if (!isIncorrect && (n < MIN_N || n > MAX_N)) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите число от 3 до 15");
            }
        } while (isIncorrect);
        int[][] coordinates = new int[n][2];
        System.out.println("Введите координаты вершин в порядке обхода по часовой стрелке:");
        for (int i = 0; i < coordinates.length; i++) {
            do {
                System.out.print("Введите x" + (i + 1) + ": ");
                isIncorrect = false;
                try {
                    coordinates[i][0] = Integer.parseInt(input.nextLine());
                } catch (NumberFormatException e) {
                    System.out.println("Проверьте корректность введенных данных!");
                    isIncorrect = true;
                }
                if (!isIncorrect && (coordinates[i][0] < MIN_C || coordinates[i][0] > MAX_C)) {
                    isIncorrect = true;
                    System.out.println("Ошибка! Введите число от -100 до 100");
                }
            } while (isIncorrect);
            do {
                System.out.print("Введите y" + (i + 1) + ": ");
                isIncorrect = false;
                try {
                    coordinates[i][1] = Integer.parseInt(input.nextLine());
                } catch (NumberFormatException e) {
                    System.out.println("Проверьте корректность введенных данных!");
                    isIncorrect = true;
                }
                if (!isIncorrect && (coordinates[i][1] < MIN_C || coordinates[i][1] > MAX_C)) {
                    isIncorrect = true;
                    System.out.println("Ошибка! Введите число от -100 до 100");
                }
            } while (isIncorrect);
        }
        lastNum = n - 1;
        int[][] vector = new int[n][2]; //Объявление массива координат векторов
        for (int i = 0; i < n; i++) {
            vector[i] = new int[2];
            if (i == lastNum) { //Вычисление координат последнего вектора
                vector[n - 1][0] = coordinates[0][0] - coordinates[n - 1][0];
                vector[n - 1][1] = coordinates[0][1] - coordinates[n - 1][1];
            }
            else { //Вычисление координат векторов
                vector[i][0] = coordinates[i + 1][0] - coordinates[i][0];
                vector[i][1] = coordinates[i + 1][1] - coordinates[i][1];
            }
        }
        isVipukl = true;
        while (isVipukl && k < lastNum) { //Произведение векторов
            p = vector[k][0] * vector[k + 1][1] - vector[k][1] * vector[k + 1][0];
            if (p > 0) {
                isVipukl = false;
            }
            else {
                k++;
            }
        }
        if (isVipukl) {
            System.out.println("Многоугольник выпуклый");
        }
        else {
            System.out.println("Многоугольник невыпуклый");
        }
        input.close();
    }
}
