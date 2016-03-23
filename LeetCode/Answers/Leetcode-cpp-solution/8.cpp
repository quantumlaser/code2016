/*
String to Integer (atoi)Dec 27 '112809 / 13204

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/
class Solution {
public:
    int atoi(const char *str) {
        int i=0, len=strlen(str), sign=1;
        while(i<len && str[i]==' ') i++;
        if(i==len || (!isdigit(str[i]) && str[i]!='+' && str[i]!='-')) return 0;
        if(!isdigit(str[i]) && (sign = (str[i]=='+'?1:-1)) && !isdigit(str[++i])) return 0;
        int j=i+1;
        while(j<len && isdigit(str[j])) j++;
        int num=0;
        while(i<j) {
            if(num > INT_MAX/10 || num < INT_MIN/10) return sign==1 ? INT_MAX : INT_MIN;
            num *= 10;
            int d = str[i++]-'0';
            if(num > INT_MAX-d || num <INT_MIN+d) return sign==1 ? INT_MAX : INT_MIN;
            num += sign*d;
        }
        return num;
    }
};

class Solution {
public:
    int atoi(const char *str) {
        if(!str) return 0;
        char *p = const_cast<char *>(str);
        int sign = 1;
        while(*p && *p==' ') p++;
        if(*p == '+') p++;
        if(*p == '-') sign=-1, p++;
        int max = (sign==1)?INT_MAX:INT_MIN;
        int val = 0;
        while(isdigit(*p)) {
            if(abs(val*1.0/(max/10))>1.0 || abs(val*10.0/(max-sign*(*p-'0')))>1.0)
                return max;
            val = val*10 + *(p++)-'0';
        }
        return sign * val;
    }
};