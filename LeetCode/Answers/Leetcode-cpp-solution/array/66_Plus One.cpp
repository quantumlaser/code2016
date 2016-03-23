/*
Given a number represented as an array of digits, plus one to the number.
*/
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int carry = 1;
            vector<int>::reverse_iterator iter;
            for(iter=digits.rbegin(); iter!=digits.rend()&&carry; ++iter) {
                *iter += carry;
                carry = *iter / 10;
                *iter = *iter % 10;
            }
            if(carry) digits.insert(digits.begin(), 1);
            return digits;
        }
};
