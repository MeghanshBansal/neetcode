"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None: 
            return None
        mpp = dict()
        temp = head 
        while temp is not None: 
            dupNode = Node(temp.val)
            mpp[temp] = dupNode
            temp = temp.next 

        temp = head 
        while temp is not None: 
            copyNode = mpp[temp]
            copyNode.next = mpp.get(temp.next, None)
            copyNode.random = mpp.get(temp.random, None)
            temp = temp.next 

        return mpp[head]