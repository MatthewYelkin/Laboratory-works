public class Lab_2_2 {
    public static int[] findNum(){
        final int Factor = 2;
        final int Size = 100;
        int h = 2, m = 0, q = 0;
        int[] num = new int[Size];
        do {
            h = h * Factor + m;
            if (h < 10) {
                m = 0;
            } else {
                h = h - 10;
                m = 1;
            }
        q += 1;
        num[q] = h;
        } while (h != 2 || m != 0);
        return num;
    }
    public static void printArr(int[] arr){
        System.out.println("Минимальное число: ");
        for (int i = 18; i > 0; i--) {
            System.out.print(arr[i]);
        }
    }
    public static void main(String[] args) {
        printArr(findNum());
    }
}