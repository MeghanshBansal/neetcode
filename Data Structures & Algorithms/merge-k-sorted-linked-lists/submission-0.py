# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if lists is None or len(lists) == 0: 
            return None
             
        while len(lists) > 1: 
            mergedLists = []
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if i+1 < len(lists) else None

                mergedLists.append(self.mergeTwoLists(l1, l2))
            lists = mergedLists
        
        return lists[0]
            
    
    def mergeTwoLists(self, l1, l2):
        sortedList = ListNode()
        temp = sortedList
        
        while l1 is not None and l2 is not None: 
            if l1.val <= l2.val:
                temp.next = ListNode(l1.val)
                l1 = l1.next 
                temp = temp.next 
            else: 
                temp.next = ListNode(l2.val)
                l2 = l2.next 
                temp = temp.next 

        while l1 is not None: 
            temp.next = ListNode(l1.val)
            l1 = l1.next 
            temp = temp.next 

        while l2 is not None: 
            temp.next = ListNode(l2.val)
            l2 = l2.next 
            temp = temp.next 

        return sortedList.next 

    
        