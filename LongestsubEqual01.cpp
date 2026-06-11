public class Main {

    public static int longestEqual01(String s) {
        int n = s.length();

        int[] firstIndex = new int[2 * n + 1];

        for (int i = 0; i < firstIndex.length; i++) {
            firstIndex[i] = -2;
        }

        int sum = 0;
        int maxLen = 0;

        firstIndex[n] = -1;

        for (int i = 0; i < n; i++) {

            if (s.charAt(i) == '0')
                sum--;
            else
                sum++;

            int idx = sum + n;

            if (firstIndex[idx] != -2) {
                maxLen = Math.max(maxLen, i - firstIndex[idx]);
            } else {
                firstIndex[idx] = i;
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String s = "1011001";

        System.out.println(longestEqual01(s));
    }
}
