/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
*/
class Solution {
public:
    int jump(int A[], int n) {
        int cur=0, last=0, step=0; 
        for(int i=0; i<n; ++i) {
            if(i>last) {           //last is the maximum distance that can be reached using 'step' steps
                last = cur;			//cur is the maximum distance that can be reached using 'step+1' steps
                step++;
            }
            cur = max(cur, i+A[i]);  //update the maximum distance using 'step+1' steps
        }
        return step;
    }
};
/*
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
 */