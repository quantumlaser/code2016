/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
*/
struct Node
{
    int val;
    int idx;
    Node(){}
    Node(int v, int i):val(v),idx(i){}
}; 

bool cmp(const Node &a, const Node &b)
{
    return a.val<b.val;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> nvec;
        vector<int> ret;
        for(vector<int>::size_type i = 0; i!=numbers.size(); ++i) 
            nvec.push_back(Node(numbers[i], i+1));
        sort(nvec.begin(), nvec.end(), cmp);
        int l = 0, h = nvec.size()-1;
        while(l<h) {
            int s = nvec[l].val + nvec[h].val;
            if(s==target) {
                ret.push_back(min(nvec[l].idx, nvec[h].idx));
                ret.push_back(max(nvec[l].idx, nvec[h].idx));
                break;
            }
            else if(s<target) l++;
            else h--;
        }
        return ret;
    }
};