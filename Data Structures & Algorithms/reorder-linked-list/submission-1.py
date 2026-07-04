# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head == None or head.next == None: 
            return

        slow = head 
        fast = head.next 

        while fast is not None and fast.next is not None: 
            slow = slow.next 
            fast = fast.next.next 

        second = slow.next 

        slow.next = None
        prev = None

        #reversing the second half of list
        while second is not None: 
            temp = second.next 
            second.next = prev 
            prev = second
            second = temp

        first = head 
        second = prev
        # aranging the nodes from original first half and reversed second half
        while second is not None:
            temp1 = first.next 
            temp2 = second.next

            first.next = second
            second.next = temp1

            first = temp1
            second = temp2
        
