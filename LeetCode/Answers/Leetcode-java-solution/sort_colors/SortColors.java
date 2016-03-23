package sort_colors;

public class SortColors {

    public class Solution {
        public void sortColors(int[] A) {
            int zero = -1;
            int one = -1;
            for (int i = 0; i < A.length; i++) {
                if (A[i] == 0) {
                    A[i] = A[++zero];
                    A[zero] = 0;
                    one = Math.max(zero, one);
                }
                if (A[i] == 1) {
                    A[i] = A[++one];
                    A[one] = 1;
                }
            }
        }
    }

    public static class UnitTest {

    }
}
