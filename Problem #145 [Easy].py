# This problem was asked by Google.

# Given the head of a singly linked list, swap every two nodes and return its head.
class ListNode:
    def __init__(self, val = 0, next = None) -> None:
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self) -> None:
        self.head = None
    def push(self, new_val):
        newNode = ListNode(new_val)
        newNode.next =  self.head
        self.head = newNode
    def print(self):
        temp = self.head
        while temp:
            print(temp.val, end=" -> " if temp.next else "\n")
            temp = temp.next
    # recursive version
    def swapPairs(self,head) -> ListNode:
        if head is None or head.next is None:
                return head
        newhead = head.next
        head.next = self.swapPairs(newhead.next)
        newhead.next = head
        return newhead
    # def swapPairs(self) -> ListNode:
    #     dummyHead = ListNode(0)
    #     dummyHead.next = self.head
    #     temp = dummyHead
    #     while temp.next and temp.next.next:
    #         node1 = temp.next
    #         node2 = temp.next.next
    #         temp.next = node2
    #         node1.next = node2.next
    #         node2.next = node1
    #         temp = node1
    #     self.head = dummyHead.next
    #     return self.head

    
        

llist = LinkedList()
llist.push(5)
llist.push(4)
llist.push(3)
llist.push(2)
llist.push(1)
llist.print()
llist.head = llist.swapPairs(llist.head)
llist.print()

 
    


            


    