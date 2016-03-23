/*
Convert Sorted List to Binary Search TreeOct 3 '125768 / 16298

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        ListNode **p=&head, *q=head->next;
        while(q && q->next) {
            p = &((*p)->next);
            q = q->next->next;
        }
        TreeNode *root = new TreeNode((*p)->val);
        ListNode *tmp = (*p)->next;
        *p = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(tmp);
        return root;
    }
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        int n = 1;
        ListNode *p = head;
        while(p=p->next) n++;
        return sortedListToBST(head, 0, n);
    }
    
    TreeNode *sortedListToBST(ListNode *&list, int s, int e) {
        if(s >= e) return NULL;
        int m = s + (e-s)/2;
        TreeNode *left = sortedListToBST(list, s, m); //when this recursive call is done, list has been advanced to m
        TreeNode *parent = new TreeNode(list->val);
        parent->left = left;
        list = list->next; //advance one step
        parent->right = sortedListToBST(list, m+1, e);  //continue to advance so now list is equal to e
        return parent;
        
    }
};

/*If you have not checked out my previous post: Convert Sorted Array to Balanced Binary Search Tree (BST), you should check it out now as this solution is built upon the previous solution.

Things get a little more complicated when you have a singly linked list instead of an array. Please note that in linked list, you no longer have random access to an element in O(1) time.


Singly-linked lists contain nodes which have a data field as well as a next field, which points to the next node in the linked list.

Naive Solution:
A naive way is to apply the previous solution directly. In each recursive call, you would have to traverse half of the list's length to find the middle element. The run time complexity is clearly O(N lg N), where N is the total number of elements in the list. This is because each level of recursive call requires a total of N/2 traversal steps in the list, and there are a total of lg N number of levels (ie, the height of the balanced tree).

Hint:
How about inserting nodes following the list's order? If we can achieve this, we no longer need to find the middle element, as we are able to traverse the list while inserting nodes to the tree.

Best Solution:
As usual, the best solution requires you to think from another perspective. In other words, we no longer create nodes in the tree using the top-down approach. We create nodes bottom-up, and assign them to its parents. The bottom-up approach enables us to access the list in its order while creating nodes.

Isn't the bottom-up approach neat? Each time you are stucked with the top-down approach, give bottom-up a try. Although bottom-up approach is not the most natural way we think, it is extremely helpful in some cases. However, you should prefer top-down instead of bottom-up in general, since the latter is more difficult to verify in correctness.

Below is the code for converting a singly linked list to a balanced BST. Please note that the algorithm requires the list's length to be passed in as the function's parameters. The list's length could be found in O(N) time by traversing the entire list's once. The recursive calls traverse the list and create tree's nodes by the list's order, which also takes O(N) time. Therefore, the overall run time complexity is still O(N).
*/
BinaryTree* sortedListToBST(ListNode *& list, int start, int end) {
    if (start > end) return NULL;
    // same as (start+end)/2, avoids overflow
    int mid = start + (end - start) / 2;
    BinaryTree *leftChild = sortedListToBST(list, start, mid-1);
    BinaryTree *parent = new BinaryTree(list->data);
    parent->left = leftChild;
    list = list->next;
    parent->right = sortedListToBST(list, mid+1, end);
    return parent;
}

BinaryTree* sortedListToBST(ListNode *head, int n) {
    return sortedListToBST(head, 0, n-1);
}


 public TreeNode sortedListToBST(ListNode head) {
    // Start typing your Java solution below
    // DO NOT write main() function
    //two base cases
    if(head==null)
        return null;
    if(head.next==null)
        return new TreeNode(head.val);
    ListNode fast=head.next.next;
    ListNode slow=head;
    //partition the list from the middle, use two pointers
    //the slow pointer will be the prev of the middle node
    while(fast!=null && fast.next!=null)
    {
        fast=fast.next.next;
        slow=slow.next;
    }
    //find the middle node
    ListNode parent=slow.next;
    slow.next=null;
    //partition the list into left and right
    ListNode left=head;
    ListNode right=parent.next;
    parent.next=null;
    //make the middle node as the root, then apply the function
    //to the left part and the right part recursively
    TreeNode root=new TreeNode(parent.val);                                     
    root.left=sortedListToBST(left);            
    root.right=sortedListToBST(right);
    return root;
}