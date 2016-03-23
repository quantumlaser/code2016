package length_of_last_word;

public class LengthofLastWord {

    public class Solution {
        public int lengthOfLastWord(String s) {
            int len = 0;
            int i = 0;
            while (true) {
                while (i < s.length() && s.charAt(i) == ' ') {
                    i++;
                }
                if (i == s.length()) {
                    break;
                }
                int start = i;
                while (i < s.length() && s.charAt(i) != ' ') {
                    i++;
                }
                len = i - start;
                if (i == s.length()) {
                    break;
                }
            }
            return len;
        }
    }

    public static class UnitTest {

    }
}
