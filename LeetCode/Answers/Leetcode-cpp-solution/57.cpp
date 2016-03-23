/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
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
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> rst;
        int n = intervals.size();
        int k = 0;
        while(k<n && intervals[k].end < newInterval.start) rst.push_back(intervals[k++]);
        if(k==n || newInterval.end < intervals[k].start) {
            rst.push_back(newInterval);
            rst.insert(rst.end(), intervals.begin()+k, intervals.end());
        } else {
            rst.push_back(Interval(min(newInterval.start, intervals[k].start), max(newInterval.end, intervals[k].end)));
            int i = k+1;
            while(i < n) {
                if(intervals[i].start > rst.back().end)
                    break;
                rst.back().end = max(rst.back().end, intervals[i++].end);
            }
            rst.insert(rst.end(), intervals.begin()+i, intervals.end());
        }
        return rst;
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> rst;
        int n = intervals.size();
        int k = 0;
        while(k<n && intervals[k].end < newInterval.start) 
            rst.push_back(intervals[k++]);
        if(k<n) 
            newInterval.start = min(newInterval.start, intervals[k].start);
        while(k<n && intervals[k].start <= newInterval.end) 
            newInterval.end = max(newInterval.end, intervals[k++].end);
        rst.push_back(newInterval);
        while(k<n)
            rst.push_back(intervals[k++]);
        return rst;
    }
};