# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        counter = 0
        temp = head
        dummy = ListNode(0, head)

        # If the list is empty or has only one node, return None
        if not head or not head.next:
            return None

        # Count the total number of nodes in the list
        while temp:
            temp = temp.next
            counter += 1

        # Reset temp to the dummy node
        temp = dummy

        # Move temp to the (counter-n)th node
        for i in range(counter - n):
            temp = temp.next

        # Remove the nth node from the end
        temp.next = temp.next.next

        return dummy.next