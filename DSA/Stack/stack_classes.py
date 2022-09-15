# I am going to implement the stack DS using the built-in functions and then without them!

# The class stack is a data structure that has a list of items, and has methods to add items to the
# list, remove items from the list, and display the list.
class stack:
    def __init__(self):
        """
        The function __init__() is a special function in Python classes. It is run as soon as an object
        of a class is instantiated. The method __init__() is similar to constructors in C++ and Java
        """
        self.stack = []
    
    
    def push(self, item):
        """
        Add the item to the end of the list.
        :param item: The item to be pushed onto the stack
        """
        self.stack.append(item)
        
    def pop(self):
        """
        It removes the last element from the stack.
        """
        self.stack.pop()
    
    def display(self):
        print(self.stack)
        
def main():
    stack_1 = stack()
    
    for i in range(1,6):
        stack_1.push(i)
    
    stack_1.display()
    
    stack_1.pop()
    
    stack_1.display()
    

# A way to execute the main function when the program is run.
if __name__ == "__main__":
    main()