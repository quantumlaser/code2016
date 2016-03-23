package linked_list_cycle;

import common.ListNode;

public class LinkedListCycle {

    public class Solution {
        public boolean hasCycle(ListNode head) {
            ListNode slow = head;
            ListNode fast = head;
            do {
                if (fast == null || fast.next == null) {
                    return false;
                }
                fast = fast.next.next;
                slow = slow.next;
            } while (fast != slow);
            return true;
        }
    }

    public static class UnitTest {

    }
}
