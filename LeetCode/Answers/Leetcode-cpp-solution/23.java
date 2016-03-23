i/** 
  * Definition for singly-linked list. 
  *  * public class ListNode { 
  *   *     int val; 
  *    *     ListNode next; 
  *     *     ListNode(int x) { 
  *      *         val = x; 
  *       *         next = null; 
  *        *     } 
  *         * } 
  *          */  
public class Solution {  

    //null, {}, {{1},{2,3}}      
    public ListNode mergeKLists(ArrayList<ListNode> lists) {  
        if(lists==null) return null;  

        ListNode head = new ListNode(0); //dummy  
        ListNode p = head;  
        ArrayList<ListNode> temp = new ArrayList<ListNode>();  

        for(int i=0; i<lists.size(); i++) {  
            if(lists.get(i)!=null) {  
                temp.add( lists.get(i) );  
            }  
        }  

        while( !temp.isEmpty() ) {  
            int min = temp.get(0).val;  
            ListNode minNode = temp.get(0);  
            int minIndex = 0;  
            for(int i=1; i<temp.size(); i++) {  
                if(min > temp.get(i).val) {  
                    minNode = temp.get(i);  
                    min = minNode.val;  
                    minIndex = i;  
                }  
            }  
            p.next = minNode;  
            p = p.next;  

            if(minNode.next ==null) {  
                temp.remove(minIndex);  
            } else {  
                temp.set(minIndex, minNode.next);  //<strong>big mistake!!! if you wanna change the elment in list must use list.set().</strong>  
            }  
        }  

        return head.next;  
    }  
}  
