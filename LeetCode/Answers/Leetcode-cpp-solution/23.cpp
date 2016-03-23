/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/
/**http://blog.csdn.net/xudli/article/details/8492032 
 ** Definition for singly-linked list. 
 ** struct ListNode { 
 **     int val; 
 **     ListNode *next; 
 **     ListNode(int x) : val(x), next(NULL) {} 
 ** }; 
keypoints: 1 be familiar with use of pointer to pointer ** pre, no need for a dummy head node.

2. when the container need erase or insert, it's probably a sign of using list instead of vector.

3. when use erase or insert function in vector and list, the argument must be iterator not index. Whereas, the argument is index position in string class.
 **/  
class Solution {  
    public:  
        ListNode *mergeKLists(vector<ListNode *> &lists) {  
            list<ListNode* > mylist;  
            for( int i=0; i< lists.size(); i++){  
                if(lists[i] != NULL) {  
                    mylist.push_back( lists[i] );  
                }  
            }  
            ListNode * head = NULL;  
            ListNode ** pre = &head;  
            while( ! mylist.empty()) {  
                list<ListNode* > :: iterator minIt = mylist.begin();  
                list<ListNode* > :: iterator it = mylist.begin();   
                while( ++it != mylist.end() ) {                  
                    if( (*it)->val < (*minIt)->val ) {  
                        minIt = it;  
                    }  
                }  
                *pre = *minIt;  
                if( (*minIt)->next == NULL ) {  
                    mylist.erase( minIt );  
                } else {  
                    (*minIt) = (*minIt)->next ;  
                }  
                pre = &( (*pre)->next);       
            }  
            return head;  
        }  
};  

//no need to use list, just swap elements in vector
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL, **tail = &head;
        for(int i=0; i<lists.size(); ++i) 
            if(!lists[i]) {
                lists[i--] = lists.back();
                lists.pop_back();
            }
        while(!lists.empty()) {
            int minIdx = 0;
            for(int i=1; i<lists.size(); ++i) 
                if(lists[i]->val < lists[minIdx]->val)
                    minIdx = i;
            *tail = lists[minIdx];
            if(lists[minIdx]->next)
                lists[minIdx] = lists[minIdx]->next;
            else {
                lists[minIdx] = lists.back();
                lists.pop_back();
            }
            tail = &((*tail)->next);
        }
        return head;
    }
};

//complexity: log(k)*n
//call make_heap to rearrange the elements in the input vector to form a min heap 
//pop the minimum element from the heap each time into the new list
//then call push_heap and pop_heap to automatically maintain heap propertities
class cmp {
public:
    bool operator() (const ListNode *lhs, const ListNode *rhs) const {
        return (lhs->val > rhs->val);
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *>::iterator iter = lists.begin();
        while(iter != lists.end() )
            *iter==NULL ? lists.erase(iter) : ++iter;
        ListNode *head = NULL, **tail = &head;
        make_heap(lists.begin(), lists.end(), cmp());
        while(!lists.empty()) {
            *tail = lists[0];
            tail = &((*tail)->next);
            pop_heap(lists.begin(), lists.end(), cmp());
            if(lists.back()->next) {
                lists.back() = lists.back()->next;
                push_heap(lists.begin(), lists.end(), cmp());
            }
            else lists.pop_back();
        }
        return head;
    }
};