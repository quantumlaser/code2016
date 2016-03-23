/*
Implement strStr()Feb 18 '122641 / 8299

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        int m=strlen(haystack), n=strlen(needle);
        if(!n) return haystack;
        if(!m) return NULL;
        for(int i=0; i<=m-n; ++i) {
            int j=0;
            while(j<n && haystack[i+j]==needle[j]) j++;
            if(j==n) return haystack+i;
        }
        return NULL;
    }
};

class Solution {
public:
    char *strStr(const char *haystack, const char *needle) {
        if(!*needle) return haystack;
        do {
            char *p1=haystack, *p2=needle;
            while(*p1 && *p2 && *p1==*p2) p1++, p2++;
            if(!*p2) return haystack;
            if(!*p1) break;
        } while(++haystack);
        return NULL;
    }
};

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle) return NULL;
        if(!*needle) return haystack;
        char *p1Adv = haystack;
        char *p1, *p2 = needle;
        while(*++p2 && *++p1Adv);
        while(*p1Adv++) {
            p1 = haystack;
            p2 = needle;
            while(*p1 && *p2 && *p1==*p2) p1++, p2++;
            if(!*p2) return haystack;
            haystack++;
        }
        return NULL;
    }
};
