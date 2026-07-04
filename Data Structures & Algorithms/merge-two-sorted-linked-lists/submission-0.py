# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None: 
            return list2
        if list2 is None: 
            return list1 
        
        newListHead = ListNode()
        temp = newListHead
        while list1 is not None and list2 is not None: 
            if list1.val <= list2.val:
                newListHead.next = ListNode(list1.val)
                list1 = list1.next
            else: 
                newListHead.next = ListNode(list2.val)
                list2 = list2.next
            newListHead = newListHead.next

        while list1 is not None: 
            newListHead.next = ListNode(list1.val)
            list1 = list1.next
            newListHead = newListHead.next 
        
        while list2 is not None: 
            newListHead.next = ListNode(list2.val)
            list2 = list2.next 
            newListHead = newListHead.next 

        return temp.next