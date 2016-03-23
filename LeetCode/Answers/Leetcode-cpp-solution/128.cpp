/*
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int, int> m;
        int maxl = 1;
        for(int i=0; i<num.size(); ++i) {
            if(m.count(num[i]))
                continue;
            m[num[i]] = 1;
            if(m.count(num[i]-1))
                maxl = max(maxl, merge(m, num[i]));
            if(m.count(num[i]+1))
                maxl = max(maxl, merge(m, num[i]+1));
        }
        return maxl;
    }
    int merge(map<int, int> &m, int right) {
        int left = right - 1;
        int low = left - m[left] + 1;
        int high = right + m[right] - 1;
        int len = high - low + 1;
        m[low] = m[high] = len;
        return len;
    }
};