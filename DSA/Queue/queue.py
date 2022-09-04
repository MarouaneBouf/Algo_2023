# A queue is a data structure that stores items in a first-in-first-out (FIFO) manner
class queue:
    def __init__(self) -> None:
        """
        It creates an empty list called `queue` and assigns it to the `self.queue` attribute
        """
        self.queue = []
        
    def enqueue(self,new_item):
        return self.queue.append(new_item)
    
    def dequeue(self):
        return self.queue.pop(0) if len(self.queue) != 0 else "Queue is empty!"
    
    def display(self):
        print(self.queue)
        
        
def main():
# Creating an object of the class queue.
    Queue_1 = queue()
    
# Asking the user to enter 4 elements and then adding them to the queue.
    for _ in range(int(input("Max size of the queue: "))):
        Queue_1.enqueue(int(input("Enter Element: ")))

# Removing the first element from the queue.
    Queue_1.dequeue()

# Printing the queue.
    Queue_1.display()
    
    
# A way to execute the main function when the program is run.
if __name__ == "__main__":
    main()