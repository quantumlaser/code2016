/*
Jump GameMar 25 '126923 / 16241

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        return recur(A, n, 0);
    }
    
    bool recur(int A[], int n, int i) {
        if(A[i] + i >= n -1) return true;
        for(int k = i + 1; k <= A[i] + i; ++k)
            if(recur(A, n, k)) return true;
        return false;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> flag(n, 0);
        for(int i=n-1; i>=0; --i) {
            if(i + A[i] >= n-1) {
                flag[i] = 1;
                continue;
            }
            for(int j = i + 1; j<=min(n-1, i + A[i]); ++j)
                if(flag[j]) {
                    flag[i] = 1;
                    break;
                }
        }
        return flag[0];
    }
};



class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int reach = 1;
        for (int i = 0; i < reach && reach < n; ++i)
            reach = max(reach, A[i] + i + 1);
        return reach >= n;
    }
};

