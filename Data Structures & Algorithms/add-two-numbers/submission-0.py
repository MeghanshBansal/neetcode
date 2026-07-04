# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(0)
        temp = ans
        curr1 = l1
        curr2 = l2

        remain = 0
        while curr1 is not None and curr2 is not None: 
            s = curr1.val + curr2.val + remain
            val = s % 10 
            remain = s // 10 
            temp.next = ListNode(val)
            temp = temp.next 
            curr1 = curr1.next 
            curr2 = curr2.next 

        while curr1 is not None: 
            s = curr1.val + remain
            val = s % 10 
            remain = s // 10 
            temp.next = ListNode(val)
            temp = temp.next 
            curr1 = curr1.next 

        while curr2 is not None: 
            s = curr2.val + remain
            val = s % 10 
            remain = s // 10 
            temp.next = ListNode(val)
            temp = temp.next 
            curr2 = curr2.next 

        while remain: 
            val = remain % 10
            remain = remain // 10
            temp.next = ListNode(val)
            temp = temp.next 
        
        return ans.next
        
    
            