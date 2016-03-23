class Solution {
public:
    string addBinary(string aa, string bb) {
        const char *a = aa.c_str();
        const char *b = bb.c_str();
        int len = max(aa.size(), bb.size()) +2;
        char *s = new char[len];
        int carry = 0;
        int i=strlen(a)-1, j=strlen(b)-1, l=len-2;
        for(;i>=0||j>=0||carry; --i,--j,--l) {
            int ia = i>=0 ? (a[i]-'0'):0;
            int ib = j>=0 ? (b[j]-'0'):0;
            int sum = ia+ib+carry;
            carry = sum/2;
            s[l] = sum%2 + '0';
        }
        s[len-1] = '\0';
        string r(s[0]=='1' ? s:s+1);
        return r;
    }
};