package pascals_triangle_ii;

import java.util.ArrayList;

public class PascalsTriangleII {

    public class Solution {
        public ArrayList<Integer> getRow(int rowIndex) {
            ArrayList<Integer> row = new ArrayList<Integer>();
            for (int r = 0; r <= rowIndex; r++) {
                for (int j = r - 1; j >= 1; j--) {
                    row.set(j, row.get(j - 1) + row.get(j));
                }
                row.add(1);
            }
            return row;
        }
    }

    public static class UnitTest {

    }
}
