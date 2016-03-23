/*
Search in Rotated Sorted Array IIApr 20 '124077 / 10753

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l=0, h=n-1;
        while(l<=h) {
            int m = l+(h-l)/2;
            if(target==A[m]) return true;
            if(A[m]>A[l]) {
                if(target>=A[l] && target<A[m]) h = m-1;
                else l = m+1;
            }
            else if(A[m]<A[l]) {
                if(target>A[m] && target<=A[h]) l = m+1;
                else h = m-1;
            }
            else l++;
        }
        return false;
    }
};