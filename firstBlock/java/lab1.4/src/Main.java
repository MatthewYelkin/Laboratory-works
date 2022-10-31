import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        int sum;
        n = 0;
        sum = 0;
        final int MIN = 1;
        final int MAX = 100;
        boolean isIncorrect;
        Scanner input = new Scanner(System.in);
        System.out.println("Вычислить A1+2A2+3A3+...+NAN. Диапазон ввода - от 1 до 100.");
        do {
            System.out.print("Введите число N: ");
            isIncorrect = false;
            try {
                n = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Проверьте корректность введенных данных!");
                isIncorrect = true;
            }
            if (!isIncorrect && (n < MIN || n > MAX)) {
                isIncorrect = true;
                System.out.println("Ошибка! Введите число от 1 до 100");
            }
        } while (isIncorrect);
        int arr[] = new int[n];
        for (int i = 0; i < arr.length; i++) {
            do {
                System.out.print("Введите A" + (i + 1) + ": ");
                isIncorrect = false;
                try {
                    arr[i] = Integer.parseInt(input.nextLine());
                } catch (NumberFormatException e) {
                    System.out.println("Проверьте корректность введенных данных!");
                    isIncorrect = true;
                }
                if (!isIncorrect && (arr[i] < MIN || arr[i] > MAX)) {
                    isIncorrect = true;
                    System.out.println("Ошибка! Введите число от 1 до 100");
                }
            } while (isIncorrect);
        }
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i] * (i+1);
        }
        System.out.println("Сумма: " + sum);
        input.close();
    }
}