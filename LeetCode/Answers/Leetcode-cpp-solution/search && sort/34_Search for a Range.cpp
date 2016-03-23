/*
Search for a RangeMar 3 '124707 / 12607

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i=0, j=n-1;
        vector<int> rst(2, -1);
        while(i<=j) {
            int mid = (i+j)/2;
            A[mid]>=target ? j=mid-1: i=mid+1;
        }
        if(A[i]!=target) return rst;
        rst[0] = i;
        i=0, j=n-1;
        while(i<=j) {
            int mid = (i+j)/2;
            A[mid]<=target ? i=mid+1: j=mid-1;
        }
        rst[1] = j;
        return rst;
    }
};
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> rst(2, -1);
        int l=0, h=n-1;
        while(l < h) {
            int mid = l+(h-l)/2;  //mid may equal to l
            A[mid]<target ? (l=mid+1) : (h=mid); //l increases until reach the lower bound
        }
        if(A[l]!=target) return rst;
        rst[0] = l;
        l=0, h=n-1;
        while(l < h) {
            int mid = l+ceil((h-l)/2.0);   //mid may equal to h
            A[mid]<=target ? (l=mid) : (h=mid-1); //h stop decreasing when reach the upper bound
        }
        rst[1] = l;
        return rst;
    }
};
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l=0, h=n-1, m, i, j;
        while(l<=h) {
            m = (l+h)/2;
            if(A[m]<=target) l=m+1;
            else h=m-1;
        }
        if(A[h]!=target) return vector<int>(2,-1);
        j = h;
        l = 0, h=n-1;
        while(l<=h) {
            m = (l+h)/2;
            if(A[m]>=target) h=m-1;
            else l=m+1;
        }
        i = l;
        int ret[] = {i, j};
        return vector<int>(ret, ret+2);
    }
};

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l=0, h=n, m, i, j;
        while(l<h) {
            m = (l+h)/2;
            if(A[m]<=target) l=m+1;
            else h=m;
        }
        if(A[h-1]!=target) return vector<int>(2,-1);
        j = h-1;
        l = 0, h=n;
        while(l<h) {
            m = (l+h)/2;
            if(A[m]>=target) h=m;
            else l=m+1;
        }
        i = l;
        int ret[] = {i, j};
        return vector<int>(ret, ret+2);
    }
}；



class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);
        int lower = 0;
        int upper = n;
        int mid;

        // Search for lower bound
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] < target)
                lower = mid + 1;
            else
                upper = mid;
        }

        // If the target is not found, return (-1, -1)
        if (A[lower] != target)
            return range;
        range[0] = lower;

        // Search for upper bound
        upper = n;
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] > target)
                upper = mid;
            else
                lower = mid + 1;
        }
        range[1] = upper - 1;

        return range;
    }
};



class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        ret.push_back(search(A, n, target, -1));
        ret.push_back(search(A, n, target, 1));
        return ret;
    }

    int search(int A[], int n, int target, int offset) {
        int L = 0, R = n - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (A[mid] == target) {
                if (mid + offset < 0 || mid + offset >= n || A[mid + offset] != target)
                    return mid;
                if (offset > 0)
                    L = mid + 1;
                else
                    R = mid - 1;
            } else if (A[mid] < target) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return -1;
    }
};

