'''
Queue is a linear data structue that follows FIFO concept
which stands for first in first out.
We can perform different operations with a queue:
enqueue / dequeue / peek / display 
'''

class node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next
        
class queue:
    def __init__(self):
        self.head = None
        self.rear = None
    
    # Add elements at the end of the queue like append for linked list implementation   
    def enqueue(self, item):
        new_node = node()
        new_node.data = item
        # Checking if the queue is empty or not.
        if self.rear is None:
            # Assigning the new node to both head and rear.
            self.head = self.rear = new_node
        else:
            # Adding the new node to the end of the queue.
            self.rear.next = new_node
            # Updating the rear pointer to point to the new node.
            self.rear = new_node
            
    # Remove the first element from the queue
    def dequeue(self):
        if self.rear is None:
            print("Queue is empty!")
        else:
           # Checking if the queue is empty or not.
            if self.head.next is None:
                print("Queue is empty!")
                self.head = self.rear = None
            # Removing the first element of the queue.
            self.head = self.head.next
    
    # Display the elements of the stack
    def display(self):
        temp = self.head
        # Printing the data of the nodes in the queue.
        while(temp != None):
            print(temp.data)
            temp = temp.next


def main():
    queue_1 = queue()
    for _ in range(3):
        queue_1.enqueue(input("Who's turn now? "))
    queue_1.dequeue()
    queue_1.display()


if __name__ == "__main__":
    main()
    