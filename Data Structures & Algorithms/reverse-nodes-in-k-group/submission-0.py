# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None: 
            return head 

        l = self.length(head)

        dummyNode = ListNode()
        dummyNode.next = head 

        prev = dummyNode 
        curr, nxt = None, None

        while l >= k:
            curr = prev.next 
            nxt = curr.next
            for i in range(1, k):
                curr.next = nxt.next
                nxt.next = prev.next 
                prev.next = nxt
                nxt = curr.next 
            prev = curr 
            l -= k
        return dummyNode.next 
        
    def length(self, head):
        l = 0
        curr = head 
        while curr is not None:
            curr = curr.next
            l +=1
        return l