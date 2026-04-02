# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Approach: Two Pointer -- T.C: O(N), S.C: O(1)
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

        """
        # Approach: HashSet -- T.C: O(N), S.C: O(N)
        curr = head
        visited_addr = set()

        while curr:
            curr_addr = id(curr)
            if curr_addr in visited_addr:
                return True
            visited_addr.add(curr_addr)
            curr = curr.next
        return False
        """
