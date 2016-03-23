package jump_game_ii;

public class JumpGameII {

    public class Solution {
        public int jump(int[] A) {
            int step = 0;
            int next = 0;
            int current = 0;
            for (int i = 0; i < A.length; i++) {
                if (i > current) {
                    current = next;
                    step++;
                }
                next = Math.max(next, i + A[i]);
            }
            return step;
        }
    }

    public static class UnitTest {

    }
}
