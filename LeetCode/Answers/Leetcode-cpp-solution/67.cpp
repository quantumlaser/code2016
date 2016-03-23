/*
Add BinaryApr 2 '122163 / 6167

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
string addBinary(string a, string b) {
    string sum="";
    int la=a.length()-1;
    int lb=b.length()-1;
    int c=0;
    while (la >=0 || lb >= 0 ||c >0)        
    {
        int v = c;
        if (la >=0) v+=a[la]-'0';
        if (lb >=0) v+=b[lb]-'0';

        c = v/2;
        sum = string(1,('0'+(v&1)))+sum;            
        la--;
        lb--;
    }
    return sum;
}

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string s;
        int i = a.size()-1, j = b.size()-1;
        for(;i>=0 || j>=0 || carry; --i, --j) {
            int ia = i>=0 ? (a[i]-'0'): 0;
            int ib = j>=0 ? (b[j]-'0'): 0;
            int sum = ia + ib + carry;
            carry = sum/2;
            s.push_back(sum%2 + '0');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

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