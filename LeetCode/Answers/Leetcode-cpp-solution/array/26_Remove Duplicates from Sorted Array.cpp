/*
Remove Duplicates from Sorted ArrayFeb 16 '125494 / 11609

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n<=1) return n;
            int pre = 0, cur = 1;
            for(; cur<n; ++cur)
                if(A[cur] != A[pre])
                    A[++pre] = A[cur];
            return pre + 1;
        }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i,j;
        for(i=-1,j=0; j<n; ++j) {
            if(A[j]!=A[i]) 
                A[++i] = A[j];
        }
        return i+1;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        for(int j=0; j<n; ++j) {
            if(j==0 || A[j]!=A[j-1])
                A[i++] = A[j];
        }
        return i;
    }
};