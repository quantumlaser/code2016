/*
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        stack<int> stk;
        int i = 0, maxA = 0;
        h.push_back(0);
        while(i < h.size()) {
            if(stk.empty() || h[stk.top()]<=h[i])
                stk.push(i++);
            else {
                int j = stk.top();
                stk.pop();
                maxA = max(maxA, h[j] * (stk.empty() ? i : i-stk.top()-1));
            }
        }
        return maxA;
    }
};