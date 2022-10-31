public class Lab_1_2 {
    public static void main(String[] args) {
        final double PI = 3.1415;
        double v;
        double d;
        double r;
        int n;
        n = 12;
        d = 10;
        r = d / 2;
        System.out.println("Определить суммарный объем (л) 12 вложенных друг в друга шаров  со  стенками 5 мм.");
        System.out.println("Внутренний диаметр внутреннего шара равен 10 см. Считать, что шары вкладываются друг");
        System.out.println("в друга без зазоров.");
        for (int i = 0; i < n; i++){
            r += 0.5;
        }
        v = 4.0 / 3 * PI * r * r * r / 1000;
        System.out.println("Суммарный объем = " + v + "(л)");
    }
}