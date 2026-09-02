
import java.util.*;

class minimum_range {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int q = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        while (q-- > 0) {
            int q1 = sc.nextInt() - 1; // convert to 0-based index
            int q2 = sc.nextInt() - 1;

            int small = Integer.MAX_VALUE;

            for (int j = q1; j <= q2; j++) {
                small = Math.min(small, arr[j]);
            }

            System.out.println(small);
        }

        sc.close();
    }
}
