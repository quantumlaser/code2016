/*
Unique Binary Search TreesAug 27 '121938 / 3756

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
        int *num = new int[n+1];
        num[0] = 1;
        for(int i=1; i<=n; ++i) {
            num[i] = 0;
            for(int j=0; j<i; ++j) {
                num[i] += num[j]*num[i-j-1];
            }
        }
        return num[n];
    }
};