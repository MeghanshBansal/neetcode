# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None: 
            return False

        slow = head 
        fast = head

        while fast.next is not None and fast.next.next is not None and True: 
            slow = slow.next 
            fast = fast.next.next 
            if slow == fast: 
                return True

        return False