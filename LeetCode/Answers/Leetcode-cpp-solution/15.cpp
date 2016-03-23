/**
3SumJan 18 '12817 / 3133

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
//256 milli secs
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> rst;
        if(num.size() < 3) return rst;
        sort(num.begin(), num.end());
        for(int k=0; k != num.size()-2; ++k) {
            if(k>0 && num[k]==num[k-1]) continue;
            int i=k+1, j=num.size()-1;
            while(i<j) {
                if(i>k+1&&num[i]==num[i-1]) { i++; continue;}
                if(j<num.size()-1&&num[j]==num[j+1]) {j--; continue;}
                if(num[i]+num[j]+num[k]==0) {
                    int a[] = {num[k], num[i++], num[j--]};
                    rst.push_back(vector<int>(a, a+3));
                }
                else num[i]+num[j]+num[k]<0 ? i++ : j--;
            }
        }
        return rst;
    }
};
//1528 milli secs
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > rst;
        if(num.size()<3) return rst;
        sort(num.begin(), num.end());
        for(int k=0; k!=num.size(); ++k) {
            int i = k+1, j=num.size()-1, t=-num[k];
            while(i<j) {
                int s = num[i]+num[j];
                if(s==t) {
                    vector<int> ivec;
                    ivec.push_back(num[k]);
                    ivec.push_back(num[i++]);
                    ivec.push_back(num[j--]);
                    if(rst.end() == find(rst.begin(), rst.end(), ivec)) rst.push_back(ivec);
                }
                else s<t ? i++ : j--;
            }
        }
        return rst;
    }
};

//276 milli secs
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > rst;
        if(num.size()<3) return rst;
        sort(num.begin(), num.end());
        for(int k=0; k!=num.size(); ++k) {
            if(k>0 && num[k]==num[k-1]) continue;
            int i = k+1, j=num.size()-1, t=-num[k];
            while(i<j) {
                int s = num[i]+num[j];
                if(s==t) {
                    if(i>k+1 && num[i]==num[i-1]) {i++, j--;continue;}
                    vector<int> ivec;
                    ivec.push_back(num[k]);
                    ivec.push_back(num[i++]);
                    ivec.push_back(num[j--]);
                    //int triple[] = {num[k], num[i++], num[j--]};
                    //vector<int> ivec(triple, triple+3);
                    rst.push_back(ivec);
                }
                else s<t ? i++ : j--;
            }
        }
        return rst;
    }
};