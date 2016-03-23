/*
 Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int once = 0, twice = 0, thrice;   
        for(int i=0; i<n; ++i) {
            twice |= once & A[i];  //record all bits appeared twice
            once ^= A[i];           //record all bits appeared once
            thrice = once & twice;
            once &= ~thrice;        //clear all bits that appeared thrice
            twice &= ~thrice;
        }
        return once;
    }
};