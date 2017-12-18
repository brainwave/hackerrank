class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None

class LinkedList:
    
    def __init__(self, initdata = None):
        if initdata == None:
            self.head = None
        else:
            self.head = Node(initdata)

    def append(self, newdata):

        temp = self.head;
        self.head = Node(newdata)
        self.head.next = temp

    def appendToTail(self, newdata):

        n = self.head

        while n.next is not None:
           n = n.next
        
        n.next = Node(newdata)

    def deleteNode(self,intdata):

        if self.head.data == intdata:
            self.head = self.head.next

        n = self.head

        while n.next != None:
            if n.next.data == intdata:
                n.next = n.next.next

            n = n.next

    def deleteDups(self):
        n = self.head    
        prev = None

        dict_ll = dict()

        while n != None:
            if  n.data in dict_ll:
                prev.next = n.next

            else:
                dict_ll[n.data] = 1
                prev = n
            
            n = n.next

    def printNodes(self):

        n = self.head

        while n is not None:
            print(n.data)
            n = n.next

    

