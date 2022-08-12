import java.util.Scanner;
import java.io.PrintStream;

public class A {
    static Scanner in = new Scanner(System.in);
    static PrintStream out = System.out;

    static final int DAY = 24 * 60;

    static int alarm() {
        int h = in.nextInt();
        int m = in.nextInt();
        return h * 60 + m;
    }

    public static void main(String[] args) {
        int T = in.nextInt();
        while (T-- > 0) {
            int n = in.nextInt();
            int x = alarm();
            int ansMin = Integer.MAX_VALUE;
            while (n-- > 0) {
                int y = alarm();
                ansMin = Math.min(ansMin, (y - x + DAY) % DAY);
            }
            int h = ansMin / 60, m = ansMin % 60;
            out.printf("%d %d%n", h, m);
        }
    }
}

