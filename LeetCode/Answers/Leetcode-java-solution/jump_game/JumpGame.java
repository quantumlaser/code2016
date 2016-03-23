package jump_game;

public class JumpGame {

    public class Solution {
        public boolean canJump(int[] A) {
            assert A != null;
            int far = 0;
            for (int i = 0; i < A.length && i <= far; i++) {
                far = Math.max(far, A[i] + i);
            }
            return far >= A.length - 1;
        }
    }

    public static class UnitTest {

    }
}
