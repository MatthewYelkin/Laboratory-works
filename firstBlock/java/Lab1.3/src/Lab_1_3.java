import java.util.Scanner;

public class Lab_1_3 {
    public static void main(String[] args) {
        final int MIN = 2;
        int m;
        int n;
        int mult;
        int k;
        boolean isIncorrect;
        m = 0;
        n = 0;
        k = 0;
        mult = 1;
        Scanner input = new Scanner(System.in);
        System.out.println("Даны два натуральных числа m и n (1<m<n). Найти наименьшее k, при котором m^k>n");
        do {
            do {
            isIncorrect = false;
            System.out.print("Введите m = ");
            try {
                m = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Ошибка. Введите корректное число");
                isIncorrect = true;
                }
            } while (isIncorrect);
            do {
                isIncorrect = false;
                System.out.print("Введите n = ");
            try {
                n = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Ошибка. Введите корректное число");
                isIncorrect = true;
            }
            } while (isIncorrect);
            if (m < MIN || m > n - 1) {
                isIncorrect = true;
                System.out.println("Ошибка. Должно выполняться условие 1<m<n");
            }
        }while (isIncorrect);
        input.close();
        while (mult < n + 1){
            mult *= m;
            k += 1;
        }
        System.out.println("Наименьшее k, при котором m^k>n: " + k);
    }
}
