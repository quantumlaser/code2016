/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool isLower(const Interval &lhs, const Interval &rhs) {return lhs.start<rhs.start;}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> rst;
        sort(intervals.begin(), intervals.end(), isLower);
        for(int i=0; i<intervals.size(); ++i) {
            if(rst.empty() || rst.back().end<intervals[i].start)
                rst.push_back(intervals[i]);
            else rst.back().end = max(rst.back().end, intervals[i].end);
        }
        return rst;
    }
};