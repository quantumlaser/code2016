/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::reverse_iterator r_iter = num.rbegin()+1;
        while(r_iter!=num.rend() && *r_iter>=*(r_iter-1)) //
            r_iter++;
        if(r_iter != num.rend()) {
            vector<int>::reverse_iterator r_iter2 = find_if(num.rbegin(), r_iter, bind2nd(greater<int>(), *r_iter));
            swap(*r_iter, *r_iter2);
            sort(num.rbegin(), r_iter, greater<int>());
        }
        else sort(num.rbegin(), num.rend(), greater<int>());
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::reverse_iterator r_iter = num.rbegin()+1;
        for(; r_iter!=num.rend(); ++r_iter) {
            if(*r_iter < *(r_iter-1)) {
                vector<int>::reverse_iterator r_iter2 = find_if(num.rbegin(), r_iter, bind2nd(greater<int>(), *r_iter));
                swap(*r_iter, *r_iter2);
                sort(num.rbegin(), r_iter, greater<int>());
                return;
            }
        }
        sort(num.rbegin(), num.rend(), greater<int>());
    }
};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::reverse_iterator r_iter = num.rbegin()+1;
        for(; r_iter!=num.rend(); ++r_iter) {
            if(*r_iter < *(r_iter-1)) {   // scan from the last element, find the first one that is not in ascending order
                vector<int>::reverse_iterator r_iter2 = find_if(num.rbegin(), r_iter, bind2nd(greater<int>(), *r_iter)); 
                swap(*r_iter, *r_iter2);  //swap this element *r_iter with the minimum one which is greater than *r_iter in the sequence scanned.
                reverse(num.rbegin(), r_iter); //reverse the sequence scanned
                return;
            }
        }
        reverse(num.rbegin(), num.rend()); //rearrage the greatest order to the lowest order by reverse the sequence
    }
};