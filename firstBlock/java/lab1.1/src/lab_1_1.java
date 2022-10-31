import java.util.Scanner;
public class lab_1_1 {
    public static void main(String[] args) {
        final int MIN = 1, MAX = 7;
        int number = 0;
        boolean isIncorrect;
        Scanner input = new Scanner(System.in);
        System.out.println("Введите  номер  дня недели(число от 1 до 7)");
        do {
            isIncorrect = false;
            try {
                number = Integer.parseInt(input.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Проверьте корректность введенных данных!");
                isIncorrect = true;
            }
            if (!isIncorrect && (number < MIN || number > MAX)) {
                isIncorrect = true;
                System.out.println("Проверьте корректность введенных данных!");
            }
        } while (isIncorrect);
        input.close();
        switch (number) {
            case 1 -> System.out.println("Понедельник");
            case 2 -> System.out.println("Вторник");
            case 3 -> System.out.println("Среда");
            case 4 -> System.out.println("Четверг");
            case 5 -> System.out.println("Пятница");
            case 6 -> System.out.println("Суббота");
            case 7 -> System.out.println("Воскресенье");
        }
    }
}