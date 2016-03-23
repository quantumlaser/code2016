/*Edit DistanceApr 4 '121824 / 5557

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if(!l1 || !l2) return max(l1, l2);
        int t1 = minDistance(word1.substr(1, l1), word2.substr(1, l2));
        if(word1[0]==word2[0]) return t1;
        t1 += 1;
        int t2 = minDistance(word1.substr(1, l1), word2.substr(0, l2)) + 1;
        int t3 = minDistance(word1.substr(0, l1), word2.substr(1, l2)) + 1;
        return min(min(t1,t2), t3);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        if(!l1 || !l2) return max(l1, l2);
        vector<vector<int> > d(l1, vector<int>(l2));
        int i, j;
        d[0][0] = word1[0]==word2[0] ? 0:1;
        for(i=1; i<l1; ++i) 
            d[i][0] = (word1[i]==word2[0] ? i : d[i-1][0]+1);
        for(j=1; j<l2; ++j)
            d[0][j] = (word1[0]==word2[j] ? j : d[0][j-1]+1);
        for(i=1; i<l1; ++i)
            for(j=1; j<l2; ++j) {
                d[i][j] = d[i-1][j-1] + (word1[i]==word2[j] ? 0 : 1);
                d[i][j] = min(d[i][j], min(d[i-1][j]+1, d[i][j-1]+1));
            }
        return d[l1-1][l2-1];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j, l1 = word1.size(), l2 = word2.size();
        if(!l1 || !l2) return max(l1, l2);
        vector<vector<int> > d(l1+1, vector<int>(l2+1));
        for(i=1; i<=l1; ++i) d[i][0] = i;
        for(j=1; j<=l2; ++j) d[0][j] = j;
        for(i=1; i<=l1; ++i)
            for(j=1; j<=l2; ++j) {
                d[i][j] = d[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0:1);
                d[i][j] = min(d[i][j], min(d[i-1][j]+1, d[i][j-1]+1));
            }
        return d[l1][l2];
    }
};

class Solution {
public:
    inline int minInt(int a, int b){
        return (a< b?a:b);
    }
    inline int minInt(int a, int b, int c){
        return minInt(minInt(a, b), c);        
    }
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.length();
        int l2 = word2.length();
        string& w1 = (l1< l2?word1:word2);//shorter - horizontal
        string& w2 = (l1< l2?word2:word1);//longer - vertical
        int const length1 = w1.length();
        int const length2 = w2.length();
        if (!length1) return length2;
        vector< int> dist(length1,0);
        for(int ii = 0; ii < length1; ++ii){//row 0, dist[0] is not used
            dist[ii] = ii + 1;
        }//for ii
        for(int ii = 0; ii < length2; ++ii){//vertical, start from row 1 (when length2==1)
            int distDiag = ii;
            int distLeft = ii + 1;
            for(int jj = 0; jj < length1; ++jj){//horizontal
                int const distUp = dist[jj];
                if (w1[jj] == w2[ii]) dist[jj] = distDiag;
                else dist[jj] = minInt(distLeft, distUp, distDiag) + 1;
                distDiag = distUp;
                distLeft = dist[jj];
            }
        }
        return dist[length1-1];
    }
};

/**If there is some memory constrain, the minimum memory depends on the length
of the shorter string, as the code above

The general bottom-up method utilizing updating table, similar to the
longest-common sequence (start at 55:50)
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-15-dynamic-programming-longest-common-subsequence/

Algo: http://en.wikipedia.org/wiki/Levenshtein_distance
A working implementation can be found here:
http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class Solution{
public:
  int edit_distance(T const& s1, T const& s2){
    vector<vector<int>> matrix(s1.size()+1, vector<int>(s2.size()+1));
    //s2 horizontal, s1 vertical
    for(int ii = 0; ii <= s1.size(); ++ii) matrix[ii][0] = ii;
    for(int ii = 0; ii <= s2.size(); ++ii) matrix[0][ii] = ii;
    for(int ii = 1; ii <= s1.size(); ++ii){
      for(int jj = 1; jj <= s2.size(); ++jj){//scan from left to right
        //line by line
        matrix[ii][jj] = min(min(matrix[ii-1][jj], matrix[ii][jj-1])+1,
          matrix[ii-1][jj-1]+static_cast<int>(s1[ii-1] != s2[jj-1]));
      }//for jj
    }//for ii
    return matrix[s1.size()][s2.size()];
  }
};

int main(){
  cout<<"hello"<<endl;

  Solution<string> s;
  string s1("cat");
  string s2("hat");
  cout<<s.edit_distance(s1,s2)<<endl;
  return 0;
}



class Solution { public:
    int minDistance(string word1, string word2) {
        int ar[word1.size()+1][word2.size()+1];
        for(int i=0;i<=word1.size();i++)
            ar[i][0]=i;
        for(int j=0;j<=word2.size();j++)
            ar[0][j]=j;
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                    ar[i][j]=ar[i-1][j-1];
                else
                {
                    int mn=min(ar[i-1][j],ar[i][j-1]);
                    ar[i][j]=1+min(ar[i-1][j-1],mn);
                }
            }
        }
        return ar[word1.size()][word2.size()];   
    } };

