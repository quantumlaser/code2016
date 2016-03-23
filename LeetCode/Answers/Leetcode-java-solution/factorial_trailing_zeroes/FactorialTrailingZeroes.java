package factorial_trailing_zeroes;

public class FactorialTrailingZeroes {

    public class Solution {
        public int trailingZeroes(int n) {
            int times = 5;
            int zeroes = 0;
            while (n >= times) {
                zeroes += n / times;
                times *= 5;
            }
            return zeroes;
        }
    }

    public static class UnitTest {

    }
}

