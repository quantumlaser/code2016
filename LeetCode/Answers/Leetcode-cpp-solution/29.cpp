/*
Divide two integers without using multiplication, division and mod operator. 
*/
//Submission Result: Time Limit Exceeded
class Solution {
public:
    int divide(int dividend, int divisor) {
        int c = 0;
        for(; divisor<=dividend; c++)
            dividend -= divisor;
        return c;
    }
};

//if a, b are integer not longlong, error below will accur.
//Submission Result: Time Limit Exceeded
//Last executed input: 	2147483647(0x7fffffff), 1
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs(dividend);
        long long b = abs(divisor);
        int rst = 0;
        while(a >= b) {
            int c = 0;
            while(a >= (b<<c)) c++;
            rst += 1<<(--c);
            a -= b<<c;
        }
        return (dividend^divisor)>>31 ? -rst : rst;
    }
};