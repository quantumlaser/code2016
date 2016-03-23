package sqrt_x;

public class SqrtX {

    public class Solution {
        public int sqrt(int a) {
            double x = 1.0;
            while (Math.abs(x * x - a) > 10E-6) {
                x = (x + a / x) / 2;
            }
            return (int) x;
        }
    }

    public static class UnitTest {

    }
}
