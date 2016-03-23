package remove_duplicates_from_sorted_array;

public class RemoveDuplicatesfromSortedArray {

    public class Solution {
        public int removeDuplicates(int[] A) {
            assert A != null;
            if (A.length == 0) {
                return 0;
            }
            int len = 1;
            for (int i = 1; i < A.length; i++) {
                if (A[len - 1] != A[i]) {
                    A[len++] = A[i];
                }
            }
            return len;
        }
    }

    public static class UnitTest {

    }
}
