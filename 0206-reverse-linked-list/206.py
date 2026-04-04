# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Approach:
        1. Iterative -- T.C: O(N), S.C: O(1)
            - Use three pointers: prev, curr, next. Reverse the link at each node and advance forward.
        2. Recursive -- T.C: O(N), S.C: O(N)
            - Recurse to the end of the list, then reverse links on the way back up the call stack.
        """

        # Approach 1 - Iterative
        """
        prev curr next
                3   2   1

        """
        prev_node = None
        curr_node = head
        next_node = None

        while curr_node:
            next_node = curr_node.next
            curr_node.next = prev_node
            prev_node = curr_node
            curr_node = next_node
        return prev_node

        """
        # Approach 2 - Recursive
        if head is None or head.next is None:
            return head

        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return new_head
        """
