/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/
class Solution {
public:
    int trap(int A[], int n) {
        int rst = 0;
        if(n<3) return rst;
        vector<int> tHigh(A, A+n);
        for(int i=1; i<n-1; ++i)                        //find the highest bar in the left
            tHigh[i] = max(tHigh[i-1], A[i]);
        for(int i=n-2; i>0; --i) {                      //find the highest bar in the right
            tHigh[i] = max(tHigh[i+1], A[i]);
            rst += max(min(tHigh[i-1], tHigh[i+1])-A[i], 0);  //volume this bar can hold
        }
        return rst;
    }
};



int trap(int A[], int n) {
    int i = 0, j = n-1;
    int volume = 0;        
    int k = 0;
    while (i < j) {
        if (A[i] <= A[j]) {
            k = i+1;
            while (A[i] > A[k]) {
                volume += (A[i]-A[k]);
                k++;
            }
            i = k;
        }
        else {
            k = j-1;
            while (A[j] > A[k]) {
                volume += (A[j]-A[k]);
                k--;
            }
            j = k;
        }
    }   
    return volume;        
}

