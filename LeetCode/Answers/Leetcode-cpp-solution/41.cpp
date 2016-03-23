/*
 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0; i<n; ++i) {
            if(A[i]>0 && A[i]<n && A[i]-1!=i && A[A[i]-1]!=A[i]) {
                swap(A[i], A[A[i]-1]);
                i--;
            }
        }
        for(int i=0; i<n; ++i) 
            if(A[i]!=i+1)
                return i+1;
        return n+1;
    }
};
//https://github.com/Warren5382/leetcode/blob/master/first_missing_positive/test.cpp
class Solution {
        public:
                int firstMissingPositive(int A[], int n) {
                        if(n <= 0)
                                return 1;
                        int intOutOfRange = n + 2;
                        //first run, turn every negetive value into an impossible positive value
                        //make every value in A is positive
                        for(int i = 0 ; i < n ; ++ i) {
                                if(A[i] <= 0)
                                        A[i] = intOutOfRange;
                        }
                        //second run, make A[] as a hash table, A[i] indicate the presence of i + 1
                        //the way is that, if k in [1,n] is in A[], then turn A[k -1] to negetive
                        for(int i = 0 ; i < n ; ++i) {
                                int ai = A[i];
                                int absi = abs(ai);
                                if(absi <= n)
                                        A[absi-1] = -abs(A[absi-1]);
                        }
                        //third run, if A[i] is positive, from step 2, we know that i + 1 is missing.
                        for(int i = 0 ; i < n ; ++i) {
                                if(A[i] > 0)
                                        return i + 1;
                        }
                        //all int from 1 to n is present, then return n + 1
                        return n+1;
                }
};