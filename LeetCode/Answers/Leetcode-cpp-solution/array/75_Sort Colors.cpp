/*Sort ColorsApr 9 '122127 / 4935

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int l=0, h=n-1;
        for(int i=0; i<=h; ++i) {
            if(A[i]==0) swap(A[i], A[l++]);
            else if(A[i]==2) swap(A[i--], A[h--]);
        }
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int i=-1, j=n;
        for(int k=0; k<j; ++k) {
            if(A[k]==0) xchg(A[++i], A[k]);
            else if(A[k]==2) xchg(A[--j], A[k--]);
        }
    }

private:
    void xchg(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int w = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                swap(A[b], A[i]);
                swap(A[b++], A[w++]);
            } else if (A[i] == 1) {
                swap(A[b++], A[i]);
            }
        }
    }
};

