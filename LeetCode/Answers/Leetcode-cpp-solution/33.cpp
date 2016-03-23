/*
Search in Rotated Sorted ArrayMar 3 '122782 / 7248

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j) {
            int mid = i+(j-i)/2;
            if(A[mid] == target) return mid;
            if(A[mid] >= A[i]) {
                if(A[mid]>target && A[i]<=target) j = mid-1;
                else i = mid+1;
            }
            else {
                if(A[mid]<target && A[j]>=target) i = mid+1;
                else j = mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, h = n, m;
        while(l < h) {
            m = (l+h)/2;
            if(target == A[m]) 
                return m;
            else if(target < A[m]) {
                if(A[l]<=A[m] && target<A[l]) l=m+1;
                else h=m;
            }
            else {
                if(A[m]<=A[h-1] && target>A[h-1]) h=m;
                else l=m+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        int l=0, h=n-1;
        while(l<=h) {
            int m = l+(h-l)/2;
            if(target==A[m]) return m;
            if(A[m]>=A[l] && target<A[m] && target>=A[l] || 
               (A[m]<A[l] && (target<A[m]||target>A[h])))
                h = m-1;
            else l = m+1;
        }
        return -1;
    }
};

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, h = n-1;
        while(l<=h) {
            int m = l+(h-l)/2;
            if(A[m]==target) return m;
            if(A[m]<target) {
                if(A[m]<A[l] && target>A[h]) h = m-1;
                else l = m+1;
            }
            else {
                if(A[m]>=A[l] && target<A[l]) l = m+1;
                else h = m-1;
            }
        }
        return -1;
    }
};