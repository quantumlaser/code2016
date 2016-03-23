/*
Remove Duplicates from Sorted Array IIApr 19 '121761 / 4358

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n) return 0;
        int pos = 0;
        int cnt = 1;
        for(int i=1; i<n; ++i) {
            if(A[i]!=A[pos]) {
                A[++pos] = A[i];
                cnt = 1;
            }
            else if(++cnt<3) A[++pos] = A[i];
        }
        return pos + 1;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        for(int i=0; i<n; ++i) {
            if(i<n-2 && A[i]==A[i+1] && A[i]==A[i+2]) continue;
            A[j++] = A[i];
        }
        return j;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) return n;

        int cur = 1;
        for (int i = 2; i < n; ++i) {
            if (!(A[i] == A[cur] && A[i] == A[cur - 1]))
                A[++cur] = A[i];
        }

        return cur + 1;
    }
};

