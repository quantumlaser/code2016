/**
Container With Most WaterJan 9 '12551 / 1134

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are 

drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a 

container, such that the container contains the most water.

Note: You may not slant the container. 
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size()-1;
        int max_v = 0;
        while(i<j) max_v = max(max_v, (j-i)*(height[i]<height[j] ? height[i++] : height[j--]));
        return max_v;
    }
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, h = height.size()-1;
        int vmax = 0;
        while(l<h) {
            int vnew = min(height[l], height[h]) * (h-l);
            vmax = max(vmax, vnew);
            height[l] < height[h] ? l++ : h--;
        }
        return vmax;
    }
};