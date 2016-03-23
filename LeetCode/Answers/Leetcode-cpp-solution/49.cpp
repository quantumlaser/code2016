/*
AnagramsMar 19 '125117 / 16882

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
public:
    bool cmp(string a, string b) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a < b;
    }
    bool isAnagram(string a, string b) 
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
    vector<string> anagrams(vector<string> &strs) {
        vector<string> rst;
        sort(strs.begin(), strs.end(), cmp);
        int cnt = 1;
        for(int i=1; i<strs.size(); ++i) {
            if(isAnagram(strs[i], strs[i-1])) cnt++;
            else if(cnt > 1) {
                rst.insert(rst.end(),  &strs[i - cnt], &strs[i]);
                cnt = 1;
            }
        }
        if(cnt > 1) rst.insert(rst.end(), &strs[strs.size() - cnt], &strs[strs.size()]);
        return rst;
    }
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> cc;
        map<string, vector<string> > dict;
        vector<string>::iterator st;
        for(st = strs.begin(); st != strs.end(); st++) {
            string key = *st;
            sort(key.begin(), key.end());
            dict[key].push_back(*st);
        }
        map<string, vector<string> >::iterator it;
        for(it = dict.begin(); it != dict.end(); it++) {
            if(it->second.size() > 1)
                for(st = it->second.begin(); st != it->second.end(); st++)
                    cc.push_back(*st);
        }
        return cc;
    }
};
