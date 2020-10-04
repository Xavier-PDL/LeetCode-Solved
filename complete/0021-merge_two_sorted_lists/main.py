class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
    def add(self, val=0):
        if self.next == None:
            self.next = ListNode(val)
        else:
            self.next.add(val)

    def print(self):
        currNode = self
        print("[ ", end = '')
        while currNode != None:
            print("{} ".format(currNode.val), end='')
            currNode = currNode.next
        print("]")

class Solution:
    def mergeTwoLists(self, l1, l2):
        out = ListNode()
        if l1 == None:
            return l2
        elif l2 == None:
            return l1

        if l1.val < l2.val:
            out = l1
            l1 = l1.next
        else:
            out = l2
            l2 = l2.next

        currNode = out
        while True:
            if l1 != None and l2 == None:
                currNode.next = l1
                return out
            elif l1 == None and l2 != None:
                currNode.next = l2
                return out

            if l1.val < l2.val:
                currNode.next = l1
                l1 = l1.next
            elif l1.val >= l2.val:
                currNode.next = l2
                l2 = l2.next
            else: break
            currNode = currNode.next
            
        return out


def main():
    l1 = ListNode(1)
    l1.add(2)
    l1.add(4)
    l2 = ListNode(1)
    l2.add(3)
    l2.add(3)
    
    s = Solution()
    out = s.mergeTwoLists(l1, l2)
    out.print()
    print("done...")
    
main()