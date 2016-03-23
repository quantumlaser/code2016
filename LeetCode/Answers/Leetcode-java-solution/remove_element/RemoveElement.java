package remove_element;

public class RemoveElement {

    public class Solution {
        public int removeElement(int[] A, int elem) {
            assert A != null;
            int len = 0;
            for (int i = 0; i < A.length; i++) {
                if (A[i] != elem) {
                    A[len++] = A[i];
                }
            }
            return len;
        }
    }

    public static class UnitTest {

    }
}
